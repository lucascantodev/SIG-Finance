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
    int cpf[11];
    char name[36];
    char birth_date;
};

//CRUD: User
void userMenu(void);
void createUser(void);
void userList(void);
void updateUser(void);
void deleteUser(void);
