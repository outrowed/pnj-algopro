#include <iostream>
#include <string>

int main() {
    int sisaUang = 0;

    while (true) {
        std::cout << "==========[[ INDOMARET ]]==========\n"
            << "~ Selamat datang di Indomaret! ~\n"
            << "Silahkan pilih barang yang anda ingin beli:\n"
            << "\n"
            << "== MAKANAN RINGAN ==\n"
            << "1. Sari Roti Coklat - Rp. 16,000\n"
            << "2. Silverqueen Coklat Bar - Rp. 46,000\n"
            << "3. Dairy Milk Coklat Bar - Rp. 47,000\n"
            << "4. Kacang Garuda - Rp. 12,000\n"
            << "5. Permen Kiss - Rp. 3,000\n"
            << "6. Permen Karet - Rp. 3,000\n"
            << "\n"
            << "== SOFT DRINK ==\n"
            << "7. Susu Cimory Coklat - Rp. 7,000\n"
            << "8. Teh Botol - Rp. 4,000\n"
            << "9. Coca-cola - Rp. 6,000\n"
            << "10. Botol Air Putih - Rp. 3,000\n"
            << "\n"
            << "== LAIN-LAIN ==\n"
            << "11. Mesin ATM Bank (tarik tunai)\n"
            << "12. Bayar di kasir\n"
            << "\n"
            << "Sisa Uang: Rp. " << sisaUang << "\n"
            << "\n"
            << "Input nomor barang yang dibeli (1-10),\n  tarik tunai dari ATM (11),\n  atau bayar di kasir (12)\n";

        int totalBelanja = 0;
        std::string daftarBarangTerpilih = "";

        while (true) {
            std::string pilihan;
    
            std::cout << "-> ";
        
            std::getline(std::cin, pilihan);

            // Pembelian barang dalam keranjang
            if (pilihan == "1") {
                daftarBarangTerpilih += "Sari Roti Coklat - Rp. 16,000\n";
                totalBelanja += 16000;
                std::cout << "[+] Sari Roti Coklat ditambahkan ke keranjang.\n";
            }
            else if (pilihan == "2") {
                daftarBarangTerpilih += "Silverqueen Coklat Bar - Rp. 46,000\n";
                totalBelanja += 46000;
                std::cout << "[+] Silverqueen Coklat Bar ditambahkan ke keranjang.\n";
            }
            else if (pilihan == "3") {
                daftarBarangTerpilih += "Dairy Milk Coklat Bar - Rp. 47,000\n";
                totalBelanja += 47000;
                std::cout << "[+] Dairy Milk Coklat Bar ditambahkan ke keranjang.\n";
            }
            else if (pilihan == "4") {
                daftarBarangTerpilih += "Kacang Garuda - Rp. 12,000\n";
                totalBelanja += 12000;
                std::cout << "[+] Kacang Garuda ditambahkan ke keranjang.\n";
            }
            else if (pilihan == "5") {
                daftarBarangTerpilih += "Permen Kiss - Rp. 3,000\n";
                totalBelanja += 3000;
                std::cout << "[+] Permen Kiss ditambahkan ke keranjang.\n";
            }
            else if (pilihan == "6") {
                daftarBarangTerpilih += "Permen Karet - Rp. 3,000\n";
                totalBelanja += 3000;
                std::cout << "[+] Permen Karet ditambahkan ke keranjang.\n";
            }
            else if (pilihan == "7") {
                daftarBarangTerpilih += "Susu Cimory Coklat - Rp. 7,000\n";
                totalBelanja += 7000;
                std::cout << "[+] Susu Cimory Coklat ditambahkan ke keranjang.\n";
            }
            else if (pilihan == "8") {
                daftarBarangTerpilih += "Teh Botol - Rp. 4,000\n";
                totalBelanja += 4000;
                std::cout << "[+] Teh Botol ditambahkan ke keranjang.\n";
            }
            else if (pilihan == "9") {
                daftarBarangTerpilih += "Coca-cola - Rp. 6,000\n";
                totalBelanja += 6000;
                std::cout << "[+] Coca-cola ditambahkan ke keranjang.\n";
            }
            else if (pilihan == "10") {
                daftarBarangTerpilih += "Botol Air Mineral - Rp. 3,000\n";
                totalBelanja += 3000;
                std::cout << "[+] Botol Air Mineral ditambahkan ke keranjang.\n";
            }
            
            // Tarik tunak di ATM Bank
            else if (pilihan == "11") {
                int tarikTunai;
                std::string tarikTunaiInput;

                std::cout << "ATM: Masukkan jumlah yang ingin ditarik: ";
                
                std::getline(std::cin, tarikTunaiInput);

                tarikTunai = std::stoi(tarikTunaiInput);
                
                if (tarikTunai > 0) {
                    sisaUang += tarikTunai;
                    std::cout << "Berhasil menarik Rp. " << tarikTunai << ". Uang Anda sekarang: Rp. " << sisaUang << "\n";
                }
                else {
                    std::cout << "Jumlah tidak valid.\n";
                }
            }
            
            // Pembayaran
            else if (pilihan == "12") {
                break; // Lanjut ke proses pembayaran di bawah
            }
        }

        std::cout << "\n\n=== Proses Pembayaran ===\n";
            
        if (totalBelanja > 0) {
            // Sukses
            if (sisaUang >= totalBelanja) {
                sisaUang -= totalBelanja;
                
                std::cout << "--- Struk Belanja ---\n";
                std::cout << daftarBarangTerpilih;
                std::cout << "---------------------\n";
                std::cout << "Total Belanja: Rp. " << totalBelanja << "\n";
                std::cout << "-> Pembayaran BERHASIL. <-\n";
                std::cout << "Sisa Uang Anda: Rp. " << sisaUang << "\n";
                std::cout << "---------------------\n";
                std::cout << "Terima kasih telah berbelanja!\n";
            }
            // Gagal
            else {
                std::cout << "MAAF, UANG ANDA TIDAK CUKUP!\n";
                std::cout << "Total belanja: Rp. " << totalBelanja << "\n";
                std::cout << "Uang Anda: Rp. " << sisaUang << "\n";
                std::cout << "Silahkan ambil uang di ATM atau mulai lagi.\n";
            }
        }
        else {
            std::cout << "Anda belum membeli barang apapun.\n";
        }

        std::string lanjutAtauKeluar;

        std::cout << "Apakah anda ingin melanjut atau keluar dari Indomaret? (1: Lanjut, 2: Keluar)\n";

        std::getline(std::cin, lanjutAtauKeluar);

        if (lanjutAtauKeluar == "1") {
            continue;
        }
        else if (lanjutAtauKeluar == "2") {
            std::cout << "Anda telah keluar dari Indomaret, terima kasih untuk berbelanja!\n";
            break;
        }
    }

    return 0;
}