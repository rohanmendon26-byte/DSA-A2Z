#include<iostream>
using namespace std;
int main()
{
    string s;
    cout<<"Enter the string"<<endl;
    cin>>s;

    //precompute
    int hash[256]={0};
    for(int i=0;i<s.size();i++){
        hash[s[i]]+=1;
    }

    int q;
    cout<<"Enter the query";
    cin>>q;
    while(q--){
        char c;
        cout<<"enter the character"<<endl;
        cin>>c;
        cout<<hash[c]<<endl;
    }
    return 0;
}