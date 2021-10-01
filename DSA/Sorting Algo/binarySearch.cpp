#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter size of array - ";
    cin >> n;
    int arr[n];
    cout << "Enter elements - \n";
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    int target;
    cout << "Element to be searched - ";
    cin >> target;

    int start = 0;
    int end = n;
    int counter = 0;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        counter++;
        if (arr[mid] > target)
        {
            end = mid - 1;
        }
        else if (arr[mid] < target)
        {
            start = mid + 1;
        }
        else
        {
            cout << "Index - " << mid;
            break;
        }
    }
    cout << "\nNumber of steps to identfies the number is " << counter;

    return 0;
}