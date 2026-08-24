#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class NhanVien {
private:
    string hovaten;

public:
    NhanVien() {
        hovaten = "";
    }

    NhanVien(string ten) {
        hovaten = ten;
    }

    void xuat(int stt) {
        cout << left << setw(10) << stt
             << setw(30) << hovaten << endl;
    }
};

int main() {
    int n;

    cout << "Nhap so luong nhan vien: ";
    cin >> n;
    cin.ignore();

    NhanVien *dsnv;
    dsnv = new NhanVien[n];

    for (int i = 0; i < n; i++) {
        string ten;

        cout << "Nhap ho va ten nhan vien thu " << i + 1 << ": ";
        getline(cin, ten);

        dsnv[i] = NhanVien(ten);
    }

    cout << "\nDANH SACH NHAN VIEN\n";

    cout << left << setw(10) << "STT"
         << setw(30) << "Ho va Ten" << endl;

    for (int i = 0; i < n; i++) {
        dsnv[i].xuat(i + 1);
    }

    delete[] dsnv;

    return 0;
}
