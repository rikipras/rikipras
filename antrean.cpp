#include <iostream>
#include <iomanip>
#include <stdexcept>

// Fungsi untuk menghitung Lq pada model M/M/1
double calculateLq(double lambda, double mu) {
    if (mu <= lambda) {
        throw std::invalid_argument("Tingkat pelayanan (mu) harus lebih besar dari tingkat kedatangan (lambda) untuk sistem stabil.");
    }
    return (lambda * lambda) / (mu * (mu - lambda));
}

void explainCalculation(double lambda, double mu, double Lq) {
    std::cout << "\nPenjelasan Perhitungan:\n";
    std::cout << "1. Tingkat kedatangan (lambda) = " << lambda << " pelanggan per satuan waktu.\n";
    std::cout << "2. Tingkat pelayanan (mu) = " << mu << " pelanggan per satuan waktu.\n";
    std::cout << "3. Rumus untuk Lq:\n";
    std::cout << "   Lq = (lambda^2) / (mu * (mu - lambda))\n";
    std::cout << "4. Substitusi nilai:\n";
    std::cout << "   Lq = (" << lambda << "^2) / (" << mu << " * (" << mu << " - " << lambda << "))\n";
    std::cout << "   Lq = " << Lq << " pelanggan.\n";
}

int main() {
    double lambda, mu;

    std::cout << "======================================\n";
    std::cout << "  Kalkulator Antrean (Model M/M/1)\n";
    std::cout << "======================================\n";

    try {
        // Input tingkat kedatangan (lambda)
        std::cout << "Masukkan tingkat kedatangan (lambda): ";
        std::cin >> lambda;
        if (std::cin.fail() || lambda <= 0) {
            throw std::invalid_argument("Tingkat kedatangan harus berupa angka positif.");
        }

        // Input tingkat pelayanan (mu)
        std::cout << "Masukkan tingkat pelayanan (mu): ";
        std::cin >> mu;
        if (std::cin.fail() || mu <= 0) {
            throw std::invalid_argument("Tingkat pelayanan harus berupa angka positif.");
        }

        // Hitung Lq
        double Lq = calculateLq(lambda, mu);

        // Tampilkan hasil
        std::cout << "\nHasil:\n";
        std::cout << "Jumlah rata-rata pelanggan dalam antrian (Lq): " << std::fixed << std::setprecision(2) << Lq << " pelanggan.\n";

        // Penjelasan perhitungan
        explainCalculation(lambda, mu, Lq);

    } catch (const std::invalid_argument& e) {
        std::cerr << "\nError: " << e.what() << "\n";
    }

    return 0;
}