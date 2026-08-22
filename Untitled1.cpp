#include<iostream>
#include<string>
#include<vector>

using namespace std;

class nhanvien {
private:
    string manv;
    string hoten;
    string ngaysinh;

public:
    void nhap() {
        cout << "Nhap ma nhan vien: ";
        getline(cin, manv);

        cout << "Nhap ho ten: ";
        getline(cin, hoten);

        cout << "Nhap ngay sinh: ";
        getline(cin, ngaysinh);
    }

    void xuat() {
        cout << "MA NV: " << manv << endl;
        cout << "HO TEN: " << hoten << endl;
        cout << "NGAY SINH: " << ngaysinh << endl;
    }
};

int main() {
    int i;

    // CACH 1: DUNG MANG TINH
    nhanvien dsnv[10];

    cout << "\nCACH 1: MANG TINH\n";

    for (i = 0; i < 10; i++) {
        cout << "\nNhap nhan vien thu " << i + 1 << endl;
        dsnv[i].nhap();
    }

    for (i = 0; i < 10; i++) {
        cout << "\nNhan vien thu " << i + 1 << endl;
        dsnv[i].xuat();
    }


    // CACH 2: DUNG NEW CAP PHAT MANG DONG
    nhanvien *dsnv2;
    dsnv2 = new nhanvien[10];

    cout << "\nCACH 2: MANG DONG\n";

    for (i = 0; i < 10; i++) {
        cout << "\nNhap nhan vien thu " << i + 1 << endl;
        dsnv2[i].nhap();
    }

    for (i = 0; i < 10; i++) {
        cout << "\nNhan vien thu " << i + 1 << endl;
        dsnv2[i].xuat();
    }

    delete[] dsnv2;


    // CACH 3: DUNG VECTOR
    vector<nhanvien> ds;

    cout << "\nCACH 3: VECTOR\n";

    for (i = 0; i < 10; i++) {
        nhanvien nv;

        cout << "\nNhap nhan vien thu " << i + 1 << endl;
        nv.nhap();

        ds.push_back(nv);
    }

    for (i = 0; i < ds.size(); i++) {
        cout << "\nNhan vien thu " << i + 1 << endl;
        ds[i].xuat();
    }


    // SO SANH
    cout << "\nSO SANH 3 CACH\n";

    cout << "\nMang tinh:";
    cout << "\n- Kich thuoc co dinh.";
    cout << "\n- De su dung.";

    cout << "\n\nMang dong:";
    cout << "\n- Kich thuoc cap phat khi chay.";
    cout << "\n- Phai dung new va delete[].";

    cout << "\n\nVector:";
    cout << "\n- Kich thuoc tu dong thay doi.";
    cout << "\n- Them phan tu bang push_back().";
    cout << "\n- De su dung va tu dong quan ly bo nho.";

    return 0;
}

