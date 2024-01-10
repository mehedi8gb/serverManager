// main.cpp

#include <iostream>
#include "RegistryManager.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: ServerManager <action> <directory> [value]" << std::endl;
        return 1;
    }

    std::string action = argv[1];
    std::wstring directory = L"";

    // Convert command-line arguments to wide strings
    directory.assign(argv[2], argv[2] + strlen(argv[2]));

    if (action == "list") {
        // List available PHP versions in the specified directory
        std::vector<std::wstring> phpVersions = RegistryManager::listPHPVersions(directory);
        std::cout << "Available PHP versions:" << std::endl;
        for (const auto& version : phpVersions) {
            std::wcout << version << std::endl;
        }
    } else if (action == "add") {
        if (argc != 4) {
            std::cerr << "Usage: ServerManager add <directory> <version>" << std::endl;
            return 1;
        }

        std::wstring versionToAdd = L"";
        versionToAdd.assign(argv[3], argv[3] + strlen(argv[3]));

        // Check if the specified version exists in the directory
        std::vector<std::wstring> phpVersions = RegistryManager::listPHPVersions(directory);
        auto found = std::find(phpVersions.begin(), phpVersions.end(), versionToAdd);

        if (found != phpVersions.end()) {
            std::wcout << L"Adding PHP version " << versionToAdd << L" to PATH..." << std::endl;

            // Construct the full path to the PHP version directory
            std::wstring fullVersionPath = directory + L"\\" + versionToAdd;

            // Call function to add directory to PATH
            if (RegistryManager::addToPath(fullVersionPath)) {
                std::wcout << L"PHP version " << versionToAdd << L" added to PATH successfully." << std::endl;
            } else {
                std::cerr << "Failed to add PHP version to PATH." << std::endl;
                return 1;
            }
        } else {
            std::cerr << "Specified PHP version not found in the directory." << std::endl;
            return 1;
        }
    } else if (action == "remove") {
        // Implementation for removing PHP version from PATH
        // ...
    } else {
        std::cerr << "Invalid action. Use 'list', 'add', or 'remove'." << std::endl;
        return 1;
    }

    return 0;
}
