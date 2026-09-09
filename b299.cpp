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
		
		friend istream& operator>>(istream& in, phanso& a){
			cout << "Nhap tu so: ";
			in >> a.tu;
			
			do{
				cout << "Nhap mau so: ";
				in >> a.mau;
				
				if(a.mau == 0){
					cout << "Mau phai khac 0\n";
				}
			}
			while(a.mau == 0);
			
			return in;
		}
		
		friend ostream& operator<<(ostream& out, phanso a){
			a.rutgon();
			
			if(a.mau == 1){
				out << a.tu;
			}
			else{
				out << a.tu << "/" << a.mau;
			}
			
			return out;
		}
		
		phanso operator+(phanso b){
			phanso kq;
			
			kq.tu = tu * b.mau + b.tu * mau;
			kq.mau = mau * b.mau;
			
			kq.rutgon();
			
			return kq;
		}
		
		phanso operator-(phanso b){
			phanso kq;
			
			kq.tu = tu * b.mau - b.tu * mau;
			kq.mau = mau * b.mau;
			
			kq.rutgon();
			
			return kq;
		}
		
		phanso operator*(phanso b){
			phanso kq;
			
			kq.tu = tu * b.tu;
			kq.mau = mau * b.mau;
			
			kq.rutgon();
			
			return kq;
		}
		
		phanso operator/(phanso b){
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
	cin >> a;
	
	cout << "\nNhap phan so thu hai:\n";
	cin >> b;
	
	cout << "\nPhan so thu nhat: " << a;
	cout << "\nPhan so thu hai: " << b;
	
	kq = a + b;
	cout << "\nTong: " << kq;
	
	kq = a - b;
	cout << "\nHieu: " << kq;
	
	kq = a * b;
	cout << "\nTich: " << kq;
	
	if(!b.tuBangKhong()){
		kq = a / b;
		cout << "\nThuong: " << kq;
	}
	else{
		cout << "\nKhong the chia cho phan so co tu so bang 0";
	}
	
	return 0;
}
