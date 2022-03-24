#include <stdio.h>
#include <stdlib.h>
#define true 1

typedef struct
{
    char gioitinh[5];
    char queQuan[30];
    float tongDiem;
    char hoTen[30];

} hocSinh;

typedef union
{
    float diemTD, diemtin;
    hocSinh hs;
} nam;

typedef union
{
    hocSinh hs;
    float diemhat, diemmua;
} nu;
nu Nu[10];
nam Nam[10];

void nhapDuLieuNu(int n)
{
    for(int i=0; i<n; i++)
    {

        printf("Nhap ho ten hoc sinh: ");
        fflush(stdin);
        gets(Nu[i].hs.hoTen);
        printf("que quan: ");
        gets(Nu[i].hs.queQuan);
        printf("Nhap diem hat: ");
        scanf("%f", &Nu[i].diemhat);
        printf("Nhap diem mua: ");
        scanf("%f", &Nu[i].diemmua);
        Nu[i].hs.tongDiem = Nu[i].diemhat+Nu[i].diemmua;
    }
}


void nhapDuLieuNam(int n)
{
    for(int i=0; i<n; i++)
    {

        printf("Nhap ho ten hoc sinh: ");
        fflush(stdin);
        gets((Nam[i].hs).hoTen);
        printf("que quan: ");
        gets(Nam[i].hs.queQuan);
        printf("Nhap diem the duc: ");
        scanf("%f", &Nam[i].diemTD);
        printf("Nhap diem tin: ");
        scanf("%f", &Nam[i].diemtin);
        Nam[i].hs.tongDiem = Nam[i].diemTD+Nam[i].diemtin;

    }
}



void inDanhSachNam(int n)
{
    printf("\t\tDANH SACH NAM\n");
    int stt=1;
    printf("%5s%20s%20s%20s%20s%20s\n", "STT", "Ho ten", "Que", "Diem the duc", "Diem tin", "Tong");
    for(int i=0; i<n; i++)
    {
        printf("%5d%20s%20s%20.2f%20.2f%20.2f\n", stt, Nam[i].hs.hoTen, Nam[i].hs.queQuan, Nam[i].diemTD, Nam[i].diemtin, Nam[i].hs.tongDiem);
        stt++;
    }

}

void inDanhSachNu(int n)
{
    printf("\t\tDANH SACH Nu\n");
    int stt=1;
    printf("%5s%20s%20s%20s%20s%20s\n", "STT", "Ho ten", "Que", "Diem hat", "Diem mua", "Tong");
    for(int i=0; i<n; i++)
    {
        printf("%5d%20s%20s%20.2f%20.2f%20.2f\n", stt, Nu[i].hs.hoTen, Nu[i].hs.queQuan, Nu[i].diemhat, Nu[i].diemmua, Nu[i].hs.tongDiem);
        stt++;
    }

}

void menu()
{
    printf("\t\t\tMenu\n");
    printf("1. Nhap danh sach nam\n");
    printf("2. Nhap danh sach nu\n");
    printf("3. Hien thi danh sach nam\n");
    printf("4. Hien thi danh sach nu\n");
    printf("5. exit(0)\n");
}

int main()
{

    while(true)
    {
        int n,m;
        menu();
        printf("\t\tVui long chon: ");
        int chon;
        scanf("%d", &chon);
        system("cls");
        switch(chon)
        {
        case 1:
        {
            system("cls");
            printf("Nhap so hoc sinh nam: ");
            scanf("%d", &n);
            nhapDuLieuNam(n);
            break;


        }
        case 2:
        {
            system("cls");
            printf("Nhap so hoc sinh nu: ");
            scanf("%d", &m);
            nhapDuLieuNu(m);
            break;

        }
        case 3:
        {
            system("cls");
            inDanhSachNam(n);
            break;

        }
        case 4:
        {
            system("cls");
            inDanhSachNu(m);
            break;

        }
        case 5:
        {
            exit(0);
        }
        default:
        {
            printf("Chi nhap 1-5\n");
        }

        }

    }
}
