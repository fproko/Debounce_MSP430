//----------------------------------------------------------------------------
//  Description:  This file contains functions that allow the use the USCI_A
//  module in UART mode for MSP430 devices. 
//
//  MSP430 Pheriperal Interface Code Library v1.0
//
//----------------------------------------------------------------------------

#include "TI_MSP_UART.h"
#include "msp430f5529.h"

//******************************************************************************
// Funcion: Init_UART
// Configuracion Inicial del UCA 0 como UART
//******************************************************************************
void Init_UART(void){
                        
  UART_UCAxCTL1 |= (UCSWRST); //primero lo pone en 1, despues lo pone a lo ultimo en 0. USCI Software Reset
 
    
  /* USCI Ax Control Register 0 */
  UART_UCAxCTL0 = 0x00;
  //con esto esta poniendo
  //UCSYNC=0 modo asincrono (sin clock), UCMODEx=00 que es UART Mode, UCSPB=0 un bit de stop, UCPEN=0 paridad desabilitad
  //UCMSB LBIT first
  
  /* USCI Ax Control Register 1 */
  UART_UCAxCTL1 |= UCSSEL__SMCLK; //pongo un 1 en el bit 8 para elegir el SMCLK
  
  /* Esto es lo mismo que la linea de arriba
  
  UART_UCAxCTL1 |= (UCSSEL0 + UCSSEL1);
  
  //define con que clock generar los baudios para el UART
  //definio el SMCLK
   */
  
 /* USCI Ax Baud Rate  */
 /* USCI Ax Modulation Control */
#if MSP430_UART_SMCLK_FREQ == SMCLK_1MHZ             // 1MHz as BRCLK
  #if MSP430_UART_BAUD_RATE == BAUD_RATE_9600BPS        // 9600bps
    UART_UCAxBR1 = 0x00;	
    UART_UCAxBR0 = 0x68;
    UART_UCAxMCTL = 0x02;
  #endif
  #if MSP430_UART_BAUD_RATE == BAUD_RATE_19200BPS    // 19200bps
    UART_UCAxBR1 = 0x00;	
    UART_UCAxBR0 = 0x34;
    UART_UCAxMCTL = 0x00;
  #endif
  #if MSP430_UART_BAUD_RATE == BAUD_RATE_56000BPS    // 56000bps
    UART_UCAxBR1 = 0x00;	
    UART_UCAxBR0 = 0x11;
    UART_UCAxMCTL = 0x0E;
  #endif
  #if MSP430_UART_BAUD_RATE == BAUD_RATE_115200BPS    // 115200bps
    UART_UCAxBR1 = 0x00;	
    UART_UCAxBR0 = 0x08;
    UART_UCAxMCTL = 0x0C;
  #endif
#endif
    
#if MSP430_UART_SMCLK_FREQ == SMCLK_1048MHZ             // 1.048MHz as BRCLK
  #if MSP430_UART_BAUD_RATE == BAUD_RATE_9600BPS        // 9600bps
    UART_UCAxBR1 = 0x00;	
    UART_UCAxBR0 = 109; //109 en los bits mas bajos por eso es en este, y en el UCAxBR1=0
    UART_UCAxMCTL |= UCBRS_2 + UCBRF_0;
  #endif
  #if MSP430_UART_BAUD_RATE == BAUD_RATE_19200BPS    // 19200bps
    UART_UCAxBR1 = 0x00;	
    UART_UCAxBR0 = 54;
    UART_UCAxMCTL |= UCBRS_5 + UCBRF_0;
  #endif
  #if MSP430_UART_BAUD_RATE == BAUD_RATE_56000BPS    // 56000bps
    UART_UCAxBR1 = 0x00;	
    UART_UCAxBR0 = 18;
    UART_UCAxMCTL |= UCBRS_1 + UCBRF_0;
  #endif
  #if MSP430_UART_BAUD_RATE == BAUD_RATE_115200BPS    // 115200bps
    UART_UCAxBR1 = 0x00;	
    UART_UCAxBR0 = 9;
    UART_UCAxMCTL |= UCBRS_1 + UCBRF_0;
  #endif
#endif
#if MSP430_UART_SMCLK_FREQ == SMCLK_4MHZ             // 4MHz as BRCLK
  #if MSP430_UART_BAUD_RATE == BAUD_RATE_9600BPS      // 9600bps
    UART_UCAxBR1 = 0x01;	
    UART_UCAxBR0 = 0xA0;
    UART_UCAxMCTL = 0x0C;
  #elif MSP430_UART_BAUD_RATE == BAUD_RATE_19200BPS    // 19200bps
    UART_UCAxBR1 = 0x00;	
    UART_UCAxBR0 = 0xD0;
    UART_UCAxMCTL = 0x06;
  #elif MSP430_UART_BAUD_RATE == BAUD_RATE_56000BPS    // 56000bps
    UART_UCAxBR1 = 0x00;	
    UART_UCAxBR0 = 0x47;
    UART_UCAxMCTL = 0x08;
  #elif MSP430_UART_BAUD_RATE == BAUD_RATE_115200BPS    // 115200bps
    UART_UCAxBR1 = 0x00;	
    UART_UCAxBR0 = 0x22;
    UART_UCAxMCTL = 0x0C;
  #endif
#endif
#if MSP430_UART_SMCLK_FREQ == SMCLK_8MHZ             // 8MHz as BRCLK
  #if MSP430_UART_BAUD_RATE == BAUD_RATE_9600BPS      // 9600bps
    UART_UCAxBR1 = 0x03;	
    UART_UCAxBR0 = 0x41;
    UART_UCAxMCTL = 0x04;
  #elif MSP430_UART_BAUD_RATE == BAUD_RATE_19200BPS    // 19200bps
    UART_UCAxBR1 = 0x01;	
    UART_UCAxBR0 = 0xA0;
    UART_UCAxMCTL = 0x0C;
  #elif MSP430_UART_BAUD_RATE == BAUD_RATE_56000BPS    // 56000bps
    UART_UCAxBR1 = 0x00;	
    UART_UCAxBR0 = 0x8E;
    UART_UCAxMCTL = 0x0E;
  #elif MSP430_UART_BAUD_RATE == BAUD_RATE_115200BPS    // 115200bps
    UART_UCAxBR1 = 0x00;	
    UART_UCAxBR0 = 0x45;
    UART_UCAxMCTL = 0x08;
  #endif
#endif
#if MSP430_UART_SMCLK_FREQ == SMCLK_12MHZ             // 12MHz as BRCLK
  #if MSP430_UART_BAUD_RATE == BAUD_RATE_9600BPS      // 9600bps
    UART_UCAxBR1 = 0x04;	
    UART_UCAxBR0 = 0xE2;
    UART_UCAxMCTL = 0x00;
  #elif MSP430_UART_BAUD_RATE == BAUD_RATE_19200BPS    // 19200bps
    UART_UCAxBR1 = 0x02;	
    UART_UCAxBR0 = 0x71;
    UART_UCAxMCTL = 0x00;
  #elif MSP430_UART_BAUD_RATE == BAUD_RATE_56000BPS    // 56000bps
    UART_UCAxBR1 = 0x00;	
    UART_UCAxBR0 = 0xD6;
    UART_UCAxMCTL = 0x04;
  #elif MSP430_UART_BAUD_RATE == BAUD_RATE_115200BPS    // 115200bps
    UART_UCAxBR1 = 0x00;	
    UART_UCAxBR0 = 0x68;
    UART_UCAxMCTL = 0x02;
  #endif
#endif
#if MSP430_UART_SMCLK_FREQ == SMCLK_16MHZ             // 16MHz as BRCLK
  #if MSP430_UART_BAUD_RATE == BAUD_RATE_9600BPS      // 9600bps
    UART_UCAxBR1 = 0x06;	
    UART_UCAxBR0 = 0x82;
    UART_UCAxMCTL = 0x0C;
  #elif MSP430_UART_BAUD_RATE == BAUD_RATE_19200BPS    // 19200bps
    UART_UCAxBR1 = 0x03;	
    UART_UCAxBR0 = 0x41;
    UART_UCAxMCTL = 0x04;
  #elif MSP430_UART_BAUD_RATE == BAUD_RATE_56000BPS    // 56000bps
    UART_UCAxBR1 = 0x01;	
    UART_UCAxBR0 = 0x1D;
    UART_UCAxMCTL = 0x0C;
  #elif MSP430_UART_BAUD_RATE == BAUD_RATE_115200BPS    // 115200bps
    UART_UCAxBR1 = 0x00;	
    UART_UCAxBR0 = 0x08A;
    UART_UCAxMCTL = 0x0E;
  #endif
#endif

  
  UART_PORTSEL |= (UART_PIN_TX + UART_PIN_RX); // Configura los pines como  TXD/RXD
  //sive para saber si el pin correspontiente va a estar conectado al puerto o periferico 
  // para el UART es con un 1
  //UART_PORTDIR |= (UART_PIN_TX); //configura como salida el pin de transmicion
  //UART_PORTDIR &= ~(UART_PIN_RX);//configura como entrada el pin de recepcion
  
  UART_UCAxCTL1 &= ~(UCSWRST); //aca se ve q lo pone en 0 como decia el tutorial
  
  UART_IFG &= ~UART_UCAxRXIFG;  //baja la bandera para decir q no hay interrupcion de recepcion pendiente
  UART_IE |= (UART_UCAxRXIE); //habilita la interrupcion para la recepcion
}

