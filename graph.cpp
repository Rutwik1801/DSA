#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// ///////////////////////////////////////////////////////////////////
// // Prims Algorithm for minimum spanning tree

// int findMin(int V,vector<int> vis,vector<int> val){
//     int minVal=INT_MAX,idx;
//     for(int i=0;i<V;i++){
//         if(vis[i]!=1 && val[i]<minVal){
//             minVal=val[i];
//             idx=i;
//         }
//     }
//     return idx;
// }
// int main(){
//     int V,e;
//     cin>>V>>e;
//     vector<vector<int>> adj[V];
//     for(int i=0;i<e;i++){
//       int u,v,w;
//       cin>>u>>v>>w;
//       adj[u].push_back({v,w});
//       adj[v].push_back({u,w});
//     }
//   vector<int> val(V,INT_MAX);
//   vector<int> vis(V,0);
//   int res=0;
//   val[0]=0;
//   for(int i=0;i<V;i++){
//       int u=findMin(V,vis,val);
//       vis[u]=1;
//       res+=val[u];
//       for(int j=0;j<adj[u].size();j++){
//           if(vis[adj[u][j][0]]!=1){
//               val[adj[u][j][0]]=min(val[adj[u][j][0]],adj[u][j][1]);
//           }
//       }
//   }
//   cout<<res<<"ff";
//     return 0;
// }
// // Prims algo for minimum spanning tree
// ///////////////////////////////////////////////////////////////

// ////////////////////////////////////////////////////
// // Dijkstras Algo

//     vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
//     {
//         // Code here
//       vector<int> vis(V,INT_MAX);
//       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
//       vis[S]=0;
//       pq.push({0,S});
//       while(!pq.empty()){
//           int dist=pq.top().first;
//           int node=pq.top().second;
//           pq.pop();
//           for(int i=0;i<adj[node].size();i++){
//               int newDist=adj[node][i][1];
//               int newNode=adj[node][i][0];
//               if(vis[newNode]>dist+newDist){
//                   vis[newNode]=dist+newDist;
//                   pq.push({vis[newNode],newNode});
//               }
//           }
//       }
//       return vis;
//     }
//     // Dijkstras algo
// ////////////////////////////////////////////////////////

// //////////////////////////////////////
// // Topological Sort

// 	void solve(vector<int> adj[],vector<int> &vis,int V,stack<int> &st){
// 	    vis[V]=1;
// 	    for(int i=0;i<adj[V].size();i++){
// 	        if(!vis[adj[V][i]]){
// 	            solve(adj,vis,adj[V][i],st);
// 	        }
// 	    }
// 	    st.push(V);
// 	}
// 	vector<int> topoSort(int V, vector<int> adj[]) 
// 	{
// 	    // code here
// 	    stack<int> st;
// 	    vector<int> vis(V,0);
// 	    for(int i=0;i<V;i++){
// 	        if(vis[i]==0){
// 	     	    solve(adj,vis,0,st);       
// 	        }
// 	    }
// 	    vector<int> ans;
// 	    while(!st.empty()){
// 	        ans.push_back(st.top());
// 	        st.pop();
// 	    }
// 	    return ans;
// 	}

// // Topo Sort
//     /////////////////////////////////////////

//     ////////////////////////////////////////////
// // Minimum time taken by each job to be completed given by a Directed Acyclic Graph

// int main(){
// int v,e;
// cin>>v>>e;
// vector<int> g[v+1];
// vector<int> indeg(v+1,0);
// for(int i=0;i<e;i++){
// int x,y;
// cin>>x>>y;
// g[x].push_back(y);
// indeg[y]++;
// }    
// queue<int> q;
// vector<int> ans(v+1,0);
// for(int i=1;i<=v;i++){
// if(indeg[i]==0){
// q.push(i);
// ans[i]=1;
// }}
// while(!q.empty()){
// int val=q.front(); q.pop();
// for(int i=0;i<g[val].size();i++){
// indeg[g[val][i]]--;
// if(indeg[g[val][i]]==0){
// ans[g[val][i]]=ans[val] + 1;
// q.push(g[val][i]);
// }}}
// for(int i=1;i<ans.size();i++){
// cout<<ans[i]<<" "; 
// }
// return 0;
// }


// ///////////////////////////////////
// // //////////Disjoint Set


// int r[10001];
// int parent[10001];

// //initialize rank to 0 and parent of i to i itself 
// void makeSet(int n){
//     for(int i=1;i<=n;i++){
//         r[i]=0;
//         parent[i]=i;
//     }
// }

// int findParent(int node){
//     if(node==parent[node]) return node;
//     // here parent[node]= signifies the compression (i.e. it directly connects the child to ultimate parent and reduces time complexity )
//     return parent[node]=findParent(parent[node]);
// }

