
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;


typedef long long ll;
void solution();

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    clock_t tStart=clock();
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    solution();
    
    #ifndef ONLINE_JUDGE
    fprintf(stderr,"Runtime: %.10fs\n",(double)(clock() - tStart)/CLOCKS_PER_SEC);
    #endif
    return 0;
}

ll func(ll n)
{
    return (n*(n+1))/2;
}

void solution()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll sum=(n*(n+1))/2;
        ll ans1=0;
        if(sum & 1)ans1=0;
        else
        {
            double tmp=sum/2;
            double k=(sqrt(8 * tmp +1)/2)-0.5;
            double deci,inti;
            deci=modf(k,&inti);
            ll ans=(ll)k;
            if(deci==0) 
                ans1=func(ans-1) + func(n-ans-1);
            ans1+=n-ans;    
        }
        cout<<ans1<<endl;
        for(int i=0;i<6;i++)
        {
            
        }
    }
    for(int i=0;i<6;i++)
    {
        
    }
}


