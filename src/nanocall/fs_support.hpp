#ifndef __FS_SUPPORT_HPP
#define __FS_SUPPORT_HPP

#include <string>
#include <vector>

#include <sys/types.h>

#ifdef WIN32
#include "dirent.h"
#else
#include <dirent.h>
#endif // WIN32

// This should work in windows.
// Ref:
// http://stackoverflow.com/a/612176/717706

bool is_directory(const std::string& file_name)
{
    auto dir = opendir(file_name.c_str());
    if (not dir) return false;
    closedir(dir);
    return true;
}

std::vector< std::string > list_directory(const std::string& file_name)
{
    std::vector< std::string > res;
    DIR* dir;
    struct dirent *ent;

    dir = opendir(file_name.c_str());
    if (not dir) return res;
    while ((ent = readdir(dir)) != nullptr)
    {
        res.push_back(ent->d_name);
    }
    closedir(dir);
    return res;
}

#endif
