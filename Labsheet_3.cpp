// Bubble Sort in Ascending Order (show array before sorting and after each pass)
#include <iostream>
using namespace std;

void bubbleSortAsc(int arr[], int n) {
    cout << "Original Array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) swap(arr[j], arr[j+1]);
        }
        cout << "After pass " << i+1 << ": ";
        for (int k = 0; k < n; k++) cout << arr[k] << " ";
        cout << endl;
    }
}

int main() {
    int arr[] = {5, 3, 8, 4, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSortAsc(arr, n);
    return 0;
}


// Q2. Bubble Sort in Descending Order (final sorted array only)
#include <iostream>
using namespace std;

void bubbleSortDesc(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] < arr[j+1]) swap(arr[j], arr[j+1]);
        }
    }
    cout << "Sorted Array (Descending): ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {5, 3, 8, 4, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSortDesc(arr, n);
    return 0;
}


// Q3. Insertion Sort in Ascending Order (show passes)
#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {
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
}

int main() {
    int arr[] = {5, 3, 8, 4, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    insertionSort(arr, n);
    return 0;
}


// Q4. Selection Sort in Ascending Order (show min each pass)
#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int minIndex = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[minIndex]) minIndex = j;
        }
        cout << "Pass " << i+1 << ": Minimum selected = " << arr[minIndex] << endl;
        swap(arr[i], arr[minIndex]);
    }
    cout << "Final Sorted Array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {5, 3, 8, 4, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, n);
    return 0;
}


// Q5. Merge Sort (separate functions for Merge and MergeSort)
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
    cout << "Sorted Array: ";
    for (int i=0; i<n; i++) cout << arr[i] << " ";
    cout << endl;
    return 0;
}


//Q6 & Q7. Quick Sort (last element pivot, show partitions)
#include <iostream>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high], i = low-1;
    for (int j=low; j<high; j++) {
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
        for (int k=0; k<n; k++) cout << arr[k] << " ";
        cout << endl;
        quickSort(arr, low, pi-1, n);
        quickSort(arr, pi+1, high, n);
    }
}

int main() {
    int arr[] = {5, 3, 8, 4, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0, n-1, n);
    cout << "Final Sorted Array: ";
    for (int i=0; i<n; i++) cout << arr[i] << " ";
    cout << endl;
    return 0;
}


// Q8. Program to implement all five sorting algorithms (Bubble, Insertion, Selection, Merge, Quick Sort)
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
        int key = arr[i], j=i-1;
        while (j>=0 && arr[j]>key) { arr[j+1]=arr[j]; j--; }
        arr[j+1]=key;
    }
}

// Selection Sort
void selectionSort(int arr[], int n) {
    for (int i=0; i<n-1; i++) {
        int minIndex=i;
        for (int j=i+1; j<n; j++)
            if (arr[j]<arr[minIndex]) minIndex=j;
        swap(arr[i], arr[minIndex]);
    }
}

// Merge Sort
void merge(int arr[], int l, int m, int r) {
    int n1=m-l+1, n2=r-m;
    int L[n1], R[n2];
    for (int i=0;i<n1;i++) L[i]=arr[l+i];
    for (int j=0;j<n2;j++) R[j]=arr[m+1+j];
    int i=0,j=0,k=l;
    while(i<n1 && j<n2) arr[k++]=(L[i]<=R[j])?L[i++]:R[j++];
    while(i<n1) arr[k++]=L[i++];
    while(j<n2) arr[k++]=R[j++];
}
void mergeSort(int arr[], int l, int r) {
    if(l<r){ int m=(l+r)/2; mergeSort(arr,l,m); mergeSort(arr,m+1,r); merge(arr,l,m,r); }
}

// Quick Sort
int partition(int arr[], int low, int high) {
    int pivot=arr[high], i=low-1;
    for(int j=low;j<high;j++) if(arr[j]<pivot) swap(arr[++i],arr[j]);
    swap(arr[i+1],arr[high]); return i+1;
}
void quickSort(int arr[], int low, int high) {
    if(low<high){ int pi=partition(arr,low,high); quickSort(arr,low,pi-1); quickSort(arr,pi+1,high); }
}

