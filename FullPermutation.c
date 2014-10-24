//
//  main.c
//  DFSTest
//
/**
 * 输入数字n 输出1－n的全排列
 */
//  Created by ScorpioNeal on 14/10/24.
//  Copyright (c) 2014年 ScorpioNeal. All rights reserved.
//

#include <stdio.h>

int a[10], book[10], n;

void dfs(int step){//step表示在第几个盒子前
    printf("-----%d\r\n",step);
    if(step == n+1){
        for(int i = 1; i <= n; i++){
            printf("%d", a[i]);
        }
        printf("\r\n");
        return;
    }
    
    for(int i = 1; i <= n; i++){
        //printf("book[i] is %d", book[i]);
        if(book[i] == 0){
            a[step] = i;//把i号扑克牌放入第step个盒子里
            book[i] = 1;//表示i号扑克牌已经没有了
            
            //第step个盒子已经放好了， 接下来放第step+1个盒子
            dfs(step + 1);
            book[i] = 0;//? Attention! 谁能给个很好的解释啊
        }
    }
}

int main(int argc, const char * argv[]) {
    scanf("%d", &n);
    dfs(1);
    return 0;
}
