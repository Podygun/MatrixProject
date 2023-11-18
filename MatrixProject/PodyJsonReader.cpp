#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "PodyJsonReader.h"
#include "nlohmann/json.hpp"

ConfigData PodyJsonReader::readData(const std::string path)
{
    std::string serializedString = ReadFileString(path);
    ConfigData data{};
    nlohmann::json jsonObj = nlohmann::json::parse(serializedString);
    MapFields(data, jsonObj);
    return data;
}

std::string PodyJsonReader::ReadFileString(const std::string path) {

    std::ifstream file(path);

    if (!file.is_open()) {
        std::cerr << "Не удалось открыть файл!" << std::endl;
        return "";
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string fileContents = buffer.str();

    file.close();

    return fileContents;
}

void PodyJsonReader::MapFields(ConfigData &object, nlohmann::json jsonObject) {
    object.columns_amount = jsonObject["columns_amount"];
    object.rows_amount = jsonObject["rows_amount"];
    object.is_random_fill = jsonObject["is_random_fill"];
    object.version = jsonObject["version"];
}


