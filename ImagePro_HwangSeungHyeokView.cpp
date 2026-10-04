
// ImagePro_HwangSeungHyeokView.cpp: CImageProHwangSeungHyeokView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "ImagePro_HwangSeungHyeok.h"
#endif
#define TWO_IMAGES      1 
#define THREE_IMAGES    2 

#include "ImagePro_HwangSeungHyeokDoc.h"
#include "ImagePro_HwangSeungHyeokView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CImageProHwangSeungHyeokView

IMPLEMENT_DYNCREATE(CImageProHwangSeungHyeokView, CScrollView)

BEGIN_MESSAGE_MAP(CImageProHwangSeungHyeokView, CScrollView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CImageProHwangSeungHyeokView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_PIXEL_ADD, &CImageProHwangSeungHyeokView::OnPixelAdd)
	ON_COMMAND(ID_PIXEL_SUB, &CImageProHwangSeungHyeokView::OnPixelSub)
	ON_COMMAND(ID_PIXEL_MUL, &CImageProHwangSeungHyeokView::OnPixelMul)
	ON_COMMAND(ID_PIXEL_DIV, &CImageProHwangSeungHyeokView::OnPixelDiv)
	ON_COMMAND(ID_PIXEL_HISTO_EQ, &CImageProHwangSeungHyeokView::OnPixelHistoEq)
	ON_COMMAND(ID_PIXEL_CONTRAST_STRETCHING, &CImageProHwangSeungHyeokView::OnPixelContrastStretching)
	ON_COMMAND(ID_DRAW_HISTOGRAM_ONOFF, &CImageProHwangSeungHyeokView::OnDrawHistogramOnoff)
	ON_COMMAND(ID_PIXEL_BINARIZATION, &CImageProHwangSeungHyeokView::OnPixelBinarization)
	ON_COMMAND(ID_PIXEL_BINARIZATION_AUTO_THRESH, &CImageProHwangSeungHyeokView::OnPixelBinarizationAutoThresh)
	ON_COMMAND(ID_PIXEL_BINARIZATION_ADAPTIVE_THRESH, &CImageProHwangSeungHyeokView::OnPixelBinarizationAdaptiveThresh)
	ON_COMMAND(ID_PIXEL_BINARIZATION_H_RANGE, &CImageProHwangSeungHyeokView::OnPixelBinarizationHRange)
	ON_COMMAND(ID_PIXEL_INVERT, &CImageProHwangSeungHyeokView::OnPixelInvert)
	ON_COMMAND(ID_PIXEL_QUANTIZATION, &CImageProHwangSeungHyeokView::OnPixelQuantization)
	ON_COMMAND(ID_PIXEL_RANGE_HIGHLIGHTING, &CImageProHwangSeungHyeokView::OnPixelRangeHighlighting)
	ON_COMMAND(ID_PIXEL_GAMMA_CORRECTION, &CImageProHwangSeungHyeokView::OnPixelGammaCorrection)
	ON_COMMAND(ID_PIXEL_TWO_IMAGES_ADD, &CImageProHwangSeungHyeokView::OnPixelTwoImagesAdd)
	ON_COMMAND(ID_PIXEL_TWO_IMAGES_ADD_LOGO, &CImageProHwangSeungHyeokView::OnPixelTwoImagesAddLogo)
	ON_COMMAND(ID_MORPHOLOGY_EROSION, &CImageProHwangSeungHyeokView::OnMorphologyErosion)
	ON_COMMAND(ID_MORPHOLOGY_DILATION, &CImageProHwangSeungHyeokView::OnMorphologyDilation)
	ON_COMMAND(ID_MORPHOLOGY_OPENING, &CImageProHwangSeungHyeokView::OnMorphologyOpening)
	ON_COMMAND(ID_MORPHOLOGY_CLOSING, &CImageProHwangSeungHyeokView::OnMorphologyClosing)
	ON_COMMAND(ID_MORPHOLOGY_GRADIENT, &CImageProHwangSeungHyeokView::OnMorphologyGradient)
	ON_COMMAND(ID_MORPHOLOGY_TOP_HAT, &CImageProHwangSeungHyeokView::OnMorphologyTopHat)
	ON_COMMAND(ID_MORPHOLOGY_BLACK_HAT, &CImageProHwangSeungHyeokView::OnMorphologyBlackHat)
	ON_COMMAND(ID_MORPHOLOGY_HIT_OR_MISS, &CImageProHwangSeungHyeokView::OnMorphologyHitOrMiss)
	ON_COMMAND(ID_MORPHOLOGY_LINE_DETECTION, &CImageProHwangSeungHyeokView::OnMorphologyLineDetection)
	ON_COMMAND(ID_MORPHOLOGY_COUNT_CELL, &CImageProHwangSeungHyeokView::OnMorphologyCountCell)
	ON_COMMAND(ID_REGION_BLURRING, &CImageProHwangSeungHyeokView::OnRegionBlurring)
	ON_COMMAND(ID_REGION_SHARPENING, &CImageProHwangSeungHyeokView::OnRegionSharpening)
	ON_COMMAND(ID_REGION_SOBEL, &CImageProHwangSeungHyeokView::OnRegionSobel)
	ON_COMMAND(ID_REGION_CANNY, &CImageProHwangSeungHyeokView::OnRegionCanny)
	ON_COMMAND(ID_REGION_EMBOSSING, &CImageProHwangSeungHyeokView::OnRegionEmbossing)
	ON_COMMAND(ID_REGION_WATER_COLOR, &CImageProHwangSeungHyeokView::OnRegionWaterColor)
	ON_COMMAND(ID_GAUSSIAN_BLURRING, &CImageProHwangSeungHyeokView::OnGaussianBlurring)
	ON_COMMAND(ID_MEDIAN_BLURRING, &CImageProHwangSeungHyeokView::OnMedianBlurring)
	ON_COMMAND(ID_BILATERAL_BLURRING, &CImageProHwangSeungHyeokView::OnBilateralBlurring)
	ON_COMMAND(ID_REGION_PREWITT, &CImageProHwangSeungHyeokView::OnRegionPrewitt)
	ON_COMMAND(ID_REGION_ROBERTS, &CImageProHwangSeungHyeokView::OnRegionRoberts)
	ON_COMMAND(ID_REGION_LAPRASIAN, &CImageProHwangSeungHyeokView::OnRegionLaprasian)
	ON_COMMAND(ID_PIXEL_TWO_IMAGES_SUB, &CImageProHwangSeungHyeokView::OnPixelTwoImagesSub)
	ON_COMMAND(ID_PIXEL_TWO_IMAGES_AND, &CImageProHwangSeungHyeokView::OnPixelTwoImagesAnd)
	ON_COMMAND(ID_PIXEL_TWO_IMAGES_OR, &CImageProHwangSeungHyeokView::OnPixelTwoImagesOr)
	ON_COMMAND(ID_PIXEL_TWO_IMAGES_XOR, &CImageProHwangSeungHyeokView::OnPixelTwoImagesXor)
