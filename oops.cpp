#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// empty class ko hamesha 1 byte of memory allocate ho jaati hai, baaki usme jitne properties hai utni 
// memory allocate hoti hai

// is class ko doosri flie se bhi import kart sakte hai #include "Hero.cpp"

// class Hero{
//     // properties
//     // public:
//     int health;
//     // private:
//     char level;
// };

// int main(){
//   Hero Ram;
// //   agar koi value pass nahi ki to garbage value store hogi
//  cout<<"size: "<<Ram.health<<endl;
//   cout<<"level: "<<Ram.level<<endl;
// // isme health and level are private members
//     return 0;
// }

// access mdifiers: 
// public: kahi bhi access,class ke andar and class ke bahar
// private: by default class me yahi laga hota hai...sirf class ke andar hi access hai
// protected:


// getter and setter

// class Hero{
//     // properties
//         private:
//     char level;
//     public:
//     int health;
// // getter use karte hai private access karne ke liye
//     char getLevel(char l){
//       return level;
//     }
//     // setter use karte hai private ki value set karne ke liye
//    void setLevel(char l) {
//      level=l;
//    }

// };

// int main(){
//   // static allocation
//   Hero Ram;
//    cout<<"size: "<<Ram.health<<endl;
//   cout<<"level: "<<Ram.getLevel('c')<<endl;
//   // dynamic allocation
//   Hero *b=new Hero;
//   // isme b address pe padi hui hai to uski value chahiye to dereference karna padega to (*b) hoga
//    cout<<"size: "<<(*b).health<<endl;
//   cout<<"level: "<<(*b).getLevel('c')<<endl;

//   // or

//      cout<<"size: "<<b->health<<endl;
//   cout<<"level: "<<b->getLevel('c')<<endl;

//     return 0;
// }



