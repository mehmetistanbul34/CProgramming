#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void minFind(int arr[]);
void maxFind(int arr[]);
void ortGet(int arr[]);
void siralama(int arr[]);
void terstenYaz(int arr2[]);

#define ARR_LENGTH 15
#define LENGTH2 13


int main(){

	int dizi[]={2,3,1,5,6,4,8,9,7,0,10,-1,-2,15,30};
	int dizi2[]={0,1,2,3,4,5,6,7,8,9,10,11,12};
	
	minFind(dizi);
	maxFind(dizi);
	ortGet(dizi);
	siralama(dizi);
	terstenYaz(dizi2);
	
}

void minFind(int arr[]){

	int min=arr[0];
	int i=0,k=0;
	
	for(i=1;i<ARR_LENGTH;i++){
		if(arr[i]<min){
			min=arr[i];
			k=i;
		}
	}

			printf("Min Bul -----> Dizideki Minimum Değer Dizinin %d. Elemanı Olan %d Değeridir\n\n",k,arr[k]); 

}

void maxFind(int arr[]){

	int max=arr[0];
	int i=0,k=0;
	
	for(i=1;i<ARR_LENGTH;i++){
		if(arr[i]>max){
			max=arr[i];
			k=i;
		}
	}
			printf("Max Bul -----> Dizideki Maxsimum Değer Dizinin %d. Elemanı Olan %d Değeridir\n\n",k,arr[k]); 

}

void ortGet(int arr[]){

	int ort=0,top=0;
	int i;
	
	for(i=0;i<ARR_LENGTH;i++){
		top+=arr[i];
	}
	ort=top/ARR_LENGTH;

			printf("Ort Almak -----> Dizinin Ortalaması = %d\n\n",ort);
			printf("--------------------------------------------------------------------------------\n\n"); 

} 

void siralama(int arr[]){

	int i=0,j=0;
	int kutu;
	
	printf("Siaralanmamiş Dizi :(\n");
	printf("\t");
	for(i=0;i<ARR_LENGTH;i++){
		printf("%1d,",arr[i]);
	}printf("\n\n");
		
		
for ( i=0 ; i<ARR_LENGTH ; i++) {
			for (j=0 ; j<ARR_LENGTH-1 ; j++) {
				if (arr[j] > arr[j+1]) {
					kutu = arr[j];
					arr[j] = arr[j+1];
					arr[j+1] = kutu;
				}
			}
		}
	
	printf("Kuçukten Buyuğe Siaralanmiş Dizi :)\n");
	printf("\t");
	for(i=0;i<ARR_LENGTH;i++){
		printf("%1d,",arr[i]);
	}printf("\n\n");
		

for ( i=0 ; i<ARR_LENGTH ; i++) {
			for (j=0 ; j<ARR_LENGTH-1 ; j++) {
				if (arr[j] < arr[j+1]) {
					kutu = arr[j];
					arr[j] = arr[j+1];
					arr[j+1] = kutu;
				}
			}
		}
		
	printf("Buyukten Kuçuğe Siaralanmiş Dizi :)\n");
	printf("\t");
	for(i=0;i<ARR_LENGTH;i++){
		printf("%1d,",arr[i]);
	}printf("\n\n");
	printf("--------------------------------------------------------------------------------\n\n");

}

void terstenYaz(int arr2[]){
	int kutu2,i;
	
	printf("Dizi_2 :");
	printf("\n");
	printf("\t");
	for(i=0;i<LENGTH2;i++){
		printf("%1d,",arr2[i]);
	}printf("\n\n");
	
	if(LENGTH2%2==0){
		for(i=0;i<LENGTH2/2;i++){
			kutu2=arr2[i];
			arr2[i]=arr2[LENGTH2-(i+1)];
			arr2[LENGTH2-(i+1)]=kutu2;
		}
	}else if(LENGTH2%2==1){
		for(i=0;i<((LENGTH2-1)/2);i++){
			kutu2=arr2[i];
			arr2[i]=arr2[LENGTH2-(i+1)];
			arr2[LENGTH2-(i+1)]=kutu2;
		}
	}
	
	printf("Dizi_2'nin Tersten Yazilişi :");
	printf("\n");
	printf("\t");
	for(i=0;i<LENGTH2;i++){
		printf("%1d,",arr2[i]);
	}printf("\n");

}
