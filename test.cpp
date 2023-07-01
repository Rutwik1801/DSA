#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

int solve(int x,int y,vector<vector<int>> arr){
  vector<pair<int,int>> x1;
  vector<pair<int,int>> y1;
  for(int i=0;i<arr.size();i++){
    if(arr[i][0]==1){
      x1.push_back({arr[i][2],arr[i][1]});
    }else{
      y1.push_back({arr[i][2],arr[i][1]});
    }
  }
  int ans=0;
  sort(x1.begin(),x1.end());
  sort(y1.begin(),y1.end());
  for(int i=x1.size()-1;i>=0;i--){
    if(x>=x1[i].second){
      ans+=x1[i].first;
      break;
    }
  }
    for(int i=y1.size()-1;i>=0;i--){
    if(y>=y1[i].second){
      ans+=y1[i].first;
      break;
    }
  }
  return ans;
}

int main(){
  int x,y;
  vector<vector<int>> arr={{1,2,3},{2,2,3},{1,4,5},{2,1,5}};
  cout<<solve(4,1,arr);
  return 0;
}