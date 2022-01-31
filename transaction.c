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

    if (saveTransactionOk(tran,"REGISTER")){
        if(saveTransaction(tran)){
            fileSucess();
        }
    }else{
        saveCanceled();
    }
    free(tran);
}

// void showTransactionDetails(Transaction* tran){

// }



//(read)
int transactionList(){
    FILE* fp;
    fp = fopen("transactions.dat","rb");

    if (fp == NULL){
        fileError();
        return 0;
    }

    Transaction* tran;
    tran = (Transaction*) malloc(sizeof(Transaction));

    
    while(fread(tran,sizeof(Transaction),1,fp)){
        showTransaction(tran);
    }
    free(tran);
    fclose(fp);
    return 1;
}
 
int saveTransaction(Transaction* tran){
    FILE* fp;
    fp = fopen("transactions.dat","ab");

    if (fp == NULL){
        fileError();
        return 0;
    }
    fwrite(tran,sizeof(Transaction),1,fp);
    fclose(fp);
    return 1;
}

//(createFill)
Transaction* createTransactionFill(void){

    Transaction* tran;
    tran = (Transaction*) malloc(sizeof(Transaction));
    char value[11];
    bool ok;

    //define id
    tran->id = (fileLen("transactions.dat")/sizeof(Transaction));
    
    printf("\t!!!!!!!!!! If any invalid value is entered, the field will be asked again !!!!!!!!!!\n");
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
        printf("\n                 = = = = = = Type of transaction = = = = = =                  \n\n");
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
int saveTransactionOk(Transaction* tran, char* operation){
    char dw[11];
    tran->DW == 'd' ? strcpy(dw,"DEPOSIT") : strcpy(dw,"WITHDRAWAL");

    printf("\n\n");
    printf("\t            = = = = = = Register Transaction = = = = = =               \n\n");

    printf("\n\tDo you really want to %s %s of R$ %.3f made by XXX ?\n", operation, dw, tran->value);
    printf("\tID: %ld",tran->id);
    printf("\n\t");
    printfDateTime(tran->time,tran->date);
    printf("\tDescription: %s\n", tran->description);
    printf("\n");

    return yesOrNo();
}

//(readByID)
void detailTransaction(){
    long int id;
    Transaction* tran;
    char dw[11];

    printf("\n\tWhich transaction ID you want to see detailed: ");
    scanf("%ld", &id);
    getchar();

    tran = findTransaction(&id);
    if (tran == NULL || tran->deleted == 1){
        registerNotFound();
    }else{
        tran->DW == 'd' ? strcpy(dw,"DEPOSIT") : strcpy(dw,"WITHDRAWAL");
        printf("\n\n\t\t= = = = = Registered Transaction = = = = =");
        printf("\nID: %ld",tran->id); //printf("Made by: %s",nameOfUser);
        printf("\n%s: $%.3lf",dw,tran->value);
        printf("\n"); printfDateTime(tran->time,tran->date);
        //print("\n%s",type)
        printf("\nDescription: %s",tran->description);
        printf("\nCreation time: %s | Creation date: %s",tran->creationTime,tran->creationDate);
        printf("\n\n\t\t\t>>> Press ENTER to continue <<<");
        getchar();
    }
    free(tran);
    
    printf("\n");

}

void showTransaction(Transaction* tran){
    if (tran->deleted == 0){
        char dw[11];
        tran->DW == 'd' ? strcpy(dw,"DEPOSIT") : strcpy(dw,"WITHDRAWAL");

        printf("\n\n\t\t= = = = = Registered Transaction = = = = =");
        printf("\nID: %ld",tran->id);//printf("Made by: %s",nameOfUser);
        printf("\n%s: $%.3lf",dw,tran->value);
        //printf("\n%s",type);
        printf("\n");
        printfDateTime(tran->time,tran->date);

    }else if(tran == NULL){
        printf("\t\n= = = = = Non-existent Transaction = = = = =");
    }
}

//(update)
void updateTransaction(){

    long int id;
    Transaction* tran;
    char value[11];
    bool ok;

    printf("                 = = = = = = Update Transaction = = = = = =                  \n\n");
    printf("\nWhich transaction ID do you want to be updated: ");    
    scanf("%ld", &id);
    getchar();

    tran = findTransaction(&id);

    if(tran == NULL){
        registerNotFound();
    }else{  
            do{
            printf("\n           User's CPF (only numbers): ");
            fgetsS(tran->userCPF,12);
            getchar();
            //TODO: check if userCPF is registered in the users
        } while (!(validateCPF(tran->userCPF)));

        do{
            printf("\n           Deposit or Withdrawal (d/w): ");
            scanf("%c", &tran->DW);
            getchar();
            
        } while (!(dOrW(tran->DW)));
        
        do{
            ok = true;
            printf("\n           Value no signal (532.25): ");
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
            printf("\n           Date (DDMMAAAA): ");
            scanf("%s", tran->date);
            getchar();
            
        } while (!(validateDate(tran->date)));
        
        do{
            printf("\n           Time (HH MM): ");
            fgetsS(tran->time,6);
            getchar();
            
        } while (!(validateTime(tran->time)));

        printf("\n           Description (size=100):\n");
        fgetsS(tran->description,101);

        do{
            printf("\n                 = = = = = = Type of transaction = = = = = =                  \n\n");
            //typeList();
            printf("\n///           Choose ID of Type:                                          ///\n");
            scanf("%ld", &tran->typeID);
            getchar();
        } while (/* TODO: check if typeID is registered in types */ false);

        if(saveTransactionOk(tran,"UPDATE")){           
            if(resaveTransaction(tran)){
                fileSucess(); 
            }else{
                saveCanceled();
            }
        }
        free(tran);
    }

}

//(delete)
void deleteTransaction(){
    long int id;
    Transaction* tran;

    printf("\nWhich transaction ID do you want to be deleted: ");    
    scanf("%ld", &id);
    getchar();

    tran = findTransaction(&id);
    if (tran == NULL){
        registerNotFound();
    }else{
        if(saveTransactionOk(tran,"DELETE")){
            tran->deleted = 1;
            if(resaveTransaction(tran)){
                fileSucess();  
            }
        }
    }
    free(tran);
}

int resaveTransaction(Transaction* tran){
    FILE* fp;
    fp = fopen("transactions.dat","r+b");
    bool find = false;

    if (fp == NULL){
        fileError();
        return find;
    }
    Transaction* tranRead;
    tranRead = (Transaction*) malloc(sizeof(Transaction));

    while (fread(tranRead,sizeof(Transaction),1,fp) && !find){
        if(tranRead->id == tran->id && tranRead->deleted == 0){
            find = true;
            fseek(fp, -1*sizeof(Transaction), SEEK_CUR);
            fwrite(tran,sizeof(Transaction),1,fp);    
        }
    }
    fclose(fp);
    free(tranRead);
    return find;
}

Transaction* findTransaction(long int* id){
    FILE* fp;
    Transaction* tran;

    fp = fopen("transactions.dat","rb");

    if (fp == NULL){
        fileError();
        return NULL;
    }

    tran = (Transaction*) malloc(sizeof(Transaction));

    while (fread(tran,sizeof(Transaction),1,fp)){   
        if(tran->id == *id && tran->deleted == 0){
            fclose(fp);
            return tran;
        }
    }

    fclose(fp);
    return NULL; 
}
