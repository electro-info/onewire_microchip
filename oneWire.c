#include "mcc_generated_files/mcc.h"
#include "oneWire.h"

void ow_init() {
    DQ_SetDigitalOutput();  
    DQ_SetDigitalMode();
    DQ_SetPullup();
    DQ_SetPushPull();
}

owByte ow_reset() {   
    owByte presence = OW_FALSE;
    
    DQ_SetLow();
    OW_DELAY_US(OW_RST_PULSE);        
    DQ_SetHigh();
    OW_DELAY_US(OW_PRES_DETECT_HIGH);
    presence = DQ_GetValue();
    OW_DELAY_US(OW_PRES_DETECT_LOW);
    
    return !presence;
}

owByte ow_readBit() {
    DQ_SetLow();
    OW_DELAY_US(1);
    DQ_SetHigh();
    OW_DELAY_US(OW_READ_DATA_VALID);
    return DQ_GetValue();
}

void ow_writeBit(owByte bitval) {
    DQ_SetLow();
    OW_DELAY_US(1);
    if(bitval==1) DQ_SetHigh();
    OW_DELAY_US(OW_TIME_SLOT);
    DQ_SetHigh();   
}

owByte ow_readByte() {
    owByte i;
    owByte result = 0;
    
    for(i=0; i<8 ; i++) {
        if(ow_readBit())
            result = result | (0x01 << i);
        OW_DELAY_US(OW_TIME_SLOT);
    }
    return result;
}

void ow_writeByte(owByte val) {
    owByte i;
    owByte temp;
    
    for(i=0; i<8 ; i++) {
        temp = val >> i;
        temp = temp & 0x01;
        ow_writeBit(temp);
    }   
}

owByte crc8(owByte *addr, owByte len) {
    owByte i, crc, inbyte, mix;
    crc = 0;
    
    while(len--) {
        inbyte = *addr++;
        for(i=8 ; i ; i--) {
            mix = (crc ^ inbyte) & 0x01;
            crc >>= 1;
            if(mix) crc ^= 0x8C;
            inbyte >>= 1;
        }
    }
    return crc;
}