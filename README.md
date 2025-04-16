# arduino-sensor-python-link
# Arduino Serial Sensor Communication

This project demonstrates how to measure temperature and humidity using the DHT22 sensor with Arduino, and send the data via serial communication to a PC for monitoring and logging using Python.

## Features
- Real-time temperature/humidity/heat index display on LCD
- Buzzer alarm based on temperature threshold
- Serial communication with PC (9600 baud rate)
- Python script to receive and display data

## Components
- Arduino UNO
- DHT22 Sensor
- LCD I2C Display
- Buzzer
- PC (Python 3.x)

## Usage
1. Upload `SensorSender.ino` to Arduino.
2. Connect the Arduino to your PC via USB.
3. Run `ReceiverPC.py` on your PC (adjust COM port as needed).

[한국어 README 보러가기 ➡️](README_KR.md)
