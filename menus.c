#include <stdio.h>
#include <stdlib.h>

//screens
void welcome(void);
void about(void);
void team(void);
void mainScreen(void);

//CRUD: Transactions
void transactionMenu(void);
void createTransaction(void);
void transactionList(void);
void detailTransaction(void);
void updateTransaction(void);
void deleteTransaction(void);

//CRUD: Types
void typeMenu(void);
void createType(void);

int main(){
    welcome();
    about();
    team();
    mainScreen();

    transactionMenu();
    createTransaction();
    transactionList();
    detailTransaction();
    updateTransaction();
    deleteTransaction();

    typeMenu();
    createType();
    return 0;
}

void welcome(){
    printf("\n");
	printf("          __          __       _                                 _ \n          \\ \\        / /      | |                               | |\n           \\ \\  /\\  / /   ___ | |  ___   ___   _ __ ___    ___  | |\n            \\ \\/  \\/ /   / _ \\| | / __| / _ \\ | '_ ` _ \\  / _ \\ | |\n             \\  /\\  /   |  __/| || (__ | (_) || | | | | ||  __/ |_|\n              \\/  \\/     \\___||_| \\___| \\___/ |_| |_| |_| \\___| (_)\n");
    printf("\n");
}

void about(){
	printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
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
    printf("///////////////////////////////////////////////////////////////////////////////\n");
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

void mainScreen(void) {
    char op;

    printf("\n");
	printf("///////////////////////////////////////////////////////////////////////////////////\n");
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
    printf("///                                                                            ///\n");
	printf("/// | /////////// | /////////// | /////////// | /////////// | /////////// | ////////\n");
	printf("////////////////////////////////////////////////////////////////////////////////////\n");
    printf("\t\t\tChoose an option: ");
    scanf("%c", &op);
    getchar();
    printf("\n");
}

//transaction module
void transactionMenu() {
    char op;

    printf("\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                       ///\n");
    printf("///               = = = = = = = = = = = = = = = = = = = =                 ///\n");
    printf("///           = = = = = = = =  Transaction Menu = = = = = = =             ///\n");
    printf("///               = = = = = = = = = = = = = = = = = = = =                 ///\n");
    printf("///                                                                       ///\n");
    printf("///              1. Register new transaction                              ///\n");
    printf("///              2. Transactions list                                     ///\n");
    printf("///              3. Detail transaction                                    ///\n");
    printf("///              4. Update transaction                                    ///\n");
    printf("///              5. Delete transaction                                    ///\n");
    printf("///              0. Back to main menu                                     ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\tChoose an option: ");
    scanf("%c", &op);
    getchar();
    printf("\n");
}

//(create)
void createTransaction(){
    char name[31];
    char DW;
    float value;
    char description[101];

    printf("\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                       ///\n");
    printf("///            = = = = = = Register Transaction = = = = = =               ///\n");
    printf("///                                                                       ///\n");
    printf("///           Your name:                                                  ///\n");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÃÕ a-záéíóúâêôçãõ]", name); //adapted from @flgorgonio
    getchar();
    printf("///           Deposit or Withdrawal (D/W):                                ///\n");
    scanf("%c", &DW);
    getchar();
    printf("///           Value (no signal):                                          ///\n");
    scanf("%f", &value);
    getchar();
    printf("///           Description:                                                ///\n");
    scanf("%s", description);
    getchar();
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");

    //Deposit
    // printf("\n");
    // printf("/////////////////////////////////////////////////////////////////////////////\n");
    // printf("///                                                                       ///\n");
    // printf("///            = = = = = = Register Transaction = = = = = =               ///\n");
    // printf("///                                                                       ///\n");
    // printf("///                 The deposit registration made by XXX                  ///\n");
    // printf("///                       of +R$ XXX was sucessful!                       ///\n");
    // printf("///                                                                       ///\n");
    // printf("///     Description: texttexttexttexttexttexttexttexttexttext.            ///\n");
    // printf("///                                                                       ///\n");
    // printf("/////////////////////////////////////////////////////////////////////////////\n");
    // printf("\n");

    // //Withdrawal
    // printf("\n");
    // printf("/////////////////////////////////////////////////////////////////////////////\n");
    // printf("///                                                                       ///\n");
    // printf("///            = = = = = = Register Transaction = = = = = =               ///\n");
    // printf("///                                                                       ///\n");
    // printf("///                 The withdrawal registration made by XXX               ///\n");
    // printf("///                       of -R$ XXX was sucessful!                       ///\n");
    // printf("///                                                                       ///\n");
    // printf("///     Description: texttexttexttexttexttexttexttexttexttext.            ///\n");
    // printf("///                                                                       ///\n");
    // printf("/////////////////////////////////////////////////////////////////////////////\n");
    // printf("\n");
}

