#include "funcall.h"
void reserve_ticket()
{
    int number,requested,i,booked=0;
    char date[15],name[50],gender[15];
    int age;
    Train_info *t;
    Passenger_info *node,*last;
    printf("\n====== RESERVE TICKET ======\n");
    printf("Train number: ");
    scanf("%d",&number);
    t=find_train(number);
    if(t==NULL)
    {
        printf("Train not found.\n");
        return;
    }
    printf("Journey date (DD-MM-YYYY; today or next 2 days): ");
    scanf("%s",date);
    if(!date_allowed(date))
    {
        printf("Invalid date. Only today and the next two days are allowed.\n");
        return;
    }
    printf("Number of seats: ");
    scanf("%d",&requested);
    if(requested<=0)
    {
        printf("Seat count must be positive.\n");
        return;
    }
    for(i=0;i<requested;i++)
    {
        int seat=0;
        Passenger_info *q;
        for(q=passenger_head;q!=NULL;q=q->next)
        {
            if(q->train_number==number && strcmp(q->date,date)==0 && !q->waiting && q->seat_number>seat)
	    {
                seat=q->seat_number;
	    }
        }
        if(seat>=t->seats.total_seats)
        {
            printf("No confirmed seats left. Remaining passengers are not booked.\n");
            break;
        }
        printf("\nPassenger %d name : ", i+1);
        scanf("%s",name);
        printf("Age: ");
        scanf("%d",&age);
        printf("Gender(male/female): ");
        scanf("%s",gender);
        if(age<=0)
        {
            printf("Invalid age. Passenger skipped.\n");
            continue;
        }
        node=calloc(1,sizeof(*node));
        if(node==NULL)
        {
            printf("Memory allocation failed.\n");
            break;
        }
        node->train_number=number;
        strcpy(node->date,date);
        node->seat_number=seat+1;
        strcpy(node->name,name);
        node->age=age;
        strcpy(node->gender,gender);
        node->waiting=0;
        node->next=NULL;
        if(passenger_head==NULL)
	{
            passenger_head=node;
	}
        else
        {
            last=passenger_head;
            while(last->next!=NULL)
	    {
		    last=last->next;
	    }
            last->next=node;
        }
        booked++;
    }
    save_passengers();
    printf("--------------------------------------");
    printf("Confirmed seats booked: %d\n",booked);
    printf("--------------------------------------");
    if(booked<requested)
    {
        printf("Not all requested seats could be confirmed.\n");
    }
}
