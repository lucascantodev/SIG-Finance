#include <stdio.h>
#include <string.h>
#include "validations.h"
#include <stdlib.h>

int containsLetter(char *string)
{
    for (int i = 0; i < strlen(string); i++)
    {
        if (isLetter(string[i]))
        {
            return 1;
        }
    }
    return 0;
}

int isSpace(char c)
{
    if (c == 32)
    {
        return 1;
    }
    return 0;
}

// Adapted from @flgorgonio
int isLetter(char c)
{
    if (c >= 'A' && c <= 'Z')
    {
        return 1;
    }
    else if (c >= 'a' && c <= 'z')
    {
        return 1;
    }
    return 0;
}

// To be validated, the name must contain some letter and only letters and spaces
int validateName(char *name)
{
    if (!containsLetter(name))
    {
        return 0;
    }

    for (int i = 0; i < strlen(name); i++)
    {
        if (!isLetter(name[i]))
        {
            if (!isSpace(name[i]))
            {
                return 0;
            }
        }
    }
    return 1;
}

// Inspired by George Henrique Wurthmann: https://wurthmann.blogspot.com/2012/12/funcao-em-linguagem-c-validador-de-cpf.html#:~:text=Fun%C3%A7%C3%A3o%20em%20C%20para%20validar%20o%20CPF%3A%20H%C3%A1,loop%20que%20faz%20o%20calculo%20do%20segundo%20d%C3%ADgito.
int validateCPF(char *cpf)
{
    int cpfInteger[12];
    int i;
    int sum = 0;
    int digit1;
    int digit1Final;
    int digit2;
    int digit2Final;
    int finalValue;

    // Using ASCII Table -> char to int
    for (i = 0; i < 11; i++)
    {
        cpfInteger[i] = cpf[i] - 48;
    }
    if (strlen(cpf) != 11)
    {
        return 0;
    }

    // First digit
    for (i = 0; i < 9; i++)
    {
        sum = sum + cpfInteger[i] * (10 - i);
    }
    digit1Final = sum % 11;
    if ((digit1Final == 0) || (digit1Final == 1))
    {
        digit1 = 0;
    }
    else
    {
        digit1 = 11 - digit1Final;
    }

    // Second digit
    sum = 0;
    for (i = 0; i < 10; i++)
    {
        sum = sum + cpfInteger[i] * (11 - i);
    }
    finalValue = (sum / 11) * 11;
    digit2Final = sum - finalValue;
    if ((digit2Final == 0) || (digit2Final == 1))
    {
        digit2 = 0;
    }
    else
    {
        digit2 = 11 - digit2Final;
    }

    // Final validation of both digits
    if ((digit1 == cpfInteger[9]) && (digit2 == cpfInteger[10]))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
