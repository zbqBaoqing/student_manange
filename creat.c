
#include"stu_govern.h"

//数据创建函数
int creat(DOD *head)	
{
	DOD *p1,*p2,*p3,*p4,*q;
	char ch;
	int i=1;
	
	p1=head;
	printf("请选择排序方式\n");
	 printf("学号排序(U/u)/姓名排序(N/n)\n$$:");
	 scanf("%c",&ch);
	 ch=toupper(ch);
	printf("学生信息的输入\n");
	system("clear");
	while(1)
	{	
		printf("请输入第%d名同学的学号(整数,为零停止)\n",i++); 
		p2=(DOD *)malloc(N);
		scanf("%d",&p2->num);
		if(p2->num==0)	//判断输入是否为零，为零则结束
			break;
		p4=head;
		while(p4->next!=NULL)	//检查你是否输入相同的学号
		{   
			if(p4->next->num==p2->num)
			{
				printf("注意！此学号你一用过，请换一个学号！\n");
				scanf("%d",&p2->num);
			}
			p4=p4->next;
		}
		printf("请输入姓名(不加空格)\n");
		scanf("%s",p2->name);
		printf("请输入生日：年  月  日\n");
		scanf("%d%d%d",&p2->birth.year,
				&p2->birth.month,&p2->birth.day);
		printf("请输入性别\n");
		scanf("%s",p2->sex);
		printf("请输入班级\n");
		scanf("%s",p2->class);
		printf("请输入地址\n");
		scanf("%s",p2->address);
		printf("请输入：英语   高数   C语言\n");
		scanf("%f%f%f",&p2->eng,&p2->math,&p2->chinese);
		getchar();
		system("clear");

		p3=head;
		p1->next=p2;
		 p2->next=NULL;   
		 if(ch=='U')
		 {
			while(p3->next!=NULL&&p3->next->num<p2->num) /*对学号的比较，如果满足条件，指针下移*/
				p3=p3->next;	//指针移动，直到不满足条件为止
			if(p3->next->num==p2->num)
				p1=p2;
		 }
		if(ch=='N')
		{
			while(p3->next!=NULL&&strcmp(p3->next->name,p2->name)<0)
				p3=p3->next;
			if(strcmp(p3->next->name,p2->name)==0)
				p1=p2;
		}
			if(p3->next->num!=p2->num||strcmp(p3->next->name,p2->name)!=0)	
			{
				p1->next=NULL;	//倒数第二个结点指针域置空
				q=p1;		//记录倒数第二个结点
				p1=p3->next;	//p1指针移动到条件终止时,p3所链接的下一结点的位置
				p2->next=p1;	//将p1结点链接在新结点后
				p3->next=p2;	//学号乱序，链表重连排		
				p1=q;		//p1指向最后一结点
			}
	}
	p1->next=NULL;		//最后一结点指针域置空
	free(p2);		//释放空结点

	return 1;
}

