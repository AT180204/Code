#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#define true 1
#define false 0

typedef struct
{
    char tenSach[30];
    int soLuong;
    char maSach[30];
    char tacGia[30];
    
} Sach;

typedef struct node
{
    Sach s;
    struct node* next;
} Node;

typedef struct 
{
    Node* pHead;
    Node* pTail;
} List;

void init(List* l)
{
    l->pHead=NULL;
    l->pTail=NULL;
}

Node* capPhat()
{
    return (Node*)malloc(sizeof(Node));
}

Sach nhapThongTinSach()
{
    Sach s;
    printf("Nhap ma sach: ");
    fflush(stdin);
    gets(s.maSach);
    printf("Nhap ten sach: ");
    gets(s.tenSach);
    printf("Nhap so luong: ");
    scanf("%d", &s.soLuong);
    fflush(stdin);
    printf("Nhap tac gia: ");
    gets(s.tacGia);
    return s;
}

Node* taoNode()
{
    Node* pNode = capPhat();
    if(pNode == NULL)
        printf("Loi cap phat\n");
    else
    {
        pNode->s=nhapThongTinSach();
        pNode->next=NULL;
    }
    return pNode;
}

void themNodeVaoCuoiDS(List* l, Node* pNode)
{
    if(l->pHead == NULL)
        l->pHead = l->pTail = pNode;
    else
    {
        l->pTail->next = pNode;
        l->pTail = pNode;
    }
}

void nhapDS(List* l)
{
    int count=1;
    while (true)
    {
        printf("Nhap thong tin sach thu %d:\n",count++);
        themNodeVaoCuoiDS(l,taoNode());
        printf("Nhap y de tiep tuc: ");
        char ch = getchar();
        if (ch != 'y' && ch != 'Y')
            break;
    }
       
}

void hienThiDS(List* l)
{
    printf("\t\t\tDANH SACH SACH\n");
    printf("%-5s%-20s%-20s%-20s%-20s\n","STT","Ma sach","Ten sach","So luong","Tac gia");
    int stt=1;
    for (Node* i = l->pHead; i != NULL; i=i->next)
        printf("%-5d%-20s%-20s%-20d%-20s\n", stt++,i->s.maSach,i->s.tenSach,i->s.soLuong,i->s.tacGia);   
}

void sapXepGiamDan(List* l)
{
    for (Node* i = l->pHead; i->next != NULL; i=i->next)
    {
        for (Node* j = i->next; j != NULL; j=j->next)
        {
            if(i->s.maSach < j->s.maSach)
            {
                Sach tmp = i->s;
                i->s = j->s;
                j->s = tmp;
            }
        }   
    }
    hienThiDS(l);  
}

void xoaTheoMaSach(List* l)
{
    char maCanXoa[20];
    printf("Nhap ma cua sach can xoa: ");
    fflush(stdin);
    gets(maCanXoa);
    Node* i = NULL;
    for (i = l->pHead; i != NULL; i=i->next)
        if (strcmp(i->s.maSach,maCanXoa) == 0)
            break;
    if(l->pHead == i)
    {
        l->pHead = l->pHead->next;
        free(i);
    }
    else
    {
        Node* pNode = l->pHead;
        while (pNode->next != i)
            pNode=pNode->next;
        pNode->next = i->next;
        free(i);
    }
     hienThiDS(l);   
}

void menu()
{
	printf("\t\t\tMENU\n");
	printf("\t1.	Tao danh sach\n");
	printf("\t2.	Hien thi danh sach\n");
	printf("\t3.	Sap xep giam dan theo so luong\n");
	printf("\t4.	Xoa theo ma nhap\n");
	printf("\t5.	Ket thuc\n");
	printf("\tVui long nhap so: ");
}

int main()
{
    int chon;
    List l;
    init(&l);
    while (true)
    {
        system("cls");
        menu();
        scanf("%d", &chon);
        switch (chon)
        {
        case 1:
            system("cls");
            nhapDS(&l);
            break;
        case 2:
            system("cls");
            hienThiDS(&l);
            system("pause");
            break;
        case 3:
            system("cls");
            sapXepGiamDan(&l);
            system("pause");
            break;
        case 4:
            system("cls");
            xoaTheoMaSach(&l);
            system("pause");
            break;
        case 5:
            system("cls");
            printf("\t\tBYE!!!");
            exit(0);      
        default:
            printf("Chi nhap tu 1 den 5!!\n");
            system("pause");
            break;
        }
    }
    return 0;
}