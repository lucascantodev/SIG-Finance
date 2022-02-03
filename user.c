#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "user.h"
#include "validations.h"

// typedef struct user User;

// user module
void userMenu()
{
    char op;
    bool isValid = true;

    do
    {
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

        switch (op)
        {
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
            printf("\t\t\t>>> Choose a valid option <<<\n");
        }
    } while (isValid);
}

//(create)
void createUser()
{
    User *use;
    use = createUserFill();

    if (saveUserOk(use))
    {
        if (saveUser(use))
        {
            fileSucess();
        }
    }
    else
    {
        saveCanceled();
    }
    free(use);
}

int saveUser(User *use)
{
    FILE *fp;
    fp = fopen("users.dat", "ab");

    if (fp == NULL)
    {
        fileError();
        return 0;
    }
    fwrite(use, sizeof(use), 1, fp);
    fclose(fp);
    return 1;
}

int saveUserOk(User *use)
{
    printf("\n\n");
    printf("\t              = = = = = = Register User = = = = = =                 \n\n");

    printf("\n\tDo you really want to register a user named %s ?\n", use->name);
    printf("\n");

    return yesOrNo();
}

//(createFill)
User *createUserFill(void)
{
    User *use;
    use = (User *)malloc(sizeof(User));

    // bool ok
    printf("\n/////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                       ///\n");
    printf("///               = = = = = = = = = = = = = = = = = = = =                 ///\n");
    printf("///           = = = = = = = =   Register User   = = = = = = =             ///\n");
    printf("///               = = = = = = = = = = = = = = = = = = = =                 ///\n");
    printf("///                                                                       ///\n");
    do
    {

        printf("///                         User name:                                    ///\n");
        fgetsS(use->name, 41);
    } while (!validateName(use->name));

    do
    {
        printf("///                                                                       ///\n");
        printf("///                         User birthday:   (DDMMYYYY)                   ///\n");
        fgetsS(use->birth_date, 9);
        getchar();
    } while (!validateBirthday(use->birth_date));

    printf("///                                                                       ///\n");

    do
    {

        printf("///                         User's CPF:                                   ///\n");
        fgetsS(use->cpf, 12);
        getchar();
    } while (!validateCPF(use->cpf));

    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n\n");
    use->deleted = 0;

    return use;
}

// read and show user
int userList()
{
    FILE *fp;
    fp = fopen("users.dat", "rb");

    if (fp == NULL)
    {
        fileError();
        return 0;
    }

    User *use;
    use = (User *)malloc(sizeof(User));

    while (fread(use, sizeof(User), 1, fp))
    {
        if (use->deleted != 1)
        {
            printf("\n\t\t= = = = = Registred User = = = = =");
            printf("\nUser name: %s", use->name);
            printf("\nUser Birthday: %s", use->birth_date);
        }
        else if (use == NULL)
        {
            printf("\t\n= = = = = Non-existent User = = = = =");
        }
    }

    free(use);
    fclose(fp);
    return 1;
}

//(update)
void updateUser()
{
    char cpf[12];
    User *use;

    printf("                 = = = = = = Update User = = = = = =                  \n\n");
    printf("\nWhich user CPF do you want to update? ");
    scanf("%s", cpf);
    getchar();
    use = findUser(cpf);

    if (use == NULL)
    {
        registerNotFound();
    }
    else
    {
        do
        {
            printf("\n           User's Name (only letters): ");
            fgetsS(use->name, 41);
            getchar();

        } while (!(validateName(use->name)));

        do
        {
            printf("\n           User's CPF (only numbers): ");
            fgetsS(use->cpf, 12);
            getchar();

        } while (!(validateCPF(use->cpf)));

        do
        {
            printf("\n           Birthday (DDMMAAAA): ");
            scanf("%s", use->birth_date);
            getchar();

        } while (!(validateDate(use->birth_date)));

        if (saveUserOk(use))
        {
            if (resaveUser(use))
            {
                fileSucess();
            }
            else
            {
                saveCanceled();
            }
        }
        free(use);
    }
}

User *findUser(char *cpf)
{
    FILE *fp;
    User *use;

    fp = fopen("users.dat", "rb");

    if (fp == NULL)
    {
        fileError();
        return NULL;
    }

    use = (User *)malloc(sizeof(User));

    while (fread(use, sizeof(User), 1, fp))
    {
        if (use->cpf == cpf && use->deleted == 0)
        {
            fclose(fp);
            return use;
        }
    }

    fclose(fp);
    return NULL;
}

//(delete)
void deleteUser()
{
    User *use;
    char cpf[11];

    printf("\n/////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                       ///\n");
    printf("///                = = = = = = Delete User = = = = = =                    ///\n");
    printf("///                                                                       ///\n");
    printf("///               Which User CPF do you want to be deleted?               ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n\n");
    scanf("%s", cpf);
    getchar();

    use = findUser(cpf);
    if (use == NULL)
    {
        registerNotFound();
    }
    else
    {
        if (saveUserOk(use))
        {
            use->deleted = 1;
            if (resaveUser(use))
            {
                fileSucess();
            }
        }
    }
    free(use);
}

int resaveUser(User *use)
{
    FILE *fp;
    fp = fopen("user.dat", "r+b");
    bool find = false;

    if (fp == NULL)
    {
        fileError();
        return find;
    }
    User *useRead;
    useRead = (User *)malloc(sizeof(User));

    while (fread(useRead, sizeof(User), 1, fp) && !find)
    {
        if (useRead->cpf == use->cpf && useRead->deleted == 0)
        {
            find = true;
            fseek(fp, -1 * sizeof(User), SEEK_CUR);
            fwrite(use, sizeof(User), 1, fp);
        }
    }
    fclose(fp);
    free(useRead);
    return find;
}

void registerNotFound(void)
{
    printf("\n\t\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
    printf("\t\t!!    CPF is not registered.    !!\n");
    printf("\t\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n");

    printf("\t\t\t>>> Press ENTER to continue <<<");
    getchar();
}

void printfDateTime(char *time, char *date)
{
    printf("Time: %c%c:%c%c | %c%c/%c%c/%c%c%c%c", time[0],
           time[1], time[3], time[4], date[0], date[1],
           date[2], date[3], date[4], date[5], date[6], date[7]);
}