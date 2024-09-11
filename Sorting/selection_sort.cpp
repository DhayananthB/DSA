#include <bits/stdc++.h>
using namespace std;

void selection_sort(int nums[], int n)
{
    int min, temp;
    for (int i = 0; i < n - 1; i++)
    {
        min = i; // we are finding minimum index since we are going to swap it
        for (int j = i; j < n; j++)
        {
            if (nums[j] < nums[min])
            {
                min = j;
            }
        }
        // swapping
        temp = nums[min];
        nums[min] = nums[i];
        nums[i] = temp;
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
    selection_sort(nums, n);
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
}