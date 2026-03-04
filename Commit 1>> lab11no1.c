#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void addRecord(char *addName, int addAge);
void displayRecords(); 

int main() 
{
    char name[64]; 
    int age;
    
    printf("--- Add New Record ---\n");
    printf("Enter name: "); 
    scanf("%63s", name); 
    
    printf("Enter age: "); 
    scanf("%d", &age);
    
    addRecord(name, age);

    printf("\n--- All Records in File ---\n");
    displayRecords();

    return 0;
}

void addRecord(char *addName, int addAge) 
{
    FILE *fptr;

    fptr = fopen("C:\\Users\\salan\\Desktop\\first.txt", "a");

    if (fptr == NULL) 
    {
        printf("Error: Cannot open or create the file for writing.\n");
        return; 
    }

    fprintf(fptr, "%s \t %d\n", addName, addAge);

    fclose(fptr);
}

void displayRecords() 
{
    FILE *fptr;
    char name[64];
    int age;

    fptr = fopen("C:\\Users\\salan\\Desktop\\first.txt", "r");

    if (fptr == NULL) 
    {
        printf("No records found or file does not exist.\n");
        return; 
    }

    printf("Name\tAge\n");
    printf("-------------------\n");

    while (fscanf(fptr, "%63s %d", name, &age) == 2) 
    {
        printf("%s\t%d\n", name, age);
    }

    fclose(fptr);
}
