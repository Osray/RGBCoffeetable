/* This file has been generated by pinning m4 system automatically.
   Please do not modify it, edit the m4 scripts below pinning/ instead. */

/* code to en-/disable RS485 transmitters depending on the usart used */
#undef RS485_HAVE_TE
#undef RS485_DISABLE_TX
#undef RS485_ENABLE_TX
#undef RS485_TE_SETUP
#if ((USE_USART + 0) == 0 && defined(HAVE_RS485TE_USART0))
  #define RS485_HAVE_TE     1
  #define RS485_DISABLE_TX  PIN_CLEAR(RS485TE_USART0)
  #define RS485_ENABLE_TX   PIN_SET(RS485TE_USART0)
  #define RS485_TE_SETUP    DDR_CONFIG_OUT(RS485TE_USART0)
#elif ((USE_USART + 0) == 1 && defined(HAVE_RS485TE_USART1))
  #define RS485_HAVE_TE     1
  #define RS485_DISABLE_TX  PIN_CLEAR(RS485TE_USART1)
  #define RS485_ENABLE_TX   PIN_SET(RS485TE_USART1)
  #define RS485_TE_SETUP    DDR_CONFIG_OUT(RS485TE_USART1)
#else
  #define RS485_HAVE_TE     0
  #define RS485_DISABLE_TX  /* empty */
  #define RS485_ENABLE_TX   /* empty */
  #define RS485_TE_SETUP    /* empty */
#endif



#ifndef _PINNING_HEADER
#define _PINNING_HEADER

#define _ISC(n,m) _BV(ISC ## n ## m)
#define _paste(n,m) n ## m
#define _paste3(a,b,c) a ## b ## c

#define _PORT_CHAR(character) PORT ## character
#define PORT_CHAR(character) _PORT_CHAR(character)

#define _PIN_CHAR(character) PIN ## character
#define PIN_CHAR(character) _PIN_CHAR(character)

#define _DDR_CHAR(character) DDR ## character
#define DDR_CHAR(character) _DDR_CHAR(character)


#define DDR_CONFIG_IN(pin)  DDR_CHAR( pin ## _PORT) &= ~_BV((pin ## _PIN))
#define DDR_CONFIG_OUT(pin)  DDR_CHAR( pin ## _PORT) |= _BV((pin ## _PIN))

#define PIN_BV(pin) (_BV(pin ## _PIN))
#define PIN_NR(pin) (pin ## _PIN)
#define PIN_HIGH(pin) (PIN_CHAR(pin ## _PORT) & _BV(pin ## _PIN))
#define PIN_SET(pin) PORT_CHAR(pin ## _PORT) |= _BV(pin ## _PIN)
#define PIN_CLEAR(pin) PORT_CHAR(pin ## _PORT) &= ~_BV(pin ## _PIN)
#define PIN_TOGGLE(pin) PORT_CHAR(pin ## _PORT) ^= _BV(pin ## _PIN)
#define PIN_PULSE(pin) do { PORT_CHAR(pin ## _PORT) &= ~_BV(pin ## _PIN); \
                            PORT_CHAR(pin ## _PORT) ^=  _BV(pin ## _PIN); \
                          } while(0)

/* spi defines */
#define SPI_MOSI_PORT B
#define SPI_MOSI_PIN 5
#define HAVE_SPI_MOSI 1



#ifdef PB5_USED
#  error Pinning Error: pinning/controllers/atmega32.m4:27: SPI_MOSI has a double define on PB5
#endif
#define PB5_USED 1


#define SPI_MISO_PORT B
#define SPI_MISO_PIN 6
#define HAVE_SPI_MISO 1



#ifdef PB6_USED
#  error Pinning Error: pinning/controllers/atmega32.m4:27: SPI_MISO has a double define on PB6
#endif
#define PB6_USED 1


#define SPI_SCK_PORT B
#define SPI_SCK_PIN 7
#define HAVE_SPI_SCK 1



#ifdef PB7_USED
#  error Pinning Error: pinning/controllers/atmega32.m4:27: SPI_SCK has a double define on PB7
#endif
#define PB7_USED 1


