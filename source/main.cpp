#include "ReplacementHandler.h"
#include <iostream>

int main()
{
	ReplacementHandler* h = new ReplacementHandler ((unsigned char)1,(unsigned char)1,(unsigned char)1,(unsigned char)2,PLRU);
    unsigned char a;
    a = h->findVictim(12);
    std::cout << "Hello World!\n"; 
    std::cout << "Call find victim -> "<<(int)a<<std::endl; 
}