END_MESSAGE_MAP()

// CImageProHwangSeungHyeokView 생성/소멸

CImageProHwangSeungHyeokView::CImageProHwangSeungHyeokView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CImageProHwangSeungHyeokView::~CImageProHwangSeungHyeokView()
{
}

BOOL CImageProHwangSeungHyeokView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CScrollView::PreCreateWindow(cs);
}

// CImageProHwangSeungHyeokView 그리기

void CImageProHwangSeungHyeokView::OnDraw(CDC* pDC)
{
	CImageProHwangSeungHyeokDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	drawImage(pDC, pDoc->inputImg, 0, 0);
	if (viewMode == THREE_IMAGES) {
		drawImage(pDC, pDoc->inputImg2, pDoc->inputImg.cols + 30, 0);
		drawImage(pDC, pDoc->resultImg, pDoc->inputImg.cols + pDoc->inputImg2.cols + 60, 0);
	}
	else if (viewMode == TWO_IMAGES)
		drawImage(pDC, pDoc->resultImg, pDoc->inputImg.cols + 30, 0);


}

void CImageProHwangSeungHyeokView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: 이 뷰의 전체 크기를 계산합니다.
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}


// CImageProHwangSeungHyeokView 인쇄


void CImageProHwangSeungHyeokView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CImageProHwangSeungHyeokView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CImageProHwangSeungHyeokView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CImageProHwangSeungHyeokView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CImageProHwangSeungHyeokView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CImageProHwangSeungHyeokView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CImageProHwangSeungHyeokView 진단

