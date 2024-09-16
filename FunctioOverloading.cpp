#include<iostream>
using namespace std;
class A{
	public:
		int a,b,c;
		void sum(int x,int y){
			a=x;
			b=y;
			cout<<"Sum of two no. = "<<a+b<<endl;
			
		}
		void sum(int x, int y, int z){
			a=x;
			b=y;
			c=z;
			cout<<"Sum of three no. = "<<a+b+c<<endl;
		}
};
main(){
	A obj;
	obj.sum(99,2);
	obj.sum(45,13,22);
}
