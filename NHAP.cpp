class Solution { 
      public : 
      vector<double> averageOfLevels(TreeNode* root) {
            queue<TreeNode*> q ; 
            q.push(root) ; 
            q.push(nullptr) ; 
             vector<double> result ;
        
       while(q.front() != nullptr) {
            double sum =0  ; 
            int counts = q.size() ; 
        for(int i =0 ; i < counts ; i++) {
            TreeNode* node = q.front() ;
            sum += node->val ; 
            if(node->left != nullptr) {
                   q.push(node->left) ;
            }
            if(node->right != nullptr) {
                   q.push(node->right) ;
            }
            result.push_back(sum / count) ;
          }
       
          
       }
          return result ;     
}
};