#define SPI_CS_HARDWARE_PORT B
#define SPI_CS_HARDWARE_PIN 4
#define HAVE_SPI_CS_HARDWARE 1



#ifdef PB4_USED
#  error Pinning Error: pinning/controllers/atmega32.m4:27: SPI_CS_HARDWARE has a double define on PB4
#endif
#define PB4_USED 1




#define ADC_CHANNELS 8

/* MCU doesn't support toggling pins by writing to PINx register */
#define PINx_TOGGLE_WORKAROUND

#define _ATMEGA32

#define _SPMCR SPMCR

/* ATmega32 specific adjustments */
#define USART0_UDRE_vect USART_UDRE_vect
#define USART0_RX_vect USART_RXC_vect
#define USART0_TX_vect USART_TXC_vect
#define UPE PE /* parity error */
#define _IVREG MCUCR
#define _EIMSK GICR
#define _EICRA MCUCR
#define ANALOG_COMP_vect ANA_COMP_vect

/* Watchdog status register */
#define MCU_STATUS_REGISTER  MCUCSR

/* Generic timer macros */
#define TC0_PRESCALER_1      {TCCR0&=~(_BV(CS02)|_BV(CS01));TCCR0|=_BV(CS00);}
#define TC0_PRESCALER_8      {TCCR0&=~(_BV(CS02)|_BV(CS00));TCCR0|=_BV(CS01);}
#define TC0_PRESCALER_64     {TCCR0&=~(_BV(CS02));TCCR0|=_BV(CS01)|_BV(CS00);}
#define TC0_PRESCALER_256    {TCCR0&=~(_BV(CS01)|_BV(CS00));TCCR0|=_BV(CS02);}
#define TC0_PRESCALER_1024   {TCCR0&=~(_BV(CS01));TCCR0|=_BV(CS02)|_BV(CS00);}

#define TC0_MODE_OFF	     {TCCR0&=~(_BV(WGM01)|_BV(WGM00));}
#define TC0_MODE_PWM         {TCCR0&=~(_BV(WGM01));TCCR0|=_BV(WGM00);}
#define TC0_MODE_CTC         {TCCR0&=~(_BV(WGM00));TCCR0|=_BV(WGM01);}
#define TC0_MODE_PWMFAST     {TCCR0|=_BV(WGM01)|_BV(WGM00);}

#define TC0_OUTPUT_COMPARE_NONE   {TCCR0&=~(_BV(COM01)|_BV(COM00));}
#define TC0_OUTPUT_COMPARE_TOGGLE {TCCR0&=~(_BV(COM01));TCCR0|=_BV(COM00);}
#define TC0_OUTPUT_COMPARE_CLEAR  {TCCR0&=~(_BV(COM00));TCCR0|=_BV(COM01);}
#define TC0_OUTPUT_COMPARE_SET    {TCCR0|=_BV(COM01)|_BV(COM00);}

#define TC0_COUNTER_CURRENT  TCNT0
#define TC0_COUNTER_COMPARE  OCR0

#define TC0_INT_COMPARE_ON   TIMSK|=_BV(OCIE0);
#define TC0_INT_COMPARE_OFF  TIMSK&=~_BV(OCIE0);
#define TC0_INT_OVERFLOW_ON  TIMSK|=_BV(TOIE0);
#define TC0_INT_OVERFLOW_OFF TIMSK&=~_BV(TOIE0);

#define TC0_INT_COMPARE_TST  (TIFR&_BV(OCF0))
#define TC0_INT_COMPARE_CLR  TIFR=_BV(OCF0);
#define TC0_INT_OVERFLOW_TST (TIFR&_BV(TOV0))
#define TC0_INT_OVERFLOW_CLR TIFR=_BV(TOV0);

#define TC0_VECTOR_OVERFLOW  TIMER0_OVF_vect
#define TC0_VECTOR_COMPARE   TIMER0_COMP_vect

