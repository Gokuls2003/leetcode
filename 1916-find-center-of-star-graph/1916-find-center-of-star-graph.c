int findCenter(int** edges, int edgesSize, int* edgesColSize) {
    int nodes[edgesSize+2];
    for(int i=0 ; i<edgesSize+2 ; i++)
        nodes[i] = 0;
    for(int i=0 ; i<edgesSize ; i++){
        for(int j=0 ; j<2 ; j++)
            nodes[edges[i][j]]++;
    }
    int max=0;
    int index=0;
    for(int i=0 ; i<edgesSize+2 ; i++){
        if(nodes[i]>max){
            max=nodes[i];
            index=i;
        }
    }
    return index;
}