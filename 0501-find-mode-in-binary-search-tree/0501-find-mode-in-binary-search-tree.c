void inorder(struct TreeNode *root, int *arr, int *size){
    if (!root)
        return;
    inorder(root->left, arr, size);
    arr[(*size)++] = root->val;
    inorder(root->right, arr, size);
}

int* findMode(struct TreeNode* root, int* returnSize){
    
    int *arr = calloc(10000, sizeof(int)), size = 0;
    inorder(root, arr, &size);
    
    int *ret = malloc(sizeof(int) * size);
    int max = 0, idx = 0, len = 0, cur = arr[0];
    
    for (int i = 0; i < size; i++){
        if (arr[i] == cur)
            len++;
        else{
            if (len > max){
                idx = 0;
                ret[idx++] = cur;
                max = len;
            }else if (len == max){
                ret[idx++] = cur;
            }      
            cur = arr[i];
            len = 1;
        }
    }
    
    if (len > max){
        idx = 0;
        ret[idx++] = cur;
    }else if (len == max){
        ret[idx++] = cur;
    }  
    
    *returnSize = idx;
    return ret;
}