#ifdef _DEBUG
void CImageProHwangSeungHyeokView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CImageProHwangSeungHyeokView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CImageProHwangSeungHyeokDoc* CImageProHwangSeungHyeokView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CImageProHwangSeungHyeokDoc)));
	return (CImageProHwangSeungHyeokDoc*)m_pDocument;
}
#endif //_DEBUG


// CImageProHwangSeungHyeokView 메시지 처리기

void CImageProHwangSeungHyeokView::OnPixelAdd()
{
	CImageProHwangSeungHyeokDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	if (pDoc->inputImg.empty()) return;
	pDoc->PixelAdd();
	viewMode = TWO_IMAGES;


	Invalidate(TRUE);

}

void CImageProHwangSeungHyeokView::drawImage(CDC* pDC, Mat img, int offset_x, int offset_y)
{
	if (img.empty()) return;
	for (int y = 0; y < img.rows; y++)
		for (int x = 0; x < img.cols; x++)
			if (img.channels() == 1)
				pDC->SetPixel(x + offset_x, y + offset_y,
					RGB(img.at<BYTE>(y, x), img.at<BYTE>(y, x),
						img.at<BYTE>(y, x)));
			else if (img.channels() == 3)
				pDC->SetPixel(x + offset_x, y + offset_y,
					RGB(img.at<Vec3b>(y, x)[2], img.at<Vec3b>(y, x)[1],
						img.at<Vec3b>(y, x)[0]));
	if (drawHist) {
		int hist[256];
		int pixel;

		for (int i = 0; i < 256; i++) hist[i] = 0;  // 히스토그램 초기화

		// 영상에서 0에서 255까지 각각의 값이 몇 번  나타나는지 카운트 
		for (int y = 0; y < img.rows; y++)
			for (int x = 0; x < img.cols; x++) {
				if (img.channels() == 1) pixel = img.at<BYTE>(y, x);
				else if (img.channels() == 3)
					pixel = (img.at<Vec3b>(y, x)[0] + img.at<Vec3b>(y, x)[1] +
						img.at<Vec3b>(y, x)[0]) / 3;
				hist[pixel]++;
			}
		float max = 0;
		for (int i = 0; i < 256; i++)
			if (hist[i] > max) max = hist[i];  // 제일 큰 빈도수를 찾음

		// 제일 큰 빈도수에 상대적인 크기를 구하여 세로선을 그림
		//        제일 큰 빈도수 = 1000인 경우
		//               제일 큰 빈도수를 갖는 명암 값에 대해 길이가 256인 세로선을 그림
		//               빈도수가 500인 명암 값에 대해 길이가 128인 세로선을 그림
		//               빈도수가 250인 명암 값에 대해 길이가 64인 세로선을 그림
		for (int x = 0; x < 256; x++)
			for (int y = 0; y < hist[x] / max * 256; y++)
				pDC->SetPixel(x + offset_x, 255 - y + img.rows + 30 + offset_y, RGB(0, 0, 0));
	}
}

void CImageProHwangSeungHyeokView::OnPixelSub()
{
	CImageProHwangSeungHyeokDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	if (pDoc->inputImg.empty()) return;
	pDoc->PixelSub();
	viewMode = TWO_IMAGES;

	Invalidate(TRUE);


}