//*****************************************************************
// Funcion: UART_Tx_char();
//                escribe un char por el UART
//******************************************************************
void UART_Tx_char(char dato)
{
    UART_UCAxTXBUF = dato;                //Se carga en el buffer de transmisión el dato a mandar
    while (!(UART_IFG & UART_UCAxTXIFG)); //Espero a que se vacie el buffer de transmisión
                                          //UCTXIFG is set when UCAxTXBUF empty
}        

//*****************************************************************
// Funcion: UART_Tx_string();
// Descr.:    escribe un string por el UART
// Paramatros: cant = 0 (escribe hasta encontrar un null (0))
//             cant != 0 (imprime el numero de chars asignado)
//*****************************************************************
// Puede usarse como:
//   sprintf((char *)&buffer[0], "variable: %d", var);
//   UART_Tx_string(buffer);
//*****************************************************************
void UART_Tx_string(char *dato, char cant){
  char i;
  
  if(!cant){                                  //si paso un cero imprime hasta null (un string)
    while(*dato){                             //mientras que no tenga un null 
      UART_UCAxTXBUF = *dato++;               //escribo un caracter e incremento el puntero  
      while(!(UART_IFG & UART_UCAxTXIFG));    //mientras no este vacio me quedo a esperar, cuando se vacio me voy			
    }
  }else{
    for(i=0; i<=cant; i++){                   //pasando la cantidad a imprimir
      UART_UCAxTXBUF = *(dato++);             //escribo un caracter e incremento el puntero  
      while(!(UART_IFG & UART_UCAxTXIFG));    //mientras no este vacio me quedo a esperar, cuando se vacio me voy
    }
  }
}   

