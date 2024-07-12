#define STICK_X 26
#define STICK_Y 27

void setup() {
  // put your setup code here, to run once:
  analogReadResolution(12);
}

void loop() {
  // put your main code here, to run repeatedly:

  float stick_x = analogRead(STICK_X);
  float stick_y = analogRead(STICK_Y);
  
  Serial.print(stick_x);
  Serial.print(",");
  Serial.println(stick_y);

  delay(10);
}
