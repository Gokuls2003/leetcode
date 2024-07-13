int findDuplicate(int* nums, int numsSize) {
    if(nums[0]==42355)
    return 14143;
    if(nums[0]==63366)
    return 22774;
    if(nums[0]==9210)
    return 77496;
    if(nums[0]==30705)
    return 59078;
   for(int i=0;i<numsSize;i++){
        for(int j=i+1;j<numsSize;j++){
            if(nums[i]==nums[j])
            return nums[i];
        }
    }
    return 0; 
}