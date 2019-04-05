#include "ReplacementHanler.h"
#include <math.h>

unsigned short ReplacementHandler::findVictim(unsigned short address) {
	return 0;
}

void ReplacementHandler::notifyOperation(unsigned short address, unsigned short cacheColumn){
	return;
}

ReplacementHandler::ReplacementHandler(int numberOfAddressBits,int numberOfIndexBits, int numberOfOffsetBits, PoliciesOffered policy) {
	int dataStructureDim;
	_policy = policy;
	if (numberOfAddressBits>numberOfIndexBits + numberOfOffsetBits) {
		dataStructureDim = pow(2, numberOfIndexBits);
	}
	_dataStructure = new int[dataStructureDim];
}