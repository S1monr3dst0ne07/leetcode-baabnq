#include <stdbool.h>
#include <math.h>

#define SIGN_BIT ((unsigned)1 << 31)
#define INT_LIMIT (SIGN_BIT-1)

//accumulator limit
const int ACCUM_LIMIT = (INT_LIMIT / 10);


int reverse(int x)
{
    //this is an edge case because -SIGN_BIT = _SIGN_BIT
    if (x == SIGN_BIT) return 0;

    bool sign = x & SIGN_BIT;
    unsigned int in = abs(x);

    int out = 0;
    while (in)
    {
        if (out > ACCUM_LIMIT) return 0;
        out = (out * 10) + (in % 10);
        in /= 10;
    }

    return sign ? -out : out;
}
