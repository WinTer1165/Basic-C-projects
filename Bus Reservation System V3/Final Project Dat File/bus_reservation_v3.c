#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include "splashscreen.c"

/*
stdio.h - standard input output: printf(), scanf(), FILE etc
string.h - string library: strcmp()
stdlib - standard library: for using random srand(), rand(), system clear etc
time.h - time library: for using random
Windows.h - windows specific header file: Sleep()
splashscreen.c - for starting animation
*/

// maximum number of seat in a single bus
#define MAX_SEAT 40
// maximum character a name can have
#define P_NAME_SIZE 50
// maximum phone number string
#define P_CONTACT_SIZE 15

// for running loop in file
int P_MAX;
// for generating a unique id number
int ID = 1000;
// ticket price
float TICKET_PRICE = 320;

// class
struct Passenger
{
    char passenger_name[P_NAME_SIZE];
    int passenger_id;
    char passenger_contact[P_CONTACT_SIZE];
    int passenger_seat_position;
    float given_money;
    float ticket_price;
    float return_money;
};

// clearing screen
void clr_scrn()
{
    system("@cls || clear");
    system("cls");
}

// small welcome message
void welcome_message()
{
    printf("/================================================================================\\\n");
    printf("|| ___     _            ___ _ _          ___           ___             _        ||\n");
    printf("|||_ _|_ _| |_ ___ _ _ / __(_| |_ _  _  | _ )_  _ ___ / __|___ _ ___ _(_)__ ___ ||\n");
    printf("|| | || ' |  _/ -_| '_| (__| |  _| || | | _ | || (_-< \\__ / -_| '_\\ V | / _/ -_)||\n");
    printf("|||___|_||_\\__\\___|_|  \\___|_|\\__|\\_, | |___/\\_,_/__/ |___\\___|_|  \\_/|_\\__\\___|||\n");
    printf("||                                |__/                                          ||\n");
    printf("||                                          powered by cat transportation system||\n");
    printf("\\================================================================================/\n");
}

// returning money after deducting ticket price from passenger given money
float return_money(float x, float y)
{
    return x - y;
}

// generating unique id number
int passenger_identity()
{
    srand(time(NULL));
    int number1 = rand() % 999;
    Sleep(rand() % 100);
    int number2 = rand() % 999;
    Sleep(rand() % 100);
    int number3 = rand() % 999;
    return ID + number1 + number2 + number3;
}

// detecting how many passengers are there in details file
int passenger_number()
{
    int counter = 0;
    char ch;
    FILE *fp;
    fp = fopen("details.dat", "r");
    while ((ch = fgetc(fp)) != EOF)
    {
        if (ch == '\n')
            counter++;
    }
    P_MAX = counter;
    return P_MAX;
}

// visualizing bus seats
void booked_seat(struct Passenger commuter[MAX_SEAT])
{
    FILE *fp;
    fp = fopen("details.dat", "r");
    passenger_number();
    int total_passenger = 0;
    int passenger_seat_positions[MAX_SEAT] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40};
    int all_seat_positions[MAX_SEAT] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40};

    for (int i = 0; i < P_MAX; i++)
    {
        fscanf(fp, "%d", &commuter[i].passenger_id);
        fscanf(fp, "%s", &commuter[i].passenger_name);
        fscanf(fp, "%s", &commuter[i].passenger_contact);
        fscanf(fp, "%d", &commuter[i].passenger_seat_position);
        fscanf(fp, "%f", &commuter[i].given_money);
        fscanf(fp, "%f", &commuter[i].ticket_price);
        fscanf(fp, "%f", &commuter[i].return_money);

        for (int j = 0; j < MAX_SEAT; j++)
        {
            if (passenger_seat_positions[j] == commuter[i].passenger_seat_position)
            {
                passenger_seat_positions[j] = 0;
                total_passenger++;
            }
        }
    }

    int row_times = 4, col_times = 10, bus_seats = 0;
    printf("  _________________________________________\n");
    printf(" ///___||___||-=Intercity Bus=-||___||___\\\\\\\n");
    printf("                                         \n");
    printf("  Door                           Driver  \n");
    printf("                                         \n");
    for (int i = 0; i < col_times; i++)
    {
        for (int k = 0; k < row_times; k++)
        {
            if (passenger_seat_positions[bus_seats] == 0)
            {
                printf("  [X] ");
            }
            else
            {
                printf("  [O] ");
            }
            printf("%2d", all_seat_positions[bus_seats]);

            if (all_seat_positions[bus_seats] % 2 == 0 && all_seat_positions[bus_seats] % 4 != 0)
            {
                printf("     ");
            }
            else
            {
                printf("   ");
            }

            bus_seats++;
        }
        printf("\n");
    }
    printf("_____________________________________________\n");
    printf("\n[O] = Seat Available \n[X] = Seat Booked\n");
    printf("Total Passenger: %d/40\n", total_passenger);
    fclose(fp);
}

