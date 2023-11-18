#pragma once
#include "nlohmann/json.hpp"
#include "ConfigData.h"
#include <iostream>
#include <string>



class PodyJsonReader {
public:
	static ConfigData readData(const std::string path);

	static std::string ReadFileString(const std::string path);

	static void MapFields(ConfigData& object, nlohmann::json jsonObject);
};