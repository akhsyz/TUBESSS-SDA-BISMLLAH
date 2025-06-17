/*
PIC : aufa
NIM : 241524052
*/

#ifndef TREE_H
#define TREE_H

#include "queue.h"

typedef struct NodeTree {
    int id_tim1;        
    int id_tim2;       
    int id_pemenang;   
    int match_id;       
    struct NodeTree* left;  
    struct NodeTree* right; 
} NodeTree;

typedef struct TournamentMetadata {
    int total_participants;  
    char tournament_format[20]; 
    int total_rounds;        
} TournamentMetadata;

typedef struct TournamentTree {
    NodeTree* root;          
    TournamentMetadata meta;
} TournamentTree;
/*	Deskripsi	: Fungsi utama untuk membangun pohon turnamen eliminasi tunggal berdasarkan jumlah tim (3-12) dengan mengambil ID tim dari antrian (Queue). Memanggil fungsi buildTreeXTeams sesuai jumlah tim.
	I.S			: - Q Pointer ke antrian berisi node tim.
tota			  - l_teams Jumlah tim (3-12).
				  - head Pointer ke linked list tim (tidak digunakan dalam implementasi ini).
	F.S			: - Mengembalikan pointer ke root pohon turnamen yang dibangun oleh fungsi buildTreeXTeams sesuai jumlah tim.
				  - Array teams diisi dengan ID tim dari antrian (maksimal 12 tim).
				  - Pohon turnamen dibangun dengan struktur sesuai jumlah tim (3-12).
*/

typedef NodeTree* addressTree;
typedef TournamentTree* addressTournamentTree;

