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
    char name[21];
    int id;
};

//CRUD: Types
void typeMenu(void);
void createType(void);
void typeList(void);
void updateType(void);
void deleteType(void);