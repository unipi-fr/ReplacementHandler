#include "ReplacementHandler.h"
#include <iostream>
#include <cstdint>

using namespace std;

void test_PLRU(){
	ReplacementHandler* h = new ReplacementHandler ((unsigned char)3,(unsigned char)1,(unsigned char)4,PLRU);
    unsigned char a;
    a = h->findVictim(12);
    cout << "Hello World!\n"; 
    cout << "Call find victim -> "<<(int)a<<endl; 
}


void test_LFU(){
	ReplacementHandler* h = new ReplacementHandler (3,1,4,LFU);
    unsigned char a;
    a = h->findVictim(12);
    cout << endl;
    h->updateStatistics(12, a, false);
    cout << "Hello World!\n"; 
    cout << "Call find victim -> "<<(int)a<<endl;     
}

void test_RND(){
	ReplacementHandler* h = new ReplacementHandler (3,1,4,RND);
    unsigned char a;
    a = h->findVictim(12);
    cout << "Hello World!\n"; 
    cout << "Call find victim -> "<<(int)a<<endl; 
}

int main()
{
	//test_PLRU();
	//cout << endl;
	//test_LFU();
	test_RND();
	return 0;
}







