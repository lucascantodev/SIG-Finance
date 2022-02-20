///////////////////////////////////////////////////////////////////////////////
///                              Developed by:                              ///
///////////////////////////////////////////////////////////////////////////////
///                                                                         ///
///             Lucas Canto           &           Jonathan Maia             ///
///             @lucascantodev                    @jtauanpm                 ///
///                                                                         ///
///        Repository: https://github.com/lucascantodev/SIG-Finance         ///
///                                                                         ///
///////////////////////////////////////////////////////////////////////////////

typedef struct type Type;

struct type {
    long int id;
    char name[21];
    int deleted;
};

//CRUD: Types
void typeMenu(void);
void createType(void);
Type* createTypeFill(void);
int saveTypeOk(Type* type,char* operation);
int typeList(void);
void updateType(void);
void deleteType(void);
int saveType(Type* type);
Type* findType(long int* id);
int resaveType(Type* type);
