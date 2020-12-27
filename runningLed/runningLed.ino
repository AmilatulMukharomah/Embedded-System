void setup() {
  // Pin 3, 4, dan 5 dideklarasikan sebagai OUTPUT
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() {
  // Pin 3 dinyatakan sebagai pin aktif
  digitalWrite(3, HIGH);
  delay(100); //jeda waktu selama 0.1 detik
  // Pin 4 dinyatakan sebagai pin aktif
  digitalWrite(4, HIGH);
  delay(100); //jeda waktu selama 0.1 detik
  // Pin 5 dinyatakan sebagai pin aktif
  digitalWrite(5, HIGH);
  delay(100); //jeda waktu selama 0.1 detik
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  delay(100);
}
