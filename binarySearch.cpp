#include <iostream>
#include <algorithm>
using namespace std;
string binarySearch(long long arr[], int l, int r, int key)
{
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (arr[m] == key)
            return "found";
        if (arr[m] > key)
            r = m - 1;
        else
            l = m + 1;
    }
    return "not found";
}
int main()
{
    int n, t;
    cin >> n >> t;
    long long arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    while (t--)
    {
        long long key;
        cin >> key;
        cout << binarySearch(arr, 0, n - 1, key) << endl;
    }
}
