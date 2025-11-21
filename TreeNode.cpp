#include<bits/stdc++.h>
using namespace std  ; 
class Node  {
public : 
    int value ; 
    Node* left  ; 
    Node* right ; 
Node(int value) : value(value), left(nullptr), right(nullptr) {}
    
};   
class BinarySearchTree { 
    public : 
        Node* root ; 
    public  : 
        BinarySearchTree() {  root = nullptr; } // cay ban dau chua co node nao nen truyen tham so root = nullptr }
    Node* getRoot() { 
         return root ; 

    }

bool insert (int value) { 
    // tao node moi moi voi gia tri can chen 
    Node* newNode = new Node(value); 
    //neu cay nay rong node moi tro thanh than root 
    if(root == nullptr ) { 
        root  = newNode; 
        return true; // chen node thanh cong  
    }
    Node* temp = root ;  //tao tro temp bat dau tu root 
    while(true) { 
        if(newNode->value == temp->value) return false ; 
        if(newNode->value < temp->value) {
             if(temp->left == nullptr ) {  // ben trai cay ma chua co node thi tao node moi 
                temp->left = newNode ; // di chuyen node sang trái đe tao node moi 
                return true ; // tra ve nhu cux 
             }
             temp = temp->left ; // di chuyen tiep xuong ben trai tao node thanh cong  
        }else  { 
             if(temp->right == nullptr ) {  // di chuyen node xuong ben phai 
                temp->right = newNode;  // tao mot node moi
                return true;  // tra ve true ban dau 
             }
             temp = temp->right ; // chen them một node mới bên tay phải của cây nhị phân  
        }
    }
}

void inorder(Node* n ) { 
     if(!n) return ; 
     inorder(n->left) ; 
     cout << n->value << " " ; 
     inorder(n->right) ; 
}
void printinorder() { inorder(root); 
cout << "\n"  ; 
}

};

int main() { 
     BinarySearchTree* myBST = new BinarySearchTree();
    myBST->insert(10);
    myBST->insert(5);
    myBST->insert(15);
    myBST->insert(7);

    cout << "Root: " << (myBST->root ? myBST->root->value :- 1 ) << '\n';
    myBST->printinorder(); // 5 7 10 15
    delete myBST;
    return 0;
}