#include <bits/stdc++.h>
using namespace std;

class Sort
{
    int size;
    int *arr;

public:
    Sort(int n)
    {
        this->size = n;
        arr = new int[size];
    }

    void setVal()
    {
        for (int i = 0; i < size; i++)
        {
            cout << "Enter value you want to insert at index " << i << ": ";
            cin >> arr[i];
        }
    }

    void bubbleSortA()
    {
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = 0; j < size - 1 - i; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    int temp = arr[j + 1];
                    arr[j + 1] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }

    void bubbleSortD()
    {
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = 0; j < size - 1 - i; j++)
            {
                if (arr[j] < arr[j + 1])
                {
                    int temp = arr[j + 1];
                    arr[j + 1] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }

    void insertionSortA()
    {
        for (int i = 1; i <= size - 1; i++)
        {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key)
            {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }

    void insertionSortD()
    {
        for (int i = 1; i <= size - 1; i++)
        {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] < key)
            {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }

    void selectionSortA()
    {
        int indexOfmin;
        for (int i = 0; i < size - 1; i++)
        {
            indexOfmin = i;
            for (int j = i + 1; j < size; j++)
            {
                if (arr[j] < arr[indexOfmin])
                {
                    indexOfmin = j;
                }
            }
            int temp = arr[indexOfmin];
            arr[indexOfmin] = arr[i];
            arr[i] = temp;
        }
    }

    void selectionSortD()
    {
        int indexOfmax;
        for (int i = 0; i < size - 1; i++)
        {
            indexOfmax = i;
            for (int j = i + 1; j < size; j++)
            {
                if (arr[j] > arr[indexOfmax])
                {
                    indexOfmax = j;
                }
            }
            int temp = arr[indexOfmax];
            arr[indexOfmax] = arr[i];
            arr[i] = temp;
        }
    }

    int PartitionA(int low, int high)
    {
        int i, j, pivot;
        pivot = arr[low];
        i = low + 1;
        j = high;
        do
        {
            if (arr[i] < pivot)
            {
                i++;
            }
            if (arr[j] > pivot)
            {
                j--;
            }
            if (i < j)
            {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        } while (i < j);
        int t = arr[low];
        arr[low] = arr[j];
        arr[j] = t;
        return j;
    }

    void quickSortA(int low, int high)
    {
        int p;
        if (low < high)
        {
            p = PartitionA(low, high);
            quickSortA(low, p - 1);
            quickSortA(p + 1, high);
        }
    }

    int PartitionD(int low, int high)
    {
        int i, j, pivot;
        pivot = arr[low];
        i = low + 1;
        j = high;
        do
        {
            if (arr[i] > pivot)
            {
                i++;
            }
            if (arr[j] < pivot)
            {
                j--;
            }
            if (i < j)
            {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        } while (i < j);
        int t = arr[low];
        arr[low] = arr[j];
        arr[j] = t;
        return j;
    }

    void quickSortD(int low, int high)
    {
        int p;
        if (low < high)
        {
            p = PartitionD(low, high);
            quickSortD(low, p - 1);
            quickSortD(p + 1, high);
        }
    }

    void mergeA(int low, int mid, int high)
    {
        int i, j, b[size + 1], k = low;
        i = low;
        j = mid + 1;
        while (i <= mid && j <= high)
        {
            if (arr[i] < arr[j])
            {
                b[k] = arr[i];
                k++;
                i++;
            }
            else
            {
                b[k] = arr[j];
                k++;
                j++;
            }
        }
        while (i <= mid)
        {
            b[k] = arr[i];
            k++;
            i++;
        }
        while (j <= high)
        {
            b[k] = arr[j];
            k++;
            j++;
        }
        for (int i = low; i <= high; i++)
        {
            arr[i] = b[i];
        }
    }

    void mergeSortA(int low, int high)
    {
        int mid;
        if (low < high)
        {
            mid = (low + high) / 2;
            mergeSortA(low, mid);
            mergeSortA(mid + 1, high);
            mergeA(low, mid, high);
        }
    }

    void mergeD(int low, int mid, int high)
    {
        int i, j, b[size + 1], k = low;
        i = low;
        j = mid + 1;
        while (i <= mid && j <= high)
        {
            if (arr[i] > arr[j])
            {
                b[k] = arr[i];
                k++;
                i++;
            }
            else
            {
                b[k] = arr[j];
                k++;
                j++;
            }
        }
        while (i <= mid)
        {
            b[k] = arr[i];
            k++;
            i++;
        }
        while (j <= high)
        {
            b[k] = arr[j];
            k++;
            j++;
        }
        for (int i = low; i <= high; i++)
        {
            arr[i] = b[i];
        }
    }

    void mergeSortD(int low, int high)
    {
        int mid;
        if (low < high)
        {
            mid = (low + high) / 2;
            mergeSortD(low, mid);
            mergeSortD(mid + 1, high);
            mergeD(low, mid, high);
        } 
    }

    void countSortA()
    {
        int max = *max_element(arr, arr + size);
        int count[max + 1];
        for (int i = 0; i < max + 1; i++)
        {
            count[i] = 0;
        }
        for (int i = 0; i < size; i++)
        {
            count[arr[i]]++;
        }
        int j = 0;
        for (int i = 0; i < max + 1;)
        {
            if (count[i] > 0)
            {
                arr[j] = i;
                j++;
                count[i]--;
            }
            else
            {
                i++;
            }
        }
    }

    void countSortD()
    {
        int max = *max_element(arr, arr + size);
        int count[max + 1];
        for (int i = 0; i < max + 1; i++)
        {
            count[i] = 0;
        }
        for (int i = 0; i < size; i++)
        {
            count[arr[i]]++;
        }
        int j = 0;
        for (int i = max; i >= 0;)
        {
            if (count[i] > 0)
            {
                arr[j] = i;
                j++;
                count[i]--;
            }
            else
            {
                i--;
            }
        }
    }

    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    int s;
    cout << "Enter the size of array: ";
    cin >> s;
    Sort S(s);
    S.setVal();
    cout << "\nInitial Array:" << endl;
    S.display();
    while (true)
    {
        cout << "\n\n------Menu Driven Program For Sorting------" << endl;
        cout << "1. Ascending Order through Bubble sort" << endl;
        cout << "2. Descending Order through Bubble sort" << endl;
        cout << "3. Ascending Order through Insertion sort" << endl;
        cout << "4. Descending Order through Insertion sort" << endl;
        cout << "5. Ascending Order through Selection sort" << endl;
        cout << "6. Descending Order through Selection sort" << endl;
        cout << "7. Ascending Order through Quick sort" << endl;
        cout << "8. Descending Order through Quick sort" << endl;
        cout << "9. Ascending Order through Merge sort" << endl;
        cout << "10. Descending Order through Merge sort" << endl;
        cout << "11. Ascending Order through Count sort" << endl;
        cout << "12. Descending Order through Count sort" << endl;
        cout << "13. Exit" << endl;
        cout << "-------------------------------------------" << endl;
        int choice;
        cout << "\nEnter you choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            S.bubbleSortA();
            cout << "Sorted Array:" << endl;
            S.display();
            break;
        case 2:
            S.bubbleSortD();
            cout << "Sorted Array:" << endl;
            S.display();
            break;
        case 3:
            S.insertionSortA();
            cout << "Sorted Array:" << endl;
            S.display();
            break;
        case 4:
            S.insertionSortD();
            cout << "Sorted Array:" << endl;
            S.display();
            break;
        case 5:
            S.selectionSortA();
            cout << "Sorted Array:" << endl;
            S.display();
            break;
        case 6:
            S.selectionSortD();
            cout << "Sorted Array:" << endl;
            S.display();
            break;
        case 7:
            S.quickSortA(0, s - 1);
            cout << "Sorted Array:" << endl;
            S.display();
            break;
        case 8:
            S.quickSortD(0, s - 1);
            cout << "Sorted Array:" << endl;
            S.display();
            break;
        case 9:
            S.mergeSortA(0, s - 1);
            cout << "Sorted Array:" << endl;
            S.display();
            break;
        case 10:
            S.mergeSortD(0, s - 1);
            cout << "Sorted Array:" << endl;
            S.display();
            break;
        case 11:
            S.countSortA();
            cout << "Sorted Array:" << endl;
            S.display();
            break;
        case 12:
            S.countSortD();
            cout << "Sorted Array:" << endl;
            S.display();
            break;
        case 13:
            cout << "Exiting..." << endl;
            exit(0);
        default:
            break;
        }
    }
    return 0;
}
