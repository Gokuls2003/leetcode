/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct TreeNode TN_t;
typedef struct Map {
    int id; TN_t *node, *parent;
    UT_hash_handle hh;
} Map_t;

TN_t* createBinaryTree(
    int** descriptions,
    int descriptionsSize,
    int* descriptionsColSize
) {
    Map_t *map=NULL, *mapP, *mapC;
    TN_t *root=NULL, *nodeP, *nodeC;

    for(int i=0; i<descriptionsSize; i++) {
        HASH_FIND_INT(map, &descriptions[i][0], mapP);
        if(mapP==NULL) {
            nodeP=malloc(sizeof(TN_t));
            *nodeP=(TN_t){descriptions[i][0], NULL, NULL};
            mapP=malloc(sizeof(Map_t));
            *mapP=(Map_t){descriptions[i][0], nodeP, NULL};
            HASH_ADD_INT(map, id, mapP);
        } else { nodeP=mapP->node; }

        HASH_FIND_INT(map, &descriptions[i][1], mapC);
        if(mapC==NULL) {
            nodeC=malloc(sizeof(TN_t));
            *nodeC=(TN_t){descriptions[i][1], NULL, NULL};
            mapC=malloc(sizeof(Map_t));
            *mapC=(Map_t){descriptions[i][1], nodeC, nodeP};
            HASH_ADD_INT(map, id, mapC);
        } else { nodeC=mapC->node; mapC->parent=nodeP; }

        if(descriptions[i][2]) {
            nodeP->left=nodeC;
        } else {
            nodeP->right=nodeC;
        }
    }
    HASH_ITER(hh, map, mapP, mapC) {
        if(mapP->parent==NULL){ root=mapP->node; }
        HASH_DEL(map, mapP); free(mapP);
    }

    return root;
}