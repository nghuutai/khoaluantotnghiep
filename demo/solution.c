#include <stdio.h>
#include <stdlib.h> // For exit() function

int max(int a, int b, int c) 
{
  if(a >= b && a>= c){
    return a;
  } else if(b >=a && b>=c){
    return b;
  } else{
    return c;
  }
}

int main()
{
    int a,b,c,m;
    FILE *fptr;
    FILE *out;
 
    if ((fptr = fopen("./datatest/test.txt", "r")) == NULL)
    {
        printf("Error! opening file");
        exit(1);         
    }
 
    fscanf(fptr,"%d", &a);
    fscanf(fptr,"%d", &b);
    fscanf(fptr,"%d", &c);
    fclose(fptr);

    if ((out = fopen("out.txt", "w")) == NULL)
    {
        printf("Error! opening file");
        exit(1);         
    }
    m = max(a,b,c);
    fprintf(out,"%d",m);
    fclose(fptr);
    return 0;
}