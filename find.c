#include"stu_govern.h"

//查找函数
int find(DOD *po,char filename[])
{
	DOD *p;
	char ch;
	int i=0,k;
	FILE *fp;
	
	fp=fopen(filename,"rt");
		if(fscanf(fp,"%c",&ch) == EOF)
		{
			printf("对不起！数据还未创建，无法查找\n");
			printf("按任意键返回\n");
			  fclose(fp);  
			return 1;
		}
	fclose(fp);

	printf("请选择查找方式\n");
	p=(DOD *)malloc(N);
	printf("姓名查找(1)/学号查找(2)/退出(0)\n");
	ch=getchar();
	getchar();
	if(ch=='0')
		return 0;
	po=po->next;
	if(ch=='1')
	{
		printf("请输入要查找的姓名\n");
		scanf("%s",p->name);
		while(po!=NULL)
		{
			if(strcmp(po->name,p->name)==0)
			{
				i++;
				printf("学号  姓名  生日  性别  班级  地址  英语  高数  C语言\n");
				printf("%-4d%-7s%d.%d.%-4d%-4s%-5s%-6s%-8.2f%-8.2f%-8.2f\n",po->num,po->name,po->birth.year,po->birth.month,po->birth.day,po->sex,po->class,po->address,po->eng,po->math,po->chinese);
			}
				po=po->next;
		}
		if(i==0)
			printf("对不起！你要查找的数据不存在！\n");

	}
	else
	{		
		printf("请输入想要查询的学号\n");
		scanf("%d",&p->num);
		while(po!=NULL)
		{
			if(po->num==p->num)	
			{
				i++;
				printf("学号  姓名  生日  性别  班级  地址  英语  高数  C语言\n");
				printf("%-4d%-7s%d.%d.%-4d%-4s%-5s%-6s%-8.2f%-8.2f%-8.2f\n",po->num,po->name,po->birth.year,po->birth.month,po->birth.day,po->sex,po->class,po->address,po->eng,po->math,po->chinese);
				break;
			}
				po=po->next;
		}
		if(i==0)
			printf("对不起！你要查找的数据不存在！\n");
	}
	return 1;
}


