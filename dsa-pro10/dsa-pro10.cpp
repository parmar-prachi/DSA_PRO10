#include <iostream>
using namespace std;

// Function to print an array
void printArray(int arr[], int size)
{
    cout << "Array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Selection Sort
void SelectionSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }
    cout << "Selection Sort done!\n";
}

// Bubble Sort
void BubbleSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
    cout << "Array sorted!\n";
}

// Check if array is sorted
bool isSorted(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] > arr[i + 1])
            return false;
    }
    return true;
}

// Linear Search
void LinearSearch(int arr[], int size, int num)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == num)
        {
            cout << "Found at position " << i << " (0-based index)\n";
            return;
        }
    }
    cout << "Not found.\n";
}

// Binary Search (array must be sorted first)
void BinarySearch(int arr[], int size, int num)
{
    int left = 0, right = size - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] == num)
        {
            cout << "Found at position " << mid << " (0-based index)\n";
            return;
        }
        else if (arr[mid] < num)
            left = mid + 1;
        else
            right = mid - 1;
    }
    cout << "Not found.\n";
}

int main()
{
    int size;
    cout << "Enter the number of elements in the array: ";
    cin >> size;

    int arr[100];
    cout << "Enter " << size << " numbers:\n";
    for (int i = 0; i < size; i++)
        cin >> arr[i];

    int choice;
    do
    {
        cout << "\n--- MENU ---\n";
        cout << "1. Selection Sort\n";
        cout << "2. Bubble Sort\n";
        cout << "3. Linear Search\n";
        cout << "4. Binary Search\n";
        cout << "5. Print Array\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            SelectionSort(arr, size);
            break;

        case 2:
            BubbleSort(arr, size);
            break;

        case 3:
        {
            int num;
            cout << "Enter number to search: ";
            cin >> num;
            LinearSearch(arr, size, num);
            break;
        }

        case 4:
        {
            if (!isSorted(arr, size))
            {
                cout << "Array is unsorted. Sorting automatically...\n";
                BubbleSort(arr, size);
            }
            int num;
            cout << "Enter number to search: ";
            cin >> num;
            BinarySearch(arr, size, num);
            break;
        }

        case 5:
            printArray(arr, size);
            break;

        case 0:
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice!\n";
            break;
        }

    } while (choice != 0);

    return 0;
}
