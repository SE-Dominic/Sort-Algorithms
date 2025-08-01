#include <iostream>
using namespace std;

template <typename T>
void merge(T arr[], int start, int end) {
   //dynamically create an array with exact size 
    T* t_arr = new T[end + 1];
   //get middle value
    int mid = (start + end) / 2;
    
    //pointers
    int left, right;
    left = start; //pointer for left half
    right = mid + 1; //pointer for right half
    int counter = 0; //for temp array

   while (left <= mid && right <= end) {
    //check who gets entered into array first
    if (arr[left] < arr[right]) {
        t_arr[counter++] = arr[left++];
    } else {
        t_arr[counter++] = arr[right++];
    }
   }
   //copy remaining elements from left and right
   while (left <= mid) {
    t_arr[counter++] = arr[left++];
   }
   while (right <= end) {
    t_arr[counter++] = arr[right++];
   }

   //merge back into original array
   for (int i = 0; i < end - start + 1; i++) {
    arr[start + i] = t_arr[i];
   }
   //destroy temp array
   delete[] t_arr;
}

template <typename T>
void mergeSort(T arr[], int start, int end) {
    //time complexity: ALWAYS -> O(nlog(n))
    //space complexity: O(n)
    //recursive base case
    if (start >= end) {
        return;
    }
     //sort left and right halfs of array
    int mid = (start + end) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
     //merge to one array
    merge(arr, start, end);
}


int main() {
    int array[10] = {5, 2, 6, 19, 9, 3, 1, 5, 12, 43};
    mergeSort(array, 0, 9);
    for (int a = 0; a < 10; a++) {
        cout << array[a] << endl;
    }

    string ar[5] = {"Dominic", "Bryan", "Angela", "Jenna", "Cindy"};
    mergeSort(ar,0, 4);
    for (int i = 0; i < 5; i++) {
        cout << ar[i] << endl;
    }

    return 0;
}