int myAtoi(char* s)
{
    while (*s == ' ') s++;
    if (*s == '\0') return 0;

    bool sign = *s == '-';
    if (*s == '+' || *s == '-') s++;
    if (*s == '\0') return 0;

    int out = 0;
    while (isdigit(*s))
        if (out > INT_MAX/10) return sign ? -INT_MAX-1 : INT_MAX; 
        else if (out * 10 > INT_MAX - (*s - '0'))  return sign ? -INT_MAX-1 : INT_MAX;
        else out = out * 10 + (*s++ - '0');

    return sign ? -out : out;
}
