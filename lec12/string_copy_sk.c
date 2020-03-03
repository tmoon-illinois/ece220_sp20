#include <stdio.h>
#include <string.h>

#define BUF_SIZE 200
void string_copy(char des[], char const src[]);
void string_copy2(char *des, char *src);

int main(){

    char buf[200];
    char buf2[200]="ABC";

    //buf = "abc";
    //string_copy(buf,"ABC");
    string_copy(buf, buf2);
    printf("%s\n", buf);
    printf("%s\n", buf2);
}
void string_copy(char des[], char const src[])
{
    int i=0;
    //src[i] = 'T';
    while(*(src+i) !='\0' ){
        *(des+i) = *(src+i);
        i++;
    }
    *(des+i) = '\0';

}

void string_copy2(char *des, char *src)
{
    int i=0;
    while(src[i] !='\0' ){
        des[i] = src[i];
        i++;
    }
    des[i] = '\0';

}
