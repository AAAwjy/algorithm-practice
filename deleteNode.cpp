public:
TreeNode* deleteNode(TreeNode* root, int key) {
    if(!root) return root;
    if(key<root->val)
        root->left=deleteNode(root->left,key);
    else if(key>root->val)
        root->right=deleteNode(root->right,key);
    else if(root->val==key){
        //1.叶子节点
        if(!root->left&&!root->right) return nullptr;
        //2.左空右不空
        if(!root->left&&root->right) return root->right;
        //3.左不空右空
        if(root->left&&!root->right) return root->left;
        //4.左不空右不空
        if(root->left&&root->right) {
            //选择左节点作为替换节点,左节点的右子树要接到右节点的左子树上
            TreeNode* rl=Findrl(root->right);
            r1->left=root->left;
            return root->right;
        }
    }
    return root;
}

TreeNode* Findrl(TreeNode* root){
    while(root->left){
        root=root->left;
    }
    return root;
}
