#include<iostream>
using namespace std;
class A{
	public:
		int x;
		void getx(){
			cout<<"Enter an element\t";
			cin>>x;
			
		}
		void operator !(){
			cout<<2*x<<endl;
		}
		
};
main(){
	A a;
	a.getx();
	!a;
}