void CImageProHwangSeungHyeokView::OnPixelMul()
{
	CImageProHwangSeungHyeokDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	if (pDoc->inputImg.empty()) return;
	pDoc->PixelMUL();
	viewMode = TWO_IMAGES;

	Invalidate(TRUE);
}

void CImageProHwangSeungHyeokView::OnPixelDiv()
{
	CImageProHwangSeungHyeokDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	if (pDoc->inputImg.empty()) return;
	pDoc->PixelDiv();
	viewMode = TWO_IMAGES;

	Invalidate(TRUE);
}

void CImageProHwangSeungHyeokView::OnPixelHistoEq()
{
	CImageProHwangSeungHyeokDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	viewMode = TWO_IMAGES;

	if (pDoc->inputImg.empty()) return;
	pDoc->PixelHistoEq();  // CImageProDoc 클래스의 PixelHistoEq() 호출 
	Invalidate(TRUE);
}

void CImageProHwangSeungHyeokView::OnPixelContrastStretching()
{
	CImageProHwangSeungHyeokDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	viewMode = TWO_IMAGES;

	if (pDoc->inputImg.empty()) return;
	pDoc->PixelContrastStretching();
	Invalidate(TRUE);      //화면 갱신.   

}

void CImageProHwangSeungHyeokView::OnDrawHistogramOnoff()
{
	if (drawHist == false) drawHist = true;
	else drawHist = false;
	viewMode = TWO_IMAGES;

	Invalidate(TRUE);

}

void CImageProHwangSeungHyeokView::OnPixelBinarization()
{
	CImageProHwangSeungHyeokDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (pDoc->inputImg.empty()) return;
	pDoc->PixelBinarization();
	viewMode = TWO_IMAGES;

	Invalidate(TRUE);
}

void CImageProHwangSeungHyeokView::OnPixelBinarizationAutoThresh()
{
	CImageProHwangSeungHyeokDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (pDoc->inputImg.empty()) return;
	pDoc->PixelBinarizationAutoThresh();
	viewMode = TWO_IMAGES;

	Invalidate(TRUE);
}

void CImageProHwangSeungHyeokView::OnPixelBinarizationAdaptiveThresh()
{
	CImageProHwangSeungHyeokDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (pDoc->inputImg.empty()) return;
	pDoc->PixelBinarizationAdaptiveThresh();
	viewMode = TWO_IMAGES;

	Invalidate(TRUE);      //화면 갱신.   

}

void CImageProHwangSeungHyeokView::OnPixelBinarizationHRange()
{
	CImageProHwangSeungHyeokDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (pDoc->inputImg.empty()) return;
	pDoc->PixelBinarizationHRange();
	viewMode = TWO_IMAGES;

	Invalidate(TRUE);
}

void CImageProHwangSeungHyeokView::OnPixelInvert()
{
	CImageProHwangSeungHyeokDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	viewMode = TWO_IMAGES;

	if (pDoc->inputImg.empty()) return;
	pDoc->PixelInvert();  // CImageProDoc 클래스의 PixelInvert() 호출 
	Invalidate(TRUE);      //화면 갱신.   

}

void CImageProHwangSeungHyeokView::OnPixelQuantization()
{
	CImageProHwangSeungHyeokDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	if (pDoc->inputImg.empty()) return;
	pDoc->PixelQuantization();
	viewMode = TWO_IMAGES;

	Invalidate(TRUE);      //화면 갱신.   

}

void CImageProHwangSeungHyeokView::OnPixelRangeHighlighting()
{
	CImageProHwangSeungHyeokDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	if (pDoc->inputImg.empty()) return;
	pDoc->PixelRangeHighligthing();
	viewMode = TWO_IMAGES;

	Invalidate(TRUE);      //화면 갱신.   

}

void CImageProHwangSeungHyeokView::OnPixelGammaCorrection()
{
	CImageProHwangSeungHyeokDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	if (pDoc->inputImg.empty()) return;
	pDoc->PixelGammaCorrection();
	viewMode = TWO_IMAGES;

	Invalidate(TRUE);      //화면 갱신.   

}

