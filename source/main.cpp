#include "ReplacementHandler.h"
#include <iostream>
#include <cstdint>

using namespace std;

void test_PLRU(){
	try
	{
		ReplacementHandler* h = new ReplacementHandler ((unsigned char)3,(unsigned char)1,(unsigned char)17,PLRU_RH);
		unsigned char a;
		h->updateStatistics(12,3);
		h->updateStatistics(12,2);
		h->updateStatistics(12,1);
		a = h->findVictim(12); 
		cout << "Call find victim PLRU-> "<<(int)a<<endl; 
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}  
}


void test_LFU(){
	ReplacementHandler* h = new ReplacementHandler (3,1,4,LFU_RH);
    unsigned char a;
    a = h->findVictim(12);
    cout << endl;
    h->updateStatistics(12, a); 
    cout << "Call find victim LFU -> "<<(int)a<<endl;     
}

void test_RND(){
	ReplacementHandler* h = new ReplacementHandler (3,1,4,RND_RH);
    unsigned char a;
    a = h->findVictim(12);
    cout << endl;
    cout << "Call find victim Random -> "<<(int)a<<endl; 
}

int main()
{
	cout << endl;
	test_PLRU();
	
	test_LFU();
	test_RND();
	cout << endl;
	return 0;
}







