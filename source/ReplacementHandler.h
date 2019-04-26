#ifndef REPLACEMENT_H
#define REPLACEMENT_H
#include "IReplacementHandler.h"
#include "ReplacementHandlerExceptions.h"
#include <cstdint>
#include <cstddef>
#include <stdlib.h>
#define numberOfAddressBits 16 


enum PoliciesOffered { PLRU, LFU, RND };

class ReplacementHandler : public IReplacementPolicy {
public:
    ReplacementHandler(uint8_t numberOfIndexBits, uint8_t numberOfOffsetBits,uint8_t nWayAssociative, PoliciesOffered policy);
	uint8_t findVictim(uint16_t address);
	void updateStatistics(uint16_t address, uint8_t cacheColumn);
	void invalidateStatistics(uint16_t address, uint8_t cacheColumn);

private:
	PoliciesOffered _policy;
	IReplacementPolicy* _policyAdopted;
};

#endif