void CImageProHwangSeungHyeokView::OnPixelTwoImagesAdd()
{
	CImageProHwangSeungHyeokDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->PixelTwoImagesAdd();
	viewMode = THREE_IMAGES;

	Invalidate(TRUE);
	
}

void CImageProHwangSeungHyeokView::OnPixelTwoImagesAddLogo()
{
	CImageProHwangSeungHyeokDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->PixelTwoImagesAddLogo();
	viewMode = THREE_IMAGES;
	Invalidate(TRUE);

}

void CImageProHwangSeungHyeokView::OnMorphologyErosion()
{
	CImageProHwangSeungHyeokDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (pDoc->inputImg.empty()) return;
	pDoc->MorphologyErosion();
	viewMode = TWO_IMAGES;
	Invalidate(TRUE);
}

void CImageProHwangSeungHyeokView::OnMorphologyDilation()
{
	CImageProHwangSeungHyeokDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (pDoc->inputImg.empty()) return;
	pDoc->MorphologyDilation();
	viewMode = TWO_IMAGES;
	Invalidate(TRUE);
}

void CImageProHwangSeungHyeokView::OnMorphologyOpening()
{
	CImageProHwangSeungHyeokDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	if (pDoc->inputImg.empty()) return;
	pDoc->MorphologyOpening();
	viewMode = TWO_IMAGES;
	Invalidate(TRUE);
}

void CImageProHwangSeungHyeokView::OnMorphologyClosing()
{
	CImageProHwangSeungHyeokDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (pDoc->inputImg.empty()) return;
	pDoc->MorphologyClosing();
	viewMode = TWO_IMAGES;
	Invalidate(TRUE);

}

void CImageProHwangSeungHyeokView::OnMorphologyGradient()
{
	CImageProHwangSeungHyeokDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (pDoc->inputImg.empty()) return;
	pDoc->MorphologyGradient();
	viewMode = TWO_IMAGES;
	Invalidate(TRUE);

}

void CImageProHwangSeungHyeokView::OnMorphologyTopHat()
{
	CImageProHwangSeungHyeokDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (pDoc->inputImg.empty()) return;
	pDoc->MorphologyTopHat();
	viewMode = TWO_IMAGES;
	Invalidate(TRUE);
}

void CImageProHwangSeungHyeokView::OnMorphologyBlackHat()
{
	CImageProHwangSeungHyeokDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (pDoc->inputImg.empty()) return;
	pDoc->MorphologyBlackHat();
	viewMode = TWO_IMAGES;
	Invalidate(TRUE);

}

void CImageProHwangSeungHyeokView::OnMorphologyHitOrMiss()
{
	CImageProHwangSeungHyeokDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (pDoc->inputImg.empty()) return;
	pDoc->MorphologyHitOrMiss();
	viewMode = TWO_IMAGES;
	Invalidate(TRUE);

}

void CImageProHwangSeungHyeokView::OnMorphologyLineDetection()
{
	CImageProHwangSeungHyeokDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (pDoc->inputImg.empty()) return;
	pDoc->MorphologyLineDetection();
	viewMode = TWO_IMAGES;
	Invalidate(TRUE);

}

void CImageProHwangSeungHyeokView::OnMorphologyCountCell()
{
	CImageProHwangSeungHyeokDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (pDoc->inputImg.empty()) return;
	pDoc->MorphologyCountCell();
	viewMode = TWO_IMAGES;
	Invalidate(TRUE);
}

void CImageProHwangSeungHyeokView::OnRegionBlurring()
{
	CImageProHwangSeungHyeokDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	if (pDoc->inputImg.empty()) return;
	pDoc->RegionBlurring();
	viewMode = TWO_IMAGES;
	Invalidate(TRUE);

}

void CImageProHwangSeungHyeokView::OnRegionSharpening()
{
	CImageProHwangSeungHyeokDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (pDoc->inputImg.empty()) return;
	pDoc->RegionSharpening();
	viewMode = TWO_IMAGES;
	Invalidate(TRUE);

}

