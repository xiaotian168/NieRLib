
#pragma once

#include "../NieRLib.h"

class NR_IArchiver;

NIER_API bool NR_UnpackAllArchiverItemW(NR_IArchiver * pArchiver, std::list<std::wstring> & ItemPathList);
