#include<iostream>
using namespace std;
class A{
	public:
		int n1,n2;
		void getdata(){
			cout<<"Enter two no."<<endl;
			cin>>n1>>n2;
			
		}
};
class B:virtual public A{
	public:
		void sum(){
			cout<<"Sum of "<<n1<<" and "<<n2<<" = "<<n1+n2<<endl;
			}
};
class C:virtual public A{
	public:
		void sub(){
			cout<<"Subtraction of "<<n1<<" and "<<n2<<" = "<<n1-n2<<endl;
		}
};
class D:public B,public C{
	public:
		void product(){
			cout<<"Product of "<<n1<<" and "<<n2<<" = "<<n1*n2<<endl;
		}
};
main(){
	D d;
	d.getdata();
	d.sum();
	d.sub();
	d.product();
	
}