// check if new passenger's seat conflict with previous passenger's seat
int check_seats(struct Passenger commuter[MAX_SEAT], int new_seat)
{
    FILE *fp;
    fp = fopen("details.dat", "r");
    passenger_number();
    int taken_seat[MAX_SEAT];
    for (int i = 0; i < P_MAX; i++)
    {
        fscanf(fp, "%d", &commuter[i].passenger_id);
        fscanf(fp, "%s", &commuter[i].passenger_name);
        fscanf(fp, "%s", &commuter[i].passenger_contact);
        fscanf(fp, "%d", &commuter[i].passenger_seat_position);
        fscanf(fp, "%f", &commuter[i].given_money);
        fscanf(fp, "%f", &commuter[i].ticket_price);
        fscanf(fp, "%f", &commuter[i].return_money);

        for (int j = 0; j < P_MAX; j++)
        {
            taken_seat[i] = commuter[i].passenger_seat_position;
        }
    }
    for (int i = 0; i < MAX_SEAT; i++)
    {
        if (taken_seat[i] == new_seat)
        {
            return 1;
        }
    }
}

// adding passenger or selling them tickets
void add_Passenger(struct Passenger commuter[MAX_SEAT])
{
    FILE *fp;
    for (int i = passenger_number(); i < MAX_SEAT; i++)
    {
        fp = fopen("details.dat", "a");

        commuter[i].passenger_id = passenger_identity();
        printf("Enter passenger name(max: 50 characters): ");
        scanf("\n");
        scanf("%[^\n]%*c", commuter[i].passenger_name);

        /*
        %*[^\n] scans everything until \n
        %*c scans a single character, which will be the \n left by %*[^\n]
        asterisk instructs scanf to discard the scanned character
        */

        printf("Enter passenger mobile number(max: 11 digits): ");
        scanf("\n");
        scanf("%[^\n]%*c", commuter[i].passenger_contact);

    seat_check_done:
        printf("Enter passenger seat number: ");
        scanf("%d", &commuter[i].passenger_seat_position);

        if (check_seats(commuter, commuter[i].passenger_seat_position) == 1)
        {
            printf("Invalid! Seat already taken! Below seats are empty!\n");
            booked_seat(commuter);
            goto seat_check_done;
        }

        printf("Enter passenger given money: ");
        scanf("%f", &commuter[i].given_money);
        commuter[i].ticket_price = TICKET_PRICE;
        commuter[i].return_money = return_money(commuter[i].given_money, TICKET_PRICE);

        fprintf(fp, "%d ", commuter[i].passenger_id);
        fprintf(fp, "%s ", commuter[i].passenger_name);
        fprintf(fp, "%s ", commuter[i].passenger_contact);
        fprintf(fp, "%d ", commuter[i].passenger_seat_position);
        fprintf(fp, "%f ", commuter[i].given_money);
        fprintf(fp, "%f ", commuter[i].ticket_price);
        fprintf(fp, "%f \n", commuter[i].return_money);
        fclose(fp);
    bus_overload:
        printf("Do you want to add another passenger?\n1.Yes\n0.Back to Main Menu\nYour Command: ");
        int choice;
        scanf("%d", &choice);
        if (choice == 1)
        {
            continue;
        }
        else if (choice == 0)
        {
            clr_scrn();
            break;
        }

        else
        {
            printf("Invalid Command!\n\n");
            goto bus_overload;
        }
    }
}

