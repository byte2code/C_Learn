#include <stdio.h>

void swap(int* x, int* y);
void quicksort(int array[], int length);
void quicksort_recursion(int array[], int low, int high);
int partition(int array[], int low, int high);

int main() {
    int a[] = {10, 20, 5, 6, 7, 45, 15200, 78, 6, 9, 11, 33, 99};
    int length = sizeof(a) / sizeof(a[0]);
    
    quicksort(a, length);
    
    int i;
    printf("Sorted Array: ");
    for(i = 0; i<length; i++)
        printf("%d ", a[i]);
    
    printf("\nLength of array: %d", length);
    return 0;
}

// swapping left, right and pivot index
void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Calling quick sort Function
void quicksort(int array[], int length){
    quicksort_recursion(array, 0, length-1);
}

// Recursion call Quick Sort
void quicksort_recursion(int array[], int low, int high){
    if(low < high){
        int pivot_index = partition(array, low, high);
        
        // Print to see pivot index
        // printf("Pivot : %d\n", pivot_index);
        
 // Operate over each sub array, on returned pivot index
//  One: from Low to Pivot_Index - 1
//  Other: from Pivot_Index + 1  to high
        quicksort_recursion(array, low, pivot_index-1);
        quicksort_recursion(array, pivot_index+1, high);
    }
}

// Dividing array into sub arrays
int partition(int array[], int low, int high){
    // pivot to the right most element of array
    // two pointer i, j setting to the left most side
// Working

// j             p    (p => Pivot)
// 6 4 5 10 7 3 [4]
// i
// Step 1: As 6 <= 4 (false) increment j by 1
//   j           p
// 6 4 5 10 7 3 [4]
// i
// Step 2: As 4 <= 4 (true). Swap i and j. Increment i by 1, j is usually incremented by 1 in loop
//     j         p
// 4 6 5 10 7 3 [4]
//   i
// Step 3: Again 5 <= 4 (false) Increment j. Same repeat till j index equal to value 3
//            j  p
// 4 6 5 10 7 3 [4]
//   i
// Step 4: 3 <= 4 (true). Swap i and j. Increment i by 1, loop increment j by 1
//              j p
// 4 3 5 10 7 6 [4]
//     i
// Finally: j < high (false). Swap i with high
//              j p
// 4 3 4 10 7 6 [5]
//     i
// Return i as pivot_index for further dividing array into sub array
    
    int i=low, j;
    int pivot_value = array[high];
    
    for(j=low; j < high; j++){
        // Comparing the value of j with the pivot value to swap
        if(array[j] <= pivot_value){
            swap(&array[i], &array[j]);
            i++;
        }
    }
    
    swap(&array[i], &array[high]);
    return i;
}
