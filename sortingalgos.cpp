#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <functional>
#include <vector>

using namespace std;

class Sorter
{
public:
    // Function for Bubble Sort
    void bubbleSort(int a[], int N)
    {
        for (int i = 0; i <= N - 1; i++)
        {
            for (int j = 0; j < N - 1 - i; j++)
            {
                if (a[j] > a[j + 1])
                {
                    swap(a[j], a[j + 1]);
                }
            }
        }
    }

    // Selection Sort
    void selectionSort(int a[], int N)
    {
        int max = 0;
        for (int i = N - 1; i > 0; i--)
        {
            max = i;
            for (int j = 0; j < i; j++)
            {
                if (a[j] > a[max])
                {
                    max = j;
                }
            }
            swap(a[i], a[max]);
        }
    }

    // Insertion Sort
    void insertionSort(int a[], int N)
    {
        for (int i = 1; i <= N - 1; i++)
        {
            int j = i;
            while (j > 0 && a[j - 1] > a[j])
            {
                swap(a[j - 1], a[j]);
                j--;
            }
        }
    }

    // Merge Sort
    void Merge_Sort(int a[], int first, int last)
    {
        if (first < last)
        {
            int mid = (first + last) / 2;
            Merge_Sort(a, first, mid);
            Merge_Sort(a, mid + 1, last);
            Merge(a, first, mid, last);
        }
    }

    void Merge(int a[], int first, int mid, int right)
    {
        int i = 0, k = first, j = 0; // Initialize i, k, and j
        int n1 = mid - first + 1;
        int n2 = right - mid;
        int L[n1], R[n2];

        for (int i = 0; i < n1; i++)
        {
            L[i] = a[first + i];
        }
        for (int j = 0; j < n2; j++)
        {
            R[j] = a[mid + 1 + j];
        }

        while (i < n1 && j < n2)
        {
            if (L[i] > R[j])
            {
                a[k] = R[j];
                j++;
            }
            else
            {
                a[k] = L[i];
                i++;
            }
            k++;
        }
        while (i < n1)
        {
            a[k] = L[i];
            i++;
            k++;
        }
        while (j < n2)
        {
            a[k] = R[j];
            j++;
            k++;
        }
    }

    // Quick Sort Algorithm
    void QuickSort(int a[], int left, int right)
    {
        if (left < right)
        {
            int pivot = Partition(a, left, right);
            QuickSort(a, left, pivot - 1);
            QuickSort(a, pivot + 1, right);
        }
    }

    // Partition Function
    int Partition(int arr[], int left, int right)
    {
        int pivot = arr[right];
        int i = left - 1; // last number smaller than pivot
        for (int j = left; j < right; j++)
        {
            if (arr[j] < pivot)
            {
                i++;
                swap(arr[i], arr[j]);
                // swapping technically only happens when we have j element larger than pivot
                // so that the if condition is skipped
                // when the next smaller element at j position is found it is replaced with
                // i+1 position
            }
        }
        swap(arr[i + 1], arr[right]); // all elements till i posiiton are less than pivot
        // so pivots position is supposed to be at i+1
        return i + 1;
    }
    
    // Counting Sort
    void countSort(int arr[], int n)
    {
        int k = arr[0];
        for (int i = 0; i < n; i++) //finding max element for count array size
        {
            k = max(k, arr[i]);
        }

        int count[k + 1] = {0}; //make new array of size k+1

        for (int i = 0; i < n; i++)
        {
            count[arr[i]]++; //add the count of each element
        }

        for (int i = 1; i <= k; i++)
        {
            count[i] += count[i - 1]; //add previous numbers count too
        }

        int output[n] = {0}; //new output array

        for (int i =0; i <= n-1; i++)
        {
            output[--count[arr[i]]] = arr[i]; //minus the count by 1 and store at that position
        }

        for (int i = 0; i < n; i++)
        {
            arr[i] = output[i]; //make array equal to output array
        }
    }

    // Function to display an array
    void displayArray(int arr[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main()
{
    Sorter s;
    int a[10] = {1, 4, 5, 6, 7, 8, 0, -11, 10, 111};
    s.bubbleSort(a, 10);
    s.displayArray(a, 10);

    int myArray[] = {10, 6, 1, -12, 22, 0};
    // s.selectionSort(myArray, sizeof(myArray) / sizeof(int));
    // s.displayArray(myArray, sizeof(myArray) / sizeof(int));

    int a1[10] = {1, 4, 5, 6, 7, 8, 0, -11, 10, 111};
    s.displayArray(myArray, 6);
    cout << "\n";
    s.insertionSort(myArray, 6);
    s.displayArray(myArray, 6);
    cout << "Result of Merge sort: ";
    s.Merge_Sort(a1, 0, 9);
    s.displayArray(a1, 10);

    cout << "Displaying the result of Quick Sorting Algorithm: ";
    int a2[10] = {1, 4, 5, 6, 7, 8, 0, -11, 10, 111};
    s.QuickSort(a2, 0, 9);
    s.displayArray(a2, 10);

    cout << "\nDisplaying the result through counting sort: ";
    int a3[10] = {1, 4, 5, 6, 7, 8, 0, 10, 111};
    s.countSort(a3, 9);
    s.displayArray(a3, 9);
    return 0;
}
