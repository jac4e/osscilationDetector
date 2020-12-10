// Initialize pins
int laserPin = 2;
int sensorPin = 3;

// Initialize sensor value, threshold, and polling delay 
int value = 0;
int threshold = 300;
int dt = 100;

// Initialize period and time varibles
int t = 0;
int t1 = 0;
int t2 = 0;
int t3 = 0;
int t4 = 0;

// Initiallize count and blocked trackers
int count = 0;
boolean blocked = false;

void setup() {
  Serial.begin(9600);
  Serial.println("Starting...");
  pinMode(laserPin, OUTPUT);
  digitalWrite(laserPin, HIGH);
}

void loop() {
  delay(1000);
  Serial.println("Ready!");
    while (t1==0 || t2==0 || t3==0 || t4==0) {
      Serial.print("Sensor: ");
      // Poll sensor and record corrisponding time variable
      value = analogRead(sensorPin);
      Serial.println(value);
      if (value > threshold && !blocked && t1==0) {
        t1 = millis();
        Serial.print("t1: ");
        Serial.println(t1);
        blocked = true;
      }
      if (value < threshold && blocked && t2==0) {
        t2 = millis();
        Serial.print("t2: ");
        Serial.println(t2);
        blocked = false;
      }
      if (value > threshold && !blocked && t3==0) {
        t3 = millis();
        Serial.print("t3: ");
        Serial.println(t3);
        blocked = true;
      }
      if (value < threshold && blocked && t4==0) {
        t4 = millis();
        Serial.print("t4: ");
        Serial.println(t4);
        blocked = false;
      }
      delayMicroseconds(dt);
    }
    // Add calcualted period to sum of periods.
    t = (t3 + t4) - (t1 + t2);
  Serial.println("Period:");
  // Print average of 5 periods to serial
  Serial.println(t);
}