// outputs the entire passenger list
void view_Passenger(struct Passenger commuter[MAX_SEAT])
{
    passenger_number();
    FILE *fp;
    fp = fopen("details.dat", "r");

    for (int i = 0; i < P_MAX; i++)
    {
        fscanf(fp, "%d", &commuter[i].passenger_id);
        fscanf(fp, "%s", &commuter[i].passenger_name);
        fscanf(fp, "%s", &commuter[i].passenger_contact);
        fscanf(fp, "%d", &commuter[i].passenger_seat_position);
        fscanf(fp, "%f", &commuter[i].given_money);
        fscanf(fp, "%f", &commuter[i].ticket_price);
        fscanf(fp, "%f", &commuter[i].return_money);

        printf("Passenger ID   : %d \n", commuter[i].passenger_id);
        printf("Passenger Name : %s \n", commuter[i].passenger_name);
        printf("Contact Number : %s \n", commuter[i].passenger_contact);
        printf("Seat Number    : %d \n", commuter[i].passenger_seat_position);
        printf("Received Money : %.2f \n", commuter[i].given_money);
        printf("Ticket Price   : %.2f \n", commuter[i].ticket_price);
        printf("Return Money   : %.2f \n", commuter[i].return_money);
        printf("\n\n\n");
    }
    fclose(fp);
}

