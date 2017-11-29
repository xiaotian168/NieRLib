
#pragma once

#include "../NieRLib.h"
#include <list>
#include <string>

class IArchiver;

NIER_API bool UnpackAllArchiverItemW(IArchiver * pArchiver, std::list<std::wstring> & ItemPathList);
