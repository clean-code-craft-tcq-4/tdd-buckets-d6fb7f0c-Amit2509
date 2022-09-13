#define ERROR_INVALID_VALUE -99
#define ERROR_INVALID_SENSOR -100
#define NUM_OF_SENSORS_AVAILABLE 2

int ConvertD2A_1(int digital);
int ConvertD2A_2(int digital);
int ReadCurrentSensor(int* Digital, int numOfDigitalValues, int* Analog, int sensorID);
