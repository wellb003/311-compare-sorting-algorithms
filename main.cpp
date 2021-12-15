#include <iostream>
#include <iomanip>
using namespace std;

void display(const int a[], int n) {
  for (int i = 0; i < n; i++) {
    cout << a[i] << ' ';
  }
  cout << endl;
}

void selection_sort(int a[], int n) {
  int pass_num = 0;
  cout << "Selection sort, before sorting: ";
  display(a, n);
  for (int j = 0; j < n - 1; j++){
    pass_num++;
    int min_index = j;
    int comparison = 0;
    int update = 0;
    for (int i = j + 1; i < n; i++) {
      comparison++;
      if (a[i] < a[min_index]) {
        min_index = i;
        update++;
      }
    }
    swap(a[j], a[min_index]);
    cout << "Pass " << pass_num << ": " << comparison << " comparisons and " << update <<  " updates to min_index." << endl;
    cout << "The array is now: ";
    display(a, n);
  }
  cout << "End of selection sort.\n\n";
}

void bubble_sort(int a[], int n) {
  int pass_num = 0;
  cout << "Bubble sort, before sorting: ";
  display(a, n);
  for (int j = n - 1; j > 0; j--){
    pass_num++;
    int comparison = 0;
    int swaps = 0;
    for (int i = 0; i < j; i++) {
      comparison++;
      if (a[i] < a[i + 1]) {
        swaps++;
        swap(a[i], a[i + 1]);
      }
    }
    cout << "Pass " << pass_num << ": " << comparison << " comparisons and " << swaps <<  " swaps." << endl;
    cout << "The array is now: ";
    display(a, n);
  }
  cout << "End of bubble sort.\n\n";
}

void insertion_sort(int a[], int n) {
  int pass_num = 0;
  cout << "Insertion sort, before sorting: ";
  display(a, n);
  for (int j = n - 1; j > 0; j--){
    pass_num++;
    int comparison = 0;
    int swaps = 0;
    bool done = false;  //done moving a[j] up
    for (int i = j; i < n && !done; i++) {
      comparison++;
      if (a[i] < a[i - 1]) {
        swaps++;
        swap(a[i], a[i - 1]);
      } else {  
        done = true;
      }
    }
    cout << "Pass " << pass_num << ": " << comparison << " comparisons and " << swaps <<  " swaps." << endl;
    cout << "The array is now: ";
    display(a, n);
  }
  cout << "End of insertion sort.\n\n";
}

void insertion_sort(int a[], int n, int& comparisons, int& swaps) {
  for (int i = 1; i < n; i++) {
    for (int j = i; j > 0; j--) {
      comparisons++;
      if (a[j - 1] > a[j]) {
        int temp = a[j];
        a[j] = a[j - 1];
        a[j - 1] = temp;
        swaps++;
      }
    }
  }
}

//used https://www.geeksforgeeks.org/merge-sort/ as a reference
 void merge_sort(int a[], int start, int end, int& recursions, int& merges) {
  //base case
  if (start >= end) {
    recursions++;
    return;
  }
  int middle = (start + end)/2;
  //Left subarray is [start ... middle]
  //Right subarray is [middle + 1 ... end]
  int n1 = middle - start + 1;
  int n2 = end - middle;
  //Create temporary arrays
  int left[n1], right[n2];
  //Copy data to the temporary arrays
  for (int i = 0; i < n1; i++) {
    left[i] = a[i];
    merges++;
  }
  for (int j = 0; j < n2; j++) {
    right[j] = a[n1 + j];
    merges++;
  }
  //recursive call - this part creates two sorted arrays
  recursions++;
  merge_sort(left, start, middle, recursions, merges);
  merge_sort(right, middle + 1, end, recursions, merges);
  //Merge sorted arrays back into arr[start, end]
  //index of left subarray
  int i = 0;
  //index of right subarray
  int j = 0;
  //index of merged subarray
  int k = 0;

  while (i < n1 && j < n2) {
    if (left[i] < right[j]) {
      a[k] = left[i];
      i++;
    } else {
      a[k] = right[j];
      j++; 
    }
    merges++;
    k++;
  }
  //add any leftover values from left
  while (i < n1) {
    a[k] = left[i];
    i++;
    k++;
    merges++;
  }
  //add any leftover values from right
  while (j < n2) {
    a[k] = right[j];
    j++;
    k++;
    merges++;
  }
}

int main() {
  int to_sort1[] = {5, 10, 4, 2, 8, 6, 1, 9, 3, 7};
  int to_sort2[] = {5, 10, 4, 2, 8, 6, 1, 9, 3, 7};
  int to_sort3[] = {5, 10, 4, 2, 8, 6, 1, 9, 3, 7};
  int to_sort4[] = {5, 10, 4, 2, 8, 6, 1, 9, 3, 7};
  int to_sort5[] = {5, 10, 4, 2, 8, 6, 1, 9, 3, 7};
  int nElem = sizeof(to_sort1) / sizeof(int);

  cout << "**First we will compare selection, bubble, and insertion sort**\n\n";
  selection_sort(to_sort1, nElem);
  bubble_sort(to_sort2, nElem);
  insertion_sort(to_sort3, nElem);

  cout << "**We will now compare recurrsive insertion and merge sort**\n\n";
  cout << right;
  cout << "Array before sorting: ";
  display(to_sort4, nElem);
  cout << endl;
  cout << setw(27) << "INSERTION SORT" << setw(27) << "MERGE SORT\n";
  cout << left;
  cout << setw(10) << "SIZE" << setw(15) << "COMPARISONS" << setw(15) << "SWAPS" << setw(15) << "RECURSIONS" << "MERGES\n";
  for (int i = 0; i < 11; i++) {
    int comparisons = 0;
    int swaps = 0;
    int recursions = 0;
    int merges = 0;
    insertion_sort(to_sort4, i, comparisons, swaps);
    merge_sort(to_sort5, 0, i - 1, recursions, merges);
    cout << setw(10) << i << setw(15) << comparisons << setw(15) << swaps << setw(15) << recursions << merges << endl;
  }
  cout << "After insertion sort: ";
  display(to_sort4, nElem);
  cout << "After merge sort: ";
  display(to_sort5, nElem);

} 