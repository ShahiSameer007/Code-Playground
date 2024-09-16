#include<iostream>
using namespace std;
class A{
	public:
		int a;
		void get_a(){
			cout<<"Enter value of a"<<endl;
			cin>>a;
			
		}
};
class B{
	public:
		int b;
		void get_b(){
			cout<<"Enter value of b"<<endl;
			cin>>b;
			
		}
};
class Sum:public A,public B{
	public:
		void sum(){
			cout<<"Sum = "<<a+b<<endl;
			
		}
};
main(){
	Sum S;
	S.get_a();
	S.get_b();
	S.sum();
}
