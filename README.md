# IReplacementPolicy
Is the interface which defines the base operations that a replacement policy module for **associative** cache must provides.
```
class IReplacementPolicy {
public:
   virtual unsigned char findVictim(unsigned short address) = 0;
   virtual void notifyOperation(unsigned short address, unsigned char cacheColumn) = 0;
};
```
# ReplacementHandler
Our ReplacementHandler is a module C++ which implements some of the most popular replacement policies for cache. 
```
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
```
In order to work properly, the data structures must be initialized by the only constructor of the class, which takes as input those parameters:
* ```numberOfIndexBits``` Number of index bits
* ```numberOfOffsetBits``` Number of offset bits
* ```nWayAssociative``` Level of assocety
* ```policy``` La politica da adottare
Le politiche disponibili sono accessibili attraverso l’enumerato 
      ```enum PoliciesOffered { PLRU, LFU };```

Our class implements IReplacementPolicy and consequently it realize the methods described in the interface.

## Other Links
[Google Drive](https://drive.google.com/drive/u/0/folders/1Z0gnNFUfblsVpuH6YsJS_U8zh4fRdnUz) - The Google Drive Folder with more details 

