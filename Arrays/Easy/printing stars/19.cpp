#include<iostream>
using namespace std;

void print1(int n){
    int inis=0;
    for(int i=0;i<n;i++){
        //stars
        for(int j=1;j<=n-i;j++){
            cout<<"*";
        }
        //spaces
        for(int j=0;j<inis;j++){
            cout<<" ";
        }
        //stars
        for(int j=1;j<=n-i;j++){
            cout<<"*";
        }
        inis+=2;
        cout<<endl;
    }  
}

void print2(int n){
    int inis=8;
    for(int i=1;i<=n;i++){
        //stars
        for(int j=1;j<=i;j++){
            cout<<"*";
        }

        //spaces
        for(int j=1;j<=inis;j++){
            cout<<" ";
        }

        //stars
        for(int j=1;j<=i;j++){
            cout<<"*";
        }
        inis-=2;
        cout<<endl;
    }
}
int main()
{
    print1(5);
    print2(5);
}

// **********
// ****  ****
// ***    ***
// **      **
// *        *
// *        *
// **      **
// ***    ***
// ****  ****
// **********