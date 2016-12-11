#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#define SIZE 10
int min_position(int* data, int from, int to);
void selection_sort(int* data, int size);

void insertion_sort(int* data, int size);


void mergeSort(int x[], int n);
void msort(int x[], int lo, int hi, int tmp[]);
void merge(int x[], int lo, int mid, int hi, int tmp[]);



void bubbleSort(int* x, int size);


int pivot(int* x, int lo, int hi);
void qSort( int* a, int lo, int hi );
void quicksort( int* x, int n);




void swap(int* a, int * b);
void printlist(int* a, int n);



int main()
{
    int i;
    int data[SIZE];
    srand ((unsigned)time(NULL));
    //int data[] = {33, 64, 65, 75, 25, 66, 94, 7, 10, 57,59};
    for (i = 0; i < SIZE; i++)
        data[i] = rand()%100 +1;
    
    printlist(data,SIZE);
    
    
    //selection_sort(data, SIZE);
    // insertion_sort(data, SIZE);
    //mergeSort(data, SIZE);
    // bubbleSort(data, SIZE);
    quicksort(data, SIZE);
    
    printlist(data,SIZE);
    system("pause");
    return 0;
}


//---------------------------------Selection Sort------------------------------------------------

/*
 Purpose: Find the position of the minimum value in part of an array
 
 Param:  data - integer array to be sorted
 from - starting index
 to   - ending index
 
 returns  - index of minimum value between from and to
 */

int min_position(int* data, int from, int to)

{
    
    int min_pos = from;
    
    int i;
    
    for (i = from + 1; i <= to; i++)
        
        if (data[i] < data[min_pos]) min_pos = i;
    
    return min_pos;
    
}

/*
 Purpose: sorts elements of an array of integers using selection sort
 
 Param:  data - integer array to be sorted
 size - size of the array
 */

void selection_sort(int* data, int size)

{
    
    int next; // The next position to be set to the minimum
    
    for (next = 0; next <size - 1; next++)
        
    {
        
        int min_pos = min_position(data, next, size-1);
        
        if (min_pos != next)
            
            swap(&data[min_pos], &data[next]);
        
    }
    
}

//---------------------------------Insertion Sort------------------------------------------------

/*
 Purpose: sorts elements of an array of integers using insertion sort
 
 Param:  data - integer array to be sorted
 size - size of the array
 */

void insertion_sort(int* data, int size)
{
    int i;
    int pos, temp;
    for (i = 1 ; i <= size-1; i++) {
        temp = data[i];
        pos = i-1;
        
        while ( pos >= 0 && data[pos] > temp) {
            data[pos+1]   = data[pos];
            pos--;
        }
        data[pos+1] = temp;
    }
}






//-------------------------------------Merge Sort------------------------------------------------------------

/*
 Purpose:  Merges two adjacent ranges in an array
 
 param     x   - integer array to be sorted
 lo   - from the start of the first range
 mid  - the end of the first range
 end  - end of the second range
 tmp[]- temp memory used for sorting
 */

void merge(int x[], int lo, int mid, int hi, int tmp[]) {
    
    int a = lo, b = mid+1, k;
    
    for( k = lo; k <= hi; k++ )
        
        if( a <= mid && ( b > hi || x[a] < x[b] ) )
            
            tmp[k] = x[a++];
    
        else
            
            tmp[k] = x[b++];
    
    for( k = lo; k <= hi; k++ )
        
        x[k] = tmp[k];
    
}



/**
 Purpose:  Sorts the elements in a range in an array.
 
 param     x   - integer array to be sorted
 lo  - start of the range to sort
 hi  - end of the range to sort
 tmp - temp memory used for sorting
 */


void msort(int x[], int lo, int hi, int tmp[]) {
    
    int mid;
    
    if (lo >= hi)
        
        return;
    
    mid = (lo+hi)/2;
    
    msort(x, lo, mid, tmp);      /* left partition  */
    
    msort(x, mid+1, hi, tmp);    /* right partition */
    
    merge(x, lo, mid, hi, tmp);
    
}




/*
 Purpose: sorts elements of an array of integers using merge sort
 
 Param:  x - integer array to be sorted
 n - size of the array
 */

void mergeSort(int x[], int n) {
    
    int * tmp = (int *) malloc(n * sizeof(int));  /* temp. space */
    
    msort(x, 0, n-1, tmp);
    
    free(tmp);
    
}







//----------------------------------------Bubble Sort-----------------------------------------------

/*
 Purpose: sorts elements of an array of integers using bubble sort
 
 Param:  x - integer array to be sorted
 n - size of the array
 */

void bubbleSort(int* x, int n)
{
    int i, j, flag = 1;    // set flag to 1 to start first pass
    for(i = 1; (i <= n) && flag; i++)
    {
        flag = 0;
        for (j=0; j < (n -1); j++)
        {
            if (x[j+1] < x[j])      // descending order simply changes to <
            {
                swap(&x[j], &x[j+1]);
                flag = 1; // indicates that a swap occurred.
            }
        }
    }
    return;   //arrays are passed to functions by address; nothing is returned
}

//--------------------------------------Quick Sort------------------------------------------------------------


/*
 Purpose: find and return the index of pivot element.
 
 Param:  x  - integer array to be sorted
 lo - the start of the sequence to be sorted.
 hi - the end of the sequence to be sorted.
 */

int pivot(int* x, int lo, int hi){
    int i;
    int  p = lo;
    int pivotElement = x[lo];
    for(i = lo+1 ; i <= hi ; i++){
        if(x[i] <= pivotElement){
            p++;
            swap(&x[i], &x[p]);
        }
    }
    
    swap(&x[p], &x[lo]);
    return p;
}


/*
 Purpose: sorts elements of an array of integers using Quicksort
 
 Param:  x  - integer array to be sorted
 lo - the start of the sequence to be sorted.
 hi - the end of the sequence to be sorted.
 */

void qSort( int* a, int lo, int hi ){
    int pivotElement;
    if(lo < hi){
        pivotElement = pivot(a, lo, hi);
        qSort(a, lo, pivotElement-1);
        qSort(a, pivotElement+1, hi);
    }
}

void quicksort( int* x, int n)
{
    qSort(x,0, n-1);
}


/////////////////////////////////////////////////////////////////////////

/*
 Purpose: swaps the value of the two passed parameters
 
 Param:  a  - first integer
 b  - second integer
 */

void swap(int* a, int * b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}




/*
 Purpose: prints the elements of an array of integers
 
 Param:  a  -  array to be printed
 n  -  size of the array
 */
void printlist(int* a, int n){
    int i;
    for ( i = 0; i < n; i++)
        printf("%d " , a[i]);
    
    printf(" \n");
}


