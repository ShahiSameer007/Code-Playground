#include<stdio.h>
main(){
	int a[100],i,n;
	printf("Enter size of array:\n");
	scanf("%d",&n);
	printf("Enter %d elements in the array:\n",n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("\nElements in array are:\n");
	for(i=0;i<n;i++){
		printf(" %d ",a[i]);
	}
}

