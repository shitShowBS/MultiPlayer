// properties.cpp
#include "propertiescontroller.h"
#include <fstream>

PropertiesController::PropertiesController(const std::string& filename) : filename(filename) {
    // Lese die Properties-Datei beim Erstellen des Objekts
    readProperties();
}

PropertiesController::~PropertiesController() {
    // Speichere die Properties-Datei beim Zerstören des Objekts
    writeProperties();
}

void PropertiesController::setProperty(const std::string& key, const std::string& value) {
    properties[key] = value;
}

std::string PropertiesController::getProperty(const std::string& key) {
    auto it = properties.find(key);
    return (it != properties.end()) ? it->second : "";
}

void PropertiesController::readProperties() {
    std::ifstream file(filename);

    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            size_t delimiterPos = line.find('=');
            if (delimiterPos != std::string::npos) {
                std::string key = line.substr(0, delimiterPos);
                std::string value = line.substr(delimiterPos + 1);
                properties[key] = value;
            }
        }

        file.close();
    }
}

void PropertiesController::writeProperties() {
    std::ofstream file(filename);

    if (file.is_open()) {
        for (const auto& entry : properties) {
            file << entry.first << "=" << entry.second << "\n";
        }

        file.close();
    }
}
