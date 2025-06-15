#include "fileio.h"
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <sys/stat.h>  
#include <errno.h>     

void createDataFolder() {
    const char* folder_name = "tournament_data";
    
#ifdef _WIN32
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

void createJSONPath(const char* tournament_name, char* output_path, size_t max_len) {
    createDataFolder(); // Pastikan folder ada
    snprintf(output_path, max_len, "tournament_data/%s.json", tournament_name);
}

// Fungsi helper untuk escape string dalam JSON
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

// Fungsi untuk mendapatkan timestamp saat ini
void getCurrentTimestamp(char* timestamp) {
    time_t now = time(0);
    struct tm* timeinfo = localtime(&now);
    strftime(timestamp, 20, "%Y-%m-%d %H:%M:%S", timeinfo);
}

// Fungsi untuk menyimpan semua data turnamen dalam format JSON
void saveTournamentToJSON(addressList head, addressTree root, Stack* history, const char* tournament_name, const char* filename) {
    saveTournamentToJSONQuiet(head, root, history, tournament_name, filename, true);
}

// Fungsi untuk menyimpan tanpa output verbose (untuk exit yang clean)
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

// Fungsi helper untuk menyimpan bracket structure ke JSON - ganti nama parameter
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

// Fungsi untuk memuat semua data turnamen dari JSON - fix conversion warnings
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
    
    // Parse bracket (basic reconstruction)
    data->root = parseJsonBracket(json_content);

    free(json_content);
    
    if (data->head != NULL) {
        printf("Data turnamen '%s' berhasil dimuat dari %s.\n", data->tournament_name, filename);
        return data;
    } else {
        printf("Gagal memuat data turnamen dari %s.\n", filename);
        free(data->history);
        free(data);
        return NULL;
    }
}

// Fungsi helper untuk parsing JSON string value - fix conversion warning
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

// Fungsi helper untuk parsing teams dari JSON - fix conversion warning
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
