/**
 * Program to rotate an array.
 */
#include <stdio.h>

void rotate(int *arr, int size) {
    // Save last element in buffer.
    int buf = arr[size-1];

    for (int i = size-1; i>0; i--)
        // shift
        arr[i] = arr[i-1];
    arr[0] = buf;
}

void nrotate(int *arr, int size, int n) {
    if (n == 0) return;  // No rotation needed.
    n = n % size;        // Handle the case where n > size
    int buf[n];

    // Save the last n elements of arr into a buffer.
    for (int i=0; i<n; i++)
       buf[i] = arr[size-n+i];

    // Shift by n positions
    for (int i = size-1; i>=n; i--) {
       arr[i] = arr[i-n];
    }

    // Recopy the first n elements from the buffer.
    for (int i=0; i<n; i++)
       arr[i] = buf[i];
}


int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int nshift = 2;

    // for (int i = 0; i<nshift; i++)
    //    rotate(arr, 6);

    nrotate(arr, 6, nshift);

    for (int i = 0; i<=5; i++) {
        printf("%d", arr[i]);
    }

    return 0;
}
