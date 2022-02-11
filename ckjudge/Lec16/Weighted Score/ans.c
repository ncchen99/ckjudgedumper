
int cmp(struct weight* a, struct weight* b) {
    return strcmp(a->chapter, b->chapter);
}
// int cmp2(struct score* a, struct score* b) {
//     return strcmp(a->chapter, b->chapter);
// }
void calculate(struct report_card card[], struct weight chapter[], int student_num, int chapter_num) {
    qsort(chapter, chapter_num, sizeof(chapter[0]), cmp);
    for (int i = 0; i < student_num; i++)
        qsort(card[i].record, chapter_num, sizeof(card[i].record[1]), cmp);
    for (int i = 0; i < student_num; i++) {
        card[i].final = 0;
        card[i].max_score = 0;
        card[i].min_score = 10000;
        for (int j = 0; j < chapter_num; j++) {
            card[i].final += chapter[j].percent * card[i].record[j].score;
            card[i].max_score = (card[i].max_score < card[i].record[j].score ? card[i].record[j].score : card[i].max_score);
            card[i].min_score = (card[i].min_score < card[i].record[j].score ? card[i].min_score : card[i].record[j].score);
        }
        card[i].final /= 100;
    }
}
