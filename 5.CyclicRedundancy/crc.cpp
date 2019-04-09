#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number of bits in data: ";
    cin>>n;
    int data[2*n];
    cout<<"Enter the data (space separated bits):  ";

    for(int i=0 ; i<n; i++){
        cin>>data[i];
    }

    int m;
    cout<<"Enter the number of bits in generator polynomial: ";
    cin>>m;

    int genPol[m];
    cout<<"Enter the generator polynomial (space separated bits): ";
    for(int i=0; i<m; i++){
        cin>>genPol[i];
    }
    cout<<endl;
    
    int sz = n;
    int temp[n];
    for(int i=0; i<n; i++){
        temp[i] = data[i];
    }

    for(int i=0; i<m-1; i++){
        data[n++] = 0;
    }

    int rem[n+1];
    int quo[n+1];
    int jr = 0;
    int jq = 0;

    for(int i = 0; i < sz; ++i){
        int start = i;

        if(data[start] == 0){
            quo[jq++] = 0;
            continue;
        }
        quo[jq++] = 1;
        for(int k = 0 ; k < m; ++k){
            data[start] = data[start]^genPol[k];
            start++;
        }
    }

    cout<<"Quotient: ";
    for(int i = 0 ; i < jq; ++i){
        cout<<quo[i]<<" ";
    }
    cout<<endl;

    int i = 0;
    for(i=0; i<m-1; i++){
        rem[jr++] = data[i+sz];
    }

    cout<<"Remainder: ";
    for(i=0; i<jr; i++){
        cout<<rem[i]<<" ";
    }
    cout<<endl;

    for(i=0 ; i<sz; i++){
        data[i] = temp[i];
    }

    for(i=0 ; i<jr; i++){
        data[sz++] = rem[i];
    }

    cout<<"Encoded Data: ";
    for( i=0; i<sz; i++){
        cout<<data[i]<<" ";
    }
    cout<<endl;

    return 0;
}
