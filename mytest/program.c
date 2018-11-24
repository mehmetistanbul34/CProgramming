#include<stdio.h>
#include<stdlib.h>

int my_print(int arr[][3]);
int find_space(int arr[][3]);
int siralama(int arr[][3]);

#define row_x 3
#define column_y 3

int main(){
		//[satır][sütun]
	int dizi[3][3]={8,5,7,4,2,6,0,1,3};
	
	my_print(dizi);
	find_space(dizi);
		
}

int find_space(int arr[][3]){
	
	int space=arr[0][0];
	int row=0,column=0;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(arr[i][j]==0){	
				row=i;
				column=j;
				space=arr[row][column];
				printf("Bosluk %d. satırın %d. sütunundadır.\n",row,column);
			}
		}
	}
	
	while(siralama(arr)<0){
		printf("Sıralama : %d\n",siralama(arr));
		/*if(row==0 && column==0){
			int tmp[1][2]={row*row_x+1,(column+1)*column_y};
			int r1=rand()%2;
			int r2=rand()%2;
			arr[space] = arr[tmp[r1][r2]];
			arr[tmp[r1][r2]] = 0;
			space = tmp[r1][r2];
		}*/
	}
}

int my_print(int arr[][3]){
		
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
		printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
	
}

int siralama(int arr[][3]){
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++)
		if(arr[i][j]>arr[i+1][j+1])
			return -1;
			
	}
	
	return 1;
}
