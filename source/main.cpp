#include "ReplacementHandler.h"
#include <iostream>
#include <cstdint>

using namespace std;

void test_PLRU(){
	try
	{
		ReplacementHandler* h = new ReplacementHandler ((unsigned char)3,(unsigned char)1,(unsigned char)17,PLRU);
		unsigned char a;
		h->updateStatistics(12,3);
		h->updateStatistics(12,2);
		h->updateStatistics(12,1);
		a = h->findVictim(12);
		cout << "Hello World!\n"; 
		cout << "Call find victim -> "<<(int)a<<endl; 
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}  
}


void test_LFU(){
	ReplacementHandler* h = new ReplacementHandler (3,1,4,LFU);
    unsigned char a;
    a = h->findVictim(12);
    cout << endl;
    h->updateStatistics(12, a);
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
	test_PLRU();
	//cout << endl;
	//test_LFU();
	//test_RND();
	return 0;
}







