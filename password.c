#include "funcall.h"
int check_password(char password[])
{
    int i,upper=0,lower=0,digit=0,special=0;
    if(strlen(password)<8)
    {
        return 0;
    }
    for(i=0;password[i]!='\0';i++)
    {
        if(password[i]>='A' && password[i]<='Z')
	{
            upper=1;
	}
        else if(password[i]>='a' && password[i]<='z')
	{
            lower=1;
	}
        else if(password[i]>='0' && password[i]<='9')
	{
            digit=1;
	}
        else
	{
            special=1;
	}
    }
    return upper && lower && digit && special;
}
