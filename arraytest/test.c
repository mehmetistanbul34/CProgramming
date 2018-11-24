#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void myPrint(int dizi[][6][2]){

	for(int i=0;i<2;i++){
		printf("BeginY");
		for(int j=0;j<6;j++){
			printf("BeginX");
			for(int n=0;n<2;n++)
				printf(" %d, ",dizi[i][j][n]);
			printf("EndX");
		}
		printf("EndY");
	}
	
	printf("\n");
	
}


int main(){

	int arr[2][6][2];
	
	srand((unsigned)time(NULL));
	
	for(int i=0;i<2;i++){
		for(int j=0;j<6;j++)
			for(int n=0;n<2;n++)
				arr[i][j][n] = rand()%100;
	}
	
	myPrint(arr);

	return 0;
}



