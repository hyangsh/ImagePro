
// ImagePro_HwangSeungHyeokDoc.h: CImageProHwangSeungHyeokDoc 클래스의 인터페이스
//


#pragma once
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
using namespace cv;
using namespace std;


class CImageProHwangSeungHyeokDoc : public CDocument
{
protected: // serialization에서만 만들어집니다.
	CImageProHwangSeungHyeokDoc() noexcept;
	DECLARE_DYNCREATE(CImageProHwangSeungHyeokDoc)

// 특성입니다.
public:
	Mat inputImg;  
	Mat inputImg2;// 입력 영상을 위한 공간
	Mat resultImg;   // 영상 처리 결과 저장을 위한 공간
// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 구현입니다.
public:
	virtual ~CImageProHwangSeungHyeokDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 검색 처리기에 대한 검색 콘텐츠를 설정하는 도우미 함수
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	void PixelAdd();
	void PixelSub();
	void PixelMUL();
	void PixelDiv();
	int PixelHistoEq();
	void PixelContrastStretching();
	void drawHist();
	void PixelBinarization();
	int PixelBinarizationAutoTresh();
	void PixelBinarizationAdaptiveThresh();
	void PixelBinarizationAutoThresh();
	void PixelBinarizationHRange();
	void PixelInvert();
	void PixelQuantization();
	void PixelRangeHighligthing();
	void PixelGammaCorrection();
	void PixelTwoImagesAdd();
	void LoadTwoImages();
	void PixelTwoImagesAddLogo();
	void MorphologyErosion();
	void MorphologyDilation();
	void MorphologyOpening();
	void MorphologyClosing();
	void MorphologyGradient();
	void MorphologyTopHat();
	void MorphologyBlackHat();
	void MorphologyHitOrMiss();
	void MorphologyLineDetection();
	void MorphologyCountCell();
	void RegionBlurring();
	void RegionSharpening();
	void RegionSobel();
	void RegionCanny();
	void RegionEmbossing();
	void RegionWaterColor();
	void GaussianBlurring();
	void MedianBlurring();
	void BilateralBlurring();
	void RegionPrewitt();
	void RegionBoberts();
	void RegionLaprasian();
	void PixelTwoImagesSub();
	void PixelTwoImagesAnd();
	void PixelTwoImagesOR();
	void PixelTwoImagesXOR();
};
