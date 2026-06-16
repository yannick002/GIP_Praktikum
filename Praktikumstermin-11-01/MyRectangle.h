#pragma once

class MyRectangle{
private:    
    int x1,y1,x2,y2;

public:
    MyRectangle();
    MyRectangle(int x1, int y1, int x2, int y2);
    
    int get_x1() const{return x1;};
    int get_x2() const{return x2;};
    int get_y1() const{return y1;};
    int get_y2() const{return y2;};
    void set_x1(int x1){this->x1 = x1;};
    void set_x2(int x2){this->x2 = x2;};
    void set_y1(int y1){this->y1 = y1;};
    void set_y2(int y2){this->y2 = y2;};
    void set(int x1, int y1, int x2, int y2);

    void draw();
    bool does_not_collide_with(const MyRectangle& other);

};