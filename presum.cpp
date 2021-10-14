#include<stdio.h>
int main()
{
int i,n,q,l,r;
long long presum[n+1],arr[n];
scanf("%d %d",&n,&q); //taking no. of elements in array and no of queries
for(i=0;i<n;i++){
scanf("%lld",&arr[i]);                                                                                                                                                                                                                                                                                                                                             
}
presum[0]=0;
for(i=0;i<n;i++)
{
presum[i+1]=presum[i]+arr[i];     // suppose arr: 1 2 3  4   5
}                                                  //    presum:  0 1 3 6 10  15   
while(q--){
scanf("%d%d",&l,&r); //taking the value of l and r for each query
long long sum=0;
sum= presum[r]-presum[l-1];
printf("%lld\n",sum/r-l+1);
}
return 0;

}                        
