#include<stdio.h>

#define ARR_X 3
#define ARR_Y 3
#define ARR_SIZE 9

int siralimi(int arr[9]);
void changeSpace(int arr[9],int spaceIndex);
void myPrint(int arr[9]);


int main(){
	int k,spaceIndex=0;
	int dizi[9]={8,7,6,5,4,3,2,1,0};
	
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
	
	printf("Row : %d\tColumn : %d\n",row,column);
	if(row==0 && column==0){
		int tmp[2] = { row+1,column+1};
			int random = rand()%2;
			arr[spaceIndex] = arr[tmp[random]];
			arr[tmp[random]] = 0;
			spaceIndex = tmp[random];
	}
	
	if(row==0 && column==2){
		int tmp[2] = { row+1,column-1};
			int random = rand()%2;
			arr[spaceIndex] = arr[tmp[random]];
			arr[tmp[random]] = 0;
			spaceIndex = tmp[random];
	}
	
	if(row==2 && column==0){
		int tmp[2] = { row-1,column+1};
			int random = rand()%2;
			arr[spaceIndex] = arr[tmp[random]];
			arr[tmp[random]] = 0;
			spaceIndex = tmp[random];
	}
	
	if(row==2 && column==2){
		int tmp[2] = { row-1,column-1};
			int random = rand()%2;
			arr[spaceIndex] = arr[tmp[random]];
			arr[tmp[random]] = 0;
			spaceIndex = tmp[random];
	}
	
	
	if(row==0 && column==1){
		int tmp[3] = { row+1,column+1,column-1};
			int random = rand()%3;
			arr[spaceIndex] = arr[tmp[random]];
			arr[tmp[random]] = 0;
			spaceIndex = tmp[random];
	}
	
	if(row==1 && column==0){
		int tmp[3] = { row-1,row+1,column+1};
			int random = rand()%3;
			arr[spaceIndex] = arr[tmp[random]];
			arr[tmp[random]] = 0;
			spaceIndex = tmp[random];
	}
	
	if(row==1 && column==2){
		int tmp[3] = { row+1,row-1,column-1};
			int random = rand()%3;
			arr[spaceIndex] = arr[tmp[random]];
			arr[tmp[random]] = 0;
			spaceIndex = tmp[random];
	}
	
	if(row==2 && column==1){
		int tmp[3] = { row+1,column-1,column+1};
			int random = rand()%3;
			arr[spaceIndex] = arr[tmp[random]];
			arr[tmp[random]] = 0;
			spaceIndex = tmp[random];
	}
	if(row==1 && column==1){
		int tmp[4] = { row-1,row+1,column-1,column+1};
			int random = rand()%4;
			arr[spaceIndex] = arr[tmp[random]];
			arr[tmp[random]] = 0;
			spaceIndex = tmp[random];
	}
}

int siralimi(int arr[9]){
	int a;
	for(a=0;a<ARR_SIZE-1;a++){
		if(arr[a]>arr[a+1])
		return -1;
	}
	
	return 1;
}

void myPrint(int arr[9]){
	int i;
	for(i=0;i<ARR_SIZE;i++){
		if(i%3!=0 || i==0){
			printf("%d ",arr[i]);
		}
		else{
			printf("\n");
			printf("%d ",arr[i]);
		}
	}
	printf("\n");
}
