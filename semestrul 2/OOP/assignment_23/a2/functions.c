#include <stdio.h>
#include <string.h>
#include "read_from_file.c"

struct
{
    char name[30], supplier[30];
    int quantity, expiration_day, expiration_month, expiration_year;
} save_deleted_elements[100], save_elements_that_have_been_added_and_than_comand_was_undone[100];

struct
{
    char name[30], old_supplier[30], new_supplier[30];
    int old_quantity, new_quantity, old_expiration_day, old_expiration_month, old_expiration_year, new_expiration_day, new_expiration_month, new_expiration_year;
    ;
} elements_that_have_been_updated[100];

struct Materials filtered_products[100];

int index_of_deleted_elements = 0, how_many_materials_were_updated_count = 0;

int if_material_already_exists(char new_name[], char new_supplier[], int new_quantity, int new_expiration_day, int new_expiration_month, int new_expiration_year)
{
    int number_of_materials = read_from_file_the_struct();
    for (int i = 0; i < number_of_materials; i++)
    {
        if (strcmp(Product[i].name, new_name) == 0)
            if (strcmp(Product[i].supplier, new_supplier) == 0)
                if ((Product[i].expiration_day == new_expiration_day) && (Product[i].expiration_month = new_expiration_month) && (Product[i].expiration_year == new_expiration_year))
                    return i;
    }
    return -1;
}

int index_of_element_with_given_name(char name[])
{
    int number_of_materials = read_from_file_the_struct();
    for (int i = 0; i < number_of_materials; i++)
        if (strcmp(Product[i].name, name) == 0)
            return i;
    return -1;
}

int add_element(char new_name[], char new_supplier[], int new_quantity, int new_expiration_day, int new_expiration_month, int new_expiration_year)
{
    int number_of_materials = read_from_file_the_struct();
    int search_function_result = if_material_already_exists(new_name, new_supplier, new_quantity, new_expiration_day, new_expiration_month, new_expiration_year);
    if (search_function_result != -1)
    {
        Product[search_function_result].quantity += new_quantity;
        rewrite_file(number_of_materials);
        return 1;
    }
    else
    {
        strcpy(Product[number_of_materials].name, new_name);
        strcpy(Product[number_of_materials].supplier, new_supplier);
        Product[number_of_materials].quantity = new_quantity;
        Product[number_of_materials].expiration_day = new_expiration_day;
        Product[number_of_materials].expiration_month = new_expiration_month;
        Product[number_of_materials].expiration_year = new_expiration_year;
        rewrite_file(number_of_materials + 1);
    }
    return 0;
}

int delete_element(char name[], char supplier[], int quantity, int expiration_day, int expiration_month, int expiration_year)
{
    int number_of_materials = read_from_file_the_struct();
    int search_function_result = if_material_already_exists(name, supplier, quantity, expiration_day, expiration_month, expiration_year);
    if (search_function_result == -1)
        return 1;
    else
    {
        save_deleted_elements[index_of_deleted_elements].quantity = Product[search_function_result].quantity;
        save_deleted_elements[index_of_deleted_elements].expiration_day = Product[search_function_result].expiration_day;
        save_deleted_elements[index_of_deleted_elements].expiration_month = Product[search_function_result].expiration_month;
        save_deleted_elements[index_of_deleted_elements].expiration_year = Product[search_function_result].expiration_year;
        strcpy(save_deleted_elements[index_of_deleted_elements].name, Product[search_function_result].name);
        strcpy(save_deleted_elements[index_of_deleted_elements].supplier, Product[search_function_result].supplier);
        index_of_deleted_elements++;
        for (int i = search_function_result; i < number_of_materials; i++)
        {
            strcpy(Product[i].name, Product[i + 1].name);
            strcpy(Product[i].supplier, Product[i + 1].supplier);
            Product[i].quantity = Product[i + 1].quantity;
            Product[i].expiration_day = Product[i + 1].expiration_day;
            Product[i].expiration_month = Product[i + 1].expiration_month;
            Product[i].expiration_year = Product[i + 1].expiration_year;
        }
        rewrite_file(number_of_materials - 1);
        return 0;
    }
}

