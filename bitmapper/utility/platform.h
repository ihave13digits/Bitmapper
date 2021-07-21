//
// Handle Platform Functions
//

#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif

namespace os
{
    std::string GetCWD()
        {
            char buff[FILENAME_MAX];
            GetCurrentDir(buff, FILENAME_MAX);
            std::string _dir(buff);
            return _dir;
        }

    void MakeDirectory(std::string path_data)
    {
        std::string _dir = os::GetCWD() + path_data;
        std::string _cmd = "mkdir " + _dir;
        const char* mkdir_cmd = _cmd.c_str();
        system(mkdir_cmd);
    }
}
