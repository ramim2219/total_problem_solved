#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
void build(int ind, int low, int high, int arr[], int seg[])
{
    if(low==high)
    {
        seg[ind]=arr[low];
        return;
    }
    int mid=(low+high)/2;
    build(2*ind+1,low,mid,arr,seg);
    build(2*ind+2,mid+1,high,arr,seg);
    seg[ind]=seg[2*ind+1]+seg[2*ind+2];
}
void update(int ind,int low,int high,int i,int val,int seg[])
{
    if(low==high){
        seg[ind]=val;
        return;
    }
    int mid=(low+high)/2;
    if(i<=mid)update(2*ind+1,low,mid,i,val,seg);
    else update(2*ind+2,mid+1,high,i,val,seg);
    seg[ind]=seg[2*ind+1]+seg[2*ind+2];
}
int query_sum(int ind,int low,int high,int l,int r,int seg[])
{
    if(r<low || high<l)return 0; // No overlap
    if(low>=l && high<=r) return seg[ind];
    int mid=(low+high)/2;
    int left=query_sum(2*ind+1,low,mid,l,r,seg);
    int right=query_sum(2*ind+2,mid+1,high,l,r,seg);
    return left+right;
}
int main()
{
    fast;
    int n,q;
    cin>>n>>q;
    int arr[n+5],seg[n*4+5];
    for(int i=0;i<n;i++)cin>>arr[i];
    build(0,0,n-1,arr,seg);
    for(int i=0;i<q;i++)
    {
        int type;cin>>type;
        if(type==1)
        {
            int ind,val;
            cin>>ind>>val;
            update(0,0,n-1,ind,val,seg);
        }
        else if(type==2)
        {
            int l,r;
            cin>>l>>r;
            int ans = query_sum(0,0,n-1,l,r,seg);
            cout<<ans<<endl;
        }
    }
    return 0;
}
