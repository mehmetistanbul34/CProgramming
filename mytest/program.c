#include<stdio.h>
#include<stdlib.h>

//int my_print(int arr[][3]);
void findSpace(int const arr[][3],int spaceIndex[]);
int testFindSpace(int spaceArr[]);
//void change_space(int arr[][3]);
//int siralama(int arr[][3]);

#define ARR_X 3
#define ARR_Y 3
//#define row_x 3
//#define column_y 3

int main(){
		//[satır][sütun]
	int dizi[ARR_X][ARR_Y]={{8,0,7},{4,2,6},{5,1,3}};
	
	int spaceIndex[2] = {-1,-1}; //initialize
	findSpace(dizi,spaceIndex);
	
	if(!testFindSpace(spaceIndex)){
		printf("SpaceIndex değeri bulunamadı. program sonlandırıldı.\n");
		return 0;
	}
	
	printf("SpaceIndex successfull\n");
	
	while(!validSort(dizi)){
		changeSpace(dizi,spaceIndex);			
	}
	//change_space(dizi);
	//my_print(dizi);
	
	
	return 0;
}


void changeSpace(int arr[][ARR_Y],int spaceIndex[]){

	int row=spaceIndex[0];
	int column=spaceIndex[1];
	
		if(spaceIndex[0]==0 && spaceIndex[1]==0) //RULE ONE : LEFT TOP CORNER	
		{
			//to do.
			int tmp[2] = { row*ARR_X+column+1, (row+1)*ARR_X+column };
				int my_random = rand()%2;
				arr[spaceIndex] = arr[tmp[my_random]];
				arr[tmp[my_random]] = 0;
				spaceIndex = tmp[my_random]; 
		}
		
		if(spaceIndex[0]==0 && spaceIndex[1]==2) //RULE TWO : RİGHT TOP CORNER
		{
			//to do.
			int tmp[2] = { row*ARR_X+column-1, (row-1)*ARR_X+column };
				int my_random = rand()%2;
				arr[spaceIndex] = arr[tmp[my_random]];
				arr[tmp[my_random]] = 0;
				spaceIndex = tmp[my_random];
		}
		
		if(spaceIndex[0]==2 && spaceIndex[1]==0) //RULE THREE : LEFT BOTTOM CORNER
		{
			//to do.
			int tmp[2] = { row*ARR_X+column+1, (row+1)*ARR_X+column };
				int my_random = rand()%2;
				arr[spaceIndex] = arr[tmp[my_random]];
				arr[tmp[my_random]] = 0;
				spaceIndex = tmp[my_random];
		}
		
		if(spaceIndex[0]==2 && spaceIndex[1]==2) //RULE FOUR : RİGHT TOP CORNER
		{
			//to do.
			int tmp[2] = { row*ARR_X+column-1, (row-1)*ARR_X+column };
				int my_random = rand()%2;
				arr[spaceIndex] = arr[tmp[my_random]];
				arr[tmp[my_random]] = 0;
				spaceIndex = tmp[my_random];
		}
		
		
		if(spaceIndex[0]==0 && !(spaceIndex[1]==0 || spaceIndex[1]==2)) //RULE FİVE : MİDLE TOP	
		{
			//to do.
			int tmp[3] = { row*ARR_X+column+1,row*ARR_X+column-1, (row+1)*ARR_X+column };
				int my_random = rand()%3;
				arr[spaceIndex] = arr[tmp[my_random]];
				arr[tmp[my_random]] = 0;
				spaceIndex = tmp[my_random]; 
		}
		
		if(!(spaceIndex[0]==0 || spaceIndex[0]==2) && spaceIndex[1]==0) //RULE SİX : LEFT MİDLE
		{
			//to do.
			int tmp[3] = { row*ARR_X+column+1, (row-1)*ARR_X+column , (row+1)*ARR_X+column };
				int my_random = rand()%3;
				arr[spaceIndex] = arr[tmp[my_random]];
				arr[tmp[my_random]] = 0;
				spaceIndex = tmp[my_random];
		}
		
		if(spaceIndex[0]==1 && !(spaceIndex[1]==0 || spaceIndex[1]==1)) //RULE SEVEN : RİGHT MİDLE
		{
			//to do.
			int tmp[3] = { row*ARR_X+column-1, (row+1)*ARR_X+column , (row-1)*ARR_X+column };
				int my_random = rand()%3;
				arr[spaceIndex] = arr[tmp[my_random]];
				arr[tmp[my_random]] = 0;
				spaceIndex = tmp[my_random];
		}
		
		if(spaceIndex[0]==2 && !(spaceIndex[1]==0 || spaceIndex[1]==2)) //RULE EİGHT : BOTTOM MİDLE
		{
			//to do.
			int tmp[3] = { row*ARR_X+column-1, row*ARR_X+column+1, (row-1)*ARR_X+column };
				int my_random = rand()%3;
				arr[spaceIndex] = arr[tmp[my_random]];
				arr[tmp[my_random]] = 0;
				spaceIndex = tmp[my_random];
		}
		
		
		if(!(spaceIndex[0]==0 || spaceIndex[0]==2)  && !(spaceIndex[1]==0 || spaceIndex[1]==2)) //RULE NİNE : MİDLE
		{
			//to do.
			int tmp[4] = { row*ARR_X+column-1, row*ARR_X+column+1, (row-1)*ARR_X+column ,(row+1)*ARR_X+column };
				int my_random = rand()%4;
				arr[spaceIndex] = arr[tmp[my_random]];
				arr[tmp[my_random]] = 0;
				spaceIndex = tmp[my_random];
		}
		
	
}


int validSort(int arr[][ARR_Y]){
	for(int i=0;i<ARR_X;i++)
		for(int j=0;j<ARR_Y-1;j++){
			if(arr[i][j]==0)
				continue;
			if(arr[i][j]>arr[i][j+1])
			{		
				return -1;
			}
		}
	return 1;	
}

void findSpace(int const arr[][ARR_Y],int spaceIndex[]){
	for(int i=0;i<ARR_X;i++)
		for(int j=0;j<ARR_Y;j++)
			if(arr[i][j]==0)
			{		
				spaceIndex[0] = i;
				spaceIndex[1] = j;	
			}	
}

int testFindSpace(int spaceArr[]){
	if(spaceArr[0]==0 && spaceArr[1]==1)
		return 1;
	return -1;
}
/*
int my_print(int arr[][3]){
		
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
		printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
	
}

void change_space(int arr[][3],int spaceIndex){
	while(siralama(arr)<0){
		//sol üst köşe
		
		//sağ üst köşe
		//sol alt köşe
		//sağ alt köşe
		
		//üst orta
		//alt orta
		//sol orta
		//sağ orta
		
		//en orta
	}
}

int siralama(int arr[][3]){
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++)
		if(arr[i][j]>arr[i+1][j+1])
			return -1;
			
	}
	
	return 1;
}
*/
