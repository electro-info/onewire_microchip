#include "ds2401.h"

owByte ow_DS2401_init() {
    ow_init();
    return ow_reset();
}

owByte ow_DS2401_getID(owByte* owRom) {
    owByte i;
      
    if(ow_reset()) {
        ow_writeByte(DS2401_READ_ROM);
     
        for(i=0; i < DS2401_MEMORY_SIZE; i++) 
            owRom[i] = ow_readByte();
        
        if(owRom[0] != DS2401_FAMILLY_CODE)
            return OW_FALSE;
        
        // owRom[3] = 0; // Pour test CRC
        if(crc8(owRom,DS2401_MEMORY_SIZE-1) != owRom[7])
            return OW_FALSE;
        
        return OW_TRUE;
    }
    return OW_FALSE;
}

void owDS2401_ID_To_String(owByte* owRom, char* strID) {
    owByte i, j, value;
    
    for(i=1; i < 7; i++) {        
        j = 11 - ((i - 1) * 2);
        
        value = (owRom[i] >> 4) & 0x0F;
        strID[j - 1] = _numberToHex(value);
        
        value = owRom[i] & 0x0F;
        strID[j] = _numberToHex(value);        
    }
    strID[12] = '\0';
}

char _numberToHex(owByte number) {
    if(number < 10)  number = number + '0';
    else number = number - 10 + 'A';    
    
    return (char)number;
}