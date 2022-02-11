
void addition() {
    float a, b, g, k, *d = &g, *e = &k;
    scanf("%f%f", &a, &b);
    g = a;
    k = b;
    printf("   ");
    print_binary(&a);
    printf("\n+) ");
    print_binary(&b);
    printf("\n---------------------------------------\n   ");

    int c = *(int*)d + *(int*)e;
    print_binary(&c);
    printf("\n%d + %d = %d", (int)g, (int)k, c);
}