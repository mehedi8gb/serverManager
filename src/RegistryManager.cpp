// RegistryManager.cpp

#include "RegistryManager.h"
#include <iostream>
#include <windows.h>
#include <filesystem>

namespace fs = std::filesystem;

bool RegistryManager::addToPath(const std::wstring& directoryToAdd) {
    // Implementation to add directory to the PATH in the Windows Registry
    // Refer to the previous C++ code example
    // ...

    return true;  // Return true if the operation was successful, otherwise false
}

bool RegistryManager::removeFromPath(const std::wstring& directoryToRemove) {
    // Implementation to remove directory from the PATH in the Windows Registry
    // Refer to the previous C++ code example
    // ...

    return true;  // Return true if the operation was successful, otherwise false
}

std::vector<std::wstring> RegistryManager::listPHPVersions(const std::wstring& folderPath) {
    std::vector<std::wstring> phpVersions;

    for (const auto& entry : fs::directory_iterator(folderPath)) {
        if (entry.is_directory()) {
            std::wstring directoryName = entry.path().filename();
            if (directoryName.find(L"php") == 0) {
                phpVersions.push_back(directoryName);
            }
        }
    }

    return phpVersions;
}
