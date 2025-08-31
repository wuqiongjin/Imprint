#include "common.h"
#include <cstdlib>

namespace Imprint {
    fs::path Common::GetAppDir() {
        static fs::path appDir{};
        if (!appDir.empty()) {
            return appDir;
        }
#ifdef _WIN32
        // 优先用环境变量，比 SHGetKnownFolderPath 简单
        const char* p = std::getenv("LOCALAPPDATA");
        if (p) {
            appDir = fs::path(p) / APP_NAME;
        }

        // 保险方案：回退到 home / AppData/Local
        p = std::getenv("USERPROFILE");
        if (!p) {
            p = std::getenv("HOME");
        }
        return p ? std::filesystem::path(p) / "AppData" / "Local" / APP_NAME
                 : std::filesystem::path();   // 空路径表示失败
#else
        const char* home = std::getenv("HOME");
        if (!home) home = std::getenv("HOME");   // 再次确认
#   ifdef __APPLE__
        return home ? std::filesystem::path(home) / "Library" / "Caches" / APP_NAME
                    : std::filesystem::path();
#   else
        // Linux / BSD / etc.
        const char* xdg = std::getenv("XDG_DATA_HOME");
        if (xdg && *xdg) return xdg;
        return home ? std::filesystem::path(home) / ".local" / "share" / APP_NAME
                    : std::filesystem::path();
#   endif
#endif
    }
    
} // namespace Imprint