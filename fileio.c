/*
PIC : akhsya 
NIM : 241524039
*/

#include "fileio.h"

/* Deskripsi   : Prosedur untuk membuat folder "tournament_data" jika belum ada. Jika folder sudah ada, prosedur ini tidak melakukan apa-apa. Menampilkan peringatan jika terjadi kegagalan lain selain folder sudah ada.
    I.S         : Sistem file tidak memiliki folder "tournament_data" atau sudah memilikinya.
    F.S         : Folder "tournament_data" ada di direktori kerja saat ini.
*/

void createDataFolder() {
    const char* folder_name = "tournament_data";
    
    // Coba buat folder (akan gagal jika sudah ada, tapi tidak masalah)
#ifdef _WIN32
    // Windows
    if (mkdir(folder_name) != 0) {
        if (errno != EEXIST) {
            printf("Warning: Gagal membuat folder %s\n", folder_name);
        }
    }
#else
    // Linux/Unix
    if (mkdir(folder_name, 0755) != 0) {
        if (errno != EEXIST) {
            printf("Warning: Gagal membuat folder %s\n", folder_name);
        }
    }
#endif
}

/* Deskripsi   : Prosedur untuk membangun jalur file lengkap untuk menyimpan atau memuat data turnamen dalam format JSON. Memastikan folder data ada terlebih dahulu.
    I.S         : - tournament_name adalah string nama turnamen.
                  - output_path adalah buffer char kosong yang akan menyimpan jalur file.
                  - max_len adalah ukuran maksimum buffer output_path.
    F.S         : - Folder "tournament_data" ada.
                  - output_path berisi jalur lengkap ke file JSON (contoh: "tournament_data/NamaTurnamen.json").
*/

void createJSONPath(const char* tournament_name, char* output_path, size_t max_len) {
    createDataFolder(); // Pastikan folder ada
    snprintf(output_path, max_len, "tournament_data/%s.json", tournament_name);
}


/* Deskripsi   : Fungsi helper untuk melakukan escaping pada string agar aman digunakan dalam format JSON. Mengganti karakter khusus seperti tanda kutip ganda (") dan backslash (\) dengan urutan escape yang sesuai.
    I.S         : - input adalah string yang mungkin berisi karakter yang perlu di-escape.
                  - output adalah buffer char kosong yang akan menyimpan string yang sudah di-escape.
    F.S         : output berisi input string dengan karakter " dan \ yang di-escape.
*/

void escapeJsonString(const char* input, char* output) {
    int j = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == '"') {
            output[j++] = '\\';
            output[j++] = '"';
        } else if (input[i] == '\\') {
            output[j++] = '\\';
            output[j++] = '\\';
        } else {
            output[j++] = input[i];
        }
    }
    output[j] = '\0';
}

/* Deskripsi   : Prosedur untuk mendapatkan timestamp (tanggal dan waktu) saat ini dalam format string "YYYY-MM-DD HH:MM:SS".
    I.S         : timestamp adalah buffer char kosong dengan ukuran yang cukup.
    F.S         : timestamp berisi string representasi tanggal dan waktu saat ini.
*/

void getCurrentTimestamp(char* timestamp) {
    time_t now = time(0);
    struct tm* timeinfo = localtime(&now);
    strftime(timestamp, 20, "%Y-%m-%d %H:%M:%S", timeinfo);
}

/* Deskripsi   : Prosedur untuk menyimpan semua data turnamen (daftar tim, riwayat pertandingan, dan struktur bracket) ke dalam file JSON dengan output ke konsol. Ini adalah pembungkus untuk `saveTournamentToJSONQuiet` dengan `show_output` diatur ke true.
    I.S         : - head adalah pointer ke linked list tim yang berisi data tim yang valid.
                  - root adalah pointer ke root tree bracket turnamen yang valid (mungkin NULL jika belum ada bracket).
                  - history adalah pointer ke stack riwayat pertandingan yang valid (mungkin kosong).
                  - tournament_name adalah string nama turnamen.
                  - filename adalah string nama file tujuan.
    F.S         : Data turnamen (tim, riwayat pertandingan, dan bracket) berhasil ditulis ke file JSON yang ditentukan, dan pesan konfirmasi ditampilkan di konsol. Jika gagal, pesan kesalahan ditampilkan.
*/

