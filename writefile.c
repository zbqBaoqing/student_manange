#include"stu_govern.h"

//数据保存文件
void writefile(DOD *head,char filename[])
{
	char ch;
	FILE *fp;
	DOD *po=head->next;
	
	fp=fopen(filename,"wt+");
	if(fp==NULL)
	{
		printf("\n打开文件失败！%s可能不存在\n",filename);
		printf("按任意键 退出\n");
		getchar();
		exit(1);
	}
	
	while(po!=NULL)
	{
		fprintf(fp,"%d %s %d %d %d %s %s %s %f %f %f\n",po->num,po->name,po->birth.year,po->birth.month,po->birth.day,po->sex,po->class,po->address,po->eng,po->math,po->chinese);
		po=po->next;
	}
	if(po==NULL)
		printf("数据保存成功！\n");
	fclose(fp);
}

