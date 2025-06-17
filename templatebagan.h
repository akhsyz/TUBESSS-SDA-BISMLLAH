/*
PIC : aufa
NIM : 241524052
*/

#ifndef TEMPLATEBAGAN_H
#define TEMPLATEBAGAN_H

#include "results.h"

void templatebagan3tim(addressTree root, addressList head, Stack *history);
/* Deskripsi   : Menampilkan struktur bagan turnamen untuk 3 tim, yang terdiri dari satu pertandingan semifinal dan satu pertandingan final (dengan satu tim menerima BYE).
    I.S         : - `root` adalah pointer ke root pohon bracket turnamen yang sudah terbentuk untuk 3 tim.
                  - `head` adalah pointer ke head linked list tim.
                  - `history` adalah pointer ke stack riwayat pertandingan (tidak digunakan secara langsung untuk tampilan ini).
    F.S         : Struktur bagan turnamen untuk 3 tim (semifinal dan final) ditampilkan di konsol, termasuk status pertandingan dan informasi tim/pemenang.
*/
void templatebagan4tim(addressTree root, addressList head, Stack *history);
/* Deskripsi   : Menampilkan struktur bagan turnamen untuk 4 tim, yang terdiri dari dua pertandingan semifinal dan satu pertandingan final.
    I.S         : - `root` adalah pointer ke root pohon bracket turnamen yang sudah terbentuk untuk 4 tim.
                  - `head` adalah pointer ke head linked list tim.
                  - `history` adalah pointer ke stack riwayat pertandingan (tidak digunakan secara langsung untuk tampilan ini).
    F.S         : Struktur bagan turnamen untuk 4 tim (semifinal dan final) ditampilkan di konsol, termasuk status pertandingan dan informasi tim/pemenang.
*/
void templatebagan5tim(addressTree root, addressList head, Stack *history);
/* Deskripsi   : Menampilkan struktur bagan turnamen untuk 5 tim, yang terdiri dari pertandingan babak pertama, semifinal, dan final.
    I.S         : - `root` adalah pointer ke root pohon bracket turnamen yang sudah terbentuk untuk 5 tim.
                  - `head` adalah pointer ke head linked list tim.
                  - `history` adalah pointer ke stack riwayat pertandingan (tidak digunakan secara langsung untuk tampilan ini).
    F.S         : Struktur bagan turnamen untuk 5 tim (babak pertama, semifinal, dan final) ditampilkan di konsol, termasuk status pertandingan dan informasi tim/pemenang.
*/
void templatebagan6tim(addressTree root, addressList head, Stack *history);
/* Deskripsi   : Menampilkan struktur bagan turnamen untuk 6 tim, yang terdiri dari pertandingan babak pertama, semifinal, dan final.
    I.S         : - `root` adalah pointer ke root pohon bracket turnamen yang sudah terbentuk untuk 6 tim.
                  - `head` adalah pointer ke head linked list tim.
                  - `history` adalah pointer ke stack riwayat pertandingan (tidak digunakan secara langsung untuk tampilan ini).
    F.S         : Struktur bagan turnamen untuk 6 tim (babak pertama, semifinal, dan final) ditampilkan di konsol, termasuk status pertandingan dan informasi tim/pemenang.
*/
void templatebagan7tim(addressTree root, addressList head, Stack *history);
/* Deskripsi   : Menampilkan struktur bagan turnamen untuk 7 tim, yang terdiri dari pertandingan babak pertama, perempat final, semifinal, dan final, dengan mengatur tampilan berdasarkan level kedalaman dalam pohon bracket.
    I.S         : - `root` adalah pointer ke root pohon bracket turnamen yang sudah terbentuk untuk 7 tim.
                  - `head` adalah pointer ke head linked list tim.
                  - `history` adalah pointer ke stack riwayat pertandingan (tidak digunakan secara langsung untuk tampilan ini).
    F.S         : Struktur bagan turnamen untuk 7 tim (babak pertama, perempat final, semifinal, dan final) ditampilkan di konsol, termasuk status pertandingan dan informasi tim/pemenang.
*/
void templatebagan8tim(addressTree root, addressList head, Stack *history);
/* Deskripsi   : Menampilkan struktur bagan turnamen untuk 8 tim, yang terdiri dari pertandingan perempat final, semifinal, dan final.
    I.S         : - `root` adalah pointer ke root pohon bracket turnamen yang sudah terbentuk untuk 8 tim.
                  - `head` adalah pointer ke head linked list tim.
                  - `history` adalah pointer ke stack riwayat pertandingan (tidak digunakan secara langsung untuk tampilan ini).
    F.S         : Struktur bagan turnamen untuk 8 tim (perempat final, semifinal, dan final) ditampilkan di konsol, termasuk status pertandingan dan informasi tim/pemenang.
*/
void templatebagan9tim(addressTree root, addressList head, Stack *history);
/* Deskripsi   : Menampilkan struktur bagan turnamen untuk 9 tim, yang terdiri dari pertandingan babak pertama, perempat final, semifinal, dan final, dengan mengatur tampilan berdasarkan level kedalaman dalam pohon bracket.
    I.S         : - `root` adalah pointer ke root pohon bracket turnamen yang sudah terbentuk untuk 9 tim.
                  - `head` adalah pointer ke head linked list tim.
                  - `history` adalah pointer ke stack riwayat pertandingan (tidak digunakan secara langsung untuk tampilan ini).
    F.S         : Struktur bagan turnamen untuk 9 tim (babak pertama, perempat final, semifinal, dan final) ditampilkan di konsol, termasuk status pertandingan dan informasi tim/pemenang.
*/
void templatebagan10tim(addressTree root, addressList head, Stack *history);
/* Deskripsi   : Menampilkan struktur bagan turnamen untuk 10 tim, yang terdiri dari pertandingan babak pertama, perempat final, semifinal, dan final, dengan mengatur tampilan berdasarkan level kedalaman dalam pohon bracket.
    I.S         : - `root` adalah pointer ke root pohon bracket turnamen yang sudah terbentuk untuk 10 tim.
                  - `head` adalah pointer ke head linked list tim.
                  - `history` adalah pointer ke stack riwayat pertandingan (tidak digunakan secara langsung untuk tampilan ini).
    F.S         : Struktur bagan turnamen untuk 10 tim (babak pertama, perempat final, semifinal, dan final) ditampilkan di konsol, termasuk status pertandingan dan informasi tim/pemenang.
*/
void templatebagan11tim(addressTree root, addressList head, Stack *history);
/* Deskripsi   : Menampilkan struktur bagan turnamen untuk 11 tim, yang terdiri dari pertandingan babak pertama, perempat final, semifinal, dan final, dengan mengatur tampilan berdasarkan level kedalaman dalam pohon bracket.
    I.S         : - `root` adalah pointer ke root pohon bracket turnamen yang sudah terbentuk untuk 11 tim.
                  - `head` adalah pointer ke head linked list tim.
                  - `history` adalah pointer ke stack riwayat pertandingan (tidak digunakan secara langsung untuk tampilan ini).
    F.S         : Struktur bagan turnamen untuk 11 tim (babak pertama, perempat final, semifinal, dan final) ditampilkan di konsol, termasuk status pertandingan dan informasi tim/pemenang.
*/
void templatebagan12tim(addressTree root, addressList head, Stack *history);
/* Deskripsi   : Menampilkan struktur bagan turnamen untuk 12 tim, yang terdiri dari pertandingan babak pertama, perempat final, semifinal, dan final, dengan mengatur tampilan berdasarkan level kedalaman dalam pohon bracket. Struktur ini dioptimalkan untuk meminimalkan BYE.
    I.S         : - `root` adalah pointer ke root pohon bracket turnamen yang sudah terbentuk untuk 12 tim.
                  - `head` adalah pointer ke head linked list tim.
                  - `history` adalah pointer ke stack riwayat pertandingan (tidak digunakan secara langsung untuk tampilan ini).
    F.S         : Struktur bagan turnamen untuk 12 tim (babak pertama, perempat final, semifinal, dan final) ditampilkan di konsol, termasuk status pertandingan dan informasi tim/pemenang.
*/
void displayTreeStructure(addressTree root, addressList head, Stack *history, int depth);
/* Deskripsi   : Fungsi rekursif untuk menampilkan struktur pohon bracket turnamen secara keseluruhan dengan indentasi yang menunjukkan kedalaman setiap node. Ini adalah fungsi tampilan umum yang bisa digunakan sebagai fallback.
    I.S         : - `root` adalah pointer ke node pohon bracket turnamen saat ini.
                  - `head` adalah pointer ke head linked list tim.
                  - `history` adalah pointer ke stack riwayat pertandingan (tidak digunakan secara langsung untuk tampilan ini, hanya untuk konsistensi parameter).
                  - `depth` adalah tingkat kedalaman node saat ini dari root (root adalah 0).
    F.S         : Struktur pohon bracket turnamen, termasuk ID pertandingan, nama tim yang terlibat, dan pemenang (jika ada), ditampilkan di konsol dengan indentasi yang sesuai.
*/
void displayMatchesByRound(addressTree root, addressList head, int target_round);
/* Deskripsi   : Fungsi rekursif untuk menampilkan informasi pertandingan yang berada di babak (`round`) tertentu dalam pohon bracket turnamen. Ini adalah fungsi fallback yang mungkin kurang efisien untuk jumlah tim tertentu dibandingkan fungsi `displayMatchesByLevelSpecific` yang baru.
    I.S         : - `root` adalah pointer ke node pohon bracket turnamen saat ini.
                  - `head` adalah pointer ke head linked list tim.
                  - `target_round` adalah nomor babak yang ingin ditampilkan.
    F.S         : Informasi pertandingan untuk semua node pada `target_round` ditampilkan di konsol. Status pertandingan dan informasi tim/pemenang juga ditampilkan.
*/
void getTeamName(int id_tim, addressList head, char *output);
/* Deskripsi   : Fungsi helper untuk mendapatkan nama tim dari linked list berdasarkan ID tim. Jika ID tim adalah 0 atau negatif (menunjukkan BYE), akan mengembalikan "BYE". Jika tim tidak ditemukan, akan mengembalikan "Tim-ID". Nama tim akan dipotong jika melebihi 19 karakter.
    I.S         : - `id_tim` adalah integer ID tim yang akan dicari namanya.
                  - `head` adalah pointer ke head linked list tim.
                  - `output` adalah buffer karakter untuk menyimpan nama tim.
    F.S         : `output` berisi nama tim yang sesuai, "BYE", atau "Tim-ID", dengan panjang maksimal 19 karakter ditambah null terminator.
*/
void getMatchScore(int match_id, Stack *history, int *skor1, int *skor2);
/* Deskripsi   : Fungsi helper untuk mengambil skor tim1 dan tim2 dari riwayat pertandingan (stack) berdasarkan ID pertandingan.
    I.S         : - `match_id` adalah ID pertandingan yang skornya ingin dicari.
                  - `history` adalah pointer ke stack riwayat pertandingan.
                  - `skor1` dan `skor2` adalah pointer ke integer yang akan menyimpan skor.
    F.S         : - `skor1` dan `skor2` akan berisi skor tim1 dan tim2 dari pertandingan yang sesuai.
                  - Jika pertandingan tidak ditemukan atau stack kosong, `skor1` dan `skor2` tetap 0.
                  - Stack `history` tidak berubah.
*/
void displayMatchInfo(addressTree match, addressList head);
/* Deskripsi   : Fungsi helper untuk menampilkan informasi detail pertandingan (Match ID, nama tim, status pertandingan, dan pemenang jika ada).
    I.S         : - `match` adalah pointer ke node pertandingan dalam pohon bracket.
                  - `head` adalah pointer ke head linked list tim.
    F.S         : Informasi pertandingan ditampilkan di konsol. Status bisa "vs [SIAP DIMAINKAN]", "vs TBD [MENUNGGU]", atau ">> Menang: [Nama Pemenang]".
*/
void displayLeafMatches(addressTree root, addressList head);
/* Deskripsi   : Fungsi rekursif untuk menampilkan informasi pertandingan dari semua node daun (leaf nodes) dalam pohon bracket turnamen. Ini biasanya mewakili pertandingan babak pertama.
    I.S         : - `root` adalah pointer ke root pohon bracket turnamen.
                  - `head` adalah pointer ke head linked list tim.
    F.S         : Informasi pertandingan untuk setiap node daun dalam pohon ditampilkan di konsol.
*/
void displaySemifinalMatches(addressTree root, addressList head);
/* Deskripsi   : Fungsi rekursif untuk menampilkan informasi pertandingan dari node-node yang berada di level semifinal dalam pohon bracket turnamen. Ini mengidentifikasi node yang merupakan anak dari root dan memiliki anak sendiri (bukan daun).
    I.S         : - `root` adalah pointer ke root pohon bracket turnamen.
                  - `head` adalah pointer ke head linked list tim.
    F.S         : Informasi pertandingan untuk node-node semifinal dalam pohon ditampilkan di konsol.
*/
void displayFinalMatch(addressTree root, addressList head);
/* Deskripsi   : Fungsi untuk menampilkan informasi pertandingan final turnamen.
    I.S         : - `root` adalah pointer ke root pohon bracket turnamen (yang mewakili pertandingan final).
                  - `head` adalah pointer ke head linked list tim.
    F.S         : Informasi pertandingan final ditampilkan di konsol.
*/
void displayQuarterFinalMatches(addressTree root, addressList head);
/* Deskripsi   : Fungsi pembungkus untuk memanggil fungsi helper rekursif `displayQuarterFinalHelper` guna menampilkan semua pertandingan di babak perempat final.
    I.S         : - `root` adalah pointer ke root pohon bracket turnamen.
                  - `head` adalah pointer ke head linked list tim.
    F.S         : Memanggil `displayQuarterFinalHelper` untuk menampilkan informasi pertandingan di level perempat final.
*/
void displayQuarterFinalHelper(addressTree root, addressList head, int level);
/* Deskripsi   : Fungsi helper rekursif untuk menampilkan informasi pertandingan pada level tertentu dalam pohon bracket. Ini digunakan untuk mengidentifikasi dan menampilkan pertandingan di babak perempat final (level 2 dari root, dengan root sebagai level 0).
    I.S         : - `root` adalah pointer ke node pohon bracket turnamen saat ini.
                  - `head` adalah pointer ke head linked list tim.
                  - `level` adalah level kedalaman saat ini dari root (root adalah level 0).
    F.S         : Informasi pertandingan untuk node-node pada `target_level` (yaitu 2 untuk perempat final) ditampilkan di konsol.
*/
void displayMatchesByLevelSpecific(addressTree root, addressList head, int target_level, int current_level);
/* Deskripsi   : Fungsi rekursif yang fleksibel untuk menampilkan informasi pertandingan di semua node pada level kedalaman tertentu dalam pohon bracket turnamen.
    I.S         : - `root` adalah pointer ke node pohon bracket turnamen saat ini.
                  - `head` adalah pointer ke head linked list tim.
                  - `target_level` adalah level kedalaman yang ingin ditampilkan (root adalah level 0).
                  - `current_level` adalah level kedalaman node `root` saat ini.
    F.S         : Informasi pertandingan untuk semua node pada `target_level` ditampilkan di konsol.
*/
#endif
