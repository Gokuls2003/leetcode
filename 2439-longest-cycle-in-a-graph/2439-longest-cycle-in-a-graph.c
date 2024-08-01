int longestCycle(int* edges, int edgesSize) {
    int* tries = (int*)calloc(edgesSize + 1, sizeof(int));
    int* length = (int*)calloc(edgesSize + 1, sizeof(int));
    // 0: "alive" vertices, -1: "dead" vertices, others: visited vertices 
    int max_cycle_length = 0, cycle_length, try_label = 1;

    for (int i = 0; i < edgesSize; i++) {
        if (edges[i] == -1) {
            tries[i] = -1;
        }
    }
    int current;

    for (int i = 0; i < edgesSize; i++) {
        current = i;
        tries[current] = try_label;
        cycle_length = 0;
        //printf("hello: %d", tries[edges[current]]);
        while (edges[current] != -1 && tries[current] > 0) {
            // when the next vertex is possible to go
            if (edges[edges[current]] != -1 && tries[edges[current]] == 0) {
                tries[edges[current]] = try_label;
                length[edges[current]] = ++cycle_length; // assigning label of cycle
                current = edges[current];
            }
            // when we found a cycle (not necessarily the longest)
            else if (edges[edges[current]] != -1 && tries[edges[current]] == try_label) {
                cycle_length++;
                if (max_cycle_length < cycle_length - length[edges[current]])
                    max_cycle_length = cycle_length - length[edges[current]];
                break;
            }
            else
                break;
        }
        try_label++;
    }

    free(tries), free(length);

    return max_cycle_length == 0 ? -1 : max_cycle_length;
}