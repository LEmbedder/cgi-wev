#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
	//设置HTML语言
	printf("Content-type:text/html\n\n");
	printf("<title>hello</title>");
	printf("%s<br><br>", getenv("REQUEST_METHOD"));
	char *pp = getenv("QUERY_STRING");

	char pgetenv[256];
	sprintf(pgetenv,"%s",pp);

        //打印输入的内容
	printf("%s<br><br>", pgetenv);

	char *p = pgetenv + 4; 
	char*p1 = strchr(pgetenv, '&');
	*p1 = '\0';
#if 1
	char cmd[256] = {0};

	//字符串映射
	sprintf(cmd, "%s", p);
	printf("%s<br><br>", cmd);

	//以读的方式打开1.txt
	FILE* fp = fopen(cmd, "r");
 
    //循环成立的条件是没有读到文件结尾
    while(!feof(fp))
    {
        //每次从文件中读取1个字符
        char ch = fgetc(fp);
 
        //当读取到\n时
        if('\n' == ch)
        {
            //打印换行
            printf("<br><br>");
        }
       else
        {
            //打印字符
            putchar(ch);
        }
    }
close(fp);

#endif

}