addressTree createTreeNode(int id_tim1, int id_tim2, int match_id);
/*	Deskripsi	: Fungsi untuk membuat node baru dalam pohon turnamen (Binary Tree) yang merepresentasikan sebuah pertandingan. Node menyimpan ID dua tim yang bertanding, ID pemenang (awalnya 0), ID pertandingan, dan pointer ke anak kiri dan kanan.
	I.S			: - id_tim1 ID tim pertama yang bertanding, id_tim2 ID tim kedua yang bertanding (atau 0 jika BYE), dan match_id ID unik untuk pertandingan belum memiliki nilai.
	F.S			: Mengembalikan pointer ke node baru dengan:
					- id_tim1 = nilai parameter id_tim1.
					- id_tim2 = nilai parameter id_tim2.
					- id_pemenang = 0.
					- match_id = nilai parameter match_id.
					- left = NULL.
					- right = NULL.
*/
addressTree createMatchNode(int id_tim1, int id_tim2, int match_id);
/*	Deskripsi	: Fungsi helper untuk membuat node pertandingan dengan memanggil createTreeNode. Digunakan untuk menyederhanakan pembuatan node pertandingan dengan parameter yang sama.
	I.S			: id_tim1 ID tim pertama yang bertanding, id_tim2 ID tim kedua yang bertanding (atau 0 jika BYE), dam match_id ID unik untuk pertandingan belum memiliki nilai.
	F.S			: - Mengembalikan pointer ke node baru yang dibuat oleh createTreeNode dengan parameter yang diberikan.
				  - Jika alokasi gagal di createTreeNode, mengembalikan NULL.
*/
addressTree buildTournamentTree(Queue *Q, int total_teams, addressList head);
TournamentTree* buildTournamentTreeWithMeta(Queue *Q, int total_teams, addressList head);
addressTree buildTree3Teams(int teams[], int *match_id);
/*	Deskripsi	: Fungsi untuk membangun pohon turnamen eliminasi tunggal untuk 3 tim, menghasilkan 2 pertandingan: satu semifinal (tim 1 vs tim 2) dan satu final (pemenang semifinal vs tim 3 yang mendapat BYE).
	I.S			: - teams Array berisi ID 3 tim.
				  - match_id Pointer ke integer yang menyimpan ID pertandingan berikutnya.
	F.S			: - Mengembalikan pointer ke root pohon turnamen (node final).
				  - match_id bertambah sebanyak jumlah pertandingan (2).
*/
addressTree buildTree4Teams(int teams[], int *match_id);
/*	Deskripsi	: Fungsi untuk membangun pohon turnamen eliminasi tunggal untuk 4 tim, menghasilkan 3 pertandingan: dua semifinal (tim 1 vs tim 2, tim 3 vs tim 4) dan satu final (pemenang semifinal 1 vs pemenang semifinal 2).
	I.S			: - teams Array berisi ID 4 tim.
				  - match_id Pointer ke integer yang menyimpan ID pertandingan berikutnya.
	F.S			: - Mengembalikan pointer ke root pohon turnamen (node final).
				  - match_id bertambah sebanyak jumlah pertandingan (3).
*/
addressTree buildTree5Teams(int teams[], int *match_id);
/*	Deskripsi	: Fungsi untuk membangun pohon turnamen eliminasi tunggal untuk 5 tim, menghasilkan 4 pertandingan: dua pertandingan babak pertama, satu semifinal (pemenang babak 1 vs tim 5), dan satu final.
	I.S			: - teams Array berisi ID 5 tim.
				  - match_id Pointer ke integer yang menyimpan ID pertandingan berikutnya.
	F.S			: - Mengembalikan pointer ke root pohon turnamen (node final).
				  - match_id bertambah sebanyak jumlah pertandingan (4).
*/
addressTree buildTree6Teams(int teams[], int *match_id);
/*	Deskripsi	: Fungsi untuk membangun pohon turnamen eliminasi tunggal untuk 6 tim, menghasilkan 5 pertandingan: dua pertandingan babak pertama, dua semifinal (masing-masing pemenang babak 1 vs tim dengan BYE), dan satu final.
	I.S			: - teams Array berisi ID 6 tim.
				  - match_id Pointer ke integer yang menyimpan ID pertandingan berikutnya.
	F.S			: - Mengembalikan pointer ke root pohon turnamen (node final).
				  - match_id bertambah sebanyak jumlah pertandingan (5).
*/
addressTree buildTree7Teams(int teams[], int *match_id);
/*	Deskripsi	: Fungsi untuk membangun pohon turnamen eliminasi tunggal untuk 7 tim, menghasilkan 6 pertandingan: satu babak pertama, tiga perempat final, dua semifinal (satu dengan BYE), dan satu final.
	I.S			: - teams Array berisi ID 7 tim.
				  - match_id Pointer ke integer yang menyimpan ID pertandingan berikutnya.
	F.S			: - Mengembalikan pointer ke root pohon turnamen (node final).
				  - match_id bertambah sebanyak jumlah pertandingan (6).
*/
addressTree buildTree8Teams(int teams[], int *match_id);
/*	Deskripsi	: Fungsi untuk membangun pohon turnamen eliminasi tunggal untuk 8 tim, menghasilkan 7 pertandingan: empat perempat final, dua semifinal, dan satu final. Merupakan pohon turnamen sempurna tanpa BYE.
	I.S			: - teams Array berisi ID 8 tim.
				  - match_id Pointer ke integer yang menyimpan ID pertandingan berikutnya.
	F.S			: - Mengembalikan pointer ke root pohon turnamen (node final).
				  - match_id bertambah sebanyak jumlah pertandingan (7).
*/
addressTree buildTree9Teams(int teams[], int *match_id);
/*	Deskripsi	: Fungsi untuk membangun pohon turnamen eliminasi tunggal untuk 9 tim, menghasilkan 8 pertandingan: satu babak pertama, empat perempat final, dua semifinal, dan satu final.
	I.S			: - teams Array berisi ID 9 tim.
				  - match_id Pointer ke integer yang menyimpan ID pertandingan berikutnya.
	F.S			: - Mengembalikan pointer ke root pohon turnamen (node final).
				  - match_id bertambah sebanyak jumlah pertandingan (8).
*/
addressTree buildTree10Teams(int teams[], int *match_id);
/*	Deskripsi	: Fungsi untuk membangun pohon turnamen eliminasi tunggal untuk 10 tim, menghasilkan 9 pertandingan: dua babak pertama, empat perempat final, dua semifinal, dan satu final.
	I.S			: - teams Array berisi ID 10 tim.
				  - match_id Pointer ke integer yang menyimpan ID pertandingan berikutnya.
	F.S			: - Mengembalikan pointer ke root pohon turnamen (node final).
				  - match_id bertambah sebanyak jumlah pertandingan (9).
*/
addressTree buildTree11Teams(int teams[], int *match_id);
/*	Deskripsi	: Fungsi untuk membangun pohon turnamen eliminasi tunggal untuk 11 tim, menghasilkan 10 pertandingan: lima babak pertama, tiga perempat final, satu semifinal, dan satu final. Satu tim mendapat BYE ke perempat final.
	I.S			: - teams Array berisi ID 11 tim.
				  - match_id Pointer ke integer yang menyimpan ID pertandingan berikutnya.
	F.S			: - Mengembalikan pointer ke root pohon turnamen (node final).
				  - match_id bertambah sebanyak jumlah pertandingan (10).
*/
addressTree buildTree12Teams(int teams[], int *match_id);
/*	Deskripsi	: Fungsi untuk membangun pohon turnamen eliminasi tunggal untuk 12 tim, menghasilkan 11 pertandingan: enam babak pertama, tiga perempat final, dua semifinal (satu tim langsung ke final), dan satu final.
	I.S			: - teams Array berisi ID 12 tim.
				  - match_id Pointer ke integer yang menyimpan ID pertandingan berikutnya.
	F.S			: - Mengembalikan pointer ke root pohon turnamen (node final).
				  - match_id bertambah sebanyak jumlah pertandingan (11).
*/

