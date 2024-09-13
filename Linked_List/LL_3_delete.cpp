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
void traverse(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *deleteAtBeginning(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *temp = head;
    head = head->next;
    // free(temp);
    delete temp;
    return head;
}

//delete element at the tail
Node *deleteAtEnd(Node* head){
    if(head==NULL || head->next==NULL){
        return NULL;
    }
    Node* temp = head;
    while(temp->next->next){
        temp=temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;
}

// delete kth element
Node *deleteKthelement(Node* head,int k){
    if(head==NULL){
        return head;
    }
    if(k==1){
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    Node* temp=head,*prev = NULL;
    int cnt=0;
    while(temp){
        cnt++;
        if(cnt==k){
            prev->next = prev->next->next;
            free(temp);
            return head;
        }
        prev = temp;
        temp = temp->next;
    }

    return head;
}

// delete the value
Node *deletetheValue(Node* head,int k){
    if(head==NULL){
        return head;
    }
    if(head->data==k){
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    Node* temp=head,*prev = NULL;
    while(temp){
        if(temp->data==k){
            prev->next = prev->next->next;
            free(temp);
            return head;
        }
        prev = temp;
        temp = temp->next;
    }

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
    vector<int> arr = {3, 4, 5, 6, 92, 56, 88, 7, 70};
    Node *head = convertArrtoLL(arr);
    traverse(head);
    head = deleteAtBeginning(head);
    cout << "Deletion at beginning" << endl;
    traverse(head);
    cout << "Deletion at End" << endl;
    head = deleteAtEnd(head);
    traverse(head);
    cout << "Deletion of 3rd element"<< endl;
    head = deleteKthelement(head,3);
    traverse(head);
    cout << "Deletion of 10th element"<< endl;
    head = deleteKthelement(head,10);
    traverse(head);
    cout << "Deletion of 1st element"<< endl;
    head = deleteKthelement(head,1);
    traverse(head);
    cout << "Deletion of 88"<< endl;
    head = deletetheValue(head,88);
    traverse(head);
    cout << "Deletion of 5"<< endl;
    head = deletetheValue(head,5);
    traverse(head);
    return 0;
}