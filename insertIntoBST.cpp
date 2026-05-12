#递归
TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL){
            TreeNode*node=new TreeNode(val);
            return node;
        }
        if(root->val>val)root->left=insertIntoBST(root->left,val);
        if(root->val<val)root->right=insertIntoBST(root->right,val);
        return root;
    }
#迭代
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL){
            TreeNode*node=new TreeNode(val);
            return node;
        }
        TreeNode*cur=root;
        TreeNode*par=root;
        while(cur!=NULL){
            par=cur;
            if(cur->val>val)cur=cur->left;
            else cur=cur->right;
        }
        TreeNode*node=new TreeNode(val);
        if(val<par->val)par->left=node;
        else
        par->right=node;
        return root;
    }
};
