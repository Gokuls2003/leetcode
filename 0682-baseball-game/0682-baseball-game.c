int calPoints(char** operations, int operationsSize) {
    int *record=(int *)malloc(sizeof(int)*operationsSize);
    int s=0,index=0;
    for(int i=0;i<operationsSize;i++){
        if(strcmp(operations[i],"C")==0){
            record[index-1]=0;
            index--;
        }
        else if(strcmp(operations[i],"D")==0){
            record[index++]=record[index-1]*2;
        }
        else if(strcmp(operations[i],"+")==0){
            record[index++]=record[index-1]+record[index-2];
        }
        else{
            record[index++]=atoi(operations[i]);
        }
    }
    for(int i=0;i<index;i++){
        s+=record[i];
    }
    return s;
}