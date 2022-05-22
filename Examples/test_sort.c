#include "sort.h"
#include "stdlib.h"

typedef struct ds
{
    char x;
    int prior;
} ds_t;

static ds_t buff[] = {
    {'A', 1},
    {'B', 4},
    {'c', 0},
    {'D', 3},
    {'E', 2},
};

SORT_INSTANCE_STRUCT(DEMO, ds_t, buff, prior);

void main()
{
    system("clear");
    printf("Launch Bubble Sort Struct Test\nOwner: Pranjal Chanda (pranjalchanda08@gmail.com)\n");
    printf("Structure buffer before sorting: \n");
    for (size_t i = 0; i < sizeof(buff) / sizeof(ds_t); i++)
    {
        printf("%c, %d\n", buff[i].x, buff[i].prior);
    }
    // bubbleSort(&sort_DEMO_inst);
    insertionSort(&sort_DEMO_inst);

    printf("Structure buffer after sorting: \n");
    for (size_t i = 0; i < sizeof(buff) / sizeof(ds_t); i++)
    {
        printf("%c, %d\n", buff[i].x, buff[i].prior);
    }
}