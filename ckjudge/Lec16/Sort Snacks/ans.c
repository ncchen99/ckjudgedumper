
void sort_snacks(struct snack snacks[], int n) {
    for (int i = 0; i < n; i++)
        snacks[i].value = snacks[i].weight / (double)snacks[i].price;
    qsort(snacks, n, sizeof(snacks[0]), cmp);
}

int cmp(const void *a, const void *b) {
    struct snack aa = *(struct snack *)a;
    struct snack bb = *(struct snack *)b;
    // printf("%d", ((__uint128_t)(aa.value * 1000)) * (__uint128_t)100000);
    __uint128_t aaa = (((int)(aa.value * 1000)) * (__uint128_t)100000) - aa.price * 10000 - aa.id;
    __uint128_t bbb = (((int)(bb.value * 1000)) * (__uint128_t)100000) - bb.price * 10000 - bb.id;
    return bbb - aaa;
}