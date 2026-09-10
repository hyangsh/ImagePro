
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
