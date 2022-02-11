void recovering_order(char *order, char **result) {
    char *p = strtok(order, ":");
    *result = malloc(1000000);
    memset(*result, '\0', 100000);
    int c = 0;
    while (p != NULL) {
        char tmp[120] = {};
        int mlen = 10000, j = 0;

        for (int i = 0; i < GOODS_SIZE; i++) {
            for (char *s = names[i]; s < names[i] + strlen(names[i]) - strlen(p) + 1; s++) {
                if (!strncmp(s, p, strlen(p)) && !strcmp(tmp, "")) {
                    // printf("frist name:%s, startfrom:%s\n", names[i], s);
                    strcpy(tmp, names[i]);
                    mlen = s - names[i];
                } else if (!strncmp(s, p, strlen(p)) && s - names[i] < mlen) {
                    strcpy(tmp, names[i]);
                    mlen = s - names[i];
                } else if (!strncmp(s, p, strlen(p)) && s - names[i] == mlen && (strlen(tmp) > strlen(names[i]) || (strcmp(names[i], tmp) < 0 && strlen(tmp) >= strlen(names[i])))) {
                    // printf("name:%s, startfrom:%s\n", names[i], s);
                    strcpy(tmp, names[i]);
                }
            }
        }

        // printf("j:%d", j);
        // qsort(tmp, j, sizeof(tmp[0]), cmp);
        strcat(*result, (c == 0 ? "" : "+"));
        strcat(*result, tmp);
        // printf("%s", tmp);
        c++;
        p = strtok(NULL, ":");
    }
    return;
}
