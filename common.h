#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <time.h>

#define TRAIN_FILE "trains_info.txt"
#define BOOKING_FILE "passengers_info.txt"
#define USER_FILE "usr_logins.txt"
#define CANCEL_FILE "cancelled_info.txt"
#define MAX_TEXT 50

typedef struct
{
    int total_seats;
    int waiting_list;
    int current_booking_seat_number;
} Seats_info;

typedef struct Train_info
{
    char train_name[MAX_TEXT];
    int train_number;
    char source[MAX_TEXT];
    char destination[MAX_TEXT];
    int no_of_seats;
    Seats_info seats;
    struct Train_info *next;
} Train_info;

typedef struct Passenger_info
{
    int train_number;
    char date[15];
    int seat_number;
    char name[MAX_TEXT];
    int age;
    char gender[15];
    int waiting;
    struct Passenger_info *next;
} Passenger_info;

typedef struct User_info
{
    char username[MAX_TEXT];
    char password[MAX_TEXT];
} User_info;

extern Train_info *train_head;
extern Passenger_info *passenger_head;
extern char logged_user[MAX_TEXT];

void syncfile(void);
void free_lists(void);
void save_trains(void);
void save_passengers(void);
void save_cancelled(const Passenger_info *p);
void free_lists(void);

int check_password(const char password[]);
void signup(void);
int signin(void);
void main_menu(const char *username);
void train_information(void);
void add_train(void);
void reserve_ticket(void);
void cancel_ticket(void);
void booking_details(void);
Train_info *find_train(int train_number);
int date_allowed(const char *date);
int train_has_name(const char *name);
int train_has_number(int number);
int read_int(const char *prompt);

#endif
