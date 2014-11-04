//
//  main.c
//  LinkedListTest
//
//  Created by ScorpioNeal on 14/11/4.
//  Copyright (c) 2014年 ScorpioNeal. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#define  SUCCESS 1
#define  FAILURE 0

#define TRUE 1
#define FALSE 0

//链表的单个数据结构
typedef struct Node{
    int data;
    struct Node *next;
}Node;

//链表
typedef struct{
    Node *head;
}LinkList;

//创建一个空的链表
int InitList(LinkList *L){
    L->head = (Node *)malloc(sizeof(Node));
    if(L->head){
        L->head->next = NULL;
        return SUCCESS;
    }
    return FAILURE;
}

//销毁链表，即链表都不存在
void DestroyList(LinkList *L){
    Node *p;
    while (L->head) {
        p = L->head;
        L->head = L->head->next;//每次断掉头节点
        free(p);
    }
}

//清空链表，即保存有个头节点
void ClearList(LinkList *L){
    Node *p;
    while (L->head->next) {
        p = L->head->next;
        L->head->next = p->next;
        free(p);
    }
}

//返回链表长度
int ListLength(LinkList *L){
    Node *p;
    int len = 0;
    p = L->head;
    while (p->next) {
        p = p->next;
        len++;
    }
    return len;
}

//判断链表是否为空
int ListEmpty(LinkList *L){
    if(L->head->next == NULL){
        return TRUE;
    }
    return FALSE;
}

//返回链表L中第i个数据元素的内容保存在e中
void GetElement(LinkList *L, int i, int *e){
    int j = 0;
    Node *p;
    if(i < 1 || i > ListLength(L)){
        printf("Not found");
    }else{
        for(p = L->head; j < i; p = p->next, j++){
            *e = p->data;
        }
    }
}

//获取数值等于e的节点
Node *LocateElem(LinkList *L, int e){
    Node *p;
    p = L->head->next;
    while (p && p->data != e) {
        p = p->next;
    }
    return p;
}

//在i处插入新的节点，数值为e
int ListInsert(LinkList *L, int i, int e){
    Node *p, *s;
    int j = 0;
    if(i < 1 || i > ListLength(L) + 1){
        return FAILURE;
    }
    s = (Node *)malloc(sizeof(Node));
    if(s == NULL){
        return FAILURE;
    }
    s->data = e;
    for(p = L->head, j = 0; p != NULL && j < i - 1; p = p->next, j++);//这儿是遍历链表跳到正确位置
    
    s->next = p->next; //这儿是关键
    p->next = s;
    
    return SUCCESS;
}

//删除链表中第i个元素
int ListDelete(LinkList *L, int i, int *e){
    int j = 0;
    Node *p = L->head;
    while (p != NULL && j < i - 1) {
        p = p->next;
        j++;
    }
    if(j < i - 1){
        return FAILURE;
    }
    p->next = p->next->next;//这儿是关键
    free(p);
    return SUCCESS;
}

void VisitList(LinkList *L){
    Node *p = L->head;
    while (p->next != NULL) {
        printf("%d ", p->next->data);
        p = p->next;
    }
}

int main(int argc, const char * argv[]) {

    LinkList list, *L;
    Node *t;
    L = &list;
    
    InitList(L);
    ListInsert(L, 1, 12);
    ListInsert(L, 2, 13);
    ListInsert(L, 1, 14);
    ListInsert(L, 1, 15);
    ListInsert(L, 1, 16);
    ListInsert(L, 3, 17);
    t = LocateElem(L, 14);
    printf("%d \n", t->data);
    VisitList(L);
    DestroyList(L);
    return 0;
}
