
#include <stdlib.h>
#include <string.h>

struct haha {
    int arr[1000];
    int num;
    int size;
};
int cmp(int *a, int *b) {
    return *a - *b;
}

int cmp2(struct haha *a, struct haha *b) {
    return (a->num) - (b->num);
}
struct node *read_data(int *size) {
    struct haha ha[1005];
    int i = 0;
    for (i = 0; scanf("%d ->", &(ha[i].num)) != EOF; i++) {
        // printf("ha[i].num:%d", ha[i].num);
        int j, tmp;
        // memset(ha[i].arr, 0, 1000);
        scanf("%d", &tmp);
        // printf("%d ", tmp);
        for (j = 0; tmp != 0; j++) {
            ha[i].arr[j] = tmp;
            // printf("%d ", tmp);
            scanf("%d", &tmp);
        }
        ha[i].size = j;
        // printf("\n");
        // for (int k = 0; k < j; k++) {
        //     printf("%d ", ha[i].arr[k]);
        // }
        // printf("j:%d\n", j);
        qsort(ha[i].arr, j, sizeof(int), cmp);
    }
    // printf("i:%d", i);
    qsort(ha, i, sizeof(ha[0]), cmp2);
    for (int w = 0; w < i; w++) {
        printf("%d -> ", ha[w].num);
        for (int j = 0; j < ha[w].size; j++) {
            printf("%d ", ha[w].arr[j]);
        }
        printf("\n");
    }
    exit(0);
}