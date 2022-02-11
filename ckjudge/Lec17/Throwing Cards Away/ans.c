#include <stdio.h>
#include <stdlib.h>

struct card {
    struct card* next;
    int v;
};

int main() {
    struct card *cur = malloc(sizeof(struct card)), *top = cur, *last;
    int n, op;
    scanf("%d%d", &n, &op);
    for (int i = 0; i < n; i++) {
        cur->next = malloc(sizeof(struct card));
        cur->v = i + 1;
        cur = (i == n - 1 ? cur : cur->next);
    }
    for (int i = 0; i < op; i++) {
        printf("%d ", top->v);
        cur->next = top->next;
        cur = cur->next;
        top->next = top->next->next;
        top = top->next;
    }
}