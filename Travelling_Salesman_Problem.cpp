#include<bits/stdc++.h>
using namespace std;
#define mod                   1000000007
#define ll                    long long
#define Author                std::ios_base::sync_with_stdio(0);
#define u_map                 unordered_map<ll,ll>
#define n_map                 map<ll,ll>
#define n_pair                pair<ll,ll>
#define all(v)                v.begin(),v.end()
#define frr(i,j,k)            for(int i=j; i<k; i++)
#define frp(i,j,k)            for(int i=j; i>=k; i--)
#define pb(a)                 push_back(a)
#define lb(v,t)               lower_bound(all(v),t)-v.begin()
#define ub(v,t)               upper_bound(all(v),t)-v.begin()
#define mem(a)               memset(a,0,sizeof(a))
#define pii                  pair<int,int>
vector<int>v[100];
map<pii,int>mp;
struct state{
    vector<int>vs;
    int cost;
};
void dobfs(int start,int  n){
    ll dis[n+1];
    map<vector<int>,int>vis;
    vector<int>ans;
    ans.pb(start);
    queue<state>qq;
    qq.push({ans,0});
    int min=INT_MAX;
    vector<int>path;
    while(!qq.empty()){
        struct state tp=qq.front();
        qq.pop();
        vector<int>vv=tp.vs;
        int cst=tp.cost;
        ll curr=vv[vv.size()-1];
        bool flag=false;
        ll cnt=0;
        for(int i:v[curr]){
            if(i==start)cnt=1;
            if(find(vv.begin(),vv.end(),i)!=vv.end())continue;
            flag=true;
            vv.pb(i);
            qq.push({vv,cst+mp[{curr,i}]});
            vv.pop_back();
        }
        if(!flag){
            if(cnt==1&&vv.size()==n){
                cst+=mp[{curr,start}];
                if(cst<min){
                    min=cst;
                    path=vv;
                }
            }
        }
    }
   // cout<<min<<endl;
   // cout<<path.size()<<endl;
    if(path.size()==n){
        cout<<"YES MISSION SUCCESSFUL"<<endl;
        frr(i,0,n){
            cout<<path[i]<<" ";
        }
        cout<<start<<endl;
        cout<<min<<endl;
    }
    else{
        cout<<"UNSUCCESSFUL"<<endl;
    }


}
int main(){
    ll n,m;
    cout<<"ENTER THE NUMBER OF VERTICES AND EDGES"<<endl;
    cin>>n>>m;
    cout<<"ENTER THE EDGE IN THE FORMAT A-->B WEIGHT W" <<endl;
    frr(i,0,m){
        ll a,b,c;
        cin>>a>>b>>c;
        mp[{a,b}]=c;
        mp[{b,a}]=c;
        v[a].push_back(b);
        v[b].pb(a);
    }
    cout<<"GIVE START VERTEX"<<endl;
    ll start;
    cin>>start;
    dobfs(start,n);
}
