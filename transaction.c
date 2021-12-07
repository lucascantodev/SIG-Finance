#include <stdio.h>
#include <stdbool.h>
#include "transaction.h"

//transaction module
void transactionMenu() {
    char op;
    bool isValid = true;

    do{
        printf("\n/////////////////////////////////////////////////////////////////////////////\n");
        printf("///                                                                       ///\n");
        printf("///               = = = = = = = = = = = = = = = = = = = =                 ///\n");
        printf("///           = = = = = = = = Transaction Menu = = = = = = =              ///\n");
        printf("///               = = = = = = = = = = = = = = = = = = = =                 ///\n");
        printf("///                                                                       ///\n");
        printf("///              1. Register new transaction                              ///\n");
        printf("///              2. Transactions list                                     ///\n");
        printf("///              3. Detail transaction                                    ///\n");
        printf("///              4. Update transaction                                    ///\n");
        printf("///              5. Delete transaction                                    ///\n");
        printf("///              0. Back to main menu                                     ///\n");
        printf("///                                                                       ///\n");
        printf("/////////////////////////////////////////////////////////////////////////////\n\n");
        printf("\t\t\tChoose an option: ");
        scanf("%c", &op);
        getchar();
        printf("\n");

        switch (op){
            case '1':
                createTransaction();
                break;
            case '2':
                transactionList();
                break;
            case '3':
                detailTransaction();
                break;
            case '4':
                updateTransaction();
                break;
            case '5':
                deleteTransaction();
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
}

//(create)
void createTransaction(){
    char name[31];
    char DW;
    float value;
    char description[101];

    printf("\n/////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                       ///\n");
    printf("///            = = = = = = Register Transaction = = = = = =               ///\n");
    printf("///                                                                       ///\n");
    printf("///           User name:                                                  ///\n");
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
    printf("/////////////////////////////////////////////////////////////////////////////\n\n");

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
    printf("\n\t\t========== Transaction List ==========\n");
    printf("\t\tTODO: loop to show each transaction\n");
    //TODO: loop to show each transaction
}

//(readByID)
void detailTransaction(){
    int id;

    printf("\n/////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                       ///\n");
    printf("///            = = = = = = Detail Transaction = = = = = =                 ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n\n");
    printf("Which transaction ID you want to see detailed: ");
    scanf("%d", &id);
    getchar();
    //TODO: Show detailed transaction
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
    int id;
    char name[31];
    char DW;
    float value;
    char description[101];

    printf("\n/////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                       ///\n");
    printf("///              = = = = = = Update Transaction = = = = = =               ///\n");
    printf("///                                                                       ///\n");
    printf("///           Enter the ID of the transaction you want to update:         ///\n");
    scanf("%d",&id);
    getchar();
    printf("///           User name:                                                  ///\n");
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
    printf("/////////////////////////////////////////////////////////////////////////////\n\n");

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
    int id;

    printf("\n/////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                       ///\n");
    printf("///            = = = = = = Delete Transaction = = = = = =                 ///\n");
    printf("///                                                                       ///\n");
    printf("///           Please enter the transaction ID to remove it                ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n\n");
    printf("Which transaction ID do you want to be deleted :");    
    scanf("%d", &id);
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