// searching passengers through name, seat number, id, mobile
void search_Passenger(struct Passenger commuter[MAX_SEAT])
{
    FILE *fp;
    int search_command;
    printf("Type '1' for searching with name\n");
    printf("Type '2' for searching with seat number\n");
    printf("Type '3' for searching with unique id number\n");
    printf("Type '4' for searching with contact number\n");
    printf("Type your searching preference: ");
    scanf("%d", &search_command);
    passenger_number();
    switch (search_command)
    {
    case 1:
        fp = fopen("details.dat", "r");
        printf("Enter passenger name(max: 50 characters): ");
        char search_name[P_NAME_SIZE];
        scanf("\n");
        scanf("%[^\n]%*c", search_name);
        for (int i = 0; i < P_MAX; i++)
        {
            fscanf(fp, "%d", &commuter[i].passenger_id);
            fscanf(fp, "%s", &commuter[i].passenger_name);
            fscanf(fp, "%s", &commuter[i].passenger_contact);
            fscanf(fp, "%d", &commuter[i].passenger_seat_position);
            fscanf(fp, "%f", &commuter[i].given_money);
            fscanf(fp, "%f", &commuter[i].ticket_price);
            fscanf(fp, "%f", &commuter[i].return_money);

            if (strcmp(search_name, commuter[i].passenger_name) == 0)
            {
                printf("Passenger ID   : %d \n", commuter[i].passenger_id);
                printf("Passenger Name : %s \n", commuter[i].passenger_name);
                printf("Contact Number : %s \n", commuter[i].passenger_contact);
                printf("Seat Number    : %d \n", commuter[i].passenger_seat_position);
                printf("Received Money : %.2f \n", commuter[i].given_money);
                printf("Ticket Price   : %.2f \n", commuter[i].ticket_price);
                printf("Return Money   : %.2f \n", commuter[i].return_money);
                printf("\n\n\n");
            }
        }
        fclose(fp);
        break;

    case 2:
        fp = fopen("details.dat", "r");
        printf("Enter passenger seat position: ");
        int search_seat;
        scanf("%d", &search_seat);
        for (int i = 0; i < P_MAX; i++)
        {
            fscanf(fp, "%d", &commuter[i].passenger_id);
            fscanf(fp, "%s", &commuter[i].passenger_name);
            fscanf(fp, "%s", &commuter[i].passenger_contact);
            fscanf(fp, "%d", &commuter[i].passenger_seat_position);
            fscanf(fp, "%f", &commuter[i].given_money);
            fscanf(fp, "%f", &commuter[i].ticket_price);
            fscanf(fp, "%f", &commuter[i].return_money);
            int file_seat = commuter[i].passenger_seat_position;
            if (file_seat == search_seat)
            {
                printf("Passenger ID   : %d \n", commuter[i].passenger_id);
                printf("Passenger Name : %s \n", commuter[i].passenger_name);
                printf("Contact Number : %s \n", commuter[i].passenger_contact);
                printf("Seat Number    : %d \n", commuter[i].passenger_seat_position);
                printf("Received Money : %.2f \n", commuter[i].given_money);
                printf("Ticket Price   : %.2f \n", commuter[i].ticket_price);
                printf("Return Money   : %.2f \n", commuter[i].return_money);
                printf("\n\n\n");
            }
        }
        fclose(fp);
        break;

    case 3:
        fp = fopen("details.dat", "r");
        printf("Enter passenger unique identity number: ");
        int search_id;
        scanf("%d", &search_id);
        for (int i = 0; i < P_MAX; i++)
        {
            fscanf(fp, "%d", &commuter[i].passenger_id);
            fscanf(fp, "%s", &commuter[i].passenger_name);
            fscanf(fp, "%s", &commuter[i].passenger_contact);
            fscanf(fp, "%d", &commuter[i].passenger_seat_position);
            fscanf(fp, "%f", &commuter[i].given_money);
            fscanf(fp, "%f", &commuter[i].ticket_price);
            fscanf(fp, "%f", &commuter[i].return_money);

            int file_id = commuter[i].passenger_id;
            if (file_id == search_id)
            {
                printf("Passenger ID   : %d \n", commuter[i].passenger_id);
                printf("Passenger Name : %s \n", commuter[i].passenger_name);
                printf("Contact Number : %s \n", commuter[i].passenger_contact);
                printf("Seat Number    : %d \n", commuter[i].passenger_seat_position);
                printf("Received Money : %.2f \n", commuter[i].given_money);
                printf("Ticket Price   : %.2f \n", commuter[i].ticket_price);
                printf("Return Money   : %.2f \n", commuter[i].return_money);
                printf("\n\n\n");
            }
        }
        fclose(fp);
        break;

    case 4:
        fp = fopen("details.dat", "r");
        printf("Enter passenger mobile number(max: 11 digits): ");
        char search_mobile[P_NAME_SIZE];
        scanf("\n");
        scanf("%[^\n]%*c", search_mobile);
        for (int i = 0; i < P_MAX; i++)
        {
            fscanf(fp, "%d", &commuter[i].passenger_id);
            fscanf(fp, "%s", &commuter[i].passenger_name);
            fscanf(fp, "%s", &commuter[i].passenger_contact);
            fscanf(fp, "%d", &commuter[i].passenger_seat_position);
            fscanf(fp, "%f", &commuter[i].given_money);
            fscanf(fp, "%f", &commuter[i].ticket_price);
            fscanf(fp, "%f", &commuter[i].return_money);

            if (strcmp(search_mobile, commuter[i].passenger_contact) == 0)
            {
                printf("Passenger ID   : %d \n", commuter[i].passenger_id);
                printf("Passenger Name : %s \n", commuter[i].passenger_name);
                printf("Contact Number : %s \n", commuter[i].passenger_contact);
                printf("Seat Number    : %d \n", commuter[i].passenger_seat_position);
                printf("Received Money : %.2f \n", commuter[i].given_money);
                printf("Ticket Price   : %.2f \n", commuter[i].ticket_price);
                printf("Return Money   : %.2f \n", commuter[i].return_money);
                printf("\n\n\n");
            }
        }
        fclose(fp);
        break;
    }
}

