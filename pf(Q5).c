#include <stdio.h>

void encodeMessage(char message[]);
void decodeMessage(char message[]);
void mainMenu();


void mainMenu(){
	char message[256];
	int choice;
	while(1){
		printf("Enter 1 if you want to encode your message: \n");
		printf("Enter 2 if you want to decode your message: \n");
		printf("Enter 3 if you want to exit: \n");
		scanf("%d" , &choice);
		
		switch(choice){
			case 1:
				printf("Enter the message you want to encode (Do not include spaces)");
				scanf("%s", message);
				encodeMessage(message);
				break;
			case 2:
				printf("Enter the message you want to decode (Don nnot include spaces)");
				scanf("%s", message);
				decodeMessage(message);
				break;
			case 3:
				return;
				
			default:
				printf("Invalid choice\n");
		}
	}
}
void encodeMessage(char message[]){
	int size=0,i,asciival;
	char temp,value;
	
	//calculate the lenght of the string//
	while(message[size]!='\0'){
		size++;
	}
	
	for(i=0;i<size/2;i++){  //this will switch the places of the first char in the string with the last and so on//
		temp = message[i];
		message[i]= message[size-i-1]; //if string len is 10 then char on index 0 will be swapped with char on index 9 then index 1 with index [10-1-1 =8]
		message[size-i-1]=temp;
	}
	for(i=0;i<size;i++){
		value=message[i];
		asciival=(int)value;
	      //toggle second bit by bit 1 //
	    asciival= asciival ^ (1 << 1);;  //toggle usuing xor//
          	//toggle fifth//
	    asciival = asciival ^ (1<<4);
	    
	    message[i]=(char)asciival;
	}
	printf("Encoded message: \n");
	for(i=0;i<size;i++){
		printf("%c" , message[i]);
	}
	printf("\n");
}
void decodeMessage(char message[]){
	int size,i,asciival;
	char temp;
	//toggling the bits again will give us the origial values//
	while(message[size] != '\0'){
		size++;
	}
	
	for(i=0;i<size;i++){
		asciival=(int)message[i];
		
		asciival=asciival ^ (1 << 1);
		asciival=asciival ^ (1 << 4);
		
		message[i]= (char)asciival;
	}
	
	for(i=0;i<size/2;i++){
		temp = message[i];
		message[i]= message[size-i-1];
		message[size-i-1]=temp;
		
	}
	printf("Decoded message: \n");
	for(i=0;i<size;i++){
		printf("%c" , message[i]);
	}
	printf("\n");
	
}
int main(){
	
	mainMenu();
}
