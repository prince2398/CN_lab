#include <iostream>
#include <string>

using namespace std;

int main(){
    int a[20], b[30], k, n,i,j;

    cout<<"Enter size of frame: ";
    cin>>n;
    cout<<"Enter data in frame in binary format: \n";
    for (i = 0; i < n; i++){
        cin>>a[i];
    }

    int c = 1;
    for (i=0,j=0;i < n;i++,j++){
        if (a[i] == 1){
            b[j] = a[i];
            for (k = i + 1; (a[k] == 1) && (k < n) && (c < 5); k++){
                b[++j] = a[k];
                c++;
                if (c == 5){
                    b[++j] = 0;
                }
                i = k;
            }
        }else{
            b[j] = a[i];
        }
    }

    cout<<"After Bit Stuffing :\n";
    for (i = 0; i < j; i++){
        cout<<b[i]<<" ";
    }
    cout<<endl;

    return 0;
}