#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Library Management System.
// Keep track of the books in a small library: add new books, issue a book
// to someone, take it back, search the shelf, and remove old titles.
// Everything is saved to a file so the library is the same next time you open it.
//
// Tip: run this program from inside its own folder so it can find library.txt.

#define MAX_BOOKS 200
#define FILE_NAME "library.txt"

struct book
{
    int id;
    char title[100];
    char author[100];
    int is_issued;          // 0 = on the shelf, 1 = issued out
    char issued_to[50];     // who currently has it ("-" when on the shelf)
};

struct book books[MAX_BOOKS];
int book_count = 0;
int next_id = 1;

// read a full line into 'buffer' and strip the trailing newline
void read_line(char *buffer, int size)
{
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
}

// load saved books from the file into memory.
// each book is stored as five lines: id, title, author, issued flag, borrower.
void load_books()
{
    FILE *fp = fopen(FILE_NAME, "r");
    if (fp == NULL)
    {
        return; // no file yet just means an empty library
    }

    char line[100];
    while (book_count < MAX_BOOKS && fgets(line, sizeof(line), fp) != NULL)
    {
        struct book *b = &books[book_count];

        b->id = atoi(line);

        fgets(b->title, sizeof(b->title), fp);
        b->title[strcspn(b->title, "\n")] = '\0';

        fgets(b->author, sizeof(b->author), fp);
        b->author[strcspn(b->author, "\n")] = '\0';

        fgets(line, sizeof(line), fp);
        b->is_issued = atoi(line);

        fgets(b->issued_to, sizeof(b->issued_to), fp);
        b->issued_to[strcspn(b->issued_to, "\n")] = '\0';

        if (b->id >= next_id)
        {
            next_id = b->id + 1; // keep new ids unique
        }
        book_count++;
    }

    fclose(fp);
}

// write the whole library back to the file
void save_books()
{
    FILE *fp = fopen(FILE_NAME, "w");
    if (fp == NULL)
    {
        printf("Could not save the library to file.\n");
        return;
    }

    for (int i = 0; i < book_count; i++)
    {
        fprintf(fp, "%d\n%s\n%s\n%d\n%s\n",
                books[i].id, books[i].title, books[i].author,
                books[i].is_issued, books[i].issued_to);
    }

    fclose(fp);
}

// find a book by its id, or return -1 if there is no such book
int find_book(int id)
{
    for (int i = 0; i < book_count; i++)
    {
        if (books[i].id == id)
        {
            return i;
        }
    }
    return -1;
}

void add_book()
{
    if (book_count >= MAX_BOOKS)
    {
        printf("\nThe library is full.\n");
        return;
    }

    struct book *b = &books[book_count];
    b->id = next_id++;
    b->is_issued = 0;
    strcpy(b->issued_to, "-");

    getchar(); // clear the leftover newline before reading lines
    printf("Enter the book title: ");
    read_line(b->title, sizeof(b->title));
    printf("Enter the author: ");
    read_line(b->author, sizeof(b->author));

    book_count++;
    save_books();
    printf("Book added with id %d.\n", b->id);
}

void display_books()
{
    if (book_count == 0)
    {
        printf("\nThe library has no books yet.\n");
        return;
    }

    printf("\n%-5s %-30s %-20s %-12s %s\n", "ID", "Title", "Author", "Status", "Borrower");
    printf("--------------------------------------------------------------------------------\n");
    for (int i = 0; i < book_count; i++)
    {
        printf("%-5d %-30s %-20s %-12s %s\n",
               books[i].id, books[i].title, books[i].author,
               books[i].is_issued ? "Issued" : "On shelf",
               books[i].issued_to);
    }
}

void issue_book()
{
    int id;
    printf("Enter the book id to issue: ");
    scanf("%d", &id);

    int index = find_book(id);
    if (index == -1)
    {
        printf("No book with that id.\n");
        return;
    }
    if (books[index].is_issued)
    {
        printf("That book is already issued to %s.\n", books[index].issued_to);
        return;
    }

    getchar();
    printf("Issue to whom? ");
    read_line(books[index].issued_to, sizeof(books[index].issued_to));
    books[index].is_issued = 1;

    save_books();
    printf("Book issued to %s.\n", books[index].issued_to);
}

void return_book()
{
    int id;
    printf("Enter the book id to return: ");
    scanf("%d", &id);

    int index = find_book(id);
    if (index == -1)
    {
        printf("No book with that id.\n");
        return;
    }
    if (!books[index].is_issued)
    {
        printf("That book is already on the shelf.\n");
        return;
    }

    books[index].is_issued = 0;
    strcpy(books[index].issued_to, "-");

    save_books();
    printf("Book returned. Thanks!\n");
}

void search_book()
{
    char keyword[100];
    int found = 0;

    getchar();
    printf("Enter a title to search for: ");
    read_line(keyword, sizeof(keyword));

    for (int i = 0; i < book_count; i++)
    {
        // strstr finds the keyword anywhere inside the title
        if (strstr(books[i].title, keyword) != NULL)
        {
            printf("[%d] %s by %s (%s)\n", books[i].id, books[i].title,
                   books[i].author, books[i].is_issued ? "issued" : "on shelf");
            found = 1;
        }
    }

    if (!found)
    {
        printf("No books matched that search.\n");
    }
}

void delete_book()
{
    int id;
    printf("Enter the book id to delete: ");
    scanf("%d", &id);

    int index = find_book(id);
    if (index == -1)
    {
        printf("No book with that id.\n");
        return;
    }

    // shift the rest of the list up to fill the gap
    for (int i = index; i < book_count - 1; i++)
    {
        books[i] = books[i + 1];
    }
    book_count--;

    save_books();
    printf("Book deleted.\n");
}

int main()
{
    int choice;

    load_books();
    printf("\n. . . . . LIBRARY MANAGEMENT SYSTEM . . . . .\n");

    while (1)
    {
        printf("\n1. Add a book\n");
        printf("2. Show all books\n");
        printf("3. Issue a book\n");
        printf("4. Return a book\n");
        printf("5. Search by title\n");
        printf("6. Delete a book\n");
        printf("7. Exit\n");
        printf("Your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("\nGoodbye!\n");
            break;
        }

        switch (choice)
        {
        case 1: add_book();      break;
        case 2: display_books(); break;
        case 3: issue_book();    break;
        case 4: return_book();   break;
        case 5: search_book();   break;
        case 6: delete_book();   break;
        case 7:
            printf("\nGoodbye!\n");
            return 0;
        default:
            printf("Please pick a number between 1 and 7.\n");
        }
    }

    return 0;
}
