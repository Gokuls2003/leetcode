char* reorganizeString(char* s) {
    int majority=0,letters=0;
    char* str=(char*)malloc(sizeof(str)*strlen(s));
    int hash[26]={0};
    for(int i=0; i<strlen(s); i++){
        hash[s[i]-'a']++;
    }
    for(int i=0; i<26; i++){
    if(hash[i]>majority){
    majority=hash[i];
    letters=i;
    }
    }
    if(majority>(strlen(s)+1)/2) return "";
    //filling all even places with majority characters.
    int index=0;
    while(hash[letters]-- >0){
        str[index]=(char)(letters+'a');
        index+=2;
    }
    //here we fill the other remaining characters.
    for(int i=0; i<26; i++){
        while(hash[i]-- >0){
            if(index>=strlen(s)){
                index=1;
            }
            str[index]=(char)(i+'a');
            index+=2;
        }
    }
    str[strlen(s)]='\0';
    return str;
}
