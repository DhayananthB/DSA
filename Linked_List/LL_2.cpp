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

// length of a linked list
int lengthofLinkedList(Node *head)
{
    int cnt = 0;
    Node *temp = head;
    while (temp)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

// Searching in a linkedlist
bool check(Node *head, int ele)
{
    Node *temp = head;
    while (temp)
    {
        if (temp->data == ele)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int main()
{
    vector<int> arr = {3, 4, 5, 6, 7};
    Node *head = convertArrtoLL(arr);
    cout << head->data << endl;
    cout << head->next->data << endl;

    // traversal
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl
         << "Length of the Linked List is " << lengthofLinkedList(head) << endl;
         
    check(head, 5) ? cout << "Present" << endl : cout << "not present" << endl;
    check(head, 8) ? cout << "Present" << endl : cout << "not present" << endl;

    return 0;
}