// removing passenger from bus
void remove_Passenger(struct Passenger commuter[MAX_SEAT])
{
    FILE *fp;
    FILE *temp;
    fp = fopen("details.dat", "r");
    temp = fopen("temp.dat", "w");
    passenger_number();
    printf("Enter passenger seat position: ");
    int search_seat;
    scanf("%d", &search_seat);
    for (int i = 0; i < P_MAX; i++)
    {
        fscanf(fp, "%d", &commuter[i].passenger_id);
        fscanf(fp, "%s", &commuter[i].passenger_name);
        fscanf(fp, "%s", &commuter[i].passenger_contact);
        fscanf(fp, "%d", &commuter[i].passenger_seat_position);
        fscanf(fp, "%f", &commuter[i].given_money);
        fscanf(fp, "%f", &commuter[i].ticket_price);
        fscanf(fp, "%f", &commuter[i].return_money);

        int file_seat = commuter[i].passenger_seat_position;
        if (file_seat != search_seat)
        {
            fprintf(temp, "%d ", commuter[i].passenger_id);
            fprintf(temp, "%s ", commuter[i].passenger_name);
            fprintf(temp, "%s ", commuter[i].passenger_contact);
            fprintf(temp, "%d ", commuter[i].passenger_seat_position);
            fprintf(temp, "%f ", commuter[i].given_money);
            fprintf(temp, "%f ", commuter[i].ticket_price);
            fprintf(temp, "%f \n", commuter[i].return_money);
        }
    }
    fclose(fp);
    fclose(temp);
    P_MAX--;
    fp = fopen("details.dat", "w");
    temp = fopen("temp.dat", "r");

    for (int i = 0; i < P_MAX; i++)
    {
        fscanf(temp, "%d", &commuter[i].passenger_id);
        fscanf(temp, "%s", &commuter[i].passenger_name);
        fscanf(temp, "%s", &commuter[i].passenger_contact);
        fscanf(temp, "%d", &commuter[i].passenger_seat_position);
        fscanf(temp, "%f", &commuter[i].given_money);
        fscanf(temp, "%f", &commuter[i].ticket_price);
        fscanf(temp, "%f", &commuter[i].return_money);

        int file_seat = commuter[i].passenger_seat_position;
        if (file_seat != search_seat)
        {
            fprintf(fp, "%d ", commuter[i].passenger_id);
            fprintf(fp, "%s ", commuter[i].passenger_name);
            fprintf(fp, "%s ", commuter[i].passenger_contact);
            fprintf(fp, "%d ", commuter[i].passenger_seat_position);
            fprintf(fp, "%f ", commuter[i].given_money);
            fprintf(fp, "%f ", commuter[i].ticket_price);
            fprintf(fp, "%f \n", commuter[i].return_money);
        }
    }
    fclose(fp);
    fclose(temp);
}

