
#include <stdlib.h>
int *report_card(int *s) {
    int *r = malloc(1200);
    int ss = 0, maxss = 0, c = 0;
    for (int i = 0; s[i] != -1; i++) {
        if (s[i] >= 60)
            ss += s[i];
        else
            ss = 0;
        if (ss > maxss) {
            maxss = ss;
            int c = 0;
            for (int j = i; s[j] >= 60; j--)
                c++;
            int k = 0;
            for (int j = i - c + 1; s[j] >= 60; j++, k++)
                r[k] = s[j];
            r[k] = -1;
        }
    }
    return r;
}