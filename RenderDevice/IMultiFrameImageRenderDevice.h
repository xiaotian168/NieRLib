
#include "../Base/IRefCount.h"

class IMultiFrameImage2D;

/**
** @brief ֧����Ⱦ��֡ͼ�����Ⱦ�豸�ӿ�
*/
class IMultiFrameImageRenderDevice : public IRefCount
{
public:

	/**
	** @brief ���ļ�������֡ͼ��
	*/
	virtual IMultiFrameImage2D * CreateMultiFrameImageFromFileW(const wchar_t * pszFile) = 0;

	/**
	** @brief ���ڴ洴����֡ͼ��
	*/
	virtual IMultiFrameImage2D * CreateMultiFrameImageFromMemory(const void * pBuffer, const unsigned uSize) = 0;

	/**
	** @brief ���ƶ�֡ͼ��
	*/
	virtual bool RenderMultiFrameImage(IMultiFrameImage2D * pImage, const unsigned int uFrameIndex, const int nPosX, const int nPosY) = 0;
};
