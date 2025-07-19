#include <bits/stdc++.h>
using namespace std;

void print(vector<int> &arr)
{
    for (int i : arr)
    {
        cout << i << " "; // Change from endl to space for better readability
    }
    cout << endl;
}

void subsequences(vector<int> &ans, vector<int> &arr, int index)
{
    if (index >= arr.size()) // Corrected condition to use arr.size()
    {
        // print(ans);
        for (int i : ans)
        {
            cout << i << " ";
        }
        cout << endl;
        return;
    }
    // Include the current element
    ans.push_back(arr[index]);
    subsequences(ans, arr, index + 1);

    // Exclude the current element
    ans.pop_back();
    subsequences(ans, arr, index + 1); // Call with the next index to skip the current element
}

int main()
{
    // int len;
    // cout << "Enter the number of items: ";
    // cin >> len;
    // cout << endl;
    // vector<int> arr;
    // cout << "Enter the elements: ";
    // while (len--)
    // {
    //     int num;
    //     cin >> num;
    //     arr.push_back(num); // You can also use emplace_back here, but push_back is more common
    // }
    // print(arr);
    vector<int> arr = {1, 2, 3};
    vector<int> ans;
    int index = 0;
    cout << "Generating the subsequences: " << endl;
    subsequences(ans, arr, index);
    return 0;
}
