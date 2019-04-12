#ifndef REPLACEMENT_H
#define REPLACEMENT_H
#include "IReplacementHandler.h"
#include <cstdint>
#include <cstddef>

#define numberOfAddressBits 16 


enum PoliciesOffered { PLRU, LFU };

class ReplacementHandler : public IReplacementPolicy {
public:
    ReplacementHandler(uint8_t numberOfIndexBits, uint8_t numberOfOffsetBits,uint8_t nWayAssociative, PoliciesOffered policy);
	uint8_t findVictim(uint16_t address);
	void notifyOperation(uint16_t address, uint8_t cacheColumn);

private:
	PoliciesOffered _policy;
	IReplacementPolicy* _policyAdopted;
};

#endif

