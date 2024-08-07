int** findDifference(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize, int** returnColumnSizes){
    /* range -1000 - 1000, 2001 totally */
    int* hash = (int*)calloc(2001, sizeof(int));
    int** ans = (int**)malloc(sizeof(int*) * 2);
    ans[0] = (int*)calloc(nums1Size, sizeof(int));
    ans[1] = (int*)calloc(nums2Size, sizeof(int));
    
    for(int i = 0; i < nums2Size; i++)
        hash[nums2[i]+1000] = 1;
    
    for(int i = 0; i < nums1Size; i++)
    {
        if(hash[nums1[i]+1000]>0)/* means both num1 and num2 existed */
            hash[nums1[i]+1000]++;
        else /* only num1 has */
            hash[nums1[i]+1000] = -1;
    }
    int* col = (int*)calloc(2, sizeof(int));
    for(int i = -1000; i <= 1000; i++)
    {
        if(hash[i+1000] == -1)/* num1 */
            ans[0][col[0]++] = i;
        else if(hash[i+1000] == 1)/* num2 */
            ans[1][col[1]++] = i;
    }
    
    *returnSize = 2;
    *returnColumnSizes = col;
    return ans;
}