#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number of nodes in the network: ";
    cin>>n;

    vector<vector<int>> distTable(n+1, vector<int> (n+1, 10000));
    for(int i=1; i<=n; i++){
        int childs;
        cout<<endl;
        cout<<"Enter the number of nodes connected to node "<<i<<": ";
        cin >> childs;
        distTable[i][i] = 0;
        if(childs>0){
            cout<<"Enter nodes and their distances: "<<endl;
        }
        for(int j = 0; j < childs; ++j){
            int sibling;
            int distance;
            cin >> sibling >> distance;
            distTable[i][sibling] = distance;
            distTable[sibling][i] = distance;
        }
    }

    bool done = false;

    while(!done){
        done = true;
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n ; j++){
                for(int k=1; k<=n; k++){
                    if(distTable[i][j] > (distTable[i][k]+distTable[k][j])){
                        distTable[i][j] = distTable[i][k] + distTable[k][j];
                        done = false;
                    }
                }
            }
        }
    }

    cout<<endl;
    cout<<"Distance Matrix: "<<endl;
    for(int i=1; i<=n ; i++){
        for (int j=1; j<=n ; j++){
            if(distTable[i][j] == 10000)
                distTable[i][j] = -1;
            cout<<distTable[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
