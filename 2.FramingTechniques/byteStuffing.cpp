#include <iostream>

using namespace std;
int main(){
    int i, j, k, data[100], n;

    cout<<"Enter size of frame: ";
    cin>>n;
    cout<<"Enter data in frame in binary format: "<<endl;
    for (i = 0; i < n; i++){
        cin>>data[i];
    }

    cout<<"Entered data is: "<<endl;
    for (int i = 0; i < n; i++){
        cout<<data[i]<<" ";
    }
    cout<<endl;

    for (int i = 0; i < n; i++){
        if (data[i] == 0 && 
            data[i + 1] == 1 && data[i + 2] == 1 && data[i + 3] == 1 && 
            data[i + 4] == 1 && data[i + 5] == 1 && data[i + 6] == 1 && 
            data[i + 7] == 0){

            i = i + 8;
            for (j = i + 8; j >= i; j--){
                data[j + 8] = data[j];
                n++;
            }
            for (int k = 0; k < 8; k++){
                if (k == 0 || k == 7){
                    data[i] = 0;
                }
                else{
                    data[i] = 1;
                }
                i++;
            }
        }
    }

    cout<<"The data with after Byte Stuffing: "<<endl;
    cout<<"0 1 1 1 1 1 1 0 ";
    for (int i = 0; i < n - 1; i++)
    {
        cout<<data[i]<<" ";
    }
    cout<<"0 1 1 1 1 1 1 0"<<endl;
    
    return 0;
}