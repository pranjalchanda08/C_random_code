#include "cq.h"
#include "stdio.h"

#define CQ_INS &(CQ_INSTANCE(CQ_DEMO))          /* Instance Name as cq_CQ_DEMO_inst */

CQ_INIT_BUFFER(CQ_DEMO, 5, int);                /* Create Static Buffer and CQ instance */

void main()
{
    int choice;
    int element;
    while(1)    /* CTRL + C to break */
    {
        printf("\nEnter Choice: \n");
        printf("1. Enqueue Element\n2. Dequeue Element\n3. Peak Element\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter Element: ");
            scanf("%d", &element);
            cq_enqueue(CQ_INS, (uint8_t *)&element);
            break;
        case 2:
            cq_dequeue(CQ_INS, (uint8_t *)&element) == CQ_SUCCESS ? printf("Element Deqeue: %d", element) : printf("Underflow\n");
            break;
        case 3:
            cq_peak(CQ_INS, (uint8_t *)&element) == CQ_SUCCESS ? printf("Element Deqeue: %d", element) : printf("Underflow\n");
            break;
        default:
            break;
        }
    }    
}
