#ifndef IREPLACEMENT_H
#define IREPLACEMENT_H
#include <cstdint>


class IReplacementPolicy {
public:
	virtual uint8_t findVictim(uint16_t address) = 0;
	virtual void updateStatistics(uint16_t address, uint8_t cacheColumn) = 0;
	void invalidateStatistics(uint16_t address, uint8_t cacheColumn) = 0;
};

#endif