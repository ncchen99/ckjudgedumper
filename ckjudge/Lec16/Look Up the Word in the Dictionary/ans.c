#include <search.h>
int search(dict_t arr[], char target[]) {
    ENTRY e;
    hcreate(10);
    for (size_t i = 0; i < 10; i++) {
        e.key = arr[i].word;
        e.data = (void *)(&arr[i].page);
        hsearch(e, ENTER);
    }
    e.key = target;
    return (hsearch(e, FIND)) ? *(int *)(hsearch(e, FIND)->data) : 0;
}