int min(int a, int b) {
    if (a < b) {
        return a;
    }
    else {
        return b;
    }
}

int minCostToMoveChips(int* position, int positionSize) {
    int odd_count;
    int even_count;
    int i;
    int ans;

    odd_count = 0;
    even_count = 0;
    for (i = 0; i < positionSize; i++) {
        if (position[i] & 1) {
            odd_count++;
        }
        else {
            even_count++;
        }
    }
    ans = min(odd_count, even_count);
    return ans;
}