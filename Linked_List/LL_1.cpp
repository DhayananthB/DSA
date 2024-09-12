#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data1,Node* next1=nullptr){
        data=data1;
        next= next1;
    }
};


int main(){
    vector<int> arr = {2,3,4,5};

    // creating object
    Node y = Node(arr[0]);
    cout<< y.data << endl;

    //creating pointer to memory location
    Node* z = new Node(arr[0]);
    cout<< z << endl;
    
    cout << z->data << endl;
    cout << z->next << endl;

    return 0;
}