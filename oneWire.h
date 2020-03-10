/* 
 * File:   oneWire.h
 * Author: SD
 *
 * Créé le 21 octobre 2017
 * 
 */

#ifndef ONEWIRE_H
#define	ONEWIRE_H

#ifdef	__cplusplus
extern "C" {
#endif

#define OW_RST_PULSE           480
#define OW_PRES_DETECT_HIGH    60
#define OW_PRES_DETECT_LOW     240
#define OW_READ_DATA_VALID     15
#define OW_TIME_SLOT           60

// Changer le nom de la fonction delay en fonction du compilateur :
//      - Pour XC8 : __delay_us     
#define OW_DELAY_US            __delay_us

// Si autre compilateur que XC8, définir (DQ étant la GPIO utilisée pour le bus OneWire) :
// DQ_SetLow
// DQ_SetHigh
// DQ_GetValue
// Modifier également ow_init de manière à configurer la GPIO DQ correctement
    
typedef unsigned char owByte;

#define OW_TRUE     1
#define OW_FALSE    0

/**
 * Initialise la GPIO DQ du bus OneWire
 * @author : SD
 */
void ow_init();


/**
 * Initialise le bus OneWire, si un périphérique est connecté, il doit répondre
 * @author SD
 * @return TRUE si un prériphérique est détecté, FALSE sinon
 */
owByte ow_reset();


/**
 * Lit un bit reçu sur le bus OneWire
 * @author SD
 * @return la valeur du bit lu : 0 ou 1
 */
owByte ow_readBit();


/**
 * Ecrit un bit sur le bus OneWire
 * @author SD
 * @param la valeur du bit à écrire : 0 ou 1
 */
void ow_writeBit(owByte);


/**
 * Lit un octet reçu sur le bus OneWire
 * @author SD
 * @return la valeur du l'octet reçu
 */
owByte ow_readByte();


/**
 * Ecrit un octet sur le bus OneWire
 * @author SD
 * @param la valeur du l'octet à envoyer
 */
void ow_writeByte(owByte);        


/**
 * Calcul le CRC d'un tableau d'octets (usage interne seulement)
 * @param pointeur sue le tableau
 * @param taille du tableau
 * @return le CRC calculé
 */
owByte crc8(owByte* , owByte);

#ifdef	__cplusplus
}
#endif

#endif	/* ONEWIRE_H */