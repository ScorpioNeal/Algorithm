//
//  main.c
//  BfsTest
//
//  Created by ScorpioNeal on 14/10/24.
//  Copyright (c) 2014年 ScorpioNeal. All rights reserved.
//

#include <stdio.h>

struct note{
    int x;//横坐标
    int y;//纵坐标
    int f;//父节点在队列中的编号
    int s;//步数
};


int main(int argc, const char * argv[]) {

    struct note que[2501];
    
    int a[51][51] = {0};//地图
    int book[51][51] = {0};//记录是否重复
    
    int next[4][2] = {
        {0, 1},//右
        {1, 0},//下
        {0, -1},//左
        {-1, 0}//上
    };
    
    int head, tail;
    
    int m, n;//地图宽高
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            scanf("%d", &a[i][j]);//输入地图
        }
    }
    int startx, starty, p, q;//起止点坐标
    scanf("%d %d %d %d", &startx, &starty, &p, &q);
    
    
    int tx, ty;
    
    //队列初始化
    head = 1;
    tail = 1;
    que[tail].x = startx;
    que[tail].y = starty;
    que[tail].f = 0;
    que[tail].s = 0;
    
    tail++;
    book[startx][starty] = 1;
    
    int flag = 0;//用于标记是否到达目的地
    while(head < tail){
        for(int k = 0; k < 4; k++){
            tx = que[head].x + next[k][0];
            ty = que[head].y + next[k][1];
            if(tx < 1 || tx > n || ty < 1 || ty > m){
                continue;
            }
            if(a[tx][ty] == 0 && book[tx][ty] == 0){
                book[tx][ty] = 1;
                que[tail].x = tx;
                que[tail].y = ty;
                que[tail].f = head;
                que[tail].s = que[head].s + 1;
                tail++;
            }
            
            if(tx == p && ty == q){
                flag = 1;
                break;
            }
        }
        
        if(flag == 1){
            break;
        }
        head++;//当一个点拓展结束后，head++即把该点给去掉
    }
    
    printf("%d", que[tail - 1].s);
    
    return 0;
}
