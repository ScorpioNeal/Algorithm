//
//  main.c
//  DfsTest
//
//  Created by ScorpioNeal on 14/10/24.
//  Copyright (c) 2014年 ScorpioNeal. All rights reserved.
//

#include <stdio.h>

int m, n, p, q, min = 99999999;
int a[51][51], book[51][51];

void dfs(int x, int y, int step){
    int next[4][2] = {
        {0, 1},//向右
        {1, 0},//向下
        {0, -1},//向左
        {-1, 0}//向上
    };
    
    int tx, ty;//走过之后的坐标
    if(x == p && y == q){//p,q为目标坐标
        if(step < min){
            min = step;
        }
        return;
    }
    
    for(int k = 0; k < 3; k++){
        tx = x + next[k][0];
        ty = y + next[k][1];
        if(tx < 1 || tx > n || ty < 1 || ty > m){//m,n为地图最大宽高
            continue;
        }
        if(a[tx][ty] == 0 && book[tx][ty] == 0){
            book[tx][ty] = 1;
            dfs(tx, ty, step + 1);
            book[tx][ty] = 0;
        }
    }
}

int main(int argc, const char * argv[]) {
    int startx, starty;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n;i++){
        for(int j = 1; j<=m; j++){
            scanf("%d", &a[i][j]);
        }
    }
    scanf("%d %d %d %d", &startx, &starty, &p, &q);
    book[startx][starty] = 1;
    dfs(startx, starty, 0);
    printf("%d", min);
    return 0;
}
