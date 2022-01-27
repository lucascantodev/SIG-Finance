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

    if(createdTypeOK(type)){
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
    fp = fopen("types.h","at");

    if (fp == NULL){
        fileError();
        return 0;
    }
    fprintf(fp,"<< Recorded Type >>\n");
    fprintf(fp,"Name: %s\n",type->name);
    fclose(fp);
    return 1;
}

//(createFill)
Type* createTypeFill(){

    Type* type;
    type = (Type*) malloc(sizeof(Type));

    printf("\n/////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                       ///\n");
    printf("///              = = = = = = = = Create Type = = = = = = = =              ///\n");
    printf("///                                                                       ///\n");
    printf("///           Type name:                                                  ///\n");
    fgets(type->name,21,stdin); //adapted from @flgorgonio
    getchar();
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n\n");
    type->deleted = 0;
    return type;
}

int createdTypeOK(Type* type){
    printf("\n\n");
    printf("\t            = = = = = = Register Type = = = = = =               \n\n");

    printf("\n\t Do you really want to register type of %s ?\n", type->name);
    printf("\n");

    return yesOrNo();
}

//(read)
int typeList(){
    FILE* fp;
    fp = fopen("types.txt","rt");
    char line;

    if (fp == NULL){
        fileError();
        return 0;
    }
    printf("\n\t\t========== Type List ==========\n");

    line = fgetc(fp);

    while (line != EOF){    
        printf("%c", line);
        line = fgetc(fp);
    }
    
    fclose(fp);
    return 1;
}

//(update)
void updateType(){
    int id;
    char name[21];

    printf("\n/////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                       ///\n");
    printf("///              = = = = = = = = Update Type = = = = = = = =              ///\n");
    printf("///                                                                       ///\n");
    printf("///           Enter the ID of the type you want to update:                ///\n");
    scanf("%d",&id);
    getchar();
    printf("///           New type name:                                              ///\n");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÃÕ a-záéíóúâêôçãõ]", name); //adapted from @flgorgonio
    getchar();
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n\n");
}

//(delete)
void deleteType(){
    int id;

    printf("\n/////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                       ///\n");
    printf("///              = = = = = = = = Delete Type = = = = = = = =              ///\n");
    printf("///                                                                       ///\n");
    printf("///           Enter the ID of the type you want to delete:                ///\n");
    scanf("%d",&id);
    getchar();
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n\n");
}