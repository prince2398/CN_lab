#include<bits/stdc++.h>
using namespace std;

/* stop and wait*/
int main(){
    int n;
    cout<<"Enter the number of frames: ";
    cin>>n;
    cout<<endl;
    for (int i=0; i<n; i++){
        cout<<"Sender Side:"<<endl;
        cout<<"Sending Frame... "<<(i%2)<<endl<<endl;
        cout<<"Receiver Side:"<<endl;
        cout<<"Did you receive the frame? (y or n) ";
        char ch;
        cin>>ch;
        if(ch == 'y'){
            cout<<"Frame Received" << endl;
            cout<<"Sending Acknowledgement for frame " 
                << !(i%2) << endl<<endl;
            cout<<"Sender Side:" << endl;
            cout<<"Did you receive the acknowledgement? (y or n) ";
            cin>>ch;
            if(ch == 'y'){
                cout<<"Acknowledgement Received!  ";
                cout<<"Successful Transmission"<<endl<<endl;
            }else{
                cout<<"TimeOut!"<<endl;
                cout<<"Acknowledge not received"<<endl;
                cout << "Retransmitting"<<endl;
                i--;
            }

        }else{
            cout<<"Frame Not Received!"<<endl<<endl;
            cout<<"Sender Side:"<<endl;
            cout<<"TimeOut!"<<endl;
            cout<<"Acknowledge not received"<<endl;
            cout<<"Retransmitting"<<endl;
            i--;
        }

        cout << "-------------------------------------------------------------" << endl;
    }

    return 0;
}
