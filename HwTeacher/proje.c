#include<stdio.h>
#include<stdlib.h>

#define ARR_X 3
#define ARR_Y 3
#define ARR_LENGTH (ARR_X*ARR_Y)
#define FIRST_ROW 0
#define FIRST_COLUMN 0
#define LAST_ROW 2
#define LAST_COLUMN 2


void matris(int arr[][ARR_Y]);
void printMatris(int arr[][ARR_Y]);


int main(){

	int dizi[ARR_X][ARR_Y]={};
	
	matris(dizi);
	
}

void matris(int arr[][ARR_Y]){

	printf("-------------------------------------------------------------------------------\n\n");	
	printf("\n");
	
	int row=0;
	int column=0;
	int number=1;
	arr[row][column]=1;
	number++;
	
	while(number<=ARR_LENGTH){
		
		printf("Adım :%2d\n\n",number-1);
		printMatris(arr);
		
		int back_row=row;
		int back_column=column;
		
		column++;
		if(column>LAST_COLUMN){
			column=FIRST_COLUMN;
			row--;
			if(row<FIRST_ROW){
				row=LAST_ROW;
				if(arr[row][column]==0){
					arr[row][column]=number;
				}else{
					arr[back_row+1][back_column]=number;
					row=back_row+1;
					column=back_column;
				}
			}else{
				if(arr[row][column]==0){
					arr[row][column]=number;
				}else{
					arr[back_row+1][back_column]=number;
					row=back_row+1;
					column=back_column;
				}
			}
		}else{
			row--;
			if(row<FIRST_ROW){
				row=LAST_ROW;
				if(arr[row][column]==0){
					arr[row][column]=number;
				}else{
					arr[back_row+1][back_column]=number;
					row=back_row+1;
					column=back_column;
				}
			}else{
				if(arr[row][column]==0){
					arr[row][column]=number;
				}else{
					arr[back_row+1][back_column]=number;
					row=back_row+1;
					column=back_column;
				}
			}
		
		}
	   number++;	
	}
	 printf("Adım :%3d\n\n",number-1);
	 printMatris(arr);
}

void printMatris(int arr[][ARR_Y]){

	int i,j;
	for(i=0;i<ARR_X;i++){
		for(j=0;j<ARR_Y;j++){
			printf("%4d",arr[i][j]);
		}
		printf("\n");
	}printf("\n\n");
	printf("-------------------------------------------------------------------------------\n\n");

}
