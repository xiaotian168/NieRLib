
#include "../Base/NR_IRefCount.h"

class NR_IMultiFrameImage2D;

/**
** @brief 支持渲染多帧图像的渲染设备接口
*/
class NR_IMultiFrameImageRenderDevice : public NR_IRefCount
{
public:

	/**
	** @brief 从文件创建多帧图像
	*/
	virtual NR_IMultiFrameImage2D * CreateMultiFrameImageFromFileW(const wchar_t * pszFile) = 0;

	/**
	** @brief 从内存创建多帧图像
	*/
	virtual NR_IMultiFrameImage2D * CreateMultiFrameImageFromMemory(const void * pBuffer, const unsigned uSize) = 0;

	/**
	** @brief 绘制多帧图像
	*/
	virtual bool RenderMultiFrameImage(NR_IMultiFrameImage2D * pImage, const unsigned int uFrameIndex, const int nPosX, const int nPosY) = 0;
};