void printArray(int arr[], int n) { for(int i=0;i<n;i++) cout<<arr[i]<<" "; cout<<endl; }

int main() {
    int arr[]={5,3,8,4,2}, n=5;
    int temp[n];

    // Bubble
    copy(arr,arr+n,temp); bubbleSort(temp,n); cout<<"Bubble Sort: "; printArray(temp,n);

    // Insertion
    copy(arr,arr+n,temp); insertionSort(temp,n); cout<<"Insertion Sort: "; printArray(temp,n);

    // Selection
    copy(arr,arr+n,temp); selectionSort(temp,n); cout<<"Selection Sort: "; printArray(temp,n);

    // Merge
    copy(arr,arr+n,temp); mergeSort(temp,0,n-1); cout<<"Merge Sort: "; printArray(temp,n);

    // Quick
    copy(arr,arr+n,temp); quickSort(temp,0,n-1); cout<<"Quick Sort: "; printArray(temp,n);

    return 0;
}


// Q9. Compare Bubble, Insertion, Selection Sort (comparisons & swaps)
#include <iostream>
using namespace std;

struct Count { int comp=0, swaps=0; };

void bubbleSort(int arr[], int n, Count &c) {
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++) {
            c.comp++;
            if(arr[j]>arr[j+1]) { swap(arr[j],arr[j+1]); c.swaps++; }
        }
}

void insertionSort(int arr[], int n, Count &c) {
    for(int i=1;i<n;i++) {
        int key=arr[i], j=i-1;
        while(j>=0 && (++c.comp && arr[j]>key)) { arr[j+1]=arr[j]; j--; c.swaps++; }
        arr[j+1]=key;
    }
}

void selectionSort(int arr[], int n, Count &c) {
    for(int i=0;i<n-1;i++) {
        int minIndex=i;
        for(int j=i+1;j<n;j++) { c.comp++; if(arr[j]<arr[minIndex]) minIndex=j; }
        if(minIndex!=i){ swap(arr[i],arr[minIndex]); c.swaps++; }
    }
}

int main() {
    int arr[]={5,3,8,4,2}, n=5;
    int temp[n]; Count c;

    copy(arr,arr+n,temp); c={0,0}; bubbleSort(temp,n,c);
    cout<<"Bubble Sort: Comparisons="<<c.comp<<" Swaps="<<c.swaps<<endl;

    copy(arr,arr+n,temp); c={0,0}; insertionSort(temp,n,c);
    cout<<"Insertion Sort: Comparisons="<<c.comp<<" Swaps="<<c.swaps<<endl;

    copy(arr,arr+n,temp); c={0,0}; selectionSort(temp,n,c);
    cout<<"Selection Sort: Comparisons="<<c.comp<<" Swaps="<<c.swaps<<endl;

    return 0;
}


// Q10. Compare Merge Sort & Quick Sort (time & space complexity)
#include <iostream>
using namespace std;

void merge(int arr[],int l,int m,int r){int n1=m-l+1,n2=r-m;int L[n1],R[n2];for(int i=0;i<n1;i++)L[i]=arr[l+i];for(int j=0;j<n2;j++)R[j]=arr[m+1+j];int i=0,j=0,k=l;while(i<n1&&j<n2)arr[k++]=(L[i]<=R[j])?L[i++]:R[j++];while(i<n1)arr[k++]=L[i++];while(j<n2)arr[k++]=R[j++];}
void mergeSort(int arr[],int l,int r){if(l<r){int m=(l+r)/2;mergeSort(arr,l,m);mergeSort(arr,m+1,r);merge(arr,l,m,r);}}
int partition(int arr[],int low,int high){int pivot=arr[high],i=low-1;for(int j=low;j<high;j++)if(arr[j]<pivot)swap(arr[++i],arr[j]);swap(arr[i+1],arr[high]);return i+1;}
void quickSort(int arr[],int low,int high){if(low<high){int pi=partition(arr,low,high);quickSort(arr,low,pi-1);quickSort(arr,pi+1,high);}}

