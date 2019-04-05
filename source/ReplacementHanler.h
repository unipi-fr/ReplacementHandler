#ifndef REPLACEMENT_H
#define REPLACEMENT_H
#include "IReplacementHandler.h"

enum PoliciesOffered { PLRU, LFU };

class ReplacementHandler : public IReplacementPolicy {
public:
    ReplacementHandler(int numberOfAddressBits,int numberOfIndexBits, int numberOfOffsetBits, PoliciesOffered policy);
	unsigned short findVictim(unsigned short address);
	void notifyOperation(unsigned short address, unsigned short cacheColumn);

private:
	PoliciesOffered _policy;
	int* _dataStructure;

};

#endif

