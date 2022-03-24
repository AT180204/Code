#include<stdio.h>
#include<malloc.h>
typedef struct{
	char ten_hang[20];
	int dongia;
	int soluong;
	int thanh_tien;
}hang;
typedef struct Node{
	hang data;
	struct Node *next;
}Node;
typedef struct{
	Node *head;
	Node *tail;
}list;
void init(list *l){
	l->head=NULL;
	l->tail=NULL;
}
Node *creat_node(hang x){
	Node *p;
	p=(Node*) malloc(sizeof(Node));
	if(p==NULL){
		printf("Loi cap phat");
		return NULL;
	}
	else{
		p->data=x;
		p->next=NULL;
		return p;
	}
}
void nhap_hang(hang *h){
	printf("Nhap ten hang:");
	gets(h->ten_hang);
	printf("Nhap don gia:");
	scanf("%d", &h->dongia);
	printf("Nhap so luong:");
	scanf("%d", &h->soluong);
	getchar();
	h->thanh_tien=h->dongia*h->soluong;
}
void insert_list(list *l, Node *p){
	if(l->tail==NULL){
		l->head=p;
		l->tail=p;
	}
	else{
		p->next=l->tail;
		l->tail=p;
	}
}
void display(list l){
	Node *p=l.tail;
	while(p!=NULL){
		printf("%s\t%d\t%d\t%d", p->data.ten_hang,p->data.dongia, p->data.soluong, p->data.thanh_tien);
		p=p->next;
	}
}

int main(){
	list l;
	hang h;
	nhap_hang(&h);
	init(&l);
	Node *p=creat_node(h);
	insert_list(&l, p);
	display(l);
}
