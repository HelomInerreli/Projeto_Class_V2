#include "../include/Auxiliares.h"
#include <string>
#include <iostream>

string Auxiliares::textToUpper(string text)
{
    string retorno;
 
    for (char c : text)
    {
        retorno += toupper(c);
    }
    return retorno;
}
