/*************************************************************************
	> File Name: stu_govern.h
	> Author: yexingkong
	> Mail: abqyexingkong@gmail.com 
	> Created Time: 2013年05月25日 星期六 20时28分56秒
    > Description: 
 ************************************************************************/

#ifndef _STU_GOVERN_H_
#define _STR_GOVERN_H_

		/*学生管理系统*/
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define N sizeof(struct stu)
#define xue_num 8
#define name_num 20
#define sex_num 6
#define class_num 15
#define address_num 20


struct stue
{
	int year;
	int month;
	int day;
};

typedef struct stu
{	
	int num;			//学号
	char name[name_num];		//姓名
	struct stue birth;		//生日
	char sex[sex_num];		//性别
	char class[class_num];		//班级
	char address[address_num];	//地址
	float eng;			//英语成绩
	float math;			//数学成绩
	float chinese;		        //C语言成绩
	float average;			//学生的平均成绩
	float ever_sum;			//学生的各门成绩总和
	int e,m,c;			//名次
	struct stu *next;		//存放地址的指针
}DOD;



int creat(DOD *head);		
int find(DOD *head,char filename[]);				/*函数声明部分*/
int delete(DOD *head,char filename[]);				
int add(DOD *head,char filename[]);
int paixu(DOD *h,char filename[]);
int averpaixu(DOD *head,char filename[]);
void writefile(DOD *head,char filename[]);
int list(DOD *head,char filename[]);				
void listt(DOD head,char filename[]);

#endif

