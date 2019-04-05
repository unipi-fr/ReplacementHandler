#ifndef REPLACEMENT_H
#define REPLACEMENT_H
#include "IReplacementHandler.h"
#include <cstddef>


enum PoliciesOffered { PLRU, LFU };

class ReplacementHandler : public IReplacementPolicy {
public:
    ReplacementHandler(unsigned char numberOfAddressBits,unsigned char numberOfIndexBits, unsigned char numberOfOffsetBits, unsigned char nWayAssociative, PoliciesOffered policy);
	unsigned char findVictim(unsigned short address);
	void notifyOperation(unsigned short address, unsigned char cacheColumn);

private:
	PoliciesOffered _policy;
	size_t _sizeDataStructure;
	unsigned char* _dataStructure;

	void PLRUSetUp(unsigned char numberOfAddressBits,unsigned char numberOfIndexBits, unsigned char numberOfOffsetBits, unsigned char nWayAssociative);
	unsigned char PLRUFindVictim(unsigned short address);
	void PLRUNotifyOperation(unsigned short address, unsigned char cacheColumn);

	void LFUSetUp(unsigned char numberOfAddressBits,unsigned char numberOfIndexBits, unsigned char numberOfOffsetBits, unsigned char nWayAssociative);
	unsigned char LFUFindVictim(unsigned short address);
	void LFUNotifyOperation(unsigned short address, unsigned char cacheColumn);
};

#endif

