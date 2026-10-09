#include "funcall.h"
void save_trains()
{
    FILE *fp=fopen("trains_info.txt","w");
    Train_info *p;
    if(fp==NULL)
    {
        printf("Could not save train data.\n");
        return;
    }
    for(p=train_head;p!=NULL;p=p->next)
    {
        fprintf(fp,"%d %s %s %s %d %d %d %d\n",p->train_number,p->train_name,p->source,p->destination,p->no_of_seats,p->seats.total_seats,p->seats.waiting_list,p->seats.current_booking_seat_number);
    }
    fclose(fp);
}

void save_passengers()
{
    FILE *fp=fopen("passengers_info.txt","w");
    Passenger_info *p;
    if(fp==NULL)
    {
        printf("Could not save passenger data.\n");
        return;
    }
    for(p=passenger_head;p!=NULL;p=p->next)
    {
        fprintf(fp,"%d %s %d %s %d %s %d\n",p->train_number, p->date, p->seat_number, p->name, p->age, p->gender, p->waiting);
    }
    fclose(fp);
}

void save_cancelled(Passenger_info *p)
{
    FILE *fp=NULL;
    fp=fopen("cancelled_info.txt","a");
    if(fp==NULL)
    {
        printf("Could not save cancellation record.\n");
        return;
    }
    fprintf(fp,"%d %s %d %s %d %s CANCELLED\n",p->train_number, p->date, p->seat_number, p->name, p->age, p->gender);
    fclose(fp);
}
