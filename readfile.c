#include"stu_govern.h"

//数据读取文件
 readfile(DOD *head,char filename[])
{
	char ch;
	FILE *fp;
	DOD *p2,*p1;

	fp=fopen(filename,"rt+");
	if(fp==NULL)
	{
		if(fscanf(fp,"%c",&ch)==EOF)
		printf("\n打开文件失败！%s可能不存在\n",filename);
		printf("按任意键 退出\n");
		getchar();
		exit(1);
	}
	p1=head;	//注意：读取数据时，还需再建链，因为当再次运行时，链表链已不存在，故无法再次对链表操作了
	p2=(DOD *)malloc(N);
	printf("你输入的数据如下\n");
	while(fscanf(fp,"%d %s %d %d %d %s %s %s %f %f %f",&p2->num,p2->name,&p2->birth.year,&p2->birth.month,&p2->birth.day,p2->sex,p2->class,p2->address,&p2->eng,&p2->math,&p2->chinese)!=EOF)
	{
		p1->next=p2;
		p1=p2;
		printf("学号  姓名  生日  性别  班级  地址  英语  高数  C语言   \n");
		printf("%-4d%-7s%d.%d.%-4d%-4s%-5s%-6s%-8.2f%-8.2f%-8.2f\n",p2->num,p2->name,p2->birth.year,p2->birth.month,p2->birth.day,p2->sex,p2->class,p2->address,p2->eng,p2->math,p2->chinese);
		p2=(DOD *)malloc(N);
	}
	p1->next=NULL;
	free(p2);
	fclose(fp);
}


