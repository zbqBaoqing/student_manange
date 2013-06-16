#include"stu_govern.h"

//排序函数
int paixu(DOD *head,char filename[])
{
	DOD *po,*tail,*p1,*p2;
	int i,per_num=0;
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
	
	printf("单科成绩排序:英语(E/e)/高数(M/m)/C语言(C/c)/退出(Q/q)\n$$:");
	scanf("%c",&ch);
	getchar();
	printf("%c\n",ch);
	ch=toupper(ch);	//小写字母转换成大写字母

	if(ch=='Q')
		return 0;
	po=head;
	while(po->next!=NULL)	//求总人数
	{
		per_num++;
		po=po->next;
	}

	po=head;
	while(po->next!=NULL)
		po=po->next;	//找到尾结点
	tail=po;

	po=head;
	i=1;
	while(i<=per_num)
	{
		p1=head;
		while(p1->next!=tail)
			p1=p1->next;
		p2=head;
		if(ch=='E')
	        	while(p2->next!=tail&&p2->next->eng > tail->eng)	//每次从尾结点开始，找前面所有结点中数据比自己小的前区结点
				p2=p2->next;
		if(ch=='M')
			while(p2->next!=tail&&p2->next->math > tail->math)
				p2=p2->next;
		if(ch=='C')
			while(p2->next!=tail&&p2->next->chinese > tail->chinese)
				p2=p2->next;
			

		if(p2->next!=tail)
		{				//将尾结点插到前区结点后
			p1->next=tail->next;	
			tail->next=p2->next;
			p2->next=tail;
			tail=p1;		//尾指针指从新向尾
		}
		else
			tail=p1;		//尾指针指从新向尾

		i++;	
	}
	po=head;
	i=1;
	while(po->next!=NULL)
	{
		printf("学号  姓名  生日  性别  班级  地址  ");
		if(ch=='E')
			printf("英语   排名\n");
		if(ch=='M')
			printf("高数   排名\n");
    		if(ch=='C')
			printf("C语言   排名\n");
		printf("%-4d%-7s%d.%d.%-4d%-4s%-5s%-6s",
			po->next->num,po->next->name,po->next->birth.year,
			po->next->birth.month,po->next->birth.day,
			po->next->sex,po->next->class,po->next->address);
			if(ch=='E')
				printf("%-7.2f%-4d\n",po->next->eng,i++);
			if(ch=='M')
				printf("%-7.2f%-4d\n",po->next->math,i++);
			if(ch=='C')
				printf("%-7.2f%-4d\n",po->next->chinese,i++);
		po=po->next;
	}
		return 1;		
}

