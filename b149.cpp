#include <iostream>
#include <string>

using namespace std;

class nguoi {
protected:
    string hoten;
    int namsinh;

public:
    nguoi() {
        hoten = "";
        namsinh = 0;
    }

    nguoi(string hoten, int namsinh) {
        this->hoten = hoten;
        this->namsinh = namsinh;
    }

    void nhap() {
        cout << "Nhap ho ten: ";
        getline(cin >> ws, hoten);

        cout << "Nhap nam sinh: ";
        cin >> namsinh;
    }

    void xuat() {
        cout << "Ho ten: " << hoten;
        cout << " | Nam sinh: " << namsinh;
    }
};

class sinhvien : public nguoi {
private:
    string msv;
    float dtb;

public:
    sinhvien() : nguoi() {
        msv = "";
        dtb = 0;
    }

    sinhvien(string hoten, int namsinh, string msv, float dtb)
        : nguoi(hoten, namsinh) {
        this->msv = msv;
        this->dtb = dtb;
    }

    float getDTB() {
        return dtb;
    }

    void nhap() {
        nguoi::nhap();

        cout << "Nhap ma sinh vien: ";
        getline(cin >> ws, msv);

        cout << "Nhap diem trung binh: ";
        cin >> dtb;
    }

    void xuat() {
        nguoi::xuat();
        cout << " | Ma SV: " << msv;
        cout << " | Diem TB: " << dtb << endl;
    }
};

void sapxep(sinhvien ds[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ds[i].getDTB() < ds[j].getDTB()) {
                sinhvien temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }
}

int main() {
    cout << "DEMO HAM TAO CO DOI" << endl;

    sinhvien sv1("Nguyen Van A", 2003, "SV001", 8.5);

    cout << "Thong tin sinh vien khoi tao bang ham tao co doi:" << endl;
    sv1.xuat();

    cout << "" << endl;

    int n;
    cout << "\nNhap so luong sinh vien: ";
    cin >> n;

    sinhvien ds[100];

    cout << "\nNHAP DANH SACH SINH VIEN" << endl;

    for (int i = 0; i < n; i++) {
        cout << "\nNhap sinh vien thu " << i + 1 << ":" << endl;
        ds[i].nhap();
    }

    sapxep(ds, n);

    cout << "\nDANH SACH SINH VIEN GIAM DAN THEO DIEM TRUNG BINH" << endl;

    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". ";
        ds[i].xuat();
    }

    return 0;
}
