#include <iostream>

//Task 1
char* normalizeWhitespace(char* str){

    if (str == nullptr || str[0] == '\0') {
        return str;
    }
    char* read = str;
    char* write = str;
    bool inWhitespace = true;

    while (*read != '\0') {
        if (*read == ' ' || *read == '\n' || *read == '\t' || *read == '\r') {
            if (inWhitespace == false)
            {
                *write = ' ';
                ++write;
                inWhitespace = true;
            }
        }
        else {
            *write = *read;
            ++write;
            inWhitespace = false;
        }
        ++read;
    }
    if (write > str && *(write - 1) == ' ') {
        --write;
    }
    *write = '\0';

    return str;
}

//Task 2
int toInt(char* str){

    int result = 0;
    bool isNegative = false;

    if (str == nullptr || str[0] == '\0') {
        return result;
    }

    if (str[0] == '-') {
        isNegative = true;
        str++;
    }

    while (*str != '\0') {
        if (*str < '0' || *str > '9') {
            return 0;
        }
        result = result * 10 + (int)(*str - '0');
        str++;
    }

    if (isNegative == true) {
        return -result;
    }

    return result; 
}

int main(){

    char str1[] = "  \t abc       def\t\t\tgh\r\t";
    char str2[] = "\r\n  Test\tString \t with  \n lots  of  spaces  \r ";
    char str3[] = "\r\t   Mix\t\n of \tspaces\t\n and \tnewlines\r   ";
    char str4[] = "\n\t   Hello   World!   \r\n   ";

    std :: cout << normalizeWhitespace(str1) << "\n";
    std :: cout << normalizeWhitespace(str2) << "\n";
    std :: cout << normalizeWhitespace(str3) << "\n";
    std :: cout << normalizeWhitespace(str4) << "\n";

    std :: cout << "-------------------------------" << "\n";

    char str5[] = "123";
    char str6[] = " ";
    char str7[] = "-123";

    std :: cout << toInt(str5) << "\n";
    std :: cout << toInt(str6) << "\n";
    std :: cout << toInt(nullptr) << "\n";
    std :: cout << toInt(str7) << "\n";
}