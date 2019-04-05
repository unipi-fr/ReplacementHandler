#include "ReplacementHanler.h"
#include <math.h>
#include <limits.h>

ReplacementHandler::ReplacementHandler(unsigned char numberOfAddressBits,unsigned char numberOfIndexBits, unsigned char numberOfOffsetBits, unsigned char nWayAssociative, PoliciesOffered policy) {
	_policy = policy;

	switch (policy)
	{
		case PLRU:
			PLRUSetUp(numberOfAddressBits,numberOfIndexBits,numberOfOffsetBits,nWayAssociative);
			break;
		case LFU:
			LFUSetUp(numberOfAddressBits,numberOfIndexBits,numberOfOffsetBits,nWayAssociative);
			break;
		default:
			//TODO: gestire l'errore
			break;
	}
	
}

/*Returns the cacheColumn where the victim was chosen*/
unsigned char ReplacementHandler::findVictim(unsigned short address) {
	switch (_policy)
	{
		case PLRU:
			return PLRUFindVictim(address);
			break;
		case LFU:
			return LFUFindVictim(address);
			break;
		default:
			//TODO: gestire l'errore
			break;
	}
}

void ReplacementHandler::notifyOperation(unsigned short address, unsigned char cacheColumn){
	switch (_policy)
	{
		case PLRU:
			PLRUNotifyOperation(address,cacheColumn);
			break;
		case LFU:
			LFUNotifyOperation(address,cacheColumn);
			break;
		default:
			//TODO: gestire l'errore
			break;
	}
}

void ReplacementHandler::PLRUSetUp(unsigned char numberOfAddressBits,unsigned char numberOfIndexBits, unsigned char numberOfOffsetBits, unsigned char nWayAssociative){
	if(numberOfIndexBits > UCHAR_MAX - numberOfOffsetBits){
		//TODO: gestire errore overflow della somma
		return;
	}
	if (numberOfAddressBits <= numberOfIndexBits + numberOfOffsetBits) {
		//TODO: gestire errore "il numero dei bit offset+index supera i bit dell'indirizzo"
		return;
	}
	_sizeDataStructure = pow(2, numberOfIndexBits);
	_dataStructure = new unsigned char[_sizeDataStructure];
}

unsigned char ReplacementHandler::PLRUFindVictim(unsigned short address){
	//insert code HERE
	return 0;
}

void ReplacementHandler::PLRUNotifyOperation(unsigned short address, unsigned char cacheColumn){
	//insert code HERE
}

void ReplacementHandler::LFUSetUp(unsigned char numberOfAddressBits,unsigned char numberOfIndexBits, unsigned char numberOfOffsetBits, unsigned char nWayAssociative){
	//insert code HERE
}

unsigned char ReplacementHandler::LFUFindVictim(unsigned short address){
	//insert code HERE
	return 0;
}

void ReplacementHandler::LFUNotifyOperation(unsigned short address, unsigned char cacheColumn){
	//insert code HERE
}