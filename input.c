#include "funcall.h"
int read_int(char *prompt)
{
    int value;
    char line[100];
    while(1)
    {
        printf("%s",prompt);
        if(fgets(line,sizeof(line),stdin)==NULL)
	{
            return 0;
	}
        if(sscanf(line,"%d",&value)==1)
	{
            return value;
	}
        printf("Enter a valid number.\n");
    }
}
