#include "Utilities.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include "NFTables.h"

Utilities::Utilities() {}

void Utilities::resetNFTablesConfigFileToDefault()
{
    std::ofstream outputFile(NFTables::NFTConfigPath, std::ios::trunc);
    if (!outputFile.is_open())
    {
        std::cerr << "Failed to reset default NFTables config file (/etc/nftables.conf)!\n";
    }
    std::string defaultConfig =
        "#!/usr/sbin/nft -f\n\n"
        "flush ruleset\n\n"
        "table inet filter {\n"
        "   chain input {\n"
        "       type filter hook input priority 0;\n"
        "   }\n"
        "   chain forward {\n"
        "       type filter hook forward priority 0;\n"
        "   }\n"
        "   chain output {\n"
        "       type filter hook output priority 0;\n"
        "   }\n"
        "}\n";
    outputFile << defaultConfig;
    outputFile.close();
    NFTables::reloadNFT();
}

void Utilities::addLineToFile(const std::string &filePath, const std::string &lineToAdd)
{
    std::ofstream outputFile(filePath, std::ios::app);
    if (!outputFile.is_open())
    {
        std::cerr << "Failed to open the file: " << filePath << "\n";
        return;
    }
    outputFile << lineToAdd << "\n";
    outputFile.close();
}

void Utilities::removeLineContainingFromFile(const std::string &filePath, const std::string &lineToRemove)
{
    std::ifstream inputFile(filePath);
    if (!inputFile.is_open())
    {
        std::cerr << "Failed to open the file: " << filePath << "\n";
        return;
    }

    std::string fileContent;
    std::string line;
    while (getline(inputFile, line))
    {
        if (line.find(lineToRemove) == std::string::npos)
        {
            fileContent += line + "\n";
        }
    }
    inputFile.close();

    std::ofstream outputFile(filePath, std::ios::trunc);
    if (!outputFile.is_open())
    {
        std::cerr << "Failed to open the file for writing: " << filePath << "\n";
        return;
    }

    outputFile << fileContent;
    outputFile.close();
}

void Utilities::removeContentFromFile(const std::string &filePath, const std::string &contentToRemove)
{
    std::ifstream inputFile(filePath);
    if (!inputFile.is_open())
    {
        std::cerr << "Failed to open the file: " << filePath << "\n";
        return;
    }

    std::stringstream buffer;
    buffer << inputFile.rdbuf();
    std::string fileContent = buffer.str();
    inputFile.close();

    size_t pos;
    while ((pos = fileContent.find(contentToRemove)) != std::string::npos)
    {
        fileContent.erase(pos, contentToRemove.length());
    }

    std::ofstream outputFile(filePath, std::ios::trunc);
    if (!outputFile.is_open())
    {
        std::cerr << "Failed to open the file for writting: " << filePath << "\n";
        return;
    }

    outputFile << fileContent;
    outputFile.close();
}
