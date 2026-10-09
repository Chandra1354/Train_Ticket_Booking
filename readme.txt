TRAIN TICKET BOOKING APPLICATION
================================

Folder:
    MINI

Files:
    funcall.h      function declarations
    struct.h       Structures
    main.c         Main program and first menu
    input.c        Integer input function
    signup.c       New user registration
    signin.c       User login
    password.c     Password validation
    menu.c         Menu after login
    train.c        Train list, search and admin train addition
    date_check.c   Checks that journey date is today or within next two days
    reserve.c      Ticket reservation
    cancel.c       Ticket cancellation and removal from active bookings
    booking.c      Displays active booking details
    save.c         Saves train, passenger and cancellation data
    sync.c         Reads previous data when the program starts
    free.c         Frees linked-list memory
    Makefile       Builds the application

Compile:
    Open terminal in this folder and run:
        make

Run:
        ./a.out

Clean compiled program:
        make clean

Default trains are created on the first run:
    101 Chennai_Express   Nellore -> Chennai       20 seats
    102 Godavari_Express  Hyderabad -> Vijayawada  20 seats
    103 Vande_Bharat      Nellore -> Hyderabad     20 seats

User:
    Sign up with a username and password.
    Password must be at least 8 characters and include uppercase,
    lowercase, a number and a special character.

Not added
Admin:
    Sign up with username TRAIN_ADMIN to use the Add Train option.
    Train number and train name must be unique.
    Enter train names, sources and destinations without spaces;
    use underscores instead of spaces.

Date:
    Reservation accepts only today, tomorrow or the day after tomorrow.
    Format: DD-MM-YYYY.

Cancellation:
    Enter train number, journey date and seat number.
    The booking is removed from passengers_info.txt and therefore
    does not appear in active Booking Details.
    A cancellation history is appended to cancelled_info.txt.

Persistent files created automatically:
    trains_info.txt
    passengers_info.txt
    usr_logins.txt
    cancelled_info.txt

Important:
    Keep the text data files in the same folder as the executable.
    Do not delete them if you want to retain earlier records.

Note:
    This is a learning project. Passwords are stored as plain text,
    so do not use a real or reused password.
