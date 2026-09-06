#include<iostream>
#include<string>

using namespace std;

class sinhvien{
	private:
		string hoten;
		int namsinh;
		float diem[4];
	
	public:
		void nhap(){
			cout <<"Ho ten sinh vien:";
			getline(cin, hoten);
			
			cout << "Nam sinh sinh vien:";
			cin >> namsinh;
			
			for(int i = 0; i < 4; i++){
				cout <<"Nhap diem mon" << i + 1 << ":";
				cin >> diem[i];
			}
		}
		float tinhdiemtrungbinh(){
			float tong = 0;
			for(int i = 0; i < 4; i++){
				tong += diem[i];
			}
			return tong / 4;
		}
		void xuat(){
			cout << "Ho ten:" << hoten << endl;
			cout << "Nam sinh:" << namsinh << endl;
			
			for(int i = 0; i < 4; i++){
				cout <<"Diem mon" << i + 1 << ":" << diem[i] << endl;
			}
			cout << "Diem trung binh:" << tinhdiemtrungbinh() << endl;
		}
		bool thitotnghiep(){
			for(int i = 0; i  < 4; i++){
				if(diem[i] < 5){
					return false;
				}
			}
			if(tinhdiemtrungbinh() < 7){
				return true;
			}
			return false;
		
		}
	
};
int main(){
	int n;
	
	cout <<"Nhap so sinh vien:";
	cin >> n;
	
	sinhvien ds[100];
	
	for(int i = 0; i < n; i++){
		cout << "Sinh vien:" << i + 1 << endl;
		
		cin.ignore();
		ds[i].nhap();
	}
	cout << "Danh Sach Sinh Vien Phai Thi Tot Nghiep:" << endl;
	
	for(int i = 0; i < n; i++){
		if(ds[i].thitotnghiep()){
			cout <<"Sinh vien" << i + 1 << endl;
			ds[i].xuat();
		}
	}
	return 0;
}
