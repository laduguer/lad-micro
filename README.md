# lad-micro

This repository comtains experiments with ATTiny85 in embedded C.
The goal is to extract re-usable code to the `/laduguer` folder as much as possible.  


- Makefile: Makefile to do actions trough the `make` command. Using a Tiny AVR Programmer from SparkFun for testing and prototyping
- laduguer
    - serial: Serial communication with ATTiny. For testing an Adruino is hooked up to PB0 on the ATTiny and connected to pin 1 (tx) on the arduino. 
    Either the Arduino IDE's serial monitor or another monitor (e.g. CLion Serial Monitor plugin) can be used to read the output. 