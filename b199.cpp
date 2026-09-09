#include<iostream>

using namespace std;

class phanso{
	private:
		int tu;
		int mau;
	
	public:
		phanso(){
			tu = 0;
			mau = 1;
		}
		
		phanso(int t, int m){
			tu = t;
			mau = m;
		}
		
		~phanso(){
			
		}
		
		void nhap(){
			cout << "Nhap tu so: ";
			cin >> tu;
			
			do{
				cout << "Nhap mau so: ";
				cin >> mau;
				
				if(mau == 0){
					cout << "Mau phai khac 0\n";
				}
			}
			while(mau == 0);
		}
		
		void rutgon(){
			int a = tu;
			int b = mau;
			
			if(a < 0){
				a = -a;
			}
			
			if(b < 0){
				b = -b;
			}
			
			while(b != 0){
				int r = a % b;
				a = b;
				b = r;
			}
			
			if(a != 0){
				tu = tu / a;
				mau = mau / a;
			}
			
			if(mau < 0){
				tu = -tu;
				mau = -mau;
			}
		}
		
		void xuat(){
			rutgon();
			
			if(mau == 1){
				cout << tu;
			}
			else{
				cout << tu << "/" << mau;
			}
		}
		
		phanso cong(phanso b){
			phanso kq;
			
			kq.tu = tu * b.mau + b.tu * mau;
			kq.mau = mau * b.mau;
			
			kq.rutgon();
			
			return kq;
		}
		
		phanso tru(phanso b){
			phanso kq;
			
			kq.tu = tu * b.mau - b.tu * mau;
			kq.mau = mau * b.mau;
			
			kq.rutgon();
			
			return kq;
		}
		
		phanso nhan(phanso b){
			phanso kq;
			
			kq.tu = tu * b.tu;
			kq.mau = mau * b.mau;
			
			kq.rutgon();
			
			return kq;
		}
		
		phanso chia(phanso b){
			phanso kq;
			
			kq.tu = tu * b.mau;
			kq.mau = mau * b.tu;
			
			kq.rutgon();
			
			return kq;
		}
		
		bool tuBangKhong(){
			return tu == 0;
		}
};

int main(){
	phanso a, b, kq;
	
	cout << "Nhap phan so thu nhat:\n";
	a.nhap();
	
	cout << "\nNhap phan so thu hai:\n";
	b.nhap();
	
	cout << "\nPhan so thu nhat: ";
	a.xuat();
	
	cout << "\nPhan so thu hai: ";
	b.xuat();
	
	kq = a.cong(b);
	cout << "\nTong: ";
	kq.xuat();
	
	kq = a.tru(b);
	cout << "\nHieu: ";
	kq.xuat();
	
	kq = a.nhan(b);
	cout << "\nTich: ";
	kq.xuat();
	
	if(b.tuBangKhong()){
		cout << "\nKhong the chia cho 0";
	}
	else{
		kq = a.chia(b);
		cout << "\nThuong: ";
		kq.xuat();
	}
	
	return 0;
}


