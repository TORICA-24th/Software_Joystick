#include <Servo.h>

const byte SERVO_ID = 0x01; // サーボのIDを設定（例: 1）
const byte CMD_TMPLIM = 0x04; // 温度制限コマンド
const byte MAX_TEMPERATURE_LIMIT = 0x7F; // 最大温度制限値

void setup() {
  // シリアルモニタの開始
  Serial.begin(9600);
  // ICS用シリアルポートの開始
  Serial1.begin(115200);
  
  // 温度制限を設定
  setTemperatureLimit(SERVO_ID, MAX_TEMPERATURE_LIMIT);
}

void loop() {
  // メインループ内で特にすることはない
}

void setTemperatureLimit(byte id, byte limit) {
  byte command[] = {0xA0 | id, CMD_TMPLIM, limit};
  sendCommand(command, sizeof(command));
  
  // 返答を待つ
  while (!Serial1.available()) {
    delay(10);
  }
  while (Serial1.available()) {
    byte response = Serial1.read();
    Serial.print("Response: 0x");
    Serial.println(response, HEX);
  }
}

void sendCommand(byte* command, byte length) {
  // コマンドを送信
  for (byte i = 0; i < length; i++) {
    Serial1.write(command[i]);
  }
}
