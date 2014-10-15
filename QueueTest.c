//
//  main.c
//  QueneTest
//
//  Created by ScorpioNeal on 14-10-14.
//  Copyright (c) 2014年 ScorpioNeal. All rights reserved.
//

#include <stdio.h>

/**
 *输入一串号码， 第一个去掉，第二个放最后，组成新的号码， 依此类推直到去掉最后一个
 */

int main(int argc, const char * argv[]) {

    int a[20] = {6, 3, 1, 7, 5, 8, 9, 2, 4};
    int head = 0;
    int tail = 9;
    
    while (head < tail) {
        printf("%d", a[head]);
        head++;
        a[tail] = a[head];
        tail++;
        head++;
    }
    return 0;
}
