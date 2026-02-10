//insertion sort, selection sort, bubble sort
#include <iostream>
using namespace std;

template <typename T>
void _swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}
template <typename T>
void insertionSort(T ar[], int length) {
    //loop through everything after first element
    //key is where we know to check the left side
    //need iterator to check left side
    //shift elements
    for (int i = 1; i < length; i++) {
        T key = ar[i];
        int j = i - 1;
        while (j >= 0 && ar[j] > key) {
            ar[j + 1] = ar[j];
            j = j - 1;
        }
        ar[j + 1] = key;
    }

}

template <typename T>
void selectionSort(T ar[], int length) 
{
    for (int i = 0; i < length - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < length; j++)
        {
            if (ar[j] < ar[min_idx]) 
            {
                min_idx = j;
            }
        }
        if (min_idx != i)
        {
            _swap(ar[i], ar[min_idx]);
        }
    }
}

template <typename T>
void bubbleSort( T ar[], int length) {
    for (int passes = 0; passes < length - 1; passes++) {
        for (int i = 0; i < length - passes - 1; i++) {
            if (ar[i] > ar[i + 1]) {
                _swap(ar[i], ar[i + 1]);
            }
        }
    }
}

int main() {
    cout << "Insertion Sort: " << endl;
    int ar1[10] = {1, 5, 3, 7, 34, 56, 34, 9, 16, 25};
    insertionSort(ar1, 10);
    for(int i = 0; i < 10; i++) {
        cout << ar1[i] << " ";
    }
    cout << endl;
    
    cout << "Selection Sort: " << endl;
    int ar2[10] = {1, 5, 3, 7, 34, 56, 34, 9, 16, 25};
    selectionSort(ar2, 10);
    for(int i = 0; i < 10; i++) {
        cout << ar2[i] << " ";
    }
    cout << endl;

    cout << "Bubble Sort: " << endl;
    int ar3[10] = {1, 5, 3, 7, 34, 56, 34, 9, 16, 25};
    bubbleSort(ar3, 10);
    for(int i = 0; i < 10; i++) {
        cout << ar3[i] << " ";
    }
    cout << endl;

    return 0;
}
