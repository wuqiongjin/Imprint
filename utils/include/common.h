#pragma once
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

namespace Imprint {

    constexpr const char* APP_NAME = "Imprint";

    class Common {
    public:
        static fs::path GetAppDir();
    };
} // namespace Imprint