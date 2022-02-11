Sei\'s online potion store
--------------------------

### Description

<div>

Sei is a researcher at the Medicinal Flora Research Institute. She has
been work there for a year and is struggling to improve her KPI. One day
she finds out that she can sell potions online to improve her poor KPI
(?. After several days of hard working, she has finished a framework of
the ordering system, there are only two little functions that aims to
calculate the total cost of orders and reordering the orders gaps her
from finish, please help her to fulfill those functions.

She currently sells 15 potion products over the online shop that are
given name `Prod_A, Prod_B ..., Prod_O`, each product costs differently,
the information could be found in the finished part (loader code) of the
platform. You do not need to concern the orders with the same pick up
time.![](https://64.media.tumblr.com/a527a758b1d7ad5b066382dd1e879acb/da9735baa45d502a-9e/s400x600/39963fb633c270428befd5937883837e6ae46561.gifv)

</div>

### Input

The first line contains an integer N that indicates the number of orders
which followed by the detail of N orders. For each order, the order ID
comes first, then the pick up time of the order which followed by the
item count M of the order, finally M items and the count are given.

### Output

The order ID and the total cost of the orders, the order that has a
closer pick up time comes first.

### Loader Code

<div>

Your code will be judge using this program:

</div>

    #include <‍stdio.h>
    #include <‍string.h>
    #include <‍stdlib.h>

    typedef struct {
        unsigned char hour;
        unsigned char minute;
    } hm_t;

    typedef struct {
        const char *item_name;
        unsigned cost;
        unsigned cnt;
    } item_t;

    typedef struct {
        unsigned order_id;
        hm_t pick_up_time;
        unsigned total_cost;
        unsigned item_cnt;
        item_t *items;
    } order_t;

    const item_t avaliable_items[] = {
        {"Prod_A",  10},
        {"Prod_B",  20},
        {"Prod_C",  15},
        {"Prod_D",  30},
        {"Prod_E",  50},
        {"Prod_F",  60},
        {"Prod_G",  75},
        {"Prod_H",   5},
        {"Prod_I",  25},
        {"Prod_J",  80},
        {"Prod_K", 100},
        {"Prod_L",  90},
        {"Prod_M",  45},
        {"Prod_N",  40},
        {"Prod_O",  85},
    };

    const unsigned avaliable_item_cnt = 15;
    #define MAX_ORDER_CNT 1024

    unsigned fetch_orders(order_t orders[]);
    void sum_total_costs(order_t orders[], unsigned order_cnt);
    void reorder(order_t orders[], unsigned order_cnt);
    void print_result(order_t orders[], unsigned order_cnt);
    void clean_up(order_t orders[], unsigned order_cnt);

    int main()
    {
        order_t orders[MAX_ORDER_CNT];
        unsigned order_cnt = fetch_orders(orders);
        sum_total_costs(orders, order_cnt);
        reorder(orders, order_cnt);
        print_result(orders, order_cnt);
        clean_up(orders, order_cnt);
        return 0;
    }

    unsigned fetch_orders(order_t orders[])
    {
        unsigned order_cnt;
        scanf("%u", &order_cnt);

        // Prepare the orders.
        order_t *curr = orders;
        for (unsigned i = 0; i <‍ order_cnt; i++, curr++) {
            hm_t *curr_pu = &(curr->pick_up_time);
            scanf("%u %hhu:%hhu %u",
                                    &(curr->order_id),
                                    &(curr_pu->hour),
                                    &(curr_pu->minute),
                                    &(curr->item_cnt));

            // Create a variable length array with malloc.
            item_t *curr_items = curr->items = malloc(sizeof(item_t) * curr->item_cnt);
            for (unsigned j = 0; j <‍ curr->item_cnt; j++) {
                char item_name[32];
                scanf("%s", item_name);
                for (unsigned k = 0; k <‍ avaliable_item_cnt; k++) {
                    if (!strcmp(item_name, avaliable_items[k].item_name)) {
                        // Copy the memory content from avaliable_items to curr_items.
                        curr_items[j] = avaliable_items[k];
                        break;
                    }
                }
                scanf("%u", &(curr_items[j].cnt));
            }
        }
        return order_cnt;
    }

    void print_result(order_t orders[], unsigned order_cnt)
    {
        for (unsigned i = 0; i <‍ order_cnt; i++) {
            printf("#%u %u\n", orders[i].order_id, orders[i].total_cost);
        }
    }

    void clean_up(order_t orders[], unsigned order_cnt)
    {
        for (unsigned i = 0; i <‍ order_cnt; i++) {
            free(orders[i].items);
        }
    }

<div>

### Sample1

#### Input

    3
    123 1:40 2
    Prod_A 2
    Prod_B 3
    234 2:10 3
    Prod_D 12
    Prod_E 1
    Prod_C 4
    345 1:30 4
    Prod_A 3
    Prod_B 5
    Prod_C 1
    Prod_D 2

#### Output

    #345 205
    #123 80
    #234 470

</div>

<div>

### Sample2

#### Input

    5
    100 3:10 1
    Prod_O 1
    101 1:00 3
    Prod_K 2
    Prod_L 5
    Prod_A 20
    102 0:40 2
    Prod_C 4
    Prod_I 2
    103 5:45 1
    Prod_E 2
    104 6:00 4
    Prod_F 1
    Prod_N 1
    Prod_L 1
    Prod_A 1

#### Output

    #102 110
    #101 850
    #100 85
    #103 100
    #104 200

</div>
