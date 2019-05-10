#ifndef CABINH
#define CABINH

#include "cclass.h"


CLASS(Cabin)
	unsigned int state_;
METHODS
	enum Signal CabinGetSignals(Cabin *me);
	void CabinInit(Cabin *me);
	void CabinTran_(Cabin *me, unsigned int dest);
	void CabinDispatch(Cabin *me);
END_CLASS

#endif // CABINH