addressTree findMatchNode(addressTree root, int match_id);
/*	Deskripsi	: Fungsi untuk mencari node pertandingan dalam pohon turnamen berdasarkan ID pertandingan menggunakan traversal rekursif.
	I.S			: - root Pohon turnamen yang mungkin kosong atau berisi node pertandingan.
				  - match_id ID pertandingan yang dicari.
	F.S			: - Mengembalikan pointer ke node tersebut.
				  - Pohon turnamen tidak mengalami perubahan.
*/
addressTree findParentNode(addressTree root, addressTree node);
/*	Deskripsi	: Fungsi untuk mencari node parent dari node anak tertentu dalam pohon turnamen menggunakan traversal rekursif.
	I.S			: - root Pohon turnamen yang mungkin kosong atau berisi node pertandingan.
				  - childNode Node anak yang parentnya dicari.
	F.S			: Mengembalikan pointer ke root.
*/
void updateMatchWinner(addressTree root, int match_id, int winner_id);
/*	Deskripsi	: Prosedur untuk memperbarui pemenang pertandingan berdasarkan ID pertandingan dan ID pemenang, lalu memperbarui node parent dengan memanggil updateParentNodes. Memvalidasi bahwa pemenang adalah salah satu tim yang bertanding.
	I.S			: - root Pohon turnamen yang mungkin kosong atau berisi node pertandingan.
				  - match_id ID pertandingan yang akan diperbarui.
				  - winner_id ID tim pemenang.
	F.S			: - id_pemenang pada node pertandingan diatur ke winner_id.
				  - Node parent diperbarui melalui updateParentNodes.
*/
void updateParentNodes(addressTree root, addressTree changed_node);
/*	Deskripsi	: Prosedur helper untuk memperbarui node parent setelah pemenang pertandingan ditentukan. Mengatur id_tim1 atau id_tim2 pada node parent berdasarkan pemenang anak.
	I.S			: - root Pohon turnamen yang berisi node pertandingan.
				  - changed_node Node pertandingan yang pemenangnya baru diperbarui.
	F.S			: - Jika changed_node memiliki pemenang (id_pemenang ≠ 0) maka Node parent ditemukan menggunakan findParentNode dan id_tim1 atau id_tim2 pada parent diatur ke id_pemenang dari changed_node, tergantung apakah changed_node adalah anak kiri atau kanan.
				  - Jika parent memiliki kedua tim (id_tim1 dan id_tim2 > 0) maka Parent siap dimainkan (tidak ada aksi tambahan dalam kode ini).
*/
int calculateRoundNumber(addressTree root, int match_id, addressList head);
/*	Deskripsi	: Fungsi untuk menghitung nomor babak (round) dari sebuah pertandingan berdasarkan ID pertandingan. Menghitung kedalaman dari node pertandingan ke leaf (babak pertama dianggap round 1).
	I.S			: - root Pohon turnamen yang mungkin kosong atau berisi node pertandingan.
				  - match_id ID pertandingan yang babaknya akan dihitung.
				  - head Pointer ke linked list tim (tidak digunakan dalam implementasi ini).
	F.S			: - Mengembalikan nomor babak (kedalaman dari node ke leaf + 1).
				  - Pohon turnamen tidak mengalami perubahan.
*/
int calculateDepthFromLeaf(addressTree root, addressTree target);
/*	Deskripsi	: Fungsi untuk menghitung kedalaman dari node tertentu ke leaf dalam pohon turnamen. Digunakan untuk menentukan posisi node dalam struktur turnamen.
	I.S			: - root Pohon turnamen yang mungkin kosong atau berisi node pertandingan.
				  - target Node yang kedalamannya akan dihitung.
	F.S			: - Jika target adalah leaf (left dan right = NULL), mengembalikan 0.
				  - Jika bukan leaf, mengembalikan kedalaman maksimum dari anak-anaknya + 1.
				  - Pohon turnamen tidak mengalami perubahan.
*/
int calculateMaxDepth(addressTree root);
/*	Deskripsi	: Fungsi helper untuk menghitung kedalaman maksimum dari sebuah pohon atau subpohon, diukur dari node saat ini ke leaf terdalam.
	I.S			: root Pohon atau subpohon turnamen yang mungkin kosong atau berisi node pertandingan.
	F.S			: Jika root adalah leaf (left dan right = NULL) Mengembalikan 0.
*/
void getMatchesByRound(addressTree root, int target_round, addressTree matches[], int *count);
int isPowerOfTwo(int n);
/*	Deskripsi	: Fungsi helper untuk memeriksa apakah suatu angka merupakan pangkat dari dua (misalnya, 2, 4, 8). Digunakan untuk menentukan apakah jumlah tim memungkinkan pohon turnamen sempurna tanpa BYE.
	I.S			: n Integer yang akan diperiksa.
	F.S			: - Mengembalikan 1 (true) jika n adalah pangkat dari dua dan lebih besar dari 0.
				  - Mengembalikan 0 (false) jika n bukan pangkat dari dua atau n ≤ 0.
*/
void printTreeStructure(addressTree root, int depth);
/*	Deskripsi	: Prosedur untuk menampilkan struktur pohon turnamen secara rekursif dengan format yang rapi, menunjukkan ID pertandingan, tim yang bertanding, dan pemenang (jika ada), dengan indentasi berdasarkan kedalaman.
	I.S			: - root Pohon turnamen yang mungkin kosong atau berisi node pertandingan.
				  - depth Kedalaman saat ini untuk indentasi (biasanya 0 saat pemanggilan awal).
	F.S			: - Menampilkan setiap node dengan format: "Match [match_id]: Tim [id_tim1] vs Tim [id_tim2] (Winner: [id_pemenang])" (jika ada pemenang).
				  - Indentasi sebanyak depth spasi untuk setiap level.
				  -	Traversal dilakukan ke subpohon kiri dan kanan.
*/
void clearTree(addressTree *root);
/*	Deskripsi	: Prosedur untuk membebaskan memori seluruh node dalam pohon turnamen menggunakan traversal post-order, mengatur root ke NULL setelah penghapusan.
	I.S			: root Pointer ke pohon turnamen yang mungkin kosong atau berisi node pertandingan.
	F.S			: - Semua node dalam pohon dibebaskan dari memori.
				  - *root diatur ke NULL.
*/
void clearTournamentTree(TournamentTree **tournament);
int getTournamentParticipants(TournamentTree *tournament);
void setTournamentMetadata(TournamentTree *tournament, int participants, const char* format);

#endif
