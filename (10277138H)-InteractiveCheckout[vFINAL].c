#include <stdio.h>                          
#include <string.h>           
#include <stdbool.h> 
#include <windows.h>
#include <time.h>

void loadingDot(void);
void printHeader(void); 
float calculatePrice(float totalPrice, float discount);
float discountPrice(float finalPrice, float totalPrice);
void displayReceipt(char itemList[1000], float totalPrice, float finalPrice, float discountedPrice, char isMrHee, float discount);

int main(void){
    
    //Prices of the modifications
    const float mod1 = 99.99;
    const float mod2 = 449.99;
    const float mod3 = 1049.99;
    const float mod4 = 0.00;
    
    //Prices of the watches
    const float typeA = 449.99;
    const float typeB = 1599.99;
    const float typeC = 649.99;
    
    //Temporary storage for user inputs
    char inputBuffer[255] = "";
    
    bool runningProgram = true;
    
    while(runningProgram){
        //Boolean to prevent user from choosing a mod. twice
        bool choseMod1 = false;
        bool choseMod2 = false;
        bool choseMod3 = false;
        
        //List for purchased items and modifications
        char itemList[1000]  = "";
        
        //Other variables that are declared later on
        float totalPrice = 0;
        float discount   = 0;
        char enteredYN   = 0;
        char input       = 0;
        char isMrHee     = 0;
        
        printHeader();
        
        do{
            while(1){
            
                printf("\nWhat SEIKO watch would you like to purchase?");
                printf("\nType [1]: 5Sports - S$449.99 ");
                printf("\nType [2]: Prospex - S$1599.99 ");
                printf("\nType [3]: Presage - S$649.99");
                printf("\nYour selection: ");
                scanf("%99s", inputBuffer); //Stores user input into inputBuffer temporarily
                input = inputBuffer[0]; //Sets the first letter as the input
            
                if(input == '1' && inputBuffer[1] == '\0'){ //Checks if the second character is null terminator
                    totalPrice = totalPrice + typeA;
                    printf("\033[1;4;40;37mYou have selected the 5Sports.\033[0m\n");
                    strcat(itemList, "\n SEIKO 5Sports - S$449.99"); //Adds item into array
                    break; //Ends the while loop and moves on to the next while loop
                
                } else if(input == '2' && inputBuffer[1] == '\0'){
                    totalPrice = totalPrice + typeB;
                    printf("\033[1;4;40;37mYou have selected the Prospex.\033[0m\n");
                    strcat(itemList, "\n SEIKO Prospex - S$1599.99");
                    break;
                
                } else if(input == '3' && inputBuffer[1] == '\0'){
                    totalPrice = totalPrice + typeC;
                    printf("\033[1;4;40;37mYou have selected the Presage.\033[0m\n");
                    strcat(itemList, "\n SEIKO Presage - S$649.99");
                    break;
                
                } else {
                    printf("\"%s\" is not a valid selection. Please enter a valid selection!\n", inputBuffer);    
                    while (getchar() != '\n');//Loops until all characters are deleted except for \n
                }
            } 
        
            while(1){
            
                input     = 0;
                printf("\nAdd modification?");
                printf("\nType [1]: Horse leather strap - S$99.99");
                printf("\nType [2]: Sapphire dial - S$449.99");
                printf("\nType [3]: Diamond crown - S$649.99");
                printf("\nType [4]: No thanks!");
                printf("\nYour selection: ");
                scanf("%99s", inputBuffer);
                input = inputBuffer[0];
            
                if(input == '1' && inputBuffer[1] == '\0' && choseMod1 == false){
                    totalPrice = totalPrice + mod1;
                    choseMod1  = true;//Sets choseMod = true so that user is not able to select this mod again
                    printf("\033[1;4;40;37mYou have added the Horse Leather Strap.\033[0m\n");
                    strcat(itemList, "\n + Horse Leather Strap - S$99.99");//Adds modification to itemList
                    continue;//Continues to run the while loop from the start (Asks to add mod.)
                
                } else if(input == '2' && inputBuffer[1] == '\0' && choseMod2 == false){
                    totalPrice = totalPrice + mod2;
                    choseMod2  = true;
                    printf("\033[1;4;40;37mYou have added the Sapphire Dial.\033[0m\n");
                    strcat(itemList, "\n + Sapphire Dial - S$449.99");
                    continue;
                
                } else if(input == '3' && inputBuffer[1] == '\0' && choseMod3 == false){
                    totalPrice = totalPrice + mod3;
                    choseMod3  = true;
                    printf("\033[1;4;40;37mYou have added the Diamond Crown.\033[0m\n");
                    strcat(itemList, "\n + Diamond Crown - S$1049.99");
                    continue;
                
                } else if(input == '4' && inputBuffer[1] == '\0'){
                    totalPrice = totalPrice + mod4;
                    break;
                
                } else if(input == '1' && inputBuffer[1] == '\0' && choseMod1 == true){
                    printf("You have already added the Horse Leather Strap! Please select something else.\n");
                    continue;
                
                } else if(input == '2' && inputBuffer[1] == '\0' && choseMod2 == true){
                    printf("You have already added the Sapphire Dial! Please select something else.\n");
                    continue;
                
                } else if(input == '3' && inputBuffer[1] == '\0' && choseMod3 == true){
                    printf("You have already added the Diamond Crown! Please select something else.\n");
                    continue;
                
                } else {
                    printf("\"%s\" is not a valid selection. Please enter a valid selection!\n", inputBuffer); 
                    while (getchar() != '\n');
                }
            }
        
            while(1){
                printf("\nWould you like to purchase another watch? [Y/N] ");
                scanf("%99s", inputBuffer);
                enteredYN = inputBuffer[0];
                if((enteredYN == 'y' || enteredYN == 'Y' || enteredYN == 'n' || enteredYN == 'N') && inputBuffer[1] == '\0'){
                    break;
                } else {
                    printf("\"%s\" is not a valid selection. Please enter a valid selection!\n", inputBuffer); 
                    while (getchar() != '\n');
                }
            }
        } while(enteredYN == 'Y' || enteredYN == 'y');
        
        while(1){
        
            printf("\nAre you Mr. Hee? [Y/N] ");
            scanf("%99s", inputBuffer);
            isMrHee = inputBuffer[0];
        
            if((isMrHee == 'Y' || isMrHee == 'y') && inputBuffer[1] == '\0'){
                discount = discount + 0.2;
                printf("Applying a Mr. Hee gratituity discount of 20%%.");
                loadingDot();
                printf("\n");
                break;
            
            } else if((isMrHee == 'n' || isMrHee == 'N') && inputBuffer[1] == '\0') {
                break;
            } else {
                printf("\"%s\" is not a valid selection. Please enter a valid selection!\n", inputBuffer); 
                while (getchar() != '\n');
            }
        }
       
        while(1){
            input = 0;
            printf("\nDo you have a discount code to apply? [Y/N] ");
            scanf("%99s", inputBuffer);
            input = inputBuffer[0];
            if((input == 'Y' || input == 'y') && inputBuffer[1] == '\0'){
                printf("Enter your code: ");
                scanf("%99s", inputBuffer);
                input = inputBuffer[0];
                if(strcmp(inputBuffer, "MRHEE77") == 0){
            
                    discount = discount + 0.05;
                    printf("Code is valid!\n");
                    printf("Applying code MRHEE77.");
                    loadingDot();
                    printf("\n");
                    break;
                } else {
                    printf("\"%s\" is not a valid code. Please enter a valid code or type 'nil' to proceed with checkout!\n", inputBuffer); 
                    while (getchar() != '\n');
                }
            }else if((input == 'n' || input == 'N') && inputBuffer[1] == '\0'){
                printf("Proceeding straight to checkout.");
                loadingDot();
                printf("\n");
                break;  
            
            } else {
                printf("\"%s\" is not a valid selection. Please enter a valid selection!\n", inputBuffer); 
                while (getchar() != '\n');
            }
        }
        
        if(isMrHee == 'Y' || isMrHee == 'y'){  
    
            float finalPrice      = calculatePrice(totalPrice , discount);
            float discountedPrice = discountPrice(finalPrice, totalPrice);
            printf("Hello Mr. Hee! Your total is $%.2f after $%.2f deduction! \nPlease PayNow total amount to \033[1;40;37m88184854\033[0m.\n\n", finalPrice, discountedPrice);
            displayReceipt(itemList, totalPrice, finalPrice, discountedPrice, isMrHee, discount);

        }else if(isMrHee == 'n' || isMrHee == 'N'){ 
        
            float finalPrice = calculatePrice(totalPrice , discount);
            float discountedPrice = discountPrice(finalPrice, totalPrice);
            printf("Your total is $%.2f! Please PayNow total amount to \033[1;40;37m88184854\033[0m.\n\n", finalPrice);
            displayReceipt(itemList, totalPrice, finalPrice, discountedPrice, isMrHee, discount);
        }
        while(1){
            printf("\nProceed with the next customer? [Y/N] ");
            scanf("%99s", inputBuffer);
            input = inputBuffer[0];
            if((input == 'Y' || input == 'y')&& inputBuffer[1] == '\0'){
                printf("Running progran again.");
                loadingDot();
                printf("\n");
                break;
            } else if((input == 'N' || input == 'n') && inputBuffer[1] == '\0'){
                printf("\nThank you for shopping with us! Ending program.");
                loadingDot();
                runningProgram = false;
                break;
            } else {
                printf("\"%s\" is not a valid selection. Please enter a valid selection!\n", inputBuffer); 
                while (getchar() != '\n');
            }  
        }
    }return 0;
}
    
