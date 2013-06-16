#include"stu_govern.h"
//删除函数
int delete(DOD *head,char filename[])
{
	DOD *p,*po;
	char ch,name[name_num],fa;
	int i=0,num;
	FILE *fp;
	
	fp=fopen(filename,"rt+");
	if(fp!=NULL)
	{
		if(fscanf(fp,"%c",&fa)==EOF)
		{
			printf("对不起！数据还未创建，无法查找\n");
			printf("按任意键返回\n");
			getchar();
			  fclose(fp);  
			return 1;
		}
	fclose(fp);
	}

  
	printf("请选择删除方式\n");
	printf("按姓名删除(1)/按学号删除(2)/退出(0)\n");
	scanf("%c",&ch);
	if(ch=='0')
		return 0;
	po=head;
	p=po->next;
	if(ch=='2')
		goto loop;
	else
	{
		printf("请输入要删除的姓名\n");
		scanf("%s",name);
		while(p!=NULL)
		{
			if(strcmp(p->name,name)==0)
			{
				i++;
				printf("学号  姓名  生日  性别  班级  地址  英语  高数  C语言\n");
			printf("%-4d%-7s%d.%d.%-4d%-4s%-5s%-6s%-8.2f%-8.2f%-8.2f\n",p->num,p->name,p->birth.year,p->birth.month,p->birth.day,p->sex,p->class,p->address,p->eng,p->math,p->chinese);
			}
			po=p;
			p=p->next;
		}
			if(i==0)
			{
				printf("对不起！%s的数据可能不存在\n",name);
				return 0;
			}
			if(i==1)
			{
				printf("你确定要删除他/她的数据吗？(y/n)\n");
				getchar();
				ch=getchar();
				getchar();
				if(ch=='y')
				{	
					po=head;
					p=po->next;
					while(p!=NULL)
					{
						if(strcmp(p->name,name)==0)
						{
							po->next=p->next;
							free(p);
							writefile(head,filename);
							printf("恭喜你！删除成功！\n");
							break;
						}
						po=p;
						p=p->next;
					}
				}
			}
			else
			{
	loop:			printf("请输入要删除的的学号\n");
				scanf("%d",&num);
				po=head;
				p=po->next;
				while(p!=NULL)
				{
					if(p->num==num)
					{
						printf("你确定要删除他/她的信息吗(y/n)？\n");
						getchar();//清除缓冲区
						ch=getchar();
						getchar();//清除缓冲区
						if(ch=='y')
						{
							po->next=p->next;
							free(p);
							printf("恭喜你！删除成功！\n");
							writefile(head,filename);
							break;
						}
					}
					po=p;
					p=p->next;
				}
			}
		po=head;
		if(po->next==NULL)
			printf("数据已清空\n");
		else
	 		while(po->next!=NULL)
			{
			printf("学号  姓名  生日  性别  班级  地址  英语  高数  C语言\n");
			printf("%-4d%-7s%d.%d.%-4d%-4s%-5s%-6s%-8.2f%-8.2f%-8.2f\n",
			po->next->num,po->next->name,po->next->birth.year,po->next->birth.month,po->next->birth.day,
			po->next->sex,po->next->class,po->next->address,po->next->eng,po->next->math,po->next->chinese);
				po=po->next;
			}
	}
	return 1;
}

