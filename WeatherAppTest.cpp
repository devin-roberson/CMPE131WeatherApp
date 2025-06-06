#include "pch.h"
#include "CppUnitTest.h"
#include "weather.h"
#include <fstream>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace WeatherAppTest
{
	TEST_CLASS(WeatherAppTest)
	{
	public:
		
		TEST_METHOD(TestGetData)
		{
			weatherStation test;
			test.getData();
			test.storeData();

			std::ifstream iFile("save.data");
			Assert::IsTrue(iFile.is_open(), L"Error opening file.");

			std::string l;
			std::getline(iFile, l);
			iFile.close();

			Assert::AreEqual(std::string("Temp:70,Rain:1,40,Thunder:1,Hail:0,Windy:1,20"), l, L"Data does not match.");
		}
	};
}
