void sortColors(int* nums, int numsSize){
    int lo=0, hi=numsSize-1, i = 0, tmp;
    while (i <= hi) {
        if (nums[i] == 0) {
            tmp = nums[lo];
            nums[lo++] = nums[i];
            nums[i] = tmp;
        }
        if (nums[i] == 2) {
            tmp = nums[hi];
            nums[hi--] = nums[i];
            nums[i] = tmp;
            continue;
        }
        ++i;
    }
}

/*
void sortColors(int* nums, int numsSize){
    int colours[3] = {0}, i, j = 0;
    for (i = 0; i < numsSize; ++i) {
        ++colours[nums[i]];
    }
    for (i = 0; i < 3; ++i) {
        while(colours[i]-- > 0) nums[j++] = i;
    }
}
*/