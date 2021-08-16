void DISP(int *s,int t)
{
	while(t!=-1)
	printf("|%d|\n",s[t--]);
	printf("_______\n");
}
