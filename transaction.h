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

#include "user.h"
#include "type.h"

typedef struct transaction Transaction;

struct transaction
{
    long int id;
    char DW;
    float value;
    char date[9];
    char time[6];
    char description[101];
    User* user;
    Type* type;
};


//CRUD: Transactions
void transactionMenu(void);
void createTransaction(void);
void transactionList(void);
void detailTransaction(void);
void updateTransaction(void);
void deleteTransaction(void);