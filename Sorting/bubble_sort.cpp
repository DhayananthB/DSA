#include <bits/stdc++.h>

using namespace std;

void bubble_sort(int arr[], int n)
{
    // maximum will be moved to last by adjacent swapping

    for (int i = n - 1; i >= 0; i--)
    {
        // Suppose n=6
        // at first iteration 0-5 next -> 0-4 -> 0-3 -> 0-2 -> 0-1
        int didswap=0;
        for (int j = 0; j <= i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                didswap=1;
            }
        }
        if(didswap==0){
            break;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int nums[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    bubble_sort(nums, n);
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
}