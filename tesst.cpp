class Solution  { 
    public : 
    int sumRoottoLeaf(TreeNode * root ) {  
        int totla = 0 ;  
        dfs(root , 0 , total ) ; 
        return total  ; 

    }
    void dfs(TreeNode* root , int pathSum , int &  total ) {  
        if(root == nullptr ) return ; 
        pathSum = pathSum * 10 + root -> val ;  { 
            if(root->left == nullptr && root right  = nullptr ) { 
                total += total + pathSum ; 
                return ; 
            }
            dfs(root->left , pathSum , total ) ; 
            dfs(root -> right  , pathSum , total ) ; 
        }
    }

}