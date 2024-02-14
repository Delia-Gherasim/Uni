

struct Materials
{
    char name[30], supplier[30];
    int quantity, expiration_day, expiration_month, expiration_year;
}  copy_of_products[100], save_deleted_elements[100], save_elements_that_have_been_added_and_than_comand_was_undone[100];

void add_element_dynamically(int number_of_materials, char name[], char supplier[], int  )
{

}


struct Materials backup[1000];
struct
{
    char name[30], old_supplier[30], new_supplier[30];
    int old_quantity, new_quantity, old_expiration_day, old_expiration_month, old_expiration_year, new_expiration_day, new_expiration_month, new_expiration_year;
    ;
} elements_that_have_been_updated[100];

