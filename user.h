///////////////////////////////////////////////////////////////////////////////
///                              Developed by:                              ///
///////////////////////////////////////////////////////////////////////////////
///                                                                         ///
///             Lucas Canto           &           Jonathan Maia             ///
///             @lucascantodev                  @jonathan-tauan             ///
///                                                                         ///
///        Repository: https://github.com/lucascantodev/SIG-Finance         ///
///                                                                         ///
///////////////////////////////////////////////////////////////////////////////

typedef struct user User;

struct user
{
    char name[41];
    char birth_date[9];
    char cpf[12];
    short int deleted;
};

// CRUD: User
void userMenu(void);
void createUser(void);
User *createUserFill(void);
int userList(void);
void updateUser(void);
void deleteUser(void);
int saveUser(User *use);
int saveUserOk(User *use, char *operation);
User *findUser(char *cpf);
int resaveUser(User *use);
