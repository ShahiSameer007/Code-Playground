#include<iostream>
using namespace std;
class data{
	public:
	int l,b;
	void getdata(){
		cout<<"Enter length and breadth\n";
		cin>>l>>b;
		
	}	
	
};
class Perim:public data{
	public:
		void per(){
			cout<<"Perimeter = "<<2*(l+b)<<endl;
		}
};
class Area:public data{
	public:
		void area(){
			cout<<"Area = "<<l*b<<endl;
		}
};
main(){
	Perim P;
	P.getdata();
	P.per();
	Area A;
	A.getdata();
	A.area();
}