float calculatePrice(float totalPrice, float discount){
    printf("Calculating total...\n");
    float price = totalPrice * (1.0 - discount);
    return price;
}

float discountPrice(float finalPrice, float totalPrice){
    float discountedPrice = totalPrice - finalPrice;
    return discountedPrice;
}

void displayReceipt(char itemList[1000], float totalPrice, float finalPrice, float discountedPrice, char isMrHee, float discount){
    time_t currentTime;
    
    time(&currentTime); //Gets current calender time
    
    printf("\033[1;40;37m=========================================\033[0m\n");
    printf("\033[1;40;37m             OFFICIAL RECEIPT            \033[0m\n");
    printf("\033[1;40;37m=========================================\033[0m\n");
    if(isMrHee == 'Y' || isMrHee == 'y'){
        printf("\033[1;40;37m Customer: Mr. Hee (VIP)\033[0m\n");
    } else {
        printf("\033[1;40;37m Customer: Guest\033[0m\n");
    }
    printf("\033[1;40;37m Date: %s\033[0m", ctime(&currentTime));
    printf("\033[1;40;37m-----------------------------------------\033[0m\n");
    printf("\033[1;40;37m Item purchased: \033[0m\n");
    printf("\033[1;40;37m%s \033[0m\n", itemList);
    printf("\033[1;40;37m-----------------------------------------\033[0m\n");
    printf("\033[1;40;37m Subtotal: $%.2f\033[0m\n", totalPrice);
    printf("\033[1;40;37m Total Discount: %.1f%%\033[0m\n", discount * 100);
    printf("\033[1;40;37m Total Saved: -$%.2f\033[0m\n", discountedPrice);
    printf("\033[1;40;37m-----------------------------------------\033[0m\n");
    printf("\033[1;40;37m Final Total: $%.2f\033[0m\n", finalPrice);
    printf("\033[1;40;37m=========================================\033[0m\n");
    printf("\033[1;40;37m Thank you for shopping with us!\033[0m\n");
    printf("\033[1;40;37m=========================================\033[0m\n");
    
}

void printHeader(void){
    
    printf("\033[1;40;37m=========================================\033[0m\n");
    printf("\033[1;40;37m        FRANCO'S SEIKO BOUTIQUE          \033[0m\n");
    printf("\033[1;40;37m=========================================\033[0m\n");
    printf("Welcome to Franco's Seiko Boutique!\n");
    printf("Use code '\033[1;4;40;37mMRHEE77\033[0m' on checkout to get 5%% off your order!\n");
}

void loadingDot(void){
    Sleep(500);
    printf(".");
    Sleep(500);
    printf(".");
}

