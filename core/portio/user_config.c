
/* Autogenerated File */
#define OUTPUT 0
#define INPUT 1
#define LOW 0
#define HIGH 1

/* fix for MCU missing PORTA (http://bugs.ethersex.de/view.php?id=166) */
#ifdef PORTA
#define PORT_CORR 0
#else
#define PORT_CORR 1
#endif

const char named_pin_text31703[] PROGMEM = "p1";
const char named_pin_text5300[] PROGMEM = "p2";
const char named_pin_text16671[] PROGMEM = "p3";
const char named_pin_text1860[] PROGMEM = "p4";

const struct PinConfiguration portio_pincfg[] PROGMEM = {
    /*  port	pin	input	reverse? */
	{	0 - PORT_CORR,	0,	OUTPUT,	HIGH,	named_pin_text31703 }, 	/* p1	*/ 
	{	0 - PORT_CORR,	1,	OUTPUT,	HIGH,	named_pin_text5300 }, 	/* p2	*/ 
	{	0 - PORT_CORR,	2,	OUTPUT,	HIGH,	named_pin_text16671 }, 	/* p3	*/ 
	{	0 - PORT_CORR,	3,	OUTPUT,	HIGH,	named_pin_text1860 }, 	/* p4	*/ 

    /* mark the end of the list */
    { 255, 255, 255, 255, NULL}
};
