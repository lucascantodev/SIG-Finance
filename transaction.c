#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

#include "transaction.h"
#include "type.h"
#include "validations.h"

//typedef struct transaction Transaction;

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
void createTransaction(void){

    Transaction* tran;
    tran = createTransactionFill();
    int aux = createdTransactionOk(tran);

    if (aux == 1){
        //TODO: save in the file and print "Sucess"
    }else{
        printf("\t\t\t<<<<<<<< Registration Canceled >>>>>>>>\n");
    }

    free(tran);
}

//(createFill)
Transaction* createTransactionFill(void){
    Transaction* tran;
    tran = (Transaction*) malloc(sizeof(Transaction));

    char date[11];
    char hour[6];
    char value[11];
    bool ok;

    //TODO: tran->id
    printf("\t!!!!!!!!!! if any invalid value is entered, the field will be asked again !!!!!!!!!!\n");
    printf("\n/////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                       ///\n");
    printf("///            = = = = = = Register Transaction = = = = = =               ///\n");
    printf("///                                                                       ///\n");
    do
    {
        printf("///           User's CPF (only numbers):                                  ///\n");
        fgets(tran->userCPF,12,stdin);
        getchar();
        //TODO: check if userCPF is registered in the users
    } while (!(validateCPF(tran->userCPF)));

    do
    {
        printf("///           Deposit or Withdrawal (d/w):                                ///\n");
        scanf("%c", &tran->DW);
        getchar();
        
    } while (!(dOrW(tran->DW)));
    
    do
    {
        ok = true;
        printf("///           Value no signal (532.25):                                    ///\n");
        fgets(value,11,stdin);

        for (int i = 0; i < strlen(value)-1; i++)
        {
            if(isDigitOrPoint(value[i]) == 0 ){
                ok = false;
                break;
            }
        }
        if(ok == true){
            tran->value = atof(value);
            break;
        }
    } while (true);

    

    do
    {
        printf("///           Date (DDMMAAAA):                                            ///\n");
        scanf("%s", tran->date);
        getchar();
        
    } while (!(validateDate(tran->date)));
    

    do
    {
        printf("///           Time (HH MM):                                               ///\n");
        fgets(tran->time,6,stdin);
        //printf("salvei");
        getchar();
        
    } while (!(validateTime(tran->time)));
    


    printf("///           Description (size=100):                                     ///\n");
    scanf("%s", tran->description);
    getchar();


    do
    {
        printf("///           Type of transactions:                                        ///\n");
        typeList();
        printf("\n///           Choose ID of Type:                                          ///\n");
        scanf("%ld", &tran->typeID);
        getchar();
    } while (/* TODO: check if typeID is registered in types */ false);
    

    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n\n");
    
    tran->deleted = 0;
    currentTime(date,hour);
    strcpy(tran->creationDate,date);
    strcpy(tran->creationTime,hour);

    return tran;

}
//(createCheck)
int createdTransactionOk(Transaction* tran){
    char dw[11];
    char yn;
    tran->DW == 'd' ? strcpy(dw,"DEPOSIT") : strcpy(dw,"WITHDRAWAL");

    printf("\n\n");
    printf("\t            = = = = = = Register Transaction = = = = = =               \n\n");

    printf("\n\t Do you really want to register %s of R$ %.3f made by XXX ?\n", dw, tran->value);
    printf("\t Description: %s\n", tran->description);
    printf("\n");

    do{
        printf("Type (y) for yes or (n) for no: \n");
        scanf("%c",&yn);
        getchar();

        if (yn == 'y'){
            return 1;
        }else if (yn == 'n'){
            return 0;
        }
    } while (true);
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

    printf("\n\tWhich transaction ID you want to see detailed: ");
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

}

//(delete)
void deleteTransaction(){
    int id;

    printf("Which transaction ID do you want to be deleted :");    
    scanf("%d", &id);
    getchar();
    printf("\n");

}