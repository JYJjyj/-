#include <stdio.h>
#include "BinTree.h"
#include <string.h>

int main()
{
    int arr[10] = {0};
    arr[0] = 10;
    memmove(arr+1,arr,1);
    arr[0]=0;
    printf("%d ",arr[0]);
    printf("%d ",arr[1]);
    return 0;
}
