// input: nama, nim, nilai
// output: huruf, sebutan, angka mutu
#include <iostream>
#include <string>

int main() {
    std::string nama, nim;
    float nilai = 0.0f;

    std::string nilaiInput;

    std::cout << "Input nama:\n";
    std::getline(std::cin, nama);

    std::cout << "Input NIM:\n";
    std::getline(std::cin, nim);

    std::cout << "Input nilai:\n";
    std::getline(std::cin, nilaiInput);

    nilai = std::stof(nilaiInput);

    std::string hurufMutu, sebutan, angkaMutu, range;

    if (nilai > 100) {
        std::cout << "Nilai salah, karena lebih dari 100\n";
        return 1; // tidak akan melanjut
    }
    
    if (nilai >= 81) {
        hurufMutu = "A";
        sebutan = "Sangat Istimewa";
        angkaMutu = "4";
        range = "20";
    }
    else if (nilai >= 76) {
        hurufMutu = "A-";
        sebutan = "Istimewa";
        angkaMutu = "3.7";
        range = "5";
    }
    else if (nilai >= 72) {
        hurufMutu = "B+";
        sebutan = "Lebih dari Baik";
        angkaMutu = "3.3";
        range = "4";
    }
    else if (nilai >= 68) {
        hurufMutu = "B";
        sebutan = "Baik";
        angkaMutu = "3";
        range = "4";
    }
    else if (nilai >= 64) {
        hurufMutu = "B-";
        sebutan = "Cukup Baik";
        angkaMutu = "2.7";
        range = "4";
    }
    else if (nilai >= 60) {
        hurufMutu = "C+";
        sebutan = "Lebih dari Cukup";
        angkaMutu = "2.3";
        range = "4";
    }
    else if (nilai >= 56) {
        hurufMutu = "C";
        sebutan = "Cukup";
        angkaMutu = "2";
        range = "4";
    }
    else if (nilai >= 41) {
        hurufMutu = "D";
        sebutan = "Kurang";
        angkaMutu = "1";
        range = "15";
    }
    else if (nilai >= 1) {
        hurufMutu = "E";
        sebutan = "Gagal";
        angkaMutu = "0";
        range = "41";
    }
    
    std::cout << "--- Profil mahasiswa ---\n";
    std::cout << "Nama: " << nama << "\n";
    std::cout << "NIM: " << nim << "\n";
    std::cout << "Nilai: " << nilaiInput << "\n";
    std::cout << "--- Hasil ---\n";
    std::cout << "Huruf mutu: " << hurufMutu << "\n";
    std::cout << "Sebutan mutu: " << sebutan << "\n";
    std::cout << "Angka mutu: " << angkaMutu << "\n";
    std::cout << "Range: " << range << "\n";

    return 0;
}