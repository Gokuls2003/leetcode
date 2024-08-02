int min(int a, int b)  { return (a < b ? a : b); }

int minCostClimbingStairs(int* cost, int costSize){
    int minus_1_cost = 0;
    int minus_2_cost = 0;
    int cur_cost = 0;
    int i = 2;
    for(;i<costSize;i++) {
        cur_cost = min(minus_1_cost + cost[i-1], minus_2_cost + cost[i-2]);
        minus_2_cost = minus_1_cost;
        minus_1_cost = cur_cost;
    }
    return min(minus_1_cost + cost[i-1], minus_2_cost + cost[i-2]);
}