// properties.h
#ifndef PROPERTIES_H
#define PROPERTIES_H

#include <string>
#include <map>

class PropertiesController {
public:
    PropertiesController(const std::string& filename);
    ~PropertiesController();

    void setProperty(const std::string& key, const std::string& value);
    std::string getProperty(const std::string& key);

private:
    std::string filename;
    std::map<std::string, std::string> properties;

    void readProperties();
    void writeProperties();
};

#endif // PROPERTIES_H