#define TC1_PRESCALER_1      {TCCR1B&=~(_BV(CS12)|_BV(CS11));TCCR1B|=_BV(CS10);}
#define TC1_PRESCALER_8      {TCCR1B&=~(_BV(CS12)|_BV(CS10));TCCR1B|=_BV(CS11);}
#define TC1_PRESCALER_64     {TCCR1B&=~(_BV(CS12));TCCR1B|=_BV(CS11)|_BV(CS10);}
#define TC1_PRESCALER_256    {TCCR1B&=~(_BV(CS11)|_BV(CS10));TCCR1B|=_BV(CS12);}
#define TC1_PRESCALER_1024   {TCCR1B&=~(_BV(CS11));TCCR1B|=_BV(CS12)|_BV(CS10);}

#define TC1_MODE_OFF	     {TCCR1A&=~(_BV(WGM11)|_BV(WGM10));TCCR1B&=~(_BV(WGM12));}
#define TC1_MODE_PWM         {TCCR1A&=~(_BV(WGM11));TCCR1A|=_BV(WGM10);TCCR1B&=~(_BV(WGM12));}
#define TC1_MODE_CTC         {TCCR1A&=~(_BV(WGM10));TCCR1A&=~(_BV(WGM11));TCCR1B|=_BV(WGM12);}
#define TC1_MODE_PWMFAST     {TCCR1A|=_BV(WGM11)|_BV(WGM10);TCCR1B&=~(_BV(WGM12));}

#define TC1_OUTPUT_COMPARE_NONE   {TCCR1A&=~(_BV(COM1A1)|_BV(COM1A0));}
#define TC1_OUTPUT_COMPARE_TOGGLE {TCCR1A&=~(_BV(COM1A1));TCCR1A|=_BV(COM1A0);}
#define TC1_OUTPUT_COMPARE_CLEAR  {TCCR1A&=~(_BV(COM1A0));TCCR1A|=_BV(COM1A1);}
#define TC1_OUTPUT_COMPARE_SET    {TCCR1A|=_BV(COM1A1)|_BV(COM1A0);}

#define TC1_COUNTER_CURRENT  TCNT1
#define TC1_COUNTER_COMPARE  OCR1A

#define TC1_INT_COMPARE_ON   TIMSK|=_BV(OCIE1A);
#define TC1_INT_COMPARE_OFF  TIMSK&=~_BV(OCIE1A);
#define TC1_INT_OVERFLOW_ON  TIMSK|=_BV(TOIE1);
#define TC1_INT_OVERFLOW_OFF TIMSK&=~_BV(TOIE1);

#define TC1_INT_OVERFLOW_TST (TIFR&_BV(TOV1))
#define TC1_INT_OVERFLOW_CLR TIFR=_BV(TOV1);

#define TC1_VECTOR_OVERFLOW  TIMER1_OVF_vect
#define TC1_VECTOR_COMPARE   TIMER1_COMPA_vect

#define TC2_PRESCALER_1      {TCCR2&=~(_BV(CS22)|_BV(CS21));TCCR2|=_BV(CS20);}
#define TC2_PRESCALER_8      {TCCR2&=~(_BV(CS22)|_BV(CS20));TCCR2|=_BV(CS21);}
#define TC2_PRESCALER_32     {TCCR2&=~(_BV(CS22));TCCR2|=_BV(CS21)|_BV(CS20);}
#define TC2_PRESCALER_64     {TCCR2&=~(_BV(CS21)|_BV(CS20));TCCR2|=_BV(CS22);}
#define TC2_PRESCALER_128    {TCCR2&=~(_BV(CS21));TCCR2|=_BV(CS20)|_BV(CS22);}
#define TC2_PRESCALER_256    {TCCR2&=~(_BV(CS20));TCCR2|=_BV(CS22)|_BV(CS21);}
#define TC2_PRESCALER_1024   {TCCR2|=_BV(CS22)|_BV(CS21)|_BV(CS20);}

#define TC2_MODE_OFF	     {TCCR2&=~(_BV(WGM21)|_BV(WGM20));}
#define TC2_MODE_PWM         {TCCR2&=~(_BV(WGM21));TCCR2|=_BV(WGM20);}
#define TC2_MODE_CTC         {TCCR2&=~(_BV(WGM20));TCCR2|=_BV(WGM21);}
#define TC2_MODE_PWMFAST     {TCCR2|=_BV(WGM21)|_BV(WGM20);}

