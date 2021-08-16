/*
Question: An Array of integers is given, both +ve and -ve. You need to find the two elements such that their sum is closest to zero.

1) Sort all the elements of the input array.
2) Use two index variables l and r to traverse from left and right ends respectively. Initialize l as 0 and r as n-1.
3) sum = a[l] + a[r]
4) If sum is -ve, then l++
5) If sum is +ve, then r–
6) Keep track of abs min sum.
7) Repeat steps 3, 4, 5 and 6 while l < r
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void quickSort(int *, int, int); 
  
/* Function to print pair of elements having minimum sum */
void minAbsSumPair(int arr[], int n) 
{ 
  // Variables to keep track of current sum and minimum sum 
  int sum, min_sum = 9999999; 
  
  // left and right index variables 
  int l = 0, r = n-1; 
  
  // variable to keep track of the left and right pair for min_sum 
  int min_l = l, min_r = n-1; 
  
  /* Array should have at least two elements*/
  if(n < 2) 
  { 
    printf("Invalid Input"); 
    return; 
  } 
  
  /* Sort the elements */
  quickSort(arr, l, r); 
  
  while(l < r) 
  { 
    sum = arr[l] + arr[r]; 
  
    /*If abs(sum) is less then update the result items*/
    if(abs(sum) < abs(min_sum)) 
    { 
      min_sum = sum; 
      min_l = l; 
      min_r = r; 
    } 
    if(sum < 0) 
      l++; 
    else
      r--; 
  } 
  
  printf(" The two elements whose sum is minimum are %d and %d", 
          arr[min_l], arr[min_r]); 
} 
  
/* Driver program to test above function */
int main() 
{ 
  int arr[] = {1,-2,-5,2,3,-3}; 
  int n = sizeof(arr)/sizeof(arr[0]); 
  minAbsSumPair(arr, n); 
  getchar(); 
  return 0; 
} 
  
/* FOLLOWING FUNCTIONS ARE ONLY FOR SORTING 
    PURPOSE */
void exchange(int *a, int *b) 
{ 
  int temp; 
  temp = *a; 
  *a   = *b; 
  *b   = temp; 
} 
  
int partition(int arr[], int si, int ei) 
{ 
  int x = arr[ei]; 
  int i = (si - 1); 
  int j; 
  
  for (j = si; j <= ei - 1; j++) 
  { 
    if(arr[j] <= x) 
    { 
      i++; 
      exchange(&arr[i], &arr[j]); 
    } 
  } 
  
  exchange (&arr[i + 1], &arr[ei]); 
  return (i + 1); 
} 
  
/* Implementation of Quick Sort 
arr[] --> Array to be sorted 
si  --> Starting index 
ei  --> Ending index 
*/
void quickSort(int arr[], int si, int ei) 
{ 
  int pi;    /* Partitioning index */
  if(si < ei) 
  { 
    pi = partition(arr, si, ei); 
    quickSort(arr, si, pi - 1); 
    quickSort(arr, pi + 1, ei); 
  } 
} 
