#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

#define PI 3.146785
#define NUMBER_OF_LOOP 10

float eSonuc(int a,int b);
float eSonuc2(int a,int b);
float eSonuc3(int a,int b);
float eSonucRandom(int r1,int r2);
float f1(int a,int b);
float f2(int a,int b);
float f3(int a,int b);
float fRandom(int r1,int r2);
float takingPower(float base, float power);


int main(){
	int a,b;
	float t1,t2,t3,min;

	srand((unsigned)time(NULL)); 
	int r1=rand()%10;
	printf("Random1 : %d\n",r1);
	int r2 =rand()%10;
	printf("Random2 : %d\n",r2);

	printf("a dergerini giriniz\n");
	scanf("%d",&a);
	printf("b dergerini giriniz\n");
	scanf("%d",&b);

	printf("F1  : %f\n",f1(a,b));
	printf("F2  : %f\n",f2(a,b));
	printf("F3  : %f\n",f3(a,b));
	printf("F Random  : %f\n",fRandom(r1,r2));

	t1=(fRandom(r1,r2)-f1(a,b));
	t1=abs(t1);
	printf("t1 : %f\n",t1);

	t2=(fRandom(r1,r2)-f2(a,b));
	t2=abs(t2);
	printf("t2 : %f\n",t2);

	t3=(fRandom(r1,r2)-f3(a,b));
	t3=abs(t3);
	printf("t3 : %f\n",t3);
	
	min=t1;
	if(t2<min){
		min=t2;
		if(t3<min){
			min=t3;
			printf("En Doğru Fonksiyon f3'dir\n");		
		}else{
			printf("En Doğru Fonksiyon f2'dir\n");	
		}
	}else if(t3<min){
		min=t3;
		printf("En Doğru Fonksiyon f3'dir\n");
	}else{
		min=t1;
		printf("En Doğru Fonksiyon f1'dir\n");	
	}	
}

float eSonuc(int a,int b){
	float sayi,sonuc;
	sayi=(a*a-b*b)/a*a;
	sonuc=sqrt(sayi);
	return sonuc;
}

float eSonuc2(int a,int b){
	float sayi,sonuc,q=0;
	q=(a-b)/(a+b);
	sayi=(4-3*(q*q));
	sonuc=sqrt(sayi);
	return sonuc;
}

float eSonuc3(int a,int b){
	float sayi,sonuc;
	sayi=((3*a+b)*(a+3*b));
	sonuc=sqrt(sayi);
	return sonuc;
}

float eSonucRandom(int r1,int r2){
	double sayi,sonuc;
	sayi=r1*r1+r2*r2;
	sonuc=sqrt(sayi);
	return sonuc;
}

float f1(int a,int b){
	float n,e,m,carpim=1,csonuc,toplam=0,C,E;
		E=eSonuc(a,b);
	for(n=0;n<10;n++){
		for(m=1;m<n;m++){
				carpim*=m;
		}
		csonuc=carpim*(2*m-1)/2*m;
		csonuc*=csonuc;
			E=takingPower(E,2.0*n);	
		E/(2*n-1);
		csonuc*=E;
	toplam-=csonuc;
	C=2*PI*a*toplam;
	return C;
	}
}

float f2(int a, int b){
	float C2,x,y;	
	x=takingPower((a-b)/(a+b),2);
	y=eSonuc2(a,b);
	C2=PI*(a+b)*(1+(3*x)/(10+y));
	return C2;
}

float f3(int a,int b){
	float C3,d;
	d=eSonuc3(a,b);
	C3=PI*(3*(a+b)-d);
	return C3;
}

float fRandom(int r1,int r2){
	float C3,d;
	d=eSonucRandom(r1,r2);
	C3=2*PI*d;
	return C3;
}

//iteratif yöntem, brute force yöntem
float takingPower(float base,float power){
	float result = base;
	if(power>=0){
		if(power==0)
			return 1.0;
		if(power==1)
			return result;

		for(int i=1;i<power;i++){
			result = result * base;
		}
	}
	else{
		for(int i=1;i<power;i++){
			result =1/(result * base);
		}
	}
	return result;
}

