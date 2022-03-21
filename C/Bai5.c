#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define true 1

typedef struct
{   
    char queQuan[30];
    char hoTen[30];
    float tongDiem;
    
    
    char gioiTinh[5];
} HocSinh;

typedef struct
{
    float diemTD, diemTin;
    HocSinh hs;
} Nam;

typedef union 
{
    float diemHat, diemMua;
    HocSinh hs;
} Nu;

Nam nam[30];
Nu nu[30];

void nhapDuLieuNam(int n)
{
    for(int i=0; i<n; i++)
    {
        printf("Nhap ho ten hoc sinh: ");
        fflush(stdin);
        gets(nam[i].hs.hoTen);
        printf("Nhap que quan: ");
        gets(nam[i].hs.queQuan);
        printf("Nhap diem the duc: ");
        scanf("%f", &nam[i].diemTD);
        printf("Nhap diem tin: ");
        scanf("%f", &nam[i].diemTin);
        nam[i].hs.tongDiem = nam[i].diemTD + nam[i].diemTin;
    }
}

void nhapDuLieuNu(int n)
{
    for(int i=0; i<n; i++)
    {
        printf("Nhap ho ten hoc sinh: ");
        fflush(stdin);
        gets(nu[i].hs.hoTen);
        printf("Nhap que quan: ");
        gets(nu[i].hs.queQuan);
        printf("Nhap diem hat: ");
        scanf("%f", &nu[i].diemHat);
        printf("Nhap diem mua: ");
        scanf("%f", &nu[i].diemMua);
        nu[i].hs.tongDiem = nu[i].diemHat + nu[i].diemMua;
    }
}

void inDanhSachNam(int n)
{
    printf("\t\tDANH SACH NAM\n");
    int stt=1;
    printf("%5s%20s%20s%20s%20s%20s\n","STT", "Ho ten", "Que", "Diem the duc", "Diem tin", "Tong");
    for(int i=0; i<n; i++)
        printf("%5d%20s%20s%20.2f%20.2f%20.2f\n", stt++, nam[i].hs.hoTen, nam[i].hs.queQuan, nam[i].diemTD, nam[i].diemTin, nam[i].hs.tongDiem);
}

void inDanhSachNu(int n)
{
    printf("\t\tDANH SACH NU\n");
    int stt=1;
    printf("%5s%20s%20s%20s%20s%20s\n",  "STT", "Ho ten", "Que", "Diem the duc", "Diem tin", "Tong");
    for(int i=0; i<n; i++)
        printf("%5d%20s%20s%20.2f%20.2f%20.2f\n", stt++, nu[i].hs.hoTen, nu[i].hs.queQuan, nu[i].diemHat, nu[i].diemMua, nu[i].hs.tongDiem);
}

void menu()
{
    printf("\t\tMenu\n");
    printf("1. Nhap danh sach nam\n");
    printf("2. Nhap danh sach nu\n");
    printf("3. Hien thi danh sach nam\n");
    printf("4. Hien thi danh sach nu\n");
    printf("0. exit\n");
}

int main()
{
    while (true)
    {
        int n,m;
        menu();
        printf("\t\tVui long chon: ");
        int chon;
        scanf("%d", &chon);
        system("cls");
        switch (chon)
        {
        case 1:
            system("cls");
            printf("Nhap so hoc sinh nam: ");
            scanf("%d", &n);
            nhapDuLieuNam(n);
            break;
        case 2:
            system("cls");
            printf("Nhap so hoc sinh nu: ");
            scanf("%d", &m);
            nhapDuLieuNu(m);
            break;
        case 3:
            system("cls");
            inDanhSachNam(n);
            break;
        case 4:
            system("cls");
            inDanhSachNu(m);
            break;
        case 0:
            exit(0);
        default:
            printf("Chi nhap tu 0-4!\n");
            break;
        }
    }
    return 0;
}