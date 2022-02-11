int *cmp(void *a, void *b) {
    return **(int **)b - **(int **)a;
}
void sort_pointers(int **ptr_arr, int *arr, int size) {
    for (int i = 0; i < size; i++)
        ptr_arr[i] = &(arr[i]);
    qsort(ptr_arr, size, sizeof((ptr_arr[0])), cmp);
}