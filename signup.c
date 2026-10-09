#include "funcall.h"
void signup()
{
    char username[50],password[50],u[50],p[50];
    FILE *fp;
    int valid;
    printf("\n====== SIGN-UP ======\n");
    printf("Username : ");
    scanf("%s",username);
    fp=fopen("usr_logins.txt","r");
    if(fp!=NULL)
    {
        while(fscanf(fp,"%s %s",u,p)==2)
        {
            if(strcmp(username,u)==0)
            {
                fclose(fp);
                printf("Username already exists.\n");
                return;
            }
        }
        fclose(fp);
    }
    do
    {
        printf("Password : ");
        scanf("%s",password);
        valid=check_password(password);
        if(!valid)
	{
	    printf("-----------------------------------------\n");	
            printf("8 charectars/upper/lower/number/special\n");
            printf("Password is not strong enough. Try again.\n");
	    printf("-----------------------------------------\n");	
	}
    }while(!valid);
    fp=fopen("usr_logins.txt","a");
    if(fp==NULL)
    {
        printf("Could not open user file.\n");
        return;
    }
    fprintf(fp,"%s %s\n",username,password);
    fclose(fp);
    printf("Sign-up successful.\n");
}
