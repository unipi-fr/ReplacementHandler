#include "ReplacementHandler.h"
#include <iostream>
#include <cstdint>

using namespace std;

void test_PLRU(){
	ReplacementHandler* h = new ReplacementHandler ((unsigned char)1,(unsigned char)1,(unsigned char)2,PLRU);
    unsigned char a;
    a = h->findVictim(12);
    cout << "Hello World!\n"; 
    cout << "Call find victim -> "<<(int)a<<endl; 
}


void test_LFU(){
	ReplacementHandler* h = new ReplacementHandler (1,1,2,LFU);
    unsigned char a;
    a = h->findVictim(12);
    cout << "Hello World!\n"; 
    cout << "Call find victim -> "<<(int)a<<endl; 

     
}

int main()
{
	test_PLRU();
	cout << endl;
	test_LFU();
}







