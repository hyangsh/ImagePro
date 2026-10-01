
// ImagePro_HwangSeungHyeokView.h: CImageProHwangSeungHyeokView 클래스의 인터페이스
//

#pragma once


class CImageProHwangSeungHyeokView : public CScrollView
{
protected: // serialization에서만 만들어집니다.
	CImageProHwangSeungHyeokView() noexcept;
	DECLARE_DYNCREATE(CImageProHwangSeungHyeokView)

// 특성입니다.
public:
	CImageProHwangSeungHyeokDoc* GetDocument() const;
	int drawHist = false;
	int viewMode;
// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // 생성 후 처음 호출되었습니다.
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CImageProHwangSeungHyeokView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPixelAdd();
	void drawImage(CDC* pDC, Mat img, int offset_x, int offset_y);
	afx_msg void OnPixelSub();
	afx_msg void OnPixelMul();
	afx_msg void OnPixelDiv();
	afx_msg void OnPixelHistoEq();
	afx_msg void OnPixelContrastStretching();
	afx_msg void OnDrawHistogramOnoff();
	afx_msg void OnPixelBinarization();
	afx_msg void OnPixelBinarizationAutoThresh();
	afx_msg void OnPixelBinarizationAdaptiveThresh();
	afx_msg void OnPixelBinarizationHRange();
	afx_msg void OnPixelInvert();
	afx_msg void OnPixelQuantization();
	afx_msg void OnPixelRangeHighlighting();
	afx_msg void OnPixelGammaCorrection();
	afx_msg void OnPixelTwoImagesAdd();
	afx_msg void OnPixelTwoImagesAddLogo();
	afx_msg void OnMorphologyErosion();
	afx_msg void OnMorphologyDilation();
	afx_msg void OnMorphologyOpening();
	afx_msg void OnMorphologyClosing();
	afx_msg void OnMorphologyGradient();
	afx_msg void OnMorphologyTopHat();
	afx_msg void OnMorphologyBlackHat();
	afx_msg void OnMorphologyHitOrMiss();
	afx_msg void OnMorphologyLineDetection();
	afx_msg void OnMorphologyCountCell();
	afx_msg void OnRegionBlurring();
	afx_msg void OnRegionSharpening();
	afx_msg void OnRegionSobel();
	afx_msg void OnRegionCanny();
	afx_msg void OnRegionEmbossing();
	afx_msg void OnRegionWaterColor();
};

#ifndef _DEBUG  // ImagePro_HwangSeungHyeokView.cpp의 디버그 버전
inline CImageProHwangSeungHyeokDoc* CImageProHwangSeungHyeokView::GetDocument() const
   { return reinterpret_cast<CImageProHwangSeungHyeokDoc*>(m_pDocument); }
#endif

