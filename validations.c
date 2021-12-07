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

int isLetter(char c) {
    if (c >= 'A' && c <= 'Z') {
        return 1;
    }else if (c >= 'a' && c <= 'z')
    {
        return 1;
    }    
    return 0;
}