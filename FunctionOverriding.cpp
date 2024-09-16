#include<iostream>
using namespace std;
class A{
	public:
	virtual	void display(){
			cout<<"Base class\n";
			
		}
};
class B:public A{
	public:
		void display(){
			cout<<"Derived class\n";
			
		}
};
void main(){
	B b;
	b.display();
	A *a;
	a->display();
}
