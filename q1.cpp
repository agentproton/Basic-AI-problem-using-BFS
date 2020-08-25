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
 #define ft                   first
 #define sd second
 #define in(a)  scanf("%lld",&a);
 #define out(a) printf("%lld\n",a);
//mainly used functions
struct data{
  vector<vector<int>>vs;
  int height;
};
bool doswapup(vector<vector<int>>&a, map<vector<vector<int>>,int>vis){
   frr(i,0,3){
     frr(j,0,3){
       if(a[i][j]==0){
          if(i==0)return false;
          else{
            swap(a[i-1][j],a[i][j]);
            if(!vis[a])return true;
              else return false; 
          }
       }
     }
   }

}
bool doswapdown(vector<vector<int>>&a, map<vector<vector<int>>,int>vis){
   frr(i,0,3){
     frr(j,0,3){
       if(a[i][j]==0){
          if(i==2)return false;
          else{
            swap(a[i+1][j],a[i][j]);
            if(!vis[a])return true;
             else return false;
          }
       }
     }
   }
}
bool doswapright(vector<vector<int>>&a, map<vector<vector<int>>,int>vis){
   frr(i,0,3){
     frr(j,0,3){
       if(a[i][j]==0){
          if(j==2)return false;
          else{
            swap(a[i][j+1],a[i][j]);
            if(!vis[a])return true;
             else return false;
          }
       }
     }
   }
}
bool doswapleft(vector<vector<int>>&a, map<vector<vector<int>>,int>vis){
   frr(i,0,3){
     frr(j,0,3){
       if(a[i][j]==0){
          if(j==0)return false;
          else{
            swap(a[i][j-1],a[i][j]);
            if(!vis[a])return true;
            else return false;
          }
       }
     }
   }
   
}
void print(vector<vector<int>>&v){
  frr(i,0,3){
    frr(j,0,3){
      cout<<v[i][j];
    }
    cout<<endl;
  }
  cout<<endl;
}
void dobfs(vector<vector<int>>&in,vector<vector<int>>&out){
    struct data d={in,0};
    map<vector<vector<int>>,vector<vector<int>>>par;
    map<vector<vector<int>>,int>vis;
    queue<data>qq;
    qq.push(d);
    bool result=false;
    ll cost=0;
    int lop=100000000,k=0;
    while(!qq.empty()){
       struct data tp=qq.front();
       qq.pop();
       vector<vector<int>>v=tp.vs;
       vis[v]=1;
       //print(v);
       int hk=tp.height;
       vector<vector<int>>v1=v;
       vector<vector<int>>v2=v;
       vector<vector<int>>v3=v;
       vector<vector<int>>v4=v;
       if(vis[out]==1){
         result=true;
         cost=hk;
         break;
       }
       if(doswapup(v1,vis)){
          par[v1]=v;
          qq.push({v1,hk+1});
       }
       if(doswapdown(v2,vis)){
         par[v2]=v;
         qq.push({v2,hk+1});
       }
       if(doswapright(v3,vis)){
          par[v3]=v;
          qq.push({v3,hk+1});
       }
       if(doswapleft(v4,vis)){
          par[v4]=v;
          qq.push({v4,hk+1});
       }
       k++;
       if(k>lop)break;
    }
    stack<vector<vector<int>>>ss;
    if(result){
      cout<<"YES"<<endl;
       while(out!=in){
         ss.push(out);
         out=par[out];
       }
       ss.push(in);
       while(!ss.empty()){
         print(ss.top());
         ss.pop();
       }
    }
    else{
      cout<<"NO"<<endl;
    }
 
}
int main(){
    ll n;
    cin>>n;
     vector<vector<int>>in( n+1 , vector<int> (n+1, 0));
     vector<vector<int> > out( n+1 , vector<int> (n+1, 0));
    ll l=0,m=0;
    frr(i,0,n){
      frr(j,0,n){
         cin>>in[i][j];
      }
    }
    frr(i,0,n){
      frr(j,0,n){
         cin>>out[i][j];
      }
    }
   dobfs(in,out);
}