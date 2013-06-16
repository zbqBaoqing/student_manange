#include"stu_govern.h"
//数据的添加或修改
int add(DOD *head,char filename[])
{
	DOD *p,*po,*p1;
	int k;
	char ch,fa;
	FILE *fp;
	
	fp=fopen(filename,"rt+");
		if(fscanf(fp,"%c",&fa)==EOF)
		{
			printf("对不起！数据还未创建，无法查找\n");
			printf("按任意键返回\n");
			getchar();
			  fclose(fp);  
			return 1;
		}
	fclose(fp);

	printf("请输入要添加或要修改的学生信息\n");
	p=(DOD *)malloc(N);

	printf("请输入学号(整数，为零停止)\n"); 
	scanf("%d",&p->num);
	printf("请输入姓名(不加空格)\n");
	scanf("%s",p->name);
	printf("请输入生日：年  月  日\n");
	scanf("%d%d%d",&p->birth.year,
			&p->birth.month,&p->birth.day);
	printf("请输入性别\n");
	scanf("%s",p->sex);
	printf("请输入班级\n");
	scanf("%s",p->class);
	printf("请输入地址\n");
	scanf("%s",p->address);
	printf("请输入：英语   高数   C语言\n");
	scanf("%f%f%f",&p->eng,&p->math,&p->chinese);

	po=head;
	p1=head->next;
	while(p1->next!=NULL&&po->next->num < p1->next->num)
	{	
		po=po->next;
		p1=po->next;
	}
	if(p1->next==NULL)
	{
		po=head;
		p1=po->next;
		while(po->next!=NULL&&po->next->num<p->num)
		{
			p1=p1->next;
			po=po->next;
		}
		if(p1!=NULL&&p1->num==p->num)
		{
			p->next=p1->next;
			po->next=p;
			free(p1);
			writefile(head,filename);
			printf("恭喜你！信息修改成功!\n");
			goto loop;
			return 1;
		}
	}
	else
	{
		po=head;
		p1=po->next;
		while(po->next!=NULL&&strcmp(po->next->name,p->name)<0)
		{
			p1=p1->next;
			po=po->next;
		}
		if(p1!=NULL&&strcmp(p1->name,p->name)==0)
		{
			p->next=p1->next;
			po->next=p;
			free(p1);
			writefile(head,filename);
			printf("恭喜你！信息修改成功!\n");
			goto loop;
			return 1;
		}

	}
		p->next=p1;
		po->next=p;
		writefile(head,filename);
		printf("恭喜你！信息添加成功！\n");

loop:	po=head;
	while(po->next!=NULL)
	{
		printf("学号  姓名  生日  性别  班级  地址  英语  高数  C语言\n");
		printf("%-4d%-7s%d.%d.%-4d%-4s%-5s%-6s%8.2f%8.2f%8.2f\n",
			po->next->num,po->next->name,po->next->birth.year,
			po->next->birth.month,po->next->birth.day,
			po->next->sex,po->next->class,po->next->address,
			po->next->eng,po->next->math,po->next->chinese);
			po=po->next;
	}
	return 1;
}

