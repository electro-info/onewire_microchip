#include "ds18s20.h"

owByte ow_DS18S20_init() {
    ow_init();
    return ow_reset();
}

owByte ow_DS18S20_startTempConvAll() {
    if(ow_reset()) {
        ow_writeByte(DS18S20_SKIP_ROM);
        ow_writeByte(DS18S20_START_TEMP_CONV); 
        return OW_TRUE;
    }
    return OW_FALSE;
}

float ow_DS1820_getTemp(owByte lsb, owByte msb) {
    if(msb == 0) {  // Nombre positif, on divise par 2 pour obtenir la partie décimal
        return lsb >> 1; 
    } else {    // Nombre négatif : décodage du complément à 2 et division par 2
        return -(256 - lsb) >> 1;
    }
}

owByte ow_DS1820_readScratchPad(owByte* owPAD) { 
   owByte i;
      
  if(ow_reset()) {
    ow_writeByte(DS18S20_SKIP_ROM);
    ow_writeByte(DS18S20_READ_SCRATCHPAD);
     
    for(i=0; i<DS18S20_SCRATCHPAD_SIZE; i++) 
       owPAD[i] = ow_readByte();
      
    return OW_TRUE;
  }
  return OW_FALSE;
}

void ow_readROM(owByte* owROM) { 
    owByte i;
    
    ow_reset();
    ow_writeByte(DS18S20_READ_ROM);
    
    for(i=0; i<8 ; i++) owROM[i] = ow_readByte();
}