/* 
 * File:   ds2401.h
 * Author: SD
 *
 * Created on 24 février 2020, 18:08
 * 
 * https://datasheets.maximintegrated.com/en/ds/DS2401.pdf
 * Voir programme d'exemple en bas de ce fichier
 */
#include "oneWire.h"

#ifndef DS2401_H
#define	DS2401_H

#ifdef	__cplusplus
extern "C" {
#endif

#define DS2401_MEMORY_SIZE  8
#define DS2401_READ_ROM     0x33
#define DS2401_FAMILLY_CODE 0x01

/**
 * Initialise la GPIO DQ du bus OneWire. Fait un reset du bus OneWire, 
 * si un périphérique est connecté, il doit répondre
 * 
 * @author SD
 * @return TRUE ou FALSE selon si un périphérique à répondu ou pas
*/
owByte ow_DS2401_init();


/**
 *  Lit la mémoire interne du DS2401
 * @author SD
 * 
 * @param owRom : pointeur sur un tableau de 8 octets :
 *      - octet 1 : Familly code : 01h
 *      - octets 2 à 7 : Identifiant unique 48 bits (MSB first)
 *      - octet 8 : CRC code
 * 
 * @return TRUE si un périphérique répond et si le "familly code" correspond à 01h
 */
owByte ow_DS2401_getID(owByte* owRom);


/**
 *  Convertit l'identifiant unique 48 bits en une chaine de caractères
 * @author SD
 * 
 * @param owRom : pointeur sur un tableau de 8 octets :
 *      - octet 1 : Familly code : 01h
 *      - octets 2 à 7 : Identifiant unique 48 bits (LSB first)
 *      - octet 8 : CRC code
 * @param strID : pointeur sur un tableau de caractères qui contiendra le 
 *  résultat. Le tableau doit avoir une taille d'au moins 13 caractères
 */   
void owDS2401_ID_To_String(owByte* owRom, char* strID);


/**
 * Usage interne seulement 
 * Convertit un un nombre entier non signé [0 - 15] en un caractère hexadécimal
 * @param number : nombre compris entre 0 et 15
 * @return : caractère hexadécimal correspondant à number
 */
char _numberToHex(owByte number);

/* // Programme d'exemple d'utilisation (main)
#include "mcc_generated_files/mcc.h"
#include "ds2401.h"
void main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    owByte owRom[DS2401_MEMORY_SIZE];
    
    if(ow_DS2401_init()) {
        if(ow_DS2401_getID(owRom)) {  
            char str[13];
            owDS2401_ID_To_String(owRom, str);
            printf("ID : %s\r\n",str);
        }
        else {
            printf("ERREUR, \"Familly code\" invalide ou CRC invalide\r\n");
        }
    }
    else {
        printf("ERREUR, périphérique OneWire non détecté ou ne répond pas\r\n");
    }
}
*/

#ifdef	__cplusplus
}
#endif

#endif	/* DS2401_H */

