#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define ARR_X 3
#define ARR_Y 3
#define ARR_SIZE 9
#define FIRST_COLUMN 0
#define LAST_COLUMN (ARR_Y-1)
#define FIRST_ROW  0
#define LAST_ROW (ARR_X-1)

#define RANDOM_2 2
#define RANDOM_3 3
#define RANDOM_4 4

int siralimi(int arr[ARR_SIZE]);
void chandeSpace(int arr[ARR_SIZE],int sapceIndex); 
void myPrint(int arr[ARR_SIZE]);

int main(){
	srand((unsigned)time(NULL));
	
	int dizi[ARR_SIZE]={8,6,3,4,0,2,1,5,7};	
	
	int i,spaceIndex=0;
	for(i=0;i<ARR_SIZE;i++){
		if(dizi[i]==0){
			spaceIndex=i;
		}
	}
	
	myPrint(dizi);
	int ChangeNumber=0;
	while(siralimi(dizi)<0){  // BU SATIRI ACIKLA neden while icinde cagiriiyorsun.
		ChangeNumber++;
		printf("Change Number : %d\n",ChangeNumber);
		chandeSpace(dizi,spaceIndex);
		myPrint(dizi);
		getchar();
	}
	
	
	return 0;
}

int siralimi(int arr[9]){
	int k;
	for(k=0;k<ARR_SIZE-1;k++){
		if(arr[k]==0)    //????? : bu satirda ne yapiyorsun
			continue; //????? : bu satirda neden atliyorsun
		if(arr[k]>arr[k+1]){
			return -1;
		}
	}
	return 1;
}

void chandeSpace(int arr[ARR_SIZE],int spaceIndex){ 	// Space Change Function

	int row = spaceIndex/ARR_X;	// Faind Row
	int column = spaceIndex%ARR_X;	// Faind Column
	
	if(row==0 && column==FIRST_COLUMN){	// Left Top Corner
		int tmp[RANDOM_2]={row*ARR_X+column+1,(row+1)*ARR_X+column};	//bir yana yada bir alta kaydırılmasını sağlar
		int random = rand()% RANDOM_2;	// Random olarak 1 veya 2 sayılarından birini seçer 
		arr[spaceIndex]=arr[tmp[random]];
		arr[tmp[random]]=0;
		spaceIndex=tmp[random];	
	}
	
	if(row==0 && column==LAST_COLUMN){	// Right Top Corner
		int tmp[2]={row*ARR_X+column-1,(row+1)*ARR_X+column};	//bir yana yada bir alta kaydırılmasını sağlar ==> Bu yorum yalnis burda gidilebilecek yerler bir arr'ye ataniyor.
		int random = rand()%2;	// Random olarak 1 veya 2 sayılarından birini seçer 
		arr[spaceIndex]=arr[tmp[random]];  //?????  burda ne yapiyorsun?
		arr[tmp[random]]=0;
		spaceIndex=tmp[random];	//????? bu atamayi ne icin yaptin
	}
	
	if(row==LAST_ROW && column==FIRST_COLUMN){	// Left Bottom Corner
		int tmp[2]={row*ARR_X+column+1,(row-1)*ARR_X+column};	//bir yana yada bir alta kaydırılmasını sağlar
		int random = rand()%2;	// Random olarak 1 veya 2 sayılarından birini seçer 
		arr[spaceIndex]=arr[tmp[random]];
		arr[tmp[random]]=0;
		spaceIndex=tmp[random];	
	}
	
	if(row==LAST_ROW && column==(ARR_X-1)){// TTTTT row==(ARR_X-1) column==(ARR_Y-1) olacak diger yerleri de kontrol et	// Right Bottom Corner
		int tmp[2]={row*ARR_X+column-1,(row-1)*ARR_X+column};	//bir yana yada bir alta kaydırılmasını sağlar
		int random = rand()%2;	// Random olarak 1 veya 2 sayılarından birini seçer 
		arr[spaceIndex]=arr[tmp[random]];
		arr[tmp[random]]=0;
		spaceIndex=tmp[random];	
	}
	
	if(row==0 && !(column==FIRST_COLUMN || column==(ARR_X-1))){	// Top Middle
		int tmp[RANDOM_3]={row*ARR_X+column+1,row*ARR_X+column-1,(row+1)*ARR_X+column};	//bir yana yada bir alta kaydırılmasını sağlar
		int random = rand()% RANDOM_3;	// Random olarak 1 veya 2 sayılarından birini seçer 
		arr[spaceIndex]=arr[tmp[random]];
		arr[tmp[random]]=0;
		spaceIndex=tmp[random];	
	}
	
	if(!(row==0 || row==(ARR_Y-1)) && column==0){	// Left Middle
		int tmp[3]={row*ARR_X+column+1,(row+1)*ARR_X+column,(row-1)*ARR_X+column};	//bir yana yada bir alta kaydırılmasını sağlar
		int random = rand()%3;	// Random olarak 1 veya 2 sayılarından birini seçer 
		arr[spaceIndex]=arr[tmp[random]];
		arr[tmp[random]]=0;
		spaceIndex=tmp[random];	
	}
	
	if(row==1 && !(column==0 || column==1)){  // FFFFF BU SATIR HATALI	// Right Middle
		int tmp[3]={row*ARR_X+column-1,(row+1)*ARR_X+column,(row-1)*ARR_X+column};	//bir yana yada bir alta kaydırılmasını sağlar
		int random = rand()%3;	// Random olarak 1 veya 2 sayılarından birini seçer 
		arr[spaceIndex]=arr[tmp[random]];
		arr[tmp[random]]=0;
		spaceIndex=tmp[random];	
	}
	
	if(row==(ARR_Y-1) && !(column==0 || column==(ARR_X-1))){ // BU SATIRI ACIKLA	// Bottom Middle
		int tmp[3]={row*ARR_X+column-1,(row-1)*ARR_X+column,row*ARR_X+column+1};	//bir yana yada bir alta kaydırılmasını sağlar
		int random = rand()%3;	// Random olarak 1 veya 2 sayılarından birini seçer 
		arr[spaceIndex]=arr[tmp[random]];
		arr[tmp[random]]=0;
		spaceIndex=tmp[random];	
	}
		
	if(!(row==(ARR_Y-1) || row==0) && !(column==0 || column==(ARR_X-1))){ //???? bu satiri acikla	// Middle
		int tmp[4]={row*ARR_X+column+1,row*ARR_X+column-1,(row-1)*ARR_X+column,(row+1)*ARR_X+column};	//bir yana yada bir alta kaydırılmasını sağlar
		int random = rand()%4;	// Random olarak 1 veya 2 sayılarından birini seçer 
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
