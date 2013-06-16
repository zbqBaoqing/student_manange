#include"stu_govern.h"
//求平均数并排序函数
int averpaixu(DOD *head,char filename[])
{
	DOD *p,*po,*p1,*p2,*tail;
	int per_num=0,i,k;
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
	po=head;
	while(po->next!=NULL)	//求总人数
	{
		per_num++;
		po=po->next;
	}

	float sum[3]={0},aver[3];		//定义数组，记录所有人的单课总分,平均分

	po=head;
	k=0;
	while(po->next!=NULL)		//求各种成绩的和
	{
		po->next->ever_sum=po->next->eng+po->next->math+po->next->chinese;//每个人的三成绩之和
		sum[0]+=po->next->eng;	//所有人的英语成绩之和
		sum[1]+=po->next->math;	//所有人的高数成绩之和
		sum[2]+=po->next->chinese;//所有人的C语言成绩之和
		po=po->next;
	}

	k=0;
	po=head->next;
	while(po!=NULL)		//求每个人三门功课的平均分
	{
		po->average=po->ever_sum/3.0;	
		po=po->next;
	}

	aver[0]=1.0*sum[0]/per_num;	//求所有人英语单课平均分
	aver[1]=1.0*sum[1]/per_num;	//求所有人数学单课平均分
	aver[2]=1.0*sum[2]/per_num;	//求所有人语文单课平均分

	po=head;
	while(po->next!=NULL)
		po=po->next;
	tail=po;
	tail->next=head;	//连成环

	i=1;
	
	while(i<=per_num)	//对平均分排序并显示格门成绩的排序
	{
			tail->e=1;
			tail->m=1;
			tail->c=1;
		p1=head;
		while(p1->next!=tail)
			p1=p1->next;
		p2=head;
	        	while(p2->next!=tail&&p2->next->average >= tail->average)	//找出大于尾结点平均数的前区结点
				p2=p2->next;

			p=head;			
		 	while(p->next!=head)			//记录各门成绩的名次
			{
				if(p->next->eng > tail->eng)
					tail->e++;
				if(p->next->math > tail->math)
					tail->m++;
				if(p->next->chinese > tail->chinese)
					tail->c++;
				p=p->next;
			}
		if(p2->next!=tail)
		{				//指针插入，将尾结点链接到前区结点后
			p1->next=tail->next;
			tail->next=p2->next;
			p2->next=tail;
			tail=p1;		//尾指针指从新向尾
			i--;
		}
		else
			tail=p1;	//尾指针指从新向尾

		i++;	
	}	
	po=head;
	while(po->next!=head)
		po=po->next;
	po->next=NULL;

		p2=head;
		i=1;
		while(p2->next!=NULL)	
		{
			printf("学号  姓名  生日  性别  班级  地址  总分  平均分  排名  英语  排名  高数  排名  C语言  排名\n");
			printf("%-4d%-7s%d.%d.%-4d%-6s%-5s%-6s%-7.2f%-7.2f%-4d%-7.2f%-7d%-7.2f%-5d%-7.2f%-5d\n",
			p2->next->num,p2->next->name,p2->next->birth.year,p2->next->birth.month,p2->next->birth.day,
			p2->next->sex,p2->next->class,p2->next->address,p2->next->ever_sum,p2->next->average,i++,
			p2->next->eng,p2->next->e,p2->next->math,p2->next->m,p2->next->chinese,p2->next->c);	
			p2=p2->next;
		} 
	printf("英语单课总分为:%-4.2f\t平均分为:%-4.2f\n",sum[0],aver[0]);
	printf("数学单课总分为:%-4.2f\t平均分为:%-4.2f\n",sum[1],aver[1]);
	printf("C语言单课总分为:%-4.2f\t平均分为:%-4.2f\n",sum[2],aver[2]);
	return 1;
}


