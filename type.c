#include <stdio.h>
#include <stdbool.h>
#include "type.h"

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

    if(createdTypeOK){
        //TODO: save in the file and print "Sucess"
    }else{
        printf("\t\t\t<<<<<<<< Registration Canceled >>>>>>>>\n");
    }

    free(type);
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
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÃÕ a-záéíóúâêôçãõ]", type->name); //adapted from @flgorgonio
    getchar();
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n\n");

    return type;
}

int createdTypeOK(Type* type){
    char yn;
    printf("\n\n");
    printf("\t            = = = = = = Register Type = = = = = =               \n\n");

    printf("\n\t Do you really want to register type of R$ %s ?\n", type->name);
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
void typeList(){
    printf("\n\t\t========== Type List ==========\n");
    printf("\t\tTODO: loop to show each type\n");
    //TODO: loop to show each type
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