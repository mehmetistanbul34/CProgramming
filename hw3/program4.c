#include<stdio.h>

/* Author : Mehmet Cakmak ssss */

int main(){
	int i,j,kutu,k,deneme=0;
	char bosluk[100]=" ";
	int dizi[]={8,1,4,2,5,3,7,6};

		for(i=0;i<8;i++){
			for(j=0;j<=6;j++){
				if(dizi[j]>dizi[j+1]){
					kutu=dizi[j];		
					dizi[j]=dizi[j+1];
					dizi[j+1]=kutu;
	
			}
		}
		deneme++;
		printf("deneme %d\n",deneme);
		for(k=0;k<=2;k++){
			printf("%d ",dizi[k]);
		}
		printf("\n");
		for(k=3;k<=4;k++){
			if(k==3){
				printf("%d ",dizi[k]);
				printf("%s ",bosluk);
			}else{
				printf("%d ",dizi[k]);
			}
		}
		printf("\n");
		for(k=5;k<=7;k++){
			printf("%d ",dizi[k]);
		}
		printf("\n");
		printf("\n");
	}
}

