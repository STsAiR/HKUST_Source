#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
    // This variable stores the file pointer
    FILE *fp;

    // This variable stores the name read from the file
    char name[20];

    // Open the text file 'name.txt' for reading
    fp = fopen("name.txt", "r");

    // Read a string into the variable name
    fscanf(fp, "%s", name);

    // Close the file after reading
    fclose(fp);

    // Print the content out
    printf("The name is %s.\n", name);
}
