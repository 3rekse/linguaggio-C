#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define ARRAY_SIZE 100
#define STRING_LENGTH 10

char* arrStr[ARRAY_SIZE];

void swap(int *xp, int *yp , int printFlag) {
    if (printFlag) {
        printf("Swapping %d and %d\n", *xp, *yp);
    }
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void swapStrings(char* arr[], int index1, int index2) {
    char* temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}

void selectionSort(int arr[], int n) {
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++) {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        // Swap the found minimum element with the first element
        (min_idx==i?printf("\tok %d\n",arr[min_idx]):swap(&arr[i], &arr[min_idx],0));
        if (min_idx!=i )
            swapStrings(arrStr, i , min_idx);
    }
}

void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {     
        // Last i elements are already in place  
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Swap arr[j] and arr[j+1]
                swap(&arr[j], &arr[j+1],0);
            }
        }
    }
}

void strBubbleSort(char* arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {     
        // Last i elements are already in place  
        for (j = 0; j < n-i-1; j++) {
            if (strcmp(arr[j] , arr[j+1])>0) {
                // Swap arr[j] and arr[j+1]
                swapStrings(arr, j , j+1);
            }
        }
    }
}

int binarySearch(int trova , int inArr[], int dimArr) {
    int star_idx = 0, end_idx = dimArr - 1 , mid_idx;

    while (end_idx >= star_idx) {
         mid_idx = (star_idx + end_idx) / 2;

        // If the element is present at the middle
        if (inArr[mid_idx] == trova)
            end_idx= -1;
        else
            if (inArr[mid_idx] > trova)
                end_idx= mid_idx - 1;
            else
                star_idx = mid_idx + 1; // Else the element can only be present in right subarray
    }

    // -1 element is not present in array
    return (end_idx<0?mid_idx:-1);
}

void printArray(char* msg,int arr[], int size) {
    int i;
    printf("%s",msg);
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void printParArray(char* msg,int arr[], char* arrStr[] , int size) {
    int i;
    printf("%s",msg);
    for (i=0; i < size; i++)
        printf("%s \t %d\n ",arrStr[i],arr[i]);
    printf("\n");
}
  
void initRandArray(int arr[], int size) {
    int i;
    // Fill the array with random numbers
    for (i = 0; i < size; i++) {
        arr[i] = rand() % 100;  // Generate a random number between 0 and 99
    }
}

void initRandArrayStr(char* arr[], int size) {
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Allocate and fill the array with random strings
    for (int i = 0; i < size; i++) {
        arr[i] = malloc(STRING_LENGTH + 1);  // Allocate space for the string
        for (int j = 0; j < STRING_LENGTH; j++) {
            arr[i][j] = 'a' + rand() % 26;  // Generate a random lowercase letter
        }
        arr[i][STRING_LENGTH] = '\0';  // Null-terminate the string
    }
}

void trovaneUno(int arr[])   {
    int tentativi=0, cerca, trovato;
    do
    {
        tentativi++;
        cerca = rand() % 100;       
        trovato = binarySearch(cerca, arr, ARRAY_SIZE);
        if (trovato!= -1){
           
            int arrPos[ARRAY_SIZE], numPos=0, i;
            for( i=trovato-1; i>=0 && arr[i]==cerca; i--);
            for(int j=i+1; j<ARRAY_SIZE && arr[j]==cerca; j++){
                arrPos[numPos]=j;
                  printf("%s\t",arrStr[j]);
                numPos++;
            }
            printf("\n%d +Presente da posizione %d a %d\n",cerca , i+1, i+numPos);
        }
             //printf("%d -Presente in posArras:izione %d\n",cerca, trovato); //printf("%d -Presente in posizione %d\n",cerca, trovato);f("#%d\t%d -Assente\n",tentativi,cerca);
    } while (trovato<0);

}


int main() {
       // Seed the random number generator with the current time
    srand(time(NULL));
    int arr[ARRAY_SIZE];
    
    initRandArray(arr, ARRAY_SIZE);
    initRandArrayStr(arrStr,ARRAY_SIZE);
    printArray("Array: ",arr, ARRAY_SIZE);
    printParArray("Array:\n ",arr,arrStr, ARRAY_SIZE);
    // trovaneUno(arr); per array non ordinato 
    selectionSort(arr, ARRAY_SIZE);
    printArray("Sorted array: ",arr, ARRAY_SIZE);
    printParArray("\n ",arr,arrStr, ARRAY_SIZE);
    trovaneUno(arr);
    strBubbleSort(arrStr, ARRAY_SIZE);
    printParArray("\n ",arr,arrStr, ARRAY_SIZE);
    initRandArray(arr, ARRAY_SIZE);
    printArray("Array: ",arr, ARRAY_SIZE);
    bubbleSort(arr, ARRAY_SIZE);
    printArray("Sorted array: ",arr, ARRAY_SIZE);
    trovaneUno(arr);
    return 0;
}