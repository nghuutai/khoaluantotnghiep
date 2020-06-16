#include <stdio.h>
#include <stdlib.h> // For exit() function

void sapXep(int a[100], int n){
    int tg;
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(a[i] > a[j]){
                tg = a[i];
                a[i] = a[j];
                a[j] = tg;        
            }
        }
    }
}

// void sapXep(int a[100], int n){
//     int tg;
//     for(int i = 0; i < n - 1; i++){
//         for(int j = i + 1; j < n; j++){
//             if(a[i] > a[j] + 6){
//                 tg = a[i];
//                 a[i] = a[j];
//                 a[j] = tg;        
//             }
//         }
//     }
// }

int main() {
    int arr[100], n;
    FILE *inp, *out;

    if ((inp = fopen("./datatest/test.txt", "r")) == NULL)
    {
        printf("Error! opening file");
        exit(1);         
    }
    fscanf(inp,"%d", &n);

    for(int i = 0; i < n; i++) {
        fscanf(inp,"%d", &arr[i]);
    }
    fclose(inp);

    sapXep(arr,n);

    if ((out = fopen("outsv.txt", "w")) == NULL)
    {
        printf("Error! opening file");
        exit(1);         
    }

    for(int j = 0; j < n; j++) {
        fprintf(out,"%d ",arr[j]);
    }
    fclose(out);
}