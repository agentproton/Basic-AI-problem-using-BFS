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
map<pii,int>vis;
bool isinvalid(pii p,ll a,ll b ){
    if(p.first>a||p.second>b)return true;
    if(p.first<0||p.second<0)return true;
    if(vis[p]==1)return true;
    return false;
}
void dobfs(ll a,ll b,ll target){
   // int cp_x,cp_y;
    queue<pii>qq;
    pii final;
    qq.push({0,0});
    bool flag=false;
    map<pii,pii>par;
    while(!qq.empty()){
       pii tp=qq.front();
       qq.pop();
       vis[tp]=1;
       if(tp.first==target||tp.second==target){
           flag=true;
           final=tp;
           break;
       }
      if(tp.first<a){
          pii p1={a,tp.second};
          if(!vis[p1]){
              qq.push(p1);
              par[p1]=tp;
          }
      }
      if(tp.second<b){
          pii p1={tp.first,b};
          if(!vis[p1]){
              qq.push(p1);
              par[p1]=tp;
          }
      }
      if(tp.first>0){
          pii p1={0,tp.second};
          if(!vis[p1]){
              qq.push(p1);
              par[p1]=tp;
          }
      }
      if(tp.second>0){
         pii p1={tp.first,0};
         if(!vis[p1]){
             qq.push(p1);
             par[p1]=tp;
         }
      }
      ll tt=(tp.first+tp.second);
      if(tp.second>0){
          int c=tt-a;
          int h=min(tt,a);
          int k=max(0,c);
          pii p1={h,k};
          if(!vis[p1]){
              qq.push(p1);
              par[p1]=tp;
          }
      }
      if(tp.first>0){
          int c=tt-b;
          int h=max(0,c);
          int k=min(tt,b);
          pii p1={h,k};
          if(!vis[p1]){
              qq.push(p1);
              par[p1]=tp;
          }
      }

    }
    if(flag){
        cout<<"IT IS POSSIBLE"<<endl;
        pii in={0,0};
        stack<pii>ss;
        //cout<<final.first<<" "<<final.second<<endl;
        while(final!=in){
          ss.push(final);
          //cout<<final.first<<" "<<final.second<<endl;
          final=par[final];
        }
        ss.push(in);
        while(!ss.empty()){
            pii ans=ss.top();
            cout<<ans.first<<" "<<ans.second<<endl;
            ss.pop();
        }
    }
    else{
        cout<<"BETTER LUCK NEXT TIME"<<endl;
    }
   
}
int main(){
    ll n,m,target;
    cout<<"enter the size of glass 1 and glass 2 respectively"<<endl;
    cin>>n>>m;
    cout<<"enter the target size"<<endl;
    cin>>target;
    dobfs(n,m,target);
}