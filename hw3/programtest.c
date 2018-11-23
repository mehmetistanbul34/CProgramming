#include<stdio.h>
void myPrintArr(int arr[],boyut);

int main(){
	int i,j,row=0,column=0;
	int dizi[]={9,4,5,8,6,7,1,3,0,2};
	
	myPrintArr(dizi);
	
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
	}
	for(j=0;j<10;j++){
		if(dizi[j]==0){
			printf("Dizinin %d. satır %d kolonunun %d. Değeri Sıfırdır.\n",row,column,j);
		}
	}*/
}


void myPrintArr(int arr[],boyut){
	for(int i=0;i<arr.length;i++){
		printf("%d",arr[i]);
		if((i+1)%boyut==0)
			printf("\n");
		else
			printf(",");
	}
}