void printArray(int arr[],int n){for(int i=0;i<n;i++)cout<<arr[i]<<" ";cout<<endl;}

int main(){
    int arr[]={5,3,8,4,2},n=5,temp[n];

    copy(arr,arr+n,temp); mergeSort(temp,0,n-1);
    cout<<"Merge Sort Result: "; printArray(temp,n);
    cout<<"Time Complexity: O(n log n), Space: O(n)"<<endl;

    copy(arr,arr+n,temp); quickSort(temp,0,n-1);
    cout<<"Quick Sort Result: "; printArray(temp,n);
    cout<<"Time Complexity: O(n log n) avg, O(n^2) worst, Space: O(log n)"<<endl;

    return 0;
}


//Q11. Menu-driven program (choose sorting algorithm)
#include <iostream>
using namespace std;

void bubbleSort(int arr[],int n){for(int i=0;i<n-1;i++)for(int j=0;j<n-i-1;j++)if(arr[j]>arr[j+1])swap(arr[j],arr[j+1]);}
void insertionSort(int arr[],int n){for(int i=1;i<n;i++){int key=arr[i],j=i-1;while(j>=0&&arr[j]>key){arr[j+1]=arr[j];j--;}arr[j+1]=key;}}
void selectionSort(int arr[],int n){for(int i=0;i<n-1;i++){int minIndex=i;for(int j=i+1;j<n;j++)if(arr[j]<arr[minIndex])minIndex=j;swap(arr[i],arr[minIndex]);}}
void merge(int arr[],int l,int m,int r){int n1=m-l+1,n2=r-m;int L[n1],R[n2];for(int i=0;i<n1;i++)L[i]=arr[l+i];for(int j=0;j<n2;j++)R[j]=arr[m+1+j];int i=0,j=0,k=l;while(i<n1&&j<n2)arr[k++]=(L[i]<=R[j])?L[i++]:R[j++];while(i<n1)arr[k++]=L[i++];while(j<n2)arr[k++]=R[j++];}
void mergeSort(int arr[],int l,int r){if(l<r){int m=(l+r)/2;mergeSort(arr,l,m);mergeSort(arr,m+1,r);merge(arr,l,m,r);}}
int partition(int arr[],int low,int high){int pivot=arr[high],i=low-1;for(int j=low;j<high;j++)if(arr[j]<pivot)swap(arr[++i],arr[j]);swap(arr[i+1],arr[high]);return i+1;}
void quickSort(int arr[],int low,int high){if(low<high){int pi=partition(arr,low,high);quickSort(arr,low,pi-1);quickSort(arr,pi+1,high);}}

void printArray(int arr[],int n){for(int i=0;i<n;i++)cout<<arr[i]<<" ";cout<<endl;}

int main(){
    int arr[]={5,3,8,4,2},n=5;
    int choice;
    cout<<"Menu:\n1. Bubble\n2. Insertion\n3. Selection\n4. Merge\n5. Quick\nEnter choice: ";
    cin>>choice;
    switch(choice){
        case 1: bubbleSort(arr,n); break;
        case 2: insertionSort(arr,n); break;
        case 3: selectionSort(arr,n); break;
        case 4: mergeSort(arr,0,n-1); break;
        case 5: quickSort(arr,0,n-1); break;
        default: cout<<"Invalid choice"; return 0;
    }
    cout<<"Sorted Array: "; printArray(arr,n);
    return 0;
}


//Q12. Sort ascending then descending (any algorithm, e.g. Bubble)
#include <iostream>
using namespace std;

void bubbleSortAsc(int arr[],int n){for(int i=0;i<n-1;i++)for(int j=0;j<n-i-1;j++)if(arr[j]>arr[j+1])swap(arr[j],arr[j+1]);}
void bubbleSortDesc(int arr[],int n){for(int i=0;i<n-1;i++)for(int j=0;j<n-i-1;j++)if(arr[j]<arr[j+1])swap(arr[j],arr[j+1]);}

