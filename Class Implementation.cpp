#include<iostream>
using namespace std;
class info{
    private:
    	int price;
    	char name[20];
    public:
	   void get_data(){
	   	cout<<"Enter the name of product\n";
	   	cin>>name;
	   	cout<<"Enter the price of product\n";
	   	cin>>price;
	   	}
		void display(){
			if(price>10000)
			cout<<"Price of "<<name<<" is too high ("<<price<<")"<<endl;
			else
			cout<<"Price of "<<name<<" is affordable ("<<price<<")"<<endl;
		}   	
		};	
	main(){
		info I;
		I.get_data();
		I.display();
	}	

