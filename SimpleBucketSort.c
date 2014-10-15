//
//  main.c
//  Algorithm1
//
//  Created by ScorpioNeal on 14-10-14.
//  Copyright (c) 2014年 ScorpioNeal. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...

    int book[1000],  t, n;
    
    for(int i = 0; i < 1000; i++){
        book[i] = 0;//初始化
    }
    
    scanf("%d", &n);//输入排序的数字个数
    for(int i = 0; i < n; i++){
        scanf("%d", &t);
        book[t]++;//把数字放入数值对应的桶中
    }
    
    for(int i = 0; i < 1000; i++){
        for(int j = 0; j < book[i]; j++){
            printf("%d ", i);//输出
        }
    }
    
    return 0;
}
