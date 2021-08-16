void PUSH(int *s,int *t,int SIZE)
{
	int val;
	if(*t==SIZE-1)
	{
		printf("stack is full\n");
		return;
	}
	printf("enter ur value\n");
	scanf("%d",&val);
	(*t)++;
	s[*t]=val;
}
