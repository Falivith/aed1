#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main(){

    void* pBuffer = malloc(3*sizeof(int));

    printf("\n%p\n", (int*)pBuffer);

    scanf("%d", &((int*)pBuffer) [1] );

    printf("\n%p\n", (int*)pBuffer);

    pBuffer = pBuffer + sizeof(int);

    printf("%d", *(int*)pBuffer);

    printf("\n%p\n", (int*)pBuffer);
    return 0;
}