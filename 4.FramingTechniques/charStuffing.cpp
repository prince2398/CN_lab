#include <iostream>

using namespace std;

int main(){
    char s[50], data[100];
    int m,n;

    cout<<"Enter the length of the string: ";
    cin>>n;
    cout<<"Enter the characters in a String: "<<endl;
    for (int i = 0; i < n; i++){
        cin>>s[i];
    }

    data[0] = 'D';
    data[1] = 'L';
    data[2] = 'E';
    data[3] = 'S';
    data[4] = 'T';
    data[5] = 'X';
    m = 6;
    for (int i=0, j=6; i < n; i++){
        if (s[i] == 'D' && 
            s[i + 1] == 'L' && 
            s[i + 2] == 'E'){

            data[j++] = 'D';
            data[j++] = 'L';
            data[j++] = 'E';
            data[j++] = 'D';
            data[j++] = 'L';
            data[j++] = 'E';
            i += 3;
            m += 6;
        }else{
            data[j++] = s[i];
            m++;
        }
    }

    data[m++] = 'D';
    data[m++] = 'L';
    data[m++] = 'E';
    data[m++] = 'E';
    data[m++] = 'T';
    data[m++] = 'X';

    for (int i = 0; i < m; i++){
        cout<<data[i]<<" ";
    }
    cout<<endl;

    return 0;
}