/*
PIC : belva 
NIM : 241524035
*/

#ifndef QUEUE_H
#define QUEUE_H

#include "linkedlist.h"

typedef struct {
    addressList head;
    addressList tail;
} Queue;

void initQueue(Queue *Q);
/*	Deskripsi	: Prosedur untuk menginisialisasi antrian (Queue) dengan mengatur pointer head dan tail ke NULL.
	I.S			: Q Pointer ke struktur Queue yang belum diinisialisasi atau memiliki nilai acak untuk head dan tail.
	F.S			: - Q->head Menunjuk ke NULL.
				  - Q->tail Menunjuk ke NULL.
				  - Antrian dalam keadaan kosong.
*/

void enqueue(Queue *Q, addressList node);
/*	Deskripsi	: Prosedur untuk menambahkan node tim ke akhir antrian (Queue). Membuat salinan node dari teamNode untuk menghindari modifikasi linked list asli, kemudian menambahkannya ke antrian. Menampilkan pesan kesalahan jika node tidak valid atau alokasi memori gagal.
	I.S			: - Q Antrian mungkin kosong (head dan tail = NULL) atau berisi beberapa node tim.
				  - teamNode Pointer ke node tim dari linked list yang akan ditambahkan ke antrian (mengandung id_tim dan namaTim).
	F.S			: - Node baru dengan salinan data (id_tim, namaTim) dari teamNode ditambahkan ke akhir antrian.
				  - Jika antrian kosong, head dan tail menunjuk ke node baru.
				  - Jika antrian tidak kosong, tail->next menunjuk ke node baru, dan tail diubah ke node baru.
				  - next dari node baru diatur ke NULL.
*/

void dequeue(Queue *Q);
/*	Deskripsi	: Prosedur untuk menghapus node pertama dari antrian (Queue) dan membebaskan memorinya. Mengatur ulang pointer head dan tail sesuai kondisi antrian setelah penghapusan. Menampilkan pesan jika antrian kosong.
	I.S			: Q Antrian mungkin kosong (head dan tail = NULL) atau berisi beberapa node tim.
	F.S			: - Node pertama (head) dihapus dan memorinya dibebaskan.
				  - head diubah untuk menunjuk ke node berikutnya.
				  - Jika antrian menjadi kosong setelah penghapusan (head = NULL), tail juga diatur ke NULL.
*/

void reverseQueue(Queue *Q);
/*	Deskripsi	: Prosedur untuk membalik urutan node dalam antrian (Queue) dengan mengubah arah pointer next. Mengatur ulang head dan tail sesuai urutan baru. Tidak melakukan perubahan jika antrian kosong atau hanya memiliki satu node.
	I.S			: Q Antrian mungkin kosong, memiliki satu node, atau beberapa node tim.
	F.S			: - Urutan node dibalik (node pertama menjadi terakhir, dan sebaliknya).
				  - head menunjuk ke node yang sebelumnya adalah tail.
				  - tail menunjuk ke node yang sebelumnya adalah head.
				  - Pointer next setiap node diatur ulang untuk mencerminkan urutan baru.
*/

void clearQueue(Queue *Q);
/*	Deskripsi	: Prosedur untuk menghapus semua node dalam antrian (Queue) dengan memanggil dequeue berulang-ulang hingga antrian kosong, membebaskan memori setiap node.
	I.S			: Q Antrian mungkin kosong atau berisi beberapa node tim.
	F.S			: - Semua node dalam antrian dihapus dan memorinya dibebaskan.
				  - Q->head = NULL.
				  - Q->tail = NULL.
				  - Antrian dalam keadaan kosong.
*/

#endif