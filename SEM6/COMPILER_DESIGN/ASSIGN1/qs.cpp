#include <bits/stdc++.h>
using namespace std;
int findPivot(int arr[], int low, int high)
{
    int pivot = arr[high];
    int j = low - 1;

    for (int i = low; i <= high - 1; i++)
    {
        if (arr[i] <= pivot)
        {
            j++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[j + 1], arr[high]);
    return j + 1;
}
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int partition = findPivot(arr, low, high);
        quickSort(arr, low, partition - 1);
        quickSort(arr, partition + 1, high);
    }
}
int main()
{
    int n;
    cout << "Enter the size of the array:";
    cin >> n;
    int arr[n];
    cout << "Enter the array elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    quickSort(arr, 0, n - 1);
    cout << "After sorting the array is :\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}