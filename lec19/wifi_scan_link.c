#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NETWORK 100
#define MAX_BUF 200
typedef struct wifiStruct{
    char SSID[MAX_BUF];
    int signalStrength;
    double maxRate;
    //Linked List
    struct wifiStruct *next; 
}Wifi;

void swap(Wifi *firstVal, Wifi *secondVal);
void quickSort(Wifi array[], int low, int high);
int partition(Wifi array[], int low, int high);

int readFile2Wifi(Wifi **ptr, int *numWifi,  char *filename);
void displayWifi(Wifi *ptr);
void displayWifi2(Wifi *ptr);

//Linked List
Wifi *createWifi(Wifi *Data);
void appendWifi(Wifi **headpptr, Wifi *Data);
Wifi *searchSSID(Wifi *headptr, char *SSID);
void removeWifi(Wifi **headpptr, char *SSID);
void removeAll(Wifi **headpptr);
void addWifi(Wifi **headpptr, Wifi *Data);

int main(){
    //Wifi w[MAX_NETWORK];
    //Wifi *ptr = w;
    Wifi *headptr = NULL;
    char filename[MAX_BUF] = "data.txt";
    int numWifi;

    Wifi temp = {"Temp", 0, 0, NULL};
    appendWifi(&headptr, &temp);
    
    readFile2Wifi(&headptr, &numWifi,  filename);
    displayWifi(headptr);
    displayWifi2(headptr);
    
    
    char buffer[MAX_BUF] = "Temp";
    //char buffer[MAX_BUF] = "COECSL3005";
    
    //printf("Enter SSID to search: ");
    //scanf("%s", buffer);
    
    Wifi *searchNode = searchSSID(headptr, buffer);

    printf("Searching %s  ...\n", buffer);
    if(searchNode== NULL) 
        printf("No match found. \n");
    else
        printf("SSID=%s, Signal Strength=%d%%, Max Rate=%lfMsps \n", searchNode->SSID, searchNode->signalStrength, searchNode->maxRate);

    printf("Removing %s  ...\n", buffer);
    removeWifi(&headptr, buffer);
    displayWifi(headptr);

   /* 
    removeAll(&headptr);
    printf("headptr=%p\n", headptr);
*/
    return 0;
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
        appendWifi(ptr, temp);
        //addWifi(ptr, temp);
        cnt++;
    }
    *numWifi = cnt;
    free(temp);
    fclose(infile);
    return 1;
}

void displayWifi2(Wifi *headptr){
//    Wifi *current = headptr;
    printf("===========================================================\n");
    printf("%-20s%-15s%-15s\n", "SSID", "Strength", "Max rate");
    printf("-----------------------------------------------------------\n");
    while(headptr!= NULL){
        printf("%-20s%-15d%-15.3lf\n", headptr->SSID, headptr->signalStrength, headptr->maxRate );
        headptr = headptr->next;
    }
    printf("===========================================================\n\n\n");
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

void swap(Wifi *firstVal, Wifi *secondVal)
{
    Wifi tempVal;

    tempVal = *firstVal;
    *firstVal = *secondVal;
    *secondVal = tempVal;
}
void quickSort(Wifi array[], int low, int high)
{
    //base case
    if(low >= high)
        return;

    //recursive case
    int pivot_index = partition(array, low, high);
    quickSort(array, low , pivot_index-1 );// first half
    quickSort(array, pivot_index+1 , high );//second half
}

// partition: returing the pivot index
int partition(Wifi array[], int low, int high)
{
    int pivot = array[high].signalStrength; //set the last element as pivot
    int i = low - 1, j;
    for(j=low;j<=high-1;j++)
    {
        if(array[j].signalStrength > pivot)
        {
            i++;
            swap(&array[j], &array[i]);
        }
    }
    swap(&array[i+1], &array[high]);


    return i+1;
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
void appendWifi(Wifi **headpptr, Wifi *Data)
{
    Wifi *current = *headpptr;
    Wifi *new = createWifi(Data);
    while(current != NULL){
        if(current->next == NULL){
            current->next = new;
            return;
        }
        current = current->next;
    }
    *headpptr = new;

}
void addWifi(Wifi **headpptr, Wifi *Data)
{
    Wifi *prev, *current = *headpptr;
    Wifi *new = createWifi(Data);
    while(current != NULL){
        if(new->signalStrength > current->signalStrength){
            new->next = current;
            if(current == *headpptr)
                *headpptr = new;
            else
                prev->next = new;
            return;
        }
        if(current->next == NULL){
            current->next = new;
            return;
        }
        prev = current;
        current = current->next;
    }
    *headpptr = new;
}
/*
Wifi *searchSSID(Wifi *headptr, char *SSID)
{
    Wifi *prevNode = headptr;
    Wifi *currNode = headptr->next;

    while( currNode != NULL && strcmp(currNode->SSID, SSID) != 0){
        prevNode = currNode;
        currNode = currNode->next;
    }

    return prevNode;

}

*/
Wifi *searchSSID(Wifi *headptr, char *SSID)
{
    Wifi *current = headptr;
    while( current != NULL && strcmp(current->SSID, SSID) != 0)
        current = current->next;

    return current;
}
void removeWifi(Wifi **headpptr, char *SSID)
{
    Wifi *prev, *current=*headpptr;

    while( current != NULL && strcmp(current->SSID, SSID) != 0){
        prev = current;
        current = current->next;
    }

    if(current == NULL){
        printf("No matching SSID, nothing to remove.\n");
        return;
    }

    if(current == *headpptr)
        *headpptr = current->next;
    else
        prev->next = current->next;

    free(current);
}
void removeAll(Wifi **headpptr){
    Wifi *next, *current = *headpptr;
    
    while( current != NULL){
        printf("removing %s\n", current->SSID);
        next = current->next;
        free(current);
        current = next;
    }
    *headpptr = NULL;
}




