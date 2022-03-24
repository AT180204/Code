#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define true 1

typedef struct
{
    float diemTB;
    char gioiTinh[5];
    char hoTen[30];
} SinhVien;

typedef struct node
{
    SinhVien sv;
    struct node* next;
} Node;

Node* capPhat()
{
    return (Node*)malloc(sizeof(Node));
}

Node* taoNode()

