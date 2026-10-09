#include "funcall.h"
int signin()
{
    char username[50],password[50];
    char file_user[50],file_password[50];
    FILE *fp;
    int attempt,found;
    for(attempt=1;attempt<=5;attempt++)
    {
        printf("\n====== SIGN-IN ======\n");
        printf("Username: ");
        scanf("%s", username);
        printf("Password: ");
        scanf("%s", password);
        fp=fopen("usr_logins.txt","r");
        if(fp==NULL)
        {
            printf("No users found. Please sign up first.\n");
            return 0;
        }
        found=0;
        while(fscanf(fp,"%s %s",file_user,file_password)==2)
        {
            if(strcmp(username,file_user)==0 && strcmp(password,file_password)==0)
            {
                found=1;
                break;
            }
        }
        fclose(fp);
        if(found)
        {
            printf("Sign-in successful.\n");
            return 1;
        }
        printf("Wrong username/password. Attempt %d of 5.\n", attempt);
    }
    printf("Maximum attempts reached.\n");
    return 0;
}
