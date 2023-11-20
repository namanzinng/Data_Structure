#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertionSort(int arr[], int n) 
{

     int i, j, temp;

    for (i = 1; i < n; i++) 
    {
        temp = arr[i];
        j = i - 1;

        for (; j >= 0; j--) 
        {
            
            if(arr[j] > temp)
            {
                // shift   
                arr[j+1] = arr[j];
            }

            else // ruk jaoo
            {
                break;
            }
        }

        // copy temp value
        arr[j+1] = temp;

        printf("Iteration %d: ", i);
        for (int k = 0; k < n; k++) 
        {
            printf("%d ", arr[k]);
        }

        printf("\n");
      
    }
}

void selectionSort(int arr[], int n) 
{
    for (int i = 0; i < n - 1; i++) 
    {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) 
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }

        swap(&arr[minIndex], &arr[i]);

        // Print array at each iteration

        printf("Iteration %d : ", i + 1);
        for (int k = 0; k < n; k++) 
        {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }
}

void printArray(int arr[], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

void merge(int arr[], int s, int e) 
{

    int mid = (s+e)/2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int first[len1];
    int second[len2];

    //copy values
    int mainArrayIndex = s;
    for(int i=0; i<len1; i++) 
    {
        first[i] = arr[mainArrayIndex++];
    }

    mainArrayIndex = mid+1;
    for(int i=0; i<len2; i++) 
    {
        second[i] = arr[mainArrayIndex++];
    }

    //merge 2 sorted arrays     
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = s;

    while(index1 < len1 && index2 < len2) 
    {
        if(first[index1] < second[index2]) 
        {
            arr[mainArrayIndex++] = first[index1++];
        }
        else
        {
            arr[mainArrayIndex++] = second[index2++];
        }
    }   

    while(index1 < len1) 
    {
        arr[mainArrayIndex++] = first[index1++];
    }

    while(index2 < len2 ) 
    {
        arr[mainArrayIndex++] = second[index2++];
    }

}

void mergeSort(int arr[], int s, int e) 

{

    //base case
    if(s >= e) {
        return;
    }
    
    int mid = (s+e)/2;

    //left part sort karna h 
    mergeSort(arr, s, mid);
    
    //right part sort karna h 
    mergeSort(arr, mid+1, e);

    //merge
    merge(arr, s, e);

}

int partition( int arr[], int s, int e) 

{

    int pivot = arr[s];

    int cnt = 0;
    for(int i = s+1; i<=e; i++) 
    {
        if(arr[i] <=pivot) 
        {
            cnt++;
        }
    }

    //place pivot at right position
    int pivotIndex = s + cnt;
    swap(&arr[pivotIndex], &arr[s]);

    //left and right wala part smbhal lete h 
    int i = s, j = e;

    while(i < pivotIndex && j > pivotIndex) 
    {

        while(arr[i] <= pivot) 
        {
            i++;
        }

        while(arr[j] > pivot) 
        {
            j--;
        }

        if(i < pivotIndex && j > pivotIndex) 
        {
            swap(&arr[i++], &arr[j--]);
        }

    }

    return pivotIndex;

}

void quickSort(int arr[], int s, int e) {

    //base case
    if(s >= e) 
        return ;

    //partitioon karenfe
    int p = partition(arr, s, e);

    // Print array at each round
    printf("QuickSort at round (%d, %d): ", s, e);
    printArray(arr + s, e - s + 1);

    //left part sort karo
    quickSort(arr, s, p-1);

    //right wala part sort karo
    quickSort(arr, p+1, e);

}

void bubbleSort(int arr[], int n) 
{
    // for round 1 to n-1

    for (int i = 1; i < n; i++) 
    {
        int swapped = 0; // Initialize a flag to check if any swaps are made in the current pass

        for (int j = 0; j < n - i; j++) 
        {
            // process element till n-i th index
            if (arr[j] > arr[j + 1]) 
            {
                swap(&arr[j], &arr[j + 1]);
                swapped = 1; // Set the flag to 1 to indicate a swap
            }
        }

        if (swapped == 0) 
        {
            // the array is already sorted
            break;
        }
    }
}


int main() 
{
    int choice;
    int n;

    printf("\n");
    printf(" ___________________________________________________________________\n");
    printf("|                                                                   |\n");
    printf("|                                                                   |\n");
    printf("|                         WELCOME USER                              |\n");
    printf("|              THIS IS BETA VERSION OF MINI PROJECT                 |\n");
    printf("|                                                                   |\n");
    printf("|                                                                   |\n");
    printf("--------------------------------------------------------------------\n");

    printf("Press any key to continue.....\n");

    printf("\n");
    getchar();


    system("clear");

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    system("clear");

    int *arr = (int *)malloc(n * sizeof(int));

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; ++i) 
    {
        scanf("%d", &arr[i]);
    }

    system("clear");

    printf("Choose a sorting algorithm:\n");

    printf("1. Insertion Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Merge Sort\n");
    printf("4. Quick Sort\n");
    printf("5. bubble Sort\n");
    printf("Enter your choice (1-5): ");

   
    scanf("%d", &choice);

    system("clear");


    switch (choice) 
    
    {
        case 1:
           
            printf("original Array :\n");
            printf("\n");

            printArray(arr,n);

            printf("\n");

            printf("After appling Insertion Sort \n");
            
            printf("\n");

            insertionSort(arr, n);

            printf("\n");

            printf(" Best case \t Average case \t Worst case \n");
            printf("   O(n) \t    O(n^2)     \t O(n^2)");

            printf("\n");
            break;

        case 2:

            printf("original Array :\n");
            printf("\n");

            printArray(arr,n);

            printf("\n");

            printf("After appling Selection Sort \n");
            
            printf("\n");

            selectionSort(arr, n);

            printf("\n");

            printf(" Best case \t Average case \t Worst case \n");
            printf("   O(n^2) \t    O(n^2)     \t O(n^2)");

            printf("\n");
            break;


        case 3:

            printf("original Array :\n");
            printf("\n");

            printArray(arr,n);

            printf("\n");
            
            
            printf("Best case \t Average case \t Worst case \n");
            printf("O(n log n)  \t O(n log n)  \t O(n log n)");

            printf("\n");
            break;
            

        
        case 4:

            printf("original Array :\n");
            printf("\n");

            printArray(arr,n);

            printf("\n");

            printf("After appling Quick Sort \n");
            
            printf("\n");

            quickSort(arr, 0, n-1);

            printf("\n");

            printf("Best case \t Average case \t Worst case \n");
            printf("O(n log n)  \t O(n log n)  \t O(n^2)");

            printf("\n");
            break;

        case 5:
           
            printf("original Array :\n");
            printf("\n");

            printArray(arr,n);

            printf("\n");

            printf("After appling Bubble Sort \n");
            
            printf("\n");

            bubbleSort(arr, n);

            printf("\n");

            printf("Best case \t Average case \t Worst case \n");
            printf("O(n) \t    O(n^2)     \t O(n^2)");

            printf("\n");
            break;

            
  

        default:
            printf("Invalid choice\n");
    }


    printf("\nSorted array:\n");

    printf("\n");

    printArray(arr, n);

    printf("\n");

    free(arr);

    return 0;
}
