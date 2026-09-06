#include<iostream>
#include<string>

using namespace std;

class sinhvien{
	private:
		string hoten;
		int namsinh;
		float diem[5];
		
	public:
		void nhap(){
			cout << "Nhap ho ten:";
			getline(cin, hoten);
			
			cout <<"Nhap nam sinh:";
			cin >> namsinh;
			
			for(int i = 0; i < 5; i++){
				cout << "Nhap diem mon:" << i + 1 << "";
				cin >> diem[i];
			}
		}
		void xuat(){
			cout <<"Ho ten:" << hoten << endl;
			cout << "Nam sinh:" << namsinh << endl;
			
			for(int i = 0; i < 5; i++){
				cout <<"Diem mon" << i + 1 <<"" << diem[i] << endl;
			}
			cout <<"Diem trung binh:" << diemtb() << endl; 
		}
		float diemtb(){
			float tong = 0;
			for(int i = 0; i < 5; i++){
				tong += diem[i];
			}
			return tong / 5;
		}
		void thilai(){
			
			for( int i = 0; i < 5; i++){
				if(diem[i] < 5){
					cout << "Mon:" << i + 1 << "diem:" << diem[i] << endl; 
				}
			}
		}
};
  int main(){
  	int n;
  	
  	cout <<"Nhap so sinh vien:";
  	cin >> n;
  	
  	sinhvien ds[100];
  	
  	for(int i = 0; i < n; i++){
  		cout << " SINH VIEN:" << i + 1 << "" << endl;
  		
  		cin .ignore();
  		
  		ds[i].nhap();
	  }
	  
	  cout <<"DANH SACH SINH VIEN:";
	  
	  for(int i = 0; i< n; i++){
	  	cout << "Sinh vien" << i + 1 << "" << endl;
	  	ds[i].xuat();
	  }
	  cout <<"CAC MON PHAI THI LAI:";
	  for(int i = 0; i < n; i++){
	  	cout << "Sinh vien" << i+ 1 << "" << endl;
	  	ds[i].thilai();
	  }
	  return 0;
  }
