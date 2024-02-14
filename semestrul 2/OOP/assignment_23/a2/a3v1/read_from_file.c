#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "repository.c"


int read_from_file_the_struct()
{
    /*functions reads the number of elements saved in the file "bakery.txt" and saves the materials contained there in the array struct Products
    returns the number of materials in the file*/
    FILE *textfile;
    textfile = fopen("bakery.txt", "r");
    if (textfile == NULL)
        return 1;

    int number_of_materials_in_file, quantity, expiration_day, expiration_month, expiration_year;
    char name[30], supplier[30];
    fscanf(textfile, "%d", &number_of_materials_in_file);
    struct Materials *Product=(struct Materials*)malloc(number_of_materials_in_file*sizeof(struct Materials));
    for (int i = 0; i < number_of_materials_in_file; i++)
        {
            fscanf(textfile, "%s %s %d %d %d %d", &name, &supplier, &quantity, &expiration_day, &expiration_month, &expiration_year);
            strcpy(Product[i].name, name);
            strcpy(Product[i].supplier, supplier);
            Product[i].quantity=quantity;
            Product[i].expiration_day=expiration_day;
            Product[i].expiration_month=expiration_month;
            Product[i].expiration_year=expiration_year;
        }

    fclose(textfile);
    return number_of_materials_in_file;
}

int rewrite_file(int number_of_materials, struct Materials Product)
{
    /*functions rewrites the file "bakery.txt", writting on the first row the new number of products contained in the array and on the next lines the product names, suppliers, quantities and expiration dates
    */
    FILE *textfile;
    textfile = fopen("bakery.txt", "w");
    if (textfile == NULL)
        return 1;

    fprintf(textfile, "%d \n", number_of_materials);
    for (int i=0; i<number_of_materials; i++)
        fprintf(textfile, "%s %s %d %d %d %d \n", Product[i].name, Product[i].supplier, Product[i].quantity, Product[i].expiration_day, Product[i].expiration_month, Product[i].expiration_year);
    fclose(textfile);
    return 0;
}