// // union
//  void un(int u,int v){
//      u=findParent(u);
//      v=findParent(v);
//      if(r[u]<r[v]){
//          parent[u]=v;
//      }else if(r[u]>r[v]){
//          parent[v]=u;
//      }else{
//         //  here parent[u]=v is also correct
//          parent[v]=u;
//                  //  case where rank is equal so we increment the rank
//          r[u]++;
//      }
//  }

// int main(){
//     int n;
//     cin>>n;
//     makeSet(n);
//     return 0;
// }



// ///////Disjoint Set
///////////////////////////////////////////////

/////////////////////////////////
// ///////Kruskals Algorithm

// it uses the disjoint set technique


// int findParent(int node,vector<int> &parent){
//     if(node==parent[node]) return node;
//     return parent[node]=findParent(parent[node],parent);
// }
// void un(int u,int v,vector<int> &parent,vector<int> &rank){
//     u=findParent(u,parent);
//     v=findParent(v,parent);
//     if(rank[u]<rank[v]){
//         parent[u]=v;
//     }else if(rank[v]<rank[u]){
//         parent[v]=u;
//     }else{
//         parent[v]=u;
//         rank[u]++;
//     }

// }

// void makeSet(vector<int> &parent,vector<int> &rank,int n){
//     for(int i=0;i<n;i++){
//         parent[i]=i;
//         rank[i]=0;
//     }
// }

// int main(){
//     int n,e;
//     cin>>n>>e;
//     vector<vector<int>> edges;
//   for(int i=0;i<e;i++){
//       int u,v,wt;
//       cin>>u>>v>>wt;
//      vector<int> temp={wt,u,v};
//      edges.push_back(temp);
//   }
// //   edges sort kiye 
//   sort(edges.begin(),edges.end());
//   vector<int> parent;
//   vector<int> rank;
//   makeSet(parent,rank,n);
//   int cost=0;
//   vector<pair<int,int>> mst;
//   for(int i=0;i<edges.size();i++){
//     //   agar same component ko belong nahi karte to utha liye 
//       if(findParent(edges[i][1],parent)!=findParent(edges[i][2],parent)){
//           cost+=edges[i][0];
//         //   ye union waali step nahi bhoolna
//           un(edges[i][1],edges[i][2],parent,rank);
//       }
//   }
//   cout<<cost<<"hello";
// return 0;
// }



// //////Kruskals Algorithm
// ////////////////////////////////////////


// ////////////////////////////////////
// /////Bridge in a graph
// vector<pair<int,int>> ans;
// void solve(int node,int parent,vector<int> &vis,vector<int> &tin,vector<int> &lt,int &timer,vector<int> adj[]){
//     vis[node]=1;
//     // first time both of them are set to the same value
//     tin[node]=lt[node]=timer++;
//      for(int i=0;i<adj[node].size();i++){
//         // if both elements are the same just continue
//           if(adj[node][i]==parent) continue;
//         //   if the element has not been visited yet
//           if(!vis[adj[node][i]]){
//             solve(adj[node][i],node,vis,tin,lt,timer,adj);
//             // after the dfs is finished, we go back and check the adjacent lt[]
//             lt[node]=min(lt[node],lt[adj[node][i]]);
//     ///////// if lt[adj[node][i]]>tin[node] then there is a bridge in the graph////////////
//             if(lt[adj[node][i]]>tin[node]){
//                 ans.push_back({node,adj[node][i]});
//             }
//           } 
//         //   if the element is already visited
//            else{
//                 lt[node]=min(lt[node],tin[adj[node][i]]);
//             }
//      }
// }


// // we basically do a DFS traversal for all nodes
// int main(){
//     int n,e;
//     cin>>n>>e;
//     vector<int> adj[n];
//     for(int i=0;i<e;i++){
//         int u,v;
//         cin>>u>>v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }
//     // we take time of in array and lowest time array
//     vector<int> tin (n,-1);
//     vector<int> lt (n,-1);
//     vector<int> vis(n,0);
//     // timer to keep track of time the element was encountered
//     int timer=0;
//     for(int i=0;i<n;i++){
//         if(!vis[i]){
//             solve(i,-1,vis,tin,lt,timer,adj);
//         }
//     }
//     for(int i=0;i<ans.size();i++){
//         cout<<ans[i].first<<" bridges to "<<ans[i].second<<endl;
//     }
//     return 0;
// }

// /////////Bridge in a graph
// //////////////////////////////////////


// /////////////////////////////////
// /////Articulation Points in a graph

