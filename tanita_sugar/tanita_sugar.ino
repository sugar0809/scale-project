/*
  Tanita Digital Scale Decode Example : decode LCD display
  TANITA KD-320-WH
  (c) Jun Rekimoto 2013.1.17
  see internal blog :
  http://rekilabgroup.wordpress.com/2013/01/17/%E3%82%AD%E3%83%83%E3%83%81%E3%83%B3%E3%82%B9%E3%82%B1%E3%83%BC%E3%83%AB%E3%83%8F%E3%83%83%E3%82%AF/
 */

// LCD has 17 pins (pin1 .... pin17)
// 4桁目（左から1番目）
int pin2 = 2;
int pin3 = 3;
// 3桁目（左から2番目）
int pin4 = 4;
int pin5 = 5;
// 2桁目（左から3番目）
int pin6 = 6;
int pin7 = 7;
//1桁目（左から4番目）
int pin8 = 8;
int pin9 = 9;
//小数点以下（左から5番目）
int pin10 = 10;
int pin11= 11;

int led = 13;
int clk = A1;  // connect to pin 14
int digit[10] = {
B10111110,
B00000110,
B01111100,
B01011110,
B11000110,
B11011010,
B11111010,
B10001110,
B11111110,
B11011110
};

int delay_half= 1667; // 1.666 ms
int delay_one = 3333; // 3.33 ms = 333 us

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);//(115200);

  // make the pushbutton's pin an input:
  pinMode(pin2, INPUT);
  pinMode(pin3, INPUT);
  pinMode(pin4, INPUT);
  pinMode(pin5, INPUT);
  pinMode(pin6, INPUT);
  pinMode(pin7, INPUT);
  pinMode(pin8, INPUT);
  pinMode(pin9, INPUT);
  pinMode(pin10, INPUT);
  pinMode(pin11, INPUT);
  pinMode(led, OUTPUT);

}

// 0002 3331 --- 00001110

