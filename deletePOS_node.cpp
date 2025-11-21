#include<bits/stdc++.h>
using namespace std; 
struct node {
    int data; 
    node *next ; 

}; 
struct node *head , *temp ; 
void deletePos(node* &head) { 
struct node *nextnode  ; 
int pos, i = 1;
temp = head ; 
cout << "Enter the position to delete: "; 
cin >>pos ; 
while( i < pos - 1 ) { 
    temp = temp->next ;
    i++;     
}   
nextnode = temp->next; 
temp->next = nextnode->next; 
free(nextnode); 

}
void printList(node* head) {
while (head != NULL) {
    cout << head->data;
    if (head->next != NULL) cout << " -> ";
    head = head->next;
}
cout << endl;
}
int main () { 
node *head = new node ;
node *first = new node ; 
first->data = 5 ; 
first->next = NULL  ; 
node *second = new node;
second->data = 6; 
second->next = NULL;
node *third = new node;
third->data = 1; 
third->next = NULL;
node *fourth = new node;
fourth->data = 2;  
fourth->next = NULL;
head = first;
first->next = second;
second->next = third;
third->next = fourth;
cout << "Initial list: ";
printList(head);
deletePos(head);
cout << "After deletion: ";
printList(head); 
return 0;
}