void CImageProHwangSeungHyeokView::OnRegionSobel()
{
	CImageProHwangSeungHyeokDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (pDoc->inputImg.empty()) return;
	pDoc->RegionSobel();
	viewMode = TWO_IMAGES;
	Invalidate(TRUE);
}

void CImageProHwangSeungHyeokView::OnRegionCanny()
{
	CImageProHwangSeungHyeokDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (pDoc->inputImg.empty()) return;
	pDoc->RegionCanny();
	viewMode = TWO_IMAGES;
	Invalidate(TRUE);
	
}

void CImageProHwangSeungHyeokView::OnRegionEmbossing()
{
	CImageProHwangSeungHyeokDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (pDoc->inputImg.empty()) return;
	pDoc->RegionEmbossing();
	viewMode = TWO_IMAGES;
	Invalidate(TRUE);
}

void CImageProHwangSeungHyeokView::OnRegionWaterColor()
{
	CImageProHwangSeungHyeokDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (pDoc->inputImg.empty()) return;
	pDoc->RegionWaterColor();
	viewMode = TWO_IMAGES;
	Invalidate(TRUE);

}

void CImageProHwangSeungHyeokView::OnGaussianBlurring()
{
	CImageProHwangSeungHyeokDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	if (pDoc->inputImg.empty()) return;
	pDoc->GaussianBlurring();
	viewMode = TWO_IMAGES;
	Invalidate(TRUE);
	
}

void CImageProHwangSeungHyeokView::OnMedianBlurring()
{
	CImageProHwangSeungHyeokDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	if (pDoc->inputImg.empty()) return;
	pDoc->MedianBlurring();
	viewMode = TWO_IMAGES;
	Invalidate(TRUE);
}

void CImageProHwangSeungHyeokView::OnBilateralBlurring()
{
	CImageProHwangSeungHyeokDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	if (pDoc->inputImg.empty()) return;
	pDoc->BilateralBlurring();
	viewMode = TWO_IMAGES;
	Invalidate(TRUE);
}

void CImageProHwangSeungHyeokView::OnRegionPrewitt()
{
	CImageProHwangSeungHyeokDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (pDoc->inputImg.empty()) return;
	pDoc->RegionPrewitt();
	viewMode = TWO_IMAGES;
	Invalidate(TRUE);

}

void CImageProHwangSeungHyeokView::OnRegionRoberts()
{
	CImageProHwangSeungHyeokDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (pDoc->inputImg.empty()) return;
	pDoc->RegionBoberts();
	viewMode = TWO_IMAGES;
	Invalidate(TRUE);

}

void CImageProHwangSeungHyeokView::OnRegionLaprasian()
{
	CImageProHwangSeungHyeokDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (pDoc->inputImg.empty()) return;
	pDoc->RegionLaprasian();
	viewMode = TWO_IMAGES;
	Invalidate(TRUE);
}

void CImageProHwangSeungHyeokView::OnPixelTwoImagesSub()
{
	CImageProHwangSeungHyeokDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->PixelTwoImagesSub();
	viewMode = THREE_IMAGES;
	Invalidate(TRUE);

}

void CImageProHwangSeungHyeokView::OnPixelTwoImagesAnd()
{
	CImageProHwangSeungHyeokDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->PixelTwoImagesAnd();
	viewMode = THREE_IMAGES;
	Invalidate(TRUE);
}

void CImageProHwangSeungHyeokView::OnPixelTwoImagesOr()
{
	CImageProHwangSeungHyeokDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->PixelTwoImagesOR();
	viewMode = THREE_IMAGES;
	Invalidate(TRUE);
}

void CImageProHwangSeungHyeokView::OnPixelTwoImagesXor()
{
	CImageProHwangSeungHyeokDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->PixelTwoImagesXOR();
	viewMode = THREE_IMAGES;
	Invalidate(TRUE);
}
