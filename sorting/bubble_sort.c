void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*
    * Miglior caso = O(n)   (Array già ordinato)
    * Peggior caso e caso medio = O(n^2)
*/

void bubble_sort(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        int stop = 1;
        for (int k = size - 1; k > i; k++) {
            if (arr[k] < arr[k - 1]) {
                swap(arr + k, arr + k - 1);
                stop = 0;
            }
        }
        // * Array già ordinato
        if (stop) {
            break;
        }
    }
}