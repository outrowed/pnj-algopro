/*
    Seorang mahasiswa membeli 3 buku seharga Rp25.000 per buah dan 2 pensil seharga Rp3.000 per buah.

    Buatlah variabel untuk menyimpan jumlah dan harga tiap barang.

    Hitung total biaya yang harus dibayar menggunakan ekspresi aritmatika.

    Jika mahasiswa hanya membawa uang Rp80.000, tuliskan ekspresi logika/relasional untuk memeriksa apakah uangnya cukup.
*/
#include <iostream>

using namespace std;

int main() {
    int buku = 25000,
        pensil = 3000;
    
    int uangMahasiswa = 80000;

    int biayaMahasiswa = 0;

    biayaMahasiswa += buku * 3;
    biayaMahasiswa += pensil * 2;

    cout << "Total biaya mahasiswa yaitu: Rp " << biayaMahasiswa << "\n";
    cout << "Mahasiwa mempunyai uang: Rp " << uangMahasiswa << "\n";

    if (biayaMahasiswa > uangMahasiswa) {
        cout << "Biaya mahasiswa melebihi uang mahasiswa, sehingga tidak bisa bayar" << "\n";
    }
    else {
        cout << "Mahasiswa mempunyai uang yang cukup untuk membayar total biaya barang-barang" << "\n";
    }
}