#include<stdio.h>
#include<stdlib.h>
void inQ(void);void deQ(void);void display(void);
int q[10],n,i,f,r;
int f=0,r=0;
main(){
	int op;
	printf("Enter the size of queue\n");
	scanf("%d",&n);
	do{
		printf("\n1.Insertion\n2.Deletion\n3.Display\n4.Exit");
		printf("\nEnter your choice\n");
		scanf("%d",&op);
		switch(op){
			case 1:
				inQ();
				break;
			case 2:
			    deQ();
				break;
			case 3:
			    display();
				break;			
		}
	}while(op!=4);
}
void inQ(){
	if(r>=n)
	printf("\nQueue overflow\n");
	else{
		r=r+1;
		printf("\nEnter the item to insert:\t");
		scanf("%d",&q[r]);
		if(f==0)
		f=1;
	}
}
void deQ(){
	if(f==0)
	printf("\nQueue underflow\n");
	else{
		printf("Deleted item is:\t%d",q[f]);
		f=f+1;
		if(f>r)
		{
		f=0;
		r=0;
		}}}
void display(){
	if(f==0)
	printf("\nQueue is empty\n");
	else{
		for(i=f;i<=r;i++)
		  printf(" %d ",q[i]);
	}
}		
