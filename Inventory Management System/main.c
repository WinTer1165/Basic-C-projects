#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Inventory Management System.
// A small shop's stock room. Add products, sell and restock them, see which
// items are running low, and check the total value of everything on hand.
// The stock list is saved to a file so it survives between runs.
//
// Tip: run this program from inside its own folder so it can find inventory.txt.

#define MAX_PRODUCTS 200
#define LOW_STOCK 5          // warn when a product drops below this many units
#define FILE_NAME "inventory.txt"

struct product
{
    int id;
    char name[50];
    int quantity;
    double price;
};

struct product products[MAX_PRODUCTS];
int product_count = 0;
int next_id = 1;

void load_products()
{
    FILE *fp = fopen(FILE_NAME, "r");
    if (fp == NULL)
    {
        return;
    }

    while (product_count < MAX_PRODUCTS)
    {
        struct product *p = &products[product_count];

        // id and name on one line, then quantity and price on the next
        if (fscanf(fp, "%d %49[^\n]\n", &p->id, p->name) != 2)
        {
            break;
        }
        fscanf(fp, "%d %lf\n", &p->quantity, &p->price);

        if (p->id >= next_id)
        {
            next_id = p->id + 1;
        }
        product_count++;
    }

    fclose(fp);
}

void save_products()
{
    FILE *fp = fopen(FILE_NAME, "w");
    if (fp == NULL)
    {
        printf("Could not save inventory to file.\n");
        return;
    }

    for (int i = 0; i < product_count; i++)
    {
        fprintf(fp, "%d %s\n%d %.2f\n",
                products[i].id, products[i].name,
                products[i].quantity, products[i].price);
    }

    fclose(fp);
}

int find_product(int id)
{
    for (int i = 0; i < product_count; i++)
    {
        if (products[i].id == id)
        {
            return i;
        }
    }
    return -1;
}

void add_product()
{
    if (product_count >= MAX_PRODUCTS)
    {
        printf("\nThe stock room is full.\n");
        return;
    }

    struct product *p = &products[product_count];
    p->id = next_id++;

    getchar();
    printf("Enter product name: ");
    fgets(p->name, sizeof(p->name), stdin);
    p->name[strcspn(p->name, "\n")] = '\0';

    printf("Enter starting quantity: ");
    scanf("%d", &p->quantity);
    printf("Enter unit price: ");
    scanf("%lf", &p->price);

    product_count++;
    save_products();
    printf("Product added with id %d.\n", p->id);
}

void display_products()
{
    if (product_count == 0)
    {
        printf("\nNo products in the inventory yet.\n");
        return;
    }

    printf("\n%-5s %-25s %-10s %-10s\n", "ID", "Name", "Quantity", "Price");
    printf("------------------------------------------------------\n");
    for (int i = 0; i < product_count; i++)
    {
        printf("%-5d %-25s %-10d %-10.2f\n",
               products[i].id, products[i].name,
               products[i].quantity, products[i].price);
    }
}

void sell_product()
{
    int id, amount;
    printf("Enter product id to sell: ");
    scanf("%d", &id);

    int index = find_product(id);
    if (index == -1)
    {
        printf("No product with that id.\n");
        return;
    }

    printf("How many units sold? ");
    scanf("%d", &amount);

    if (amount <= 0)
    {
        printf("Amount must be more than zero.\n");
        return;
    }
    if (amount > products[index].quantity)
    {
        printf("Not enough stock. Only %d left.\n", products[index].quantity);
        return;
    }

    products[index].quantity -= amount;
    save_products();
    printf("Sold %d unit(s). %d left in stock.\n", amount, products[index].quantity);

    if (products[index].quantity < LOW_STOCK)
    {
        printf("Heads up: this product is running low.\n");
    }
}

void restock_product()
{
    int id, amount;
    printf("Enter product id to restock: ");
    scanf("%d", &id);

    int index = find_product(id);
    if (index == -1)
    {
        printf("No product with that id.\n");
        return;
    }

    printf("How many units to add? ");
    scanf("%d", &amount);

    if (amount <= 0)
    {
        printf("Amount must be more than zero.\n");
        return;
    }

    products[index].quantity += amount;
    save_products();
    printf("Restocked. %d now in stock.\n", products[index].quantity);
}

void low_stock_report()
{
    int found = 0;
    printf("\nProducts below %d units:\n", LOW_STOCK);
    for (int i = 0; i < product_count; i++)
    {
        if (products[i].quantity < LOW_STOCK)
        {
            printf("   [%d] %s (%d left)\n",
                   products[i].id, products[i].name, products[i].quantity);
            found = 1;
        }
    }
    if (!found)
    {
        printf("   Everything is well stocked.\n");
    }
}

void total_value()
{
    double total = 0;
    for (int i = 0; i < product_count; i++)
    {
        total += products[i].quantity * products[i].price;
    }
    printf("\nTotal value of all stock: %.2f\n", total);
}

void delete_product()
{
    int id;
    printf("Enter product id to delete: ");
    scanf("%d", &id);

    int index = find_product(id);
    if (index == -1)
    {
        printf("No product with that id.\n");
        return;
    }

    for (int i = index; i < product_count - 1; i++)
    {
        products[i] = products[i + 1];
    }
    product_count--;

    save_products();
    printf("Product deleted.\n");
}

int main()
{
    int choice;

    load_products();
    printf("\n. . . . . INVENTORY MANAGEMENT SYSTEM . . . . .\n");

    while (1)
    {
        printf("\n1. Add a product\n");
        printf("2. Show all products\n");
        printf("3. Sell a product\n");
        printf("4. Restock a product\n");
        printf("5. Low stock report\n");
        printf("6. Total inventory value\n");
        printf("7. Delete a product\n");
        printf("8. Exit\n");
        printf("Your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("\nGoodbye!\n");
            break;
        }

        switch (choice)
        {
        case 1: add_product();      break;
        case 2: display_products(); break;
        case 3: sell_product();     break;
        case 4: restock_product();  break;
        case 5: low_stock_report(); break;
        case 6: total_value();      break;
        case 7: delete_product();   break;
        case 8:
            printf("\nGoodbye!\n");
            return 0;
        default:
            printf("Please pick a number between 1 and 8.\n");
        }
    }

    return 0;
}
