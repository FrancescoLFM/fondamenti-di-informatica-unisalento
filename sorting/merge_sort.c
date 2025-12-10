/*
    * Il merge sort può essere implementato ricorsivamente o iterativamente
    * Time complexity O(nlog n)
*/
void merge(int *arr, int s, int l, int p) {
    int t[l - s + 1];

    int k = 0;
    int i = 0;
    int j = 0;
    for (; i < p && j <= l; k++) {
        if (arr[i] < arr[j]) {
            t[k] = arr[i];
            i++;
        } else {
            t[k] = arr[j];
            j++;
        }
    }

    for (; i < p; i++) {
        t[k] = arr[i];
    }

    for (int i = 0; i < (l - s + 1); i++) {
        arr[i] = t[i];
    }

}

// * Implementazione ricorsiva
void merge_sort(int *arr, int s, int l) {
    int p = (s + l) / 2;
    if (s >= l) {
        return;
    }
    merge_sort(arr, s, p - 1);
    merge_sort(arr, p, l);

    merge(arr, s, l, p); // * O(n) come complessità
}