//(read)
void transactionList(){
    printf("\n");
    printf("\t\t========== Trasaction List ==========");
    printf("\n");
    printf("\t\tTODO: loop to show each transaction");
    printf("\n");
    //TODO: loop to show each transaction
}

//(readByID)
void detailTransaction(){
    char id;

    printf("\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                       ///\n");
    printf("///            = = = = = = Detail Transaction = = = = = =                 ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("Which transaction ID you want to see detailed: ");
    scanf("%c", &id);
    getchar();
    printf("\n");

    // printf("/////////////////////////////////////////////////////////////////////////////\n");
    // printf("///                                                                       ///\n");
    // printf("///            = = = = = = Detail Transaction = = = = = =                 ///\n");
    // printf("///         _________________________________________                     ///\n");
    // printf("///         |  ID: XX                               |                     ///\n");
    // printf("///         |  Name: XXXXX                          |                     ///\n");
    // printf("///         |  Deposit or Withdrawal (D/W): D or W  |                     ///\n");
    // printf("///         |  Value: +R$ XXX or -R$ XXX            |                     ///\n");
    // printf("///         |  Description: texttexttexttextte      |                     ///\n");
    // printf("///         |_______________________________________|                     ///\n");
    // printf("///                                                                       ///\n");
    // printf("///                                                                       ///\n");
    // printf("/////////////////////////////////////////////////////////////////////////////\n");
    // printf("\n");
}

//(update)
void updateTransaction(){
    char name[31];
    char DW;
    float value;
    char description[101];

    printf("\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                       ///\n");
    printf("///              = = = = = = Update Transaction = = = = = =               ///\n");
    printf("///                                                                       ///\n");
    printf("///           Your name:                                                  ///\n");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÃÕ a-záéíóúâêôçãõ]", name); //adapted from @flgorgonio
    getchar();
    printf("///           Deposit or Withdrawal (D/W):                                ///\n");
    scanf("%c", &DW);
    getchar();
    printf("///           Value (no signal):                                          ///\n");
    scanf("%f", &value);
    getchar();
    printf("///           Description:                                                ///\n");
    scanf("%s", description);
    getchar();
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");

    // printf("/////////////////////////////////////////////////////////////////////////////\n");
    // printf("///                                                                       ///\n");
    // printf("///              = = = = = = Update Transaction = = = = = =               ///\n");
    // printf("///                                                                       ///\n");
    // printf("///               Transaction ID X was updated successfully !             ///\n");
    // printf("///                                                                       ///\n");
    // printf("/////////////////////////////////////////////////////////////////////////////\n");
    // printf("\n");

}

//(delete)
void deleteTransaction(){
    char id;

    printf("\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                       ///\n");
    printf("///            = = = = = = Delete Transaction = = = = = =                 ///\n");
    printf("///                                                                       ///\n");
    printf("///           Please enter the transaction ID to remove it                ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("Which transaction ID do you want to deleted :");    
    scanf("%c", &id);
    getchar();
    printf("\n");

    // printf("/////////////////////////////////////////////////////////////////////////////\n");
    // printf("///                                                                       ///\n");
    // printf("///            = = = = = = Delete Transaction = = = = = =                 ///\n");
    // printf("///                                                                       ///\n");
    // printf("///                                                                       ///\n");
    // printf("///             Transaction (ID X) deleted successfully!                  ///\n");
    // printf("///                                                                       ///\n");
    // printf("///                                                                       ///\n");
    // printf("///                                                                       ///\n");
    // printf("/////////////////////////////////////////////////////////////////////////////\n");
    // printf("\n");
}

//type module
void typeMenu() {
    char op;

    printf("\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                       ///\n");
    printf("///               = = = = = = = = = = = = = = = = = = = =                 ///\n");
    printf("///            = = = = = = Transaction Type Menu = = = = = =              ///\n");
    printf("///               = = = = = = = = = = = = = = = = = = = =                 ///\n");
    printf("///                                                                       ///\n");
    printf("///              1. Create new type                                       ///\n");
    printf("///              2. Type list                                             ///\n");
    printf("///              3. Update a type                                         ///\n");
    printf("///              4. Delete a type                                         ///\n");
    printf("///              0. Back to main menu                                     ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\tChoose an option: ");
    scanf("%c", &op);
    getchar();
    printf("\n");
}

void createType(){
    char name[21];

    printf("\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                       ///\n");
    printf("///              = = = = = = = = Create Type = = = = = = = =              ///\n");
    printf("///                                                                       ///\n");
    printf("///           Type name:                                                  ///\n");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÃÕ a-záéíóúâêôçãõ]", name); //adapted from @flgorgonio
    getchar();
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}