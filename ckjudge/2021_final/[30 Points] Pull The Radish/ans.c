int pull_radish(int *l, int *r, int *pos, int x) {
    int ans = 0;
    int *posbk = pos;
    pos -= x;
    while (pos >= l) {
        *pos = 0;
        pos -= x;
        ans++;
    }
    posbk += x;
    while (posbk <= r) {
        *posbk = 0;
        posbk += x;
        ans++;
    }
    return ans;
}