void setup() {
  //Pin 4 dideklarasikan sebagai OUTPUT
  pinMode(4, OUTPUT);
}

void loop() {
  //Pin 4 dinyatakan sebagai pin aktif
  digitalWrite(4, HIGH);
  delay(1000);
  digitalWrite(4, LOW);
  delay(1000);
}
