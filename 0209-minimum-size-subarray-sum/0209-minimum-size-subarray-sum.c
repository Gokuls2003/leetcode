int minSubArrayLen(int target, int* nums, size_t numsSize) {
    int i = 0; 
    int sum = 0; 
    int minLength = INT_MAX; 

    for (int j = 0; j < numsSize; j++) { 
        sum += nums[j]; 

        while (sum >= target) { 
            minLength = (minLength < j - i + 1) ? minLength : (j - i + 1);

            sum -= nums[i]; 
            i++;
        }
    }
    return (minLength == INT_MAX) ? 0 : minLength; 
}