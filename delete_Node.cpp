#include <iostream>
using namespace std;
struct node {
      int data; 
      node *next ; 
}  ; 

void delete_node(node* &head) {
    if (head == NULL) return;
    node* temp = head;
    head = head->next; // move head to the next node
    delete temp;
}

int main () { 
    node *head = new node ; 
    head->data = 10 ; 
    head->next = NULL  ; 
    node *second = new node;
    second->data = 20; 
    second->next = NULL;
    head->next = second; // link first node to second node
    cout <<"Before deletion: "<<head->data<< "->" << head->next->data << endl ;
    delete_node(head) ; 
    if(head != NULL) { 
         cout<< "\nAfter deletion: " << head->data << endl;
    }  else  { 
         cout <<"list is empty after deletion" << endl;
    }
    return 0; 
}