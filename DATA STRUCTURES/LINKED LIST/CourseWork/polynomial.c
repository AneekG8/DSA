#include<stdio.h>
#include<stdlib.h>

struct node
{
	int coeff;
	int power;
	struct node *prev,*next;
};


typedef struct node node;

void create(node **h);
void display(node *h);
void add(node **result, node *poly1, node *poly2);


int main()
{
	int m,n,i,j;
	node *h1;node *h2;node *h3;
	printf("please enter how many terms are in first polynomial\n");
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		create(&h1);
	}
	printf("please enter how many terms are in second polynomial\n");
	scanf("%d",&n);
	for(j=0;j<n;j++)
	{
		create(&h2);
	}
	printf("First Polynomial of x:\n");
    display(h1);
    printf("Second Polynomial of x:\n");
    display(h2);
	add(&h3,h1,h2);
	printf("Add:");
	display(h3);
}

void create(node **temp) 
{ 
	int x,y;
	printf("please enter the coeff: \n");
	scanf("%d",&x);
	printf("please enter the power: \n");
	scanf("%d",&y);
    node *r, *z; 
    z = *temp; 
       if(z == NULL) 
    { 
        r =(node*)malloc(sizeof(node)); 
        r->coeff = x; 
        r->power = y; 
        *temp = r; 
        r->next = (node*)malloc(sizeof(node)); 
        r = r->next; 
        r->next = NULL; 
    } 
    else
    { 
        r->coeff = x; 
        r->power = y; 
        r->next = (node*)malloc(sizeof(node)); 
        r = r->next; 
        r->next = NULL; 
    } 
} 


void display(node *h)
{
 while(h->next!=NULL)
 {
  printf("%dx^%d",h->coeff,h->power);
  h=h->next;
  if(h->next!=NULL)
   printf("+");
 }
	printf("\n");
 }

void add(node **result, node *poly1, node *poly2) 
{
    node *tmp;
    tmp = (node *) malloc(sizeof(node));
    tmp->next = NULL;
    *result = tmp; 
 
    while(poly1->next && poly2->next) 
{
        if (poly1->power > poly2->power) 
{
            tmp->power = poly1->power;
            tmp->coeff = poly1->coeff;
            poly1 = poly1->next;
        }
        else if (poly1->power < poly2->power) 
{
            tmp->power = poly2->power;
            tmp->coeff = poly2->coeff;
            poly2 = poly2->next;
        }
        else {
            tmp->power = poly1->power;
            tmp->coeff = poly1->coeff + poly2->coeff;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
 
        
     

            tmp->next = (node *) malloc(sizeof(node));
            tmp= tmp->next;
            tmp->next = NULL;
        
    }
 
    
    while(poly1->next || poly2->next) 
{
        
        
 
        if(poly1->next) {
            tmp->power = poly1->power;
            tmp->coeff = poly1->coeff;
            poly1 = poly1->next;
        }
        if(poly2->next) {
            tmp->power = poly2->power;
            tmp->coeff = poly2->coeff;
            poly2 = poly2->next;
        }
		tmp->next = (node *) malloc(sizeof(node));
        tmp= tmp->next;
        tmp->next = NULL;
    }

}
