#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
    }
}

void printArray(int arr[], int n) 
{
    const int elementsPerLine = 30;

    for (int i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);

        // Move to the next line after printing elementsPerLine elements
        if ((i + 1) % elementsPerLine == 0) 
        {
            printf("\n");
        }
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
    if(s >= e) 
    {
        return;
    }
    
    int mid = (s+e)/2;

    //left part sort karna h 
    mergeSort(arr, s, mid);
    
    //right part sort karna h 
    mergeSort(arr, mid+1, e);

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

void generateRandomArray(int arr[], int n) 
{
    srand(time(NULL)); // Seed the random number generator

    for (int i = 0; i < n; i++) 
    {
        arr[i] = rand() % 1000; // Generates random values between 0 and 999
    }
}

void inputManualArray(int arr[], int n) 
{
    printf("Enter elements manually:\n");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }
}

void compareSortingAlgorithms(int originalArr[], int n) 

{
    // Create a copy of the original array to use for comparisons
    
    int *copyArr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) 
    {
        copyArr[i] = originalArr[i];
    }

    clock_t start, end;
    double executionTimes[5] = {0}; 

    const char *algorithmNames[] = {"Insertion Sort", "Selection Sort", "Merge Sort", "Quick Sort", "Bubble Sort"};

    // Insertion Sort
    start = clock();
    insertionSort(copyArr, n);
    end = clock();
    executionTimes[0] = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Reset the array for the next sorting algorithm
    for (int i = 0; i < n; i++) 
    
    {
        copyArr[i] = originalArr[i];
    }

    // Selection Sort
    start = clock();
    selectionSort(copyArr, n);
    end = clock();
    executionTimes[1] = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Reset the array for the next sorting algorithm
    for (int i = 0; i < n; i++) 
    
    {
        copyArr[i] = originalArr[i];
    }

    // Merge Sort
    start = clock();
    mergeSort(copyArr, 0, n - 1);
    end = clock();
    executionTimes[2] = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Reset the array for the next sorting algorithm
    for (int i = 0; i < n; i++) 
    {
        copyArr[i] = originalArr[i];
    }

    // Quick Sort
    start = clock();
    quickSort(copyArr, 0, n - 1);
    end = clock();
    executionTimes[3] = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Reset the array for the next sorting algorithm
    for (int i = 0; i < n; i++) 
    {
        copyArr[i] = originalArr[i];
    }

    // Bubble Sort
    start = clock();
    bubbleSort(copyArr, n);
    end = clock();
    executionTimes[4] = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Display the execution times
    printf("\nTime taken by each algorithm:\n");
    printf("\n");
    for (int i = 0; i < 5; i++) 
    {
        printf("%d. %s: %f seconds\n", i + 1, algorithmNames[i], executionTimes[i]);
    }

    // Find the best and worst algorithms

    double minTime = executionTimes[0];
    double maxTime = executionTimes[0];
    const char *bestAlgorithm = algorithmNames[0];
    const char *worstAlgorithm = algorithmNames[0];

    for (int i = 1; i < 5; i++) 
    {
        if (executionTimes[i] < minTime) 
        {
            minTime = executionTimes[i];
            bestAlgorithm = algorithmNames[i];
        }

        if (executionTimes[i] > maxTime) 
        {
            maxTime = executionTimes[i];
            worstAlgorithm = algorithmNames[i];
        }
    }

    // Display the best and worst algorithms

    printf("\nBest Algorithm: %s (Execution Time: %f seconds)\n", bestAlgorithm, minTime);
    printf("Worst Algorithm: %s (Execution Time: %f seconds)\n", worstAlgorithm, maxTime);
    printf("\n");

    // Free the memory allocated for the copy array
    free(copyArr);
}

void displayBruteForceOptions() 
{
    printf("Choose a sorting algorithm (Brute Force):\n");
    printf("1. Insertion Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Bubble Sort\n");
    printf("Enter your choice (1-3): ");
}

void displayDivideConquerOptions() 

{
    printf("Choose a sorting algorithm (Divide and Conquer):\n");
    printf("1. Merge Sort\n");
    printf("2. Quick Sort\n");
    printf("Enter your choice (1-2): ");
}

