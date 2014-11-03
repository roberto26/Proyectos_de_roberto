int c;
int potenciometro;
String n;
String m;
String o;
String p;
// creo las cadenas que me leeran los estrados de las entradas y salidas


void  setup() {                    // ejecutar una vez, cuando se inicia el bosquejo

  Serial.begin (9600);    
  pinMode(12,OUTPUT);
  pinMode(2,INPUT);

  digitalWrite(12, LOW);
  Serial.println("Conectado Roberto");
}

void  loop()  {                      // ejecutar una y otra vez
potenciometro = analogRead ( A0 ) ;
n="/"+String(potenciometro)+"/"+String("0")+"/"+String("0")+"/";
m="/"+String(potenciometro)+"/"+String("1")+"/"+String("1")+"/";
o="/"+String(potenciometro)+"/"+String("1")+"/"+String("0")+"/";
p="/"+String(potenciometro)+"/"+String("0")+"/"+String("1")+"/";
// condiciones para leer el estado del led


  
  // condiciones para encender o apagar el led
 if (Serial.available()>0) { //Si está disponible
    c = Serial.read(); //Guardamos la lectura en una variable char
  if (c == 'e') { //Si es una 'h', enciendo el LED
    digitalWrite(12, HIGH);
  } 
  else if (c == 'a') { //Si es una 'l', apago el LED
    digitalWrite(12, LOW);
  }
if (c=='i'){
  if ((digitalRead(12)==HIGH)&&(digitalRead(2)==HIGH)){
  
    Serial.println(m);
   
  }
  if ((digitalRead(12)==LOW)&&(digitalRead(2)==LOW)){
    
    Serial.println(n);

  
  }
  // condiciones para leer el pulsador
  if ((digitalRead(12)==HIGH)&&(digitalRead(2)==LOW)){
  
    Serial.println(o);

  }
  if ((digitalRead(12)==LOW)&&(digitalRead(2)==HIGH)){
    
    Serial.println(p);

  }
 }
 }

}
