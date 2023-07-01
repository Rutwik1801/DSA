#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// rank and parent array
int r[10001];
int parent[10001];

//initialize rank to 0 and parent of i to i itself 
void makeSet(int n){
    for(int i=1;i<=n;i++){
        r[i]=0;
        parent[i]=i;
    }
}

int findParent(int node){
    if(node==parent[node]) return node;
    // here parent[node]= signifies the compression (i.e. it directly connects the child to ultimate parent and reduces time complexity )
    return parent[node]=findParent(parent[node]);
}

// union
 void un(int u,int v){
     u=findParent(u);
     v=findParent(v);
     if(r[u]<r[v]){
         parent[u]=v;
     }else if(r[u]>r[v]){
         parent[v]=u;
     }else{
        //  here parent[u]=v is also correct
         parent[v]=u;
                 //  case where rank is equal so we increment the rank
         r[u]++;
     }
 }

int main(){
    int n;
    cin>>n;
    makeSet(n);
    return 0;
}