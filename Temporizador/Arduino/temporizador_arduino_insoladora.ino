/*----------------------------------------------------- 
Author:  Carlos Escura
Date: Thu Apr 18 13:55:10 2013
Description:
*/

#include <EEPROM.h>
#include <LiquidCrystal.h>

#define Bpreset1 A0
#define Bpreset2 A1
#define Bpreset3 A2
#define Bsegundos A3
#define Bminutos 8
#define Bcomienzo 9

#define pinSalida 7

#define MApreset1 1
#define MApreset2 2
#define MApreset3 3






//--------------------------CANCIONES----------------------------//

int speakerPin = 11;
//speaker connected to one of the PWM ports
 
#define c 261
#define d 294
#define e 329
#define f 349
#define g 391
#define gS 415
#define a 440
#define aS 455
#define b 466
#define cH 523
#define cSH 554
#define dH 587
#define dSH 622
#define eH 659
#define fH 698
#define fSH 740
#define gH 784
#define gSH 830
#define aH 880


//------------------------//

 
//Tiempo
byte minutos;
byte segundos;

// LiquidCrystal lcd(RS, E, D4, D5, D6, D7);
LiquidCrystal lcd(12, 6, 5, 4, 3, 2);


void setup() {
   
   pinMode(Bcomienzo, INPUT);
   pinMode(Bminutos, INPUT);
   pinMode(Bsegundos, INPUT);
   pinMode(pinSalida, OUTPUT);
   pinMode(Bpreset1, INPUT);
   pinMode(Bpreset2, INPUT);
   pinMode(Bpreset3, INPUT);
   pinMode(speakerPin, OUTPUT); 
   //pinMode(buzzerPin, OUTPUT);
  
  lcd.begin(16, 2);
  lcd.setCursor(3,0);
  lcd.print("INSOLADORA");
  lcd.setCursor(5,1);
  lcd.print("LED-UV");
  delay(3000);
    
  lcd.clear();
  
    
  lcd.setCursor(4,0);
  lcd.print("SELECCION");
  lcd.setCursor(0,1);
  lcd.print("TIEMPO INSOLADO");
  
  delay(3000);
  lcd.clear();
    
  minutos = 0;
  segundos = 0;  
 
}


///////////////-----------------------------------------------------------------/////
//////////////--------------------------MARCHA IMPERIAL ------------------------/////



void beep (unsigned char speakerPin, int frequencyInHertz, long timeInMilliseconds)
{ 
   
    
    int x; 	 
    long delayAmount = (long)(1000000/frequencyInHertz);
    long loopTime = (long)((timeInMilliseconds*1000)/(delayAmount*2));
    for (x=0;x<loopTime;x++) 	 
    { 	 
        digitalWrite(speakerPin,HIGH);
        delayMicroseconds(delayAmount);
        digitalWrite(speakerPin,LOW);
        delayMicroseconds(delayAmount);
    } 	 
    
   
    
    delay(20);
    //a little delay to make all notes sound separate
} 	 
  	 
void march()
{ 
    
    beep(speakerPin, a, 500); 
    beep(speakerPin, a, 500);     
    beep(speakerPin, a, 500); 
    beep(speakerPin, f, 350); 
    beep(speakerPin, cH, 150);
    
    beep(speakerPin, a, 500);
    beep(speakerPin, f, 350);
    beep(speakerPin, cH, 150);
    beep(speakerPin, a, 1000);
    //first bit
    
    beep(speakerPin, eH, 500);
    beep(speakerPin, eH, 500);
    beep(speakerPin, eH, 500);    
    beep(speakerPin, fH, 350); 
    beep(speakerPin, cH, 150);
    
    beep(speakerPin, gS, 500);
    beep(speakerPin, f, 350);
    beep(speakerPin, cH, 150);
    beep(speakerPin, a, 1000);
    //second bit...
    
    beep(speakerPin, aH, 500);
    beep(speakerPin, a, 350); 
    beep(speakerPin, a, 150);
    beep(speakerPin, aH, 500);
    beep(speakerPin, gSH, 250); 
    beep(speakerPin, gH, 250);
    
    beep(speakerPin, fSH, 125);
    beep(speakerPin, fH, 125);    
    beep(speakerPin, fSH, 250);
    delay(250);
    beep(speakerPin, aS, 250);    
    beep(speakerPin, dSH, 500);  
    beep(speakerPin, dH, 250);  
    beep(speakerPin, cSH, 250);  
    //start of the interesting bit
    
    beep(speakerPin, cH, 125);  
    beep(speakerPin, b, 125);  
    beep(speakerPin, cH, 250);      
    delay(250);
    beep(speakerPin, f, 125);  
    beep(speakerPin, gS, 500);  
    beep(speakerPin, f, 375);  
    beep(speakerPin, a, 125); 
    
    beep(speakerPin, cH, 500); 
    beep(speakerPin, a, 375);  
    beep(speakerPin, cH, 125); 
    beep(speakerPin, eH, 1000); 
    //more interesting stuff (this doesn't quite get it right somehow)
    
    beep(speakerPin, aH, 500);
    beep(speakerPin, a, 350); 
    beep(speakerPin, a, 150);
    beep(speakerPin, aH, 500);
    beep(speakerPin, gSH, 250); 
    beep(speakerPin, gH, 250);
    
    beep(speakerPin, fSH, 125);
    beep(speakerPin, fH, 125);    
    beep(speakerPin, fSH, 250);
    delay(250);
    beep(speakerPin, aS, 250);    
    beep(speakerPin, dSH, 500);  
    beep(speakerPin, dH, 250);  
    beep(speakerPin, cSH, 250);  
    //repeat... repeat
    
    beep(speakerPin, cH, 125);  
    beep(speakerPin, b, 125);  
    beep(speakerPin, cH, 250);      
    delay(250);
    beep(speakerPin, f, 250);  
    beep(speakerPin, gS, 500);  
    beep(speakerPin, f, 375);  
    beep(speakerPin, cH, 125); 
           
    beep(speakerPin, a, 500);            
    beep(speakerPin, f, 375);            
    beep(speakerPin, c, 125);            
    beep(speakerPin, a, 1000);       
    //and we're done \ó/    
}





