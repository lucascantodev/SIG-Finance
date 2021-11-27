#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "transaction.h"
#include "user.h"
#include "type.h"

//screens
void welcome(void);
void about(void);
void team(void);
char mainScreen(void);

int main(){
    welcome();
    about();
    team();

    char op;
    bool isValid = true; 
    do{
        op = mainScreen();
        switch (op){
            case '1':
                transactionMenu();
                break;
            case '2':
                userMenu();
                break;
            case '3':
                typeMenu();
                break;
            case '4':
                about();
                team();
                break;
            case '0':
                isValid = false; 
                break;
            default:
                printf("\t\t\t============================\n");
                printf("\t\t\t====== Invalid option ======\n");
                printf("\t\t\t============================\n\n");
                printf("\t\t\t>>>> Choose a valid option <<<<\n");
        }
    }while(isValid);
    printf("\n\t\t\t===================================\n");
    printf("\t\t\t====== The program has ended ======\n");
    printf("\t\t\t===================================\n");

    return 0;
}

void welcome(){
    printf("\n");
	printf("          __          __       _                                 _ \n          \\ \\        / /      | |                               | |\n           \\ \\  /\\  / /   ___ | |  ___   ___   _ __ ___    ___  | |\n            \\ \\/  \\/ /   / _ \\| | / __| / _ \\ | '_ ` _ \\  / _ \\ | |\n             \\  /\\  /   |  __/| || (__ | (_) || | | | | ||  __/ |_|\n              \\/  \\/     \\___||_| \\___| \\___/ |_| |_| |_| \\___| (_)\n");
    printf("\n");
    printf("\t\t\t>>> Press ENTER to continue <<<");
    getchar();
}

void about(){
    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///               Federal University of Rio Grande do Norte                 ///\n");
    printf("///                Center for Higher Education of the Seridó               ///\n");
    printf("///               Department of Computation and Technology                  ///\n");
    printf("///                  Discipline DCT1106 -- Programming                      ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///  = = = = = Household Finance Control System Project - 2021  = = = = =   ///\n");
    printf("///                                                                         ///\n");
    printf("///    Application developed for the discipline DCT1106 - Programming       ///\n");
    printf("///    The objective of this project is to develop an application that      ///\n");
    printf("///    monitors the financial flow in a home and avoids                     ///\n");
    printf("///    the lack of control of expenses.                                     ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n\n");
    printf("\t\t\t>>> Press ENTER to continue <<<");
    getchar();
}

void team(){
	printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                              Developed by:                              ///\n");
    printf("///                                                                         ///\n");
    printf("///             Lucas Canto           &           Jonathan Maia             ///\n");
    printf("///             @lucascantodev                  @jonathan-tauan             ///\n");
	printf("///                                                                         ///\n");
    printf("///        Repository: https://github.com/lucascantodev/SIG-Finance         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n\n");
    printf("\t\t\t>>> Press ENTER to continue <<<\n");
    getchar();
}

char mainScreen() {
    char op;

	printf("\n///////////////////////////////////////////////////////////////////////////////////\n");
	printf("/// | /////////// | /////////// | /////////// | /////////// | /////////// | ///////\n");
	printf("///           ||||||===========|=============|==============||||||             ///\n");
	printf("///////       ||||||||||||||||||||||||||||||||||||||||||||||||||||          //////\n");
	printf("///           |= = = = = = = = = = = = = = = = = = = = = = = = = =|            ///\n");
	printf("///         |= = = =               SIG-FINANCE               = = = =|          ///\n");
	printf("///        |= = = =            Take control of your           = = = =|         ///\n");
	printf("///         |= = = =        Household Expenses Today!        = = = =|          ///\n");
	printf("///           |= = = = = = = = = = = = = = = = = = = = = = = = = =|            ///\n");
	printf("///                                                                            ///\n");
	printf("///               Developed by Lucas Canto and Jonathan Maia                   ///\n");
  	printf("///                                                                            ///\n");
	printf("//////////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                            ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =                  ///\n");
	printf("///         = = = = = = = = =  Start Menu  = = = = = = = = = =                 ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =                  ///\n");
	printf("///                 ______________________________                             ///\n");
    printf("///                |  1. Transaction Module       |                            ///\n");
    printf("///                |  2. User Module              |                            ///\n");
    printf("///                |  3. Transaction Type Module  |                            ///\n");
    printf("///                |  4. About Module             |                            ///\n");    
    printf("///                |  0. Exit                     |                            ///\n");
    printf("///                |______________________________|                            ///\n");
    printf("///                                                                            ///\n");
	printf("/// | /////////// | /////////// | /////////// | /////////// | /////////// | ////////\n");
	printf("////////////////////////////////////////////////////////////////////////////////////\n\n");
    printf("\t\t\tChoose an option: ");
    scanf("%c", &op);
    getchar();
    printf("\n");
    return op;
}