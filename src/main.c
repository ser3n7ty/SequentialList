#include "sequential_list.h"

int main(int argc, char** argv)
{
    int capacity;
    SequentialList *list = (SequentialList *)malloc(sizeof(SequentialList));
    if(list == NULL) {
        fprintf(stderr, "Failed to alloc memory for list");
    }
    printf("Input the capacity: ");
    scanf("%d", &capacity);

    SequentialListInit(list, capacity);
    for(int i=0; i<capacity; ++i) {
        SequentialListInsert(list, i, i);
    }
    SequentialListTraversal(list);
    int index = SequentialListFetchIndex(list, 4);
    printf("The list->elements[%d] is %d.\n", index, SequentialListFetch(list, index));
    SequentialListAlter(list, index, 9);
    SequentialListTraversal(list);
    SequentialListDelete(list, index);
    SequentialListTraversal(list);
    SequentialListDestroy(list);
    return 0;
}
