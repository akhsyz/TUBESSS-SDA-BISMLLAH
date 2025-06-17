/*
PIC : belva 
NIM : 241524035
*/

#ifndef MENU_H
#define MENU_H

#include "fileio.h"

void clearScreen(void);

void initialUI(addressList *head, Queue *matchQueue, TournamentTree **tournamentTree, Stack *matchHistory, char *namaEvent);
/* Deskripsi   : Menampilkan antarmuka pengguna awal yang memungkinkan pengguna untuk memuat turnamen yang sudah ada, membuat turnamen baru, atau keluar dari program. Fungsi ini akan terus berulang hingga pengguna memilih opsi yang valid yang mengarahkan mereka ke menu utama atau keluar.
    I.S         : - `head` menunjuk ke linked list tim yang kosong (NULL).
                  - `matchQueue` adalah antrean pertandingan yang kosong.
                  - `tournamentTree` menunjuk ke pohon bracket yang kosong (NULL).
                  - `matchHistory` adalah stack riwayat pertandingan yang kosong.
                  - `namaEvent` adalah string kosong atau string dengan nilai tidak terdefinisi.
    F.S         : - Jika pengguna memilih "Muat Turnamen", `head`, `matchQueue`, `tournamentTree`, `matchHistory`, dan `namaEvent` akan diperbarui dengan data dari turnamen yang dimuat, lalu program beralih ke `mainMenu`.
                  - Jika pengguna memilih "Buat Turnamen Baru", `namaEvent` akan diisi oleh pengguna, dan program beralih ke `mainMenu`.
                  - Jika pengguna memilih "Keluar", program akan berakhir.
                  - Jika input tidak valid, pesan kesalahan ditampilkan, dan UI awal ditampilkan kembali.
*/

void uiGreetings(char *namaEvent);
/* Deskripsi   : Menampilkan pesan sambutan yang estetik kepada pengguna dan meminta mereka untuk memasukkan nama event turnamen. Nama yang dimasukkan akan disimpan dalam variabel `namaEvent`.
    I.S         : `namaEvent` adalah string kosong atau string dengan nilai tidak terdefinisi.
    F.S         : `namaEvent` berisi string yang dimasukkan oleh pengguna sebagai nama turnamen, dan pesan sambutan yang dipersonalisasi ditampilkan di konsol.
*/

void mainMenu(addressList *head, Queue *matchQueue, TournamentTree **tournamentTree, Stack *matchHistory, char *namaEvent);
/* Deskripsi   : Menampilkan menu utama program manajemen turnamen. Pengguna dapat memilih berbagai opsi seperti menambah/menghapus tim, menampilkan daftar tim, menjadwalkan pertandingan, memasukkan/mengulang hasil pertandingan, menampilkan bracket dan statistik, melihat riwayat, atau keluar dari program.
    I.S         : - `head` menunjuk ke linked list tim (bisa kosong atau berisi data).
                  - `matchQueue` adalah antrean pertandingan (bisa kosong atau berisi pertandingan yang belum dimainkan).
                  - `tournamentTree` menunjuk ke pohon bracket turnamen (bisa kosong atau berisi struktur bracket).
                  - `matchHistory` adalah stack riwayat pertandingan (bisa kosong atau berisi riwayat pertandingan).
                  - `namaEvent` adalah nama turnamen saat ini.
    F.S         : - Tergantung pada pilihan pengguna, fungsi yang sesuai akan dipanggil untuk memodifikasi atau menampilkan data turnamen.
                  - Jika pengguna memilih "Keluar", `exitProgram` akan dipanggil, membersihkan memori dan menyimpan data.
                  - Jika turnamen telah selesai (ada pemenang di root tree), pesan juara akan ditampilkan.
*/

boolean muatTurnamen(addressList *head, Queue *matchQueue, TournamentTree **tournamentTree, Stack *matchHistory, char *namaEvent);
/* Deskripsi   : Memuat data turnamen yang sudah ada dari file JSON. Fungsi ini akan meminta nama turnamen kepada pengguna, memeriksa keberadaan file, dan jika ditemukan, akan mem-parsing data turnamen (daftar tim, bracket, riwayat pertandingan) dari file tersebut ke dalam struktur data program. Setelah berhasil dimuat, program akan melanjutkan ke menu utama.
    I.S         : - `head` menunjuk ke linked list tim yang kosong (NULL).
                  - `matchQueue` adalah antrean pertandingan yang kosong.
                  - `tournamentTree` menunjuk ke pohon bracket yang kosong (NULL).
                  - `matchHistory` adalah stack riwayat pertandingan yang kosong.
                  - `namaEvent` adalah string kosong atau string dengan nilai tidak terdefinisi.
                  - Pengguna diminta untuk memasukkan nama event turnamen.
    F.S         : - Jika file turnamen ditemukan dan berhasil dimuat:
                      - `head` menunjuk ke linked list tim yang dimuat dari file.
                      - `tournamentTree` menunjuk ke pohon bracket yang dimuat dari file.
                      - `matchHistory` berisi riwayat pertandingan yang dimuat dari file.
                      - `namaEvent` diperbarui dengan nama turnamen dari file.
                      - Pesan sukses ditampilkan, dan program beralih ke `mainMenu`.
                      - Mengembalikan `true`.
                  - Jika file turnamen tidak ditemukan atau gagal dimuat:
                      - Pesan kesalahan ditampilkan.
                      - Struktur data tetap tidak berubah (atau tetap kosong).
                      - Mengembalikan `false`.
*/

