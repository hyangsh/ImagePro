
// ImagePro_HwangSeungHyeokDoc.cpp: CImageProHwangSeungHyeokDoc 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "ImagePro_HwangSeungHyeok.h"
#endif

#include "ImagePro_HwangSeungHyeokDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CImageProHwangSeungHyeokDoc

IMPLEMENT_DYNCREATE(CImageProHwangSeungHyeokDoc, CDocument)

BEGIN_MESSAGE_MAP(CImageProHwangSeungHyeokDoc, CDocument)
END_MESSAGE_MAP()


// CImageProHwangSeungHyeokDoc 생성/소멸

CImageProHwangSeungHyeokDoc::CImageProHwangSeungHyeokDoc() noexcept
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CImageProHwangSeungHyeokDoc::~CImageProHwangSeungHyeokDoc()
{
}

BOOL CImageProHwangSeungHyeokDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// CImageProHwangSeungHyeokDoc serialization

void CImageProHwangSeungHyeokDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 여기에 저장 코드를 추가합니다.
	}
	else
	{
		inputImg = imread((String)CT2A(ar.GetFile()->GetFilePath()), IMREAD_UNCHANGED);

	}
}

#ifdef SHARED_HANDLERS

// 축소판 그림을 지원합니다.
void CImageProHwangSeungHyeokDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 문서의 데이터를 그리려면 이 코드를 수정하십시오.
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 검색 처리기를 지원합니다.
void CImageProHwangSeungHyeokDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 문서의 데이터에서 검색 콘텐츠를 설정합니다.
	// 콘텐츠 부분은 ";"로 구분되어야 합니다.

	// 예: strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CImageProHwangSeungHyeokDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CImageProHwangSeungHyeokDoc 진단

#ifdef _DEBUG
void CImageProHwangSeungHyeokDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CImageProHwangSeungHyeokDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CImageProHwangSeungHyeokDoc 명령

void CImageProHwangSeungHyeokDoc::PixelAdd()
{
	if (inputImg.channels() == 1)
		resultImg = inputImg + 100;
	else
		resultImg = inputImg + Scalar(100, 100, 100);

}

void CImageProHwangSeungHyeokDoc::PixelSub()
{
	if (inputImg.channels() == 1)
		resultImg = inputImg - 100;
	else
		resultImg = inputImg - Scalar(100, 100, 100);

}

void CImageProHwangSeungHyeokDoc::PixelMUL()
{
	resultImg = inputImg * 1.2;
}

void CImageProHwangSeungHyeokDoc::PixelDiv()
{
	resultImg = inputImg / 1.2;
}

int CImageProHwangSeungHyeokDoc::PixelHistoEq()
{
	if (inputImg.channels() > 1)
		cvtColor(inputImg, inputImg, COLOR_BGR2GRAY);
	equalizeHist(inputImg, resultImg);
	return 0;
}

void CImageProHwangSeungHyeokDoc::PixelContrastStretching()
{
	if (inputImg.channels() > 1)
		cvtColor(inputImg, inputImg, COLOR_BGR2GRAY);
	normalize(inputImg, resultImg, 0, 255, NORM_MINMAX);

}

void CImageProHwangSeungHyeokDoc::drawHist()
{
	// TODO: 여기에 구현 코드 추가.
}

void CImageProHwangSeungHyeokDoc::PixelBinarization()
{
	int T = 128;
	if (inputImg.channels() > 1)
		cvtColor(inputImg, inputImg, COLOR_BGR2GRAY);
	threshold(inputImg, resultImg, T, 255, THRESH_BINARY);

}



void CImageProHwangSeungHyeokDoc::PixelBinarizationAdaptiveThresh()
{
	if (inputImg.channels() > 1)
		cvtColor(inputImg, inputImg, COLOR_BGR2GRAY);
	adaptiveThreshold(inputImg, resultImg, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 11, 7);

}

