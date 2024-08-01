bool dfs(char** board, int num_rows, int num_cols, char* target, int seed_row, int seed_col)
{
    if (*target == '\0')
    {
        return true;
    }
    if (seed_row == num_rows || seed_col == num_cols || seed_row < 0 || seed_col < 0) // out of bounds
    {
        return false;
    }
    if (board[seed_row][seed_col] != target[0])
    {
        return false;
    }

    bool res = false;
    const char copy = board[seed_row][seed_col];
    board[seed_row][seed_col] = 0;
    
    res |= dfs(board, num_rows, num_cols, target + 1, seed_row + 1, seed_col);
    res |= dfs(board, num_rows, num_cols, target + 1, seed_row - 1, seed_col);
    res |= dfs(board, num_rows, num_cols, target + 1, seed_row, seed_col + 1);
    res |= dfs(board, num_rows, num_cols, target + 1, seed_row, seed_col - 1);

    board[seed_row][seed_col] = copy;

    return res;
}


bool exist(char** board, int num_rows, int* num_cols, char* word) 
{
    for (int row = 0; row < num_rows; ++row)
        for (int col = 0; col < *num_cols; ++col)
            if (dfs(board, num_rows, *num_cols, word, row, col))
                return true;
                
    return false;
}