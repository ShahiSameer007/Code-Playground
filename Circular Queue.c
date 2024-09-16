#include<stdio.h>
int q[100],rear=-1,front=-1,max;
void inQ(void);void deQ(void);void display(void);
main(){
	int ch;
	printf("Enter queue size\t");
	scanf("%d",&max);
	do{
		printf("\n1.Insertion\n2.Deletion\n3.Display\n4.Exit\n");
		printf("Enter your choice\n");
		scanf("%d",&ch);
		switch(ch){
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
	}while(ch!=4);
}
void inQ(){
	int item;
	if(rear==max-1)
	 printf("\nQueue overflow\n");
	else{
		if(front==-1){
		front=0;
		 }
		printf("\nInsert item in the queue\t");
		scanf("%d",&item);
		rear++;
		q[rear]=item; 
	}
}
void deQ(){
	if(front==-1)
	 printf("\nQueue underflow\n");
	 else{
	 	printf("\nDeleted element is: %d\n",q[front]);
	 	front++;
	 	if(front==max){
	 	  front=rear=-1;
	 }
	 }
}
void display(){
	int i;
	if(front==-1){
	  printf("\nQueue is empty\n");
}
	else{
		printf("\nQueue is:\n");
		for(i=front; ;i++){
			printf(" %d ",q[i]);
			if(i==rear){
			  return ;
		}
		}
	}
}

