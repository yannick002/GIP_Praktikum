#include <iostream>
using namespace std;

int main() {

    /*{//Aufgabe a)
    double tempInCel = 0, tempInFahr = 0;
    cout<<"Bitte geben Sie die Temperatur in Grad Celsius ein: ? ";
    cin>> tempInCel;
    tempInFahr = tempInCel*1.8+32;
    cout<<"Die Temperatur in Fahrenheit lautet: "<<tempInFahr<<endl;
    }*/

    /*{//Aufgabe b)
    double lengthInMeter = 0, lengthInFeet = 0;
    cout<<"Bitte geben Sie die Laenge in Metern ein: ? ";
    cin>>lengthInMeter;
    lengthInFeet = lengthInMeter*3.2808;
    cout<<"Die Laenge in Fuss lautet: "<<lengthInFeet<<endl;
    }*/

    /*{//Aufgabe c)
    double amountInEuro = 0, amountInDollar =0;
    cout<<"Bitte geben Sie die Geldmenge in Euro ein: ? ";
    cin>>amountInEuro;
    amountInDollar = amountInEuro*1.2957;
    cout<<"Die Geldmenge in US Dollar lautet: "<<amountInDollar<<endl;
    }*/

    /*{//Aufgabe d)
    double input = 0;
    int choice = 0;
    cout<<"Ihre Eingabe: ? ";
    cin>>input;
    cout<<"Ihre Auswahl in der Umwandlung: "<< endl <<"1 - Celsius in Fahrenheit"<<endl<< "2 - Meter in Fuss"<<endl<<"3 - Euro in US Dollar"<<endl;
    cin>>choice;
    double amountInDollar = 0;
    double lengthInFeet = 0;
    double tempInFahr = 0;
    amountInDollar = input * 1.2597;
    lengthInFeet = input*3.2808;
    tempInFahr = input*1.8+32;
    double result = (2-choice)*(3-choice)*(((tempInFahr)/2))+(1-choice)*(3-choice)*((lengthInFeet)*(-1))+(1-choice)*(2-choice)*((amountInDollar)/2);
    cout<<"Das Ergenis lautet: "<<result<<endl;
    }*/

    {//Aufgabe e)
    char input;
    cout<<"Bitte geben Sie den Buchstaben ein: ? ";
    cin>>input;
    int pos = input - 96;
    cout<<"Der Buchstabe hat die Position "<<pos<<" im Alphabet."<<endl;
    }

    return 0;

}