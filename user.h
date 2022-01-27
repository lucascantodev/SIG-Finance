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

struct user {
    char name[31];
    char birth_date[8];
    char cpf[12];
};

//CRUD: User
void userMenu(void);
void createUser(void);
User* createUserFill(void);
void userList(void);
void updateUser(void);
void deleteUser(void);
