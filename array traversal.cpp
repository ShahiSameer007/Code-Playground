#include<stdio.h>
void printArray(int *arr,int n){
	int i;
	printf("Array:\n");
	for(i=0;i<n;i++)
	printf(" %d ",arr[i]);
	printf("\n");
}
main(){
	int arr[]={2,-1,5,6,0,-3};
	int n=sizeof(arr)/sizeof(arr[0]);
	printArray(arr,n);
}
