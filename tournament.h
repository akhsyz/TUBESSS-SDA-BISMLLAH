/*
PIC : belva 
NIM : 241524035
*/

#ifndef TOURNAMENT_H
#define TOURNAMENT_H

#include "templatebagan.h"


void tambahTim(addressList *head);
/* Deskripsi   : Prosedur untuk memungkinkan pengguna menambah sejumlah tim baru ke linked list. Meminta jumlah tim yang akan ditambahkan, lalu mengulang untuk setiap tim untuk meminta nama. Memvalidasi input jumlah tim dan nama tim, serta mencegah penambahan tim dengan nama yang sudah ada.
    I.S        : - `head` adalah pointer ke head linked list tim (bisa kosong).
                  - Pengguna siap untuk menginput jumlah dan nama tim.
    F.S        : - Linked list `head` berisi tim-tim baru yang berhasil ditambahkan.
                  - Jika input tidak valid atau tim sudah terdaftar, pesan kesalahan ditampilkan, dan proses input mungkin diulang.
                  - Pesan konfirmasi jumlah total tim yang ditambahkan ditampilkan.
*/

void hapusTim(addressList *head);
/* Deskripsi   : Prosedur untuk memungkinkan pengguna menghapus tim dari linked list berdasarkan namanya. Sebelum menghapus, prosedur ini menampilkan daftar tim yang ada dan memvalidasi apakah nama tim yang dimasukkan benar-benar ada.
    I.S        : - `head` adalah pointer ke head linked list tim.
                  - Pengguna siap untuk menginput nama tim yang akan dihapus.
    F.S        : - Jika linked list kosong, pesan "Daftar tim kosong." ditampilkan.
                  - Jika tim ditemukan, tim tersebut dihapus dari linked list `head`, dan pesan konfirmasi ditampilkan.
                  - Jika tim tidak ditemukan atau input tidak valid, pesan kesalahan ditampilkan, dan linked list tidak berubah.
*/

void jadwalkanPertandingan(addressList head, Queue *matchQueue, TournamentTree **tournamentTree, Stack *matchHistory);
/* Deskripsi   : Prosedur untuk menjadwalkan pertandingan turnamen berdasarkan jumlah tim yang terdaftar. Fungsi ini memvalidasi jumlah tim, membersihkan struktur turnamen dan antrean pertandingan yang mungkin ada sebelumnya, membangun pohon bracket turnamen baru, dan menampilkan ringkasan penjadwalan.
    I.S        : - `head` adalah pointer ke head linked list tim yang berisi tim-tim peserta.
                  - `matchQueue` adalah pointer ke antrean pertandingan (mungkin berisi sisa pertandingan dari turnamen sebelumnya).
                  - `tournamentTree` adalah pointer ke pohon bracket turnamen (mungkin berisi struktur dari turnamen sebelumnya).
                  - Pengguna memilih opsi untuk menjadwalkan pertandingan.
    F.S        : - Jika jumlah tim tidak memenuhi syarat (kurang dari 3 atau lebih dari 12), pesan kesalahan ditampilkan, dan tidak ada penjadwalan yang terjadi.
                  - Jika turnamen sudah dijadwalkan, pengguna ditanya konfirmasi untuk membuat yang baru; jika dikonfirmasi, turnamen lama dibersihkan.
                  - `matchQueue` dikosongkan dan diisi ulang dengan tim dari `head`.
                  - `tournamentTree` dibangun atau dibangun ulang menjadi struktur bracket yang valid berdasarkan tim yang ada.
                  - Pesan sukses penjadwalan ditampilkan, termasuk total tim, total babak, sistem turnamen, dan daftar pertandingan awal yang siap dimainkan.
                  - Panduan menu selanjutnya ditampilkan.
*/

void tampilkanPertandinganSiap(addressTree root, int target_round);
/* Deskripsi   : Fungsi rekursif (lama) untuk menampilkan daftar pertandingan yang siap dimainkan atau yang sudah selesai pada babak target tertentu, hanya menampilkan ID tim. Ini digunakan untuk kompatibilitas mundur.
    I.S         : - `root` adalah pointer ke node pohon bracket turnamen saat ini.
                  - `target_round` adalah nomor babak yang ingin ditampilkan pertandingannya.
    F.S         : Daftar pertandingan pada `target_round` ditampilkan di konsol, dengan status "SIAP", "SELESAI", "BYE", atau "Menunggu".
*/

void tampilkanPertandinganTersedia(addressTree root, addressList head);
/* Deskripsi   : Fungsi rekursif untuk menampilkan semua pertandingan dalam pohon bracket yang siap untuk dimainkan (kedua tim sudah ditentukan dan belum ada pemenang). Menampilkan nama tim jika ditemukan di linked list.
    I.S         : - `root` adalah pointer ke node pohon bracket turnamen saat ini.
                  - `head` adalah pointer ke head linked list tim.
    F.S         : Daftar pertandingan yang siap dimainkan (dengan ID pertandingan, nomor babak, dan nama tim) ditampilkan di konsol.
*/
void cekStatusTurnamen(addressTree root);
/* Deskripsi   : Fungsi rekursif untuk mengecek status keseluruhan turnamen (apakah sudah selesai atau masih berlangsung). Jika turnamen sudah selesai (pemenang di node root sudah ditentukan), akan menampilkan juara. Jika belum, akan menampilkan pertandingan yang masih bisa dimainkan.
    I.S         : `root` adalah pointer ke root pohon bracket turnamen.
    F.S         : Status turnamen ditampilkan di konsol, beserta juara jika turnamen selesai, atau daftar pertandingan yang tersedia jika masih berlangsung.
*/

