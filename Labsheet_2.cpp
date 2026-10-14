//  1. Write a C++ program to implement Linear Search on an array. Display the position of the key if it is found; otherwise display an appropriate message. 
#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 30;
    bool found = false;

    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            cout << "Key found at position " << i+1 << endl;
            found = true;
            break;
        }
    }
    if (!found) cout << "Key not found" << endl;
    return 0;
}

// 2. Write a C++ program to implement Binary Search on a sorted array. Display the position of the key if it is found.
#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 40;
    int low = 0, high = n-1, mid;
    bool found = false;

    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] == key) {
            cout << "Key found at position " << mid+1 << endl;
            found = true;
            break;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    if (!found) cout << "Key not found" << endl;
    return 0;
}

// 3. Write a C++ program to compare Linear Search and Binary Search for a given array and display their results.
#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++)
        if (arr[i] == key) return i;
    return -1;
}

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n-1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key) return mid;
        else if (arr[mid] < key) low = mid+1;
        else high = mid-1;
    }
    return -1;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 40;

    int pos1 = linearSearch(arr, n, key);
    int pos2 = binarySearch(arr, n, key);

    cout << "Linear Search: ";
    if (pos1 != -1) cout << "Found at position " << pos1+1 << endl;
    else cout << "Not found" << endl;

    cout << "Binary Search: ";
    if (pos2 != -1) cout << "Found at position " << pos2+1 << endl;
    else cout << "Not found" << endl;

    return 0;
}

// 4. Write a C++ program to implement Bubble Sort in ascending order. Display the array after each pass.
#include <iostream>
using namespace std;

int main() {
    int arr[] = {5, 3, 8, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) swap(arr[j], arr[j+1]);
        }
        cout << "After pass " << i+1 << ": ";
        for (int k = 0; k < n; k++) cout << arr[k] << " ";
        cout << endl;
    }
    return 0;
}

// 5. Write a C++ program to implement Bubble Sort in descending order.
#include <iostream>
using namespace std;

int main() {
    int arr[] = {5, 3, 8, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] < arr[j+1]) swap(arr[j], arr[j+1]);
        }
    }

    cout << "Sorted in descending order: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}

// 6. Write a C++ program to implement Insertion Sort in ascending order. Display the array after each insertion/pass.
#include <iostream>
using namespace std;

int main() {
    int arr[] = {5, 3, 8, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 1; i < n; i++) {
        int key = arr[i], j = i-1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;

        cout << "After pass " << i << ": ";
        for (int k = 0; k < n; k++) cout << arr[k] << " ";
        cout << endl;
    }
    return 0;
}

// 7. Write a C++ program to implement Selection Sort in ascending order. Display the minimum element selected in each pass.
#include <iostream>
using namespace std;

int main() {
    int arr[] = {5, 3, 8, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n-1; i++) {
        int minIndex = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[minIndex]) minIndex = j;
        }
        cout << "Pass " << i+1 << ": Minimum selected = " << arr[minIndex] << endl;
        swap(arr[i], arr[minIndex]);
    }

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}

// 8. Write a C++ program to implement Merge Sort using separate functions for merging and sorting. 
#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int r) {
    int n1 = m-l+1, n2 = r-m;
    int L[n1], R[n2];
    for (int i=0; i<n1; i++) L[i] = arr[l+i];
    for (int j=0; j<n2; j++) R[j] = arr[m+1+j];

    int i=0, j=0, k=l;
    while (i<n1 && j<n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i<n1) arr[k++] = L[i++];
    while (j<n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = (l+r)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    int arr[] = {5, 3, 8, 4, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr, 0, n-1);

    cout << "Sorted array: ";
    for (int i=0; i<n; i++) cout << arr[i] << " ";
    return 0;
}

// 9. Write a C++ program to implement Quick Sort using the last element as the pivot.
#include <iostream>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low-1;
    for (int j=low; j<high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

int main() {
    int arr[] = {5, 3, 8, 4, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0, n-1);

    cout << "Sorted array: ";
    for (int i=0; i<n; i++) cout << arr[i] << " ";
    return 0;
}

// 10. Write a C++ program to implement Quick Sort and display the array after each partition.
#include <iostream>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];   
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1; 
}

void quickSort(int arr[], int low, int high, int n) {
    if (low < high) {
        int pi = partition(arr, low, high);

        cout << "After partition at index " << pi << ": ";
        for (int k = 0; k < n; k++) cout << arr[k] << " ";
        cout << endl;

        quickSort(arr, low, pi-1, n);
        quickSort(arr, pi+1, high, n);
    }
}

int main() {
    int arr[] = {5, 3, 8, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n-1, n);

    cout << "Final Sorted Array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}


//  Write a menu-driven C++ program that allows the user to choose Linear Search or Binary Search for a given array. 
#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++)
        if (arr[i] == key) return i;
    return -1;
}

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n-1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key) return mid;
        else if (arr[mid] < key) low = mid+1;
        else high = mid-1;
    }
    return -1;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key;
    int choice;

    cout << "Enter key to search: ";
    cin >> key;
    cout << "Choose search method:\n1. Linear Search\n2. Binary Search\n";
    cin >> choice;

    int pos = -1;
    if (choice == 1) pos = linearSearch(arr, n, key);
    else if (choice == 2) pos = binarySearch(arr, n, key);

    if (pos != -1) cout << "Key found at position " << pos+1 << endl;
    else cout << "Key not found" << endl;

    return 0;
}

