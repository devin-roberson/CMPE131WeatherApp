#ifndef WEATHER_H_
#define WEATHER_H_

class weatherStation {
private:
	int temp, rain, wind;
	bool rainChance, thunderChance, windChance, hailChance, gatheredData;
public:
	weatherStation();
	bool getData();
	bool storeData();
	bool transmitData();
	bool analyzeData();
	void UI();
};


#endif