int update_material(char name[], char supplier[], int quantity, int expiration_day, int expiration_month, int expiration_year)
{
    int save_index = index_of_element_with_given_name(name);
    if (save_index == -1)
        return 1;
    else
    {
        strcpy(elements_that_have_been_updated[how_many_materials_were_updated_count].name, name);
        strcpy(elements_that_have_been_updated[how_many_materials_were_updated_count].new_supplier, Product[save_index].supplier);
        strcpy(elements_that_have_been_updated[how_many_materials_were_updated_count].old_supplier, Product[save_index].supplier);
        elements_that_have_been_updated[how_many_materials_were_updated_count].new_quantity = Product[save_index].quantity;
        elements_that_have_been_updated[how_many_materials_were_updated_count].old_quantity = Product[save_index].quantity;
        elements_that_have_been_updated[how_many_materials_were_updated_count].new_expiration_day = Product[save_index].expiration_day;
        elements_that_have_been_updated[how_many_materials_were_updated_count].old_expiration_day = Product[save_index].expiration_day;
        elements_that_have_been_updated[how_many_materials_were_updated_count].new_expiration_month = Product[save_index].expiration_month;
        elements_that_have_been_updated[how_many_materials_were_updated_count].old_expiration_month = Product[save_index].expiration_month;
        elements_that_have_been_updated[how_many_materials_were_updated_count].new_expiration_year = Product[save_index].expiration_year;
        elements_that_have_been_updated[how_many_materials_were_updated_count].old_expiration_year = Product[save_index].expiration_year;
        if (strcmp(Product[save_index].supplier, supplier) != 0)
        {
            strcpy(elements_that_have_been_updated[how_many_materials_were_updated_count].new_supplier, supplier);
            strcpy(Product[save_index].supplier, supplier);
        }
        if (Product[save_index].quantity != quantity)
        {
            elements_that_have_been_updated[how_many_materials_were_updated_count].new_quantity = quantity;
            Product[save_index].quantity = quantity;
        }
        if (Product[save_index].expiration_day != expiration_day)
        {
            elements_that_have_been_updated[how_many_materials_were_updated_count].new_expiration_day = expiration_day;
            Product[save_index].expiration_day = expiration_day;
        }
        if (Product[save_index].expiration_month != expiration_month)
        {
            elements_that_have_been_updated[how_many_materials_were_updated_count].new_expiration_month = expiration_month;
            Product[save_index].expiration_month = expiration_month;
        }
        if (Product[save_index].expiration_year != expiration_year)
        {
            elements_that_have_been_updated[how_many_materials_were_updated_count].new_expiration_year = expiration_year;
            Product[save_index].expiration_year = expiration_year;
        }
        how_many_materials_were_updated_count++;
        return 0;
    }
}



int compare_expiration_dates(int vector_storing_the_indexes_of_the_filtered_product[], int current_date_day, int current_date_month, int current_date_year)
{
    int number_of_materials = read_from_file_the_struct(), index_for_saving_elemnts_in_filtered_materials_struct = 0;
    for (int i = 0; i < number_of_materials; i++)
    {
        if (Product[i].expiration_year < current_date_year)
        {
            vector_storing_the_indexes_of_the_filtered_product[index_for_saving_elemnts_in_filtered_materials_struct] = i;
            filtered_products[index_for_saving_elemnts_in_filtered_materials_struct] = Product[i];
            index_for_saving_elemnts_in_filtered_materials_struct++;
        }
        else if (Product[i].expiration_year == current_date_year)
            if (Product[i].expiration_month > current_date_month)
            {
                vector_storing_the_indexes_of_the_filtered_product[index_for_saving_elemnts_in_filtered_materials_struct] = i;
                filtered_products[index_for_saving_elemnts_in_filtered_materials_struct] = Product[i];
                index_for_saving_elemnts_in_filtered_materials_struct++;
            }
            else if (Product[i].expiration_day >= current_date_day)
            {
                vector_storing_the_indexes_of_the_filtered_product[index_for_saving_elemnts_in_filtered_materials_struct] = i;
                filtered_products[index_for_saving_elemnts_in_filtered_materials_struct] = Product[i];
                index_for_saving_elemnts_in_filtered_materials_struct++;
            }
    }
    return index_for_saving_elemnts_in_filtered_materials_struct;
}

