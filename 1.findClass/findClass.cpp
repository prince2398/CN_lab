#include <bits/stdc++.h>

using namespace std;

int main(){
    char ip[15];
    cout<<"Enter IP address: ";
    cin>>ip;
    stringstream sin(strtok(ip,"."));
    int x;
    sin>>x;
    cout<<"Your IP address is of Class ";
    if (x >= 0 && x <128){
        cout<<'A';
    }else if(x<192){
        cout<<'B';
    }else if(x<224){
        cout<<'C';
    }else if(x<240){
        cout<<'D';
    }else if(x<=256){
        cout<<'E';
    }else{
        cout<<"Wrong IP";
    }
    cout<<'.'<<endl;
    return 0;
}