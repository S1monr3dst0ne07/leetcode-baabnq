


int bestStart;
int bestEnd;


void checkAndUpdateBestPaliSubPyPosHypth(int low, int high, char* str)
{


    while (low >= 0 && str[low] == str[high])
    {
        low--;
        high++;
    }

    int start = low  + 1;
    int end   = high - 1;

    if (bestEnd - bestStart >= end - start) return;

    bestStart = start;
    bestEnd   = end;

}



char* longestPalindrome(char* s)
{
    int len = strlen(s);

    bestStart = 0;
    bestEnd   = 0;

    for (int i = 0; i < len; i++)
    {
        checkAndUpdateBestPaliSubPyPosHypth(i, i  , s);
        checkAndUpdateBestPaliSubPyPosHypth(i, i+1, s);
    }
    
    s[bestEnd + 1] = '\0';
    
    return &s[bestStart];
}
