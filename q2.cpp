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
struct state{
    char side;
    int cannileft;
    int missileft;
    int canniright;
    int missiright;
};
map<pair<char,pair<pair<int,int>,pair<int,int>>>,int>vis;
bool isvalid(ll a1,ll b1,ll a2,ll b2,char sd){
   if(a1<0||b1<0||a2<0||b2<0){
       return false;
   }
   if(a1>3||b1>3||a2>3||b2>3){
       return false;
   }
   if(a1<b1&&a1!=0)return false;
   if(a2<b2&&a2!=0)return false;
   if(vis[{sd,{{a1,b1},{a2,b2}}}])return false;
   return true;
}
void dobfs(int cnt1,int cnt2){
    queue<state>qq;
    qq.push({'L',cnt1,cnt2,0,0});
    bool flag=false;
    char last;
    map<pair<char,pair<pair<int,int>,pair<int,int>>>,pair<char,pair<pair<int,int>,pair<int,int>>>>par;
    while(!qq.empty()){
        struct state tp=qq.front();
        qq.pop();
        char sd=tp.side;
        ll a1=tp.cannileft;
        ll b1=tp.missileft;
        ll a2=tp.canniright;
        ll b2=tp.missiright;
        pair<int,int>p1={a1,b1};
        pair<int,int>p2={a2,b2};
        pair<pair<int,int>,pair<int,int>>p4={p1,p2};
        pair<char,pair<pair<int,int>,pair<int,int>>>p3={sd,p4};
       // cout<<a1<<" "<<b1<<" "<<a2<<" "<<b2<<endl;
        vis[{sd,{{a1,b1},{a2,b2}}}]=1;
        if(a1==0&&b1==0&&a2==3&&b2==3){
            flag=true;
            last=sd;
            break;
        }
        if(sd=='L'){
            if(isvalid(a1-2,b1,a2+2,b2,'R')){
                par[{'R',{{a1-2,b1},{a2+2,b2}}}]=p3;
                qq.push({'R',a1-2,b1,a2+2,b2});
            }
            if(isvalid(a1,b1-2,a2,b2+2,'R')){
                par[{'R',{{a1,b1-2},{a2,b2+2}}}]=p3;
                qq.push({'R',a1,b1-2,a2,b2+2});
            }
            if(isvalid(a1-1,b1-1,a2+1,b2+1,'R')){
                par[{'R',{{a1-1,b1-1},{a2+1,b2+1}}}]=p3;
                qq.push({'R',a1-1,b1-1,a2+1,b2+1});
            }
            if(isvalid(a1-1,b1,a2+1,b2,'R')){
                par[{'R',{{a1-1,b1},{a2+1,b2}}}]=p3;
                qq.push({'R',a1-1,b1,a2+1,b2});
            }
            if(isvalid(a1,b1-1,a2,b2+1,'R')){
                par[{'R',{{a1,b1-1},{a2,b2+1}}}]=p3;
                qq.push({'R',a1,b1-1,a2,b2+1});
            }
        }
        else{
            if(isvalid(a1+2,b1,a2-2,b2,'L')){
                par[{'L',{{a1+2,b1},{a2-2,b2}}}]=p3;
                qq.push({'L',a1+2,b1,a2-2,b2});
            }
            if(isvalid(a1,b1+2,a2,b2-2,'L')){
                par[{'L',{{a1,b1+2},{a2,b2-2}}}]=p3;
                qq.push({'L',a1,b1+2,a2,b2-2});
            }
            if(isvalid(a1+1,b1+1,a2-1,b2-1,'L')){
                par[{'L',{{a1+1,b1+1},{a2-1,b2-1}}}]=p3;
                qq.push({'L',a1+1,b1+1,a2-1,b2-1});
            }
            if(isvalid(a1+1,b1,a2-1,b2,'L')){
                par[{'L',{{a1+1,b1},{a2-1,b2}}}]=p3;
                qq.push({'L',a1+1,b1,a2-1,b2});
            }
            if(isvalid(a1,b1+1,a2,b2-1,'L')){
                par[{'L',{{a1,b1+1},{a2,b2-1}}}]=p3;
                qq.push({'L',a1,b1+1,a2,b2-1});
            }
        }
    }
       if(flag){
           cout<<"YOU WIN THE GAME"<<endl;
           pair<int,int>p1={3,3};
           pair<int,int>p2={0,0};
           pair<pair<int,int>,pair<int,int>>p4={p1,p2};
           pair<char,pair<pair<int,int>,pair<int,int>>>p3={'L',p4};
            pair<int,int>p5={0,0};
            pair<int,int>p6={3,3};
            pair<pair<int,int>,pair<int,int>>p7={p5,p6};
            pair<char,pair<pair<int,int>,pair<int,int>>>p8={last,p7};
           stack<pair<char,pair<pair<int,int>,pair<int,int>>>>ss;
           while(p8!=p3){
              ss.push(p8);
              p8=par[p8];
           }
           ss.push(p3);
           cout<<"LEFT SIDE   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~    RIGHT SIDE"<<endl;
           while(!ss.empty()){
               pair<char,pair<pair<int,int>,pair<int,int>>> tp =ss.top();
               cout<<tp.second.first.first<<" "<<tp.second.first.second<<"    "<<tp.first<<"                 "<<tp.second.second.first<<" "<<tp.second.second.second<<endl;
               ss.pop();
           }
       }
       else{
           cout<<"YOU LOSE THE GAME"<<endl;
       }
}
int main(){
    cout<<"Enter the no. of Cannibals and Missionaries"<<endl;
    ll cannibals,missionaries;
    cin>>cannibals>>missionaries;
    dobfs(cannibals,missionaries);
}