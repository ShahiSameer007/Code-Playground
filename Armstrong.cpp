#include<iostream>
using namespace std;
main(){
	int n,temp,r,sum=0;
	cout<<"Enter the number\t";
	cin>>n;
	temp=n;
	while(n>0){
		r=n%10;
		sum=sum+(r*r*r);
		n=n/10;
		}
	if(sum==temp)
	  cout<<"No. is Armstrong"<<endl;
	  else
	  cout<<"No. is not Armstrong"<<endl;
	  	
}
