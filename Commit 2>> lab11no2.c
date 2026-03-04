#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define NO_SCORE 10

typedef struct 
{
    char name[16];
    char surname[20];
    int score[NO_SCORE];
    float total;
} Student;

void findTotalScore(Student *std, int s);
float findAverage(Student std,int s);
void findLessThanTen(Student std,int s);
void displayRecords(); 

int main()
{
    Student std[3]; 
    int numScores = 3;  
    float avg[3];
 
    for(int i = 0; i < 3; i++)
    {
        printf("--- Add New Record (Student %d) ---\n", i+1);
        
       
        printf("Enter name: ");
        fgets(std[i].name, sizeof(std[i].name), stdin); 
        std[i].name[strcspn(std[i].name, "\n")] = 0; 
        
    
        printf("Enter surname: ");
        fgets(std[i].surname, sizeof(std[i].surname), stdin); 
        std[i].surname[strcspn(std[i].surname, "\n")] = 0;
        
    
        printf("Enter %d scores:\n", numScores);
        for(int j = 0; j < numScores; j++)
        {
            printf("  Score %d: ", j+1);
            scanf("%d", &std[i].score[j]);
        }

        
        while (getchar() != '\n');

        
        findTotalScore(&std[i], numScores);
        findLessThanTen(std[i], numScores);
        avg[i] = findAverage(std[i], numScores);
    }
    for(int i=0;i<3;i++)
    {
    	printf("%s : sd = %.2f \n",std[i].name,avg[i]);
	}
	printf("\n--- All Records in File ---\n");
    displayRecords();

    return 0;
}


void findTotalScore(Student *std, int s)
{
    std->total = 0; 
    for(int i = 0; i < s; i++)
    {
        std->total += std->score[i];
    }
    printf("%s %s %.1f\n", std->name, std->surname, std->total); 
    
}

void findLessThanTen(Student std, int s)
{
	int get=1;
    for(int i = 0; i < s; i++)
    {
    	 if(std.score[i] > 10.0)
        {
            get++;
        }
    	
        if(std.score[i] < 10.0)
        {
            printf("%d %s %s\n", get,std.name, std.surname); 
            break; 
        }
    }
}

float findAverage(Student std,int s)
{
	int sum;
	float sd;
	for(int i=0;i<s;i++)
	{
		sum += std.score[i];
		
	}
	sd = sqrt(sum/2);
	return sd;
}
void displayRecords()
{
    FILE *fptr;
    Student std[3]; 

    fptr = fopen("C:\\Users\\salan\\Desktop\\first.txt", "r");

    if (fptr == NULL) 
    {
        printf("No records found or file does not exist.\n");
        return; 
    }
    
    for(int i = 0; i < 3; i++)
    {
        fscanf(fptr, "%s %s %d %f",
            std[i].name,
            std[i].surname,
            &std[i].score,
            &std[i].total);
    }

    fclose(fptr);

    for(int i = 0; i < 3; i++)
    {
        printf("%s %s Score:%d Total:%.2f\n",
            std[i].name,
            std[i].surname,
            std[i].score,
            std[i].total);
    }
}
