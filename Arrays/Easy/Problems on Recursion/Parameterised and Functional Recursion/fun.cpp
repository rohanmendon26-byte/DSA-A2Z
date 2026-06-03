#include<iostream>
using namespace std;
int fn(int n){
    if(n==0){
        return 0;
    }
    return n+fn(n-1);
}
int main()
{
    int n;
    cin>>n;
    int a=fn(n);
    cout<<a;
    return 0;
}