// replacing passenger from bus
void replace_Passenger(struct Passenger commuter[MAX_SEAT])
{
    FILE *fp;
    FILE *temp;
    fp = fopen("details.dat", "r");
    temp = fopen("temp.dat", "w");
    passenger_number();
    printf("Enter seat number to replace: ");
    int search_seat;
    scanf("%d", &search_seat);
    for (int i = 0; i < P_MAX; i++)
    {
        fscanf(fp, "%d", &commuter[i].passenger_id);
        fscanf(fp, "%s", &commuter[i].passenger_name);
        fscanf(fp, "%s", &commuter[i].passenger_contact);
        fscanf(fp, "%d", &commuter[i].passenger_seat_position);
        fscanf(fp, "%f", &commuter[i].given_money);
        fscanf(fp, "%f", &commuter[i].ticket_price);
        fscanf(fp, "%f", &commuter[i].return_money);

        int file_seat = commuter[i].passenger_seat_position;
        if (file_seat != search_seat)
        {
            fprintf(temp, "%d ", commuter[i].passenger_id);
            fprintf(temp, "%s ", commuter[i].passenger_name);
            fprintf(temp, "%s ", commuter[i].passenger_contact);
            fprintf(temp, "%d ", commuter[i].passenger_seat_position);
            fprintf(temp, "%f ", commuter[i].given_money);
            fprintf(temp, "%f ", commuter[i].ticket_price);
            fprintf(temp, "%f \n", commuter[i].return_money);
        }
        else
        {
            commuter[i].passenger_id = passenger_identity();
            printf("Enter passenger name(max: 50 characters): ");
            scanf("\n");
            scanf("%[^\n]%*c", commuter[i].passenger_name);

            printf("Enter passenger mobile number(max: 11 digits): ");
            scanf("\n");
            scanf("%[^\n]%*c", commuter[i].passenger_contact);

            commuter[i].passenger_seat_position = search_seat;

            printf("Enter passenger given money: ");
            scanf("%f", &commuter[i].given_money);
            commuter[i].ticket_price = TICKET_PRICE;
            commuter[i].return_money = return_money(commuter[i].given_money, TICKET_PRICE);

            fprintf(temp, "%d ", commuter[i].passenger_id);
            fprintf(temp, "%s ", commuter[i].passenger_name);
            fprintf(temp, "%s ", commuter[i].passenger_contact);
            fprintf(temp, "%d ", commuter[i].passenger_seat_position);
            fprintf(temp, "%f ", commuter[i].given_money);
            fprintf(temp, "%f ", commuter[i].ticket_price);
            fprintf(temp, "%f \n", commuter[i].return_money);
        }
    }
    fclose(fp);
    fclose(temp);
    fp = fopen("details.dat", "w");
    temp = fopen("temp.dat", "r");

    for (int i = 0; i < P_MAX; i++)
    {
        fscanf(temp, "%d", &commuter[i].passenger_id);
        fscanf(temp, "%s", &commuter[i].passenger_name);
        fscanf(temp, "%s", &commuter[i].passenger_contact);
        fscanf(temp, "%d", &commuter[i].passenger_seat_position);
        fscanf(temp, "%f", &commuter[i].given_money);
        fscanf(temp, "%f", &commuter[i].ticket_price);
        fscanf(temp, "%f", &commuter[i].return_money);

        fprintf(fp, "%d ", commuter[i].passenger_id);
        fprintf(fp, "%s ", commuter[i].passenger_name);
        fprintf(fp, "%s ", commuter[i].passenger_contact);
        fprintf(fp, "%d ", commuter[i].passenger_seat_position);
        fprintf(fp, "%f ", commuter[i].given_money);
        fprintf(fp, "%f ", commuter[i].ticket_price);
        fprintf(fp, "%f \n", commuter[i].return_money);
    }
    fclose(fp);
    fclose(temp);
}

// viewing bus earning
void bus_revenues(struct Passenger commuter[MAX_SEAT])
{
    FILE *fp;
    fp = fopen("details.dat", "r");
    passenger_number();
    int total_passenger = 0;
    float total_passenger_given_money = 0, total_booked_seat_price = 0, total_returned_money = 0, total_bus_ticket_price = 0;

    int passenger_seat_positions[MAX_SEAT] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40};

    for (int i = 0; i < P_MAX; i++)
    {
        fscanf(fp, "%d", &commuter[i].passenger_id);
        fscanf(fp, "%s", &commuter[i].passenger_name);
        fscanf(fp, "%s", &commuter[i].passenger_contact);
        fscanf(fp, "%d", &commuter[i].passenger_seat_position);
        fscanf(fp, "%f", &commuter[i].given_money);
        fscanf(fp, "%f", &commuter[i].ticket_price);
        fscanf(fp, "%f", &commuter[i].return_money);

        for (int j = 0; j < MAX_SEAT; j++)
        {
            if (passenger_seat_positions[j] == commuter[i].passenger_seat_position)
            {
                passenger_seat_positions[j] = 0;
                total_passenger_given_money += commuter[i].given_money;
                total_returned_money += commuter[i].return_money;
                total_passenger++;
            }
        }
    }
    fclose(fp);

    printf("      BUS INCOMES\n\n");
    printf("Number of Booked Seats : %d\n", total_passenger);
    printf("Empty Seats            : %d\n", MAX_SEAT - total_passenger);
    printf("Total Seats            : %d\n\n", MAX_SEAT);
    printf("Total Money Received   : %.2f BDT\n", total_passenger_given_money);
    printf("Total Money Returned   : %.2f BDT\n", total_returned_money);
    printf("Total Money Earned     : %.2f BDT\n", total_passenger * TICKET_PRICE);
    printf("All Seat Price         : %.2f BDT\n", MAX_SEAT * TICKET_PRICE);
    printf("Unsold Ticket Money    : %.2f BDT\n", (MAX_SEAT - total_passenger) * TICKET_PRICE);
}

