#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX 100

struct room
{
    char name[20];
    int cost;
    int room_number;
    int availability;
};

struct room rooms[MAX];

int count = 0;

void read_file();
void write_file();
void add_room();
void delete_room();
void edit_room();
void search_room();
void sort_room();
void display_room();
void menu();

int main()
{
    read_file();
    menu();
    return 0;
}

void read_file()
{
    FILE *fp;
    fp = fopen("rooms.txt", "r");
    if(fp == NULL)
    {
        printf("File not found\n");
        exit(0);
    }
    while(!feof(fp))
    {
        fscanf(fp, "%s %d %d %d", rooms[count].name, &rooms[count].cost, &rooms[count].room_number, &rooms[count].availability);
        count++;
    }
    fclose(fp);
}

void write_file()
{
    FILE *fp;
    fp = fopen("rooms.txt", "w");
    if(fp == NULL)
    {
        printf("File not found\n");
        exit(0);
    }
    for(int i = 0; i < count; i++)
    {
        fprintf(fp, "%s %d %d %d\n", rooms[i].name, rooms[i].cost, rooms[i].room_number, rooms[i].availability);
    }
    fclose(fp);
}

void add_room()
{
    printf("Enter the name of the room: ");
    scanf("%s", rooms[count].name);
    printf("Enter the cost of the room: ");
    scanf("%d", &rooms[count].cost);
    printf("Enter the room number: ");
    scanf("%d", &rooms[count].room_number);
    printf("Enter the availability of the room (1 = unavailable, 0 = available): ");
    scanf("%d", &rooms[count].availability);
    count++;
    write_file();
}

void delete_room()
{
    int room_number;
    printf("Enter the room number to delete: ");
    scanf("%d", &room_number);
    for(int i = 0; i < count; i++)
    {
        if(rooms[i].room_number == room_number)
        {
            for(int j = i; j < count; j++)
            {
                strcpy(rooms[j].name, rooms[j+1].name);
                rooms[j].cost = rooms[j+1].cost;
                rooms[j].room_number = rooms[j+1].room_number;
                rooms[j].availability = rooms[j+1].availability;
            }
            count--;
            break;
        }
    }
    write_file();
}

void edit_room()
{
    int room_number;
    printf("Enter the room number to edit: ");
    scanf("%d", &room_number);
    for(int i = 0; i < count; i++)
    {
        if(rooms[i].room_number == room_number)
        {
            printf("Enter the name of the room: ");
            scanf("%s", rooms[i].name);
            printf("Enter the cost of the room: ");
            scanf("%d", &rooms[i].cost);
            printf("Enter the room number: ");
            scanf("%d", &rooms[i].room_number);
            printf("Enter the availability of the room: ");
            scanf("%d", &rooms[i].availability);
            break;
        }
    }
    write_file();
}

void search_room()
{
    int room_number;
    printf("Enter the room number to search: ");
    scanf("%d", &room_number);
    for(int i = 0; i < count; i++)
    {
        if(rooms[i].room_number == room_number)
        {
            printf("Name: %s\n", rooms[i].name);
            printf("Cost: %d\n", rooms[i].cost);
            printf("Room Number: %d\n", rooms[i].room_number);
            printf("Availability: %d\n", rooms[i].availability);
            break;
        }
    }
}


void sort_room()
{
    int choice;
    printf("1. Sort by name\n");
    printf("2. Sort by cost\n");
    printf("3. Sort by room number\n");
    printf("4. Sort by availability\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice)
    {
        case 1:
            for(int i = 0; i < count; i++)
            {
                for(int j = 0; j < count - i - 1; j++)
                {
                    if(strcmp(rooms[j].name, rooms[j+1].name) > 0)
                    {
                        struct room temp = rooms[j];
                        rooms[j] = rooms[j+1];
                        rooms[j+1] = temp;
                    }
                }
            }
            break;
        case 2:
            for(int i = 0; i < count; i++)
            {
                for(int j = 0; j < count - i - 1; j++)
                {
                    if(rooms[j].cost > rooms[j+1].cost)
                    {
                        struct room temp = rooms[j];
                        rooms[j] = rooms[j+1];
                        rooms[j+1] = temp;
                    }
                }
            }
            break;
        case 3:
            for(int i = 0; i < count; i++)
            {
                for(int j = 0; j < count - i - 1; j++)
                {
                    if(rooms[j].room_number > rooms[j+1].room_number)
                    {
                        struct room temp = rooms[j];
                        rooms[j] = rooms[j+1];
                        rooms[j+1] = temp;
                    }
                }
            }
            break;
        case 4:
            for(int i = 0; i < count; i++)
            {
                for(int j = 0; j < count - i - 1; j++)
                {
                    if(rooms[j].availability > rooms[j+1].availability)
                    {
                        struct room temp = rooms[j];
                        rooms[j] = rooms[j+1];
                        rooms[j+1] = temp;
                    }
                }
            }
            break;
        default:
            printf("Invalid choice\n");
            break;
    }
    write_file();
}

void display_room()
{
    for(int i = 0; i < count; i++)
    {
        printf("Name: %s\n", rooms[i].name);
        printf("Cost: %d\n", rooms[i].cost);
        printf("Room Number: %d\n", rooms[i].room_number);
        printf("Availability: %d\n", rooms[i].availability);
        printf("\n");
    }
}

void menu()
{
    int choice;
    do
    {
        printf("1. Add room\n");
        printf("2. Delete room\n");
        printf("3. Edit room\n");
        printf("4. Search room\n");
        printf("5. Sort room\n");
        printf("6. Display room\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                add_room();
                break;
            case 2:
                delete_room();
                break;
            case 3:
                edit_room();
                break;
            case 4:
                search_room();
                break;
            case 5:
                sort_room();
                break;
            case 6:
                display_room();
                break;
            case 7:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }while(choice != 7);
    
}

