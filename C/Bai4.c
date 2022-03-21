#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define true 1
#define false 0

typedef struct
{
	char tenHang[25];
	int donGia;
	int soLuong;
	int thanhTien;
} SoLieuBanHang;

typedef struct node
{
	SoLieuBanHang bh;
	struct node* next;
} node;

node* first = NULL;

node* capPhatNode()
{
	return (node*)malloc(sizeof(node));
}

SoLieuBanHang nhapSoLieuBanHang()
{
	SoLieuBanHang bh;
	printf("\t\t\tNhap ten mat hang: ");
	fflush(stdin);
	gets(bh.tenHang);
	printf("\t\t\tNhap don gia: ");
	scanf("%d",&bh.donGia);
	printf("\t\t\tNhap so luong: ");
	scanf("%d",&bh.soLuong);
	bh.thanhTien = bh.soLuong * bh.donGia;

	return bh;
}

node* taoVaNhapNode()
{
	node* pNode = capPhatNode();
	pNode->bh = nhapSoLieuBanHang();
	pNode->next = NULL;

	return pNode;
}

void themNodeDauTien(node* pNode)
{
	first = pNode;
	pNode->next = NULL;
}

node* timNodeCuoi()
{
	if (first == NULL)
		return NULL;
	node* i = first;
	while (i->next != NULL)
		i = i->next;
	return i;
}

void themNodeViTriCuoi(node* pNode)
{
	if (first == NULL)
		themNodeDauTien(pNode);
	else
	{
		node* lastNode = timNodeCuoi();
		lastNode->next = pNode;
		pNode->next = NULL;
	}
}

void taoDanhSachBanHang(int n)
{
	SoLieuBanHang bh;
	for (int i=0; i<n; i++)
	{
		printf("\t\tNhap mat hang thu %d\n",i+1);
		themNodeViTriCuoi(taoVaNhapNode());
	}
}

void hienThiMatHang(SoLieuBanHang bh)
{
	printf("%-15s%-10d%-12d%-15d\n",bh.tenHang,bh.donGia,bh.soLuong,bh.thanhTien);
}

void hienThiDanhSachBanHang(SoLieuBanHang bh, int n)
{
	printf("\n\t\tSO LIEU BAN HANG\n");
	printf("\n%-6s%-15s%-10s%-12s%-15s\n","STT","Ten hang","Don gia","So luong","Thanh tien");
	int stt = 1;
	node* temp = first;
	for (int i=0; i<n; i++)
	{
		printf(" %-5d",stt++);
		hienThiMatHang(temp->bh);
		temp = temp->next;
	}
}

void menu()
{
	printf("\t\tMENU\n");
	printf("\t1. Nhap danh sach ban hang\n");
	printf("\t2. Hien thi danh sach ban hang\n");
	printf("\t0. Exit\n");
	printf("\t\tVui long chon: ");
}


int main()
{
	int n;
	SoLieuBanHang bh;

	while(true)
	{
		system("cls");
		menu();
		int chon;
		scanf("%d",&chon);
		switch(chon)
		{
			case 1:
			{
				printf("\n\tBan da chon nhap danh sach ban hang\n");
				printf("\tNhap so luong mat hang: ");
				scanf("%d",&n);
				taoDanhSachBanHang(n);
				break;
			}
			case 2:
			{
				printf("\n\tBan da chon hien thi danh sach ban hang\n");
				hienThiDanhSachBanHang(bh,n);
				break;
			}
			case 0:
			{
				exit(0);
			}
			default:
				printf("\n\tVui long chi chon tu 0 den 2\n");
		}
		printf("\n\tNhan phim bat ki de ve menu");
		getch();
	}

	return 0;
}