int find_names_containing_the_string_and_compare_expiration_dates(int vector_storing_the_indexes_of_the_filtered_product[], int current_date_day, int current_date_month, int current_date_year, char contained_string[])
{
    int number_of_materials = read_from_file_the_struct(), index_for_saving_elemnts_in_filtered_materials_struct = 0;
    for (int i = 0; i < number_of_materials; i++)
    {
        if (strstr(Product[i].name, contained_string) != NULL)
        {
            if (Product[i].expiration_year < current_date_year)
            {
                vector_storing_the_indexes_of_the_filtered_product[index_for_saving_elemnts_in_filtered_materials_struct] = i;
                filtered_products[index_for_saving_elemnts_in_filtered_materials_struct] = Product[i];
                index_for_saving_elemnts_in_filtered_materials_struct++;
            }
            else if (Product[i].expiration_year == current_date_year)
                if (Product[i].expiration_month > current_date_month)
                {
                    vector_storing_the_indexes_of_the_filtered_product[index_for_saving_elemnts_in_filtered_materials_struct] = i;
                    filtered_products[index_for_saving_elemnts_in_filtered_materials_struct] = Product[i];
                    index_for_saving_elemnts_in_filtered_materials_struct++;
                }
                else if (Product[i].expiration_day >= current_date_day)
                {
                    vector_storing_the_indexes_of_the_filtered_product[index_for_saving_elemnts_in_filtered_materials_struct] = i;
                    filtered_products[index_for_saving_elemnts_in_filtered_materials_struct] = Product[i];
                    index_for_saving_elemnts_in_filtered_materials_struct++;
                }
        }
    }
    return index_for_saving_elemnts_in_filtered_materials_struct;
}

int see_if_string_is_empty(int vector_storing_the_indexes_of_the_filtered_product[], int current_date_day, int current_date_month, int current_date_year, char contained_string[])
{

    if ((strlen(contained_string) == 0) || ((strlen(contained_string) == 1) && (&contained_string[0] == "\n")))
        return compare_expiration_dates(vector_storing_the_indexes_of_the_filtered_product, current_date_day, current_date_month, current_date_year);
    else
        return find_names_containing_the_string_and_compare_expiration_dates(vector_storing_the_indexes_of_the_filtered_product, current_date_day, current_date_month, current_date_year, contained_string);
}

int undo_count=0, redo_count=0, used_commands_that_can_be_undone[1000], used_commands_that_can_be_redone[1000];
int index_of_undone_added_elements=0, index_of_deleted_than_added_elements=0;

int undo_function()
{
    int total_number_of_materials=read_from_file_the_struct();

    if (undo_count==0)
        {
            printf("No action to be undone");
            return 1;
        }
    if (used_commands_that_can_be_undone[undo_count-1]==1)
        {
            save_elements_that_have_been_added_and_than_comand_was_undone[index_of_undone_added_elements].quantity=Product[total_number_of_materials -1 ].quantity;
            save_elements_that_have_been_added_and_than_comand_was_undone[index_of_undone_added_elements].expiration_day=Product[total_number_of_materials -1 ].expiration_day;
            save_elements_that_have_been_added_and_than_comand_was_undone[index_of_undone_added_elements].expiration_month=Product[total_number_of_materials -1 ].expiration_month;
            save_elements_that_have_been_added_and_than_comand_was_undone[index_of_undone_added_elements].expiration_year=Product[total_number_of_materials -1 ].expiration_year;
            strcpy(save_elements_that_have_been_added_and_than_comand_was_undone[index_of_undone_added_elements].name,Product[total_number_of_materials -1 ].name);
            strcpy(save_elements_that_have_been_added_and_than_comand_was_undone[index_of_undone_added_elements].supplier,Product[total_number_of_materials -1 ].supplier);
            delete_element(Product[total_number_of_materials-1].name, Product[total_number_of_materials-1].supplier, Product[total_number_of_materials-1].quantity, Product[total_number_of_materials-1].expiration_day, Product[total_number_of_materials-1].expiration_month, Product[total_number_of_materials-1].expiration_year);
            undo_count--;
            used_commands_that_can_be_redone[redo_count]=2;
            redo_count++;
            index_of_undone_added_elements++;
            
        }
    else
        if (used_commands_that_can_be_undone[undo_count-1]==2)
            {
                add_element(save_deleted_elements[index_of_deleted_elements-1].name, save_deleted_elements[index_of_deleted_elements-1].supplier, save_deleted_elements[index_of_deleted_elements-1].quantity, save_deleted_elements[index_of_deleted_elements-1].expiration_day, save_deleted_elements[index_of_deleted_elements-1].expiration_month, save_deleted_elements[index_of_deleted_elements-1].expiration_year);
                undo_count--;
                index_of_deleted_than_added_elements=index_of_deleted_elements;
                used_commands_that_can_be_redone[redo_count]=1;
                redo_count++;
            }
        else
            if (used_commands_that_can_be_undone[undo_count-1]==3)
            {
                delete_element(elements_that_have_been_updated[how_many_materials_were_updated_count-1].name, elements_that_have_been_updated[how_many_materials_were_updated_count-1].new_supplier, elements_that_have_been_updated[how_many_materials_were_updated_count-1].new_quantity, elements_that_have_been_updated[how_many_materials_were_updated_count-1].new_expiration_day, elements_that_have_been_updated[how_many_materials_were_updated_count-1].new_expiration_month, elements_that_have_been_updated[how_many_materials_were_updated_count-1].new_expiration_year);
                add_element(elements_that_have_been_updated[how_many_materials_were_updated_count-1].name,elements_that_have_been_updated[how_many_materials_were_updated_count-1].old_supplier, elements_that_have_been_updated[how_many_materials_were_updated_count-1].old_quantity, elements_that_have_been_updated[how_many_materials_were_updated_count-1].old_expiration_day, elements_that_have_been_updated[how_many_materials_were_updated_count-1].old_expiration_month, elements_that_have_been_updated[how_many_materials_were_updated_count-1].old_expiration_year);
                undo_count--;
                used_commands_that_can_be_redone[redo_count]=3;
                redo_count++;
            }
    return 0;
}

