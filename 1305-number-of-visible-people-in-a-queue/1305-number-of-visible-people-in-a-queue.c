int* canSeePersonsCount(int* heights, int heightsSize, int* returnSize) {
    int* result = (int*)malloc(heightsSize * sizeof(int));
    *returnSize = heightsSize;

    int* stack = (int*)malloc(heightsSize * sizeof(int));
    int top = -1;

    // Initialize result array with zeros
    for (int i = 0; i < heightsSize; ++i) {
        result[i] = 0;
    }

    for (int i = heightsSize - 1; i >= 0; --i) {
        while (top != -1 && heights[i] > heights[stack[top]]) {
            result[i]++;
            top--;
        }
        if (top != -1) result[i]++;
        stack[++top] = i;
    }

    free(stack);
    return result;
}