// the loop routine runs over and over again forever:
void loop() {
  int data2[8];
  int data3[8];
  int data4[8];
  int data5[8];
  int data6[8];
  int data7[8];
  int data8[8];
  int data9[8];
  int data10[8];
  int data11[8];
  int i;
  
  digitalWrite(led, LOW);
  
  noInterrupts(); // for accurate delay count
  
    // pin 2
  while (analogRead(clk) > 25)
    ;
  while (analogRead(clk) < 25)
    ;
  delayMicroseconds(delay_half);
  //digitalWrite(led, HIGH);
  for (i = 0; i < 8; i++) {
    digitalWrite(led, HIGH);
    delayMicroseconds(100);
    data2[i] = digitalRead(pin2);
    delayMicroseconds(100);
    digitalWrite(led, LOW);
    delayMicroseconds(3500);
    //delayMicroseconds(delay_one);
  }
  // pin 3
   while (analogRead(clk) > 25)
    ;
  while (analogRead(clk) < 25)
    ;
  delayMicroseconds(delay_half);
  //digitalWrite(led, HIGH);
  for (i = 0; i < 8; i++) {
    digitalWrite(led, HIGH);
    delayMicroseconds(100);
    data3[i] = digitalRead(pin3);
    delayMicroseconds(100);
    digitalWrite(led, LOW);
    delayMicroseconds(3500);
    //delayMicroseconds(delay_one);
  }
  
  // pin 4
  while (analogRead(clk) > 25)
    ;
  while (analogRead(clk) < 25)
    ;
  delayMicroseconds(delay_half);
  //digitalWrite(led, HIGH);
  for (i = 0; i < 8; i++) {
    digitalWrite(led, HIGH);
    delayMicroseconds(100);
    data4[i] = digitalRead(pin4);
    delayMicroseconds(100);
    digitalWrite(led, LOW);
    delayMicroseconds(3500);
    //delayMicroseconds(delay_one);
  }
  // pin 5
   while (analogRead(clk) > 25)
    ;
  while (analogRead(clk) < 25)
    ;
  delayMicroseconds(delay_half);
  //digitalWrite(led, HIGH);
  for (i = 0; i < 8; i++) {
    digitalWrite(led, HIGH);
    delayMicroseconds(100);
    data5[i] = digitalRead(pin5);
    delayMicroseconds(100);
    digitalWrite(led, LOW);
    delayMicroseconds(3500);
    //delayMicroseconds(delay_one);
  }
    
  // pin 6
  while (analogRead(clk) > 25)
    ;
  while (analogRead(clk) < 25)
    ;
  delayMicroseconds(delay_half);
  //digitalWrite(led, HIGH);
  for (i = 0; i < 8; i++) {
    digitalWrite(led, HIGH);
    delayMicroseconds(100);
    data6[i] = digitalRead(pin6);
    delayMicroseconds(100);
    digitalWrite(led, LOW);
    delayMicroseconds(3500);
    //delayMicroseconds(delay_one);
  }
  // pin 7
   while (analogRead(clk) > 25)
    ;
  while (analogRead(clk) < 25)
    ;
  delayMicroseconds(delay_half);
  //digitalWrite(led, HIGH);
  for (i = 0; i < 8; i++) {
    digitalWrite(led, HIGH);
    delayMicroseconds(100);
    data7[i] = digitalRead(pin7);
    delayMicroseconds(100);
    digitalWrite(led, LOW);
    delayMicroseconds(3500);
    //delayMicroseconds(delay_one);
  }
  
  // pin 8
  while (analogRead(clk) > 25)
    ;
  while (analogRead(clk) < 25)
    ;
  delayMicroseconds(delay_half);
  //digitalWrite(led, HIGH);
  for (i = 0; i < 8; i++) {
    digitalWrite(led, HIGH);
    delayMicroseconds(100);
    data8[i] = digitalRead(pin8);
    delayMicroseconds(100);
    digitalWrite(led, LOW);
    delayMicroseconds(3500);
    //delayMicroseconds(delay_one);
  }
  // pin 9
   while (analogRead(clk) > 25)
    ;
  while (analogRead(clk) < 25)
    ;
  delayMicroseconds(delay_half);
  //digitalWrite(led, HIGH);
  for (i = 0; i < 8; i++) {
    digitalWrite(led, HIGH);
    delayMicroseconds(100);
    data9[i] = digitalRead(pin9);
    delayMicroseconds(100);
    digitalWrite(led, LOW);
    delayMicroseconds(3500);
    //delayMicroseconds(delay_one);
  }
  
  // pin 10
  while (analogRead(clk) > 25)
    ;
  while (analogRead(clk) < 25)
    ;
  delayMicroseconds(delay_half);
  //digitalWrite(led, HIGH);
  for (i = 0; i < 8; i++) {
    digitalWrite(led, HIGH);
    delayMicroseconds(100);
    data10[i] = digitalRead(pin10);
    delayMicroseconds(100);
    digitalWrite(led, LOW);
    delayMicroseconds(3500);
    //delayMicroseconds(delay_one);
  }

  // pin 11
   while (analogRead(clk) > 25)
    ;
  while (analogRead(clk) < 25)
    ;
  delayMicroseconds(delay_half);
  //digitalWrite(led, HIGH);
  for (i = 0; i < 8; i++) {
    digitalWrite(led, HIGH);
    delayMicroseconds(100);
    data11[i] = digitalRead(pin11);
    delayMicroseconds(100);
    digitalWrite(led, LOW);
    delayMicroseconds(3500);
    //delayMicroseconds(delay_one);
  }
  
  interrupts();
/*    
  for (i = 0; i < 8; i++) {
    Serial.print(data1[i]);
  }
  Serial.print(' ');
  for (i = 0; i < 8; i++) {
    Serial.print(data2[i]);
  }
  
  for (i = 0; i < 8; i++) {
    Serial.print(data3[i]);
  }
  Serial.print(' ');
  for (i = 0; i < 8; i++) {
    Serial.print(data4[i]);
  }
  */
  
  int d = 0;
  
  for (i = 4; i < 8; i++) {
    d = d << 1;
    d |= data2[i];
  }
  for (i = 4; i < 8; i++) {
    d = d << 1;
    d |= data3[i];
  }
  
  //Serial.println();
  // Serial.print("data=");
  // Serial.println(d);
  for (i = 0; i < 10; i++) {
    if ((B11111110 & d) == digit[i]) {
      Serial.print(" digit = ");
      Serial.print(i);
    }
  }
  if (B1 & d) {
    Serial.print(".");
  }
  //Serial.println();
  
  for (i = 4; i < 8; i++) {
    d = d << 1;
    d |= data4[i];
  }
  for (i = 4; i < 8; i++) {
    d = d << 1;
    d |= data5[i];
  }
  
    for (i = 0; i < 10; i++) {
    if ((B11111110 & d) == digit[i]) {
      //Serial.print(" digit = ");
      Serial.print(i);
    }
  }
  if (B1 & d) {
    Serial.print(".");
  }
  //Serial.println();
  
  //
    for (i = 4; i < 8; i++) {
    d = d << 1;
    d |= data6[i];
  }
  for (i = 4; i < 8; i++) {
    d = d << 1;
    d |= data7[i];
  }
  
    for (i = 0; i < 10; i++) {
    if ((B11111110 & d) == digit[i]) {
      //Serial.print(" digit = ");
      Serial.print(i);
    }
  }
  if (B1 & d) {
    Serial.print(".");
  }
  //Serial.println();
  
  //
    for (i = 4; i < 8; i++) {
    d = d << 1;
    d |= data8[i];
  }
  for (i = 4; i < 8; i++) {
    d = d << 1;
    d |= data9[i];
  }
  
    for (i = 0; i < 10; i++) {
    if ((B11111110 & d) == digit[i]) {
      //Serial.print(" digit = ");
      Serial.print(i);
    }
  }
  if (B1 & d) {
    Serial.print(".");
  }
  //Serial.println();
  
  //
    for (i = 4; i < 8; i++) {
    d = d << 1;
    d |= data10[i];
  }
  for (i = 4; i < 8; i++) {
    d = d << 1;
    d |= data11[i];
  }
  
    for (i = 0; i < 10; i++) {
    if ((B11111110 & d) == digit[i]) {
      //Serial.print(" digit = ");
      Serial.print(i);
    }
  }
  if (B1 & d) {
    Serial.print(".");
  }
  Serial.println();
  delay(100);//2013.6.11 added for Konashi
}

