void POP(int *s,int *t)
{
	if(*t==-1)
	{
		printf("stack is empty\n");
		return;
	}
	printf("Deleted %d\n",s[*t]);
	(*t)--;
}
