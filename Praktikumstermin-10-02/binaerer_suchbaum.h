#pragma once
namespace suchbaum
{
    struct BaumKnoten
    {
        int data;
        BaumKnoten *elternKnoten;
        BaumKnoten *kindKnotenLinks;
        BaumKnoten *kindKnotenRechts;

    };

    void einfuegen(BaumKnoten *&, int);
    void ausgeben(BaumKnoten *);
    
} // namespace suchbaum
