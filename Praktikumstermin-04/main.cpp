#include <iostream>
#include <time.h>
using namespace std;

void busfahrplan(){
    //Variablendeklaration
    int stundeStartuhrzeit = 0;
    int minStartuhrzeit = 0;
    int taktzeitInMin = 0;
    const int limitTakt = 180;
    const int limitMinute = 59;
    const int stundenTag = 24;
    const int limitStunde = stundenTag-1;

    //Input bekommen
    do{
        cout<<"Bitte geben Sie die Stunde der Startuhrzeit ein: ";
        cin>>stundeStartuhrzeit;
    }while (stundeStartuhrzeit<0 || stundeStartuhrzeit>limitStunde); //nochmalige Eingabe wenn negativ oder größer als 23
    do{
        cout<<"Bitte geben Sie die Minute der Startuhrzeit ein: ";
        cin>>minStartuhrzeit;
    }while (minStartuhrzeit<0 || minStartuhrzeit >limitMinute);//Die Schleife wird fortgesetzt wenn minStartuhrzeit kleiner als 0 und größer als 59 ist,
    //also genau dann wenn der Eingabewert außerhalb des gültigen Bereich liegt.
    cout<<"Der erste Bus faehrt also um "<<stundeStartuhrzeit<<":"<<minStartuhrzeit<<" Uhr"<<endl;
    do{
        cout<<"Bitte geben Sie die Taktzeit in Minuten ein: ";
        cin>>taktzeitInMin;
    }while(taktzeitInMin<0||taktzeitInMin>limitTakt); //nochmalige Eingabe wenn negativ oder größer als 180

   
    //Output
    while (stundeStartuhrzeit<stundenTag)
    {
        if(minStartuhrzeit<10){//Hier wird geschaut ob die Minute kleiner als 10 ist, also einstellig und dann eine 0 vorne angehängt,
        //aus ästhetischen Gründen
            cout<<stundeStartuhrzeit<<":"<<"0"<<minStartuhrzeit<<" ";

        }else{
            cout<<stundeStartuhrzeit<<":"<<minStartuhrzeit<<" ";
            
        }
        minStartuhrzeit += taktzeitInMin;
       
        if(minStartuhrzeit>=60){
            stundeStartuhrzeit+=minStartuhrzeit/60; //Stunde wir um die ganzzahl Division erhöht um auch wenn ein Takt > 60 eingegeben wurde die Stunden korrekt zu erhöhen
            cout<<endl; //Hier wird jede Stunde eine neue Zeile begonnen;
            minStartuhrzeit %= 60;
        } //Die Reihnfolge ist wichtig, da ansonsten 24:00 ausgegeben wird da es
        //ausgegeben wird bevor es durch die While Schleife überprüft wird

        
    }
}

void wuerfeln(){
    const int amountEyes = 30;
    int results[amountEyes] = {0};
    const int numRolls = 6000; 
    srand(time(NULL));
    for(int i = 0; i<numRolls; i++){
        int zufallszahl = (rand()%amountEyes);
        results[zufallszahl] = results[zufallszahl]+1;
    }
    for(int i = 0; i<amountEyes; i++){
        cout<<i+1<<"-er Wuerfe "<<results[i]<<" Der Prozentanteil ist: "<< results[i]/double(numRolls)*100<<"%"<<endl;
    }
}


int main() {
    //busfahrplan();
    wuerfeln();
    return 0;
}