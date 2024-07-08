/*
Author: Rishav Das (github:r1shavd)
*/

void swap(int* a, int* b) { 
    int temp = *a; *a = *b; *b = temp; 
} 
  
int partition(int arr[], int low, int high) { 
    int pivot = arr[low]; 
    int i = low; 
    int j = high; 
  
    while (i < j) { 
        while (arr[i] <= pivot && i <= high - 1) { 
            i++; 
        } 
        while (arr[j] > pivot && j >= low + 1) { 
            j--; 
        } 
        if (i < j) { 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[low], &arr[j]); 
    return j; 
} 
  
void quickSort(int arr[], int low, int high)  { 
    if (low < high) { 
        int partitionIndex = partition(arr, low, high); 
        quickSort(arr, low, partitionIndex - 1); 
        quickSort(arr, partitionIndex + 1, high); 
    } 
} 

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int* result = (int*) malloc( sizeof(int)*(nums1Size+nums2Size) ); int count = 0;
    for (int i = 0; i < m; i++) {
        *(result+count) = nums1[i];
        count++;
    }
    for (int i = 0; i < n; i++) {
        *(result+count) = nums2[i];
        count++;
    }
    quickSort(result, 0, count-1);
    for (int i = 0; i < count; i++) {
        *(nums1 + i) = *(result+i);
    }
    free(result);
}