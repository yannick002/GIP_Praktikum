#include <iostream>
using namespace std;
#include "wortspiegel.h"

const int größeSudoku = 9; //Größe des Sudokus, aber leider nicht leicht skalierbar

void eingabe(int (&sudoku)[größeSudoku][größeSudoku]){
    string eingabe[größeSudoku +2] = { "" }; //Die vorgegebene Eingabe, ein String Arrray der Länge 11, das die Zeilen darstellt
    cout<<"Bitte geben Sie das Sudoku ein: "<<endl;
    for(int k = 0; k<sizeof(eingabe)/sizeof(string); k++){ //Eine Schleife die 11 Mal iteriert um das Array zu befüllen mit User Eingaben
        getline(cin, eingabe[k]);
    }

    //Das ganze nachfolgende Konstrukt ist dafür da um was in dem Eingabe String Array steht in das Sudoku Array zu übertragen
    //Dabei wird eine verschachtelte for Schleife verwendet um dadurch über jede Zeile und dann über jeden Character in dem in der Zeile zu findenden String zu iterieren
    //Die zwei Index Variablen sind nötig, da bei dem Sudoku Array andere Indexe nötig sind als beim String Array
    
    int row = 0, collumn = 0; //Indexe des 2 dimensionalen Arrays Sudoku in dem die Integer Werte abgespeichert werden
    for(int rowIndexStringArr = 0; rowIndexStringArr<sizeof(eingabe)/sizeof(string); rowIndexStringArr++){ //erste for Schleife iteriert über alle Zeilen
        for(int charIndexStringArr = 0; charIndexStringArr<eingabe[rowIndexStringArr].length(); charIndexStringArr++){ //zweite for Schleife iteriert über alle Charaktere in der Zeile
            if(eingabe[rowIndexStringArr].at(charIndexStringArr)>='1' && eingabe[rowIndexStringArr].at(charIndexStringArr)<='9'){ //Hier wird geschaut ob der Wert im String Array eine Zahl zwischen 1 und 9 ist
                sudoku[row][collumn] = eingabe[rowIndexStringArr].at(charIndexStringArr)-'0'; //Falls das der Fall ist wird der Wert in das Sudoku Array eingetragen
                collumn++;
                if(collumn>größeSudoku-1){
                    row++;
                    collumn=0;
                }
                //Das hier drüber ist nur um über das Sudoku Array zu iterieren
            }
        }
    }
    cout<<endl;
}

void ausgabe(const int (&sudoku)[größeSudoku][größeSudoku]){
    cout<<"Das Sudoku lautet:"<<endl;
    //Wieder vernestete For Schleife um über alle Elemnte der For Schleife zu iterieren
    for(int i = 0; i<größeSudoku; i++){
        if(i%3 == 0 && i>0){ //Wenn drei Zeilen abgearbeitet wurden soll so ein Trennungsding reinkommen
           cout<< "=======//=======//======="<<endl;
        }
        for(int j = 0; j<größeSudoku; j++){
             //Nach jeder dritten Zahl soll ein ";//;" eingefügt werden. Zwischen den einzelen Zahlen nur ein ";"
            if(j%3 == 0&&j>0){
                cout<<";//;";
            }else{
                cout<<";";
            }
            cout<<sudoku[i][j];
            
        }
        cout<<endl;
    }
}







int main() {
    int sudoku[größeSudoku][größeSudoku] = {0};
    eingabe(sudoku);
    ausgabe(sudoku);
    string input = "";
    cout<<"Bitte geben Sie den Text ein: ? ";
    getline(cin,input);
    wortspiegel(input, 0);
    return 0;
}








/*
.5.1.4.|.8.6.9.|.7.2.3
.8.7.2.|.3.4.5.|.6.1.9
.9.6.3.|.2.1.7.|.5.4.8
-------|-------|-------
.6.2.8.|.1.3.4.|.9.5.7
.1.9.7.|.6.5.2.|.8.3.4
.4.3.5.|.7.9.8.|.1.6.2
-------|-------|-------
.2.4.6.|.9.7.1.|.3.8.5
.7.5.1.|.4.8.3.|.2.9.6
.3.8.9.|.5.2.6.|.4.7.1
*/