//  Write a menu-driven C++ program that allows the user to choose Bubble Sort, Insertion Sort, or Selection Sort. 
#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i=0; i<n-1; i++)
        for (int j=0; j<n-i-1; j++)
            if (arr[j] > arr[j+1]) swap(arr[j], arr[j+1]);
}

void insertionSort(int arr[], int n) {
    for (int i=1; i<n; i++) {
        int key = arr[i], j = i-1;
        while (j>=0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void selectionSort(int arr[], int n) {
    for (int i=0; i<n-1; i++) {
        int minIndex = i;
        for (int j=i+1; j<n; j++)
            if (arr[j] < arr[minIndex]) minIndex = j;
        swap(arr[i], arr[minIndex]);
    }
}

int main() {
    int arr[] = {5, 3, 8, 4, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int choice;

    cout << "Choose sorting method:\n1. Bubble Sort\n2. Insertion Sort\n3. Selection Sort\n";
    cin >> choice;

    if (choice == 1) bubbleSort(arr, n);
    else if (choice == 2) insertionSort(arr, n);
    else if (choice == 3) selectionSort(arr, n);

    cout << "Sorted array: ";
    for (int i=0; i<n; i++) cout << arr[i] << " ";
    return 0;
}

//  Write a C++ program to sort an array using Merge Sort and then search for a given element using Binary Search.
#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int r) {
    int n1 = m-l+1, n2 = r-m;
    int L[n1], R[n2];
    for (int i=0; i<n1; i++) L[i] = arr[l+i];
    for (int j=0; j<n2; j++) R[j] = arr[m+1+j];
    int i=0, j=0, k=l;
    while (i<n1 && j<n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i<n1) arr[k++] = L[i++];
    while (j<n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if (l<r) {
        int m = (l+r)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

int binarySearch(int arr[], int n, int key) {
    int low=0, high=n-1;
    while (low<=high) {
        int mid=(low+high)/2;
        if (arr[mid]==key) return mid;
        else if (arr[mid]<key) low=mid+1;
        else high=mid-1;
    }
    return -1;
}

int main() {
    int arr[] = {5, 3, 8, 4, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key;
    cout << "Enter element to search: ";
    cin >> key;

    mergeSort(arr, 0, n-1);

    cout << "Sorted array: ";
    for (int i=0; i<n; i++) cout << arr[i] << " ";
    cout << endl;

    int pos = binarySearch(arr, n, key);
    if (pos != -1) cout << "Element found at position " << pos+1 << endl;
    else cout << "Element not found" << endl;

    return 0;
}

//  Write a C++ program to implement any two sorting algorithms and compare their number of comparisons for the same input array. 
#include <iostream>
using namespace std;

int bubble_Sort(int arr[], int n) {
    int comparisons = 0;
    for (int i=0; i<n-1; i++)
        for (int j=0; j<n-i-1; j++) {
            comparisons++;
            if (arr[j] > arr[j+1]) swap(arr[j], arr[j+1]);
        }
    return comparisons;
}

int insertion_Sort(int arr[], int n) {
    int comparisons = 0;
    for (int i=1; i<n; i++) {
        int key = arr[i], j = i-1;
        while (j>=0) {
            comparisons++;
            if (arr[j] > key) arr[j+1] = arr[j];
            else break;
            j--;
        }
        arr[j+1] = key;
    }
    return comparisons;
}

int main() {
    int arr1[] = {5, 3, 8, 4, 2};
    int arr2[] = {5, 3, 8, 4, 2};
    int n = sizeof(arr1)/sizeof(arr1[0]);

    int compBubble = bubble_Sort(arr1, n);
    int compInsertion = insertion_Sort(arr2, n);

    cout << "Bubble Sort comparisons: " << compBubble << endl;
    cout << "Insertion Sort comparisons: " << compInsertion << endl;
    return 0;
}

//  Write a C++ program to implement any three sorting algorithms and display their Best, Average, and Worst-case time complexities as comments/output. 
#include <iostream>
using namespace std;

// Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i=0; i<n-1; i++)
        for (int j=0; j<n-i-1; j++)
            if (arr[j] > arr[j+1]) swap(arr[j], arr[j+1]);
}

// Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i=1; i<n; i++) {
        int key = arr[i], j = i-1;
        while (j>=0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

// Selection Sort
void selectionSort(int arr[], int n) {
    for (int i=0; i<n-1; i++) {
        int minIndex = i;
        for (int j=i+1; j<n; j++)
            if (arr[j] < arr[minIndex]) minIndex = j;
        swap(arr[i], arr[minIndex]);
    }
}

int main() {
    int arr[] = {5, 3, 8, 4, 2};
    int n = sizeof(arr)/sizeof(arr[0]);

    // Bubble Sort
    bubbleSort(arr, n);
    cout << "Bubble Sort done.\n";

    // Insertion Sort
    insertionSort(arr, n);
    cout << "Insertion Sort done.\n";

    // Selection Sort
    selectionSort(arr, n);
    cout << "Selection Sort done.\n";

    cout << "\nTime Complexities:\n";
    cout << "Bubble Sort: Best O(n), Average O(n^2), Worst O(n^2)\n";
    cout << "Insertion Sort: Best O(n), Average O(n^2), Worst O(n^2)\n";
    cout << "Selection Sort: Best O(n^2), Average O(n^2), Worst O(n^2)\n";

    return 0;