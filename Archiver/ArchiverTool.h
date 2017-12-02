
#pragma once

#include "../NieRLib.h"

class IArchiver;

NIER_API bool UnpackAllArchiverItemW(IArchiver * pArchiver, std::list<std::wstring> & ItemPathList);
