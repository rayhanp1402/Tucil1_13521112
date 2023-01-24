# Tugas Kecil 1 IF2211 Strategi Algoritma
## Semester 2 (Genap) Tahun 2022/2023
### Pencarian solusi dari Permainan Kartu 24 dengan Algoritma Brute Force

### Deskripsi Program

Implementasi Algoritma Brute Force yang digunakan dalam program adalah :

1. Cari seluruh susunan atau permutasi dari empat kartu yang digunakan.
2. Simpan seluruh susunan atau permutasi dari keempat tersebut yang mungkin.
3. Cari seluruh susunan atau permutasi dari seluruh operator aritmatika yang mungkin.
4. Simpan susunan-susunan operator aritmatika tersebut.
5. Iterasi semua susunan dari kartu, dan dari setiap satu susunan kartu, iterasi semua susunan operator aritmatika.
6. Lakukan operasi yang dibentuk dari satu susunan kartu dan operatornya dengan meninjau kasus-kasus kurung. 
7. Jika operasi menghasilkan 24, simpan operasi tersebut sebagai solusi.

### Requirement
Untuk melakukan kompilasi terhadap program, diperlukan compiler C/C++ yang dapat dirujuk pada tautan berikut

<a href="https://gcc.gnu.org/install/" target="_blank">GCCInstall</a>

### Cara Clone Program
Agar program dapat dijalankan pada mesin Anda, clone repository program dengan cara

```sh
git clone https://github.com/rayhanp1402/Tucil1_13521112.git
```

### Cara Run Program
Untuk menjalankan program, buka console dan masuk ke directory tempat Anda clone repository ini. Kemudian, jalankan perintah berikut

```sh
cd Tucil1_13521112/bin

24solver
```

Atau jika Anda telah mengkompilasi sendiri, buka console dan masuk ke directory tempat Anda clone repository ini dan jalankan perintah berikut

```sh
cd Tucil1_13521112/bin

nama_file_executable
```

### Cara Kompilasi Program
Jika Anda ingin mengkompilasi secara manual, buka console dan masuk ke directory tempat Anda clone repository ini dan jalankan perintah berikut

```sh
cd Tucil1_13521112/src
```

Anda akan berada pada directory untuk source code. Untuk mengkompilasi, jalankan perintah berikut

```sh
g++ -o nama_file_executable main.cpp solve24.cpp permutations.cpp
```

### Penggunaan Program
Saat run program, pertama kali akan ditampilkan main menu. Dari situ, pengguna memiliki pilihan untuk keluar dari program
atau "solve", yaitu mencari solusi untuk permainan Kartu 24.

Apabila pengguna memilih "solve", akan ditampilkan pilihan apakah ingin memilih empat kartu secara manual atau mengacaknya.
Untuk pemilihan kartu secara manual, input dapat berupa angka 2-10, 1 atau A, 11 atau J, 12 atau Q, dan 13 atau K

Selanjutnya akan ditampilkan jumlah solusi, solusi-solusinya, serta waktu eksekusi program dimana pengguna memiliki pilihan
untuk menyimpan hasil solusi tersebut pada sebuah file yang dapat dinamai oleh pengguna tersebut. File penyimpanan solusi
disimpan pada folder test.

Kemudian program akan kembali ke main menu.

Untuk input yang tidak sesuai, program akan mengulang hingga input benar.

### Contoh Penggunaan Program
1. Main menu

![Menu](https://cdn.discordapp.com/attachments/865154167169351730/1067554603052318730/show1.jpg)

<br>

2. Solve

![Solve](https://cdn.discordapp.com/attachments/865154167169351730/1067554602595127446/show2.jpg)

<br>

3. Simpan ke file

![Save](https://cdn.discordapp.com/attachments/865154167169351730/1067554602091814912/show3.jpg)

<br>

4. Exit

![Exit](https://cdn.discordapp.com/attachments/865154167169351730/1067554601722724463/show4.jpg)

## Dibuat oleh
Nama : Rayhan Hanif Maulana Pradana

NIM : 13521112