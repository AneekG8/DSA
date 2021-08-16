#include<stdio.h>

//using namespace std;

int i=0;
#define loop for(;i<3;i++)

int main()
{
    char* chegg_ptr = "Chegg";
    loop
    printf(chegg_ptr+i);
    return 0;
}
