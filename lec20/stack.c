#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_BUF 200
typedef struct wifiStruct{
    char SSID[MAX_BUF];
    int signalStrength;
    double maxRate;
    //Linked List
    struct wifiStruct *next;
}Wifi;

void displayWifi(Wifi *headptr);
int readFile2Wifi(Wifi **ptr, int *numWifi,  char *filename);
Wifi *searchSSID(Wifi *headptr, char *SSID);
Wifi *createWifi(Wifi *Data);
void pop(Wifi **headptr);
void push(Wifi **headptr, Wifi *Data);
int main()
{
    Wifi *headptr = NULL;
    char filename[MAX_BUF] = "data.txt";
    int numWifi;

    Wifi temp = {"Temp", 0, 0, NULL};
    push(&headptr, &temp);

    readFile2Wifi(&headptr, &numWifi,  filename);
    displayWifi(headptr);

    pop(&headptr);
    pop(&headptr);
    pop(&headptr);
    pop(&headptr);
    pop(&headptr);
    pop(&headptr);
    pop(&headptr);
    pop(&headptr);
    
    
    pop(&headptr);

    displayWifi(headptr);

    return 0;
}
void displayWifi(Wifi *headptr){
    Wifi *current = headptr;
    printf("===========================================================\n");
    printf("%-20s%-15s%-15s\n", "SSID", "Strength", "Max rate");
    printf("-----------------------------------------------------------\n");
    while(current != NULL){
        printf("%-20s%-15d%-15.3lf\n", current->SSID, current->signalStrength, current->maxRate );
        current = current->next;
    }
    printf("===========================================================\n\n\n");
}
int readFile2Wifi(Wifi **ptr, int *numWifi,  char *filename){
    FILE *infile;
    if((infile = fopen(filename, "r"))==NULL){
        printf("Cannot open the file\n");
        return 0;
    }
    Wifi *temp = (Wifi*) malloc(sizeof(Wifi));;
    char buffer[MAX_BUF];
    int cnt = 0;
    fgets(buffer, MAX_BUF, infile);// skip the header

    while( fgets(buffer, MAX_BUF, infile) ){
        //Linked List
        sscanf(buffer, "%s %d%*c %lf", temp->SSID, &(temp->signalStrength), &(temp->maxRate));
        push(ptr, temp);
        cnt++;
    }
    *numWifi = cnt;
    free(temp);
    fclose(infile);
    return 1;
}
Wifi *searchSSID(Wifi *headptr, char *SSID)
{
    Wifi *current = headptr;
    while( current != NULL && strcmp(current->SSID, SSID) != 0)
        current = current->next;

    return current;
}
Wifi *createWifi(Wifi *Data)
{
    Wifi *new = (Wifi*) malloc(sizeof(Wifi));

    strcpy(new->SSID, Data->SSID);
    new->signalStrength = Data->signalStrength;
    new->maxRate= Data->maxRate;
    new->next = NULL;

    return new;
}

void pop(Wifi **headptr)
{
    Wifi *current = *headptr;
    if(current == NULL){
        printf("Stack underflow.\n");
        return;
    }
    *headptr = current->next;
    free(current);
}
void push(Wifi **headptr, Wifi *Data)
{
    Wifi *new = createWifi(Data);
    new->next = *headptr;
    *headptr = new;
}
