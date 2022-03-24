#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>
#define true 1
#define MAX 1000

typedef struct node
{
    int data;
    struct node* next;
} Node;

Node* capPhat()
{
    return (Node*)malloc(sizeof(Node));
}

void nhapMang("")

int main()
{
    int n;
    printf("Nhap so luong cac so trong day: ");
    scanf("%d", &n);
}