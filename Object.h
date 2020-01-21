//
//  Object.h
//  25205-SerhanSilahyurekli
//
//  Created by Serhan Silahyürekli on 25.11.2019.
//  Copyright © 2019 Serhan Silahyürekli. All rights reserved.
//

#ifndef Object_h
#define Object_h
using namespace std;
class Object
{
public:
    Object();
    Object(int start, int h,int l);
    Object(const Object & rhs);

    void operator = ( const Object & rhs);
    bool operator == (const Object & rhs) const;
    bool operator != (const Object & rhs) const;
    bool operator > (const Object & rhs) const;
    bool operator < (const Object & rhs) const;
    int getstartx();
    int getheight();
    int getlabel();
private:
    int start_x;
    int height;
    int label;
};

Object::Object()
{
    start_x = 0;//max number for unside integer
    height = 0;
    label = 0;
}
Object:: Object(int start, int h,int l)
{
    start_x = start;
    height = h;
    label = l;
}
Object::Object(const Object & rhs)
{
    start_x = rhs.start_x;
    height = rhs.height;
    label = rhs.label;
}
void Object::operator=( const Object &rhs)
{
    start_x = rhs.start_x;
    height = rhs.height;
    label = rhs.label;

}
bool Object:: operator ==(const Object & rhs) const
{
    if(height == rhs.height)
    {
        return true;
    }
    return false;
}
bool Object:: operator !=(const Object & rhs) const
{
    if(height != rhs.height)
    {
        return true;
    }
    return false;
}
bool Object:: operator >(const Object & rhs) const
{
    if(height > rhs.height)
    {
        return true;
    }
    return false;
}
bool Object:: operator <(const Object & rhs) const
{
    if(height < rhs.height)
    {
        return true;
    }
    return false;
}


int Object::getstartx()
{
    return start_x;
}
int Object::getheight()
{
    return height;
}
int Object::getlabel()
{
    return label;
}
#endif /* Object_h */
