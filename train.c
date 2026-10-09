#include "funcall.h"
Train_info *find_train(int train_number)
{
    Train_info *p=train_head;
    while(p!=NULL)
    {
        if(p->train_number==train_number)
	{
            return p;
	}
        p=p->next;
    }
    return NULL;
}
int train_has_number(int number)
{
    return find_train(number)!=NULL;
}

int train_has_name(char *name)
{
    Train_info *p=train_head;
    while (p!=NULL)
    {
        if(strcasecmp(p->train_name,name)==0)
	{
            return 1;
	}
        p=p->next;
    }
    return 0;
}

void train_information()
{
    Train_info *p=train_head;
    printf("\n====================TRAIN INFORMATION====================\n");
    printf("%-8s %-22s %-15s %-15s %-8s %-8s\n","Number","Train Name","Source","Destination","Seats","Waiting");
    if(p==NULL)
    {
        printf("No train records. TRAIN_ADMIN can add a train.\n");
        return;
    }
    while(p!=NULL)
    {
        printf("%-8d %-22s %-15s %-15s %-8d %-8d\n",p->train_number,p->train_name, p->source, p->destination,p->seats.total_seats, p->seats.waiting_list);
        p=p->next;
    }
}

void add_train()
{
    Train_info *p, *node;
    char name[50],source[50],destination[50];
    int number,seats;
    printf("\n====== ADD TRAIN ======\n");
    printf("Train number: ");
    scanf("%d",&number);
    if(train_has_number(number))
    {
        printf("Train number already exists.\n");
        return;
    }
    printf("Train name : ");
    scanf("%s",name);
    if(train_has_name(name))
    {
        printf("Train name already exists.\n");
        return;
    }
    printf("Source : ");
    scanf("%s",source);
    printf("Destination : ");
    scanf("%s",destination);
    printf("Total seats : ");
    scanf("%d",&seats);
    if(seats<=0)
    {
        printf("Seats must be greater than zero.\n");
        return;
    }
    node=calloc(1,sizeof(*node));
    if(node==NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }
    strcpy(node->train_name,name);
    node->train_number=number;
    strcpy(node->source,source);
    strcpy(node->destination,destination);
    node->no_of_seats=seats;
    node->seats.total_seats=seats;
    node->seats.waiting_list=0;
    node->seats.current_booking_seat_number=0;
    node->next=NULL;
    if(train_head==NULL)
    {
        train_head=node;
    }
    else
    {
        p=train_head;
        while(p->next!=NULL) 
	{
		p=p->next;
	}
        p->next=node;
    }
    save_trains();
    printf("Train added successfully.\n");
}
