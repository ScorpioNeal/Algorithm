//
//  main.c
//  QuickSort
//
//  Created by ScorpioNeal on 14-10-14.
//  Copyright (c) 2014年 ScorpioNeal. All rights reserved.
//

#include <stdio.h>

int a[101], n;//一个是用来接受输入的数字的数组，一个是输入数字的个数

void quicksort(int left, int right){
    int temp, i , j, t;
    if(left > right){
        return;//要让左边小于右边
    }
    temp = a[left];
    i = left;//记录左边游标的位置
    j = right;//记录右边游标的位置
    
    while (i != j) {
        while (a[j] >= temp && i < j) {//如果右边大于标准，那么右边往左移动一位继续比较
            j--;
        }
        while (a[i] <= temp && i < j) {//如果左边小于标准，那么左边往右移动一位继续比较
            i++;
        }
        //然后他俩交换
        if(i < j){
            t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }
    //相遇之后与基准数互换
    a[left] = a[i];
    a[i] = temp;
    
    //然后排列左右2边的数字
    quicksort(left, i - 1);
    quicksort(i+1, right);
}

int main(int argc, const char * argv[]) {
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d",&a[i]);
    }
    quicksort(0, n - 1);//!!Notice!! 这儿是n-1 游标的位置
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    return 0;
}
