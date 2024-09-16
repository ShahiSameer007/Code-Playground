#include<stdio.h>
main(){
	int n,i,j,a[20],min,t;
	printf("Enter how many elements\n");
	scanf("%d",&n);
	printf("Enter elements in the array:\n");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<n-1;i++){
		min=i;
		for(j=i+1;j<n;j++){
			if(a[min]>a[j])
			min=j;
		}
		t=a[i];
		a[i]=a[min];
		a[min]=t;
	}
	printf("Sorted elements are:\n");
	for(i=0;i<n;i++)
	printf("%3d",a[i]);
	}
