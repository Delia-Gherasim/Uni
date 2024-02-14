#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

struct Materials
{
    char name[30], supplier[30];
    int quantity, expiration_day, expiration_month, expiration_year;
} Product[100];

int read_from_file_the_struct()
{
    FILE *textfile;
    textfile = fopen("bakery.txt", "r");
    if (textfile == NULL)
        return 1;

    int number_of_materials_in_file;
    fscanf(textfile, "%d", &number_of_materials_in_file);
    for (int i = 0; i < number_of_materials_in_file; i++)
        fscanf(textfile, "%s %s %d %d %d %d", &Product[i].name, &Product[i].supplier, &Product[i].quantity, &Product[i].expiration_day, &Product[i].expiration_month, &Product[i].expiration_year);

    fclose(textfile);
    return number_of_materials_in_file;
}

int rewrite_file(int number_of_materials)
{
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

void print_the_struct()
{
    int number_of_material_in_file=read_from_file_the_struct();
    for (int i = 0; i < number_of_material_in_file; i++)
    {
        printf("%s %s %d %d %d %d", Product[i].name, Product[i].supplier, Product[i].quantity, Product[i].expiration_day, Product[i].expiration_month, Product[i].expiration_year);
        printf("\n");
    }
}
