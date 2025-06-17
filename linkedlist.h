/*
PIC : aufa
NIM : 241524052
*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "convention.h"

typedef char* infotype;

typedef struct Node {
    int id_tim; 
    char namaTim[50];
    int laga; 
    int kemenangan; 
    int kekalahan; 
    struct Node* next;
} node;

typedef node NodeList;

typedef node* addressList;

void initLinkedList(addressList *head);
/*	Deskripsi	: Prosedur untuk menginisialisasi linked list yang digunakan untuk menyimpan data tim. Mengatur pointer head ke NULL 
				  dan menginisialisasi variabel global next_id ke 1 untuk penomoran ID tim.
	I.S			: - head Pointer ke node linked list belum menunjuk ke mana pun (tidak terdefinisi atau acak).
				  - next_id Variabel global untuk penomoran ID tim sudah diatur/dideklarasikan bernilai 1
	F.S			: - head Menunjuk ke NULL, menandakan linked list kosong.
				  - next_id Bernilai 1, siap digunakan untuk ID tim pertama.
*/
void addToLinkedList(addressList *head, char* namaTim);
/*	Deskripsi	: Prosedur untuk menambahkan tim baru ke linked list. Memeriksa apakah nama tim sudah ada untuk mencegah duplikasi, membuat node 
				  baru dengan createNode, mengatur ID tim menggunakan next_id, dan menyisipkan node ke akhir linked list menggunakan insertAtLast. 
				  Menampilkan pesan konfirmasi jika berhasil atau pesan kesalahan jika gagal.
	I.S			: - head Linked list mungkin kosong atau berisi beberapa node tim.
				  - namaTim String nama tim yang akan ditambahkan (input dari pengguna).
				  - next_id Menyimpan nilai ID berikutnya yang akan diberikan.
	F.S			: - Node baru dengan namaTim, id_tim = next_id, laga = 0, kemenangan = 0, kekalahan = 0 ditambahkan ke akhir linked list.
				  - next_id bertambah 1.
*/
void displayLinkedList(addressList head);
/*	Deskripsi	: Prosedur untuk menampilkan daftar tim yang ada di linked list dalam format tabel yang rapi, termasuk ID dan nama tim. Menggunakan warna untuk header dan baris data agar lebih jelas, serta menampilkan total jumlah tim terdaftar.
	I.S			: head Linked list mungkin kosong atau berisi beberapa node tim.
	F.S			: - Daftar tim ditampilkan dalam format tabel dengan kolom "ID" dan "Nama Tim".
				  - Baris data ditampilkan dengan warna bergantian (putih dan abu-abu).
				  - Total jumlah tim ditampilkan di footer tabel.
*/
addressList createNode(infotype info);
/*	Deskripsi	: Fungsi untuk membuat node baru untuk tim dengan nama yang diberikan. Mengalokasikan memori untuk node, mengisi nama tim, dan menginisialisasi statistik (id_tim, laga, kemenangan, kekalahan) ke nilai default. Memeriksa panjang nama tim agar tidak melebihi 49 karakter.
	I.S			: info String nama tim yang akan disimpan di node baru.
	F.S			: Mengembalikan pointer ke node baru dengan:
					- namaTim = info (maksimal 49 karakter, diakhiri \0).
					- id_tim = 0, laga = 0, kemenangan = 0, kekalahan = 0.
					- next = NULL.
*/
void insertAtFirst(addressList *head, addressList newP);
/*	Deskripsi	: Prosedur untuk menyisipkan node baru di awal linked list, menjadikannya elemen pertama dengan mengubah pointer head untuk menunjuk ke node baru.
	I.S			: - head Linked list mungkin kosong atau berisi beberapa node tim.
				  - newP Pointer ke node baru yang akan disisipkan (sudah dialokasikan).
	F.S			: - newP menjadi elemen pertama dengan newP->next menunjuk ke head sebelumnya.
				  - head diubah untuk menunjuk ke newP.
*/
void insertAtLast(addressList *head, addressList newP);
/*	Deskripsi	: Prosedur untuk menyisipkan node baru di akhir linked list. Jika linked list kosong, node baru menjadi elemen pertama. Jika tidak, node baru dihubungkan ke node terakhir.
	I.S			: - head Linked list mungkin kosong atau berisi beberapa node tim.
				  - newP Pointer ke node baru yang akan disisipkan (sudah dialokasikan).
	F.S			: - newP ditambahkan sebagai node terakhir dengan next = NULL.
				  - Node terakhir sebelumnya dihubungkan ke newP.
*/
void DeAlokasi(addressList *head);
/*	Deskripsi	: Prosedur untuk membebaskan memori yang digunakan oleh seluruh node dalam linked list, menghapus setiap node satu per satu hingga linked list kosong.
	I.S			: head Linked list mungkin kosong atau berisi beberapa node tim.
	F.S			: - Semua node dalam linked list dibebaskan dari memori.
				  - head menunjuk ke NULL, menandakan linked list kosong.
*/
void deleteFirst(addressList *head);
/*	Deskripsi	: Prosedur untuk menghapus node pertama dalam linked list dan membebaskan memorinya. Pointer head diubah untuk menunjuk ke node berikutnya.
	I.S			: head Linked list mungkin kosong atau berisi beberapa node tim.
	F.S			: - Node pertama dihapus dan memorinya dibebaskan.
				  - head diubah untuk menunjuk ke node berikutnya (atau NULL jika hanya ada satu node).
*/
void deleteValue(addressList *head, infotype info);
/*	Deskripsi	: Prosedur untuk menghapus node berdasarkan nama tim dari linked list. Jika node dengan nama tim yang sesuai ditemukan, node tersebut dihapus dan memorinya dibebaskan. Menampilkan pesan jika tim tidak ditemukan.
	I.S			: - head Linked list mungkin kosong atau berisi beberapa node tim.
				  - info String nama tim yang akan dihapus.
	F.S			: - Node yang sesuai dihapus, pointer next dari node sebelumnya dihubungkan ke node berikutnya.
				  - Memori node dibebaskan.
*/
int countNode(addressList head);
/*	Deskripsi	: Fungsi untuk menghitung jumlah node (tim) dalam linked list dan mengembalikan nilai jumlahnya.
	I.S			: head Linked list mungkin kosong atau berisi beberapa node tim.
	F.S			: - Mengembalikan integer yang menunjukkan jumlah node dalam linked list.
				  - Jika linked list kosong, mengembalikan 0.
				  - Linked list tidak mengalami perubahan.
*/
void updateTeamStats(addressList head, char* namaTim, int menang, int kalah);
/*	Deskripsi	: Prosedur untuk memperbarui statistik tim (jumlah laga, kemenangan, kekalahan) berdasarkan nama tim. Mencari node tim dalam linked list dan memperbarui statistiknya sesuai input.
	I.S			: - head Linked list mungkin kosong atau berisi beberapa node tim.
				  - namaTim String nama tim yang statistiknya akan diperbarui.
				  - menang Nilai untuk menambah jumlah kemenangan (biasanya 0 atau 1).
				  - kalah Nilai untuk menambah jumlah kekalahan (biasanya 0 atau 1).
	F.S			: - laga bertambah 1.
				  - kemenangan bertambah sesuai parameter menang.
				  - kekalahan bertambah sesuai parameter kalah.
*/
addressList searchNodeById(addressList head, int id_tim);
/*	Deskripsi	: Fungsi untuk mencari node dalam linked list berdasarkan ID tim dan mengembalikan pointer ke node tersebut.
	I.S			: - head Linked list mungkin kosong atau berisi beberapa node tim.
				  - id_tim Integer ID tim yang dicari.
	F.S			: Mengembalikan pointer ke node tersebut.
*/
void resetAllTeamStats(addressList head);
/*	Deskripsi	: Prosedur untuk mengatur ulang statistik (jumlah laga, kemenangan, kekalahan) semua tim dalam linked list ke nilai 0.
	I.S			: head Linked list mungkin kosong atau berisi beberapa node tim.
	F.S			: laga = 0, kemenangan = 0, kekalahan = 0.
*/
addressList searchNode(addressList head, char* namaTim);
/*	Deskripsi	: Fungsi untuk mencari node dalam linked list berdasarkan nama tim dan mengembalikan pointer ke node tersebut.
	I.S			: - head Linked list mungkin kosong atau berisi beberapa node tim.
				  - namaTim String nama tim yang dicari.
	F.S			: Mengembalikan pointer ke node tersebut.
*/
void renumberTeamIDs(addressList head);
void reorderTeamIDs(addressList *head);
void resetAllTeamStatsSilent(addressList head);

#endif
