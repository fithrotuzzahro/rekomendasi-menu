#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Data resep masakan Indonesia
struct Resep {
    string nama;
    string tingkat;    // mudah/sedang/sulit
    string bahan;      // ayam/sapi/ikan/sayuran/nasi

    Resep(string n, string t, string b)
        : nama(n), tingkat(t), bahan(b) {}
};

class SistemResepIndonesia {
private:
    vector<Resep> daftar_resep;

public:
    // Inisialisasi data resep Indonesia
    SistemResepIndonesia() {
        // RESEP INDONESIA - MUDAH
        daftar_resep.push_back(Resep("Nasi Goreng", "mudah", "nasi"));
        daftar_resep.push_back(Resep("Ayam Goreng", "mudah", "ayam"));
        daftar_resep.push_back(Resep("Tumis Kangkung", "mudah", "sayuran"));
        daftar_resep.push_back(Resep("Ikan Goreng", "mudah", "ikan"));
        daftar_resep.push_back(Resep("Tumis Daging", "mudah", "sapi"));
        daftar_resep.push_back(Resep("Mie Goreng", "mudah", "nasi"));
        daftar_resep.push_back(Resep("Sayur Sop", "mudah", "sayuran"));
        daftar_resep.push_back(Resep("Ayam Geprek", "mudah", "ayam"));

        // RESEP INDONESIA - SEDANG
        daftar_resep.push_back(Resep("Nasi Kuning", "sedang", "nasi"));
        daftar_resep.push_back(Resep("Soto Ayam", "sedang", "ayam"));
        daftar_resep.push_back(Resep("Gado-Gado", "sedang", "sayuran"));
        daftar_resep.push_back(Resep("Ikan Bakar", "sedang", "ikan"));
        daftar_resep.push_back(Resep("Semur Daging", "sedang", "sapi"));
        daftar_resep.push_back(Resep("Nasi Uduk", "sedang", "nasi"));
        daftar_resep.push_back(Resep("Capcay", "sedang", "sayuran"));
        daftar_resep.push_back(Resep("Gulai Ayam", "sedang", "ayam"));
        daftar_resep.push_back(Resep("Pecel Lele", "sedang", "ikan"));
        daftar_resep.push_back(Resep("Rawon", "sedang", "sapi"));

        // RESEP INDONESIA - SULIT
        daftar_resep.push_back(Resep("Nasi Liwet", "sulit", "nasi"));
        daftar_resep.push_back(Resep("Ayam Betutu", "sulit", "ayam"));
        daftar_resep.push_back(Resep("Gudeg", "sulit", "sayuran"));
        daftar_resep.push_back(Resep("Pepes Ikan", "sulit", "ikan"));
        daftar_resep.push_back(Resep("Rendang", "sulit", "sapi"));
        daftar_resep.push_back(Resep("Tumpeng", "sulit", "nasi"));
        daftar_resep.push_back(Resep("Sayur Lodeh", "sulit", "sayuran"));
        daftar_resep.push_back(Resep("Ayam Taliwang", "sulit", "ayam"));
        daftar_resep.push_back(Resep("Gulai Ikan", "sulit", "ikan"));
        daftar_resep.push_back(Resep("Sate Padang", "sulit", "sapi"));
    }

    // Cari resep berdasarkan 2 kriteria
    string cariResep(string tingkat, string bahan) {

        // Cari resep yang cocok dengan semua kriteria
        for (const auto& resep : daftar_resep) {
            if (resep.tingkat == tingkat && resep.bahan == bahan) {
                return resep.nama;
            }
        }

        // Jika tidak ada yang cocok 100%, cari berdasarkan prioritas:

        // 1. Cari berdasarkan bahan dulu
        for (const auto& resep : daftar_resep) {
            if (resep.bahan == bahan) {
                return resep.nama;
            }
        }

        // 2. Cari berdasarkan tingkat kesulitan
        for (const auto& resep : daftar_resep) {
            if (resep.tingkat == tingkat) {
                return resep.nama;
            }
        }

        // Default jika tidak ada yang cocok
        return "Nasi Goreng";
    }

    // Tampilkan detail resep
    void tampilkanDetail(string nama_resep) {
        for (const auto& resep : daftar_resep) {
            if (resep.nama == nama_resep) {
                cout << "\n=== RESEP REKOMENDASI ===" << endl;
                cout << "Nama      : " << resep.nama << endl;
                cout << "Tingkat   : " << resep.tingkat << endl;
                cout << "Bahan     : " << resep.bahan << endl;
                cout << "========================" << endl;
                return;
            }
        }
    }

