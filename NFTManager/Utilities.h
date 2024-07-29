#ifndef UTILITIES_H
#define UTILITIES_H

#include <QObject>
#include <string>

class Utilities
{
public:
    Utilities();

    static void resetNFTablesConfigFileToDefault();

    static void addLineToFile(const std::string& filePath, const std::string& lineToAdd);

    static void removeLineContainingFromFile(const std::string& filePath, const std::string& lineToRemove);
    static void removeContentFromFile(const std::string& filePath, const std::string& contentToRemove);

};

#endif // UTILITIES_H
