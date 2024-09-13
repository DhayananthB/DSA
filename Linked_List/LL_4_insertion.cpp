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

Node *insertionAtHead(Node *head, int val)
{
    Node *newnode = new Node(val, head);
    return newnode;
}

Node *insertionAtTail(Node *head, int val)
{
    Node *newnode = new Node(val);
    if (head == NULL)
    {
        return newnode;
    }
    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    return head;
}

Node *insertAtKthpos(Node *head, int val, int pos)
{
    if (head == NULL)
    {
        if (pos == 1)
        {
            Node *newnode = new Node(val);
            return newnode;
        }
        return NULL;
    }
    if (pos == 1)
    {
        Node *newnode = new Node(val, head);
        return newnode;
    }
    int cnt = 0;
    Node *temp = head;
    while (temp)
    {
        cnt++;
        if (cnt == pos - 1)
        {
            Node *newnode = new Node(val, temp->next);
            temp->next = newnode;
            return head;
        }
    }
    return NULL;
}

Node *insertBeforeK(Node *head, int val, int k)
{
    if (head == NULL)
    {
        return head;
    }
    if (head->data == k)
    {
        Node *newnode = new Node(val, head);
        return newnode;
    }
    Node *temp = head, *prev = NULL;
    while (temp)
    {
        if (temp->data == k)
        {
            Node *newnode = new Node(val, prev->next);
            prev->next = newnode;
            return head;
        }
        prev = temp;
        temp = temp->next;
    }

    return head;
}

int main()
{
    vector<int> arr = {3, 4, 5, 6, 7};
    Node *head = convertArrtoLL(arr);
    traverse(head);
    cout << "Insertion of 88 at beginning" << endl;
    head = insertionAtHead(head, 88);
    traverse(head);
    cout << "Insertion of 18 at end" << endl;
    head = insertionAtTail(head, 18);
    traverse(head);
    cout << "Insertion of 12 at 2nd position" << endl;
    head = insertAtKthpos(head, 12, 2);
    traverse(head);
    cout << "Insertion of 30 at 1st position" << endl;
    head = insertAtKthpos(head, 30, 1);
    traverse(head);
    cout << "Insertion of 69 before 88" << endl;
    head = insertBeforeK(head, 69, 88);
    traverse(head);
    cout << "Insertion of 79 before 30" << endl;
    head = insertBeforeK(head, 79, 30);
    traverse(head);
    cout << "Insertion of 999 before 18" << endl;
    head = insertBeforeK(head, 999, 18);
    traverse(head);

    return 0;
}