void imprime_guardando(byte memo){
  lcd.clear();
  lcd.setCursor(3,0);
  lcd.print("GUARDANDO ");
  lcd.setCursor(3,1);
  lcd.print("MEMORIA ");
  lcd.setCursor(11,1);
  lcd.print(memo, 10);
  delay(1500);
}

void imprime_leyendo(int val){
  lcd.clear();
  lcd.setCursor(4,0);
  lcd.print("LEYENDO");
  lcd.setCursor(3,1);
  lcd.print("MEMORIA");
  lcd.setCursor(11,1);
  lcd.print(val, 10);
  delay(2000);
  lcd.clear();

}
void imprime_guardado_completo(){
  lcd.clear();
  lcd.setCursor(4,0);
  lcd.print("Success!");
  delay(1500);

}
void anti_rebote_minutos (){

if (digitalRead(Bminutos)==HIGH){
    delay(40);
    if (digitalRead(Bminutos) == HIGH){
    minutos += 1;
    delay(90);
    }
   }
   }
   
   
void anti_rebote_segundos (){

if (digitalRead(Bsegundos)==HIGH){
    delay(40);
    if (digitalRead(Bsegundos) == HIGH){
    if(segundos <=58){
    segundos += 1;
    }else if(segundos = 59){
    //limpiar caracter lcd
    lcd.clear();
    segundos = 0;
    minutos += 1;
    }
    delay(50);
    }
   }
   }
   

void print_comienzo(){
    
    lcd.clear();
    lcd.setCursor(4,0);
    lcd.print("Let's Go");
    delay(2500);
    lcd.clear();

}

void print_cuenta_atras(){

do{

  if (segundos > 0){
             
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("MINUTOS: ") ;
      lcd.print(minutos, 10);
      lcd.setCursor(0,1);
      lcd.print("SEGUNDOS: ");
      lcd.print(segundos, 10);
      delay (1000);
      segundos --;   
     
    
  }
   
  if (minutos > 0){
      if (segundos <= 0){
      minutos--;
      segundos = 59; 
      }
  
  }
 }while (segundos != 0);

}

void print_finalizado(){

  lcd.clear();
  lcd.setCursor(3,0);
  lcd.print("INSOLACION");
  lcd.setCursor(3,1);
  lcd.print("FINALIZADA");
  delay(3000);
  lcd.clear();
  lcd.setCursor(3,0);
  lcd.print("Thinking4u");
  lcd.setCursor(0,2);
  lcd.print("Design Carlitoss");


}


void check_preset(byte button, byte memoryAddress){
    
    if (digitalRead(button)==HIGH){
        delay(10);
        if(digitalRead(button)==HIGH){
            delay(1000);
            if (digitalRead(button) == LOW){
               //Se ha soltado, leemos de eeprom
               imprime_leyendo(memoryAddress);
               minutos = EEPROM.read(memoryAddress); 
               delay(100);
               segundos = EEPROM.read(memoryAddress+10);
               delay(100);
               lcd.clear();
               
            } else if (digitalRead(button) == HIGH){    //Sigue pulsado write a eeprom
               imprime_guardando(memoryAddress);
               delay(100);
               EEPROM.write(memoryAddress, minutos);
               delay(100);
               lcd.clear();
               //imprime_guardando(segundos);
               EEPROM.write(memoryAddress+10, segundos);
               delay(500); 
               imprime_guardado_completo();
               delay(500);
               lcd.clear();
            }
        }
    }
}




void loop() {
 
 
   anti_rebote_minutos();
   anti_rebote_segundos();
   check_preset(Bpreset1, MApreset1);
   check_preset(Bpreset2, MApreset2);
   check_preset(Bpreset3, MApreset3);
   delay(20);
     

   lcd.setCursor(0,0);
   lcd.print("MINUTOS: ");
   lcd.print(minutos,10);
   lcd.setCursor(0,1);
   lcd.print("SEGUNDOS: ");
   lcd.print(segundos,10);
   
   if(digitalRead(Bcomienzo) == HIGH){
      delay (40);
      if(digitalRead(Bcomienzo) == HIGH){
        print_comienzo();
        digitalWrite(pinSalida, 1);
        print_cuenta_atras();
        digitalWrite(pinSalida, 0);
        print_finalizado();
        march();
        lcd.clear();
      }
   }

}