void saveTournamentToJSON(addressList head, addressTree root, Stack* history, const char* tournament_name, const char* filename) {
    saveTournamentToJSONQuiet(head, root, history, tournament_name, filename, true);
}

/* Deskripsi   : Prosedur untuk menyimpan semua data turnamen (daftar tim, riwayat pertandingan, dan struktur bracket) ke dalam file JSON. Prosedur ini dapat diatur untuk menampilkan atau tidak menampilkan output ke konsol.
    I.S         : - head adalah pointer ke linked list tim yang berisi data tim yang valid.
                  - root adalah pointer ke root tree bracket turnamen yang valid (mungkin NULL jika belum ada bracket).
                  - history adalah pointer ke stack riwayat pertandingan yang valid (mungkin kosong).
                  - tournament_name adalah string nama turnamen.
                  - filename adalah string nama file tujuan.
                  - show_output adalah boolean (true untuk menampilkan output ke konsol, false untuk tidak).
    F.S         : Data turnamen (tim, riwayat pertandingan, dan bracket) berhasil ditulis ke file JSON yang ditentukan. Jika `show_output` adalah true, pesan konfirmasi ditampilkan di konsol. Jika gagal membuka file, pesan kesalahan ditampilkan.
*/

void saveTournamentToJSONQuiet(addressList head, addressTree root, Stack* history, const char* tournament_name, const char* filename, bool show_output) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Gagal membuka file %s untuk menulis.\n", filename);
        return;
    }

    char timestamp[20];
    getCurrentTimestamp(timestamp);
    int total_teams = countNode(head);

    // Header JSON
    fprintf(file, "{\n");
    fprintf(file, "  \"tournament_info\": {\n");
    fprintf(file, "    \"name\": \"%s\",\n", tournament_name);
    fprintf(file, "    \"total_teams\": %d,\n", total_teams);
    fprintf(file, "    \"created_date\": \"%s\",\n", timestamp);
    fprintf(file, "    \"format\": \"single_elimination\"\n");
    fprintf(file, "  },\n");

    // Teams section
    fprintf(file, "  \"teams\": [\n");
    addressList current = head;
    bool first_team = true;
    while (current != NULL) {
        if (!first_team) {
            fprintf(file, ",\n");
        }
        
        char escaped_name[100];
        escapeJsonString(current->namaTim, escaped_name);
        
        float win_rate = 0.0f;
        if (current->laga > 0) {
            win_rate = ((float)current->kemenangan / (float)current->laga) * 100.0f;
        }
        
        fprintf(file, "    {\n");
        fprintf(file, "      \"id\": %d,\n", current->id_tim);
        fprintf(file, "      \"name\": \"%s\",\n", escaped_name);
        fprintf(file, "      \"matches_played\": %d,\n", current->laga);
        fprintf(file, "      \"wins\": %d,\n", current->kemenangan);
        fprintf(file, "      \"losses\": %d,\n", current->kekalahan);
        fprintf(file, "      \"win_rate\": %.1f\n", win_rate);
        fprintf(file, "    }");
        
        first_team = false;
        current = current->next;
    }
    fprintf(file, "\n  ],\n");

    // Matches section (dari history)
    fprintf(file, "  \"match_history\": [\n");
    if (!apakahStackKosong(history)) {
        // Convert stack to array untuk reverse order
        MatchResult matches[100]; // Asumsi max 100 matches
        int match_count = 0;
        
        Stack tempStack;
        inisialisasiStack(&tempStack);
        MatchResult result;
        
        // Pop semua dari history ke temp stack (tanpa output debug)
        while (pop(history, &result)) {
            matches[match_count++] = result;
            push(&tempStack, result);
        }
        
        // Restore history (tanpa output debug)
        while (pop(&tempStack, &result)) {
            push(history, result);
        }
        
        // Print matches dalam urutan chronological
        for (int i = match_count - 1; i >= 0; i--) {
            if (i < match_count - 1) {
                fprintf(file, ",\n");
            }
            
            fprintf(file, "    {\n");
            fprintf(file, "      \"match_id\": %d,\n", matches[i].matchID);
            fprintf(file, "      \"team1_id\": %d,\n", matches[i].team1Id);
            fprintf(file, "      \"team2_id\": %d,\n", matches[i].team2Id);
            fprintf(file, "      \"winner_id\": %d,\n", matches[i].idPemenang);
            fprintf(file, "      \"round\": %d,\n", matches[i].nomorRonde);
            fprintf(file, "      \"score\": {\n");
            fprintf(file, "        \"team1\": %d,\n", matches[i].skorTim1);
            fprintf(file, "        \"team2\": %d\n", matches[i].skorTim2);
            fprintf(file, "      }\n");
            fprintf(file, "    }");
        }
    }
    fprintf(file, "\n  ],\n");

    // Tournament bracket structure
    fprintf(file, "  \"bracket\": ");
    saveBracketToJSON(file, root, 2);
    
    // Footer JSON
    fprintf(file, "\n}\n");

    fclose(file);
    
    // Output hanya jika diminta
    if (show_output) {
        printf("Data turnamen berhasil disimpan ke %s dalam format JSON.\n", filename);
    }
}

