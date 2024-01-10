// RegistryManager.h

#pragma once

#include <string>
#include <vector>

class RegistryManager {
public:
    static bool addToPath(const std::wstring& directoryToAdd);
    static bool removeFromPath(const std::wstring& directoryToRemove);
    static std::vector<std::wstring> listPHPVersions(const std::wstring& folderPath);
};
