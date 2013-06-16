#include"stu_govern.h"
//用户登录
int login()
{
	char ch,sx,name[20],password[10],fa[20],fb[10];
	FILE *fp;
	int i=0;
	printf("$~$新用户创建（N/n）$~$\n");
	printf("$~$用户登录(L/l)$~$\n");
	scanf("%c",&ch);
	ch=toupper(ch);
	printf("温馨提示：只有三次输入密码的机会，否则退出！");
	while(i<5)
	{
		printf("输入用户名\n$$:");
		scanf("%s",name);
		printf("输入密码\n$$:");
		system("stty -echo");
		scanf("%s",password);
		getchar();
		system("stty echo");
		fp=fopen("stu_log","at+");
		if(fp!=NULL)
		{
			printf("*******************");
		
			if(ch=='L')
			{
				i++;
				rewind(fp);
				while(feof(fp)!=1)
				{
					fscanf(fp,"%s%s",fa,fb);
					if(strcmp(name,fa)!=0||strcmp(password,fb)!=0)
						  continue;
					else
						return 1;
				}
			}

			if(ch=='N')
			{
				if(fscanf(fp,"%c",&sx)!=EOF)
					fprintf(fp," ");
					fprintf(fp,"%s %s",name,password);
					printf("用户创建成功！\n");
					ch='L';
					i++;
					fclose(fp);
					continue;
			}
		}
	}
}


