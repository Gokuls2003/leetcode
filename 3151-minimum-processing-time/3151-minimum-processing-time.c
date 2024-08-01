 
// Comparison function for qsort (ascending order)
int compareAscending(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Comparison function for qsort (descending order)
int compareDescending(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}

int minProcessingTime(int* processorTime, int processorTimeSize, int* tasks, int tasksSize) {
    // Sort processorTime in ascending order
    qsort(processorTime, processorTimeSize, sizeof(int), compareAscending);
    
    // Sort tasks in descending order
    qsort(tasks, tasksSize, sizeof(int), compareDescending);
    
    int maxCompletionTime = 0;
    
    // Assign tasks to processors
    for (int i = 0; i < processorTimeSize; i++) {
        for (int j = 0; j < 4; j++) {
            int taskIndex = i * 4 + j;
            int completionTime = processorTime[i] + tasks[taskIndex];
            if (completionTime > maxCompletionTime) {
                maxCompletionTime = completionTime;
            }
        }
    }
    
    return maxCompletionTime;
}