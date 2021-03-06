#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define ARR_X 3
#define ARR_Y 4
#define ARR_SIZE 12

int siralimi(int arr[ARR_SIZE]);
void chandeSpace(int arr[ARR_SIZE],int sapceIndex);
void myPrint(int arr[ARR_SIZE]);

int main(){
	srand((unsigned)time(NULL));
	
	int dizi[ARR_SIZE]={4,5,8,6,7,1,3,0,2,9,10,11};	
	
	
	
	myPrint(dizi);
	int ChangeNumber=0;
	while(siralimi(dizi)<0){
	
	int i,spaceIndex=0;
	for(i=0;i<ARR_SIZE;i++){
		if(dizi[i]==0){
			spaceIndex=i;
		}
	}
	
		ChangeNumber++;
		printf("Change Number : %d\n",ChangeNumber);
		chandeSpace(dizi,spaceIndex);
		myPrint(dizi);
		//getchar();
	}
	
	
	return 0;
}

int siralimi(int arr[ARR_SIZE]){
	for(int k=0;k<ARR_SIZE-1;k++){
		if(arr[k]==0)
			continue;		
		if(arr[k]>arr[k+1]){
			return -1;
		}
	}
	return 1;
}

void chandeSpace(int arr[ARR_SIZE],int spaceIndex){	// Space Change Function

	int row = spaceIndex/ARR_X;	// Faind Row
	int column = spaceIndex%ARR_Y;	// Faind Column
	
	if(row==0 && column==0){	// Left Top Corner
		int tmp[2]={row*ARR_X+column+1,(row+1)*ARR_Y+column};	//bir yana yada bir alta kaydırılmasını sağlar
		int random = rand()%2;	// Random olarak 1 veya 2 sayılarından birini seçer 
		arr[spaceIndex]=arr[tmp[random]];
		arr[tmp[random]]=0;
		spaceIndex=tmp[random];	
	}
	
	if(row==0 && column==(ARR_Y-1)){	// Right Top Corner
		int tmp[2]={row*ARR_X+column-1,(row+1)*ARR_Y+column};	//bir yana yada bir alta kaydırılmasını sağlar
		int random = rand()%2;	// Random olarak 1 veya 2 sayılarından birini seçer 
		arr[spaceIndex]=arr[tmp[random]];
		arr[tmp[random]]=0;
		spaceIndex=tmp[random];	
	}
	
	if(row==(ARR_X-1) && column==0){	// Left Bottom Corner
		int tmp[2]={row*ARR_X+column+1,(row-1)*ARR_Y+column};	//bir yana yada bir alta kaydırılmasını sağlar
		int random = rand()%2;	// Random olarak 1 veya 2 sayılarından birini seçer 
		arr[spaceIndex]=arr[tmp[random]];
		arr[tmp[random]]=0;
		spaceIndex=tmp[random];	
	}
	
	if(row==(ARR_X-1) && column==(ARR_Y-1)){	// Right Bottom Corner
		int tmp[2]={row*ARR_X+column-1,(row-1)*ARR_Y+column};	//bir yana yada bir alta kaydırılmasını sağlar
		int random = rand()%2;	// Random olarak 1 veya 2 sayılarından birini seçer 
		arr[spaceIndex]=arr[tmp[random]];
		arr[tmp[random]]=0;
		spaceIndex=tmp[random];	
	}
	
	if(row==0 && !(column==0 || column==(ARR_Y-1))){	// Top Middle
		int tmp[3]={row*ARR_X+column+1,row*ARR_X+column-1,(row+1)*ARR_Y+column};	//bir yana yada bir alta kaydırılmasını sağlar
		int random = rand()%3;	// Random olarak 1 veya 2 sayılarından birini seçer 
		arr[spaceIndex]=arr[tmp[random]];
		arr[tmp[random]]=0;
		spaceIndex=tmp[random];	
	}
	
	if(!(row==0 || row==(ARR_X-1)) && column==0){	// Left Middle
		int tmp[3]={row*ARR_X+column+1,(row+1)*ARR_Y+column,(row-1)*ARR_Y+column};	//bir yana yada bir alta kaydırılmasını sağlar
		int random = rand()%3;	// Random olarak 1 veya 2 sayılarından birini seçer 
		arr[spaceIndex]=arr[tmp[random]];
		arr[tmp[random]]=0;
		spaceIndex=tmp[random];	
	}
	
	if(!(row==0 || row==ARR_X-1) && !(column==0 || column==1)){	// Right Middle
		int tmp[3]={row*ARR_X+column-1,(row+1)*ARR_Y+column,(row-1)*ARR_Y+column};	//bir yana yada bir alta kaydırılmasını sağlar
		int random = rand()%3;	// Random olarak 1 veya 2 sayılarından birini seçer 
		arr[spaceIndex]=arr[tmp[random]];
		arr[tmp[random]]=0;
		spaceIndex=tmp[random];	
	}
	
	if(row==(ARR_X-1) && !(column==0 || column==(ARR_Y-1))){	// Bottom Middle
		int tmp[3]={row*ARR_X+column-1,(row-1)*ARR_Y+column,row*ARR_X+column+1};	//bir yana yada bir alta kaydırılmasını sağlar
		int random = rand()%3;	// Random olarak 1 veya 2 sayılarından birini seçer 
		arr[spaceIndex]=arr[tmp[random]];
		arr[tmp[random]]=0;
		spaceIndex=tmp[random];	
	}
		
	if(!(row==(ARR_X-1) || row==0) && !(column==0 || column==(ARR_Y-1))){	// Middle
		int tmp[4]={row*ARR_X+column+1,row*ARR_X+column-1,(row-1)*ARR_Y+column,(row+1)*ARR_Y+column};	//bir yana yada bir alta kaydırılmasını sağlar
		int random = rand()%4;	// Random olarak 1 veya 2 sayılarından birini seçer 
		arr[spaceIndex]=arr[tmp[random]];
		arr[tmp[random]]=0;
		spaceIndex=tmp[random];	
	}	
}

void myPrint(int arr[ARR_SIZE]){	// Diziyi ekrana bastıran fonksiyon
	int j;
	for(j=0;j<ARR_SIZE;j++){
		if(j%ARR_Y==0){	// Diziyi 3*4'lük şeklinde ekrana bastırır
			printf("\n");
			printf("%d ,",arr[j]);
		}else{
			printf("%d ,",arr[j]);
		}
	}
	printf("\n");
}
