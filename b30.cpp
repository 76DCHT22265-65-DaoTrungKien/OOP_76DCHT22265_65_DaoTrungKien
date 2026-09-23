#include<iostream>
#include<cmath>

using namespace std;

class SP1{
    protected:
        float pt;
        float pa;

    public:
        SP1(){
            pt=0;
            pa=0;
        }

        void nhap(){
            cout<<"Nhap phan thuc: ";
            cin>>pt;

            cout<<"Nhap phan ao: ";
            cin>>pa;
        }

        void in(){
            cout<<pt;

            if(pa>=0){
                cout<<"+"<<pa<<"i";
            }
            else{
                cout<<pa<<"i";
            }
        }

        float modul(){
            return sqrt(pt*pt + pa*pa);
        }
};

class SP2:public SP1{
    public:
        SP2 operator=(SP2 p){
            pt=p.pt;
            pa=p.pa;
            return *this;
        }

        bool operator>(SP2 p){
            return modul()>p.modul();
        }
};

int main(){
    SP2 a,b,c;

    cout<<"Nhap so phuc a:\n";
    a.nhap();

    cout<<"Nhap so phuc b:\n";
    b.nhap();

    cout<<"So phuc a: ";
    a.in();
    cout<<"Modul a: "<<a.modul();

    cout<<"\nSo phuc b: ";
    b.in();
    cout<<"Modul b: "<<b.modul();

    c=a;

    cout<<"\nSo phuc c sau khi c=a: ";
    c.in();

    if(a>b)
        cout<<"\na co modul lon hon b";
    else
        cout<<"\na khong co modul lon hon b";

    return 0;
}
