#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

#define guard if (*in == '\0') return 0

const int ACCUM_LIMIT = (INT_MAX / 10); 

int myAtoi(char* in)
{
    //skip leading whilespace
    while (*in == ' ') in++;
    guard;

    //grab sign and skip
    bool sign = *in == '-';
    if (*in == '+' || *in == '-') in++;
    guard;

    int out = 0;
    for (; isdigit(*in); in++)
    {
        int digit = (*in - '0');

        if (out > ACCUM_LIMIT) goto overflow;
        int out10 = out * 10;

        if (out10 > INT_MAX - digit) goto overflow;
        out = out10 + digit;
    }

    return sign ? -out : out;

    overflow:
        return sign ? -INT_MAX-1 : INT_MAX;
}
