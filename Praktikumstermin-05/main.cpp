#include <iostream>
#include <string>
using namespace std;

char hauefigster_Buchstabe(string nachricht)
{
    const int alphabet_length = 26; //Konstante Variable die die Größe des Alphabets speichert.
    int maxVorkommen = 0; //Wie häufig der am häufigsten Vorkommende Buchstabe ist.
    int stelle = 0; //An welcher Stelle im haeufigkeit Array der Buchstabe der am meisten vorkommt ist.
    int haeufigkeit[alphabet_length] = {0}; //Das hier ist ein Array das abspeichert wie häufig jeder Buchstabe vorgekommen ist. Dabei ist Array Position 0 wie häufig A vorgekommen ist, Position 1 wie häufig B vorgekommen ist, Position 2 wie häufig C vorgekommen ist usw.
    for (int i = 0; i < nachricht.length(); i++)//Diese Schleife läuft über die gesamte Nachricht um so rauszufinden wie häufig jeder Buchstabe vorgekommen ist.
    {
        if (nachricht[i] >= 'A' && nachricht[i] <= 'Z') //Wir wollen natürlich nur überprüfen welche Buchstaben am häufigsten vorkommen, alle anderen Zeichen aber ignorieren, deswegen eine If Bedinung um nur Großbuchstaben rauszusortieren
        {
            haeufigkeit[nachricht[i] - 'A']++; //Um jetzt die Zuteilung im Array vorzunehmen (Also A=0, B=1 usw.) wird der Ascii Code vom Buchstaben an der Stelle nachricht[i] von 'A' abgezogen.
            //Bsp: B ist ja 66. Wenn jetzt also an der Stelle nachricht[i] B steht, rechnen wir 66 - 65, was gleich 1 ist. Damit stimmt die Zuordnung im Array haeufigkeit und wir erhöhen das Vorkommen von B um 1 im Array haeufigkeit
            if (haeufigkeit[nachricht[i] - 'A'] >= maxVorkommen) //Hier wird geschaut ob die Häufigkeit vom Buchstaben jetzt größer als maxVorkommen ist. Das wird gemacht um maxVorkommen immer aktuell zu halten. In Kombination mit der Stelle die wir uns weiter unten auch merken können wir damit genau sagen welcher Buchstabe am häufigsten vorkommt.

            {
                maxVorkommen = haeufigkeit[nachricht[i] - 'A'];
                stelle = nachricht[i] - 'A'; 
            }
        }
    }
    cout << "Der haeufigste Buchstabe ist: " << char(stelle + 'A') << " mit " << maxVorkommen << " Vorkommnissen." << endl; //Kurze Kontrollausgabe ob wir auch den richtigen Buchstaben haben
    return char(stelle + 'A'); //Rückgabe von dem am häufigsten vorkommenden Buchstaben
}

int findeSchluessel(char buchstabe)
{
    cout << "Der Schlüssel ist: " << buchstabe - 'E' << endl; //Da bekannt ist dass der am häufigste vorkommenste Buchstaben im Deutschen E ist, wissen wir nun dass der Buchstabe den wir gefunden haben eigentlich 'E' entspricht.
    //Mit der Information können wir den Schlüssel durch Subtraktion rausfinden und im nächsten Schritt zurückgeben
    return buchstabe - 'E';
}
string entschluesseleNachricht(string nachricht, int schluessel)
{
    //Mit dem Schlüssel kann jetzt die Botschaft einfach wieder zurückgeschoben werden.
    const int alphabet_length = 26;
    for (int i = 0; i < nachricht.length(); i++)
    {
        if (nachricht[i] >= 'A' && nachricht[i] <= 'Z') //Gleiche Überprüfung dass nur Buchstaben verschoben werden und keine Satzzeichen
        {   

            nachricht[i] = nachricht[i] - schluessel;
            if(nachricht[i]<'A'){
                nachricht[i]+=alphabet_length; //Falls beim Verschieben außerhalb des Alphabets geschoben wird muss wieder von 'Z' angefangen werden
                //Bsp: 'D' wird um 11 nach hinten verschoben. Durch 'D' = 68 landen wir bei 57, was einer '9' in der Ascii Tabelle entspricht. Um das zu verhindern
                //addieren wir nochmals die Länge des Alphabets. Dadurch wird 57 + 26 gerechnet und wir landen bei 'S', was die Korrekte Verschiebung ist.
            }
            
        }
    }
    return nachricht; //Die entschlüsselte Nachricht wird jetzt zurückgegeben
}

void ceaser_entschluesselung(string nachricht)
{
    char buchstabe = hauefigster_Buchstabe(nachricht); //Unterfunktionen um vorhandenen Code besser zu strukturieren
    int schluessel = findeSchluessel(buchstabe);
    string output = entschluesseleNachricht(nachricht, schluessel);
    cout<<"Die entschlüsselte Nachricht ist: "<<output<<endl;
}

int main()
{
    
    string nachricht = "OTP NLPDLC - GPCDNSWFPDDPWFYR(LFNS LWD NLPDLC - NSTQQCP, "
                       "NLPDLC - LWRZCTESXFD, NLPDLC - GPCDNSTPMFYR, GPCDNSTPMPNSTQQCP "
                       "ZOPC LWD PTYQLNSPC NLPDLC MPKPTNSYPE) TDE PTY PTYQLNSPD DJXXPECTDNSPD "
                       "GPCDNSWFPDDPWFYRDGPCQLSCPY, OLD LFQ OPC XZYZRCLASTDNSPY FYO "
                       "XZYZLWASLMPETDNSPY DFMDETEFETZY MLDTPCE. LWD PTYPD OPC PTYQLNSDEPY "
                       "FYO FYDTNSPCDEPY GPCQLSCPY OTPYE PD SPFEP SLFAEDLPNSWTNS OLKF, "
                       "RCFYOACTYKTATPY OPC VCJAEZWZRTP LYDNSLFWTNS OLCKFDEPWWPY. OPC "
                       "PTYQLNSSPTE SLWMPC HPCOPY ZQEXLWD YFC OTP 26 MFNSDELMPY OPD "
                       "WLEPTYTDNSPY LWASLMPED ZSYP FYEPCDNSPTOFYR GZY RCZDD - "
                       "FYO VWPTYMFNSDELMPY LWD LWASLMPE QFPC VWLCEPIE FYO RPSPTXEPIE GPCHPYOPE "
                       "FYO DZYOPCKPTNSPY, DLEKKPTNSPY FDH. YTNSE MPLNSEPE.";

    // Bitte f�gen Sie hier Ihren Code ein. Definieren Sie auch Funktionen, um Ihren Code besser zu strukturieren.
    ceaser_entschluesselung(nachricht);
    return 0;
}
