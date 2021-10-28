#include <stdio.h>
#include <stdlib.h>

//screens
void welcome(void);
void mainScreen(void);
void team(void);
void about(void);

//CRUD: Transactions
void createTransaction(void);
void detailTransaction(void);
void updateTransaction(void);
void deleteTransaction(void);

int main(){
    welcome();
    team();
    about();
    mainScreen();

    createTransaction();
    detailTransaction();
    updateTransaction();
    deleteTransaction();
    return 0;
}

void welcome(){
    printf("\n");
	printf("          __          __       _                                 _ \n          \\ \\        / /      | |                               | |\n           \\ \\  /\\  / /   ___ | |  ___   ___   _ __ ___    ___  | |\n            \\ \\/  \\/ /   / _ \\| | / __| / _ \\ | '_ ` _ \\  / _ \\ | |\n             \\  /\\  /   |  __/| || (__ | (_) || | | | | ||  __/ |_|\n              \\/  \\/     \\___||_| \\___| \\___/ |_| |_| |_| \\___| (_)\n");
    printf("\n");
}

void mainScreen(void) {
    printf("\n");
	printf("///////////////////////////////////////////////////////////////////////////////////\n");
	printf("///////////////////////////////////////////////////////////////////////////////////\n");
	printf("/// | /////////// | /////////// | /////////// | /////////// | /////////// | ///////\n");
	printf("///           ||||||===========|=============|==============||||||             ///\n");
	printf("///////       ||||||||||||||||||||||||||||||||||||||||||||||||||||          //////\n");
	printf("///          |= = = = = = = = = = = = = = = = = = = = = = = = = =|             ///\n");
	printf("///         |= = = =           SIG-FINANCE                 = = = =|            ///\n");
	printf("///        |= = = =         Take control of your            = = = =|           ///\n");
	printf("///        |= = = =      household expenses today!          = = = =|           ///\n");
	printf("///           |= = = = = = = = = = = = = = = = = = = = = = = = =|              ///\n");
	printf("///          |===================================================|             ///\n");
	printf("///               Developed by Lucas Canto and Jonathan Maia                   ///\n");
  	printf("///                                                                            ///\n");
	printf("//////////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                            ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =                  ///\n");
	printf("///         = = = = = = = = =  Start Menu  = = = = = = = = = =                 ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =                  ///\n");
	printf("///                 ______________________________                             ///\n");
	printf("///                |  1. View history             |                            ///\n");
    printf("///                |  2. Add/Remove a transaction |                            ///\n");
    printf("///                |  3. Change a transaction     |                            ///\n");
    printf("///                |  4. Exit                     |                            ///\n");
    printf("///                |______________________________|                            ///\n");
    printf("///                                                                            ///\n");
    printf("///                                                                            ///\n");
	printf("/// | /////////// | /////////// | /////////// | /////////// | /////////// | ////////\n");
    printf("////////////////////////////////////////////////////////////////////////////////////\n");
	printf("////////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}

void team(){
	printf("\n");
	printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                              Developed by:                              ///\n");
    printf("///                                                                         ///\n");
    printf("///             Lucas Canto           &           Jonathan Maia             ///\n");
    printf("///             @lucascantodev                  @jonathan-tauan             ///\n");
	printf("///                                                                         ///\n");
    printf("///        Repository: https://github.com/lucascantodev/SIG-Finance         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}

void about(){
	printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///               Federal University of Rio Grande do Norte                 ///\n");
    printf("///                Center for Higher Education of the Seridó                ///\n");
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
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}


void history(){

}

void createTransaction(){
    printf("\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                       ///\n");
    printf("///            = = = = = = Register Transaction = = = = = =               ///\n");
    printf("///                                                                       ///\n");
    printf("///           Your name:                                                  ///\n");
    printf("///           Deposit or Withdrawal (D/W):                                ///\n");
    printf("///           Value (no signal):                                          ///\n");
    printf("///           Description:                                                ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");

    //Deposit
    printf("\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                       ///\n");
    printf("///            = = = = = = Register Transaction = = = = = =               ///\n");
    printf("///                                                                       ///\n");
    printf("///                 The deposit registration made by XXX                  ///\n");
    printf("///                       of +R$ XXX was sucessful!                       ///\n");
    printf("///                                                                       ///\n");
    printf("///     Description: texttexttexttexttexttexttexttexttexttext.            ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");

    //Withdrawal
    printf("\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                       ///\n");
    printf("///            = = = = = = Register Transaction = = = = = =               ///\n");
    printf("///                                                                       ///\n");
    printf("///                 The withdrawal registration made by XXX               ///\n");
    printf("///                       of -R$ XXX was sucessful!                       ///\n");
    printf("///                                                                       ///\n");
    printf("///     Description: texttexttexttexttexttexttexttexttexttext.            ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}

//(readTransaction)
void detailTransaction(){
    printf("\n");
    history();
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                       ///\n");
    printf("///            = = = = = = Detail Transaction = = = = = =                 ///\n");
    printf("///         _________________________________________                     ///\n");
    printf("///         |  ID: XX                               |                     ///\n");
    printf("///         |  Name: XXXXX                          |                     ///\n");
    printf("///         |  Deposit or Withdrawal (D/W): D or W  |                     ///\n");
    printf("///         |  Value: +R$ XXX or -R$ XXX            |                     ///\n");
    printf("///         |_______________________________________|                     ///\n");
    printf("///                                                                       ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}

void updateTransaction(){
    printf("\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                       ///\n");
    printf("///              = = = = = = Update Transaction = = = = = =               ///\n");
    printf("///                                                                       ///\n");
    printf("///           Your name:                                                  ///\n");
    printf("///           Deposit or Withdrawal (D/W):                                ///\n");
    printf("///           Value (no signal):                                          ///\n");
    printf("///           Description:                                                ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");

    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                       ///\n");
    printf("///              = = = = = = Update Transaction = = = = = =               ///\n");
    printf("///                                                                       ///\n");
    printf("///               Transaction ID X was updated successfully !             ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");

}

void deleteTransaction(){
    printf("\n");
    history();
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                       ///\n");
    printf("///            = = = = = = Delete Transaction = = = = = =                 ///\n");
    printf("///                                                                       ///\n");
    printf("///                                                                       ///\n");
    printf("///           Please enter the transaction ID to remove it:               ///\n");
    printf("///                                                                       ///\n");
    printf("///                                                                       ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");

    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                       ///\n");
    printf("///            = = = = = = Delete Transaction = = = = = =                 ///\n");
    printf("///                                                                       ///\n");
    printf("///                                                                       ///\n");
    printf("///             Transaction (ID X) deleted successfully!                  ///\n");
    printf("///                                                                       ///\n");
    printf("///                                                                       ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}
