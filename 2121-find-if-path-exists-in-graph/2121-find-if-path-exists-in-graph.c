typedef struct _slist
{
    int *array;
    int len;
} s_list;

bool validPath(int n, int** edges, int edgesSize, int* edgesColSize, int source, int destination) {
    bool ret = false;
    
    // very sparse matrix
    // calculate the amount of memory to use
    int *counts = calloc( n, sizeof(int));
    for ( int i = 0; i < edgesSize; i += 1)
    {
        counts[ edges[ i][ 0]] += 1;
        counts[ edges[ i][ 1]] += 1;
    }// for i

    // record all of the links that are given
    s_list *row = calloc( n, sizeof(s_list));

    // allocate accordingly
    for ( int i = 0; i < n; i += 1)
    {
        row[ i].array = malloc( counts[ i] * sizeof(int));
    }// for i
    free( counts);
    counts = NULL;

    // write to them in a stack push style
    for ( int i = 0; i < edgesSize; i += 1)
    {
        row[ edges[ i][ 0]].array[ row[ edges[ i][ 0]].len] = edges[ i][ 1];
        row[ edges[ i][ 0]].len += 1;

        row[ edges[ i][ 1]].array[ row[ edges[ i][ 1]].len] = edges[ i][ 0];
        row[ edges[ i][ 1]].len += 1;
    }// for i


    // dfs
    char *visited = calloc( n, sizeof(char));
    int *stack = calloc( n, sizeof(int));
    int stack_top = 0;

    stack[ stack_top] = source;
    stack_top += 1;
    visited[ source] = 1;
    int current;
    while( stack_top)
    {
        stack_top -= 1;
        current = stack[ stack_top];

        if ( current == destination)
        {
            ret = true;
            break;
        }// if

        for ( int i = 0; i < row[ current].len; i += 1)
        {
            if ( !visited[ row[ current].array[ i]])
            {
                stack[ stack_top] = row[ current].array[ i];
                stack_top += 1;
                visited[ row[ current].array[ i]] = 1;
            }// if
        }// for i
    }// while

    // cleanup memory
    for ( int i = 0; i < n; i += 1)
    {
        free( row[ i].array);
        row[ i].array = NULL;
    }// for i

    free( row);
    free( visited);
    row = NULL;
    visited = NULL;
    free( stack);
    stack = NULL;

    return ret;
}