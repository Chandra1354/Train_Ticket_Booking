#include "funcall.h"
void cancel_ticket()
{
    int number,seat,removed=0;
    char date[15];
    Passenger_info *p=passenger_head,*prev=NULL,*next;
    printf("\n====== CANCEL TICKET ======\n");
    printf("Train number: ");
    scanf("%d",&number);
    printf("Journey date (DD-MM-YYYY): ");
    scanf("%s",date);
    printf("Seat number: ");
    scanf("%d",&seat);
    while(p!=NULL)
    {
        next=p->next;
        if(p->train_number==number && strcmp(p->date,date)==0 && p->seat_number==seat && !p->waiting)
        {
            save_cancelled(p);
            if(prev==NULL)
	    {
                passenger_head=next;
	    }
            else
	    {
                prev->next=next;
	    }
            free(p);
            removed=1;
            break;
        }
        prev=p;
        p=next;
    }
    if(!removed)
    {
        printf("Active booking not found. Check train, date and seat number.\n");
        return;
    }
    {
        int current=0;
        for(p=passenger_head;p!=NULL;p=p->next)
        {
            if(p->train_number==number && strcmp(p->date,date)==0 && !p->waiting)
	    {
                p->seat_number= ++current;
	    }
        }
    }
    save_passengers();
    printf("------------------------------------\n");
    printf("Ticket cancelled successfully.\n");
}
