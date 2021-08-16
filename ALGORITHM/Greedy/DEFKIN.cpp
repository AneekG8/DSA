#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int w,h,n;
		cin>>w>>h>>n;

		int hr[n+2];
		int vr[n+2];

		hr[0] = 1,vr[0] = 1,hr[n+1] = w+1, vr[n+1] = h+1;

		for(int i=1;i<=n;i++)
			cin>>hr[i]>>vr[i];

		sort(hr,hr+n+2);
		sort(vr,vr+n+2);

		int height = INT_MIN,width = INT_MIN;

		for(int i=1;i<=n+1;i++)
		{
			height = max(height,vr[i]-vr[i-1]);
			width = max(width,hr[i]-hr[i-1]);
		}

		height -= 1;
		width -= 1;

        int res = height*width;

        cout<< res <<endl;
	}
	return 0;
}

