#include <bits/stdc++.h>
using namespace std;
#define ll long long
int Cross(int a[],int low,int mid,int high)
{
    int sum=0;
    int leftsum=INT_MIN;
    for(int i=mid;i>=low;--i)
    {
        sum+=a[i];
        leftsum=max(leftsum,sum);
    }
    sum=0;
    int rightsum=INT_MIN;
    for(int i=mid+1;i<=high;++i)
    {
        sum+=a[i];
        rightsum=max(rightsum,sum);
    }

    return max(leftsum + rightsum, max(leftsum, rightsum));
}

int MaxSum(int a[],int low, int high)
{
    if(low>high)
    {
        return 0;
    }
    if(low==high)
    {
        return a[low];
    }
    int mid=(low+high)/2;
    return max(max(MaxSum(a, low, mid-1),MaxSum(a, mid+1, high)),Cross(a,low,mid,high));
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n;++i)
    {
        cin >> a[i];
    }
    cout << MaxSum(a,0,n-1);
}