#pragma once

#include <iostream>
using std::ostream;

template<class T>
class Box
{
        T contents;
    public:
        Box(T newContents)
        : contents(newContents)
        {
        }
        
        void setContents(T newContents)
        {
            contents = newContents;
        }
        
        T getContents() const
        {
            return contents;
        }
        
        friend ostream& operator <<(ostream& out, const Box& src)
        {
            out << src.getContents();
            return out;
        }
    protected:
    private:
};
