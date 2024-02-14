#include "functions.c"
#include <assert.h>

void test_function_if_material_already_exists()
{
    char new_name[] = "Sugar";
    char new_supplier[] = "ABC Supplier";
    int new_quantity = 10;
    int new_expiration_day = 1;
    int new_expiration_month = 1;
    int new_expiration_year = 2023;
    int result = if_material_already_exists(new_name, new_supplier, new_quantity, new_expiration_day, new_expiration_month, new_expiration_year);
    assert(result == -1);
}

void test_function_index_of_element_with_given_name()
{
    char name[] = "Banana";
    int result = index_of_element_with_given_name(name);
    assert(result == -1);
}

void test_add_element()
{
    char new_name[] = "Salt";
    char new_supplier[] = "GHI Supplier";
    int new_quantity = 30;
    int new_expiration_day = 3;
    int new_expiration_month = 3;
    int new_expiration_year = 2023;
    int result = add_element(new_name, new_supplier, new_quantity, new_expiration_day, new_expiration_month, new_expiration_year);
    assert(result == 0);
}

void test_delete_element()
{
    char name[] = "Banana";
    char supplier[] = "JKL Supplier";
    int quantity = 40;
    int expiration_day = 4;
    int expiration_month = 4;
    int expiration_year = 2023;
    int result = delete_element(name, supplier, quantity, expiration_day, expiration_month, expiration_year);
    assert(result == 1);
}

void test_update_material()
{

    char name[] = "Material1";
    char supplier[] = "NewSupplier";
    int quantity = 100;
    int expiration_day = 31;
    int expiration_month = 12;
    int expiration_year = 2023;
    add_element(name, supplier, quantity, expiration_day, expiration_month, expiration_year);
    int result = update_material(name, supplier, quantity, expiration_day, expiration_month, expiration_year);
    assert(result == 0);
}

void test_compare_expiration_dates()
{
    int vector_storing_the_indexes_of_the_filtered_product[10] = {0};
    int current_date_day = 1;
    int current_date_month = 8;
    int current_date_year = 3000;
    int result = compare_expiration_dates(vector_storing_the_indexes_of_the_filtered_product, current_date_day, current_date_month, current_date_year);
    assert(result == 0);
    assert(vector_storing_the_indexes_of_the_filtered_product[0] == 0);

    current_date_day = 1;
    current_date_month = 1;
    current_date_year = 2027;
    result = compare_expiration_dates(vector_storing_the_indexes_of_the_filtered_product, current_date_day, current_date_month, current_date_year);
    assert(result == 0);
}

int main()
{
    test_add_element();
    test_delete_element();
    test_function_if_material_already_exists();
    test_function_index_of_element_with_given_name();
    test_compare_expiration_dates();
    test_update_material();
}