void CImageProHwangSeungHyeokDoc::PixelBinarizationAutoThresh()
{	// TODO: 여기에 구현 코드 추가.
	if (inputImg.channels() > 1)
		cvtColor(inputImg, inputImg, COLOR_BGR2GRAY);
	threshold(inputImg, resultImg, 0, 255, THRESH_OTSU);

}

void CImageProHwangSeungHyeokDoc::PixelBinarizationHRange()
{
	Mat inputImg_HSV;

	if (inputImg.channels() != 3) {
		AfxMessageBox(L"컬러 영상을 입력해주세요");
		return;
	}
	cvtColor(inputImg, inputImg_HSV, COLOR_BGR2HSV);
	inRange(inputImg_HSV, Scalar(15, 0, 0), Scalar(30, 255, 255), resultImg);
	
}

void CImageProHwangSeungHyeokDoc::PixelInvert()
{
	bitwise_not(inputImg, resultImg);

}

void CImageProHwangSeungHyeokDoc::PixelQuantization()
{
	int N = 4;
	Mat lookUpTable(1, 256, CV_8U); // 1행 256열의 영상 생성
	for (int i = 0; i < 256; i++) {
		int level = i / (256 / N), value;
		if (level == 0) value = 0;
		else if (level == N - 1) value = 255;
		else value = (level * (256 / N) + (level + 1) * (256 / N)) / 2;
		lookUpTable.at<BYTE>(0, i) = value;
	}
	LUT(inputImg, lookUpTable, resultImg);

}

void CImageProHwangSeungHyeokDoc::PixelRangeHighligthing()
{
	int start = 100, end = 150;

	Mat lookUpTable(1, 256, CV_8U);
	for (int i = 0; i < 256; i++)
		if (i >= start && i <= end) lookUpTable.at<BYTE>(0, i) = 255;
		else lookUpTable.at<BYTE>(0, i) = i;

	LUT(inputImg, lookUpTable, resultImg);

}

void CImageProHwangSeungHyeokDoc::PixelGammaCorrection()
{
	float gamma = 0.4;

	Mat lookUpTable(1, 256, CV_8U);
	for (int i = 0; i < 256; ++i) {
		int value = pow(i / 255.0, gamma) * 255.0;
		lookUpTable.at<BYTE>(0, i) = value;
	}
	LUT(inputImg, lookUpTable, resultImg);

}

void CImageProHwangSeungHyeokDoc::PixelTwoImagesAdd()
{
	LoadTwoImages();
	add(inputImg, inputImg2, resultImg);

}

void CImageProHwangSeungHyeokDoc::LoadTwoImages()
{
	CFileDialog dlg(TRUE);   // 파일 선택 대화상자 객체 선언
	//        TRUE : 파일 열기
	//         FALSE : 파일 저장
	AfxMessageBox(L"Select the First Image");
	if (dlg.DoModal() == IDOK)       // 파일 선택 대화 상자 실행 
		inputImg = imread((String)CT2A(dlg.GetPathName()));

	AfxMessageBox(L"Select the Second Image");
	if (dlg.DoModal() == IDOK)       // 파일 선택 대화 상자 실행 
		inputImg2 = imread((String)CT2A(dlg.GetPathName()));

}

void CImageProHwangSeungHyeokDoc::PixelTwoImagesAddLogo()
{
	LoadTwoImages();
	Mat roi = inputImg(Rect(0, 0, inputImg2.cols, inputImg2.rows));
	Mat img2gray, mask, mask_inv, img1_bg, img2_fg, dst;
	cvtColor(inputImg2, img2gray, COLOR_BGR2GRAY);
	threshold(img2gray, mask, 10, 255, THRESH_BINARY);
	bitwise_not(mask, mask_inv);
	bitwise_and(inputImg2, inputImg2, img2_fg, mask = mask);
	bitwise_and(roi, roi, img1_bg, mask = mask_inv);
	add(img1_bg, img2_fg, dst);
	resultImg = inputImg.clone();
	dst.copyTo(resultImg(Rect(0, 0, inputImg2.cols, inputImg2.rows)));

}
