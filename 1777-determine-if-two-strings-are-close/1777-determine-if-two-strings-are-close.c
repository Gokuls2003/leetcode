int cmp(const void *a , const void *b){
    return *(int*)a - *(int*)b; 
}
bool closeStrings(char* word1, char* word2) {
    int i;
    int dict1[26] = {0};
    int dict2[26] = {0};
    for(i = 0 ; word1[i] && word2[i] ; ++i){
        ++dict1[word1[i] -'a'];
        ++dict2[word2[i] - 'a'];
    }
    if(word1[i] != word2[i]) return false;
    for( i = 0 ; i<26; ++i){
        if((bool)dict1[i] ^ (bool)dict2[i]){
            return false;
        }
    }
    qsort(dict1,26,sizeof(int),cmp);
    qsort(dict2,26,sizeof(int),cmp);
    i = 0;
    while(i<26 && dict1[i] == dict2[i]) i++;
    return i== 26;
    
}