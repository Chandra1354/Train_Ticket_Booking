#include "funcall.h"
void free_lists()
{
    Train_info *t;
    Passenger_info *p;
    while(train_head!=NULL)
    {
        t=train_head;
        train_head=train_head->next;
        free(t);
    }
    while(passenger_head!=NULL)
    {
        p=passenger_head;
        passenger_head=passenger_head->next;
        free(p);
    }
}
