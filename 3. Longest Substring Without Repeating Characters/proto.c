


int max(int x, int y)
{
    return x > y ? x : y;
}



//super as opposed to sub
int lengthOfLongestSubstring(char* superString)
{
    int posWhereCharLastSeen[128] = { [0 ... 127] = 0 };

    int superLen = strlen(superString);

    int start = 0;
    int best = 0;

    for (int i = 0; i < superLen; i++)
    {
        //current "position"
        //this is literally just to avoid negative numbers lol
        int pos = i + 1;

        char superChar = superString[i];
        
        start = max(start, posWhereCharLastSeen[superChar]);
        posWhereCharLastSeen[superChar] = pos;
        
        int sublen = pos - start;
        best = max(best, sublen);
    }

    return best;
}