/* Deskripsi   : Fungsi helper rekursif untuk menulis struktur bracket turnamen (binary tree) ke dalam file JSON dengan format indentasi yang sesuai.
    I.S         : - file adalah pointer ke file yang sudah terbuka untuk ditulis.
                  - treeNode adalah pointer ke node pohon bracket saat ini yang akan ditulis.
                  - indent adalah tingkat indentasi saat ini untuk format JSON.
    F.S         : Struktur node bracket saat ini, beserta anak-anaknya (jika ada), telah ditulis ke dalam file JSON dengan indentasi yang benar.
*/

void saveBracketToJSON(FILE* file, addressTree treeNode, int indent) {
    if (treeNode == NULL) {
        fprintf(file, "null");
        return;
    }

    char indent_str[50] = "";
    for (int i = 0; i < indent; i++) {
        strcat(indent_str, "  ");
    }

    fprintf(file, "{\n");
    fprintf(file, "%s  \"match_id\": %d,\n", indent_str, treeNode->match_id);
    fprintf(file, "%s  \"team1_id\": %d,\n", indent_str, treeNode->id_tim1);
    fprintf(file, "%s  \"team2_id\": %d,\n", indent_str, treeNode->id_tim2);
    fprintf(file, "%s  \"winner_id\": %d,\n", indent_str, treeNode->id_pemenang);
    
    if (treeNode->left != NULL || treeNode->right != NULL) {
        fprintf(file, "%s  \"left_match\": ", indent_str);
        saveBracketToJSON(file, treeNode->left, indent + 1);
        fprintf(file, ",\n");
        
        fprintf(file, "%s  \"right_match\": ", indent_str);
        saveBracketToJSON(file, treeNode->right, indent + 1);
        fprintf(file, "\n");
    } else {
        fprintf(file, "%s  \"left_match\": null,\n", indent_str);
        fprintf(file, "%s  \"right_match\": null\n", indent_str);
    }
    
    fprintf(file, "%s}", indent_str);
}


