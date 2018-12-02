#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define ARR_X 3
#define ARR_Y 3
#define ARR_SIZE 9

int siralimi(int arr[9]);
void chandeSpace(int arr[9],int sapceIndex);
void myPrint(int arr[9]);

int main(){
	srand((unsigned)time(NULL));
	
	int dizi[9]={4,5,8,6,7,1,3,0,2};	
	
	int i,spaceIndex=0;
	for(i=0;i<ARR_SIZE;i++){
		if(dizi[i]==0){
			spaceIndex=i;
		}
	}
	
	myPrint(dizi);
	int ChangeNumber=0;
	while(siralimi(dizi)<0){
	ChangeNumber++;
	printf("Change Number : %d\n",ChangeNumber);
	chandeSpace(dizi,spaceIndex);
	myPrint(dizi);
	}
	
	
	return 0;
}

int siralimi(int arr[9]){
	for(int k=0;k<ARR_SIZE-1;k++){
		if(arr[k]==0)
			continue;		
		if(arr[k]>arr[k+1]){
			return -1;
		}
	}
	return 1;
}

void chandeSpace(int arr[9],int spaceIndex){	// Space Change Function

	int row = spaceIndex/ARR_X;	// Faind Row
	int column = spaceIndex%ARR_X;	// Faind Column
	
	if(row==0 && column==0){	// Left Top Corner
		int tmp[2]={row*ARR_X+column+1,(row+1)*ARR_X+column};	//bir yana yada bir alta kaydırılmasını sağlar
		int random = rand()%2;	// Random olarak 1 veya 2 sayılarından birini seçer 
		arr[spaceIndex]=arr[tmp[random]];
		arr[tmp[random]]=0;
		spaceIndex=tmp[random];	
	}
	
	if(row==0 && column==ARR_X-1){	// Right Top Corner
		int tmp[2]={row*ARR_X+column-1,(row+1)*ARR_X+column};	//bir yana yada bir alta kaydırılmasını sağlar
		int random = rand()%2;	// Random olarak 1 veya 2 sayılarından birini seçer 
		arr[spaceIndex]=arr[tmp[random]];
		arr[tmp[random]]=0;
		spaceIndex=tmp[random];	
	}

}

void myPrint(int arr[9]){	// Diziyi ekrana bastıran fonksiyon
	int j;
	for(j=0;j<ARR_SIZE;j++){
		if(j%3==0){	// Diziyi 3*3'lük şeklinde ekrana bastırır
			printf("\n");
			printf("%d ,",arr[j]);
		}else{
			printf("%d ,",arr[j]);
		}
	}
	printf("\n");
}
