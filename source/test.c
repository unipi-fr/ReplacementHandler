#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

uint32_t _dataStructure[] = {
  0     ,1      ,2      ,3 ,
  4     ,5      ,6      ,7 ,
  8     ,9      ,10     ,11,
  12    ,13     ,14     ,15,
  16    ,17     ,18     ,19,
  20    ,21     ,22     ,23,
  24    ,25     ,26     ,27,
  28    ,29     ,30     ,31,
  32    ,33     ,34     ,35,
  36    ,37     ,38     ,39,
  40    ,41     ,42     ,43,
  44    ,45     ,46     ,47,
  48    ,49     ,50     ,51,
  52    ,53     ,54     ,55,
  56    ,57     ,58     ,59,
  60    ,61     ,62     ,63,
};
uint16_t _nWayAssociative = 8;

uint8_t findVictim(uint16_t address){
    uint16_t index = address;
       
        uint32_t counter = ~(_dataStructure[index]);
        
        uint8_t cacheColum = 0;
        int i = 0;
        
        for(uint8_t n = _nWayAssociative/2; n > 0; n /= 2){
            uint32_t bit = counter & (1u << i);
            
            if(bit > 0) {
                cacheColum += n;
                i += n;    
            } else {
                i += 1;
            }                
        }
        
        return cacheColum;
}

int main(){
    printf("\n{");
    for (uint32_t i = 0; i < 64; i++)
    {
        printf(" %u",findVictim(_dataStructure[i]));
        //printf(" %u",i);
        if(i<63){
            printf(",");
        }
    }
    printf("}\n");

    return 0;
}