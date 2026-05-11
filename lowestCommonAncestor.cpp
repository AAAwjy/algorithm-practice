#给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先
class Solution {
private:
    TreeNode* traversal(TreeNode*cur,TreeNode*p,TreeNode*q){
        if (cur == NULL) return NULL;
        if(cur->val<p->val&&cur->val<q->val){
           return traversal(cur->right,p,q);
        }
        if(cur->val>p->val&&cur->val>q->val){
           return traversal(cur->left,p,q);
        }
        
        return cur;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return traversal(root,p,q);
    }
};
#给定一个二叉树, 找到该树中两个指定节点的最近公共祖先
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       if(root==NULL||root==p||root==q)return root;
       TreeNode*left=lowestCommonAncestor(root->left,p,q);
       TreeNode*right=lowestCommonAncestor(root->right,p,q);
       if(left!=NULL&&right!=NULL)return root;
       if(left==NULL&&right!=NULL)return right;
       else if(left!=NULL&&right==NULL)return left;
       else{
        return NULL;
       } 
    }
};
