#include<iostream>
using namespace std;
int main()
{
    int n=5;
    for(int i=5;i>0;i--){
        for(char ch='A';ch<'A'+i;ch++){
            cout<<ch<<" ";
        }
        cout<<endl;
    }
}

// A B C D E 
// A B C D 
// A B C 
// A B 
// A 
