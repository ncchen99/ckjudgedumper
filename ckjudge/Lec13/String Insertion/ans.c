void strins(char *P, char *s, char *t) {
    char *l = strstr(P, s);
    while (l != NULL) {
        l += strlen(s);
        char tmp[MAX_LEN_P + 2];
        strcpy(tmp, l);
        strcpy(l, t);
        strcpy(l + strlen(t), tmp);
        l = strstr(l + strlen(t), s);
    }
}