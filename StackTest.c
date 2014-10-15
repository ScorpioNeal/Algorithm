//
//  main.c
//  StackTest
//
//  Created by ScorpioNeal on 14-10-14.
//  Copyright (c) 2014年 ScorpioNeal. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {

    char a[101], s[101];
    
    int len ,mid, next, top;
    gets(a);
    len = strlen(a);
    if(len % 2 == 0){
        mid = len/2 - 1;
    }else {
        mid = len / 2;
    }
    
    top = 0;
    for(int i = 0; i <= mid; i++){
        s[top++] = a[i];//mid前的数字入栈
    }
    
    
    next = mid;

    
    for(int i = next; i < len; i++){
        printf("a[i] %c s[top - 1] %c",a[i], s[top - 1]);//这儿注意是s[top - 1] 而不是s[top] ,s[top]指向的是一个未定义的数值
        if(a[i] != s[top - 1])
            break;
        top--;
    }
    
    if(top == 0){
        printf("Yes");
    }else{
        printf("No");
    }
    
    return 0;
}
