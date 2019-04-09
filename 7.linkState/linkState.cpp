#include<bits/stdc++.h>
using namespace std;

class compare{
    public:
        bool operator()(pair<int, int> child, pair<int, int> parent){
            return child.first > parent.first;
        }
};

vector<int> dijkstra(vector<vector<int> > &dMat, int node){
    vector<int> dist(dMat.size(), 10000);
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> q;
    q.push(make_pair(0, node));

    while(!q.empty()){
        int n = q.top().second;
        int d = q.top().first;
        q.pop();
        for(int i=1; i<dMat.size(); i++){
            if(dist[i] > d + dMat[n][i]){
                dist[i] = d + dMat[n][i];
                q.push(make_pair(dist[i], i));
            }
        }
    }
    return dist;
}

int main(){
    int n;
    cout<<"Enter the number of nodes in the network: ";
    cin>>n;
    vector<vector<int>> dMat(n+1, vector<int>(n+1, 10000));

    for(int i=1; i<=n; i++){
        int childs;
        cout<<endl;
        cout<<"Enter the number of nodes connected to node "<<i<<": ";
        cin>>childs;
        dMat[i][i] = 0;
        if(childs > 0){
            cout<<"Enter nodes and their distances "<<endl;
        }
        for (int j=0; j<childs; j++){
            int sibling;
            int distance;
            cin >> sibling >> distance;
            dMat[i][sibling] = distance;
            dMat[sibling][i] = distance;
        }
    }

    vector<vector<int> > dMatTemp = dMat;

    for (int i=1; i<=n; i++){
        vector<int> d = dijkstra(dMatTemp, i);
        dMat[i] = d;
    }
    
    cout<<endl;
    cout<<"Distance Matrix: "<<endl;
    for (int i=1; i<=n; i++){
        for (int j=1; j <=n;  j++){
            if(dMat[i][j] >= 10000)
                dMat[i][j] = -1;
            cout<<dMat[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
