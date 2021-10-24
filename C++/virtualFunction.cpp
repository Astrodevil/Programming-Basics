// Program to implement virtual function.

#include <iostream>

using namespace std;

class Base {
    public:
        void display() {
            cout<< "Display Base function.\n";
        }
        
        virtual void show() {
            cout<< "Show Base function.\n\n";
        }
};

class Derived: public Base {
    public: 
        void display() {
            cout<< "Display Base function.\n";
        }
        
        void show() {
            cout<< "Show Base function.\n";
        }
};

int main() {
    Base B;
    Derived D;
    Base *bptr;
    
    cout<<"bptr points to Base\n";
    bptr = &B;
    bptr->display();
    bptr->show();
    
    cout<<"bptr points to Derived\n";
    bptr = &D;
    bptr->display();
    bptr->show();
  
  return 0;
}