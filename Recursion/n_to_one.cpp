#include <bits/stdc++.h>
using namespace std;

void n_to_one(int n){
    if(n==0){
        return ;
    }
    cout << n << " ";
    n_to_one(n-1);

}

int main(){
    n_to_one(6);
    return 0;
}