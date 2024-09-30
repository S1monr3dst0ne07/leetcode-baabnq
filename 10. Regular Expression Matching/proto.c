

int cache[21][21] = { -1 };

bool performMatch(char*s, char* p);

bool cacheMatch(char* s, char* p)
{
    if (*s == '\0' && *p == '\0') return true;
    if (*p == '\0') return false;

    if (p[1] == '*')
    {
        while (*s != '\0' && (*p == *s || *p == '.'))
        {
            if (performMatch(s, p+2)) return true;
            s++;
        }
        return performMatch(s, p+2);
    }
    else if (*p == '.')
        return *s != '\0' && performMatch(s+1, p+1);

    else
        return (*p == *s) && performMatch(s+1, p+1);

}

bool performMatch(char*s, char* p)
{
    int sLen = strlen(s);
    int pLen = strlen(p);

    if (cache[sLen][pLen] == -1)
        return (cache[sLen][pLen] = cacheMatch(s, p));
    else
        return cache[sLen][pLen];

}


bool isMatch(char* s, char* p)
{
    memset(cache, -1, sizeof(cache));
    return performMatch(s, p);
}
