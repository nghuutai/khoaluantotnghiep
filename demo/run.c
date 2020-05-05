#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main ()
{
   FILE *inp,*out;
   int n,a,b,c;
   float diem;
   diem = 10;
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
      fscanf(inp,"%d",&a);
      fscanf(inp,"%d",&b);
      fscanf(inp,"%d",&c);
      fprintf(out,"%d\n",a);
      fprintf(out,"%d\n",b);
      fprintf(out,"%d\n",c);
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
      }else {
         diem = diem - 1.5;
         printf("wrong\n");
      }
   }
   fclose(inp);
   printf("Diem cua ban la: %.2f\n", diem);
   return(0);
} 