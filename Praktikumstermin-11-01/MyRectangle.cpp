#include "MyRectangle.h"
#include "CImgGIP05.h"


MyRectangle::MyRectangle() :x1{0}, y1{0}, x2{20}, y2{20}{}//Default Konstruktor
MyRectangle::MyRectangle(int x1, int y1, int x2, int y2) : x1{x1}, y1{y1}, x2{x2}, y2{y2}{} //Konstruktor mit gegebenen Paramter

void MyRectangle::set(int x1, int y1, int x2, int y2)
{
    set_x1(x1);
    set_x2(x2);
    set_y1(y1);
    set_y2(y2);
}


void MyRectangle::draw()
{
    gip_draw_rectangle(get_x1(), get_y1(), get_x2(), get_y2(), blue);
}


bool MyRectangle::does_not_collide_with(const MyRectangle& other){
    int other_x1 = other.get_x1();
    int this_x1 = this->get_x1();
    int other_y1 = other.get_y1();
    int this_y1 = this->get_y1();
    int other_x2 = other.get_x2();
    int this_x2 = this->get_x2();
    int other_y2 = other.get_y2();
    int this_y2 = this->get_y2();

    if(this_x2 < other_x1 || other_x2 < this_x1){
        return true;
    }else if(this_y1>other_y2 || other_y1>this_y2){
        return true;
    }else
        return false;

}