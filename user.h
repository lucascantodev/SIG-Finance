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
    char birth_date;
    int cpf[11];
    //user user;
    //type type;
};

//CRUD: User
void userMenu(void);
void createUser(void);
void userList(void);
void updateUser(void);
void deleteUser(void);