void tampilkanPertandinganSiapRapi(addressTree root, addressList head, int target_round);
/* Deskripsi   : Fungsi rekursif untuk menampilkan daftar pertandingan yang siap dimainkan atau pertandingan BYE pada babak target tertentu. Output akan mencakup nama tim dan status pertandingan.
    I.S         : - `root` adalah pointer ke node pohon bracket turnamen saat ini.
                  - `head` adalah pointer ke head linked list tim.
                  - `target_round` adalah nomor babak yang ingin ditampilkan pertandingannya.
    F.S         : Daftar pertandingan yang siap dimainkan (dengan nama tim dan status) pada `target_round` ditampilkan di konsol.
*/

void tampilkanBracket(TournamentTree *tournamentTree, addressList head);
/* Deskripsi   : Fungsi utama untuk menampilkan bagan turnamen secara visual. Fungsi ini memilih template tampilan yang sesuai berdasarkan jumlah tim yang terdaftar. Jika tidak ada template khusus, akan menampilkan bagan umum berdasarkan babak. Juga menampilkan juara turnamen jika sudah ada dan legenda status pertandingan.
    I.S         : - `root` adalah pointer ke root pohon bracket turnamen.
                  - `head` adalah pointer ke head linked list tim.
                  - Pengguna memilih opsi untuk menampilkan bagan.
    F.S         : - Jika turnamen belum dijadwalkan, pesan kesalahan ditampilkan.
                  - Bagan turnamen ditampilkan di konsol menggunakan template yang sesuai dengan jumlah tim, atau fallback ke tampilan umum per babak.
                  - Jika ada juara, nama juara ditampilkan secara mencolok.
                  - Legenda status pertandingan (Menang, SIAP, MENUNGGU, BYE) ditampilkan.
*/

void tampilkanBracketDetailed(addressTree root, addressList head, int depth);
/* Deskripsi   : Fungsi rekursif untuk menampilkan struktur pohon bracket turnamen secara detail, dengan indentasi yang menunjukkan kedalaman setiap node. Ini menampilkan informasi pertandingan (Match ID, nama tim) untuk node daun, dan menandai node internal sebagai "Round Match".
    I.S         : - `root` adalah pointer ke node pohon bracket turnamen saat ini.
                  - `head` adalah pointer ke head linked list tim.
                  - `depth` adalah tingkat kedalaman node saat ini dari root (root adalah 0).
    F.S         : Struktur pohon bracket turnamen ditampilkan di konsol, dengan setiap pertandingan terindentasi sesuai kedalamannya dalam pohon, menampilkan nama tim dan pemenang jika ada.
*/

void tampilkanPertandinganRound(addressTree root, addressList head, int target_round);
/* Deskripsi   : Fungsi rekursif untuk menampilkan pertandingan berdasarkan babak (`target_round`) dengan format yang lebih informatif, termasuk nama tim dan status pertandingan. Ini berfungsi sebagai fallback saat tidak ada template spesifik untuk jumlah tim tertentu.
    I.S         : - `root` adalah pointer ke node pohon bracket turnamen saat ini.
                  - `head` adalah pointer ke head linked list tim.
                  - `target_round` adalah nomor babak yang ingin ditampilkan.
    F.S         : Informasi pertandingan untuk setiap pertandingan di `target_round` ditampilkan di konsol, termasuk nama tim dan status (selesai, siap dimainkan, atau menunggu).
*/

char* getNamaTim(int id_tim, addressList head);
/* Deskripsi   : Fungsi helper untuk mendapatkan nama tim berdasarkan ID tim dari linked list. Menggunakan buffer statis untuk mengembalikan string.
    I.S         : - `id_tim` adalah integer ID tim yang namanya ingin dicari.
                  - `head` adalah pointer ke head linked list tim.
    F.S         : Mengembalikan pointer ke string yang berisi nama tim yang ditemukan. Jika ID tim tidak ditemukan, mengembalikan "Unknown".
*/

void tampilkanInfoPertandingan(addressTree match, addressList head);
/* Deskripsi   : Fungsi untuk menampilkan detail informasi dari satu pertandingan tertentu, termasuk ID pertandingan, nama dan ID kedua tim, serta pemenang jika pertandingan sudah selesai.
    I.S         : - `match` adalah pointer ke node pertandingan yang informasinya ingin ditampilkan.
                  - `head` adalah pointer ke head linked list tim (digunakan untuk mendapatkan nama tim).
    F.S         : Informasi pertandingan yang diformat ditampilkan di konsol. Jika `match` NULL, pesan "Pertandingan tidak valid." ditampilkan.
*/

boolean verifyTournamentReset(addressList head, Stack *matchHistory);
/*	Deskripsi	: Fungsi untuk memverifikasi bahwa turnamen telah direset dengan benar, memeriksa apakah stack riwayat kosong dan semua statistik tim bernilai 0.
	I.S			: - head Linked list tim yang mungkin kosong atau berisi informasi tim.
				  - matchHistory Pointer ke stack riwayat pertandingan yang mungkin kosong atau berisi data.
	F.S			: Linked list dan stack tidak berubah.
*/

#endif