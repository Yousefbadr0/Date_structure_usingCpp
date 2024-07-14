#include <iostream>
using namespace std;
void selectionSort(int arr[], int n)
{
    int min;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                swap(arr[i], arr[j]);
            }
        }
    }
}
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i - 1, num = arr[i];
        while (j >= 0 && arr[j] > num)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = num;
    }
}
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
}
void merge(int arr1[], int n, int arr2[], int m)
{
    bubbleSort(arr1, n);
    bubbleSort(arr2, m);
    const int size = n + m;
    int arr[size], j = 0, k = 0,i=0;
    while (j < n && k < m)
    {
        if (arr1[j] <= arr2[k])
        {
            arr[i] = arr1[j];
            j++;
        }
        else
        {
            arr[i] = arr2[k];
            k++;
        }
        i++;
    }
    while(j < n)
    {
        arr[i]=arr1[j];
        i++;
        j++;
    }
    while(k < m)
    {
        arr[i]=arr1[k];
        i++;
        k++;
    }
    print(arr, size);
}
void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}
int main()
{
    int arr1[5] = {5, 9, 1, 7, 2};
    int arr2[4] = {4, 3, 8, 6};
    merge(arr1, 5, arr2, 4);
}