#define TC2_OUTPUT_COMPARE_NONE   {TCCR2&=~(_BV(COM21)|_BV(COM20));}
#define TC2_OUTPUT_COMPARE_TOGGLE {TCCR2&=~(_BV(COM21));TCCR2|=_BV(COM20);}
#define TC2_OUTPUT_COMPARE_CLEAR  {TCCR2&=~(_BV(COM20));TCCR2|=_BV(COM21);}
#define TC2_OUTPUT_COMPARE_SET    {TCCR2|=_BV(COM21)|_BV(COM20);}

#define TC2_COUNTER_CURRENT  TCNT2
#define TC2_COUNTER_COMPARE  OCR2

#define TC2_INT_COMPARE_ON   TIMSK|=_BV(OCIE2);
#define TC2_INT_COMPARE_OFF  TIMSK&=~_BV(OCIE2);
#define TC2_INT_OVERFLOW_ON  TIMSK|=_BV(TOIE2);
#define TC2_INT_OVERFLOW_OFF TIMSK&=~_BV(TOIE2);

#define TC2_INT_COMPARE_TST  (TIFR&_BV(OCF2))
#define TC2_INT_COMPARE_CLR  TIFR=_BV(OCF2);
#define TC2_INT_OVERFLOW_TST (TIFR&_BV(TOV2))
#define TC2_INT_OVERFLOW_CLR TIFR=_BV(TOV2);

#define TC2_VECTOR_OVERFLOW  TIMER2_OVF_vect
#define TC2_VECTOR_COMPARE   TIMER2_COMP_vect

/* First Asyncronous Timer */
/* Flag for asyncronous operation */
#define TIMER_8_AS_1_ASYNC_ON  {ASSR |= _BV(AS2);}
#define TIMER_8_AS_1_ASYNC_OFF  {ASSR &=~(_BV(AS2));}
/* Prescaler */
#define TIMER_8_AS_1_PRESCALER_1 TC2_PRESCALER_1
#define TIMER_8_AS_1_PRESCALER_8 TC2_PRESCALER_8
#define TIMER_8_AS_1_PRESCALER_32 TC2_PRESCALER_32
#define TIMER_8_AS_1_PRESCALER_64 TC2_PRESCALER_64
#define TIMER_8_AS_1_PRESCALER_128 TC2_PRESCALER_128
#define TIMER_8_AS_1_PRESCALER_256 TC2_PRESCALER_512
#define TIMER_8_AS_1_PRESCALER_1024 TC2_PRESCALER_1024
/* PWM Settings */
#define TIMER_8_AS_1_MODE_OFF TC2_MODE_OFF
#define TIMER_8_AS_1_MODE_PWM TC2_MODE_PWM
#define TIMER_8_AS_1_MODE_CTC TC2_MODE_CTC
#define TIMER_8_AS_1_MODE_PWMFAST TC2_MODE_PWMFAST
/* Output Compare */
#define TIMER_8_AS_1_OUTPUT_COMPARE_NONE TC2_OUTPUT_COMPARE_NONE
#define TIMER_8_AS_1_OUTPUT_COMPARE_TOGGLE TC2_OUTPUT_COMPARE_TOGGLE
#define TIMER_8_AS_1_OUTPUT_COMPARE_CLEAR TC2_OUTPUT_COMPARE_CLEAR
#define TIMER_8_AS_1_OUTPUT_COMPARE_SET TC2_OUTPUT_COMPARE_SET
/* Timer Register */
#define TIMER_8_AS_1_COUNTER_CURRENT TC2_COUNTER_CURRENT
#define TIMER_8_AS_1_COUNTER_COMPARE TC2_COUNTER_COMPARE
/* Interrupts / Signals */
#define TIMER_8_AS_1_INT_COMPARE_ON TC2_INT_COMPARE_ON
#define TIMER_8_AS_1_INT_COMPARE_OFF TC2_INT_COMPARE_OFF
#define TIMER_8_AS_1_INT_OVERFLOW_ON TC2_INT_OVERFLOW_ON
#define TIMER_8_AS_1_INT_OVERFLOW_OFF TC2_INT_OVERFLOW_OFF
#define TIMER_8_AS_1_INT_OVERFLOW_TST TC2_INT_OVERFLOW_TST
#define TIMER_8_AS_1_INT_OVERFLOW_CLR TC2_INT_OVERFLOW_CLR
/* Vectors */
#define TIMER_8_AS_1_VECTOR_OVERFLOW TC2_VECTOR_OVERFLOW
#define TIMER_8_AS_1_VECTOR_COMPARE TC2_VECTOR_COMPARE
/* Busy flags */
#define TIMER_8_AS_1_COMPARE_CONTROL_BUSY TCR2UB
#define TIMER_8_AS_1_COUNTER_CURRENT_BUSY TCN2UB
#define TIMER_8_AS_1_COUNTER_CURRENT_BUSY_TST (ASSR&_BV(TIMER_8_AS_1_COUNTER_CURRENT_BUSY))
#define TIMER_8_AS_1_COMPARE_CONTROL_BUSY_TST (ASSR&_BV(TIMER_8_AS_1_COMPARE_CONTROL_BUSY))
/* both tests combined */
#define TIMER_8_AS_1_COUNTER_BUSY_TST (TIMER_8_AS_1_COMPARE_CONTROL_BUSY_TST || TIMER_8_AS_1_COUNTER_CURRENT_BUSY_TST)



