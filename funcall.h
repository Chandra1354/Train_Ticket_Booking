#ifndef FUNCALL_H
#define FUNCALL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <time.h>
#include "struct.h"
/*
#define TRAIN_FILE "trains_info.txt"
#define BOOKING_FILE "passengers_info.txt"
#define USER_FILE "usr_logins.txt"
#define CANCEL_FILE "cancelled_info.txt"
#define MAX_TEXT 50
*/
extern Train_info *train_head;
extern Passenger_info *passenger_head;
extern char logged_user[50];

void syncfile();
void free_lists();
void save_trains();
void save_passengers();
void save_cancelled(Passenger_info *p);
void free_lists();

int check_password(char password[]);
void signup();
int signin();
void main_menu(char *username);
void train_information();
void add_train();
void reserve_ticket();
void cancel_ticket();
void booking_details();
Train_info *find_train(int train_number);
int date_allowed(char *date);
int train_has_name(char *name);
int train_has_number(int number);
int read_int(char *prompt);

#endif