int main() 
{
    int choice;
    int n;
    int continueSorting = 1;

    while (continueSorting) 
    {
        printf("\n");
        printf(" ____________________________________________________________________________________________\n");
        printf("|                                                                                            |\n");
        printf("|                                                                                            |\n");
        printf("|                                         WELCOME USER                                       |\n");
        printf("|                                 THIS IS A SORTING MINI PROJECT                             |\n");
        printf("|                                                                                            |\n");
        printf("|                                                                                            |\n");
        printf("|                                      BY NAMAN SINGH NEGI                                   |\n");
        printf("|                                                                                            |\n");
        printf("----------------------------------------------------------------------------------------------\n");

        printf("Press Enter to continue.....\n");
        getchar();

        system("clear");

        printf("\n Select your choice :\n");
        printf("\n");

        printf("1. Enter the array manually \n");
        printf("2. Generate a random array \n");
        printf("Enter your choice (1 or 2): \n");
        scanf("%d", &choice);

        system("clear");

        if (choice != 1 && choice != 2) 
        {
            printf("Invalid choice. Please enter either 1 or 2. \n");
            continue;
        }

        printf("Enter the size of the array: ");
        scanf("%d", &n);

        system("clear");

        int *arr = (int *)malloc(n * sizeof(int));

        if (choice == 1) 
        
        {
            // Manual input
            inputManualArray(arr, n);
        } 

        else if (choice == 2) 
        
        {
            // Generate random array
            generateRandomArray(arr, n);
        } 
       
        else 
       
        {
            printf("Please enter a valid choice \n");
            continue;
        }

        getchar();

        system("clear");

        // Display which sorting technique would be best for the array size

        if (n <= 100) 
        {
            printf("For small arrays, Brute Force may be efficient.\n");
            printf("\n");
        } 
        else 
        {
            printf("For larger arrays, Divide and Conquer is recommended.\n");
            printf("\n");
        }

    
    int methodChoice;
        
    printf("Choose a method:\n");
    printf("1. Brute Force\n");
    printf("2. Divide and Conquer\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &methodChoice);

    system("clear");

    if (methodChoice != 1 && methodChoice != 2) 
    {
        printf("Invalid choice. Please enter either 1 or 2. \n");
        return 0;
    }
  
     system("clear");
    
    int sortingChoice;

    switch (methodChoice) 
    
    {
        case 1:

            displayBruteForceOptions();
            scanf("%d", &sortingChoice);
            system("clear");
            switch (sortingChoice) 
            
            {
                case 1:
                    printf("Original Array:\n");
                    printf("\n");
                    printArray(arr, n);
                    printf("\nAfter applying Insertion Sort:\n");
                    insertionSort(arr, n);
                    break;

                case 2:
                    printf("Original Array:\n");
                    printf("\n");
                    printArray(arr, n);
                    printf("\nAfter applying Selection Sort:\n");
                    selectionSort(arr, n);
                    break;

                case 3:
                    printf("Original Array:\n");
                    printf("\n");
                    printArray(arr, n);
                    printf("\nAfter applying Bubble Sort:\n");
                    bubbleSort(arr, n);
                    break;
            }

            break;

        case 2:

            displayDivideConquerOptions();
            scanf("%d", &sortingChoice);
            system("clear");
            switch (sortingChoice) 
            
            {
                case 1:
                    printf("Original Array:\n");
                    printf("\n");
                    printArray(arr, n);
                    printf("\nAfter applying Merge Sort:\n");
                    mergeSort(arr, 0, n - 1);
                    break;

                case 2:
                    printf("Original Array:\n");
                    printf("\n");
                    printArray(arr, n);
                    printf("\nAfter applying Quick Sort:\n");
                    quickSort(arr, 0, n - 1);
                    break;
            }

            break;

        default:
            printf("Invalid method choice\n");
            return 0;
    }


        clock_t start, end;
        double timeTaken;

        switch (choice) 
        {
            case 1:
                start = clock();
                insertionSort(arr, n);
                end = clock();
                timeTaken = ((double) (end - start)) / CLOCKS_PER_SEC;

                break;

            case 2:
                start = clock();
                selectionSort(arr, n);
                end = clock();
                timeTaken = ((double) (end - start)) / CLOCKS_PER_SEC;

                break;

            case 3:
                start = clock();
                mergeSort(arr, 0, n-1);
                end = clock();
                timeTaken = ((double) (end - start)) / CLOCKS_PER_SEC;

                break;

            case 4:
                start = clock();
                quickSort(arr, 0 ,n-1);
                end = clock();
                timeTaken = ((double) (end - start)) / CLOCKS_PER_SEC;

                break;

            case 5:
                start = clock();
                bubbleSort(arr, n);
                end = clock();
                timeTaken = ((double) (end - start)) / CLOCKS_PER_SEC;

                break;

            default:
                printf("Invalid choice\n");
        }

        printf("\nSorted array:\n");
        printf("\n");
        printArray(arr, n);
        printf("\n");

         // Display time taken by the selected algorithm
        printf("Time taken by the selected algorithm: %f seconds\n", timeTaken);
        printf("\n");



        // Ask user if they want to compare with other sorting algorithms
        int compareChoice;

        printf("Do you want to compare with other sorting algorithms? (1 for Yes, 0 for No): ");
        scanf("%d", &compareChoice);

        system("clear");

        if (compareChoice == 1) 
        
        {
            compareSortingAlgorithms(arr, n);
        }


        printf("Do you want to continue sorting another array? (1 for Yes, 0 for No): ");
        scanf("%d", &continueSorting);

        free(arr);

        system("clear");
    }

   

    return 0;
}

