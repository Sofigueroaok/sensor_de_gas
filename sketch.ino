#define MQ2pin 16 // define la conexion del sensor de gas
int buzzer= 8; // define la conexion del buzzer
int verde= 11;
int rojo= 12;

int sensorValue;  //variables donde se guarda los valores leidos por el sensor

void setup() {
  Serial.begin(9600); // sets the serial port to 9600
  Serial.println("MQ2 warming up");
  pinMode(MQ2pin, INPUT); //configura el pin del sensor como ENTRADA
  pinMode(buzzer, OUTPUT);//configura el buzzer como SALIDA
	pinMode(verde, OUTPUT); //configura el led como SALIDA
	pinMode(rojo, OUTPUT);//configura el led como SALIDA
  delay(200); // allow the MQ2 to warm up
}

void loop() {
  sensorValue = digitalRead(MQ2pin);  // Lee el estado DIGITAL del sensor MQ-2.
  Serial.println("Digital Output: ");
  Serial.print(sensorValue); //  El resultado se guarda en la variable sensorValue.
  if(sensorValue == 0){// Muestra el valor obtenido del sensor. Puede aparecer 0 o 1.
		digitalWrite(rojo, HIGH);//el sensor detectó la condición configurada.
    analogWrite(buzzer, HIGH);//se activa el buzzer
		digitalWrite(verde, LOW);// HIGH significa que se envía una señal alta al pin.
  }else{
    //el sensor devuelve 0
		digitalWrite(verde, HIGH); // El sensor no detecto gas
    analogWrite(buzzer, LOW);// se desactiva el buzzer
		digitalWrite(rojo, LOW);// LOW significa que no se envia señal al pin.
  }

  delay(2000); // Espera 200 milisegundos hasta la siguiente lectura
}