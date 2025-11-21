#include<bits/stdc++.h>
using namespace std ;
struct Node { 
      int val ; 
      Node* left , *right ; 
      Node(int v )  :val(v) , left(nullptr) , right(nullptr) {} 
}; 
int height(Node* root ) {     
      if(root == nullptr ) {  
             return 0 ; 
      }
      return 1 + max(height(root->left),height(root->right )) ; 
}
int main () { 
      Node* root = new Node(10 ) ; 
      root->left   = new Node(12) ; 
      root->left->left = new Node(30 ) ; 
      root->right = new Node(10 ) ; 
      root->right->right = new Node(10 ) ; 
      root->right ->right->right = new Node(20) ;
      root->right->right->right->right = new Node (50 ) ;  
 
      cout  << "Height of the Node: " <<  height(root ) << "\n " ;
      return 0; 
}
