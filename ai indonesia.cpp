#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Resep {
    string nama;
    string bahan;
    string kategori;  // mudah/sedang/sulit
    double skor_ai;   // skor pembelajaran AI
};

class ResepAI {
private:
    vector<Resep> daftar_resep;
    // Pembelajaran AI sederhana
    double suka_mudah, suka_sedang, suka_sulit;

public:
    ResepAI() {
        // Resep awal
        daftar_resep.push_back({"Nasi Goreng", "nasi, telur, kecap", "mudah", 0});
        daftar_resep.push_back({"Mie Ayam", "mie, ayam, sayur", "mudah", 0});
        daftar_resep.push_back({"Soto", "ayam, kuah, nasi", "sedang", 0});
        daftar_resep.push_back({"Rendang", "daging, santan, cabai", "sulit", 0});
        daftar_resep.push_back({"Gado-gado", "sayur, bumbu kacang", "sedang", 0});

        // AI mulai netral
        suka_mudah = suka_sedang = suka_sulit = 0;
    }

    void tambahResep() {
        string nama, bahan, kategori;
        int pilihan;

        cout << "\nMasukkan nama resep: ";
        cin.ignore();
        getline(cin, nama);

        cout << "Masukkan bahan-bahan: ";
        getline(cin, bahan);

        cout << "\nPilih tingkat kesulitan:\n";
        cout << "1. Mudah\n";
        cout << "2. Sedang\n";
        cout << "3. Sulit\n";
        cout << "Pilih (1-3): ";
        cin >> pilihan;

        switch(pilihan) {
            case 1: kategori = "mudah"; break;
            case 2: kategori = "sedang"; break;
            case 3: kategori = "sulit"; break;
            default: kategori = "mudah"; break;
        }

        daftar_resep.push_back({nama, bahan, kategori, 0});
        cout << "Resep berhasil ditambahkan!\n";
    }

    void lihatResep() {
        cout << "\n=== DAFTAR RESEP ===\n";
        for (int i = 0; i < daftar_resep.size(); i++) {
            cout << i+1 << ". " << daftar_resep[i].nama
                 << " (" << daftar_resep[i].kategori << ")" << endl;
            cout << "   Bahan: " << daftar_resep[i].bahan << endl;
            cout << "   Skor AI: " << daftar_resep[i].skor_ai << endl << endl;
        }
    }

    // === AI LEARNING ===
    void beriPenilaian() {
        if (daftar_resep.empty()) {
            cout << "Belum ada resep!\n";
            return;
        }

        lihatResep();

        int nomor;
        char suka;

        cout << "Pilih nomor resep (1-" << daftar_resep.size() << "): ";
        cin >> nomor;

        if (nomor < 1 || nomor > daftar_resep.size()) {
            cout << "Nomor tidak valid!\n";
            return;
        }

        cout << "Apakah Anda suka resep ini? (y/n): ";
        cin >> suka;

        Resep& resep = daftar_resep[nomor-1];

        if (suka == 'y' || suka == 'Y') {
            // User suka - tingkatkan skor
            resep.skor_ai += 1;

            // AI belajar preferensi kategori
            if (resep.kategori == "mudah") suka_mudah += 1;
            else if (resep.kategori == "sedang") suka_sedang += 1;
            else if (resep.kategori == "sulit") suka_sulit += 1;

            cout << "✓ AI Belajar: Anda suka resep " << resep.kategori << endl;
        } else {
            // User tidak suka - kurangi skor
            resep.skor_ai -= 1;

            // AI belajar preferensi kategori
            if (resep.kategori == "mudah") suka_mudah -= 1;
            else if (resep.kategori == "sedang") suka_sedang -= 1;
            else if (resep.kategori == "sulit") suka_sulit -= 1;

            cout << "✓ AI Belajar: Anda kurang suka resep " << resep.kategori << endl;
        }

        cout << " Pembelajaran AI selesai!\n";
    }

