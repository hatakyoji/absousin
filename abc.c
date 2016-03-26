/*
 * abc.c
 *
 * Created: 2011/12/15 11:26:25
*/


#include <avr/io.h>
#define USART_BPS	2082
void Usart_init( void )
{
	UBRR1 = USART_BPS;
	UCSR1B = 0b00011000;	
	UCSR1C = 0b00000110;	
	DDRA = 0b00001000;	
	DDRD = 0b00001000;

}

void Usart_sndchar( char data )
{

	while( !( UCSR1A & 0b00100000 )){
	    ;					
   }
	UDR1 = data;			
}

int main( void )
{
	char data = ' ';		
	int x;	
	Usart_init();			
	PORTA = 0b01100000;

	while(1){
		x = PINA;
		x = ~x;
		x = x & 0b01100000;		
		if( x == 0b00100000 ){
			PORTA=0b01101000;
			Usart_sndchar( 0x61 );
			
		}			
		if( x == 0b01000000 ){
			PORTA=0b01100000;
			Usart_sndchar( 0x62 );
		}
	}		
	return 0;
}

