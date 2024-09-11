#include <bits/stdc++.h>
using namespace std;

void one_to_n(int n){
    if(n==0){
        return;
    }
    one_to_n(n-1);
    cout << n << " ";
}

int main(){
    one_to_n(5);
    return 0;
}