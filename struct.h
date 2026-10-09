//struct
typedef struct
{
    int total_seats;
    int waiting_list;
    int current_booking_seat_number;
} Seats_info;

typedef struct Train_info
{
    char train_name[50];
    int train_number;
    char source[50];
    char destination[50];
    int no_of_seats;
    Seats_info seats;
    struct Train_info *next;
} Train_info;

typedef struct Passenger_info
{
    int train_number;
    char date[15];
    int seat_number;
    char name[50];
    int age;
    char gender[15];
    int waiting;
    struct Passenger_info *next;
} Passenger_info;

typedef struct User_info
{
    char username[50];
    char password[50];
} User_info;
