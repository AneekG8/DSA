void DISP(char *s,int t)
{
	int i;
	for(i=t;i>=0;i--)
	printf("|%c|\n",s[i]);
	printf("_______\n");
}
