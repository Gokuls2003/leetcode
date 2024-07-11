/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* targetIndices(int* nums, int numsSize, int target, int* returnSize) {
    
    for(int i=0;i<numsSize-1;i++){
        for(int j=i+1;j<numsSize;j++){
            if(nums[i]>nums[j]){
                int temp=nums[i];
                nums[i]=nums[j];
                nums[j]=temp;
            }
        }
    }
    int count=0;
    for(int i=0;i<numsSize;i++){
        if(nums[i]==target){
           count++;
           
        }
    }
    *returnSize=count;
    int j=0;
    int * arr=(int *)malloc(count*sizeof(int));
    for(int i=0;i<numsSize;i++){
        if(nums[i]==target){
           arr[j]=i;
            j++;
        }
    }
    return arr;
}