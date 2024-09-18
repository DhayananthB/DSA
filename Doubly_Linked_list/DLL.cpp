#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int data, Node *prev = nullptr, Node *next = nullptr)
    {
        this->data = data;
        this->prev = prev;
        this->next = next;
    }
};

Node *arraytoDLL(vector<int> arr)
{
    Node *head = new Node(arr[0]);
    Node *prev = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i], prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

void displayDLL(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *DeleteAtbeginning(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    Node *temp = head;
    head = head->next;
    head->prev = NULL;
    delete temp;

    return head;
}

Node *DeleteTailofDLL(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (head->next == NULL)
    {
        delete head;
        return NULL;
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    Node *prev = temp->prev;
    prev->next = NULL;
    delete temp;
    return head;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 95};
    Node *head = arraytoDLL(arr);
    displayDLL(head);
    head = DeleteAtbeginning(head);
    displayDLL(head);
    head = DeleteTailofDLL(head);
    displayDLL(head);
    return 0;
}