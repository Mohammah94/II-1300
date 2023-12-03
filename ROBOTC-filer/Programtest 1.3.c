#pragma config(Sensor, S1,     touchSensor,    sensorEV3_Touch)
#pragma config(Sensor, S2,     gyroSensor,     sensorEV3_Gyro, modeEV3Gyro_RateAndAngle)
#pragma config(Sensor, S3,     colorSensor,    sensorEV3_Color, modeEV3Color_Color)
#pragma config(Sensor, S4,     sonarSensor,    sensorEV3_Ultrasonic)
#pragma config(Motor,  motorA,          armMotor,      tmotorEV3_Large, openLoop, encoder)
#pragma config(Motor,  motorB,          leftMotor,     tmotorEV3_Large, openLoop, driveLeft, encoder)
#pragma config(Motor,  motorC,          rightMotor,    tmotorEV3_Large, openLoop, driveRight, encoder)
#pragma config(Motor,  motorD,           ,             tmotorEV3_Large, openLoop, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
void forward(int a);
void right_turn(int b);
void left_turn(int b);
void leave_package();

task main()
{
forward(35);
sleep(500);
right_turn(90);
sleep(500);
forward(250);


//Leave package and reverse function
leave_package();


right_turn(90);
sleep(500);
right_turn(90);
sleep(500);
forward(250);
sleep(500);
left_turn(90);
sleep(500);
forward(35);
sleep(500);

}

void forward(int a)
{
	float target_dist = (a / (3*PI)) * 360;
		resetMotorEncoder(leftMotor);
	resetMotorEncoder(rightMotor);

	setMotorSyncEncoder(motorB, motorC, 0, target_dist, 50);

	waitUntilMotorStop(motorB);
	waitUntilMotorStop(motorC);
}

void right_turn(int b)
{
	float circ_Axel = 11.7;
	float circ_Wheel = 3.0;
	float v = b;
	float target_deg = (circ_Axel/circ_Wheel) * v;

	resetMotorEncoder(leftMotor);
	resetMotorEncoder(rightMotor);
	sleep(1000);
	setMotorSyncEncoder(motorB, motorC, 100, target_deg, 30);

	waitUntilMotorStop(motorB);
	waitUntilMotorStop(motorC);
}

void left_turn(int b)
{
	float circ_Axel = 11.7;
	float circ_Wheel = 3.0;
	float v = b;

	float target_deg = (circ_Axel/circ_Wheel) * v;

	resetMotorEncoder(leftMotor);
	resetMotorEncoder(rightMotor);
	sleep(1000);
	setMotorSyncEncoder(motorB, motorC, -100, target_deg, 30);

	waitUntilMotorStop(motorB);
	waitUntilMotorStop(motorC);
}

void leave_package()
{
		resetMotorEncoder(armMotor);
	do {
		setMotorTarget(armMotor, 1440, 50);
	}
	while (getMotorEncoder(armMotor) < getMotorTarget(armMotor));

	setMotorSync(leftMotor,rightMotor,0, -10);
	sleep(2000);
	setMotorSpeed(leftMotor, 0);
	setMotorSpeed(rightMotor, 0);
	sleep(1500);
}