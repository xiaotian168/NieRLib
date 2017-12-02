
#include "../Base/NR_IRefCount.h"

class NR_IMultiFrameImage2D;

/**
** @brief ֧����Ⱦ��֡ͼ�����Ⱦ�豸�ӿ�
*/
class NR_IMultiFrameImageRenderDevice : public NR_IRefCount
{
public:

	/**
	** @brief ���ļ�������֡ͼ��
	*/
	virtual NR_IMultiFrameImage2D * CreateMultiFrameImageFromFileW(const wchar_t * pszFile) = 0;

	/**
	** @brief ���ڴ洴����֡ͼ��
	*/
	virtual NR_IMultiFrameImage2D * CreateMultiFrameImageFromMemory(const void * pBuffer, const unsigned uSize) = 0;

	/**
	** @brief ���ƶ�֡ͼ��
	*/
	virtual bool RenderMultiFrameImage(NR_IMultiFrameImage2D * pImage, const unsigned int uFrameIndex, const int nPosX, const int nPosY) = 0;
};
