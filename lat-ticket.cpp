/*
Seseorang memesan tiket bioskop dengan rincian:

Jumlah tiket = 4

Harga per tiket = Rp50.000

Diskon diberikan jika membeli lebih dari 3 tiket, yaitu 10% dari total harga.

Buat variabel untuk jumlah tiket, harga tiket, dan diskon.

Hitung total harga yang harus dibayar setelah diskon.

Gunakan ekspresi relasional untuk memeriksa apakah total harga lebih dari Rp200.000.
*/
#include <iostream>

using namespace std;

int main() {
    int jumlahTicket = 4;
    
    float hargaTicket = 50'000,
        diskonTicket = 0.1; // 10%

    cout << "Harga ticket awal: " << hargaTicket << "\n";

    if (jumlahTicket > 3) {
        hargaTicket *= diskonTicket;
        cout << "Harga satu ticket setelah diskon: " << hargaTicket << "\n";
    }
    else {
        cout << "Harga ticket tidak ganti" << "\n";
    }

    float totalHarga = jumlahTicket * hargaTicket;

    cout << "Total harga pembelian 3 ticket: " << totalHarga << "\n";

    if (totalHarga > 200'000) {
        cout << "Total harga lebih dari Rp 200,000";
    }
}