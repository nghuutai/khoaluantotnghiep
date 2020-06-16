#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h> 

void printRandoms(int lower, int upper, int count, FILE *out) 
{ 
    int i;
    fprintf(out,"%d\n",count);
    for (i = 0; i < count; i++) { 
        int num = (rand() % 
           (upper - lower + 1)) + lower; 
        fprintf(out,"%d ",num); 
    }
    fprintf(out,"\n"); 
} 

int randomNumber(int lower, int upper)
{
    int num = (rand() % (upper - lower + 1)) + lower; 
    return num;
}

void setup(int lower, int upper, int n, FILE *out)
{
    int count;
    fprintf(out,"%d\n",n);
    srand(time(0)); 
    for(int i = 0; i < n; i++)
    {
        count = randomNumber(0, 10);
        printRandoms(lower, upper, count, out);
    } 
    fclose(out);
}

int main ()
{
    FILE *inp, *out, *outTestcase;
    int n, arr[100] , m, lower = 1, upper= 100, wrong, success;
    float diem;
    success = 0;
    wrong = 0;

    if((outTestcase = fopen("./datatest/testcase.txt", "w")) == NULL)
    {
        printf("Error! opening file");
        exit(1);         
    }
    setup(lower,upper, 10,outTestcase);
    if ((inp = fopen("./datatest/testcase.txt", "r")) == NULL)
    {
        printf("Error! opening file");
        exit(1);         
    }
    fscanf(inp,"%d",&n);

    for(int i = 0; i < n; i++) {
        if((out = fopen("./datatest/test.txt", "w")) == NULL)
        {
            printf("Error! opening file");
            exit(1);         
        }
        printf("Test lan thu %d\n", i + 1);

        fscanf(inp,"%d",&m);
       
        for(int i = 0; i < m; i++) {
            fscanf(inp,"%d", &arr[i]);
        }

        fprintf(out,"%d\n",m);
        for(int i = 0; i < m; i++) {
            fprintf(out,"%d ",arr[i]);
        }
        fclose(out);

        char commandSolution[50],commandRunSolution[50],commandSV[50],commandRunSV[50],commandCompare[50];

        strcpy(commandSolution, "gcc -Wall -o solution solution.c" );
        strcpy(commandSV, "gcc -Wall -o sv sv.c" );
        strcpy(commandRunSolution, "./solution");
        strcpy(commandRunSV, "./sv");
        strcpy(commandCompare, "diff ./out.txt ./outsv.txt");
        system(commandSolution);
        system(commandSV);
        system(commandRunSolution);
        system(commandRunSV);

        if(system(commandCompare) == 0) {
            printf("succcessful\n");
            success = success + 1;
        }else {
            wrong = wrong + 1;
            printf("wrong\n");
            printf("Bo test case: ");
            for(int i = 0; i < m; i++) {
                printf("%3d", arr[i]);
            }
            printf("\n");
        }
    }
    fclose(inp);
    diem = (10.0 / n) * success;
    printf("So bo testcase sai: %d\n", wrong);
    printf("Diem cua ban la: %.2f\n", diem);
    return(0);
}