#include <string>
#include "personen.h"
#include <iostream>
using namespace std;
string trimme(string);

Person extrahiere_person(std::string eingabezeile){
    int kommaCount = 0;
    Person p;
    for(int i = 0; i<eingabezeile.length(); i++){//Je nachdem wie viele Kommas wir haben wissen wir ja ob wir Nachname, Vorname oder Geburtstag haben
        if(eingabezeile[i] == ','){
            kommaCount++;
            continue;
        }
        if(kommaCount == 0){
            p.name += eingabezeile[i];
        }else if(kommaCount == 1){
            p.vorname += eingabezeile[i];
        }else if(kommaCount == 2){
            p.geburtstag += eingabezeile[i];
        }
    }
    p.name = trimme(p.name); //Leerzeichen entfernen
    p.vorname = trimme(p.vorname);
    p.geburtstag = trimme(p.geburtstag);
    return p;
}

string trimme(string s){ //Theoretisch könnte man die Funktion noch anpassen dass s als Referenzparameter übergeben wird und auch noch auslagern in eine header Datei aber naja
    string output = "";
    int startpos = 0;
    int endpos = 0;
    for(int i = 0; i<s.length(); i++){
        if(s[i] != ' '){  //Hier werden Leerzeichen am Anfang und am Ende des Strings entfernt
            startpos = i;
            break;
        }
    }
    for(int i = s.length()-1; i>0; i--){
        if(s[i]!= ' '){
            endpos = i;
            break;
        }
    }
    if(startpos == endpos){
        return output;
    }
    for(int i = startpos ; i<=endpos; i++){
        output+=s[i];
    }
    
    return output;
}

