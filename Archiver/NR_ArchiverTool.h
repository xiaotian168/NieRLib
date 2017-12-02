
#pragma once

#include "../NieRLib.h"

class NR_IArchiver;

NR_API bool NR_UnpackAllArchiverItemW(NR_IArchiver * pArchiver, std::list<std::wstring> & ItemPathList);
