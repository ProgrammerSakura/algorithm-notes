#include<malloc.h>
#include<stdio.h>

#define MaxSize 10

typedef struct{
    int data[MaxSize];
    int length;
}Sqlist;

void ListDelete(Sqlist *&L, int x)
{
    for(int j=0; j<=L->length-1; j++)
    {
        if(L->data[j] == x) {
            //TODO
        }
    }
}