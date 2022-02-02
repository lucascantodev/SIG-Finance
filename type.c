#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "type.h"
#include "validations.h"

//type module
void typeMenu() {
    char op;
    bool isValid = true; 
    
    do{
        printf("\n/////////////////////////////////////////////////////////////////////////////\n");
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
        printf("/////////////////////////////////////////////////////////////////////////////\n\n");
        printf("\t\t\tChoose an option: ");
        scanf("%c", &op);
        getchar();
        printf("\n");

        switch (op){
            case '1':
                createType();
                break;
            case '2':
                typeList();
                break;
            case '3':
                updateType();
                break;
            case '4':
                deleteType();
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

void createType(void){
    Type* type;
    type = createTypeFill();

    if(saveTypeOk(type,"REGISTER")){
        if(saveType(type)){
            fileSucess();
        }
    }else{
        saveCanceled();
    }

    free(type);
}

int saveType(Type* type){
    FILE* fp;
    fp = fopen("types.dat","ab");

    if (fp == NULL){
        fileError();
        return 0;
    }
    fwrite(type,sizeof(Type),1,fp);
    fclose(fp);
    return 1;
}

//(createFill)
Type* createTypeFill(){

    Type* type;
    type = (Type*) malloc(sizeof(Type));

    type->id = (fileLen("types.dat")/sizeof(Type));

    printf("\n/////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                       ///\n");
    printf("///              = = = = = = = = Create Type = = = = = = = =              ///\n");
    printf("///                                                                       ///\n");
    printf("///           Type name:                                                  ///\n");
    fgetsS(type->name,21); //adapted from @flgorgonio
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n\n");
    type->deleted = 0;
    return type;
}

int saveTypeOk(Type* type, char* operation){
    printf("\n\n");
    printf("\t            = = = = = = %s TYPE = = = = = =               \n\n",operation);

    printf("\n\t Do you really want to %s %s type ?\n",operation, type->name);
    printf("\n");

    return yesOrNo();
}

//(read)
int typeList(){
    FILE* fp;
    fp = fopen("types.dat","rb");

    if (fp == NULL){
        fileError();
        return 0;
    }

    Type* type;
    type = (Type*) malloc(sizeof(Type));

    while (fread(type,sizeof(Type),1,fp)){
        if(type->deleted != 1){
            printf("\n\t\t= = = = = Registered Type = = = = =");
            printf("\nType name: %s | ID: %ld",type->name,type->id);
        }else if(type == NULL){
            printf("\t\n= = = = = Non-existent Type = = = = =");
        }
    }
    
    free(type);
    fclose(fp);
    return 1;
}

//(update)
void updateType(){
    long int id;
    Type* type;

    printf("                 = = = = = = Update Type = = = = = =                  \n\n");
    printf("\nWhich type ID do you want to be updated: ");    
    scanf("%ld",&id);
    getchar();

    type = findType(&id);
    if(type == NULL){
        registerNotFound();
    }else{
        printf("\n           Type name: \n");
        fgetsS(type->name,21);

        if(saveTypeOk(type,"UPDATE")){
            if(resaveType(type)){
                fileSucess();
            }else{
                fileError();
            }
        }else{
            saveCanceled();
        }
        free(type);
    }

}

Type* findType(long int* id){
    FILE* fp;
    Type* type;

    fp = fopen("types.dat","rb");

    if (fp == NULL){
        fileError();
        return NULL;
    }

    type = (Type*) malloc(sizeof(Type));

    while (fread(type,sizeof(Type),1,fp)){
        if(type->id == *id && type->deleted == 0){
            fclose(fp);
            return type;
        }
    }   
    fclose(fp);
    return NULL;
}

//(delete)
void deleteType(){
    long int id;
    Type* type;

    printf("\nWhich type ID do you want to be deleted: ");    
    scanf("%ld", &id);
    getchar();

    type = findType(&id);
    if (type == NULL){
        registerNotFound();
    }else{
        if (saveTypeOk(type,"DELETE")){
            type->deleted = 1;
            if (resaveType(type)){
                fileSucess();
            }else{
                fileError();
            }
        }else{
            saveCanceled();
        }
        
        free(type);
    }
}

int resaveType(Type* type){
    FILE* fp;
    fp = fopen("types.dat","r+b");
    bool find = false;

    if (fp == NULL){
        fileError();
        return find;
    }

    Type* typeRead;
    typeRead = (Type*) malloc(sizeof(Type));

    while (fread(typeRead,sizeof(Type),1,fp) && !find){
        if (typeRead->id == type->id && typeRead->deleted == 0){
            find = true;
            fseek(fp,-1*sizeof(Type),SEEK_CUR);
            fwrite(type,sizeof(Type),1,fp);
        }
    }
    fclose(fp);
    free(typeRead);
    return find;
}