
#include<iostream>
using namespace std;

class SP1{
    protected:
        float thuc;
        float ao;

    public:
        SP1(){
            thuc = 0;
            ao = 0;
        }

        SP1(float t, float a){
            thuc = t;
            ao = a;
        }

        void nhap(){
            cout<<"Nhap phan thuc: ";
            cin>>thuc;

            cout<<"Nhap phan ao: ";
            cin>>ao;
        }

        void in(){
            cout<<thuc;

            if(ao >= 0)
                cout<<" + "<<ao<<"i";
            else
                cout<<" - "<<-ao<<"i";
        }

        float module(){
            return thuc * thuc + ao * ao;
        }
};

class SP2 : public SP1{
    public:
        SP2() : SP1(){
        }

        SP2(float t, float a) : SP1(t, a){
        }

        SP2 operator=(SP2 x){
            thuc = x.thuc;
            ao = x.ao;
            return *this;
        }

        bool operator>(SP2 x){
            return module() > x.module();
        }
};

int main(){
    SP2 a[10];
    int n;

    cout<<"Nhap so luong so phuc: ";
    cin>>n;

    if(n > 10)
        n = 10;

    for(int i=0; i<n; i++){
        cout<<"\nNhap so phuc thu "<<i+1<<":\n";
        a[i].nhap();
    }

    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(a[j] > a[i]){
                SP2 tam;
                tam = a[i];
                a[i] = a[j];
                a[j] = tam;
            }
        }
    }

    cout<<"Danh sach sau khi sap xep giam dan theo module:";

    for(int i=0; i<n; i++){
        a[i].in();
        cout<<"  Module^2 = "<<a[i].module()<<endl;
    }

    return 0;
}