void buatTurnamen(addressList *head, Queue *matchQueue, TournamentTree **tournamentTree, Stack *matchHistory, char *namaEvent);
/* Deskripsi   : Memulai proses pembuatan turnamen baru. Fungsi ini akan memanggil `uiGreetings` untuk mendapatkan nama turnamen dari pengguna, kemudian melanjutkan ke `mainMenu` untuk mengelola turnamen yang baru dibuat.
    I.S         : - `head` menunjuk ke linked list tim yang kosong (NULL).
                  - `matchQueue` adalah antrean pertandingan yang kosong.
                  - `tournamentTree` menunjuk ke pohon bracket yang kosong (NULL).
                  - `matchHistory` adalah stack riwayat pertandingan yang kosong.
                  - `namaEvent` adalah string kosong atau string dengan nilai tidak terdefinisi.
    F.S         : - `namaEvent` akan berisi nama turnamen yang dimasukkan oleh pengguna melalui `uiGreetings`.
                  - Program akan beralih ke `mainMenu` dengan struktur data turnamen yang baru diinisialisasi (kosong).
*/

void showsTambahTim(addressList *head);
/* Deskripsi   : Menampilkan sub-menu untuk operasi penambahan tim. Fungsi ini memberikan informasi singkat kepada pengguna sebelum memanggil fungsi `tambahTim` yang sebenarnya.
    I.S         : - `head` menunjuk ke linked list tim yang sudah ada (bisa kosong).
                  - Pengguna telah memilih opsi untuk menambah tim dari menu utama.
    F.S         : - Pesan "--- Tambah Tim ---" dan "Tentukan jumlah tim yang akan bertanding." ditampilkan di konsol.
                  - Fungsi `tambahTim` dipanggil untuk memungkinkan pengguna memasukkan tim baru ke linked list.
*/

void showsHapusTim(addressList *head);
/* Deskripsi   : Menampilkan sub-menu untuk operasi penghapusan tim. Fungsi ini memberikan informasi singkat kepada pengguna sebelum memanggil fungsi `hapusTim` yang sebenarnya.
    I.S         : - `head` menunjuk ke linked list tim yang sudah ada.
                  - Pengguna telah memilih opsi untuk menghapus tim dari menu utama.
    F.S         : - Pesan "--- Hapus Tim ---" dan "Masukkan nama tim yang ingin dihapus." ditampilkan di konsol.
                  - Fungsi `hapusTim` dipanggil untuk memungkinkan pengguna menghapus tim dari linked list.
*/

void exitProgram(addressList *head, Queue *matchQueue, TournamentTree **tournamentTree, Stack *matchHistory, char *namaEvent);
/* Deskripsi   : Mengelola proses keluar dari program, termasuk menyimpan semua data turnamen yang ada ke file JSON, membebaskan semua memori yang dialokasikan, dan menampilkan pesan penutup yang estetik. Jika nama event kosong, akan menggunakan "default" sebagai nama file.
    I.S         : - `head` menunjuk ke linked list tim.
                  - `matchQueue` adalah antrean pertandingan.
                  - `tournamentTree` menunjuk ke pohon bracket turnamen.
                  - `matchHistory` adalah stack riwayat pertandingan.
                  - `namaEvent` adalah string nama turnamen saat ini (bisa kosong).
    F.S         : - Semua data turnamen (`head`, `tournamentTree`, `matchHistory`) telah disimpan ke file JSON di lokasi `tournament_data/namaEvent.json`.
                  - Semua memori yang dialokasikan untuk linked list tim, queue pertandingan, pohon bracket, dan stack riwayat pertandingan telah dibebaskan.
                  - Pesan konfirmasi penyimpanan atau kegagalan ditampilkan.
                  - Pesan penutup program yang estetik ditampilkan di konsol.
                  - Program siap untuk diakhiri (memori bersih).
*/

#endif