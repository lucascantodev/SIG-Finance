#include <stdio.h>
#include <stdbool.h>
#include "user.h"

typedef struct user User;

//user module
void userMenu(){
    char op;
    bool isValid = true;

    do{
        printf("\n/////////////////////////////////////////////////////////////////////////////\n");
        printf("///                                                                       ///\n");
        printf("///               = = = = = = = = = = = = = = = = = = = =                 ///\n");
        printf("///           = = = = = = = =    User Menu    = = = = = = =               ///\n");
        printf("///               = = = = = = = = = = = = = = = = = = = =                 ///\n");
        printf("///                                                                       ///\n");
        printf("///              1. Register new user                                     ///\n");
        printf("///              2. Users list                                            ///\n");
        printf("///              3. Update User                                           ///\n");
        printf("///              4. Delete User                                           ///\n");
        printf("///              0. Back to main menu                                     ///\n");
        printf("///                                                                       ///\n");
        printf("/////////////////////////////////////////////////////////////////////////////\n\n");
        printf("\t\t\tChoose an option: ");
        scanf("%c", &op);
        getchar();
        printf("\n");

        switch (op){
            case '1':
                createUser();
                break;
            case '2':
                userList();
                break;
            case '3':
                updateUser();
                break;
            case '4':
                deleteUser();
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
void createUser() {
    char name[31];
    char birth_date;
    int cpf[11];

    printf("\n/////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                       ///\n");
    printf("///               = = = = = = = = = = = = = = = = = = = =                 ///\n");
    printf("///           = = = = = = = =   Register User   = = = = = = =             ///\n");
    printf("///               = = = = = = = = = = = = = = = = = = = =                 ///\n");
    printf("///                                                                       ///\n");
    printf("///                         User name:                                    ///\n");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÃÕ a-záéíóúâêôçãõ]", name); //adapted from @flgorgonio
    getchar();
    printf("///                                                                       ///\n");
    printf("///                         User birthday:                                ///\n");
    scanf("%c", &birth_date);
    getchar();
    printf("///                                                                       ///\n");
    printf("///                         User's CPF:                                   ///\n");
    scanf("%d", cpf);
    getchar();
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n\n");
}

//read
void userList() {
    printf("\n\t\t========== User List ==========\n");
    printf("\t\tTODO: loop to show each user\n");
    //TODO: loop to show each user
}

//(update)
void updateUser() {
    char birth_date;
    int cpf[11];

    printf("\n/////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                       ///\n");
    printf("///              = = = = = = Update User = = = = = =                      ///\n");
    printf("///                PS.: this will change user's data                      ///\n");
    printf("///                                                                       ///\n");
    printf("///           User's birthday:                                            ///\n");
    scanf("%c", &birth_date);
    getchar();
    printf("///           User's CPF:                                                 ///\n");
    scanf("%d", cpf);
    getchar();
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n\n");
}

//(delete)
void deleteUser() {
    int cpf[11];

    printf("\n/////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                       ///\n");
    printf("///                = = = = = = Delete User = = = = = =                    ///\n");
    printf("///                                                                       ///\n");
    printf("///               Please enter the User's CPF to remove it                ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n\n");
    printf("Which User's CPF do you want to be deleted :");    
    scanf("%d", cpf);
    getchar();
    printf("\n");
}