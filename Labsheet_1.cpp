// 1.	WAP to print sum of odd and sum of even elements in an array. Sample Input:- Arr[]={1,2,3,4,5}
// Sample Output:- SumEven=6 SumOdd=9

#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sumEven = 0, sumOdd = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0)
            sumEven += arr[i];
        else
            sumOdd += arr[i];
    }

    cout << "SumEven=" << sumEven << " SumOdd=" << sumOdd << endl;
    return 0;
}

// 2.	WAP to print the sum of two unequal sizes array into third array. Sample Input:- A[]={1,2,3,4,5} B[]={2,4,6,8,10,12,14}
// Sample Output:- Sum[]={3,6,9,12,15,12,14}

#include <iostream>
using namespace std;

int main() {
    int A[] = {1, 2, 3, 4, 5};
    int B[] = {2, 4, 6, 8, 10, 12, 14};
    int n1 = sizeof(A) / sizeof(A[0]);
    int n2 = sizeof(B) / sizeof(B[0]);
    int n = (n1 > n2) ? n1 : n2;
    int Sum[n];

    for (int i = 0; i < n; i++) {
        if (i < n1 && i < n2)
            Sum[i] = A[i] + B[i];
        else if (i < n1)
            Sum[i] = A[i];
        else
            Sum[i] = B[i];
    }

    cout << "Sum[]={";
    for (int i = 0; i < n; i++) {
        cout << Sum[i];
        if (i < n - 1) cout << ",";
    }
    cout << "}" << endl;
    return 0;
}

// 3.	WAP to print the reverse of an array. Sample Input:- Arr[]={1,2,3,4,5} Sample Output:- 5 4 3 2 1
#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Reversed Array: ";
    for (int i = n - 1; i >= 0; i--) {
        cout << arr[i] << " ";
    }
    return 0;
}

// 4.	WAP to print kth smallest and kth largest element of an array. Sample Input:- Arr[]={1,2,3,4,5} k=2
// Sample Output:- 2nd Smallest=2 2nd Largest=4

#include <iostream>
using namespace std;

void sortArray(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    sortArray(arr, n);
    cout << k << "th Smallest=" << arr[k-1] 
         << " " << k << "th Largest=" << arr[n-k] << endl;
    return 0;
}

// 5.	WAP to print the union and intersection of two arrays. Sample Input:- A[]={1,2,3,4,5} B[]={2,4,6,8,10}
// Sample Output:- Union=1,2,3,4,5,6,8,10 Intersection=2,4

#include <iostream>
using namespace std;

int main() {
    int A[] = {1, 2, 3, 4, 5};
    int B[] = {2, 4, 6, 8, 10};
    int n1 = sizeof(A) / sizeof(A[0]);
    int n2 = sizeof(B) / sizeof(B[0]);

    cout << "Union= ";
    for (int i = 0; i < n1; i++) cout << A[i] << " ";
    for (int i = 0; i < n2; i++) {
        bool found = false;
        for (int j = 0; j < n1; j++) {
            if (B[i] == A[j]) {
                found = true;
                break;
            }
        }
        if (!found) cout << B[i] << " ";
    }

    cout << "\nIntersection= ";
    for (int i = 0; i < n2; i++) {
        for (int j = 0; j < n1; j++) {
            if (B[i] == A[j]) {
                cout << B[i] << " ";
                break;
            }
        }
    }
    return 0;
}

// 6.	WAP to find duplicate elements in an array. Sample Input:- Arr[]={1,4,3,4,5,1}
// Sample Output:- 1 4

#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 4, 3, 4, 5, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Duplicates: ";
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                cout << arr[i] << " ";
                break;
            }
        }
    }
    return 0;
}

// 7.	WAP to determine whether one array is subset of another array. Both arrays are not sorted, different sized and elements are distinct.
// Sample Input:- Arr1[] = {11, 1, 13, 21, 3, 7}, Arr2[] = {11, 3, 7, 1}
// Sample Output:- Yes

#include <iostream>
using namespace std;

int main() {
    int Arr1[] = {11, 1, 13, 21, 3, 7};
    int Arr2[] = {11, 3, 7, 1};
    int n1 = sizeof(Arr1) / sizeof(Arr1[0]);
    int n2 = sizeof(Arr2) / sizeof(Arr2[0]);
    bool isSubset = true;

    for (int i = 0; i < n2; i++) {
        bool found = false;
        for (int j = 0; j < n1; j++) {
            if (Arr2[i] == Arr1[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            isSubset = false;
            break;
        }
    }

    if (isSubset) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}

// 8.	WAP to find the first repeating element in an array. Sample Input:- Arr[] = {10, 5, 3, 4, 3, 5, 6}
// Sample Output:- 5

#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 5, 3, 4, 3, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                cout << "First Repeating Element=" << arr[i] << endl;
                return 0;
            }
        }
    }
    cout << "No repeating element found" << endl;
    return 0;
}
