#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data, Node *next = nullptr)
    {
        this->data = data;
        this->next = next;
    }
};
void traverse(Node* head){
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* deleteAtBeginning(Node* head){
    if(head==NULL){
        return NULL;
    }
    Node* temp = head;
    head= head->next;
    // free(temp);
    delete temp;
    return head;
}

// array to linked list
Node *convertArrtoLL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *temp = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *newnode = new Node(arr[i]);
        temp->next = newnode;
        temp = newnode;
    }
    return head;
}

int main()
{
    vector<int> arr = {3, 4, 5, 6, 7};
    Node *head = convertArrtoLL(arr);
    traverse(head);
    head = deleteAtBeginning(head);
    cout<< "Deletion at beginning" << endl;
    traverse(head);
    return 0;
}