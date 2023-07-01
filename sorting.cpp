#include<iostream>
#include<bits/stdc++.h>
using namespace std;


// ///////////////////selection sort 

// har iteration me minimum element waala idx find karenge then swap thst with the starting value and increment the pointer
// at the starting value
// O(n^2) thus slow


// int main(){
//     int arr[6]={2,7,4,1,5,3};
//     int j=0,i=0;
//     int temp=INT_MAX;
//     int idx=0;
//     while(i<6)
//     {
//         temp=INT_MAX;
//         j=i;
//         while(j<6){
//              if(temp>arr[j]){
//                 temp=arr[j];
//                 idx=j;
//              }
//             j++;
//         }
//          swap(arr[i],arr[idx]);
//        cout<<arr[i]<<" ";
//        i++;
//     }
//     return 0;
// }

// /////////////////////


// ////////////////////////////////


// ///////////////////////////////
// /////bubble sort
// loop karte jao aur agar current element aage waale element se bada hai to swap kardo
// isme ek pass me jo sabse bada element hai wo wo end me aa jaata hai
// har pass me list peeche se sort hote jaegi

// best case O(n) when list is already sorted
// worst case O(n^2)
// inplace and stable sorting algo
// int main(){
//     int arr[6]={2,7,4,1,5,3};
//     int n=6;
//     for(int i=0;i<n-1;i++){
//         int flag=0;
//        for(int j=0;j<n-1-i;j++){
//          if(arr[j]>arr[j+1]){
//             swap(arr[j],arr[j+1]);
//             flag=1;
//          }
//        }
//     //    agar ek bhi swap nahi hua hai to flag 0 rahega aur list poori sorted hogi to 
//     // aage loop karne ka matlab nahi hai
//        if(flag==0){
//         break;
//        }
//     }
//   for(int i=0;i<6;i++){
//     cout<<arr[i]<<" ";
//   }
//     return 0;
// }


// //////////////////////////////


//////////////////////////////////////////
// /////////////insertion sort


// assume karte hai ki initially 0th idx tak array sorted hai
// phir dheere dheere idx ko aage badhate hai aur wo element ko compare karte hai peeche
// sorted part se
// jab tak wo element se bade elemnt milte jae,wo elements ko ek place aage shift karte jaate hai

// best case O(n) when already sorted
// worst case O(n^2)

// int main(){
//     int arr[6]={2,7,4,1,5,3};
//     int n=6;
//    for(int i=1;i<6;i++){
//     // assume kiya 0th tak sorted hai to 1 se start kiya
//     int val=arr[i];
//     // idx jaha pe hole bana hai
//     int hole=i;
//     while(hole!=0 && arr[hole-1]>val){
//         // jab tak val chota hai
//         arr[hole]=arr[hole-1];
//         // hole bhi shift hota jaega
//         hole=hole-1;
//     }
//     arr[hole]=val;
//    }


//   for(int i=0;i<6;i++){
//     cout<<arr[i]<<" ";
//   }
//     return 0;
// }

// ////////////////////////////////



// ////////////////////
////////////Merge Sort

// isme recursion use hoga 
// sabse pehle do parts me divide karo mid leke phir recursively call maaro dono parts pe
// phir merge function call karo


// void merge(vector<int> &arr,int st,int end,int mid){
//     // do temp arrays lagenge left aur right parts ke liye
//     vector<int> a1,a2;
//     // left elements push
//     for(int i=st;i<=mid;i++){
//         a1.push_back(arr[i]);
//     }
//     // right elements push
//     for(int i=mid+1;i<=end;i++){
//         a2.push_back(arr[i]);
//     }
//     // main array me bharte jao compare karte hue
//     int i=0,j=0,k=st;
//     while(i<a1.size() && j<a2.size()){
//         if(a1[i]>a2[j]){
//             arr[k]=a2[j];
//             j++;
//         }else{
//             arr[k]=a1[i];
//             i++;
//         }
//         k++;
//     }
//     // agar left me bache ho
//     while(i<a1.size()){
//         arr[k]=a1[i];
//         i++;
//         k++;
//     }
//     // agar right me bache ho
//     while(j<a2.size()){
//         arr[k]=a2[j];
//         j++;
//         k++;
//     }
// }

// void solve(vector<int> &arr,int st,int end){
//     if(st>=end) return;
//     // mid nikala
//     int mid=st+ (end-st)/2;
//     // left portion pe call
//     solve(arr,st,mid);
//     // right portion pe call
//     solve(arr,mid+1,end);
//     // dono sorted portions ka merge
//     merge(arr,st,end,mid);
// }

// int main()
// {
//    int n=5;
//    vector<int> arr={4,3,2,5,1};
//     solve(arr,0,n-1);
//     for(int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }
// }


// /////////////////////////////////////////
// ///////////////////////////////////////