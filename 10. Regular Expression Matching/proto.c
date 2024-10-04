
struct regex
{
    char c;    //NULL to match any character
    bool star; //zero or more

    struct regex* next;
};

struct regex* alloc()
{
    struct regex* r = malloc(sizeof(struct regex));
    memset(r, 0x0, sizeof(struct regex));
    return r;
}


struct regex* parse(char* p)
{
    struct regex* hook = alloc();
    struct regex* this = hook;

    for (; *p; p++)
        if (*p == '*') this->star = true;
        else
        {
            this->next = alloc();
            this = this->next;

            this->c = *p != '.' ? *p : '\0';
        }

    struct regex* start = hook->next;
    free(hook);
    return start;
}



bool match(struct regex* r, char* s)
{
    if (!r) return !*s;
    if (!*s) return r->star && match(r->next, s);

    bool M = (!r->c || r->c == *s);

    switch((r->star << 1) + M)
    {
        case 0b00: return false;
        case 0b01: return match(r->next, s+1);
        case 0b10: return match(r->next, s);
        case 0b11:;
            return match(r, s+1) || match(r->next, s);

    }

    return false; //never reached
}


bool isMatch(char* s, char* p) 
{
    return match(parse(p), s);
}
