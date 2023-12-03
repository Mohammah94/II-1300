#pragma config(StandardModel, "EV3_REMBOT")
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	int distance[180];
	int n = 0;
	resetGyro(S2);
	do
	{
		setMotorSpeed(motorB,10);
		setMotorSpeed(motorC,-10);
		distance[n] = getUSDistance(S4);
		n = getGyroDegrees(S2)/2;
	}
	while (getGyroDegrees(S2) < 360);
	setMotorSpeed(motorB,0);
	setMotorSpeed(motorC,0);
	datalogDataGroupStart();
	datalogAddValue(1, distance[0]);
	datalogAddValue(2, distance[1]);
	datalogAddValue(3, distance[2]);
	datalogAddValue(4, distance[3]);
	datalogDataGroupEnd();
}
