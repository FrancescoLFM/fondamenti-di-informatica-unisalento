void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// * Time complexity = O(n^2)
void selection_sort(int *arr, int size) {
    int i = 0;
    for (int i = 0; i < size - 1; i++) {
        int min_index = i;
        for (int k = i + 1; k < size; k++) {
            if (arr[k] < arr[min_index]) {
                min_index = k;
            }
        }
        swap(arr + i, arr + min_index);
    }
}