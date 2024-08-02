#include <limits.h>

int maxProduct(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    
    int maxProd = INT_MIN;
    long long currMax = 1;
    float currMin = 1;
    
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < 0) {
            long long temp = currMax;
            currMax = currMin;
            currMin = temp;
        }
        
        currMax = (currMax * nums[i] > nums[i]) ? currMax * nums[i] : nums[i];
        currMin = (currMin * nums[i] < nums[i]) ? currMin * nums[i] : nums[i];
        
        maxProd = (currMax > maxProd) ? currMax : maxProd;
    }
    
    return maxProd;
}