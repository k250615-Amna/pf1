#include <stdio.h>
#include <string.h>  //for compare function//

discountFlag = 0;
void customerInfo(char customerName[100] , int cnic[20], int index);
void displayInventory();
void addItems();
void updateInventory();
float calculateBill();
void showInvoice();
void mainMenu();

char customerName[100];
char customerCNIC[20];
int maxproducts=5;
int cartItems=10;
int cartProduct[cartItems];
int cartQuantity[cartItems];
int cartCount =0;
float totalAfterDiscount=0.0;
int products[maxproducts] = {100, 101, 112, 004, 105};
int stock[maxproducts]= {20,5,12,3,10};
float prices[maxproducts]={30.05,40,1000,2050.75,400};

void mainMenu(){
	int choice;
	while(1){
		printf("Super market system\n");
		printf("Enter 1 for submitting customer information: \n");
		printf("Enter 2 for displaying the inventory: \n");
		printf("Emter 3 for adding items to cart: \n");
		printf("Enter 4 for displaying bill: \n");
		printf("Enter 5 for displaying the invoice: \n");
		printf("Enter 6 for exiting\n");
		scanf("%d", choice);
	switch(choice) {
		
         case 1:
            customerInfo(char customerName[100] , int cnic[20], int index);
            break;
         case 2:
            displayInventory();
            break;
         case 3:
            addItems();
            break;
         case 4:
            calculateBill();
            break;
         case 5:
            showInvoice();
            break;
         case 6:
            return;
         default:
            printf("Invalid choice!\n");
        }
    }
}

void customerInfo(){
	char customerName;
	int cnic;
	printf("Enter your name: ");
	scanf("%[^\n]" , customerName[*index]);  //syntax allows spaces//
	printf("Enter your cnic: ");
	scanf("%d", &cnic[*index]);
	
	printf("Information saved\n");
	(*index)++;
}

void displayInventory(){
	    printf("\n--- Inventory ---\n");
        printf("ProductID\tStock\tPrice");
        for(int i = 0; i < maxproducts; i++) {
           printf("%-10d %-10d %-10.2f\n", products[i], stock[i], prices[i]);
        }
} 

void addItems(){
int cartProduct[cartItems];
int cartQuantity[cartItems];
int cartCount = 0;
    if(cartCount >= cartItems) {
        printf("Cart is full\n");
        return;
    }

    int productID, quantity, productIndex = -1;

    printf("\nEnter Product ID to add to cart: ");
    scanf("%d", &productID);
    
    for(int i = 0; i < maxproducts; i++) {
        if(products[i] == productID) {
            productIndex = i;
            break;
        }
    }

    if(productIndex == -1) {
        printf("Invalid Product ID!\n");
        return;
    }

    printf("Enter quantity: ");
    scanf("%d", &quantity);
    if(quantity > stock[productIndex]) {
        printf("Not enough stock available  Available: %d\n", stock[productIndex]);
        return;
    }


    cartProduct[cartCount] = productIndex;
    cartQuantity[cartCount] = quantity;
    cartCount++;
    stock[productIndex] -= quantity;

    printf("%d units of product %d added to cart.\n", quantity, productID);
}

void calculateBill() {
    if(cartCount == 0) {
        printf("Cart is empty\n");
        return;
    }

    float total = 0.0;
    for(int i = 0; i < cartCount; i++) {
        int index = cartProduct[i];            
        total += prices[index] * cartQuantity[i];
    }

    // Check for promo code
    char promo[20];
    printf("Enter promo code if any (or type 'no'): ");
    scanf(" %s", promo);

    if(strcmp(promo, "Eid2025") == 0) {
        total *= 0.75;  // apply 25% discount
        printf("Promo code applied! 25%% discount.\n");
    }

    printf("Total Bill: %.2f\n", total);
}

void showInvoice() {
    if(cartCount == 0) {
        printf("Cart is empty! Nothing to display.\n");
        return;
    }

    printf("\n--- Sales Invoice ---\n");
    printf("Customer Name: %s\n", customerName);
    printf("Customer CNIC: %s\n", customerCNIC);

    printf("\n%-10s %-10s %-10s %-10s\n", "ProductID", "Quantity", "Price", "Total");

    float subtotal = 0.0;


    for(int i = 0; i < cartCount; i++) {
        int index = cartProduct[i];               
        float itemTotal = prices[index] * cartQuantity[i];
        subtotal += itemTotal;
        printf("%-10d %-10d %-10.2f %-10.2f\n", products[index], cartQuantity[i], prices[index], itemTotal);
    }

    printf("\nSubtotal: %.2f\n", subtotal);
    float totalAfterDiscount = subtotal;
    int discountApplied = 0;

    int discountFlag;    
    if(discountFlag) {
        totalAfterDiscount = subtotal * 0.75;  
        discountApplied = 1;
    }

    if(discountApplied) {
        printf("Discount Applied: 25%%\n");
        printf("Total after discount: %.2f\n", totalAfterDiscount);
    } else {
        printf("Total: %.2f\n", subtotal);
    }

}

int main() {

    cartCount = 0;
    discountFlag = 0;
    totalAfterDiscount = 0.0;

 
    mainMenu();
