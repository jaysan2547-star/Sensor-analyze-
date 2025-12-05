int alcoholSensor = A0; // Connect AO pin of MQ-3 to A0

void setup() {
  Serial.begin(9600);
  Serial.println("MQ-3 Alcohol Detection Started");
}

void loop() {
  int sensorValue = analogRead(alcoholSensor);
  float voltage = sensorValue * (5.0 / 1023.0); // Convert analog value to voltage

  Serial.print("Analog Value: ");
  Serial.print(sensorValue);
  Serial.print(" | Voltage: ");
  Serial.println(voltage);

  // Approximate alcohol level (for demo)
  if (voltage > 4) {
    Serial.println("🚨 Very High Alcohol Concentration!");
    Serial.println("Possibly intoxicated air (e.g., breathalyzer alert)");
  } else if (voltage > 3.5) {
    Serial.println("⚠️ High Alcohol Concentration.");
    Serial.println("Maybe strong alcohol nearby or open container.");
  } else if (voltage > 3.3) {
    Serial.println("🍷 Moderate Alcohol Detected.");
    Serial.println("Could be faint smell of alcohol or cleaner.");
  } else {
    Serial.println("✅ Air is clean (or very low alcohol).");
  }

  Serial.println("--------------------------");
  delay(2000);
}
