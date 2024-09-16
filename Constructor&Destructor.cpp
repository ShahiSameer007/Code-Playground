#include<iostream>
using namespace std;
class example{
	private:
		int n=0;
	public:
		example(){
			cout<<"Constructor is called\n";
			n=n+2;
		}
		~example(){
			cout<<"\nDestructor is called";
			n=n-1;
		}
		void display(){
			cout<<"value of n="<<n;
			
		}};
	main(){
		example Ex;
		Ex.display();
	}		
