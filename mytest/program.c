/*
	Bu ödev Mehmet Çakmak tarafından yapıldı.
	Bu ödeve devam edeceğim.
*/

#include<stdio.h>
#include<stdlib.h>

#define ARR_X 3
#define ARR_Y 3

void findSpace(int const arr[][3],int spaceIndex[]);
int validSort(int arr[][ARR_Y]);
void changeSpace(int arr[][ARR_Y],int spaceIndex[]);
int myPrint(int arr[][3]);


int main(){
		//[satır][sütun]
	int dizi[ARR_X][ARR_Y]={{8,0,7},{4,2,6},{5,1,3}};
	
	int spaceIndex[2] = {0,0}; //initialize
		
	while(!validSort(dizi)){
	
		changeSpace(dizi,spaceIndex);
		myPrint(dizi);
		
		}
		
	return 0;
}

void changeSpace(int arr[][ARR_Y],int spaceIndex[]){
	

	int row=spaceIndex[0];
	int column=spaceIndex[1];
	
		if(row==0 && column==0) //RULE ONE : LEFT TOP CORNER	
		{
			//to do.
			int tmp[2][2] = { {row,column+1}, {row+1,column} }; //tmp[0][0] = row, tmp[0][1] = column+1, tmp[1][0] = row+1
				int myRandom = rand()%2;
				arr[row][column] = arr[tmp[myRandom][0]][tmp[myRandom][1]];
				arr[tmp[myRandom][0]][tmp[myRandom][1]] = 0;
				row =  tmp[myRandom][0];
				column = tmp[myRandom][1];
				printf("Hello World");
		}
		
		if(row==0 && column==2) //RULE TWO : RİGHT TOP CORNER
		{
			//to do.
			int tmp[2][2] = { {row,column-1}, {row+1,column} }; //tmp[0][0] = row, tmp[0][1] = column+1, tmp[1][0] = row+1
				int myRandom = rand()%2;
				arr[row][column] = arr[tmp[myRandom][0]][tmp[myRandom][1]];
				arr[tmp[myRandom][0]][tmp[myRandom][1]] = 0;
				row =  tmp[myRandom][0];
				column = tmp[myRandom][1];
		}
		
		if(row==2 && column==0) // RULE THREE : LEFT BOTTOM CORNER
		{
			int tmp[2][2] = { {row,column+1}, {row-1,column} }; //tmp[0][0] = row, tmp[0][1] = column+1, tmp[1][0] = row+1
				int myRandom = rand()%2;
				arr[row][column] = arr[tmp[myRandom][0]][tmp[myRandom][1]];
				arr[tmp[myRandom][0]][tmp[myRandom][1]] = 0;
				row =  tmp[myRandom][0];
				column = tmp[myRandom][1];
		}
		
		if(row==2 && column==2) // RULE FOUR : RİGHT BOTTOM CORNER
		{
			//to do.
			int tmp[2][2] = { {row,column-1}, {row-1,column} }; //tmp[0][0] = row, tmp[0][1] = column+1, tmp[1][0] = row+1
				int myRandom = rand()%2;
				arr[row][column] = arr[tmp[myRandom][0]][tmp[myRandom][1]];
				arr[tmp[myRandom][0]][tmp[myRandom][1]] = 0;
				row =  tmp[myRandom][0];
				column = tmp[myRandom][1];
		}
		
		
		if(row==0 && !(column==0 || column==2)) // RULE FİVE : MİDLE TOP	
		{
			//to do.
			int tmp[3][2] = { {row,column-1}, {row,column+1}, {row-1,column} }; 
				int myRandom = rand()%3;
				arr[row][column] = arr[tmp[myRandom][0]][tmp[myRandom][1]];
				arr[tmp[myRandom][0]][tmp[myRandom][1]] = 0;
				row =  tmp[myRandom][0];
				column = tmp[myRandom][1];
		}
		
		if(!(row==0 || row==2) && column==0) //RULE SİX : LEFT MİDLE
		{
			//to do.
			int tmp[3][2] = { {row,column+1}, {row-1,column}, {row-1,column} }; 
				int myRandom = rand()%3;
				arr[row][column] = arr[tmp[myRandom][0]][tmp[myRandom][1]];
				arr[tmp[myRandom][0]][tmp[myRandom][1]] = 0;
				row =  tmp[myRandom][0];
				column = tmp[myRandom][1];
		}
		
		if(row==1 && !(column==0 || column==1)) //RULE SEVEN : RİGHT MİDLE
		{
			//to do.
			int tmp[3][2] = { {row,column-1}, {row+1,column}, {row-1,column} }; 
				int myRandom = rand()%3;
				arr[row][column] = arr[tmp[myRandom][0]][tmp[myRandom][1]];
				arr[tmp[myRandom][0]][tmp[myRandom][1]] = 0;
				row =  tmp[myRandom][0];
				column = tmp[myRandom][1];
		}
		
		if(row==2 && !(column==0 || column==2)) //RULE EİGHT : BOTTOM MİDLE
		{
			//to do.
			int tmp[3][2] = { {row,column-1}, {row,column+1}, {row-1,column} }; 
				int myRandom = rand()%3;
				arr[row][column] = arr[tmp[myRandom][0]][tmp[myRandom][1]];
				arr[tmp[myRandom][0]][tmp[myRandom][1]] = 0;
				row =  tmp[myRandom][0];
				column = tmp[myRandom][1];
		}
		
		
		if(!(row==0 || row==2)  && !(column==0 || column==2)) //RULE NİNE : MİDLE
		{
			//to do.
			int tmp[4][2] = { {row,column-1}, {row,column+1}, {row-1,column}, {row+1,column} }; 
				int myRandom = rand()%4;
				arr[row][column] = arr[tmp[myRandom][0]][tmp[myRandom][1]];
				arr[tmp[myRandom][0]][tmp[myRandom][1]] = 0;
				row =  tmp[myRandom][0];
				column = tmp[myRandom][1];
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

int myPrint(int arr[][3]){
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
		printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
}