    // Tampilkan semua resep berdasarkan kategori
    void tampilkanSemua() {
        cout << "\n=== DAFTAR SEMUA RESEP INDONESIA ===" << endl;

        cout << "\nTINGKAT MUDAH:" << endl;
        for (const auto& resep : daftar_resep) {
            if (resep.tingkat == "mudah") {
                cout << "  - " << resep.nama << " (" << resep.bahan << ")" << endl;
            }
        }

        cout << "\nTINGKAT SEDANG:" << endl;
        for (const auto& resep : daftar_resep) {
            if (resep.tingkat == "sedang") {
                cout << "  - " << resep.nama << " (" << resep.bahan << ")" << endl;
            }
        }

        cout << "\nTINGKAT SULIT:" << endl;
        for (const auto& resep : daftar_resep) {
            if (resep.tingkat == "sulit") {
                cout << "  - " << resep.nama << " (" << resep.bahan << ")" << endl;
            }
        }
    }

    // Tampilkan resep berdasarkan bahan
    void tampilkanBerdasarkanBahan() {
        cout << "\n=== RESEP BERDASARKAN BAHAN ===" << endl;

        cout << "\nBERBASIS NASI:" << endl;
        for (const auto& resep : daftar_resep) {
            if (resep.bahan == "nasi") {
                cout << "  - " << resep.nama << " (" << resep.tingkat << ")" << endl;
            }
        }

        cout << "\nBERBASIS AYAM:" << endl;
        for (const auto& resep : daftar_resep) {
            if (resep.bahan == "ayam") {
                cout << "  - " << resep.nama << " (" << resep.tingkat << ")" << endl;
            }
        }

        cout << "\nBERBASIS SAPI:" << endl;
        for (const auto& resep : daftar_resep) {
            if (resep.bahan == "sapi") {
                cout << "  - " << resep.nama << " (" << resep.tingkat << ")" << endl;
            }
        }

        cout << "\nBERBASIS IKAN:" << endl;
        for (const auto& resep : daftar_resep) {
            if (resep.bahan == "ikan") {
                cout << "  - " << resep.nama << " (" << resep.tingkat << ")" << endl;
            }
        }

        cout << "\nBERBASIS SAYURAN:" << endl;
        for (const auto& resep : daftar_resep) {
            if (resep.bahan == "sayuran") {
                cout << "  - " << resep.nama << " (" << resep.tingkat << ")" << endl;
            }
        }
    }

    // Proses rekomendasi (hanya 2 input)
    void prosesRekomendasi() {
        string tingkat, bahan;

        cout << "\n=== INPUT PREFERENSI ===" << endl;

        cout << "Tingkat kesulitan (mudah/sedang/sulit): ";
        cin >> tingkat;

        cout << "Bahan utama (ayam/sapi/ikan/sayuran/nasi): ";
        cin >> bahan;

        // Cari rekomendasi
        string rekomendasi = cariResep(tingkat, bahan);

        cout << "\nREKOMENDASI MASAKAN INDONESIA UNTUK ANDA: " << rekomendasi << endl;

        // Tampilkan detail
        tampilkanDetail(rekomendasi);
    }

    // Menu utama
    void jalankan() {
        int pilihan;

        cout << "=== SISTEM REKOMENDASI RESEP MASAKAN INDONESIA ===" << endl;
        cout << "Sistem rekomendasi khusus masakan Indonesia" << endl;
        cout << "Berdasarkan: Tingkat Kesulitan & Bahan Utama" << endl;

        while (true) {
            cout << "\nMENU:" << endl;
            cout << "1. Dapatkan Rekomendasi" << endl;
            cout << "2. Lihat Semua Resep bedasarkan tingkat" << endl;
            cout << "3. Lihat Resep dari Bahan" << endl;
            cout << "4. Keluar" << endl;
            cout << "Pilih (1-4): ";
            cin >> pilihan;

            if (pilihan == 1) {
                prosesRekomendasi();
            }
            else if (pilihan == 2) {
                tampilkanSemua();
            }
            else if (pilihan == 3) {
                tampilkanBerdasarkanBahan();
            }
            else if (pilihan == 4) {
                cout << "Terima kasih telah menggunakan sistem rekomendasi!" << endl;
                break;
            }
            else {
                cout << "Pilihan tidak valid! Silakan pilih 1-4." << endl;
            }
        }
    }
};

int main() {
    // Buat dan jalankan sistem
    SistemResepIndonesia sistem;
    sistem.jalankan();
    return 0;
}
