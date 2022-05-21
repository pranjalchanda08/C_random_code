#include "fifo.h"
#include "stdio.h"
#include "stdlib.h"

#define FIFO_INS &(FIFO_INSTANCE(FIFO_DEMO))            /* Instance Name as fifo_FIFO_DEMO_inst */

FIFO_INIT_BUFFER(FIFO_DEMO, 5, int);                    /* Create Static Buffer and CQ instance */

void main()
{
    int choice;
    int element;
    system("clear");
    printf("Launch FIFO Test\nOwner: Pranjal Chanda (pranjalchanda08@gmail.com)\n");
    while (1) /* CTRL + C to break */
    {
        printf("\nEnter Choice: \n");
        printf("1. Enqueue Element\n");
        printf("2. Dequeue Element\n");
        printf("3. Peak Element\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter Element: ");
            scanf("%d", &element);
            fifo_enqueue(FIFO_INS, (char *)&element) == FIFO_SUCCESS ? 0 : printf("Overflow\n");
            break;
        case 2:
            fifo_dequeue(FIFO_INS, (char *)&element) == FIFO_SUCCESS ? printf("Element Deqeue: %d", element) : printf("Underflow\n");
            break;
        case 3:
            fifo_peak(FIFO_INS, (char *)&element) == FIFO_SUCCESS ? printf("Element Deqeue: %d", element) : printf("Underflow\n");
            break;
        default:
            break;
        }
    }    
}
