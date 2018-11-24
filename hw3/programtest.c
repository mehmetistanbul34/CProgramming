#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ARR_X  3
#define ARR_Y  6
#define ARR_SIZE 18

int validation(int arr[]);
void myPrintArr(int arr[]);

int main(){
	srand((unsigned)time(NULL));
	int dizi[]={4,5,8,6,7,1,3,0,2,9,10,11,12,13,14,15,16,17};
	printf("size_t sum : %d, item  : %d \n",(int)sizeof(dizi),(int)sizeof(dizi[0]));
	myPrintArr(dizi);
	for(int index = 0;index<100;index++){
		int aa1= rand()%2;
		int aa2 = rand()%3;
		int aa3 = rand()%4;
		printf("aa1 : %d, aa2 : %d , aa3 : %d  \n",aa1,aa2,aa3);
	}
	/*for(i=0;i<10;i++){
		if(i<=2){
			printf("%d ",dizi[i]);
		}else if(i>2 && printf("\n"); i<=5){
			row++;
			printf("%d ",dizi[i]);
		}else if(i>5 && i<=8) printf("\n");{
			row++;
			printf("%d ",dizi[i]);
		}
	column++;
	}*/
	
	int space_index=-1;
	
	for(int j=0;j<10;j++){
		if(dizi[j]==0){
			space_index = j;
		}
	}
	
	int changedNumber = 0;
	
	while(validation(dizi)<0){
		changedNumber++;
		printf("ccc : %d\n",changedNumber);
		myPrintArr(dizi);
		int row = space_index/ARR_X;
		int column = space_index%ARR_X;
		if(row==0 && column==0){   //LEFT TOP
			int tmp[2] = { row*ARR_X+column+1, (row+1)*ARR_X+column};
			int my_random = rand()%2;
			dizi[space_index] = dizi[tmp[my_random]];
			dizi[tmp[my_random]] = 0;
			space_index = tmp[my_random];
		}
		
		if(row==0 && column==(ARR_X-1)){  // RIGHT TOP
			int tmp[2] = { row*ARR_X+column-1, (row+1)*ARR_X+column};
			int my_random = rand()%2;
			dizi[space_index] = dizi[tmp[my_random]];
			dizi[tmp[my_random]] = 0;
			space_index = tmp[my_random];
		}
		
		if(row==(ARR_Y-1) && column==0){  // LEFT BOTTOM
			int tmp[2] = { row*ARR_X+column+1, (row-1)*ARR_X+column};
			int my_random = rand()%2;
			dizi[space_index] = dizi[tmp[my_random]];
			dizi[tmp[my_random]] = 0;
			space_index = tmp[my_random];
		}
		
		if(row==(ARR_Y-1) && column==(ARR_X-1)){  // RIGHT BOTTOM
			int tmp[2] = { row*ARR_X+column-1, (row-1)*ARR_X+column};
			int my_random = rand()%2;
			dizi[space_index] = dizi[tmp[my_random]];
			dizi[tmp[my_random]] = 0;
			space_index = tmp[my_random];
		}
		
		if(row==0 && !(column==0 || column==(ARR_X-1))){   //MIDDLE TOP
			int tmp[3] = { row*ARR_X+column+1,row*ARR_X+column-1, (row+1)*ARR_X+column};
			int my_random = rand()%3;
			dizi[space_index] = dizi[tmp[my_random]];
			dizi[tmp[my_random]] = 0;
			space_index = tmp[my_random];
		}
		
		if(!(row==0 || row==(ARR_Y-1)) && column==(ARR_X-1)){  // RIGHT MIDDLE
			int tmp[3] = { row*ARR_X+column-1, (row+1)*ARR_X+column,(row-1)*ARR_X+column};
			int my_random = rand()%3;
			dizi[space_index] = dizi[tmp[my_random]];
			dizi[tmp[my_random]] = 0;
			space_index = tmp[my_random];
		}
		
		if(!(row==0 || row==(ARR_Y-1)) && column==0){  // LEFT MIDDLE
			int tmp[3] = { row*ARR_X+column+1, (row+1)*ARR_X+column,(row-1)*ARR_X+column};
			int my_random = rand()%3;
			dizi[space_index] = dizi[tmp[my_random]];
			dizi[tmp[my_random]] = 0;
			space_index = tmp[my_random];
		}
		
		if(row==(ARR_Y-1) && !(column==0 || column==(ARR_X-1))){  // MIDDLE BOTTOM
			int tmp[3] = { row*ARR_X+column+1,row*ARR_X+column-1, (row-1)*ARR_X+column};
			int my_random = rand()%3;
			dizi[space_index] = dizi[tmp[my_random]];
			dizi[tmp[my_random]] = 0;
			space_index = tmp[my_random];
		}
		
		if(!(row==0 || row==(ARR_Y-1)) && !(column == (ARR_X-1) || column==0)){  // MIDDLE BOTTOM
			int tmp[4] = { row*ARR_X+column+1,row*ARR_X+column-1, (row-1)*ARR_X+column,(row+1)*ARR_X+column};
			int my_random = rand()%4;
			dizi[space_index] = dizi[tmp[my_random]];
			dizi[tmp[my_random]] = 0;
			space_index = tmp[my_random];
		}
		
		//getchar();
	}
	printf("Sonuc hesaplandı : %d\n",changedNumber);
	myPrintArr(dizi);
	printf("\n\n\n");
	
	return 0;
}

int validation(int arr[]){
	for(int i=0;i<ARR_SIZE-1;i++){
		if(arr[i] ==0)
			continue;
		if(arr[i]>arr[i+1])
			return -1;
			
	}
	
	return 1;
}
			

void myPrintArr(int arr[]){
	for( int i=0; i<ARR_SIZE; i++ ){
		printf("%d",arr[i]);
		if((i+1)%ARR_X==0)
			printf("\n");
		else
			printf(",");
	}
}
