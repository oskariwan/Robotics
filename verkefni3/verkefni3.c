#pragma config(Sensor, in1,    leftLineFollower, sensorLineFollower)
#pragma config(Sensor, in2,    centerLineFollower, sensorLineFollower)
#pragma config(Sensor, in3,    rightLineFollower, sensorLineFollower)
#pragma config(Sensor, dgtl8,  rightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl6,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, in8,    lightSensor,         sensorReflection)
#pragma config(Sensor, dgtl8,  sonarSensor,         sensorSONAR_cm)
#pragma config(Motor,  port1,           rightMotor,    tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port10,          leftMotor,     tmotorServoContinuousRotation, openLoop)

const int TURNDIST = 200;

void turn(int dist){
	while(abs(SensorValue[rightEncoder]) < dist){
		motor[rightMotor] = 45;
		motor[leftMotor]  = -45;
	}
}
task main()
{
	wait1Msec(2000);//bida 2 sek og ta byrja kodi
	while(SensorValue(lightSensor) > 200)//bida eftir ljosskynnjari fer yfir 200
	{
		if(SensorValue(sonarSensor) > 20  || SensorValue(sonarSensor) == -1)//ef lengd milli sensor og vegg er meira en 20 keyra afram(-1 tydir ad sensor fynnur ekkert)
		{
			motor[rightMotor] = 63;			          // Motor on port2 is run at half (63) power forward
			motor[leftMotor]  = 63;			          // Motor on port3 is run at half (63) power forward
		}
		else(//ef sensor er undir 20 ta beygja
			turn(TURNDIST);
	}


}
