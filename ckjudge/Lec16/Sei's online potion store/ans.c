void sum_total_costs(order_t orders[], unsigned order_cnt) {
    for (int i = 0; i < order_cnt; i++) {
        orders[i].total_cost = 0;
        for (int j = 0; j < orders[i].item_cnt; j++)
            orders[i].total_cost += orders[i].items[j].cost * orders[i].items[j].cnt;
    }
}

int cmp(order_t *a, order_t *b) {
    int aa = (a->pick_up_time.hour - '0') * 60 + (a->pick_up_time.minute - '0');
    int bb = (b->pick_up_time.hour - '0') * 60 + (b->pick_up_time.minute - '0');
    return aa - bb;
}

void reorder(order_t orders[], unsigned order_cnt) {
    qsort(orders, order_cnt, sizeof(orders[0]), cmp);
}