int redo_function()
{
    if (redo_count==0)
    {
        printf("No action to redo");
        return 1;
    }
    if (used_commands_that_can_be_redone[redo_count-1]==1)
    {
        delete_element(save_deleted_elements[index_of_deleted_than_added_elements].name, save_deleted_elements[index_of_deleted_than_added_elements].supplier, save_deleted_elements[index_of_deleted_than_added_elements].quantity, save_deleted_elements[index_of_deleted_than_added_elements].expiration_day, save_deleted_elements[index_of_deleted_than_added_elements].expiration_month, save_deleted_elements[index_of_deleted_than_added_elements].expiration_year);
        redo_count--;
        index_of_deleted_than_added_elements--;
    }
    else
        if (used_commands_that_can_be_redone[redo_count-1]==2)
        {
            add_element(save_elements_that_have_been_added_and_than_comand_was_undone[index_of_undone_added_elements-1].name, save_elements_that_have_been_added_and_than_comand_was_undone[index_of_undone_added_elements-1].supplier, save_elements_that_have_been_added_and_than_comand_was_undone[index_of_undone_added_elements-1].quantity, save_elements_that_have_been_added_and_than_comand_was_undone[index_of_undone_added_elements-1].expiration_day, save_elements_that_have_been_added_and_than_comand_was_undone[index_of_undone_added_elements-1].expiration_month, save_elements_that_have_been_added_and_than_comand_was_undone[index_of_undone_added_elements-1].expiration_year);
            redo_count--;
            index_of_undone_added_elements--;
        }
    else
        if (used_commands_that_can_be_redone[redo_count-1]==3)
        {
            delete_element(elements_that_have_been_updated[how_many_materials_were_updated_count-1].name, elements_that_have_been_updated[how_many_materials_were_updated_count-1].old_supplier, elements_that_have_been_updated[how_many_materials_were_updated_count-1].old_quantity, elements_that_have_been_updated[how_many_materials_were_updated_count-1].old_expiration_day, elements_that_have_been_updated[how_many_materials_were_updated_count-1].old_expiration_month, elements_that_have_been_updated[how_many_materials_were_updated_count-1].old_expiration_year);
            add_element(elements_that_have_been_updated[how_many_materials_were_updated_count-1].name, elements_that_have_been_updated[how_many_materials_were_updated_count-1].new_supplier, elements_that_have_been_updated[how_many_materials_were_updated_count-1].new_quantity, elements_that_have_been_updated[how_many_materials_were_updated_count-1].new_expiration_day, elements_that_have_been_updated[how_many_materials_were_updated_count-1].new_expiration_month, elements_that_have_been_updated[how_many_materials_were_updated_count-1].new_expiration_year);
            redo_count--;
        }

    return 0;
}