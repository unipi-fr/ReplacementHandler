#include "ReplacementHanler.h"
#include <iostream>

int main()
{
	ReplacementHandler* h = new ReplacementHandler ((unsigned char)1,(unsigned char)1,(unsigned char)1,(unsigned char)2,PLRU);
    std::cout << "Hello World!\n"; 
}