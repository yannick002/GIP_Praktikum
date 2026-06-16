#include <iostream>
using namespace std;
int main()
{

   /*{//Aufgabe 01)
    int ersterTag = 0, ersterMonat = 0, erstesJahr = 0, zweiterTag = 0, zweiterMonat = 0, zweitesJahr = 0;

    cout<<"Bitte geben Sie den Tag des ersten Datums ein: ";
    cin>>ersterTag;
    cout<<"Bitte geben Sie den Monat des ersten Datums ein: ";
    cin>>ersterMonat;
    cout<<"Bitte geben Sie das Jahr des ersten Datums ein: ";
    cin>>erstesJahr;
    cout<<"Bitte geben Sie den Tag des zweiten Datums ein: ";
    cin>>zweiterTag;
    cout<<"Bitte geben Sie den Monat des zweiten Datums ein: ";
    cin>>zweiterMonat;
    cout<<"Bitte geben Sie das Jahr des zweiten Datums ein: ";
    cin>>zweitesJahr;

    if(erstesJahr>zweitesJahr){ //Hier wird mit dem Jahr angefangen um somit falls das schon zutrifft direkt die richtige Auswahlmöglichkeit zu haben
        cout<<"Das zweite Datum liegt vor dem ersten Datum."<<endl;
    }else if(erstesJahr<zweitesJahr){
        cout<<"Das erste Datum liegt vor dem zweiten Datum."<<endl;
    }else if(ersterMonat>zweiterMonat){
        cout<<"Das zweite Datum liegt vor dem ersten Datum."<<endl;
    }else if(ersterMonat<zweiterMonat){
        cout<<"Das erste Datum liegt vor dem zweiten Datum."<<endl;
    }else if(ersterTag>zweiterTag){
        cout<<"Das zweite Datum liegt vor dem ersten Datum."<<endl;
    }else if(ersterTag<zweiterTag){
        cout<<"Das erste Datum liegt vor dem zweiten Datum."<<endl;
    }else if(ersterTag == zweiterTag){
        cout<<"Beide Datumsangaben sind gleich."<<endl;
    }
    }//Aufgabe 01*/

   /* {//Aufgabe 02
    int min = 0, max = 0, posMax = 0, input = 0, posMin = 0;
    for(int i = 1; i<=5; i++){
        cout<<"Bitte geben Sie die "<<i<<". Zahl ein: ? ";
        cin>>input;
        if(i==1){ //Beim ersten Durchlauf muss min und max gleich Input gesetzt werden, da ansonsten das min oder max fälschlicherweise 0 bleibt auch wenn keine 0 eingegeben wurde
            min = input;
            max = input;
            posMax = i;
            posMin = i;
        }else{
            if(input>max){
                max = input;
                posMax = i;
            }else if(input<min){
                min = input;
                posMin = i;
            }
        }

    }
    cout<<"Die "<<posMin<<". Zahl war die kleinste der eingegebenen Zahlen und lautet: "<<min<<endl;
    cout<<"Die "<<posMax<<". Zahl war die größte der eingegebenen Zahlen und lautet: "<<max<<endl;
    }//Aufgabe 02*/

   { // Aufgabe 03
        int v = 0;
        const int laengeAlph = 26;
        string text = "";
        cout << "Bitte geben Sie den zu verschluesselnden Text ein: " << endl;
        getline(cin, text); //getline damit alles auch mit Leerzeichen eingelesen wird
        cout << "Bitte geben Sie die Anzahl Verschiebepositionen ein: " << endl;
        cin >> v;
        v %= 26; //Modulo 26 damit die Veschiebungsposition maximal so groß sein kann wie das Alphabet
        int letter; 
        int A = int('A');
        int a = int('a');
        int Z = int('Z');
        int z = int('z');
        for (int i = 0; i < text.length(); i++)
        {
            letter = int(text[i]);
            if(letter>=A && letter<=Z){ //Großbuchstaben
                letter += v; //Verschiebung
                if(letter>Z){
                    letter = letter -laengeAlph; //falls der Buchstabe außerhalb des Alphabets geht wird hier wieder von vorne angefangen
                }
            }
            if(letter>=a && letter<=z){ //Kleinbuchstaben
                if((letter+v)>z){ //hier muss erst überprüft werden ob der Buchstabe außerhalb des Alphabets liegt, da ansonsten die ASCII Tabelle überschritten wird und danach nicht mehr klar ist was passiert
                    letter = letter - laengeAlph;
                }
                letter +=v; //Verschiebung
            }
            cout<<char(letter);
        }
        cout<<endl; 
    } // Aufgabe 03
    return 0;
}