    void rekomendasiAI() {
        if (daftar_resep.empty()) {
            cout << "Belum ada resep!\n";
            return;
        }

        cout << "\nREKOMENDASI AI:\n";
        cout << "==================\n";

        // Hitung skor untuk setiap resep
        vector<pair<double, int>> skor_resep;

        for (int i = 0; i < daftar_resep.size(); i++) {
            double total_skor = daftar_resep[i].skor_ai;

            // Tambah bonus berdasarkan pembelajaran AI
            if (daftar_resep[i].kategori == "mudah") {
                total_skor += suka_mudah;
            } else if (daftar_resep[i].kategori == "sedang") {
                total_skor += suka_sedang;
            } else if (daftar_resep[i].kategori == "sulit") {
                total_skor += suka_sulit;
            }

            skor_resep.push_back({total_skor, i});
        }

        // Urutkan berdasarkan skor tertinggi
        sort(skor_resep.begin(), skor_resep.end(), greater<pair<double, int>>());

        // Tampilkan top 3 rekomendasi
        int jumlah = min(3, (int)skor_resep.size());
        for (int i = 0; i < jumlah; i++) {
            int idx = skor_resep[i].second;
            Resep& resep = daftar_resep[idx];

            cout << i+1 << ". " << resep.nama
                 << " (" << resep.kategori << ")" << endl;
            cout << "   Skor AI: " << skor_resep[i].first << endl;
            cout << "   Bahan: " << resep.bahan << endl << endl;
        }

        if (skor_resep[0].first <= 0) {
            cout << "Tips: Beri penilaian pada resep untuk rekomendasi yang lebih baik!\n";
        }
    }

    void lihatPembelajaranAI() {
        cout << "\nPEMBELAJARAN AI:\n";
        cout << "===================\n";
        cout << "Preferensi Tingkat Kesulitan:\n";
        cout << "  Mudah  : " << suka_mudah << endl;
        cout << "  Sedang : " << suka_sedang << endl;
        cout << "  Sulit  : " << suka_sulit << endl << endl;

        // Tentukan preferensi terkuat
        string preferensi = "belum diketahui";
        double max_suka = max({suka_mudah, suka_sedang, suka_sulit});

        if (max_suka > 0) {
            if (suka_mudah == max_suka) preferensi = "resep mudah";
            else if (suka_sedang == max_suka) preferensi = "resep sedang";
            else if (suka_sulit == max_suka) preferensi = "resep sulit";
        }

        cout << "AI memprediksi Anda lebih suka: " << preferensi << endl;
    }

    void demoAI() {
        cout << "\nDEMO AI LEARNING:\n";
        cout << "====================\n";
        cout << "Simulasi: User suka resep mudah...\n";

        // Simulasi suka resep mudah
        for (int i = 0; i < daftar_resep.size(); i++) {
            if (daftar_resep[i].kategori == "mudah") {
                daftar_resep[i].skor_ai += 2;
                suka_mudah += 2;
            }
        }

        cout << "Simulasi: User tidak suka resep sulit...\n";

        // Simulasi tidak suka resep sulit
        for (int i = 0; i < daftar_resep.size(); i++) {
            if (daftar_resep[i].kategori == "sulit") {
                daftar_resep[i].skor_ai -= 1;
                suka_sulit -= 1;
            }
        }

        cout << "Demo selesai! Lihat rekomendasi AI sekarang.\n";
    }

    void jalankan() {
        int pilihan;


        cout << "    PROGRAM RESEP DENGAN AI LEARNING   \n";
        cout << "           Versi Sederhana          \n";


        while (true) {
            cout << "\nMenu:\n";
            cout << "1. Lihat Resep\n";
            cout << "2. Tambah Resep\n";
            cout << "3. Beri Penilaian (AI Learning)\n";
            cout << "4. Rekomendasi AI\n";
            cout << "5. Lihat Pembelajaran AI\n";
            cout << "6. Demo AI\n";
            cout << "7. Keluar\n";
            cout << "Pilih: ";
            cin >> pilihan;

            switch (pilihan) {
                case 1: lihatResep(); break;
                case 2: tambahResep(); break;
                case 3: beriPenilaian(); break;
                case 4: rekomendasiAI(); break;
                case 5: lihatPembelajaranAI(); break;
                case 6: demoAI(); break;
                case 7:
                    cout << "Terima kasih! AI telah belajar dari Anda.\n";
                    return;
                default:
                    cout << "Pilihan salah!\n";
            }
        }
    }
};

int main() {
    ResepAI program;
    program.jalankan();
    return 0;
}
