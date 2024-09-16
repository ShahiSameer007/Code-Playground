#include<stdio.h>
#include<process.h>

int ch,max,item,top=-1,s[20];
void menu(void);void push(int);void pop(void);void display(void);
main(){
	printf("Enter max size\t");
	scanf("%d",&max);
	menu();
	}
void menu(){
	printf("\n1.PUSH\n2.POP\n3.EXIT\n");
	printf("Enter your choice ");

	scanf("%d",&ch);
	switch(ch){
		case 1:
			printf("Enter the item\t");
			scanf("%d",&item);
			push(item);
			menu();
			break;
		case 2:
		    pop();
			menu();
			break;
		case 3:
			display();
		    exit(0);
			}}
void push(int item){
	if( top >= max-1){
	printf("Stack overflow\n");
	}
	else{
		top++;
		s[top]=item;
		}
	display();
	}		    
void pop(){
	if(top<=-1){
		printf("Stack underflow\n");		
	}
	else{printf("Deleted item is:%d\n",s[top]);
		top--;
	}
		
}
void display(){
	int i;
	printf("top-->");
	for(i=top;i>=0;i--)
	printf(" %d\n",s[i]);
	
}
