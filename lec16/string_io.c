#include <stdio.h>
#define SIZE 100
int main(){
    FILE *fp;
    char buffer[SIZE];

    if((fp= fopen("append.txt", "a"))== NULL){
        printf("cannot open the file\n");
        return -1;
    }
    printf("Enter a string to append: ");
    fgets(buffer, SIZE, stdin);
    fputs(buffer, fp);
    fclose(fp);
}
