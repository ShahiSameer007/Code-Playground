#include<iostream>
using namespace std;
class A{
	char name[20];
	void getdata(){
		cout<<"Enter name of student\t";
		cin>>name;
	}
public:
	friend void display(A);
};
void display(A a){
	a.getdata();
	cout<<"Name of student is:\t"<<a.name;
}
main(){
	A p;
	display(p);
}

