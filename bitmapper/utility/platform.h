//
// Handle Platform Functions
//

#ifdef _WIN32
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
        std::string _dir = GetCWD() + path_data;
        _gfs::create_directory(_dir);
    }
}
