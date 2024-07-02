char* intToRoman(int num) {
    char* ones[9] = {"I", "II", "III", "IV", "V", "VI", "VII","VIII", "IX"};
    char* tens[9] = {"X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
    char* hundreds[9] = {"C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
    char* thousands[3]={"M","MM","MMM"};
    char* ans = (char*)malloc(20 * sizeof(char));
    if (ans == NULL) {
        return NULL; // malloc failed
    }
    ans[0]='\0';
    if(num/1000!=0)
    {strcat(ans,thousands[(num/1000-1)]);}
    if((num%1000)/100!=0)
    {strcat(ans,hundreds[((num%1000)/100)-1]);}
    if((num%100)/10!=0)
    {strcat(ans,tens[((num%100)/10)-1]);}
    if(num%10!=0)
    {strcat(ans,ones[(num%10)-1]);}
    return ans;
}