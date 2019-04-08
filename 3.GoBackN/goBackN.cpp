#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number of frames: ";
    cin>>n;

    int wSize;
    cout<<"Enter the window size: ";
    cin>>wSize;
    cout<<endl;

    int currFrame = 0;
    while(currFrame != n){
        cout<<"Sender Side: "<<endl;
        for(int i=currFrame; i<min(n, currFrame+wSize); i++){
            cout<<"Sending Frame "<<i<<"..."<<endl;
        }
        cout<<endl;

        cout<<"Receiver Side: "<<endl;
        vector<int> ACKs;
        for(int i=currFrame; i<min(n, currFrame+wSize); i++){
            char ch;
            cout<<"Did you receive Frame "<<i<<"? (y or n) ";
            cin>>ch;
            if(ch == 'n'){
                break;
            }else{
                cout<<"Frame Received"<<endl;
                cout<<"Sending ACK for frame "
                    <<i<<"..."<<endl;
                ACKs.push_back(i);
            }
        }
        cout<<endl;

        cout<<"Sender Side:"<<endl;
        int maxACK = currFrame - 1;
        for (int i=0; i<ACKs.size(); i++){
            char ch;
            cout<<"Did you receive the ACK for frame "
                <<ACKs[i]<<"? ";
            cin>>ch;
            if(ch == 'y'){
                maxACK = max(maxACK, ACKs[i]);
                cout<<"Successful Transmission for all frames till "
                    << ACKs[i] << endl;
            }
        }

        currFrame = maxACK + 1;
        cout << "---------------------------------------------------------------------" << endl;
    }
    return 0;
}
