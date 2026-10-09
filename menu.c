#include "funcall.h"
void main_menu(char *username)
{
    char choice;
    while(1)
    {
	printf("\n=============================== MAIN MENU ==================================\n");
        train_information();
        printf("\nR/r : Reserve ticket\nC/c : Cancel ticket\nB/b : Booking details\n");
        printf("Q/q : Logout\n");
        //printf("/*A/a : Add train (TRAIN_ADMIN only)\nQ/q : Logout\n");
        printf("Enter choice: ");
        scanf(" %c",&choice);
        switch(choice)
        {
            case 'R':
	    case 'r':reserve_ticket(); 
		     break;
            case 'C':
	    case 'c':cancel_ticket();
		     break;
            case 'B':
	    case 'b':booking_details();
		     break;
            case 'A':
	    case 'a':if(strcmp(username,"TRAIN_ADMIN")==0)
		     {
			     add_train();
		     }
		     else
		     {
			     printf("Only TRAIN_ADMIN can add trains.\n");
		     }
		     break;
            case 'Q':
	    case 'q': return;
            default: printf("Invalid choice.\n");
        }
    }
}
