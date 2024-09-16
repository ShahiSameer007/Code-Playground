#include<iostream>
using namespace std;
class A{
	public:
		int l,b;
		void getdata()
		{
			cout<<"Enter length";
			cin>>l;
			cout<<"Enter breadth";
			cin>>b;
			
		}
};
class B:public A{
	public:
		void Area(){
			cout<<"Area of quadrilateral= "<<l*b<<endl;
		}
};
main(){
B obj;
obj.getdata();
obj.Area();

}