void printArray(int arr[],int n){for(int i=0;i<n;i++)cout<<arr[i]<<" ";cout<<endl;}

int main(){
    int arr[]={5,3,8,4,2},n=5;
    bubbleSortAsc(arr,n); cout<<"Ascending: "; printArray(arr,n);
    bubbleSortDesc(arr,n); cout<<"Descending: "; printArray(arr,n);
    return 0;
}


//Q13. Count comparisons in Bubble, Insertion, Selection
#include <iostream>
using namespace std;

void bubbleSort(int arr[],int n,int &comp){for(int i=0;i<n-1;i++)for(int j=0;j<n-i-1;j++){comp++;if(arr[j]>arr[j+1])swap(arr[j],arr[j+1]);}}
void insertionSort(int arr[],int n,int &comp){for(int i=1;i<n;i++){int key=arr[i],j=i-1;while(j>=0&&(comp++,arr[j]>key)){arr[j+1]=arr[j];j--;}arr[j+1]=key;}}
void selectionSort(int arr[],int n,int &comp){for(int i=0;i<n-1;i++){int minIndex=i;for(int j=i+1;j<n;j++){comp++;if(arr[j]<arr[minIndex])minIndex=j;}swap(arr[i],arr[minIndex]);}}

int main(){
    int arr[]={5,3,8,4,2},n=5,temp[n],comp;
    copy(arr,arr+n,temp); comp=0; bubbleSort(temp,n,comp); cout<<"Bubble comparisons="<<comp<<endl;
    copy(arr,arr+n,temp); comp=0; insertionSort(temp,n,comp); cout<<"Insertion comparisons="<<comp<<endl;
    copy(arr,arr+n,temp); comp=0; selectionSort(temp,n,comp); cout<<"Selection comparisons="<<comp<<endl;
    return 0;
}


// Q14. Best-case behavior of Bubble & Insertion (already sorted array)
#include <iostream>
using namespace std;

void bubbleSort(int arr[],int n,int &comp){for(int i=0;i<n-1;i++)for(int j=0;j<n-i-1;j++){comp++;if(arr[j]>arr[j+1])swap(arr[j],arr[j+1]);}}
void insertionSort(int arr[],int n,int &comp){for(int i=1;i<n;i++){int key=arr[i],j=i-1;while(j>=0&&(comp++,arr[j]>key)){arr[j+1]=arr[j];j--;}arr[j+1]=key;}}

int main(){
    int arr[]={1,2,3,4,5},n=5,temp[n],comp;
    copy(arr,arr+n,temp); comp=0; bubbleSort(temp,n,comp); cout<<"Bubble best-case comparisons="<<comp<<endl;
    copy(arr,arr+n,temp); comp=0; insertionSort(temp,n,comp); cout<<"Insertion best-case comparisons="<<comp<<endl;
    return 0;
}

//Q15. Quick Sort on sorted, reverse, random arrays
#include <iostream>
using namespace std;

int partition(int arr[],int low,int high){int pivot=arr[high],i=low-1;for(int j=low;j<high;j++)if(arr[j]<pivot)swap(arr[++i],arr[j]);swap(arr[i+1],arr[high]);return i+1;}
void quickSort(int arr[],int low,int high){if(low<high){int pi=partition(arr,low,high);quickSort(arr,low,pi-1);quickSort(arr,pi+1,high);}}
void printArray(int arr[],int n){for(int i=0;i<n;i++)cout<<arr[i]<<" ";cout<<endl;}

int main(){
    int sorted[]={1,2,3,4,5}, reverse[]={5,4,3,2,1}, random[]={3,5,1,4,2}, n=5;
    quickSort(sorted,0,n-1); cout<<"Quick Sort on sorted: "; printArray(sorted,n);
    quickSort(reverse,0,n-1); cout<<"Quick Sort on reverse: "; printArray(reverse,n);
    quickSort(random,0,n-1); cout<<"Quick Sort on random: "; printArray(random,n);
    cout<<"Observation: Pivot=last element performs poorly on sorted/reverse arrays (O(n^2)), better on random (O(n log n))."<<endl;
    return 0;
}
