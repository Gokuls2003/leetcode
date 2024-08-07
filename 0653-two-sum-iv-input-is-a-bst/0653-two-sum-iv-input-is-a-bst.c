/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isExist(struct TreeNode *node, int val)
{
    if(!node) return false;

    if(node->val == val)
    {
        return true;
    }
    else if(node->val > val)
    {
        return isExist(node->left, val);
    }
    else
    {
        return isExist(node->right, val);
    }
}

void help(struct TreeNode *head, struct TreeNode *node, int k, bool *res)
{
    if(!node) return;
    else if(*res) return;

    int temp = k - node->val;
    if(temp > node->val)
    {
        if(isExist(head, temp))
        {
            *res = true;
            return;
        }
    }
    else if(temp < node->val)
    {
        if(isExist(head, temp))
        {
            *res = true;
            return;
        }
    }
    
    help(head, node->left, k, res);

    help(head, node->right, k, res);

}

bool findTarget(struct TreeNode* root, int k){
    bool res = false;
    
    help(root, root, k, &res);

    return res;
}


