class Solution  { 
    public : 
    int sumRootToLeaf(TreeNode* root) { 
        int total = 0 ; 
        dfs(root ,  0 , total ) ;
        return total ; 
        
    }
    void dfs(TreeNode* root . int pathSum , &int total )  {  
        if(root == NULL )return ; 
         pathSum = pathSum* 2+ root->val ;  { 
            if(root->left == NULL && root->right == nullptr ) { 
                total + pathSum ; 
                return ; 
            }
         } 
         dfs(root->left , pathSum , total ) ; 
         dfs(root->right , pathSum , total ) ; 
    }
}