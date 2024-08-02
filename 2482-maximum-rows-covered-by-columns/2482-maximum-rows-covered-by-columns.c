#define MAX(a, b) ((a) > (b) ? (a) : (b))
int maxRows(int **matrix, int row, int col, int numSelect, bool *selected, int curr)
{
    int cnt = 0, max = 0;

    if (numSelect == 0) {

        /* Check how many rows meet the requirements */
        for (int i = 0; i < row; i++) {

            bool is_matched = true;

            for (int j = 0; j < col; j++) {
                if (matrix[i][j] && selected[j] == false) {
                    is_matched = false;
                    break;
                }
            }

            cnt += is_matched ? 1 : 0;
        }

        return cnt;
    }
    for (int i = curr; i < col; i++) {
        selected[i] = true;
        cnt = maxRows(matrix, row, col, numSelect - 1, selected, i + 1);
        max = MAX(max, cnt);
        selected[i] = false;
    }

    return max;
}
int maximumRows(int** matrix, int matrixSize, int* matrixColSize, int numSelect) 
{
    bool selected[12] = {0};
    int ans;
    ans = maxRows(matrix, matrixSize, matrixColSize[0], numSelect, selected, 0);
    return ans;
}