#ifndef IREPLACEMENT_H
#define IREPLACEMENT_H
class IReplacementPolicy {
public:
	virtual unsigned char findVictim(unsigned short address) = 0;
	virtual void notifyOperation(unsigned short address, unsigned char cacheColumn) = 0;
};

#endif