/* Timer2 - PWM Melody */
#define _PWM_MELODY_COMP TIMER2_COMP_vect
#define _PWM_MELODY_OCR OCR2
#define _PWM_MELODY_TRCCRA TCCR2
#define _PWM_MELODY_TRCCRB TCCR2
#define _PWM_MELODY_COM1 COM21
#define _PWM_MELODY_COM0 COM20
#define _PWM_MELODY_WGM0 WGM20
#define _PWM_MELODY_CS0 CS20
#define _PWM_MELODY_TIMSK TIMSK
#define _PWM_MELODY_OCIE OCIE2

#define RXD0_PORT  D
#define RXD0_PIN   0

#define TXD0_PORT  D
#define TXD0_PIN   1

/* workaround for avr-libc devs not being able to decide how these registers
 * should be named... */
#ifdef SPCR0
    #define _SPCR0 SPCR0
#else
    #define _SPCR0 SPCR
#endif

#ifdef SPE0
    #define _SPE0 SPE0
#else
    #define _SPE0 SPE
#endif

#ifdef MSTR0
    #define _MSTR0 MSTR0
#else
    #define _MSTR0 MSTR
#endif

#ifdef SPSR0
    #define _SPSR0 SPSR0
#else
    #define _SPSR0 SPSR
#endif

#ifdef SPIF0
    #define _SPIF0 SPIF0
#else
    #define _SPIF0 SPIF
#endif

#ifdef SPDR0
    #define _SPDR0 SPDR0
#else
    #define _SPDR0 SPDR
#endif

#ifdef SPI2X0
    #define _SPI2X0 SPI2X0
#else
    #define _SPI2X0 SPI2X
#endif

/* port the enc28j60 is attached to */
#define SPI_CS_NET_PORT SPI_CS_HARDWARE_PORT
#define SPI_CS_NET_PIN SPI_CS_HARDWARE_PIN
#define HAVE_SPI_CS_NET HAVE_SPI_CS_HARDWARE
































#define PORTIO_MASK_A 255
#define PORTIO_MASK_B 15
#define PORTIO_MASK_C 255
#define PORTIO_MASK_D 255
#define PORTIO_MASK_E 255
#define PORTIO_MASK_F 255
#define PORTIO_MASK_G 255

#define DDR_MASK_A 0
#define DDR_MASK_B 176
#define DDR_MASK_C 0
#define DDR_MASK_D 0
#define DDR_MASK_E 0
#define DDR_MASK_F 0
#define DDR_MASK_G 0

#endif /* _PINNING_HEADER */
