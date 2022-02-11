int rising_hope(char *R) {
    int h = 0;
    for (int i = 0; R[i] != '\0'; i++) {
        if (R[i] == 'P')
            h++;
        if (R[i] == 'N')
            h--;
    }
    return h;
}
