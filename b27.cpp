#include<iostream>

using namespace std;

class ps1{
	protected:
	int ts;
	int ms;
	
	public:
		void nhap(){
			cout<<"Nhap tu so:";
			cin >> ts;
			
			do{
				cout<<"Nhap mau so:";
				cin >> ms;
			}
			while(ms == 0);
		}
		
		void toigian(){
			int a = ts;
			int b = ms;
			
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
			
			ts = ts / a;
			ms = ms/ a;
			
			if(ms < 0){
				ts = -ts;
				ms = -ms;
			}
		}
		void in(){
			toigian();
			
			if(ms == 1){
				cout<< ts;
			}
			else{
				cout<< ts << "/" << ms;
			}
		}
	
};
class ps2 : public ps1{
	public:
		
		ps2 operator = (ps2 p){
			ts = p.ts;
			ms = p.ms;
			return * this;
		}
		
		bool operator >(ps2 p){
			return ts * p.ms > p.ts * ms;
		}
};

int main(){
	ps2 a[10];
	int n;
	
	do{
		cout<<"Nhap so phan tu so:";
		cin >> n;
	}
	while(n < 1 || n > 10);
	
	for(int i = 0; i < n; i++){
		cout<<"Nhap phan so thu" << i + 1 <<"\n";
		a[i].nhap(); 
	}
	for(int i = 0; i < n - 1; i++){
		for(int j = i + 1; j < n; j++){
			if(a[j] > a[i]){
				ps2 tg;
				tg = a[i];
				a[i] = a[j];
				a[j] = tg;
			}
		}
	}
	cout<<"Danh sach phan so giam dan:\n";
	for(int i = 0; i < n; i++){
		a[i].in();
		cout<<"";
	}
	return 0;
}

