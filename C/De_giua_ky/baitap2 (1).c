#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define true 1
#define false 0

typedef struct
{
	char masach[10];
	char tensach[20];
	int SL;
	char tacgia[20];
}sach;

typedef struct node
{
	sach dt;
	struct node *next;
}node;

typedef struct 
{
	node *head;
	node *tail;
}list;

void init(list *l)
{
	l->head = l->tail = NULL;
}

sach nhapthongtin()
{
	sach dt;
	printf("Ma Sach: ");
	fflush(stdin);
	gets(dt.masach);
	printf("Ten Sach: ");
	gets(dt.tensach);
	printf("So luong: ");
	scanf("%d",&dt.SL);
	fflush(stdin);
	printf("Tac gia: ");
	gets(dt.tacgia);
	return dt;
}

node* getnode()
{
	node* p;
	p = (node*)malloc(sizeof(node));
	if(p == NULL)
	{
		printf("Loi Cap Phat");
		return NULL;
	}	
	p->dt=nhapthongtin();
	p->next=NULL;
	return p;
}

void themvaocuoiDS(list *l,node *newnode)
{
	if (l->head == NULL)
	{
		l->head = l->tail = newnode;
	}
	else
	{
		l->tail->next = newnode;
		l->tail = newnode;
	}
}

void nhapDS(list *l)
{
	int k=1;
	while(true)
	{
		printf("Nhap thong tin sach thu %d:\n",k++);
		themvaocuoiDS(l,getnode());
		printf("Nhan y de tiep tuc: ");
		fflush(stdin);
		char nhap = getchar();
		if(nhap != 'y' && nhap != 'Y')
		{
			break;
		}
	}
}

void hienthiDS(list l)
{
	printf("\t\t\tDANH SACH SACH\n");
	printf("%3s%20s%20s%20s%20s\n","STT","Ma sach","Ten sach","So luong","Tac gia");
	int stt=1;
	for(node *i=l.head;i != NULL;i=i->next)
	{
		printf("%3d%20s%20s%20d%20s\n",stt++,i->dt.masach,i->dt.tensach,i->dt.SL,i->dt.tacgia);
	}
}

void sapxepgiamdan(list *l)
{
	for(node *i=l->head;i!=NULL;i=i->next)
	{
		for(node *j=i->next;j!=NULL;j=j->next)
		{
			if(i->dt.masach < j->dt.masach)
			{
				sach temp = i->dt;
				i->dt = j->dt;
				j->dt = temp;
			}
		}
	}
	hienthiDS(*l);
}

void xoatheoMaSach(list *l)
{
	char macanxoa[10];
	printf("Nhap ma cua sach can xoa: ");
	fflush(stdin);
	gets(macanxoa);
	node *i = NULL;
	for(i = l->head;i != NULL; i = i->next)
	{
		if(strcmp(i->dt.masach,macanxoa) == 0)
		{
			break;
		}
	}
	if(l->head == i)
	{
		l->head = l->head->next;
		free(i);
	}
	else
	{
		node *p = l->head;
		while(p->next != i)
		{
			p = p->next;
		}
		p->next = i->next;
		free(i);
	}
	hienthiDS(*l);
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
	list l;
	init(&l);
	while(true)
	{
		system("cls");
		menu();
		scanf("%d",&chon);
		switch(chon)
		{
			case 1:
				{
					nhapDS(&l);
					break;
				}
			case 2:
				{
					hienthiDS(l);
					getch();
					break;

				}
			case 3:
				{
					sapxepgiamdan(&l);
					break;
				}
			case 4:
				{
					xoatheoMaSach(&l);
					break;
				}
			case 5:
				{
					printf("\t\tBYE!!");
					exit(0);
				}
			default:
				{
					printf("Vui long chi nhap tu 1 den 5!!");
				}
		}	
	}
	return 0;
}
