//
//  main.c
//  DfsTest2
//
//  Created by ScorpioNeal on 14/10/24.
//  Copyright (c) 2014年 ScorpioNeal. All rights reserved.
//

#include <stdio.h>

int book[101], sum, n, e[101][101];

void dfs(int cur){
    printf("%d", cur);
    sum++;
    if(sum == n) {
        return;
    }
    for(int i = 1; i <= n; i++){
        if(e[cur][i] == 1 && book[i] == 0){
            book[i] = 1;
            dfs(i);
        }
    }
    return;
}

int main(int argc, const char * argv[]) {
    int m;
    int a, b;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(i == j){
                e[i][j] = 0;
            }else{
                e[i][j] = 99999999;
            }
        }
    }
    for(int i = 1; i <= m; i++){
        scanf("%d %d", &a, &b);
        e[a][b] = 1;
        e[b][a] = 1;
    }
    book[1] = 1;
    dfs(1);
    return 0;
}
