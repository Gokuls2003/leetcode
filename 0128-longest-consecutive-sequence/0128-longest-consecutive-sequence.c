int sort(const void* a,const void* b){
    return *(int*)a - *(int*)b;
}

int longestConsecutive(int* nums, int numsSize) {
    if(numsSize<1)
        return 0;
    qsort(nums,numsSize,sizeof(int),sort);
    int i,maxLen = INT_MIN,curLen=1;
    for(i=0;i<numsSize-1;i++){
        if(nums[i]+1==nums[i+1]){
            curLen++;
        }
        else if(nums[i]==nums[i+1]){
            continue;
        }
        else{
            if(curLen>maxLen){
                maxLen = curLen;
                curLen = 1;
            }
            else{
                curLen = 1;
            }
        }
    }
    if(curLen>=maxLen)
        maxLen = curLen;
    return maxLen;
}