//Analog pin connected to the pressure sensor
#define pressurePin1 A0
#define pressurePin2 A1

//Digital pin connected to the relay
#define relayPin1 5
#define relayPin2 8
#define relayPin3 10
#define Pin0 0
#define Pin1 1
#define Pin2 2
#define Pin3 3
#define Pin6 6

void setup() {
  //Initialize the relays to an OFF state
  digitalWrite(relayPin1, LOW);
  digitalWrite(Pin1, HIGH);
  digitalWrite(Pin0, HIGH);
  digitalWrite(Pin2, HIGH);
  digitalWrite(Pin3, HIGH);

  //Set relay pins as output
  pinMode(relayPin1, OUTPUT);
  pinMode(relayPin2, OUTPUT);

  Serial.begin(9600);

  //Initialize the pressure sensor pins as inputs
  pinMode(pressurePin1, INPUT);
  pinMode(pressurePin2, INPUT);
}

void loop() {
  //Read the analog value from the 1st pressure sensor
  int pressureValue1 = analogRead(pressurePin1);
  int threshold = 100;
  Serial.println(pressureValue1 );

  //digitalWrite(relayPin1, LOW);

  //Read the analog value from the 2nd pressure sensor
  int pressureValue2 = analogRead(pressurePin2);
  Serial.println(pressureValue2);
  //digitalWrite(relayPin2, LOW);

  //Adjust the threshold value according to the sensor
  if (pressureValue2 || pressureValue1  > 30) {         
    digitalWrite(relayPin2, HIGH);

    digitalWrite(relayPin1, HIGH);
      //Turn on the 2nd relay
  } else {
    digitalWrite(relayPin1, LOW);
    digitalWrite(relayPin2, LOW); 
   //Turn off the 2nd relay
  }
}
  //Adjust the threshold value according to the sensor


  //ref @astrohaptics in Instagram
  // AeroSpace Conference 2024
