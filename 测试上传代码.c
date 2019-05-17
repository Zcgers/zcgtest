//
//  测试上传代码.c
//  算法程序
//
//  Created by 朱晨光 on 2019/5/17.
//  Copyright © 2019 朱晨光. All rights reserved.
//

#include <stdio.h>
#include<stdio.h>
#include<string.h>
char* fun(int n,char arr[]){
    int k = 0;int count = 1;
    char temp[100000];
    arr[0] = '1';
    for(int i = 1;i < n;i++){
        for(int j = 0;j < strlen(arr);j++,count = 1){
            while(arr[j] == arr[j + 1]){
                count++;
                j++;
            }
            temp[k++] = count + '0';
            temp[k++] = arr[j];
        }
        temp[k] = '\0';
        strcpy(arr,temp);
        k = 0;
    }
    return arr;
}


int main(){
    int n = 0;
    char arr[100000];
    scanf("%d",&n);
    char *p;
    p = fun(n,arr);
    printf("%s",p);
    return 0;
}
