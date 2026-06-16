#include <iostream>
using namespace std;
int main() {
    int input[5] = {0};
    int k = 0;
    int max = 0;
    for(int i = 0; i<5; i++){
        while(k<1 || k>9){ //Schauen ob k zwischen 1 und 9 liegt
            cout<<"Bitte geben Sie die "<<i+1<<". Zahl ein: ? ";
            cin>>k;
        }
        if(k>max){
            max = k; //max Zahl finden
        }
        input[i] = k;
        k = 0;
    }

    
    for(int i = 0; i<5; i++){
        cout<<i+1;
        for(int l = 0; l<input[i]; l++){ //Schleife die so lang wie der aktuelle Eintrag ist
            cout<<"*"; 
        }
        cout<<endl;
    }
    cout<<" "; //letzte Zeile darstellen
    for(int i = 1; i<=max; i++){
        cout<<i;
    }
    cout<<endl;
    return 0;
}