// int solve(int node,int parent,vector<int> &tin,vector<int> &lt,int timer,vector<int> adj[],vector<int> &vis,vector<int> &isArticulation){
//     vis[node]=1;
//     tin[node]=lt[node]=timer++;
//     int child=0;
//     for(int i=0;i<adj[node].size();i++){
//         if(adj[node][i]==parent) continue;
//         if(!vis[adj[node][i]]){
//             solve(adj[node][i],node,tin,lt,timer,adj,vis,isArticulation);
//             lt[node]=min(lt[node],lt[adj[node][i]]);
//             if(lt[adj[node][i]]>=tin[node] && parent!=-1){
//                 isArticulation[node]=1;
//             }
//             child++;
//         }else{
//             lt[node]=min(lt[node],tin[adj[node][i]]);
//         }
//     }
//     if(parent==-1 && child>1){
//         isArticulation[node]=1;
//     }

// }


// int main(){
//     int n,e;
//     cin>>n>>e;
//     vector<int> adj[n];
//     for(int i=0;i<e;i++){
//        int u,v;
//        cin>>u>>v;
//        adj[u].push_back(v);
//        adj[v].push_back(u);
//     }
//     vector<int> tin(n,-1);
//     vector<int> lt(n,-1);
//     vector<int> vis(n,0);
//     vector<int> isArticulation(n,0);
//     int timer=0;
//     for(int i=0;i<n;i++){
//         if(!vis[i]){
//             solve(i,-1,tin,lt,timer,adj,vis,isArticulation);
//         }
//     }
//     for(int i=0;i<isArticulation.size();i++){
//         if(isArticulation[i]==1){
//             cout<<i<<"ans"<<endl;
//         }
//     }
//     return 0;
// }


// ////////////////Articulation Point
// /////////////////////////////////////

// /////////////////////////////////////////
// /////////KOsaraju algorithm
// for strongly connected components(ek node se component ke saare nodes tak jaa sake)




// first we take topo sorting of graph 
// then create a new transpose list of the graph(u se v ko v se u karo sabme)
// then for each element of stack call the revdfs function(same as dfs bass pehli line me cout karna hai node)

// void dfs(vector<int> &vis,vector<int> adj[],stack<int> &st,int node){
//     vis[node]=1;
//     for(int i=0;i<adj[node].size();i++){
//         if(!vis[adj[node][i]]){
//             dfs(vis,adj,st,adj[node][i]);
//         }
//     }
//     st.push(node);
// }
// void revDfs(vector<int> &vis,vector<int> tra[],int node){
//     cout<<node<<" ";
//     vis[node]=1;
//     for(int i=0;i<tra[node].size();i++){
//         if(!vis[tra[node][i]]){
//             revDfs(vis,tra,tra[node][i]);
//         }
//     }
// }

// int main(){
//     int n,e;
//     cin>>n>>e;
//     vector<int> adj[n];
//     for(int i=0;i<e;i++){
//         int u,v;
//         cin>>u>>v;
//        adj[u].push_back(v);
//     }
//     stack<int> st;
//     vector<int> vis(n,0);
//     for(int i=0;i<n;i++){
//         if(!vis[i]){
//             dfs(vis,adj,st,i);
//         }
//     }
//     vector<int> tra[n];
//     for(int i=0;i<e;i++){
//         vis[i]=0;
//         for(int j=0;j<adj[i].size();j++){
//             tra[adj[i][j]].push_back(i);
//         }
//     }
//     while(!st.empty()){
//         int t=st.top();
//         st.pop();
//         if(!vis[t]){
//             cout<<"component: "<<endl;
//              revDfs(vis,tra,t);
//         }
//     }
//     return 0;
// }

// /////Kosaraju algo
// /////////////////////////////////


// /////////////////////////////////
// ///////////////Bellman Ford Algorithm


// ///used to detect negative cycle in a graph
// can be used to find shortest path if a negative cycle is not present

// arr={u,v,w};

	// int isNegativeWeightCycle(int n, vector<vector<int>> arr){
	//     // Code here
    //     vector<int> vis(n,INT_MAX);
    //     vis[0]=0;
    //     for(int i=1;i<=n-1;i++){
    //         for(int j=0;j<arr.size();j++){
    //             if(vis[arr[j][0]]!=INT_MAX && vis[arr[j][0]]+arr[j][2]<vis[arr[j][1]]){
    //                 vis[arr[j][1]]=vis[arr[j][0]]+arr[j][2];
    //             }
    //         }
    //     }
    //     for(int i=0;i<arr.size();i++){
    //                         if(vis[arr[i][0]]!=INT_MAX &&vis[arr[i][0]]+arr[i][2]<vis[arr[i][1]]){
    //                 return 1;
    //             }
    //     }
    //     return 0;
	    
	// }