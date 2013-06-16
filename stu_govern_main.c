










#include"stu_govern.h"


int main()
{	
	system("clear");
	printf("\n\t\t*****************************************");
	printf("\n\t\t\t$~$ 欢迎进入学生管理系统 $~$");
	printf("\n\t\t*****************************************\n");
	DOD *head;
	char ch,filename[]={"stu_file"};
	int rt;
	FILE *fp;

	printf("\t$~$选择登录用户老师([T/t]||学生[S/s])$~$\n");
	ch=getchar();
	getchar();
	ch=toupper(ch);
	head=(DOD *)malloc(N);
	fp=fopen(filename,"at+");	//一开始就建文件，是为了提示你没输入数据就不能进行其他操作（结合每个函数开头打开的文件）
	fclose(fp);
	system("clear");
	if(ch=='S')
		listte(head,filename);
	else
	{
		rt=login();
		if(rt==1)
		{
			system("clear");
			list(head,filename);
		}
	}
	return 1;
}
