# Sistem Manajemen Turnamen Bracket Forge

![Gambar Pratinjau](./preview.png?raw=true "preview")  

Sistem manajemen turnamen berbasis antarmuka baris perintah (CLI) yang dikembangkan menggunakan bahasa pemrograman C. Sistem ini mendukung turnamen sistem gugur dengan kapasitas 3 hingga 12 tim peserta. Fitur-fitur utama mencakup pengelolaan tim, penjadwalan pertandingan, visualisasi bagan turnamen, pencatatan riwayat pertandingan, dan penyimpanan data dalam format JSON.

---

## 🎯 Ringkasan Proyek

**Bracket Forge** merupakan aplikasi berbasis CLI yang dirancang untuk mengelola turnamen sistem gugur. Aplikasi ini terinspirasi dari turnamen olahraga dan esports terkenal seperti NCAA Basketball dan Dota 2 The International. Tujuan utama pengembangan aplikasi ini adalah membantu administrator turnamen dalam mengelola tim peserta, menjadwalkan pertandingan, mencatat hasil pertandingan, dan memantau statistik dengan efisien menggunakan berbagai struktur data seperti *linked list*, *binary tree*, *queue*, dan *stack*. Semua data turnamen disimpan dalam format JSON untuk memastikan persistensi data.

### Fitur-Fitur Utama

- **Pengelolaan Tim Peserta**: Menambahkan, menghapus, dan menampilkan daftar tim beserta statistik lengkap (total pertandingan, jumlah kemenangan, dan jumlah kekalahan).
- **Sistem Penjadwalan Otomatis**: Membangun bagan turnamen secara otomatis menggunakan struktur *binary tree* untuk 3–12 tim dengan penanganan sistem BYE yang optimal.
- **Pencatatan Hasil Pertandingan**: Memasukkan hasil pertandingan, memperbarui statistik tim secara real-time, dan menyimpan riwayat dalam struktur *stack*.
- **Fitur Pembatalan (Undo)**: Membatalkan hasil pertandingan terakhir dengan memperbarui struktur *tree* dan statistik tim secara otomatis.
- **Sistem Statistik dan Riwayat**: Menampilkan statistik lengkap setiap tim dan riwayat pertandingan yang telah berlangsung.
- **Penyimpanan Data Persisten**: Menyimpan dan memuat data turnamen (data tim, bagan pertandingan, riwayat) dalam format file JSON.

---

## 🎮 Panduan Penggunaan

### Alur Kerja Standar

Berikut adalah langkah-langkah standar untuk menggunakan aplikasi Bracket Forge:

1. **Memilih Mode Operasi**: Pilih salah satu opsi dari menu utama:
   - **Membuat Turnamen Baru**: Masukkan nama event (maksimal 8 karakter) dan mulai mendaftarkan tim peserta.
   - **Memuat Data Turnamen**: Memuat data turnamen yang telah disimpan sebelumnya dari file JSON.

2. **Mengelola Tim Peserta**: Gunakan opsi **Tambah Tim** untuk mendaftarkan tim baru atau **Hapus Tim** untuk menghapus tim yang sudah terdaftar.

3. **Memulai Penjadwalan**: Pilih opsi **Penjadwalan Pertandingan** untuk membangun bagan turnamen secara otomatis.

4. **Memasukkan Hasil Pertandingan**: Gunakan opsi **Hasil Pertandingan** untuk memperbarui bagan dan statistik tim berdasarkan hasil pertandingan.

5. **Menggunakan Fitur Undo**: Pilih **Undo Hasil Pertandingan** jika perlu membatalkan hasil pertandingan terakhir yang dimasukkan.

6. **Melihat Informasi Turnamen**: Akses **Bagan Pertandingan**, **Statistik Tim**, atau **Riwayat Pertandingan** untuk melihat status terkini turnamen.

7. **Menyimpan Data**: Gunakan opsi **Save Pertandingan** untuk menyimpan data secara manual, atau data akan tersimpan otomatis saat keluar dari aplikasi.

8. **Penyelesaian Turnamen**: Turnamen dianggap selesai ketika satu tim berhasil menjadi juara (root pada *binary tree* memiliki `id_pemenang`).

### Contoh Penggunaan Fitur

