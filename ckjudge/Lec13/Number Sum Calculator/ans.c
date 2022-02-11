int addition(char str[]) {
    char *a = strtok(str, "+");
    int sum = 0;
    while (a != NULL) {
        sum += atoi(a);
        a = strtok(NULL, "+");
    }
    return sum;
}