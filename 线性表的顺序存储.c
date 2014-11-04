//
//  main.c
//  ListTest
//
//  Created by ScorpioNeal on 14/11/4.
//  Copyright (c) 2014年 ScorpioNeal. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 50

typedef int ElemType;

typedef struct{
    ElemType data[MAXSIZE];
    int len;
} SqList;

#define TRUE 1
#define FALSE -1

typedef enum{
    ERROR = -1,
    OK = 1
}Status;

//返回线性表第i个元素位置, 存储在a里面
Status GetElem(SqList S, int i, ElemType *a){
    if((S.len == 0) || ( i < 1)||( i > S.len)){
        return ERROR;
    }
    *a = S.data[i - 1];
    return OK;
}

//在线性表S的第i个位置之前插入元素a
//即插入位置后面一直到最后都往后移动一个位子
Status ListInsert(SqList *s, int i, ElemType a){
    int j;
    if(s->len == MAXSIZE){
        return ERROR;
    }
    if((i < 1) || (i > s->len + 1)){
        return ERROR;
    }
    if(i < s->len){
        for(j = s->len; j >= i -1; j--){
            s->data[j+1]=s->data[j];
        }
    }
    s->data[i - 1] = a;
    s->len++;
    return OK;
}

//删除线性表S的第i个元素
//即i+1号元素之后都往前移动一个位置
Status ListDelete(SqList *s, int i , ElemType *a){
    int j;
    if(s->len  == 0){
        return ERROR;
    }
    if((i < 1) || (i > s->len)){
        return ERROR;
    }
    
    *a = s->data[i - 1];
    if(i < s->len){
        for(j = i; j < s->len; j++){
            s->data[j - 1] = s->data[j];
        }
    }
    s->len--;
    return OK;
}

void ListDisplay(SqList *s){
    int i;
    printf("SqList test is :");
    for(i = 0; i < s->len; i++){
        printf("%d ", s->data[i]);
    }
    printf("\n");
}

int main(int argc, const char * argv[]) {
    SqList sqList;
    sqList.len = 0;
    ListDisplay(&sqList);
    
    for(int i = 0; i < 10; i++){
        ListInsert(&sqList, i, i * 2);
        printf("insert data %d ", i*2);
        ListDisplay(&sqList);
    }
    
    int data = 0;
    GetElem(sqList, 5, &data);
    printf("SqList fifth data is %d \n", data);
    
    int length = sqList.len;
    for(int i = 0; i < length; i++){
        int b;
        ListDelete(&sqList, 1, &b);
        printf("delete data %d\n", b);
        ListDisplay(&sqList);
    }
    
    return 0;
}
