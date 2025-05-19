	#include "pch.h"
	#include "CppUnitTest.h"
	#include "weather.h"
	#include <fstream>
	#include <CppUnitTest.h>
	using namespace Microsoft::VisualStudio::CppUnitTestFramework;

	namespace WeatherAppTest
	{
		TEST_CLASS(WeatherAppTest)
		{
		public:
		
			TEST_METHOD(TestGetData)
			{
				std::ofstream inputFile("weather.data");
				inputFile << "Temp:70,Rain:1,40,Thunder:1,Hail:0,Windy:1,20";
				inputFile.close();

				weatherStation t;
				Assert::IsTrue(t.getData(), L"Error gathering data.");
				Assert::IsTrue(t.storeData(), L"Error storing data.");

				std::ifstream iFile("save.data");
				Assert::IsTrue(iFile.is_open(), L"Error opening file.");

				std::string l;
				std::getline(iFile, l);
				iFile.close();

				Assert::AreEqual(std::string("Temp:60,Rain:1,40,Thunder:1,Hail:0,Windy:1,20"), l, L"Data does not match.");
			}
		};	
	}
