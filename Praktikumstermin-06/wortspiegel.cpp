#include <iostream>
using namespace std;

char getSelection();
void spiegeln(string &, int);

void wortspiegel(string &text, int pos)
{
    char selection;
    do
    {
        cout << endl
             << text << endl; 
        for (int i = 0; i < pos; i++)
        {
            cout << " "; //Leerzeichen printen bis man zur gewünschten Stelle kommt
        }
        cout << "*" << endl;
        selection = getSelection(); //Funktion um das Wort an der ausgewählten Stelle zu bekommen
        if (selection == 'l' && pos > 0)
        {
            pos--;
        }
        else if (selection == 'r' && pos < text.length() - 1)
        {
            pos++;
        }
        else if (selection == 's')
        {
            spiegeln(text, pos);
        }
    } while (selection != 'q');
}

char getSelection()
{
    char selection;
    cout << "Befehl (l: links, r: rechts, s: spiegeln, q: Ende) ?-";
    cin >> selection;
    return selection;
}

void spiegeln(string &text, int pos)
{
    int currentIndex = pos;
    if (text[currentIndex] == ' ')
    {
        return; // Falls die Position an der wir sind ein Leerzeichen ist soll nichts passieren
    }
    else
    {
        int fromPos = 0, toPos = 0; // Deklaration der Positionen des Starts und Endbuchstabens von was gespiegelt werden soll
       
        //Linken Anfangsbuchstaben finden       
        while (text[currentIndex] != ' ' && currentIndex != 0 && text[currentIndex] != '.')
        {
            currentIndex--; // In dieser While Schleife wird solange nach links gegangen bis ein Leerzeichen, ein Punkt oder der Anfang des Satzes kommt
        }
        if (currentIndex != 0)
        {
            fromPos = currentIndex + 1; // Falls wir nicht am Anfang des Satzes sind müssen wir einen Schritt nach rechts gehen um den Anfang des Wortes zu finden
        }
        else
        {
            fromPos = currentIndex; //Wenn wir ganz am Anfang des Satzes sind müssen wir natürlich nicht eins nach rechts gehen 
        }


        //Rechter Endbuchstaben finden
        if (currentIndex != text.length() - 1) //Wenn wir nicht am Ende des Satzes sind gehen wir eins weiter nach rechts um so beim suchen des nächsten Leerzeichens nicht das bereits gefundene vor dem Wort nehmen
        {
            currentIndex++;
        }

        while (text[currentIndex] != ' ' && text[currentIndex] != '.' && currentIndex != text.length() - 1)
        {
            currentIndex++; // In dieser While Schleife wird solange nach rechts gegangen bis wir am Ende des Wortes oder Satzes angekommen sind.
        }
        if (text[text.length() - 1] != '.' && currentIndex == text.length() - 1) //Das tritt ein wenn der Satz nicht mit einem Punkt beendet wird und auch kein Leerzeichen hinten dran ist
        {
            toPos = currentIndex; //Hier wird dann die letzte Position im Text ausgewählt
        }
        else
        {
            toPos = currentIndex - 1; //Ansonsten wird ein Leerzeichen oder Punkt ausgwählt
        }



        while (fromPos < toPos)
        { // Ringtausch der Buchstaben um den String zu reversen
            char temp = text[toPos];
            text[toPos] = text[fromPos];
            text[fromPos] = temp;
            fromPos++;
            toPos--;
        }
    }

    return;
}
