
char* convert(char* in, int numRows)
{ 
    if (in == NULL) return strdup("");
    if (numRows == 1) return strdup(in);

    int len = strlen(in);
    char* out = calloc(len+1, sizeof(char));
    char* iter = out;

    int intervalLen = (numRows - 1) * 2;
    int intervalCount = len / intervalLen + 1;


    int climber = 0;
    int faller = intervalLen;

    void appendBoundsCheckWithOffset(int index)
    {
        if (index < len)
            *iter++ = in[index];
    }

    while (climber <= faller)
    {
        for (int i = 0; i < intervalCount; i++)
        {
            int offset = i * intervalLen;

            appendBoundsCheckWithOffset(climber + offset);

            if (climber == 0     ) continue;
            if (climber == faller) continue;
            
            appendBoundsCheckWithOffset(faller + offset);
        }

        climber += 1;
        faller  -= 1;
    }


    return out;
}