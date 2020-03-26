#include <stdio.h>

int main(){
    char c;
    FILE *fp1, *fp2;

    if((fp1=fopen("original.txt", "r")) == NULL){
        printf("Unable to open a file.\n");
        return -1;
    }
    if((fp2=fopen("modified.txt", "w")) == NULL){
        printf("Unable to open a file.\n");
        return -1;
    }

    c = fgetc(fp1);
    while(c!= EOF){
        printf("%c", c);
        c = fgetc(fp1);
        if(c>=48 && c<=57)
            fputc(c,fp2);
    }
    fclose(fp1);
    fclose(fp2);

    return 0;
}
