
#pragma once

#include "../NieRLibConfig.h"

class IFileSystem;

NIER_CAPI IFileSystem * MakeWin32FileSystem(void);
NIER_CAPI IFileSystem * MakeFileSystemByOSPlatform(void);
