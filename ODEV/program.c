#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ARR_X 3
#define ARR_Y 3
#define ARR_SIZE 9

int siralimi(int arr[9]);
void changeSpace(int arr[9],int spaceIndex);
void myPrint(int arr[9]);


int main(){

	
	srand((unsigned)time(NULL));

	int k,spaceIndex=0;
	int dizi[9]={8,0,6,5,4,3,2,1,7 };
	
	for(k=0;k<ARR_SIZE;k++){
		if(dizi[k]==0){
			spaceIndex=k;
		}
	}
	int changeNumber=0;
	while(siralimi(dizi)<0){
		changeNumber++;
		printf("Change Number :%d\n",changeNumber);
		changeSpace(dizi,spaceIndex);
		myPrint(dizi);
	}
	
}

void changeSpace(int arr[9],int spaceIndex){

	int row=spaceIndex/ARR_X;
	int column=spaceIndex%ARR_Y;
	
	printf("SpaceIndex  :%d\tRow : %d\tColumn : %d\n",spaceIndex,row,column);
	if(row==0 && column==0){	// Left Top Corner
		int tmp[2] = {  row*ARR_X+column+1, (row+1)*ARR_X+column};
			int random = rand()%2;	//random olarak 0 yada 1 sayılarından birini seçer
			arr[spaceIndex] = arr[tmp[random]];
			arr[tmp[random]] = 0;
			spaceIndex = tmp[random];
	}
	
	if(row==0 && column==(ARR_X-1)){	// Right Top Corner
		int tmp[2] = {  row*ARR_X+column-1, (row+1)*ARR_X+column};
			int random = rand()%2;	//random olarak 0 yada 1 sayılarından birini seçer
			arr[spaceIndex] = arr[tmp[random]];
			arr[tmp[random]] = 0;
			spaceIndex = tmp[random];
	}
	
	if(row==(ARR_Y-1) && column==0){	// Left Bottom Corner
		int tmp[2] = {  row*ARR_X+column-1, (row+1)*ARR_X+column};
			int random = rand()%2;	//random olarak 0 yada 1 sayılarından birini seçer
			arr[spaceIndex] = arr[tmp[random]];
			arr[tmp[random]] = 0;
			spaceIndex = tmp[random];
	}
	
	if(row==(ARR_Y-1) && column==(ARR_X-1)){	// Right Bottom Corner
		int tmp[2] = { row*ARR_X+column-1, (row-1)*ARR_X+column};
			int random = rand()%2;	//random olarak 0 yada 1 sayılarından birini seçer
			arr[spaceIndex] = arr[tmp[random]];
			arr[tmp[random]] = 0;
			spaceIndex = tmp[random];
	}
	
	
	if(row==0 && column==1){	// Top Midle
		int tmp[3] = { row*ARR_X+column+1,(row-1)*ARR_X+column, (row+1)*ARR_X+column};
			int random = rand()%3;	//random olarak 0 , 1 veya 2 sayılarından birini seçer
			arr[spaceIndex] = arr[tmp[random]];
			arr[tmp[random]] = 0;
			spaceIndex = tmp[random];
	}
	
	if(row==1 && column==0){	// Left Midle
		int tmp[3] = {  row*ARR_X+column+1,row*ARR_X+column-1, (row+1)*ARR_X+column};
			int random = rand()%3;	//random olarak 0 , 1 veya 2 sayılarından birini seçer
			arr[spaceIndex] = arr[tmp[random]];
			arr[tmp[random]] = 0;
			spaceIndex = tmp[random];
	}
	
	if(row==1 && column==(ARR_X-1)){	// Right Midle
		int tmp[3] = {  row*ARR_X+column-1,row*ARR_X+column+1, (row-1)*ARR_X+column};
			int random = rand()%3;	//random olarak 0 , 1 veya 2 sayılarından birini seçer
			arr[spaceIndex] = arr[tmp[random]];
			arr[tmp[random]] = 0;
			spaceIndex = tmp[random];
	}
	
	if(row==(ARR_Y-1) && column==1){	// Bottom Midle
		int tmp[3] = {  row*ARR_X+column-1,(row-1)*ARR_X+column, (row+1)*ARR_X+column};
			int random = rand()%3;	//random olarak 0 , 1 veya 2 sayılarından birini seçer
			arr[spaceIndex] = arr[tmp[random]];
			arr[tmp[random]] = 0;
			spaceIndex = tmp[random];
	}
	
	if(row==1 && column==1){	// Midle
		int tmp[4] = {  row*ARR_X+column-1,row*ARR_X+column+1,(row-1)*ARR_X+column, (row+1)*ARR_X+column};
			int random = rand()%4;	//random olarak 0 , 1 , 2 veya 3 sayılarından birini seçer
			arr[spaceIndex] = arr[tmp[random]];
			arr[tmp[random]] = 0;
			spaceIndex = tmp[random];
	}
}

int siralimi(int arr[9]){	//Bu fonksiyon dizinin sıralı olup olmadığını kontrol eder
	int a;
	for(a=0;a<ARR_SIZE-1;a++){
		if(arr[a]>arr[a+1])
		return -1;	// dizinin sıralı değil ise -1 return eder
	}
	
	return 1;	// dizinin sıralı ise 1 return eder
}

void myPrint(int arr[9]){	// Bu fonksiyon diziyi ekrana bastırır
	int i;
	for(i=0;i<ARR_SIZE;i++){
		if(i%3!=0 || i==0){	// Bu satır diziyi 3*3 şeklinde ekrana basar
			printf("%d ",arr[i]);
		}
		else{
			printf("\n");
			printf("%d ",arr[i]);
		}
	}
	printf("\n");
}
