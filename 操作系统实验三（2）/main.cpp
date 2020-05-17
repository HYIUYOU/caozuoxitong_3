//
//  main.cpp
//  操作系统实验三（2）
//
//  Created by 何忆源 on 2020/5/12.
//  Copyright © 2020 何忆源. All rights reserved.
//

#include <iostream>

#include <iostream>
using namespace std;

int DigitalMap[8][8];

void Assign(int map[8][8]);//分配
void Recovery(int map[8][8]);//回收
void Print(int map[8][8]);//打印

void Assign(int map[8][8])//分配
{
    int request;//待待分配的物理块数
    int b = 0;//空闲块数
    printf("请输入你要分配的物理块数：");
    scanf("%d",&request);
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            if(map[i][j] == 0)
            b++;
        }
        
    }
            
    if (request <= b)
    {
        printf("分配成功！\n");
        printf("分配的物理地址为：\n" );
        printf("柱面号\t磁道号\t物理记录号\n");
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (request <= 0)
                    break;
                if (map[i][j] == 0)
                {
                    map[i][j] = 1;
                    printf("\t%d\t%d\t%d\n",i,j/4,j%4);
                    request--;
                }
            }
        }
    }
    else
        printf("没有足够的物理块进行分配!\n");

    printf("\n");
    Print(map);
}

void Recovery(int map[8][8])//回收
{
    int cylinder, track, record;//柱面号、磁道号、物理记录号
    printf("请输入你想回收的物理地址：柱面号 磁道号 物理记录号\n");
    scanf("%d%d%d",&cylinder,&track,&record);
    int bytenum, position;//字节号，位号
    bytenum = cylinder;//字节号
    position = track * 4 + record;//位号
    
    if(map[bytenum][position]==0){
        printf("回收错误");
    }

    if (bytenum > 8 || position > 8)
    {
         printf("输入的物理地址错误!\n");
        printf("\n");
            return;
    }

    map[bytenum][position] = 0;
    printf("回收成功！\n");
    printf("回收字节号为:%d   回收的位号为:%d\n",bytenum,position);
    printf("\n");

    Print(map);
}

void Print(int map[8][8])//打印
{
    printf("\t------------磁盘存储存储位示图------------\n");
    for (int i = 0; i < 8; i++)
    {
        printf( "\t    ");
        for (int j = 0; j < 8; j++)
        {
            printf("%d",map[i][j]);
        }
        printf("\n");
    }
    printf("\t****************************************\n");
}


int main()
{
    for (int i = 0; i < 8; i++)//位示图初始化
    {
        for (int k = 0; k < 8; k++)
            DigitalMap[i][k] = 0;
    }
 
    int choice;
    while (true)
    {
        printf("输入你要执行的操作： 1(分配)  2(回收)  0(退出)\n" );
        scanf("%d",&choice);
        if (choice == 1)
            Assign(DigitalMap);
        else if (choice == 2)
            Recovery(DigitalMap);
        else if (choice == 0)
            break;
    }
}