void rebuildMatchResultsFromHistory(addressTree root, Stack* history, addressList head) {
    (void)head; // Suppress unused parameter warning
    
    if (root == NULL || history == NULL || apakahStackKosong(history)) {
        return; // Silent jika tidak ada data
    }
    
    // Convert stack ke array untuk proses dari pertandingan paling awal
    MatchResult matches[100]; // Asumsi max 100 matches
    int match_count = 0;
    
    // Pop semua dari history ke array (simpan order chronological)
    Stack tempStack;
    inisialisasiStack(&tempStack);
    MatchResult result;
    
    // Silent processing - tanpa debug output
    while (pop(history, &result)) {
        matches[match_count++] = result;
        push(&tempStack, result);
    }
    
    // Restore history seperti semula
    while (pop(&tempStack, &result)) {
        push(history, result);
    }
    
    // Terapkan hasil pertandingan dari yang paling awal (reverse order)
    for (int i = match_count - 1; i >= 0; i--) {
        addressTree match_node = findMatchNode(root, matches[i].matchID);
        if (match_node != NULL) {
            // Update pemenang
            match_node->id_pemenang = matches[i].idPemenang;
            
            // Update parent nodes agar peserta selanjutnya ter-update
            updateParentNodes(root, match_node);
        }
    }
    
    // Silent processing - tidak ada output
    if (match_count > 0) {
        // Proses berhasil, tapi tidak perlu output
    }
}

/* Deskripsi   : Fungsi untuk memuat semua data turnamen (informasi turnamen, daftar tim, riwayat pertandingan, dan struktur bracket) dari file JSON yang ditentukan. Ini mengalokasikan memori untuk struktur data dan mengisi mereka berdasarkan konten file.
    I.S         : filename adalah string nama file JSON yang akan dibaca.
    F.S         : - Mengembalikan pointer ke struktur TournamentData yang berisi data turnamen yang dimuat.
                  - Jika file tidak ditemukan atau gagal dibaca, atau parsing gagal, mengembalikan NULL dan menampilkan pesan kesalahan.
                  - Jika berhasil, data turnamen dimuat ke dalam memori.
*/

TournamentData* loadTournamentFromJSON(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Gagal membuka file %s untuk membaca.\n", filename);
        return NULL;
    }

    // Baca seluruh file ke dalam buffer
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    
    if (file_size <= 0) {
        printf("File kosong atau error membaca ukuran file.\n");
        fclose(file);
        return NULL;
    }
    
    char* json_content = malloc((size_t)file_size + 1);
    if (json_content == NULL) {
        printf("Gagal mengalokasi memori untuk membaca file.\n");
        fclose(file);
        return NULL;
    }
    
    fread(json_content, 1, (size_t)file_size, file);
    json_content[file_size] = '\0';
    fclose(file);

    // Parse JSON sederhana (manual parsing)
    TournamentData* data = malloc(sizeof(TournamentData));
    if (data == NULL) {
        free(json_content);
        return NULL;
    }

    // Initialize data
    data->head = NULL;
    data->root = NULL;
    data->history = malloc(sizeof(Stack));
    inisialisasiStack(data->history);
    strcpy(data->tournament_name, "");

    // Parse tournament info
    parseJsonString(json_content, "name", data->tournament_name, sizeof(data->tournament_name));
    
    // Parse teams
    data->head = parseJsonTeams(json_content);
    
    // Parse match history
    parseJsonMatches(json_content, data->history);
    
    if (data->head != NULL) {
        int total_teams = countNode(data->head);
        
        if (total_teams >= 3 && total_teams <= 12) {
            // Buat queue untuk rebuild tournament tree
            Queue tempQueue;
            initQueue(&tempQueue);
            
            // Masukkan semua tim ke queue (silent)
            addressList temp = data->head;
            while (temp != NULL) {
                enqueue(&tempQueue, temp);
                temp = temp->next;
            }
            
            // Rebuild tournament tree
            data->root = buildTournamentTree(&tempQueue, total_teams, data->head);
            
            // Cleanup queue
            clearQueue(&tempQueue);
            
            if (data->root != NULL) {
                // PENTING: Terapkan kembali hasil pertandingan dari history
                if (!apakahStackKosong(data->history)) {
                    rebuildMatchResultsFromHistory(data->root, data->history, data->head);
                }
            }
        }
    }
    free(json_content);
    
    if (data->head != NULL) {
        // Silent success - tidak ada output loading
        return data;
    } else {
        printf("Gagal memuat data turnamen dari %s.\n", filename);
        if (data->history != NULL) {
            clearStack(data->history);
            free(data->history);
        }
        free(data);
        return NULL;
    }
}

