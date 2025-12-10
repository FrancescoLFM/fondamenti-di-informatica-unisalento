void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*
    * Miglior caso = O(n)   (Array già ordinato)
    * Peggior caso = O(n^2) (Array ordinato "al contrario")
*/

void insertion_sort (int *arr, int size) {
    for (int i = 1; i < size; i++) {
        for (int k = i; k > 0; k--) {
            if (arr[k] < arr[k - 1]) {
                swap(arr + k, arr + k - 1);
            } else {
                break;
            }
        }
    }
}