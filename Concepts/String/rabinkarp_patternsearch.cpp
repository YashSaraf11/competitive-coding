

#include<bits/stdc++.h>
using namespace std;

vector<int> RabinKarp(string s,string p){
     
    return {};
}
int main(){
    //taking input for the string and pattern to match
    string s,p;
    cout<<"Enter the string:";
    cin>>s;
    cout<<"Enter the pattern:";
    cin>>p;

    vector<int> pos = RabinKarp(s,p);
    if(pos.size()>0){
        cout<<"The position that the pattern matched are: ";
        for(int i:pos)
            cout<<i<<" ";
    }
    else{
        cout<<"The pattern didn't matcht the string";
    }
    return 0;
}