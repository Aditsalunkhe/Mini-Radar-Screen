# Arduino Mini Radar

A mini radar built with an Arduino Uno. A servo sweeps an ultrasonic sensor
from 15° to 165°, and an OLED draws a radar line with a blip wherever an
object is detected.

**Live simulation:** https://wokwi.com/projects/477021862835508225

## Features
- Servo sweep with a live radar line on the OLED
- Objects within 100 cm appear as blips at the correct angle and distance
- Runs fully in the Wokwi simulator, no hardware needed

## Components
| Part | Qty |
|---|---|
| Arduino Uno | 1 |
| HC-SR04 ultrasonic sensor | 1 |
| Servo motor (SG90) | 1 |
| SSD1306 OLED 128x64 (I2C) | 1 |

## Wiring
| Component | Pin | Arduino |
|---|---|---|
| HC-SR04 | TRIG | D9 |
| HC-SR04 | ECHO | D10 |
| HC-SR04 | VCC / GND | 5V / GND |
| Servo | Signal | D6 |
| Servo | V+ / GND | 5V / GND |
| OLED | SDA | A4 |
| OLED | SCL | A5 |
| OLED | VCC / GND | 5V / GND |

## Libraries
- Adafruit SSD1306
- Adafruit GFX Library

## How to run
1. Open the Wokwi link above and press the green ▶ button.
2. Click the HC-SR04 and drag its distance slider to place an object.
3. Watch the blip appear on the radar at the matching angle.

## How it works
The servo steps 5° every 30 ms. At each step the HC-SR04 measures distance
with a trigger pulse and `pulseIn()`. The angle and distance are converted
to x/y coordinates with sine and cosine, then drawn on the OLED.

## Future improvements
- Fading trail behind the sweep line
- Range rings and distance labels
- Buzzer alert for close objects

## License
MIT
