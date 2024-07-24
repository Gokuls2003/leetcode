/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int rangeSumBST(struct TreeNode* root, int low, int high) 
{
    if (root == NULL)   return 0;

    int sum = 0;

    if (root -> val >= low && root -> val <= high){
        sum += root -> val;
    }

    
    if (root -> val > low){
        sum += rangeSumBST (root -> left, low, high);
    }

    if (root -> val < high){
        sum += rangeSumBST (root -> right, low, high);
    }

    return sum;

}