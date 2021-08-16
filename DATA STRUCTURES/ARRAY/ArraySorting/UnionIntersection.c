/*
UNION:
1) Use two index variables i and j, initial values i = 0, j = 0
2) If arr1[i] is smaller than arr2[j] then print arr1[i] and increment i.
3) If arr1[i] is greater than arr2[j] then print arr2[j] and increment j.
4) If both are same then print any of them and increment both i and j.
5) Print remaining elements of the larger array.
*/
#include<stdio.h>
#include<stdlib.h>
void Union(int small,int large,int *s,int *l)
{
	int i=0,j=0;
	while(i<small && j<large)
	{
		if(s[i]<l[j])
		{
			printf("%d ",s[i]);
			do{												//to ignore the duplicate elements
				i++;
				}while(s[i-1]==s[i]);
		}
		else if(l[j]<s[i])
		{
			printf("%d ",l[j]);
			do{
				j++;
				}while(l[j-1]==l[j]);
		}
		else
		{
			printf("%d ",s[i]);
			do{
				i++;
				}while(s[i-1]==s[i]);
			do{
				j++;
				}while(l[j-1]==l[j]);
		}
	}
	while(i<small)
	{
		printf("%d ",s[i]);
		do{
			i++;
			}while(s[i-1]==s[i]);
	}
	while(j<large)
	{
		printf("%d ",l[j]);
		do{
			j++;
			}while(l[j-1]==l[j]);
	}
	printf("\n");
}
void Intersection(int small,int large,int *s,int *l)
{
	int i=0,j=0;
	while(i<small && j<large)
	{
		if(s[i]<l[j])
		{
			do{												//to ignore the duplicate elements
				i++;
				}while(s[i-1]==s[i]);
		}
		else if(l[j]<s[i])
		{
			do{
				j++;
				}while(l[j-1]==l[j]);
		}
		else
		{
			printf("%d ",s[i]);
			do{
				i++;
				}while(s[i-1]==s[i]);
			do{
				j++;
				}while(l[j-1]==l[j]);
		}
	}
	printf("\n");
}
int main()
{
	int a[]={1,1,2,3,3,3,5,10,10,20,20,20};
	int b[]={2,2,2,5,5,8,8,15,15,15,20};
	Union(11,12,b,a);
	Intersection(11,12,b,a);
	return 0;
}
