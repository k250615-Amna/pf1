#include <stdio.h>

int stack[10];  //hard coding the lenght of the array as 10//

void push(int stack[] , int *top,int  maxSize);
void pop(int stack[], int *top);
void peak(int stack[], int *top);
void display(int stack[], int *top);
void mainMenu(int stack[], int *top, int maxSize);

void mainMenu(int stack[], int *top, int maxSize){
	int choice;

	
	while(1){
		
	     printf("Stack Menu\n");
	     printf("Enter 1 if you want to push a value into the stack\n");
     	 printf("enter 2 if you want to (pop) remove the top elememt\n");
	     printf("Enter 3 if you want to view the top most element of the stack\n");
	     printf("Enter 4 if you want to view the whole stack\n");
     	 printf("Enter 5 if you want to exit\n");
         scanf("%d", &choice);
		switch(choice){
			case 1:
				push(stack,top,maxSize);
				break;
			case 2:
				pop(stack,top);
				break;
			case 3:
				peak(stack, top);
				break;
			case 4:
				display(stack,top);
				break;
			case 5:
				return ; //breaks the code//
		
			default:
				printf("Invalid choice");
		}
		
	}
}
void push(int stack[], int *top, int maxSize){
	
	int val;
	if(*top == maxSize-1){
		printf("The stack will overflow\n");
		return;
	}
	printf("Enter the value you want to add: \n");
	scanf("%d" , &val);
	
	(*top)++;   //points at the value added and its initialized as -1//
	stack[*top] = val;
	printf("Value was pushed\n");
}
void pop(int stack[],int *top){
	if(*top==-1){
		printf("The stack is empty\n");
		return;
	}
	printf("The value that will be popped is: %d\n", stack[*top]);
	stack[*top]=0;
	(*top)--;
}
void peak(int stack[], int *top){
	if(*top == -1){
		printf("Stack is empty\n");
		return;
      }

	printf("Top most element is: %d\n" , stack[*top]);
}
void display(int stack[], int *top){
	int i, size=*top;
	if(*top==-1){
		printf("There is no value to display\n");
		return;
	}
	for(i=0;i<=size;i++){
		printf("Element %d is: %d\n", i, stack[i]);
		
	}	
}
int main(){
	int stack[10]; //hard coded , assuming size //
	int top = -1;
	int maxSize=sizeof(stack)/sizeof(stack[0]);
	
	mainMenu(stack, &top, maxSize);  //using pointers to update values throughout//
}
