/* 
 * File:   ds18s20.h
 * Author:  SD
 *
 * Créé le 21 octobre 2017
 * 
 * Voir programme d'exemple en bas de ce fichier
 */
#include "oneWire.h"

#ifndef DS18S20_H
#define	DS18S20_H

#ifdef	__cplusplus
extern "C" {
#endif

#define DS18S20_SKIP_ROM         0xCC
#define DS18S20_SEARCH_ROM       0xF0
#define DS18S20_READ_ROM         0x33

#define DS18S20_START_TEMP_CONV  0x44
#define DS18S20_READ_SCRATCHPAD  0xBE
#define DS18S20_WRITE_SCRATCHPAD 0x4E

#define DS18S20_SCRATCHPAD_SIZE	 9

/**
 * Initialise la GPIO DQ du bus OneWire. Fait un reset du bus OneWire, 
 * si un périphérique est connecté, il doit répondre
 * @return TRUE ou FALSE selon si un capteur à répondu ou pas
 */
owByte ow_DS18S20_init();
/**
 * Envoie l'ordre au capteur de réaliser une convertion de température
 * @author SD
 * @return TRUE ou FALSE selon si un capteur à répondu ou pas
 */   
owByte ow_DS18S20_startTempConvAll();
/**
 *  Lit la mémoire interne du capteur (tableau de 9 octets appelé SCRATCHPAD)
 * @author SD
 * @param owPAD : pointeur sur un tableau de 9 octets pour stocker le résultat de la lecture
 * @return TRUE ou FALSE selon si un capteur à répondu ou pas  
 */
owByte ow_DS1820_readScratchPad(owByte* owPAD);
/**
 * Convertit les valeurs lues dans le scratchpad en une valeur en degrés Celcius
 * @param lsb : premier octet du scratchpad
 * @param msb : deuxième octet du scratchpad
 * @return la température en degrés Celcius (float)
 */
float ow_DS1820_getTemp(owByte lsb, owByte msb);

void ow_readROM(owByte*);

owByte crc8(owByte* , owByte);

#ifdef	__cplusplus
}
#endif

/*
#include "mcc_generated_files/mcc.h"
#include "ds18s20.h"
void main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    owByte get[DS18S20_SCRATCHPAD_SIZE];
    if(!ow_DS18S20_init())
        printf("\r\nERREUR DS18S20_init : Le capteur ne repond pas\r\n");
    
    while (1)
    {
        if(ow_DS18S20_startTempConvAll()) {
            __delay_ms(500);
            if(ow_DS1820_readScratchPad(get)) {
                printf("T : %.1f\r\n",ow_DS1820_getTemp(get[0],get[1]));
            } else printf("\r\nERREUR readScratchPad : Le capteur ne repond pas\r\n");
        } else printf("\r\nERREUR startTempConvAll : Le capteur ne repond pas\r\n");
    }
}
 */
#endif	/* DS18S20_H */

