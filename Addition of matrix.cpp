#include<stdio.h>
main(){
	int i,j,m1[3][3],m2[3][3],m3[3][3];
	printf("Enter elements of first array\n");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			scanf("%d",&m1[i][j]);
		}
	}
	printf("Enter elements of second array\n");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			scanf("%d",&m2[i][j]);
		}
	}
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			m3[i][j]=m1[i][j]+m2[i][j];
		}
	}
	printf("Sum of matrices:\n");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf("%5d",m3[i][j]);
			
		}
		printf("\n");
	}
	
}
