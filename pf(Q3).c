#include <stdio.h>

int grid[4][4]={0};
int rows= sizeof(grid)/sizeof(grid[0]);
int cols= sizeof(grid[0])/sizeof(grid[0][0]);
void updateSector(int grid[4][4] , int r, int c, int bitNo, int setTo);
void querySector(int grid[4][4], int r, int c);
void runDiagnostics(int grid[4][4]);
void mainMenu(int grid[4][4]);


void mainMenu(int grid[4][4]){

	int choice, r, c , bitNo, setTo;
	
	while(1) {      //keeps repeating until you manually break the code//
		printf("Menu for IESCO power grid\n");
		printf("Enter 1 if you want to update sector status: \n");
		printf("Enter 2 if you want to generate the query of sector status: \n");
		printf("Enter 3 if you want to run system diagnostics: \n");
		printf("Enter 4 if you want to exit: \n");
		scanf("%d", &choice);
		
		switch(choice){
			case 1:
				printf("Enter the row (0 to 3): \n");
				scanf("%d", &r);
			    printf("Enter the column (0 to 3): \n");
				scanf("%d", &c);
			    printf("Enter the bit you want to alter (0:Power, 1:Overload, 2:Maintenance): \n");
				scanf("%d", &bitNo);
			    printf("What do you want to set the value to: ");
				scanf("%d", &setTo);
				updateSector(grid,r,c,bitNo,setTo);
			break;
			
			case 2:
				printf("Enter the row (0 to 3): \n");
				scanf("%d", &r);
			    printf("Enter the column (0 to 3): \n");
				scanf("%d", &c);
				querySector(grid,r,c);
				break;
				
			case 3:
				runDiagnostics(grid);
				break;
				
			case 4:
				return;
				
			default:
				printf("Invalid choice\n");		
		}	
	}
}
void updateSector(int grid[4][4], int r, int c, int bitNo, int setTo){
	int set=(1<<bitNo);
	if(setTo==1){
		grid[r][c] = grid[r][c] | set;
	}
	else{
		grid[r][c]= grid[r][c] & ~set;   //  ~ changes 1 to 0 and 0 to 1//
	}
}
void querySector(int grid[4][4], int r, int c){
	int value = grid[r][c];
	
	if((value & (1 << 0) )!= 0 ){
		printf("Power is on\n");
	}else{
		printf("Power is off\n");
	}
	
	if((value & (1 << 1)) !=0){
		printf("Overload\n");
	}else{
		printf("No overload \n");
	}
	
	if((value & (1 << 2))!= 0){
		printf("Maintenance needed \n");
	}else{
		printf("Maintenance not needed \n");
	}
	printf("\n");
}
void runDiagnostics(int grid[4][4]){
	int overLoad=0,  maintenance=0 ;
	int i , j , value ;
	
	for(i=0;i<rows;i++){
		for(j=0;j<cols;j++){
			value = grid[i][j];
			if((value & (1 << 1))!=0){
				overLoad++;
			}
			if((value & (1 << 2))!=0){
				maintenance++;
	    	}
		}
		
	}
printf("Total overload sectors are : %d" , overLoad);
printf("Total sectors that need maintenance are: %d", maintenance);
}
int main(){
	int grid[4][4]={0};
	 mainMenu(grid);
}
