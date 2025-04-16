#include <DHT.h>
#include <LiquidCrystal_I2C.h>

const int DHT_pin = 8;
const int DHT_TYPE = DHT22;
DHT dht(DHT_pin, DHT_TYPE);

const int ROWS = 4;
const int COLS = 20;
LiquidCrystal_I2C lcd(0x27, COLS, ROWS);

const int BUZZER = 3;

void setup() {
  dht.begin();
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  pinMode(BUZZER, OUTPUT);
}

void showLCD(float a, float b, float k) {
  lcd.setCursor(0, 0);
  lcd.print("[Temp/Humi Sensor]");
  lcd.setCursor(0, 1);
  lcd.print("Temp>>> "); lcd.print(a); lcd.print(" *C");
  lcd.setCursor(0, 2);
  lcd.print("Humi>>> "); lcd.print(b); lcd.print(" %");
  lcd.setCursor(0, 3);
  lcd.print("Heat Index: "); lcd.print(k); lcd.print(" *C");
}

void alarm(int k) {
  digitalWrite(BUZZER, HIGH);
  delay(k);
  digitalWrite(BUZZER, LOW);
  delay(k);
}

void sendData(float t, float h, float hi) {
  Serial.print(t); Serial.print(",");
  Serial.print(h); Serial.print(",");
  Serial.println(hi);  // 개행으로 한 묶음 전송
}

void loop() {
  float temp = dht.readTemperature();
  float humi = dht.readHumidity();
  float heatIndex = dht.computeHeatIndex(temp, humi);

  showLCD(temp, humi, heatIndex);
  sendData(temp, humi, heatIndex);

  if (temp > 60) {
    for (int i = 0; i < 5; i++) alarm(100);
  } else if (temp > 50) {
    alarm(500);
  } else if (temp > 40) {
    alarm(1000);
  }

  delay(1000);
  lcd.clear();
}