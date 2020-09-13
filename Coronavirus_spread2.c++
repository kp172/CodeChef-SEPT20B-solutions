#include <iostream>
#include<bits/stdc++.h>
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

struct pair1
{
    int connection;
    double time;
    pair1(int c,double t)
    {
        connection = c;
        time = t;
    }
};

int BFS(std::vector<vector<pair1>> & connections,unordered_map<int,int> & visited,queue<pair1> &Q)
{
    int count1=0;
    while(!Q.empty())
    {
        pair1 x=Q.front();
        Q.pop();
        for(int j=0;j<connections[x.connection].size();j++)
           if(visited.count(connections[x.connection][j].connection)==0)
           {
               if(x.time<(connections[x.connection][j].time))
               {
                   visited[connections[x.connection][j].connection]++;
                   Q.push(connections[x.connection][j]);
                   count1++;
               }
           }
    }
    return count1;
}

void solution()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> A(n+1);
        for(int i=1;i<n+1;i++)
        {
            cin>>A[i];
        }
        vector<vector<pair1>> connections(n+1);
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<n+1;j++)
            {
                if(i!=j)
                {
                    if(i-j>0 && A[i]-A[j]<0)
                    connections[i].push_back(pair1(j,(double)(i-j)/(A[j]-A[i])));
                    if(i-j<0 && A[i]-A[j]>0)
                    connections[i].push_back(pair1(j,(double)(j-i)/(A[i]-A[j])));
                }
            }
        }
        int min=INT_MAX, max=INT_MIN;
        for(int i=1;i<n+1;i++)
        {
            unordered_map<int,int> visited;
            queue<pair1> Q;
            int count1=1;
            visited[i]++;
            for(int j=0;j<connections[i].size();j++)
            {
                visited[connections[i][j].connection]++;
                Q.push(connections[i][j]);
                count1++;
            }
            count1+=BFS(connections , visited,Q);
            if(count1>max)
            max=count1;
            if(count1<min)
            min=count1;
        }
        cout<<min<<" "<<max<<endl;
        for(int i=0;i<5;i++)
        {
            
        }
        for(int i=0;i<5;i++)
        {
            
        }
        for(int i=0;i<5;i++)
        {
            
        }
        
        
    }
    
}
