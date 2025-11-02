 #include <stdio.h>
void addBooks(int isbns[],char titles[][50],float prices[],int quantities[] ,int *index);
void processSale(int isbns[], char titles[][50], float prices[], int quantities[], int *index);
 void lowStock(int isbns[], char titles[][50], float prices[], int quantities[], int *index);

 
 void mainMenu(int isbns[], char titles[][50], float prices[], int quantities[], int *index){
 	while(1){
	 
 	 int choice;
 	 printf("         Library Menu           \n");
 	 printf("Enter 1 to add a new book: \n");
 	 printf("Enter 2 to process a sale\n");
 	 printf("Enter 3 to generate a low stock report\n");
 	 printf("Enter your choice: \n");
 	 scanf("%d", &choice);
 	
 	  switch(choice){
 		case 1: addBooks(isbns,titles,prices,quantities,index);
 		break;
 		case 2: processSale(isbns,titles,prices,quantities,index);
 		break;
 		case 3: lowStock(isbns,titles,prices,quantities,index);
 		break;
 		default: printf("Invalid choice");
	  }
    }
 }
 void addBooks(int isbns[],char titles[][50],float prices[],int quantities[] ,int *index){
 	int isbn,val=0,i;
 	if(*index > 100){
 		printf("Inventory is full! ");
	 }

 	do {
 		printf("Enter the isbn of the book");
 		scanf("%d",&isbn);
 		for(i=0;i<*index;i++){
 			if(isbns[i]==isbn){
 				printf("The isbn number already exists");
 				val=1;
 				break;
			 }
		 }
	 }while(val==1);
	 isbns[*index]=isbn;
	 
	 printf("Enter the title of the book: ");
	 scanf(" %[^\n]", &titles[*index]);
	 printf("Enter the price of the book: ");
	 scanf("%f" , &prices[*index]);
	 printf("Enter the amount of copies available for the book: ");
	 scanf("%d" , &quantities[*index]);
	 
	 (*index)++;
 }
 void processSale(int isbns[], char titles[][50], float prices[], int quantities[], int *index){
 	int isbn,quantity,i,exists;
 	
 	printf("Enter the isbn number of the book: ");
 	scanf("%d\n", &isbn);
 	printf("Enter the quantity sold: ");
 	scanf("%d\n", &quantity);
 	
 	for(i=0;i<*index;i++){
 		
 		if(isbns[i]==isbn){
 			exists=1;
 			if(quantities[i]<quantity){
 				printf("Out of stock");
 				printf("Quantity available = %d\n" , quantities[i]);
			 }
			 else{
			 	quantities[i] = quantities[i] - quantity;
			 }
		 }
	 }
 	if(exists==0){
 		printf("The book is not registered");
	 }
 }
 void lowStock(int isbns[], char titles[][50], float prices[], int quantities[], int *index){
 	int i,found=0;
 	printf("           Low Stock Report         ");
 	for(i=0;i<*index;i++){

 		if(quantities[i]<5){
 			found=1;
 			printf("Title of the book is: %s , with the Isbn number: %d\n" , titles[i], isbns[i]);
 			printf("The per unit price of the book is %f", prices[i]);
 			printf("\n");
		 }
	 }
	 if(found==0){
	 	printf("There are no books with quantities below 5 ");
	 }
 } 
 

 int main(){
 	int isbns[100];
 	char titles[100][50];
 	float prices[100];
 	int quantities[100];
 	int index = 0;
 	mainMenu(isbns, titles, prices, quantities, &index);
 }
