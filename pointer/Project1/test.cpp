#include<iostream>

using namespace std;

struct Base {

    int a;
    int b;
    int c;
};

class Base02
{
public:
    Base02() {


    }

};


void modifyVal(int x, int y)
{
    int tmp = x+y;
    x = y;
    y = tmp;
}

// 
void modifyPtr(int* p1, int* p2)
{
    *p1 += *p2;
}

void modifyRef(int &x,int &y, Base &be)
{
    be.a = x;
    be.b = y;
    be.c = be.a+be.b;
    int temp = x;
    x = y;
    y= temp;
}

int main()
{
	int a, b;
	a = 10, b = 20;


    modifyVal(a, b);
    std::cout << "a = " << a << "\nb = " << b << std::endl;

    
    modifyPtr(&a, &b);
    std::cout << "a = " << a << "\nb = " << b << std::endl;

    Base be{};

    modifyRef(a, b, be);
    std::cout << "a = " << a << "\nb = " << b << std::endl;
    std::cout << "be.a = " << be.a << "\nbe.b = " << be.b << "\nbe.c = " <<be.c<< std::endl;
    return 0;
}