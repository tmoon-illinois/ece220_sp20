#include <stdio.h>
#define MAX_NETWORK 100
#define MAX_BUF 200
typedef struct wifiStruct{
    char SSID[MAX_BUF];
    int signalStrength;
    double maxRate;
}Wifi;
int readFile2Wifi(Wifi *ptr, int *numWifi,  char *filename);
void displayWifi(Wifi *ptr, int numWifi);


void swap(Wifi *firstVal, Wifi *secondVal);
void quickSort(Wifi array[], int low, int high);
int partition(Wifi array[], int low, int high);


int main(){
    Wifi w[MAX_NETWORK];
    Wifi *ptr = w;
    char filename[MAX_BUF] = "data.txt";
//    char filename[MAX_BUF] = "data.csv";
    int numWifi;
    
    readFile2Wifi(ptr, &numWifi,  filename);
    displayWifi(ptr, numWifi);

    quickSort(w, 0, numWifi-1);
    displayWifi(ptr, numWifi);

    return 0;
}

int readFile2Wifi(Wifi *ptr, int *numWifi,  char *filename){
    FILE *infile;
    if((infile = fopen(filename, "r"))==NULL){
        printf("Cannot open the file\n");
        return 0;
    }
    char buffer[MAX_BUF];
    int cnt = 0;
    fgets(buffer, MAX_BUF, infile);// skip the header

    while( fgets(buffer, MAX_BUF, infile) ){
        sscanf(buffer, "%s %d%*c %lf", ptr->SSID, &(ptr->signalStrength), &(ptr->maxRate) );
        ptr++;
        cnt++;
    }
    *numWifi = cnt;
    fclose(infile);
    return 1;
}

void displayWifi(Wifi *ptr, int numWifi){
    int i;
    printf("===========================================================\n");
    printf("%-20s%-15s%-15s\n", "SSID", "Strength", "Max rate");
    printf("-----------------------------------------------------------\n");
    for(i=0;i<numWifi;i++){
        printf("%-20s%-15d%-15.3lf\n", ptr->SSID, ptr->signalStrength, ptr->maxRate );
        ptr++;
    }
    printf("===========================================================\n\n\n");
}

void swap(Wifi *firstVal, Wifi *secondVal){
    Wifi tempVal;

    tempVal = *firstVal;
    *firstVal = *secondVal;
    *secondVal = tempVal;
}
void quickSort(Wifi array[], int low, int high){
    //base case
    if(low >= high)
        return;
    //recursive case
    int pivot_index = partition(array, low, high);
    quickSort(array, low , pivot_index-1 );// first half
    quickSort(array, pivot_index+1 , high );//second half
}
// partition: returing the pivot index
int partition(Wifi array[], int low, int high){
    //int pivot = array[high].signalStrength; //set the last element as pivot
    double pivot = array[high].maxRate; //set the last element as pivot
    int i = low - 1, j;
    for(j=low;j<=high-1;j++)
    {
        if(array[j].maxRate< pivot)
        {
            i++;
            swap(&array[j], &array[i]);
        }
    }
    swap(&array[i+1], &array[high]);
    return i+1;
}

