#include "funcall.h"
Train_info *train_head=NULL;
Passenger_info *passenger_head=NULL;
char logged_user[50];
int main()
{
    int choice,logged_in;
    char username[50];
    syncfile();
    while(1)
    {
        printf("\n====== TRAIN TICKET BOOKING ======\n");
        printf("1. SIGN-UP\n2. SIGN-IN\n3. EXIT\n");
        choice = read_int("Enter choice: ");
        switch(choice)
        {
            case 1:signup();
		   break;
            case 2:logged_in=signin();
		   if(logged_in)
		   {
                    main_menu(logged_user);
		   }
		   break;
            case 3:save_trains();
		   save_passengers();
		   free_lists();
		   printf("Thank you.\n");
		   return 0;
            default:printf("Invalid choice.\n");
        }
    }
}
