#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> fwdVec;
vector<int> backVec;

// A linked list node
class Node
{
    public:
    int data;
    Node* next;
    Node* prev;
};
 
void deleteNode(Node** head_ref, Node* del)
{
    if (*head_ref == NULL || del == NULL)
        return;
  
    if (*head_ref == del)
        *head_ref = del->next;
  
    if (del->next != NULL)
        del->next->prev = del->prev;
  
    if (del->prev != NULL)
        del->prev->next = del->next;
  
    free(del);
    return;
}

void removeFirstOccurrence(Node** head_ref, int toDelete) {
    if (*head_ref == NULL)
        return;
    
    Node* curr_ref = *head_ref;
    while (curr_ref != nullptr) {
        if (curr_ref->data == toDelete) {
            deleteNode(head_ref, curr_ref);
            return;
        }
        curr_ref = curr_ref->next;
    }
}

/* Given a reference (pointer to pointer)
to the head of a list
and an int, inserts a new node on the
front of the list. */
void push(Node** head_ref, int new_data)
{
    Node* new_node = new Node();
 
    new_node->data = new_data;
 
    new_node->next = (*head_ref);
    new_node->prev = nullptr;
 
    if ((*head_ref) != nullptr)
        (*head_ref)->prev = new_node;
 
    (*head_ref) = new_node;
}
 
/* Given a node as prev_node, insert
a new node after the given node */
void insertAfter(Node* prev_node, int new_data)
{
    if (prev_node == nullptr)
    {
        cout<<"the given previous node cannot be nullptr";
        return;
    }
 
    Node* new_node = new Node();

    new_node->data = new_data;
    new_node->next = prev_node->next;
    
    prev_node->next = new_node;
    new_node->prev = prev_node;
 
    if (new_node->next != nullptr)
        new_node->next->prev = new_node;
}
 
/* Given a reference (pointer to pointer) to the head
of a DLL and an int, appends a new node at the end */
void append(Node** head_ref, int new_data)
{
    Node* new_node = new Node();
 
    Node* last = *head_ref; /* used in step 5*/
 
    new_node->data = new_data;
    new_node->next = nullptr;
 
    if (*head_ref == nullptr)
    {
        new_node->prev = nullptr;
        *head_ref = new_node;
        return;
    }
 
    while (last->next != nullptr)
        last = last->next;
 
    last->next = new_node;
    new_node->prev = last;
    return;
}

void printVector(string &name, vector<int> &value) {
    cout << name << " = { ";
    for (int c: value) {
        cout << c << " ";
    }
    cout << "}" << endl;
}

// This function prints contents of
// linked list starting from the given node
void printList(Node* node)
{
    fwdVec.clear();
    backVec.clear();
    Node* last = nullptr;

    while (node != nullptr)
    {
        //cout<<" "<<node->data<<" ";
        fwdVec.push_back(node->data);
        last = node;
        node = node->next;
    }
    string nameString("Forward");
    printVector(nameString , fwdVec);
 

    while (last != nullptr)
    {
        //cout<<" "<<last->data<<" ";
        backVec.push_back(last->data);
        last = last->prev;
    }
    nameString = "Backward";
    printVector(nameString, backVec);
}
 


/* Driver program to test above functions*/
int main()
{
    std::cout << "Hello, Doubly-linked list World!\n";
    
    /* Start with the empty list */
    Node* head = nullptr;
 
    append(&head, 6); // List = { 6 }
 
    push(&head, 7); // List = { 7, 6 }
 
    push(&head, 1); // List = { 1, 7, 6 }
 
    append(&head, 4); // List = {1, 7, 6, 4}
 
    insertAfter(head->next, 8); // List = {1, 7, 8, 6, 4}
 
    printList(head);
    
    removeFirstOccurrence(&head, 8); // List = {1, 7, 6, 4}
    
    printList(head);
    
    return 0;
}
 