/* Deskripsi   : Fungsi helper untuk mengekstrak nilai string dari objek JSON berdasarkan kunci yang diberikan.
    I.S         : - json adalah string konten JSON lengkap.
                  - key adalah string kunci yang nilainya ingin diekstrak.
                  - output adalah buffer char kosong yang akan menyimpan nilai string yang diekstrak.
                  - max_len adalah ukuran maksimum buffer output.
    F.S         : output berisi nilai string yang ditemukan untuk kunci yang diberikan. Jika kunci tidak ditemukan atau terjadi kesalahan parsing, output akan menjadi string kosong.
*/
void parseJsonString(const char* json, const char* key, char* output, int max_len) {
    char search_pattern[100];
    snprintf(search_pattern, sizeof(search_pattern), "\"%s\": \"", key);
    
    char* start = strstr(json, search_pattern);
    if (start == NULL) {
        output[0] = '\0';
        return;
    }
    
    start += strlen(search_pattern);
    char* end = strchr(start, '"');
    if (end == NULL) {
        output[0] = '\0';
        return;
    }
    
    ptrdiff_t len_diff = end - start;
    if (len_diff < 0 || len_diff >= max_len) {
        output[0] = '\0';
        return;
    }
    
    size_t len = (size_t)len_diff;
    strncpy(output, start, len);
    output[len] = '\0';
}

/* Deskripsi   : Fungsi helper untuk melakukan parsing bagian "teams" dari konten JSON dan membangun kembali linked list tim yang sesuai. Ini mengekstrak detail setiap tim dan membuat node linked list baru.
    I.S         : json adalah string konten JSON lengkap yang berisi bagian "teams".
    F.S         : Mengembalikan pointer ke head dari linked list tim yang baru dibuat, yang berisi data tim dari JSON. Jika bagian "teams" tidak ditemukan atau kosong, mengembalikan NULL.
*/

addressList parseJsonTeams(const char* json) {
    addressList head = NULL;
    
    char* teams_start = strstr(json, "\"teams\": [");
    if (teams_start == NULL) return NULL;
    
    teams_start += strlen("\"teams\": [");
    char* teams_end = strstr(teams_start, "],");
    if (teams_end == NULL) return NULL;
    
    // Simple parsing - look for team objects
    char* current = teams_start;
    while (current < teams_end) {
        char* team_start = strstr(current, "{");
        if (team_start == NULL || team_start >= teams_end) break;
        
        char* team_end = strstr(team_start, "}");
        if (team_end == NULL || team_end >= teams_end) break;
        
        // Parse team data
        int id = 0, wins = 0, losses = 0, matches = 0;
        char name[50] = "";
        
        // Extract values (simple parsing) - fix conversion warning
        ptrdiff_t team_len_diff = team_end - team_start + 1;
        if (team_len_diff <= 0 || team_len_diff > 500) {
            current = team_end + 1;
            continue;
        }
        
        size_t team_len = (size_t)team_len_diff;
        char team_json[500];
        strncpy(team_json, team_start, team_len);
        team_json[team_len] = '\0';
        
        // Parse each field
        char* id_pos = strstr(team_json, "\"id\":");
        if (id_pos != NULL) {
            sscanf(id_pos, "\"id\": %d", &id);
        }
        
        parseJsonString(team_json, "name", name, sizeof(name));
        
        char* wins_pos = strstr(team_json, "\"wins\":");
        if (wins_pos != NULL) {
            sscanf(wins_pos, "\"wins\": %d", &wins);
        }
        
        char* losses_pos = strstr(team_json, "\"losses\":");
        if (losses_pos != NULL) {
            sscanf(losses_pos, "\"losses\": %d", &losses);
        }
        
        char* matches_pos = strstr(team_json, "\"matches_played\":");
        if (matches_pos != NULL) {
            sscanf(matches_pos, "\"matches_played\": %d", &matches);
        }
        
        // Create team node
        addressList newNode = createNode(name);
        if (newNode != NULL) {
            newNode->id_tim = id;
            newNode->laga = matches;
            newNode->kemenangan = wins;
            newNode->kekalahan = losses;
            insertAtLast(&head, newNode);
        }
        
        current = team_end + 1;
    }
    
    return head;
}

