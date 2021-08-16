// CPP program to sort an array with two types 
// of values in one traversal. 
#include <bits/stdc++.h> 
using namespace std; 
  
/* Method for segregation 0 and 1 given  
   input array */
// 2 WAY PARTITION:
void segregate0and1(int arr[], int n) 
{ 
    int type0 = 0; 
    int type1 = n - 1; 
  
    while (type0 < type1) { 
        if (arr[type0] == 1) { 
            swap(arr[type0], arr[type1]); 
            type1--; 
        } 
        else { 
            type0++; 
        } 
    } 
} 
  
// Driver program 
int main() 
{ 
    int arr[] = { 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1 }; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    segregate0and1(arr, n); 
    int a;
    for (a=0;a<n;a++) 
        cout << arr[a] << " "; 
} 
