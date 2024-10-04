#include <stdbool.h>

#define SIGN_BIT ((unsigned)1 << 31)
#define INT_LIMIT (SIGN_BIT-1)

int reverse(int in)
{
    int out = 0;
    for (; in; in /= 10)
    {
        if (out > (INT_LIMIT / 10)) return 0;
        out = out*10 + (in%10);
    }

    return out;
}


bool isPalindrome(int x)
{
    return x >= 0 && x == reverse(x);
}
