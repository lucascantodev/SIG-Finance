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

int containsLetter(char* string);
int isSpace(char c);
int isLetter(char c);
int validateName(char* name);
int validateCPF(char *cpf);
int equalsDigitCPF(int *cpf);
int isDigit(char d);
int isDigitOrPoint(char d);
int leapYear(int year);
int isDate(int day, int month, int year);
int validateDate(char *date);
int validateTime(char *time);
void currentTime(char* dateString, char* hourString);
int validateBirthday(char *birth_date);
int dOrW(char DW);
int yesOrNo(void);
void fileError(void);
void fileSucess(void);
void saveCanceled(void);
void fgetsS(char* string, long int stringSize);