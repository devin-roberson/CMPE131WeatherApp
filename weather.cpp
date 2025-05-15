#include "weather.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
weatherStation::weatherStation() {

	temp = 0;
	rain = 0;
	wind = 0;
	rainChance = false;
	thunderChance = false;
	windChance = false;
	hailChance = false;
	gatheredData = false;
}

void weatherStation::getData() {
	std::string l, fodder, tempV;
	std::ifstream iFile("weather.data");
	if (iFile.is_open()) {
		while (getline(iFile, l)) {
			std::stringstream l2(l);
			std::getline(l2, fodder, ':');
			std::getline(l2, tempV, ',');
			temp = std::stoi(tempV);
			std::getline(l2, fodder, ':');
			std::getline(l2, tempV, ',');
			rainChance = std::stoi(tempV);
			std::getline(l2, tempV, ',');
			rain = std::stoi(tempV);
			std::getline(l2, fodder, ':');
			std::getline(l2, tempV, ',');
			thunderChance = std::stoi(tempV);
			std::getline(l2, fodder, ':');
			std::getline(l2, tempV, ',');
			hailChance = std::stoi(tempV);
			std::getline(l2, fodder, ':');
			std::getline(l2, tempV, ',');
			windChance = std::stoi(tempV);
			std::getline(l2, tempV);
			wind = std::stoi(tempV);
			iFile.close();
			std::cout << "Data gathered." << std::endl;
		}
	}
	else
		std::cout << "Data failed to gather." << std::endl;
	gatheredData = true;
}

void weatherStation::storeData() {
	if (gatheredData) {
		std::ofstream oFile("save.data");
		if (oFile.is_open()) {
			oFile << "Temp:" << temp << ",";
			oFile << "Rain:" << rainChance << "," << rain << ",";
			oFile << "Thunder:" << thunderChance << ",";
			oFile << "Hail:" << hailChance << ",";
			oFile << "Windy:" << windChance << "," << wind;
			oFile.close();
			std::cout << "Data saved." << std::endl;
		}
		else
			std::cout << "ERROR" << std::endl;
	}
	else
		std::cout << "No data to save!" << std::endl;
}

void weatherStation::transmitData() {
	std::cout << "not implemented" << std::endl;
}

void weatherStation::analyzeData() {
	if (gatheredData) {
		std::cout << "The current temperature is " << temp << " degress fahrenheit." << std::endl;
		if (rainChance) {
			std::cout << "There will be rain with precipitation of " << rain << "%." << std::endl;
		}
		else
			std::cout << "It will not rain." << std::endl;
		if (windChance) {
			std::cout << "There will be wind with speeds of: " << wind << "mph." << std::endl;
		}
		if (thunderChance) {
			std::cout << "There will be thunder." << std::endl;
		}
		if (hailChance) {
			std::cout << "There will be hail." << std::endl;
		}
	}
	else
		std::cout << "No data to analyze!" << std::endl;
}