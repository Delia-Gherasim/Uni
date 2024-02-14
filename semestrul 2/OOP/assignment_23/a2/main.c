// ex2
/*
Bakery
Mary runs her family's bakery, “Bread'n Bagel”. Every day she struggles with keeping up to date with available stocks of raw materials and would like a program to help her manage the business more effectively.
Each Material used in the bakery must have: a name, a supplier, a quantity and the expiration date. Mary wants a software application that helps her in the following ways:
(a) Add, delete and update a material. A raw material is uniquely identified by its name, supplier and expiration date. If a material that already exists is added, its quantity will be modified (the new quantity is added to the existing one).
(b) See all available materials past their expiration date, containing a given string (if the string is empty, all materials past their expiration date will be considered).
(c) Display all materials from a given supplier, which are in short supply (quantity less than a user-provided value), sorted ascending by their quantities.
(d) Provide multiple undo and redo functionality. Each step will undo/redo the previous operation performed by the user.
*/

#include <stdio.h>
#include "functions.c"

int read_the_quantity_input_validation()
{
    int quantity;
    char user_input_buffer[10]; // allocate a buffer to hold user input
    while (1)
    {
        printf("Enter the quantity: ");
        fgets(user_input_buffer, sizeof(user_input_buffer), stdin); // read input from user
        // check if input is valid
        if (sscanf(user_input_buffer, "%d", &quantity) == 1 && quantity >= 0)
        {
            break;
        }
        else
        {
            printf("Invalid input. Please enter a positive integer.\n");
        }
    }
    return quantity;
}

int read_the_date_day_input_validation()
{
    int expiration_day;
    char user_input_buffer[10];
    while (1)
    {
        printf("Enter the expiration day: ");
        fgets(user_input_buffer, sizeof(user_input_buffer), stdin);
        if (sscanf(user_input_buffer, "%d", &expiration_day) == 1 && expiration_day > 0 && expiration_day < 31)
        {
            break;
        }
        else
        {
            printf("Invalid input. Please enter a positive integer smaller than 31.\n");
        }
    }
    return expiration_day;
}

int read_the_date_month_input_validation()
{
    int expiration_month;
    char user_input_buffer[10];
    while (1)
    {
        printf("Enter the expiration month: ");
        fgets(user_input_buffer, sizeof(user_input_buffer), stdin);
        if (sscanf(user_input_buffer, "%d", &expiration_month) == 1 && expiration_month > 0 && expiration_month < 13)
        {
            break;
        }
        else
        {
            printf("Invalid input. Please enter a positive integer smaller than 13.\n");
        }
    }
    return expiration_month;
}

int read_the_date_year_input_validation()
{
    int expiration_year;
    char user_input_buffer[10];
    while (1)
    {
        printf("Enter the expiration year: ");
        fgets(user_input_buffer, sizeof(user_input_buffer), stdin);
        if (sscanf(user_input_buffer, "%d", &expiration_year) == 1 && expiration_year > 0)
        {
            break;
        }
        else
        {
            printf("Invalid input. Please enter a positive integer.\n");
        }
    }
    return expiration_year;
}

