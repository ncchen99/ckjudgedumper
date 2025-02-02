void printf_output(int a[], int low, int high, int j);


void printf_output(int a[], int low, int high, int j) {
    for (int i = 0; i < low; i++) {
        printf("%d ", a[i]);
    }
    printf("[ ");
    for (int i = low; i < high + 1; i++) {
        if (i == j)
            printf("*%d ", a[i]);
        else
            printf("%d ", a[i]);
    }
    printf("] ");
    for (int i = high + 1; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void quicksort(int a[], int low, int high) {
    // printf("low: %d, high:%d\n", low, high);
    if (low >= high)
        return;
    int p = a[high], j = low - 1;
    for (int i = low; i < high; i++) {
        if (a[i] <= p) {
            j++;
            swap(a[i], a[j]);
        }
    }
    j += 1;
    swap(a[j], a[high]);

    printf_output(a, low, high, j);

    quicksort(a, low, j - 1);
    quicksort(a, j + 1, high);
    return;
}