// main function
void main()
{
    struct Passenger commuter[MAX_SEAT];
    //adding a little bit of animation
    splash_screen();
menu:
    printf("White \033[1;37m");
    clr_scrn();
    welcome_message();
    printf("What do you want to do?\n 1.Add Passenger\n 2.View Passenger Info\n 3.Search Passenger Info\n 4.Remove Passenger\n 5.Replace Passenger\n 6.View Bus Seats\n 7.Read Bus Incomes\n 8.Exit\n");
    int choice;
invalid_menu:
    printf("Your Command: ");
    scanf("%d", &choice);
    if (choice == 1)
    {
        clr_scrn();
        add_Passenger(commuter);
        goto menu;
    }
    else if (choice == 2)
    {
        clr_scrn();
        view_Passenger(commuter);
    zero_supremacy:
        printf("\n0.Back to Main Menu\nYour Command: ");
        scanf("%d", &choice);
        if (choice == 0)
        {
            clr_scrn();
            goto menu;
        }
        else
        {
            printf("Invalid Command!\n\n");
            goto zero_supremacy;
        }
    }
    else if (choice == 3)
    {
    thirsty_for_more_question_mark:
        clr_scrn();
        search_Passenger(commuter);
    zero_and_one_supremacy:
        printf("\n1.Search Again?\n0.Back to Main Menu\nYour Command: ");
        scanf("%d", &choice);
        if (choice == 0)
        {
            clr_scrn();
            goto menu;
        }
        else if (choice == 1)
        {
            clr_scrn();
            goto thirsty_for_more_question_mark;
        }

        else
        {
            printf("Invalid Command!\n\n");
            goto zero_and_one_supremacy;
        }
    }
    else if (choice == 4)
    {
    pls_not_again:
        clr_scrn();
        remove_Passenger(commuter);
        printf("Successfully removed... maybe\n");
    zero_and_one_supremacy_again:
        printf("\n1.Remove Another One?\n0.Back to Main Menu\nYour Command: ");
        scanf("%d", &choice);

        if (choice == 0)
        {
            clr_scrn();
            goto menu;
        }
        else if (choice == 1)
        {
            clr_scrn();
            goto pls_not_again;
        }

        else
        {
            printf("Invalid Command!\n\n");
            goto zero_and_one_supremacy_again;
        }
    }
    else if (choice == 5)
    {
    coup:
        clr_scrn();
        replace_Passenger(commuter);
        printf("Successfully replaced... maybe\n");
    zero_and_one_supremacy_for_the_last_time:

        printf("\n1.Replace Another One?\n0.Back to Main Menu\nYour Command: ");
        scanf("%d", &choice);
        if (choice == 0)
        {
            clr_scrn();
            goto menu;
        }
        else if (choice == 1)
        {
            clr_scrn();
            goto coup;
        }

        else
        {
            printf("Invalid Command!\n\n");
            goto zero_and_one_supremacy_for_the_last_time;
        }
    }

    else if (choice == 6)
    {
        clr_scrn();
        booked_seat(commuter);
    must_choose_zero:
        printf("\n0.Back to Main Menu\nYour Command: ");
        scanf("%d", &choice);
        if (choice == 0)
        {
            clr_scrn();
            goto menu;
        }
        else
        {
            printf("Invalid Command!\n\n");
            goto must_choose_zero;
        }
    }

    else if (choice == 7)
    {
        clr_scrn();
        bus_revenues(commuter);
    must_choose_zero_again:
        printf("\n0.Back to Main Menu\nYour Command: ");
        scanf("%d", &choice);
        if (choice == 0)
        {
            clr_scrn();
            goto menu;
        }
        else
        {
            printf("Invalid Command!\n\n");
            goto must_choose_zero_again;
        }
    }

    else if (choice == 8)
    {
        clr_scrn();
        printf("Thank you for utilizing me. Please use me again.\n[EXITED SUCCESSFULLY]\n");
    }

    else
    {
        printf("Invalid Command!\n\n");
        goto invalid_menu;
    }
}
