#include <stdlib.h>
#include <stdbool.h>

struct regex
{
    char letter;
    bool star;      //zero or more
    bool dot;       //match any character

    struct regex* next;
};

struct regex* alloc()
{
    return calloc(1, sizeof(struct regex));
}


struct regex* parse(char* p)
{
    struct regex hook; //hook for the chain to hang on
    struct regex* this = &hook;

    for (; *p; p++)
    {
        char c = *p;

        if (c == '*') this->star = true;
        else
        {
            this->next = alloc();
            this = this->next;

            this->letter = *p;
            this->dot    = *p == '.';
        }
    }

    return hook.next;
}


bool match(struct regex* r, char* s)
{
    if (!r) return !*s;
    if (!*s) return r->star && match(r->next, s);

    bool matching = (r->dot || r->letter == *s);

    switch((r->star << 1) + matching)
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