- **Mendaftarkan Tim**: Pilih opsi 1, masukkan jumlah tim (antara 3–12), kemudian masukkan nama setiap tim.
- **Menjadwalkan Pertandingan**: Pilih opsi 4 setelah berhasil mendaftarkan semua tim peserta.
- **Memasukkan Hasil**: Pilih opsi 5, masukkan ID pertandingan, ID tim pemenang, dan skor pertandingan.
- **Menyimpan Turnamen**: Pilih opsi 10 untuk keluar dan data akan tersimpan otomatis ke file `namaEvent.json`.

---

## 📊 Struktur Data yang Digunakan

Aplikasi ini mengimplementasikan berbagai struktur data untuk mengoptimalkan kinerja dan fungsionalitas:

| Struktur Data | Deskripsi Lengkap | Kegunaan dalam Aplikasi |
|---------------|-------------------|-------------------------|
| **Linked List** | Struktur data linear yang menyimpan informasi tim meliputi `id_tim`, `namaTim`, `laga`, `kemenangan`, dan `kekalahan`. | Digunakan untuk pendaftaran tim peserta dan pengelolaan statistik setiap tim. |
| **Queue** | Struktur data FIFO (First In, First Out) yang mengatur urutan tim untuk proses penjadwalan. | Mengorganisasi pembentukan *leaf nodes* pada struktur *binary tree* turnamen. |
| **Binary Tree** | Struktur data hierarkis yang merepresentasikan bagan turnamen dengan atribut `id_tim1`, `id_tim2`, `match_id`, dan `id_pemenang`. | Menyimpan struktur turnamen dan memfasilitasi pembaruan hasil pertandingan. |
| **Stack** | Struktur data LIFO (Last In, First Out) yang menyimpan riwayat pertandingan dengan detail `matchID`, `team1Id`, `team2Id`, `idPemenang`, `nomorRonde`, dan `skor`. | Mendukung fitur undo dan menampilkan riwayat pertandingan secara kronologis. |

---

## 🧪 Hasil Pengujian Aplikasi

Aplikasi telah melalui serangkaian pengujian komprehensif dengan 8 skenario test case untuk memastikan semua fungsionalitas bekerja dengan baik:

1. **Pengujian Pembuatan Turnamen Baru**: Memverifikasi bahwa bagan turnamen dapat dibuat, pertandingan dapat dijadwalkan, dan hasil dapat disimpan dengan benar. **Status: Berhasil**

2. **Pengujian Pemuatan Data Turnamen**: Memastikan data tim, bagan pertandingan, dan riwayat dapat dimuat dari file JSON dengan akurat. **Status: Berhasil**

3. **Pengujian Validasi Input Hasil**: Memverifikasi bahwa sistem menolak input hasil pertandingan ketika jadwal belum dibuat dengan menampilkan pesan error yang sesuai. **Status: Berhasil**

4. **Pengujian Fitur Undo**: Memastikan hasil pertandingan terakhir dapat dibatalkan dan statistik tim diperbarui dengan benar. **Status: Berhasil**

5. **Pengujian Validasi Menu**: Memverifikasi bahwa input yang tidak valid ditolak sistem dengan pesan error yang informatif. **Status: Berhasil**

6. **Pengujian Penyimpanan Otomatis**: Memastikan data turnamen tersimpan otomatis ke file JSON saat keluar dari aplikasi. **Status: Berhasil**

7. **Pengujian Validasi Nama Event**: Memverifikasi bahwa nama event dengan panjang lebih dari 8 karakter ditolak dengan pesan error yang jelas. **Status: Berhasil**

8. **Pengujian Tampilan Bagan Kosong**: Memastikan sistem menampilkan pesan yang sesuai ketika mencoba melihat bagan sebelum tim dijadwalkan. **Status: Berhasil**

---

## 🤝 Tim Pengembang dan Kontribusi

Proyek Bracket Forge dikembangkan oleh:

- **Belva Abthal Hidayat (241524035)**: Bertanggung jawab atas pengembangan fungsi-fungsi dalam `menu.c`, `tournament.c`, `queue.c`, penyusunan laporan, dan persiapan presentasi.

- **Faaiz Akhsya Nashrullah (241524037)**: Mengembangkan fungsi-fungsi dalam `stack.c`, `result.c`, `fileio.c`, berkontribusi dalam penyusunan laporan, dan persiapan presentasi.

- **Muhammad Danish Aufa (241524052)**: Mengimplementasikan fungsi-fungsi dalam `linkedlist.c`, `tree.c`, `templatebagan.c`, serta berkontribusi dalam penyusunan laporan dan persiapan presentasi.
