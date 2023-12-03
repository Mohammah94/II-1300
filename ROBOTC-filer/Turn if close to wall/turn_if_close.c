
task main()
{
int driving = 1;
while(driving == 1)
{
	do
	{
		setMotorSpeed(motorB, 50);
		setMotorSpeed(motorC, 50);
	}
	while(getUSDistance(S4) > 30);
	do
	{
		setMotorSpeed(motorB, 50);
		setMotorSpeed(motorC, -50);
	}
	while(getUSDistance(S4) < 30);
}
waitUntilMotorStop(motorB);
waitUntilMotorStop(motorC);
}
