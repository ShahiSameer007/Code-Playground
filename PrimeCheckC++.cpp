#include<iostream>
using namespace std;
main(){
	int n,i;
	bool is_prime=true;
	
	cout<<"Enter a no."<<endl;
	cin>>n;
	if(n==0||n==1)
	{
		is_prime=false;
	}
	for(i=2;i<=n/2;i++){
		if(n%i==0)
		{is_prime=false;
		break;
		}
	}
	if(is_prime)
	cout<<n<<" is prime"<<endl;
	else
	cout<<n<<" is not prime"<<endl;
}