//*****************************************************************
// Funcion: ERROR();
//                manda un error si los datos para sumar o restar no sos aptos
//******************************************************************

int ERROR(char *datos){
 int i,e=0;
 
  for (i=0;i<=2;i++){
    if(!((datos[i]>=0x30)&&(datos[i]<=0x39))){
    char error[] = {'E', 'r', 'r', 'o', 'r','1'}; 
    UART_Tx_string(error,6);
    e=1;
    
    } 
  }
  for (i=4;i<=6;i++){
    if(!((datos[i]>=0x30)&&(datos[i]<=0x39))){
    char error[] = {'E', 'r', 'r', 'o', 'r','2'}; 
    UART_Tx_string(error,6);
    e=1;
   
    } 
  }
  
    if(!((datos[3]==0x2B)||(datos[3]==0x2D))){
    char error[] = {'E', 'r', 'r', 'o', 'r','3'}; 
    UART_Tx_string(error,6);
    e=1;
    
    
  }
  return e;
}

//******************************************
//Funcion: Calculadora();
//******************************************

void calculadora(char *datos){
   char dato_tx[4],cant=4;
   int rta,j,dato1,dato2;
   

   dato1= ((int)datos[0]-0x30)*100+((int)datos[1]-0x30)*10+((int)datos[2]-0x30);
   dato2= ((int)datos[4]-0x30)*100+((int)datos[5]-0x30)*10+((int)datos[6]-0x30);
             switch(datos[3])
             {
              case '+':
                rta=dato1+dato2;
                break;
              case '-':
                rta=dato1-dato2;
                break;
             }
    j=3;
    for(j=3;j>=0;j--)
      {
        dato_tx[j]=(char)(rta%10) + 0x30; //me da el resto de la division al dividir por 10
        rta=rta/10;
       }
    UART_Tx_char('\n');
    UART_Tx_char('\r');    
    UART_Tx_string(dato_tx,cant);
}
