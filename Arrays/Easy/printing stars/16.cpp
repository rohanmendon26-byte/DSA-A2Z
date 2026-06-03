#include<iostream>
using namespace std;
int main()
{
    int n=5;
    char num='A';
    for(int i=0;i<n;i++){
        for(char ch='A';ch<=num;ch++){
            cout<<num<<" ";
        }
        cout<<endl;
        num+=1;
    }
    return 0;
}


// A 
// B B 
// C C C 
// D D D D 
// E E E E E 