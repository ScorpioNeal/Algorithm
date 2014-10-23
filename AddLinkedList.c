//
//  main.c
//  AddLinkedList
//
//  Created by ScorpioNeal on 14/10/23.
//  Copyright (c) 2014年 ScorpioNeal. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

int main(int argc, const char * argv[]) {
    struct node *head, *p, *q;
    int n, a;
    scanf("%d", &n);
    head = NULL;
    for(int i = 0; i < n; i++){
        scanf("%d", &a);
        p = (struct node*)malloc(sizeof(struct node));
        p->data = a;
        p->next = NULL;
        if(head == NULL){
            head = p;
        }else{
            q->next = p;
        }
        q = p;
    }
    
    scanf("%d", &a);
    struct node *t = head;
    while (t != NULL) {
        if(t->next->data > a){
            p = (struct node*)malloc(sizeof(struct node));
            p->data = a;
            p->next = t->next;
            t->next = p;
            break;
        }
        t = t->next;
    }
    t = head;
    while (t != NULL) {
        printf("%d ", t->data);
        t = t->next;
    }
    return 0;
}
