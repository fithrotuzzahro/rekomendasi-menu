#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Resep {
    string nama;
    string bahan;
    int skor;
};

class ResepAI {
private:
    vector<Resep> resep_list;

public:
    ResepAI() {
        // Data awal
        resep_list.push_back({"Nasi Goreng", "nasi, telur, kecap", 0});
        resep_list.push_back({"Mie Ayam", "mie, ayam, sayur", 0});
        resep_list.push_back({"Soto Ayam", "ayam, kuah, nasi", 0});
    }

    void tampilkanResep() {
        cout << "\n--- DAFTAR RESEP ---\n";
        for (int i = 0; i < resep_list.size(); i++) {
            cout << i+1 << ". " << resep_list[i].nama << endl;
            cout << "   Bahan: " << resep_list[i].bahan << endl;
            cout << "   Skor: " << resep_list[i].skor << endl << endl;
        }
    }

    void tambahResep() {
        string nama, bahan;

        cout << "Nama resep: ";
        cin.ignore();
        getline(cin, nama);

        cout << "Bahan-bahan: ";
        getline(cin, bahan);

        resep_list.push_back({nama, bahan, 0});
        cout << "Resep ditambahkan!\n";
    }

    void beriNilai() {
        tampilkanResep();

        int no;
        char suka;

        cout << "Pilih nomor resep: ";
        cin >> no;

        if (no < 1 || no > resep_list.size()) {
            cout << "Nomor salah!\n";
            return;
        }

        cout << "Suka resep ini? (y/n): ";
        cin >> suka;

        if (suka == 'y') {
            resep_list[no-1].skor++;
            cout << "AI belajar: Anda suka resep ini!\n";
        } else {
            resep_list[no-1].skor--;
            cout << "AI belajar: Anda kurang suka resep ini!\n";
        }
    }

    void rekomendasiAI() {
        cout << "\n--- REKOMENDASI AI ---\n";

        int terbaik = 0;
        for (int i = 1; i < resep_list.size(); i++) {
            if (resep_list[i].skor > resep_list[terbaik].skor) {
                terbaik = i;
            }
        }

        if (resep_list[terbaik].skor > 0) {
            cout << "AI merekomendasikan: " << resep_list[terbaik].nama << endl;
            cout << "Skor: " << resep_list[terbaik].skor << endl;
        } else {
            cout << "Belum ada rekomendasi. Beri nilai dulu!\n";
        }
    }

    void jalankan() {
        int pilihan;

        cout << "=== PROGRAM RESEP AI ===\n";

        while (true) {
            cout << "\nMenu:\n";
            cout << "1. Lihat Resep\n";
            cout << "2. Tambah Resep\n";
            cout << "3. Beri Nilai\n";
            cout << "4. Rekomendasi AI\n";
            cout << "5. Keluar\n";
            cout << "Pilih: ";
            cin >> pilihan;

            if (pilihan == 1) {
                tampilkanResep();
            } else if (pilihan == 2) {
                tambahResep();
            } else if (pilihan == 3) {
                beriNilai();
            } else if (pilihan == 4) {
                rekomendasiAI();
            } else if (pilihan == 5) {
                cout << "Sampai jumpa!\n";
                break;
            } else {
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
