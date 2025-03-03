#include <iostream>
#include <cstdlib>
using namespace std;

//prototypes
void quickSort(int a[], int start, int end);
int partition(int a[], int start, int end);

int main() { 
  srand(time(0));
  int n;
  cout << "How many numbers would you like to fill? ";
  cin >> n;
  int* arr = new int[n]; //dynamically allocate n spaces in array
  
  cout << "Fill array" << endl;
  for (int i = 0; i < n; i++) {
    arr[i] = rand() % 101;
  }
  
  cout << "Sort the Array: " << endl;
  quickSort(arr, 0, n); //call quick sort algorithm
  for (int a = 0; a < n; a++) {
    if (a % 10 == 0) {
      cout << endl;
    }
    cout << arr[a] << " ";
  }
}

//partition function
int partition(int a[], int s, int e) {
  //mid index
  int mid = s + (e - s) / 2;
  swap(a[mid], a[e]); //swap in case of already sorted array
  int red = s;
  int pivot = a[e]; //pivot is last element
  for (int green = s; green < e; green++) {
    if (a[green] < pivot) { //put values less than pivot on the left side
      swap(a[green], a[red]);
      red++;
    }
  }
  swap(a[red], a[e]); //swap pivot with middle value to put pivot in the middle
  return red; //return index where pivot is located
}

//quick sort function
void quickSort(int a[], int start, int end) {
  if (start >= end) { //if start goes over its boundary
    return;
  }
  int mid = partition(a, start, end); //call partition function and store index returned into mid
  quickSort(a, start, mid - 1); //sort left side
  quickSort(a, mid + 1, end); //sort right side
}
