#include "ReplacementHandler.h"
#include <math.h>
#include <limits.h>

class PLRUReplacementHandler : public IReplacementPolicy {
private:
	unsigned char* _dataStructure;
	size_t _sizeDataStructure;
public:
    PLRUReplacementHandler(unsigned char numberOfAddressBits,unsigned char numberOfIndexBits, unsigned char numberOfOffsetBits, unsigned char nWayAssociative){
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

	unsigned char findVictim(unsigned short address){
		//TODO: Insert Code here
		return 0;
	}

	void notifyOperation(unsigned short address, unsigned char cacheColumn){
		//TODO: Insert code here
	}
};

class LFUReplacementHandler : public IReplacementPolicy {
private:
	unsigned char* _dataStructure;
	size_t _sizeDataStructure;
public:
    LFUReplacementHandler(unsigned char numberOfAddressBits,unsigned char numberOfIndexBits, unsigned char numberOfOffsetBits, unsigned char nWayAssociative){
		//TODO: Insert Code Here
	}

	unsigned char findVictim(unsigned short address){
		//TODO: Insert Code here
		return 0;
	}

	void notifyOperation(unsigned short address, unsigned char cacheColumn){
		//TODO: Insert code here
	}
};

ReplacementHandler::ReplacementHandler(unsigned char numberOfAddressBits,unsigned char numberOfIndexBits, unsigned char numberOfOffsetBits, unsigned char nWayAssociative, PoliciesOffered policy) {
	_policy = policy;

	switch (policy)
	{
		case PLRU:
			_policyAdopted = new PLRUReplacementHandler(numberOfAddressBits,numberOfIndexBits,numberOfOffsetBits,nWayAssociative);
			break;
		case LFU:
			_policyAdopted = new LFUReplacementHandler(numberOfAddressBits,numberOfIndexBits,numberOfOffsetBits,nWayAssociative);
			break;
		default:
			//TODO: gestire l'errore
			break;
	}
	
}

/*Returns the cacheColumn where the victim was chosen*/
unsigned char ReplacementHandler::findVictim(unsigned short address) {
	return _policyAdopted->findVictim(address);
}

void ReplacementHandler::notifyOperation(unsigned short address, unsigned char cacheColumn){
	_policyAdopted->notifyOperation(address,cacheColumn);
}

