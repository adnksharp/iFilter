#include <EMA.hpp>
#include <SERVO.hpp>
#define A0 26
#define OUT 13

int hard[2] = {0, 0};

Servo servo;
EMA ema;

void setup ()
{
	Serial.begin(115200);
	servo.define(OUT);
}

void loop ()
{
	hard[0] = analogRead(A0);
	ema.filter(float(hard[0]), 4095.0);
	hard[1] = map(ema.soft(), 0, 4095, 0, 180);
	servo.write(hard[1]);
	ema.print(hard[1]);

}
