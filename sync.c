#include "funcall.h"
void syncfile()
{
    FILE *fp;
    int number,seats,total,waiting,current,age,seat,is_waiting;
    char name[50],source[50],destination[50];
    char date[15],gender[15],passenger_name[50];
    Train_info *t, *tlast;
    Passenger_info *p, *plast;
    fp=fopen("trains_info.txt","r");
    if(fp==NULL)
    {
        t=calloc(1,sizeof(*t));
        if(t!=NULL)
        {
            strcpy(t->train_name, "Chennai_Express");
            t->train_number =101;
            strcpy(t->source, "Nellore");
            strcpy(t->destination, "Chennai");
            t->no_of_seats=t->seats.total_seats= 20;
            train_head=t;
            t->next=calloc(1,sizeof(*t));
            if(t->next!=NULL)
            {
                t=t->next;
                strcpy(t->train_name, "Godavari_Express");
                t->train_number=102;
                strcpy(t->source,"Hyderabad");
                strcpy(t->destination,"Vijayawada");
                t->no_of_seats =t->seats.total_seats =20;
                t->next=calloc(1,sizeof(*t));
                if(t->next!=NULL)
                {
                    t=t->next;
                    strcpy(t->train_name,"Vande_Bharat");
                    t->train_number=103;
                    strcpy(t->source,"Nellore");
                    strcpy(t->destination,"Hyderabad");
                    t->no_of_seats = t->seats.total_seats =20;
                }
            }
        }
        save_trains();
    }
    else
    {
        while(fscanf(fp,"%d %s %s %s %d %d %d %d",&number,name,source,destination,&seats,&total,&waiting,&current)==8)
        {
            t=calloc(1,sizeof(*t));
            if(t==NULL) 
	    {
		    break;
	    }
            t->train_number=number;
            strcpy(t->train_name, name);
            strcpy(t->source,source);
            strcpy(t->destination, destination);
            t->no_of_seats=seats;
            t->seats.total_seats=total;
            t->seats.waiting_list=waiting;
            t->seats.current_booking_seat_number=current;
            if(train_head==NULL) 
	    {
		    train_head=t;
	    }
            else 
	    {
		    tlast=train_head; 
		    while(tlast->next) 
		    {
			    tlast=tlast->next; 
			    tlast->next=t; 
		    }
	    }
	}
        fclose(fp);
    }
    fp=fopen("passengers_info.txt","r");
    if(fp==NULL) 
    {
	    return;
    }
    while(fscanf(fp,"%d %s %d %s %d %s %d",&number,date,&seat,passenger_name,&age,gender,&is_waiting)==7)
    {
        p=calloc(1,sizeof(*p));
        if(p==NULL) 
	{
		break;
	}
        p->train_number=number;
        strcpy(p->date,date);
        p->seat_number=seat;
        strcpy(p->name,passenger_name);
        p->age=age;
        strcpy(p->gender,gender);
        p->waiting=is_waiting;
        if(passenger_head==NULL)
	{
	       passenger_head=p;
	}
        else
	{
		plast=passenger_head;
		while(plast->next)
		{
			plast=plast->next;
			plast->next=p;
		}
	}
    }
    fclose(fp);
}
