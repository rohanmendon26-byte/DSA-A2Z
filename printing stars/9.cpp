#include<iostream>
using namespace std;

void print1(int n){
    for(int i=n;i>0;i--)
    {
        //space
        for(int j=0;j<i-1;j++){
            cout<<" ";
        }

        //star
        for(int j=0;j<(2*n+1)-(2*i);j++){
            cout<<"*";
        }

        //space
        for(int j=0;j<i-1;j++){
            cout<<" ";
        }
        cout<<endl;
        
    }
}

void print2(int n){
    for(int i=0;i<n;i++){
        
        //space
        for(int j=0;j<i;j++){
            cout<<" ";
        }

        //star
        for(int j=0;j<(2*n)-(2*i+1);j++){
            cout<<"*";
        }

        //space
        for(int j=0;j<i;j++){
            cout<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    print1(5);
    print2(5);
}

//     *    
//    ***
//   *****
//  *******
// *********
// *********
//  *******
//   *****
//    ***
//     *