void add_material_user_input()
{
    printf(" \n Type the name, supplier and expiration date of the new material\n");
    int quantity, expiration_day, expiration_month, expiration_year;
    char name[30], supplier[30];
    printf(" The new name is? \n");
    scanf("%s", &name);
    printf("The new supplier is? \n");
    scanf("%s", &supplier);
    quantity = read_the_quantity_input_validation();
    expiration_day = read_the_date_day_input_validation();
    expiration_month = read_the_date_month_input_validation();
    expiration_year = read_the_date_year_input_validation();

    int number_thet_the_add_element_function_returns = add_element(name, supplier, quantity, expiration_day, expiration_month, expiration_year);
    if (number_thet_the_add_element_function_returns == 1)
        printf("Material already exists, but it has been updated");
    else
    {
        printf("Material has been added");
        used_commands_that_can_be_undone[undo_count] = 1;
        undo_count++;
    }
}
void delete_a_material_user_input()
{
    printf(" \n Type the name, supplier and expiration date of the material you want to delete\n");
    int quantity, expiration_day, expiration_month, expiration_year;
    char name[30], supplier[30];
    printf("The name of the material you want to delete is? \n");
    scanf("%s", &name);
    printf("The supplier of the material you want to delete is? \n");
    scanf("%s", &supplier);
    quantity = read_the_quantity_input_validation();
    expiration_day = read_the_date_day_input_validation();
    expiration_month = read_the_date_month_input_validation();
    expiration_year = read_the_date_year_input_validation();

    if (delete_element(name, supplier, quantity, expiration_day, expiration_month, expiration_year) == 1)
        printf("Material does not exist \n");
    else
    {
        printf("Material deleted \n");
        index_of_deleted_elements++;
        used_commands_that_can_be_undone[undo_count] = 2;
        undo_count++;
    }
}
void update_a_material_user_input()
{

    printf("\n Type the name of the material you want to update and the new supplier and expiration date of the material\n");
    int quantity, expiration_day, expiration_month, expiration_year;
    char name[30], supplier[30];
    printf("The name is? \n");
    scanf("%s", &name);
    printf("The new supplier is? \n");
    scanf("%s", &supplier);
    quantity = read_the_quantity_input_validation();
    expiration_day = read_the_date_day_input_validation();
    expiration_month = read_the_date_month_input_validation();
    expiration_year = read_the_date_year_input_validation();

    if (update_material(name, supplier, quantity, expiration_day, expiration_month, expiration_year) == 1)
        printf(" Material does not exist \n");
    else
    {
        printf("Material updated \n");
        used_commands_that_can_be_undone[undo_count] = 3;
    }
}

void see_all_expired_materials()
{
    char contained_string[40];
    printf("See all available materials past their expiration date, containing a given string \n");
    //_sleep(1000);
    printf("%s String:  \n");
    scanf("%[^\n]s", &contained_string);
    int current_date_day, current_date_month, current_date_year;
    printf(" Please enter the date with which you wish to compare the materials \n");
    current_date_day = read_the_date_day_input_validation();
    current_date_month = read_the_date_month_input_validation();
    current_date_year = read_the_date_year_input_validation();
    

    int vector_storing_the_indexes_of_the_filtered_product[100] = {-1};
    see_if_string_is_empty(vector_storing_the_indexes_of_the_filtered_product, current_date_day, current_date_month, current_date_year, contained_string);
    int j = 0;
    while (vector_storing_the_indexes_of_the_filtered_product[j] != -1)
    {
        int i = vector_storing_the_indexes_of_the_filtered_product[j];
        printf("%s %s %d %d %d %d \n", Product[i].name, Product[i].supplier, Product[i].quantity, Product[i].expiration_day, Product[i].expiration_month, Product[i].expiration_year);
        j++;
    }
    
}

void display_all_materials_in_short_supply_from_a_supplier()
{
    int quantity;
    char supplier[30];
    printf("The supplier is? \n");
    scanf("%s", &supplier);
    printf(" Provide a value to describe what short supply means to you \n");
    quantity = read_the_quantity_input_validation();

    int total_number_of_materials = read_from_file_the_struct();
    for (int i = 0; i < total_number_of_materials; i++)
    {
        if (strcmp(Product[i].supplier, supplier) == 0)
            if (Product[i].quantity < quantity)
                printf("%s %s %d %d %d %d \n", Product[i].name, Product[i].supplier, Product[i].quantity, Product[i].expiration_day, Product[i].expiration_month, Product[i].expiration_year);
    }
}


void ui()
{
    int option;
    printf(" Here are your options, \n");
    printf(" 1. Add  a material \n");
    printf(" 2. Delete a material \n");
    printf(" 3. Update a material \n");
    printf(" 4. See all available materials past their expiration date \n");
    printf(" 5. Display all materials from a given supplier, which are in short supply\n");
    printf(" 6. Undo\n");
    printf(" 7. Redo\n");
    printf(" 8. Exit\n");
    printf(" Your option is? ");
    scanf("%d", &option);

    while (option != 8)
    {
        if (option == 1)
            add_material_user_input();
        if (option == 2)
            delete_a_material_user_input();
        if (option == 3)
            update_a_material_user_input();
        if (option == 4)
            see_all_expired_materials();
        if (option == 5)
            display_all_materials_in_short_supply_from_a_supplier();
        if (option == 6)
            undo_function();
        if (option == 7)
            redo_function();
        else
            printf("Invalid option");
        printf("Your option is? ");
        scanf("%d", &option);
    }
}

int main()
{
    ui();
    return 0;
}