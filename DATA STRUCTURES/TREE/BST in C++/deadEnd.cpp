//check if a BST contains any dead end

bool hasDeadEnd(TreeNode* root,int min,int max)
{
    if(root)
    {
        if(min==max)
            return true;

        return hasDeadEnd(root->left) || hasDeadEnd(root->right);
    }

    return false;
}
