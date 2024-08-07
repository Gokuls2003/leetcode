int strStr(char* haystack, char* needle) {
    int index = 0; // Storing first occurence index

    for (int i = 0, j = 0, len_haystack = strlen(haystack), len_needle = strlen(needle); i < len_haystack; i++)
    {
        if (haystack[i] == needle[0])
        {
            index = i; // Needle first occured on ith index in haystack
            while (j < len_needle)
            {
                if (haystack[i] != needle[j])
                {
                    i = index; // To again compare haystack[i] with needle[0]
                    j = 0; // Returning to needle[0]
                    break;
                }
                i++;
                j++;
            }
            if (j == len_needle)
                return index;
        }
    }
    
    return -1;
}