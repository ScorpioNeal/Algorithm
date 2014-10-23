//
//  main.c
//  StackAndQueueTest
//
//  Created by ScorpioNeal on 14/10/23.
//  Copyright (c) 2014年 ScorpioNeal. All rights reserved.
//

#include <stdio.h>

//模拟手中的牌
struct queue{
    int data[100];
    int head;
    int tail;
};

//模拟桌子上的牌
struct stack{
    int data[10];
    int top;
};

int main(int argc, const char * argv[]) {
    struct queue q1, q2;
    struct stack s;
    int book[10]; //用来标记桌面上是否出现牌,如果出现牌i则book[i] = 1
    int i , t;
    
    
    //初始化队列
    q1.head = 0; q1.tail = 0;
    q2.head = 0; q2.tail = 0;
    //初始化栈
    s.top = 0;
    
    for(int i = 1; i <= 9; i++){
        book[i] = 0;
    }
    
    //q1人手中的牌初始化6张牌
    for(int i = 0; i < 6; i++){
        scanf("%d", &q1.data[q1.tail]);
        q1.tail++;
    }
    //q2人手中的6张牌初始化
    for(int i = 0; i < 6; i++){
        scanf("%d", &q2.data[q2.tail]);
        q2.tail++;
    }
    
    //队列不为空执行操作，即手中有牌的时候执行操作
    while(q1.head < q1.tail && q2.head < q2.tail){
        t = q1.data[q1.head];//q1人出一张牌
        if(book[t] == 0){//即桌面上没有该牌
            q1.head++;
            s.top++;
            s.data[s.top] = t;//把牌入栈
            book[t] = 1;
        }else{//桌面上有牌，则q1人赢得该轮
            q1.head++;
            q1.data[q1.tail] = t;
            q1.tail++;
            while (s.data[s.top] != t) {//把stack中与出的牌t不一样的从上到下依次放入q1的tail后面
                book[s.data[s.top]] = 0;
                q1.data[q1.tail] = s.data[s.top];
                q1.tail++;
                s.top--;
            }
        }
        
        t = q2.data[q2.head];
        if(book[t] == 0){
            q2.head++;
            s.top++;
            s.data[s.top] = t;
            book[t] = 1;
        }else{
            q2.head++;
            q2.data[q2.tail] = t;
            q2.tail++;
            while (s.data[s.top] != t) {
                book[s.data[s.top]] = 0;
                q2.data[q2.tail] = s.data[s.top];
                q2.tail++;
                s.top--;
            }
        }
    }
    
    if(q2.head == q2.tail){
        printf("q1 win");
        for(int i = q1.head; i < q1.tail; i++){
            printf("%d ", q1.data[i]);
        }
        if(s.top > 0){
            printf("\r\n桌子上的牌是:");
            for(int i = 1; i <= s.top; i++){//为什么从1开始？ 因为s.top = 0表示空栈
                printf("%d ", s.data[i]);
            }
        }else{
            printf("桌子上没有牌了");
        }
    }else{
        printf("q2 win");
        for(int i = q2.head; i < q2.tail; i++){
            printf("%d ", q2.data[i]);
        }
        if(s.top > 0){
            printf("\r\n桌子上的牌是:");
            for(int i = 1; i <= s.top; i++){
                printf("%d ", s.data[i]);
            }
        }else{
            printf("桌子上没有牌了");
        }

    }
    
    
    return 0;
}
