#include <iostream>
#include <string>
#include <fstream>
#include "personen.h"
using namespace std;

string br(string s);
string b(string s);
string ersetze(string, char, string);

int main() {
    string eingabezeile = "", kurztext = "", langtext = "";
    fstream newfile, newfile2;

    newfile.open("personendaten.txt", ios::in);
    //WICHTIG!!!: Das Terminal über den das Programm kompliert und ausgeführt wird MUSS im gleichen Verzeichnis wie die Text und HTML Dateien sein, sonst findet er die Dateien nicht
    //cout << "File opened successfully. Reading lines:" << endl;

    while (getline(newfile, eingabezeile)) {
        Person p = extrahiere_person(eingabezeile); //Da werden aus dem Eingabzeilen String der Vorname usw rausgelesen
        kurztext += br(b(p.name) + ", " + p.vorname)+"\n"; //Hier wird der nötige HTML Krams hinzugefügt
        langtext += br(b(p.vorname+ " "+p.name)+", "+ p.geburtstag)+"\n";
    }
    newfile.close();

    newfile.open("webseite.html", ios::out);
    newfile2.open("webseite.html.tmpl", ios::in);


    while(getline(newfile2, eingabezeile)){
        eingabezeile = ersetze(eingabezeile, '%', kurztext); //Hier wird jedes mal wenn ein % vorkommt ein kurztext in die eingazeile ergänzt, dadurch ersetzten wir % mit dem kurztext
        eingabezeile = ersetze(eingabezeile, '$', langtext); 
        newfile << eingabezeile+'\n';
    }
   
    newfile.close();
    newfile2.close();

    return 0;
}

string br(string s){ //br macht Break Line
    return (s+="<br/>");
}

string b(string s){ //b macht Bold
    return("<b>"+s+"</b>");
}

string ersetze(string s, char symbol, string k){//Ersetzt in einem String s ab einem char symbol den String mit k
    string helper;
    for(int i = 0; i<s.length(); i++){
        if(s[i] == symbol){
            helper+=k;
            continue;
        }
        helper += s[i];
    }
    return helper;
}


///Users/yannick/Universität/FH Aachen/VSCode/Praktikumstermin-07/