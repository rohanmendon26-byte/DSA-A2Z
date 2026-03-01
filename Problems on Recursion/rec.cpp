
#include<iostream>
using namespace std;

//Print the name n times

// void f(int i,int n){
//     if(i>n)
//        return;
//     cout<<"Rohan"<<endl;
//     f(i+1,n);
// }
// int main()
// {
//     int n;
//     cout<<"Enter the number of times you want to print your name?";
//     cin>>n;
//     f(1,n);
//     return 0;
// }

//print linearly from 1 to n

// void f(int i,int n){
//     if(i>n)
//       return;
//     cout<<i<<" ";
//     f(i+1,n);
// }
// int main()
// {
//     int n;
//     cout<<"Enter the number:";
//     cin>>n;
//     f(1,n);
//     return 0;
// }


//Print the term from N to 1

// void f(int n,int i){
//     if(n<i)
//       return;
//     cout<<n<<" ";
//     f(n-1,i);
// }

// int main(){
//     int n;
//     cout<<"Enter a number:";
//     cin>>n;
//     f(n,1);
// }


//Print the term from 1 to n using backtracking

// void f(int i){
//     if(i<1)
//       return;
//     f(i-1);
//     cout<<i<<" ";
// }

// int main(){
//     int n;
//     cout<<"Enter a number:";
//     cin>>n;
//     f(n);
// }


//Print the term from n to 1 using backtracking
void f(int n,int i){
    if(n<1)
      return;
    f(n-1,i+1);
    cout<<i<<" ";
}

int main(){
    int n;
    cout<<"Enter a number:";
    cin>>n;
    f(n,1);
}


