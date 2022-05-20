#include "cq.h"
#include "stdio.h"
#define CQ_INS &(CQ_INSTANCE(Demo))

CQ_INIT_BUFFER(Demo, 10, int);

void main()
{
    int choice;
    int element;
    while(1)
    {
        printf("\nEnter Choice: \n");
        printf("1. Enqueue element\n2. Dequeue Element\n");
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

        default:
            break;
        }
    }    
}
