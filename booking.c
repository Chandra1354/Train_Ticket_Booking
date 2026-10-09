#include "funcall.h"
void booking_details()
{
    Passenger_info *p=passenger_head;
    int found=0;

    printf("\n====== ACTIVE BOOKING DETAILS ======\n");
    printf("%-8s %-12s %-6s %-20s %-5s %-10s\n","Train","Date","Seat","Name","Age","Gender");
    while(p!=NULL)
    {
        if(!p->waiting)
        {
            printf("%-8d %-12s %-6d %-20s %-5d %-10s\n",p->train_number,p->date,p->seat_number,p->name,p->age,p->gender);
            found=1;
        }
        p=p->next;
    }
    if(!found)
    {
        printf("No active bookings.\n");
    }
}
