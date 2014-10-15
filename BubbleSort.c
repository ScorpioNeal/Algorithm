//
//  main.c
//  BubbleSort
//
//  Created by ScorpioNeal on 14-10-14.
//  Copyright (c) 2014年 ScorpioNeal. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int n;
    int tmp;
    scanf("%d", &n);
    int a[100];
    for(int i = 0; i < n; i++){
        scanf("%d",&a[i]);//获取输入
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(a[j] > a[j + 1]){
                tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    return 0;
}
