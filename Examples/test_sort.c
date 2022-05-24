#include "sort.h"
#include "stdlib.h"

typedef struct ds
{
    char x;
    int prior;
} ds_t;

static ds_t def_buff[] = {
    {'A', 0},
    {'B', 0},
    {'c', 0},
    {'D', 0},
    {'E', 0},
};

static ds_t buff[sizeof(def_buff) / sizeof(ds_t)];

SORT_INSTANCE_STRUCT(DEMO, ds_t, buff, prior);

void main()
{
    int choice;
    system("clear");
    printf("Launch Sort Struct Test\nOwner: Pranjal Chanda (pranjalchanda08@gmail.com)\n");
    while(1)
    {
        printf("\nEnter Choice: \n");
        printf("1. Bubble Sort\n");
        printf("2. Insertion Sort\n");
        scanf("%d", &choice);
        memcpy(buff, def_buff, sizeof(def_buff));
        printf("Structure buffer before sorting: \n");
        for (size_t i = 0; i < sizeof(buff) / sizeof(ds_t); i++)
        {
            printf("%c, %d\n", buff[i].x, buff[i].prior);
        }
        switch (choice)
        {
            case 1:
                bubble_sort(&sort_DEMO_inst, SORT_DIRECTION_DESSENDING);
                break;
            case 2:
                insertion_sort(&sort_DEMO_inst, SORT_DIRECTION_DESSENDING);
                break;
            default:
                printf("Incorrect Choice\n");
                break;
        }

        printf("Structure buffer after sorting: \n");
        for (size_t i = 0; i < sizeof(buff) / sizeof(ds_t); i++)
        {
            printf("%c, %d\n", buff[i].x, buff[i].prior);
        }        
    }
}