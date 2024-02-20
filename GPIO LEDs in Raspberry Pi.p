# blink the LEDs 
import RPi.GPIO as GPIO
import time
ledpin1 = 14
ledpin2 = 15
ledpin3 = 18

GPIO.setmode(GPIO.BCM) # Broadcom pin-numbering scheme
GPIO.setup(ledpin1, GPIO.OUT) # LED pin set as output
GPIO.setup(ledpin2, GPIO.OUT) # LED pin set as output
GPIO.setup(ledpin3, GPIO.OUT) # LED pin set as output
# make LEDs low/off
GPIO.output(ledpin1, GPIO.LOW) 
GPIO.output(ledpin2, GPIO.LOW) 
GPIO.output(ledpin3, GPIO.LOW) 
time.sleep (1)
# make LEDs high/on
GPIO.output(ledpin1, GPIO.HIGH) 
GPIO.output(ledpin2, GPIO.HIGH) 
GPIO.output(ledpin3, GPIO.HIGH) 
time.sleep (1)
