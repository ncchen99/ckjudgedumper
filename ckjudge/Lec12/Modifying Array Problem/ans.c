
void modify_array(int *p) {
    p -= SIZE / 2;
    if (*p == 1) {
        p++;
        for (int i = 0; i < SIZE; i++)
            if (i % 2 == 0)
                p[i] = p[i] + 10;
    }
    if (*p == 2) {
        p++;
        for (int i = 0; i < SIZE; i++)
            if (i % 3 == 0)
                p[i] = p[i] * 8;
    }
    if (*p == 3) {
        p++;
        for (int i = 0; i < SIZE; i++)
            if (i % 5 == 0)
                p[i] = p[i] - 2;
    }
    return;
}