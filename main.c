/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC16F1719
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc_generated_files/mcc.h"
#include "ds18s20.h"
#include "ds2401.h"
/*
                         Main application
 */
void main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();

    /*owByte get[DS18S20_SCRATCHPAD_SIZE];
    if(!ow_DS18S20_init())
        printf("\r\nERREUR DS18S20_init : Le capteur ne repond pas\r\n");
    __delay_ms(2000);
    */
    
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
        printf("ERREUR, p�riph�rique OneWire non d�tect� ou ne r�pond pas\r\n");
    }
        
    while (1)
    {
        // Add your application code
        /*if(ow_DS18S20_startTempConvAll()) {
            __delay_ms(500);
            if(ow_DS1820_readScratchPad(get)) {
                printf("T : %.1f\r\n",ow_DS1820_getTemp(get[0],get[1]));
            } else printf("\r\nERREUR readScratchPad : Le capteur ne repond pas\r\n");
        } else printf("\r\nERREUR startTempConvAll : Le capteur ne repond pas\r\n");
         */
        
    }
}
/**
 End of File
*/