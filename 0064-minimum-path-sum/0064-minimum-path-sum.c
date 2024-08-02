int min (int a, int b){
    return a>b? b:a;
}

int minPathSum(int** grid, int gridSize, int* gridColSize){
    int i, j;
    int m = gridSize;
    int n = *gridColSize;
    
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(i>0 && j>0)
                grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
            else if(i>0)
                grid[i][j] += grid[i-1][j];
            else if(j>0)
                grid[i][j] += grid[i][j-1];
        }
    }
    return grid[m-1][n-1];
}