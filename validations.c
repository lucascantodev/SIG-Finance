#include <stdio.h>
#include <string.h>

int containsLetter(char* string) {
    for (int i = 0; i < strlen(string); i++) {
        if (isLetter(string[i])) {
            return 1;
        }       
    }
    return 0;
}

int isSpace(char c) {
    if (c == 32) {
        return 1;
    }
    return 0;
}

//adapted from @flgorgonio
int isLetter(char c) {
    if (c >= 'A' && c <= 'Z') {
        return 1;
    }else if (c >= 'a' && c <= 'z'){
        return 1;
    }    
    return 0;
}

//to be validated, the name must contain some letter and only letters and spaces
int validateName(char* name) {
    if (!containsLetter(name))
    {
        return 0;
    }
    
    for (int i = 0; i < strlen(name); i++) {
        if (!isLetter(name[i])) {
            if (!isSpace(name[i]))
            {
                return 0;
            }
        }       
    }
    return 1;
}
