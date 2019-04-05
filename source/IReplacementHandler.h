#ifndef IREPLACEMENT_H
#define IREPLACEMENT_H
class IReplacementPolicy {
public:
	virtual unsigned short findVictim(unsigned short address) = 0;
	virtual void notifyOperation(unsigned short address, unsigned short cacheColumn) = 0;
};

#endif