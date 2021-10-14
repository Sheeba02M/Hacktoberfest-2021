#include<bits/stdc++.h>
using namespace std;
int main()
{
	bool found=false;
	int arr[]={0,-1,2,3,1};
	int n=sizeof(arr)/sizeof(arr[0]);
	sort(arr,arr+n);
	for(int i=0;i<n;i++)
		{
			int l=i+1;
			int r=n-1;
			int x=arr[i];

			while(l<r)
			{
             if(arr[l]+arr[r]+x==0)
             {
             	cout<<arr[l]<<" "<<x<<" "<<arr[r]<<endl;
             	l++;
             r++;
             found=true;
             break;
			}
			else if(arr[l]+arr[r]+x>0)
				r--;
			else
				l++;
		}
		
		}
		if(found==false)
			cout<<"No triplet found"<<endl;
}
