#ifndef WEATHER_H_
#define WEATHER_H_

class weatherStation {
private:
	int temp, rain, wind;
	bool rainChance, thunderChance, windChance, hailChance, gatheredData;
public:
	weatherStation();
	void getData();
	void storeData();
	void transmitData();
	void analyzeData();
};


#endif