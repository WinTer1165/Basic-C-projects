#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

#define MAX_SEAT 40
#define P_NAME_SIZE 50
#define P_CONTACT_SIZE 15

int P_MAX;
int ID = 1000;
float TICKET_PRICE = 320;

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
    // Alternate: system("cls");
}

float return_money(float x, float y)
{
    return x - y;
}

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

int passenger_number()
{
    int counter = 0;
    char ch;
    FILE *fp;
    fp = fopen("details.txt", "r");
    while ((ch = fgetc(fp)) != EOF)
    {
        if (ch == '\n')
            counter++;
    }
    P_MAX = counter;
    return P_MAX;
}

void add_Passenger(struct Passenger commuter[MAX_SEAT])
{
    FILE *fp;
    for (int i = passenger_number(); i < MAX_SEAT; i++)
    {
        fp = fopen("details.txt", "a");

        commuter[i].passenger_id = passenger_identity();
        printf("Enter passenger name(max: 50 characters): ");
        scanf("\n");
        scanf("%[^\n]%*c", commuter[i].passenger_name);

        printf("Enter passenger mobile number(max: 11 digits): ");
        scanf("\n");
        scanf("%[^\n]%*c", commuter[i].passenger_contact);

        printf("Enter passenger seat number: ");
        scanf("%d", &commuter[i].passenger_seat_position);

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
            break;
        }

        else
        {
            printf("Invalid Command!\n\n");
            goto bus_overload;
        }
    }
}

void view_Passenger(struct Passenger commuter[MAX_SEAT])
{
    passenger_number();
    FILE *fp;
    fp = fopen("details.txt", "r");

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
        printf("Received Money : %f \n", commuter[i].given_money);
        printf("Ticket Price   : %f \n", commuter[i].ticket_price);
        printf("Return Money   : %f \n", commuter[i].return_money);
        printf("\n\n\n");
    }
    fclose(fp);
}

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
        fp = fopen("details.txt", "r");
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
                printf("Received Money : %f \n", commuter[i].given_money);
                printf("Ticket Price   : %f \n", commuter[i].ticket_price);
                printf("Return Money   : %f \n", commuter[i].return_money);
                printf("\n\n\n");
            }
        }
        fclose(fp);
        break;

    case 2:
        fp = fopen("details.txt", "r");
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
                printf("Received Money : %f \n", commuter[i].given_money);
                printf("Ticket Price   : %f \n", commuter[i].ticket_price);
                printf("Return Money   : %f \n", commuter[i].return_money);
                printf("\n\n\n");
            }
        }
        fclose(fp);
        break;

    case 3:
        fp = fopen("details.txt", "r");
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
                printf("Received Money : %f \n", commuter[i].given_money);
                printf("Ticket Price   : %f \n", commuter[i].ticket_price);
                printf("Return Money   : %f \n", commuter[i].return_money);
                printf("\n\n\n");
            }
        }
        fclose(fp);
        break;

    case 4:
        fp = fopen("details.txt", "r");
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
                printf("Received Money : %f \n", commuter[i].given_money);
                printf("Ticket Price   : %f \n", commuter[i].ticket_price);
                printf("Return Money   : %f \n", commuter[i].return_money);
                printf("\n\n\n");
            }
        }
        fclose(fp);
        break;
    }
}

void remove_Passenger(struct Passenger commuter[MAX_SEAT])
{
    FILE *fp;
    FILE *temp;
    fp = fopen("details.txt", "r");
    temp = fopen("temp.txt", "w");
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
    fp = fopen("details.txt", "w");
    temp = fopen("temp.txt", "r");

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

void replace_Passenger(struct Passenger commuter[MAX_SEAT])
{
    FILE *fp;
    FILE *temp;
    fp = fopen("details.txt", "r");
    temp = fopen("temp.txt", "w");
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
    fp = fopen("details.txt", "w");
    temp = fopen("temp.txt", "r");

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

void main()
{
    struct Passenger commuter[MAX_SEAT];
menu:
    clr_scrn();
    printf("What do you want to do?\n 1.Add Passenger\n 2.View Passenger Info\n 3.Search Passenger Info\n 4.Remove Passenger\n 5.Replace Passenger\n 6.Exit\n");
    int choice;
invalid_menu:
    printf("Your Command: ");
    scanf("%d", &choice);
    if (choice == 1)
    {
        add_Passenger(commuter);
        goto menu;
    }
    else if (choice == 2)
    {
        view_Passenger(commuter);
    zero_supremacy:
        printf("\n0.Back to Main Menu\nYour Command: ");
        scanf("%d", &choice);
        if (choice == 0)
        {
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
        printf("Thank You for utilizing me. Please use me again.");
    }

    else
    {
        printf("Invalid Command!\n\n");
        goto invalid_menu;
    }
}