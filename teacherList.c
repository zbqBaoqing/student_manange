#include"stu_govern.h"

//老师登录者菜单
int list(DOD *head,char filename[])
{
	char ch;
	FILE *fp;
	fp=fopen(filename,"rt+");
	if(fscanf(fp,"%c",&ch)!=EOF)
	{
		printf("当前文件中所保存的数据如下\n");
		readfile(head,filename);
		getchar();
		system("clear");
	}
	else
		printf("对不起！文件中没有数据！\n");

	printf("\n\t\t此学生管理系统具有以下功能:\n");
	printf("\t\t&& 信息创建，请输入------(H/h)\n");
	printf("\t\t&& 数据读取，请输入-------(X/x)\n");
	printf("\t\t&& 信息查询，请输入------(F/f)\n");
	printf("\t\t&& 信息删除，请输入------(D/d)\n");
	printf("\t\t&& 信息添加或修改，请输入--------(A/a)\n");
	printf("\t\t&& 学生单课成绩排序，请输入------(P/p)\n");
	printf("\t\t&& 学生平均分排序,请输入-----(R/r)\n");
	printf("\t\t&& 如果你想退出，请输入----------(Q/q)\n$$:");
	while(1)
	{	
	       	ch=getchar();
		ch=toupper(ch);
		while(getchar() != '\n');			
     		switch(ch)
		{
			case 'H': creat(head);writefile(head,filename);getchar();break;
			case 'X': readfile(head,filename);getchar();break;
			case 'A': add(head,filename);getchar();break;
			case 'F': find(head,filename);getchar();break;
			case 'D': delete(head,filename);getchar();break;
			case 'P': paixu(head,filename);getchar();break;
			case 'R': averpaixu(head,filename);getchar();break;
			case 'Q': break;
		}
			
			printf("请问您是否还要继续其他操作？(y/n)\n$$:");
			ch=getchar();
			getchar();
		       if(ch=='n')
				break;
			else
			{
				system("clear");

				printf("\n\t\t此学生管理系统具有以下功能:\n");
				printf("\t\t&& 信息创建，请输入------(H/h)\n");
				printf("\t\t&& 数据读取，请输入-------(X/x)\n");
				printf("\t\t&& 信息查询，请输入------(F/f)\n");
				printf("\t\t&& 信息删除，请输入------(D/d)\n");
				printf("\t\t&& 信息添加或修改，请输入--------(A/a)\n");
				printf("\t\t&& 学生单课成绩排序，请输入------(P/p)\n");
				printf("\t\t&& 学生平均分排序,请输入-----(R/r)\n");
				printf("\t\t&& 如果你想退出，请输入----------(Q/q)\n$$:");

				continue;
			}
	}
		return 1;
}


