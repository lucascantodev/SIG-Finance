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

typedef struct type Type;

struct type {
    long int id;
    char name[21];
};

//CRUD: Types
void typeMenu(void);
void createType(void);
void typeList(void);
void updateType(void);
void deleteType(void);