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
	IReplacementPolicy* _policyAdopted;
};

#endif

