#include "binaerer_suchbaum.h"
#include <iostream>
using namespace suchbaum;

void suchbaum::einfuegen(BaumKnoten *&elternKnoten, int wert)
{
    BaumKnoten *knt = new BaumKnoten;
    if (elternKnoten == nullptr)
    {
        elternKnoten = knt;
        elternKnoten->data = wert;
        elternKnoten->elternKnoten = nullptr;
        elternKnoten->kindKnotenLinks = nullptr;
        elternKnoten->kindKnotenRechts = nullptr;
    }
    else
    {
        knt = elternKnoten;
        bool runLoop = true;
        while (runLoop)
        {
            if (knt->data == wert)
            {
                return;
            }
            else if (knt->data > wert)
            {
                if (knt->kindKnotenLinks == nullptr)
                {
                    //Um hier zu verkürzen könnte man einen Default Konstruktor in das Struct einbauen
                    knt->kindKnotenLinks = new BaumKnoten;
                    knt->kindKnotenLinks->data = wert;
                    knt->kindKnotenLinks->elternKnoten = knt;
                    knt->kindKnotenLinks = nullptr;
                    knt->kindKnotenRechts = nullptr;
                    break;
                }else if(knt->kindKnotenLinks !=nullptr){
                    knt = knt->kindKnotenLinks;
                }
            }else if(knt->data < wert){
                if(knt->kindKnotenRechts == nullptr){
                    knt->kindKnotenRechts = new BaumKnoten;
                    knt->kindKnotenRechts->data = wert;
                    knt->kindKnotenRechts->elternKnoten = knt;
                    knt->kindKnotenLinks = nullptr;
                    knt->kindKnotenRechts = nullptr;
                    break;
                }else if (knt->kindKnotenRechts!=nullptr)
                {
                    knt->kindKnotenRechts;
                }
                
            }
        }
    }
}


//To-Do: Boolean einfügen ob Knoten bereits besucht wurde, wenn ja dann nicht nochmal besuchen und vorherigen Knoten ausgeben. Sonst funtkioniert die Schei--benkleister nicht.
void suchbaum::ausgeben(BaumKnoten *Knoten){
    if(Knoten->elternKnoten!=nullptr){
        ausgeben(Knoten->elternKnoten);
    }else{
        if(Knoten->kindKnotenRechts!=nullptr){
            ausgeben(Knoten->kindKnotenRechts);
        }else if()
    }
}
