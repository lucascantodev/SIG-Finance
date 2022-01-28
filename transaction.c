#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

#include "transaction.h"
#include "type.h"
#include "validations.h"

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

    if (createdTransactionOk(tran)){
        if(saveTransaction(tran)){
            fileSucess();
        }
    }else{
        saveCanceled();
    }
    free(tran);
}

//(read)
int transactionList(){
    FILE* fp;
    fp = fopen("transactions.txt","rt");
    char line;

    if (fp == NULL){
        fileError();
        return 0;
    }

    printf("\n\t\t========== Transaction List ==========\n\n");

    line = fgetc(fp);

    while (line != EOF){    
        printf("%c", line);
        line = fgetc(fp);
    }
    
    fclose(fp);
    return 1;
}

int saveTransaction(Transaction* tran){
    FILE* fp;
    fp = fopen("transactions.txt","at");

    if (fp == NULL){
        fileError();
        return 0;
    }
    fprintf(fp,"<< Recorded Transaction >>\n");
    fprintf(fp,"D or W: %c\n",tran->DW);
    fprintf(fp,"Value: %f\n",tran->value);
    fprintf(fp,"Description: %s\n",tran->description);
    fclose(fp);
    return 1;
}

//(createFill)
Transaction* createTransactionFill(void){

    Transaction* tran;
    tran = (Transaction*) malloc(sizeof(Transaction));
    char value[11];
    bool ok;

    //TODO: tran->id
    printf("\t!!!!!!!!!! if any invalid value is entered, the field will be asked again !!!!!!!!!!\n");
    printf("\n/////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                       ///\n");
    printf("///            = = = = = = Register Transaction = = = = = =               ///\n");
    printf("///                                                                       ///\n");
    do{
        printf("///           User's CPF (only numbers):                                  ///\n");
        fgetsS(tran->userCPF,12);
        getchar();
        //TODO: check if userCPF is registered in the users
    } while (!(validateCPF(tran->userCPF)));

    do{
        printf("///           Deposit or Withdrawal (d/w):                                ///\n");
        scanf("%c", &tran->DW);
        getchar();
        
    } while (!(dOrW(tran->DW)));
    
    do{
        ok = true;
        printf("///           Value no signal (532.25):                                    ///\n");
        fgetsS(value,11);

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

    do{
        printf("///           Date (DDMMAAAA):                                            ///\n");
        scanf("%s", tran->date);
        getchar();
        
    } while (!(validateDate(tran->date)));
    
    do{
        printf("///           Time (HH MM):                                               ///\n");
        fgetsS(tran->time,6);
        getchar();
        
    } while (!(validateTime(tran->time)));

    printf("///           Description (size=100):                                     ///\n");
    fgetsS(tran->description,101);

    do{
        printf("///           Type of transactions:                                      ///\n");
        //typeList();
        printf("\n///           Choose ID of Type:                                          ///\n");
        scanf("%ld", &tran->typeID);
        getchar();
    } while (/* TODO: check if typeID is registered in types */ false);
    
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n\n");
    
    tran->deleted = 0;
    currentTime(tran->creationDate,tran->creationTime);

    return tran;
}
//(createCheck)
int createdTransactionOk(Transaction* tran){
    char dw[11];
    tran->DW == 'd' ? strcpy(dw,"DEPOSIT") : strcpy(dw,"WITHDRAWAL");

    printf("\n\n");
    printf("\t            = = = = = = Register Transaction = = = = = =               \n\n");

    printf("\n\t Do you really want to register %s of R$ %.3f made by XXX ?\n", dw, tran->value);
    printf("\t Description: %s\n", tran->description);
    printf("\n");

    return yesOrNo();
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