/* Deskripsi   : Fungsi helper untuk melakukan parsing bagian "match_history" dari konten JSON dan mengisi stack riwayat pertandingan. Setiap hasil pertandingan diekstrak dan didorong ke dalam stack.
    I.S         : - json adalah string konten JSON lengkap yang berisi bagian "match_history".
                  - history adalah pointer ke stack yang sudah diinisialisasi.
    F.S         : Stack history berisi semua hasil pertandingan yang ditemukan di bagian "match_history" dalam JSON. Jika bagian tersebut kosong atau tidak ditemukan, stack tetap tidak berubah.
*/

void parseJsonMatches(const char* json, Stack* history) {
    char* matches_start = strstr(json, "\"match_history\": [");
    if (matches_start == NULL) return;
    
    matches_start += strlen("\"match_history\": [");
    char* matches_end = strstr(matches_start, "],");
    if (matches_end == NULL) return;
    
    // Parse matches and push to stack
    char* current = matches_start;
    while (current < matches_end) {
        char* match_start = strstr(current, "{");
        if (match_start == NULL || match_start >= matches_end) break;
        
        char* match_end = strstr(match_start, "}");
        if (match_end == NULL || match_end >= matches_end) break;
        
        // Parse match data - fix conversion warning
        MatchResult result = {0};
        
        ptrdiff_t match_len_diff = match_end - match_start + 1;
        if (match_len_diff <= 0 || match_len_diff > 300) {
            current = match_end + 1;
            continue;
        }
        
        size_t match_len = (size_t)match_len_diff;
        char match_json[300];
        strncpy(match_json, match_start, match_len);
        match_json[match_len] = '\0';
        
        char* match_id_pos = strstr(match_json, "\"match_id\":");
        if (match_id_pos != NULL) {
            sscanf(match_id_pos, "\"match_id\": %d", &result.matchID);
        }
        
        char* team1_pos = strstr(match_json, "\"team1_id\":");
        if (team1_pos != NULL) {
            sscanf(team1_pos, "\"team1_id\": %d", &result.team1Id);
        }
        
        char* team2_pos = strstr(match_json, "\"team2_id\":");
        if (team2_pos != NULL) {
            sscanf(team2_pos, "\"team2_id\": %d", &result.team2Id);
        }
        
        char* winner_pos = strstr(match_json, "\"winner_id\":");
        if (winner_pos != NULL) {
            sscanf(winner_pos, "\"winner_id\": %d", &result.idPemenang);
        }
        
        char* round_pos = strstr(json, "\"round\":");
        if (round_pos != NULL) {
            sscanf(round_pos, "\"round\": %d", &result.nomorRonde);
        }
        
        // Parse score object
        char* score_start = strstr(match_json, "\"score\": {");
        if (score_start != NULL) {
            char* team1_score = strstr(score_start, "\"team1\":");
            if (team1_score != NULL) {
                sscanf(team1_score, "\"team1\": %d", &result.skorTim1);
            }
            
            char* team2_score = strstr(score_start, "\"team2\":");
            if (team2_score != NULL) {
                sscanf(team2_score, "\"team2\": %d", &result.skorTim2);
            }
        }
        
        push(history, result);
        current = match_end + 1;
    }
}