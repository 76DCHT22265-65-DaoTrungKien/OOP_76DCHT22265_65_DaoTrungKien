#include <iostream>
#include <string>
using namespace std;

class NhanVien {
private:
    string maNhanVien;
    string hoTen;
    string ngaySinh;
    string diaChi;

public:
    void nhap() {
        cout << "Nhap ma nhan vien: ";
        getline(cin, maNhanVien);

        cout << "Nhap ho ten: ";
        getline(cin, hoTen);

        cout << "Nhap ngay sinh: ";
        getline(cin, ngaySinh);

        cout << "Nhap dia chi: ";
        getline(cin, diaChi);
    }

    void xuat() {
        cout << "\n===== THONG TIN NHAN VIEN =====\n";
        cout << "Ma nhan vien: " << maNhanVien << endl;
        cout << "Ho ten      : " << hoTen << endl;
        cout << "Ngay sinh   : " << ngaySinh << endl;
        cout << "Dia chi     : " << diaChi << endl;
    }
};

int main() {
    NhanVien Minh;

    cout << "Nhap thong tin cho nhan vien Minh:\n";
    Minh.nhap();

    Minh.xuat();

    return 0;
}
