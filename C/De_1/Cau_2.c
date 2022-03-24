#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <conio.h>
#include <string.h>
#define true 1
#define false 0

typedef struct
{
    char soBaoDanh[20];
    char hoTen[30];
    float diemToan;
    float diemLy;
    float diemTA;
    float tongDiem;
} DiemThi;

typedef struct node
{
    DiemThi dt;
    struct node* next;
} Node;

Node* pHead = NULL;

DiemThi nhapDiemThi()
{
    DiemThi dt;
    printf("\tNhap so bao danh: ");
    fflush(stdin);
    gets(dt.soBaoDanh);
    printf("\tNhap ho ten: ");
    gets(dt.hoTen);
    printf("\tNhap diem toan: ");
    scanf("%f", &dt.diemToan);
    printf("\tNhap diem ly: ");
    scanf("%f", &dt.diemLy);
    printf("\tNhap diem tieng anh: ");
    scanf("%f", &dt.diemTA);
    dt.tongDiem = dt.diemToan + dt.diemLy + dt.diemTA;
    return dt;
}

Node* taoVaNhapNode()
{
    Node* pNode = (Node*)malloc(sizeof(Node));
    if(pNode == NULL)
        printf("Loi cap phat\n");
    else
    {
        pNode->dt = nhapDiemThi();
        pNode->next = NULL;
    }
    return pNode;
}

void themNodeVaoViTriDau(Node* pNode)
{
    if(pHead == NULL)
        pHead = pNode;
    else
    {
        pNode->next = pHead;
        pHead = pNode;
    }
}

Node* tim_pTail()
{
    Node* i = pHead;
    while (i->next != NULL)
    {
        i=i->next;
    }
    return i;
}

void themNodeVaoViTriCuoi(Node* pNode)
{
    if(pHead == NULL)
        pHead = pNode;
    else
    {
        Node* pTail = tim_pTail();
        pTail->next = pNode;
        pNode->next = NULL;
    }
}

void taoDanhSachSinhVien()
{
    int count=1;
    while (true)
    {
        printf("Nhap thong tin sinh vien thu %d:\n", count++);
        themNodeVaoViTriCuoi(taoVaNhapNode());
        printf("Ban co muon nhap tiep khong?\nBam phim 'y' de nhap tiep: ");
        fflush(stdin);
        char ch = getchar();
        if(ch == 'y')
            continue;
        else
            break;  
    }
}

void hienThiSinhVien(Node* pNode)
{
    printf("%-15s%-30s%-12.2f%-10.2f%-10.2f%-10.2f\n",pNode->dt.soBaoDanh, pNode->dt.hoTen,pNode->dt.diemToan,pNode->dt.diemLy,pNode->dt.diemTA,pNode->dt.tongDiem);
}

void hienThiDanhSach()
{
    int stt=1;
    printf("\t\t\tDANH SACH SINH VIEN\n");
    printf("%-5s%-15s%-30s%-12s%-10s%-10s%-10s\n","STT","SBD","Ho ten","Diem Toan","Diem Ly","Diem TA","Tong");
    for (Node* i = pHead; i != NULL; i=i->next)
    {
        printf("%-5d",stt++);
        hienThiSinhVien(i);  
    } 
    printf("Bam phim bat ky de ve MENU");
    getch();
}

void sapXepTheoDiemToan()
{
    for (Node* i = pHead; i != NULL; i=i->next)
    {
        for (Node* j = i->next; j->next != NULL; j=j->next)
        {
            if(i->dt.diemToan < j->dt.diemToan)
            {
                float tmp = i->dt.diemToan;
                i->dt.diemToan = j->dt.diemToan;
                j->dt.diemToan = tmp;
            }
        }
        
    }
    
}

void sapXepTheoDiemLy()
{
    for (Node* i = pHead; i != NULL; i=i->next)
    {
        for (Node* j = i->next; j->next != NULL; j=j->next)
        {
            if(i->dt.diemLy < j->dt.diemLy)
            {
                float tmp = i->dt.diemLy;
                i->dt.diemLy = j->dt.diemLy;
                j->dt.diemLy = tmp;
            }
        }
        
    }
    
}

void sapXepTheoDiemAnh()
{
    for (Node* i = pHead; i != NULL; i=i->next)
    {
        for (Node* j = i->next; j->next != NULL; j=j->next)
        {
            if(i->dt.diemTA < j->dt.diemTA)
            {
                float tmp = i->dt.diemTA;
                i->dt.diemTA = j->dt.diemTA;
                j->dt.diemTA = tmp;
            }
        }
        
    }
    
}

void sapXepTheoTongDiem()
{
    for (Node* i = pHead; i != NULL; i=i->next)
    {
        for (Node* j = i->next; j->next != NULL; j=j->next)
        {
            if(i->dt.tongDiem < j->dt.tongDiem)
            {
                float tmp = i->dt.tongDiem;
                i->dt.tongDiem = j->dt.tongDiem;
                j->dt.tongDiem = tmp;
            }
        }
        
    }
    
}

void menuSapXep()
{
    printf("\t\tChon loai sap xep\n");
    printf("\t1. Sap xep theo diem toan\n");
    printf("\t2. Sap xep theo diem ly\n");
    printf("\t3. Sap xep theo diem tieng anh\n");
    printf("\t4. Sap xep theo tong diem\n");
    printf("Vui long nhap: ");
}

void sapXepDanhSach()
{
    menuSapXep();
    int chon2;
    scanf("%d",&chon2);
    switch (chon2)
    {
    case 1:
        sapXepTheoDiemToan();
        break;
    case 2:
        sapXepTheoDiemLy();
        break;
    case 3:
        sapXepTheoDiemAnh();
        break;
    case 4:
        sapXepTheoTongDiem();
        break;
    default:
        printf("Chi nhap tu 1 den 4!\n");
        break;
    }
}

void menu()
{
    printf("\t\tMENU\n");
    printf("\t1. Tao danh sach thi sinh\n");
    printf("\t2. Hien thi danh sach thi sinh\n");
    printf("\t3. Sap xep diem thi\n");
    printf("\t4. Ket thuc\n");
    printf("Vui long nhap: ");  
}

int main()
{
    while (true)
    {
        system("cls");
        menu();
        int chon;
        scanf("%d",&chon);
        switch (chon)
        {
        case 1:
            taoDanhSachSinhVien();
            break;
        case 2:
            hienThiDanhSach();
            break;
        case 3:
            sapXepDanhSach();
            break;
        case 4:
            printf("\t\tTam biet!\n");
            exit(0);
        default:
            printf("Chi nhap tu 1 den 4!\n");
            break;
        }
    }
    
    
}