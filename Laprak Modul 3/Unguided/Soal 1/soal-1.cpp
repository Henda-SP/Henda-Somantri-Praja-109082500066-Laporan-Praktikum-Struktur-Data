#include <iostream>

using namespace std;

struct mahasiswa {
    char nama[50];
    char nim[10];
    float uts, uas, tugas, nilaiAkhir;
};

float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return (0.3 * uts) + (0.4 * uas) + (0.3 * tugas);
}

int main() {
    int n;
    cout << "Masukkan jumlah mahasiswa (maks. 10): ";
    cin >> n;

    if (n > 10) {
        n = 10;
    }

    mahasiswa mhs[10];
    
    for (int i = 0; i < n; i++) {
        cout << "\nMahasiswa ke-" << i + 1 << endl;
        cout << " Nama : ";
        cin >> mhs[i].nama;
        cout << " NIM : ";
        cin >> mhs[i].nim;
        cout << " Nilai UTS : ";
        cin >> mhs[i].uts;
        cout << " Nilai UAS : ";
        cin >> mhs[i].uas;
        cout << " Nilai Tugas : ";
        cin >> mhs[i].tugas;
    
        mhs[i].nilaiAkhir = hitungNilaiAkhir(mhs[i].uts, mhs[i].uas, mhs[i].tugas);
    }
    cout << "\n--- Daftar Nilai Akhir Mahasiswa ---" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Nama : " << mhs[i].nama << endl;
        cout << "NIM : " << mhs[i].nim << endl;
        cout << "Nilai Akhir : " << mhs[i].nilaiAkhir << endl;
    }
    return 0;
}