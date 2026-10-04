
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

void CImageProHwangSeungHyeokDoc::MorphologyErosion()
{
	erode(inputImg, resultImg, Mat());

}

void CImageProHwangSeungHyeokDoc::MorphologyDilation()
{
	dilate(inputImg, resultImg, Mat());
}

void CImageProHwangSeungHyeokDoc::MorphologyOpening()
{
	Mat tmp;
	erode(inputImg, tmp, Mat());
	erode(tmp, tmp, Mat());
	erode(tmp, tmp, Mat());
	dilate(tmp, tmp, Mat());
	dilate(tmp, tmp, Mat());
	dilate(tmp, resultImg, Mat());
}

void CImageProHwangSeungHyeokDoc::MorphologyClosing()
{
	Mat tmp;
	dilate(inputImg, tmp, Mat());
	dilate(tmp, tmp, Mat());
	dilate(tmp, tmp, Mat());
	erode(tmp, tmp, Mat());
	erode(tmp, tmp, Mat());
	erode(tmp, resultImg, Mat());
}

void CImageProHwangSeungHyeokDoc::MorphologyGradient()
{
	morphologyEx(inputImg, resultImg, MORPH_GRADIENT, Mat());

}

void CImageProHwangSeungHyeokDoc::MorphologyTopHat()
{
	morphologyEx(inputImg, resultImg, MORPH_TOPHAT, Mat());
}


void CImageProHwangSeungHyeokDoc::MorphologyBlackHat()
{
	morphologyEx(inputImg, resultImg, MORPH_BLACKHAT, Mat());
	
}

void CImageProHwangSeungHyeokDoc::MorphologyHitOrMiss()
{
	Mat out_imgs[4];

	int data1[25] = { 0, 0, -1, 0, 0, 0, 0, -1, 0, 0, 0, 0, -1, 0, 0, 0, 0, -1, 0, 0, 0, 0, 1, 0, 0 };
	int data2[25] = { 0, 0, 1, 0, 0, 0, 0, -1, 0, 0, 0, 0, -1, 0, 0, 0, 0, -1, 0, 0, 0, 0, -1, 0, 0 };
	int data3[25] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1, -1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int data4[25] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	Mat top(5, 5, CV_32SC1, data1);
	Mat bottom(5, 5, CV_32SC1, data2);
	Mat left(5, 5, CV_32SC1, data3);
	Mat right(5, 5, CV_32SC1, data4);
	morphologyEx(inputImg, out_imgs[0], MORPH_HITMISS, top);
	morphologyEx(inputImg, out_imgs[1], MORPH_HITMISS, bottom);
	morphologyEx(inputImg, out_imgs[2], MORPH_HITMISS, left);
	morphologyEx(inputImg, out_imgs[3], MORPH_HITMISS, right);
	resultImg = out_imgs[0] + out_imgs[1] + out_imgs[2] + out_imgs[3];

}

void CImageProHwangSeungHyeokDoc::MorphologyLineDetection()
{
	Mat gray, bw;
	gray = inputImg;
	if (gray.channels() > 1) cvtColor(gray, gray, COLOR_BGR2GRAY);

	bitwise_not(gray, gray);  // 배경이 0인 영상으로 변환
	threshold(gray, bw, 0, 255, THRESH_OTSU); // 이진 영상으로 변환
	Mat horizontal = bw.clone();
	Mat vertical = bw.clone();
	Mat horizontalStructure = getStructuringElement(MORPH_RECT, Size(17, 1));
	erode(horizontal, horizontal, horizontalStructure);
	dilate(horizontal, horizontal, horizontalStructure);
	bitwise_not(horizontal, horizontal);

	Mat verticalStructure = getStructuringElement(MORPH_RECT, Size(1, 5));
	erode(vertical, vertical, verticalStructure);
	dilate(vertical, vertical, verticalStructure);
	bitwise_not(vertical, vertical);
	// 입력 영상의 높이의 2배가되는 출력 영상 생성
	// 윗 부분에 수직선 검출 결과를 아랫 부분에 수평선 검출 결과를 저장
	resultImg = Mat(Size(inputImg.cols, inputImg.rows * 2), vertical.type());
	vertical.copyTo(resultImg(Rect(0, 0, inputImg.cols, inputImg.rows)));
	horizontal.copyTo(resultImg(Rect(0, inputImg.rows, inputImg.cols, inputImg.rows)));

}

void CImageProHwangSeungHyeokDoc::MorphologyCountCell()
{
	resultImg = inputImg.clone();
	if (resultImg.channels() > 1) cvtColor(resultImg, resultImg, COLOR_BGR2GRAY);
	threshold(resultImg, resultImg, 128, 255, THRESH_BINARY);
	bitwise_not(resultImg, resultImg);
	erode(resultImg, resultImg, Mat());
	erode(resultImg, resultImg, Mat());
	erode(resultImg, resultImg, Mat());
	dilate(resultImg, resultImg, Mat());
	dilate(resultImg, resultImg, Mat());
	dilate(resultImg, resultImg, Mat());
	Mat labelImage(resultImg.size(), CV_32S);
	int nLabels = connectedComponents(resultImg, labelImage);

	CString buf;
	buf.Format(L"셀의 개수 = %d", nLabels - 1);
	AfxMessageBox(buf);
}

void CImageProHwangSeungHyeokDoc::RegionBlurring()
{
	blur(inputImg, resultImg, Size(5, 5));
}

void CImageProHwangSeungHyeokDoc::RegionSharpening()
{
	float data[9] = { 0, -1, 0, -1, 5, -1, 0, -1, 0 };
	Mat kernel(3, 3, CV_32FC1, data);


	filter2D(inputImg, resultImg, -1, kernel);
}

void CImageProHwangSeungHyeokDoc::RegionSobel()
{
	Mat grad_v, grad_h;
	float arr1[9] = { 1, 0, -1, 2, 0, -2, 1, 0, -1 };
	Mat kernel_v(3, 3, CV_32FC1, arr1);
	float arr2[9] = { -1, -2, -1, 0, 0, 0, 1, 2, 1 };
	Mat kernel_h(3, 3, CV_32FC1, arr2);
	Mat img;
	img = inputImg.clone();
	if (img.channels() > 1) cvtColor(img, img, COLOR_BGR2GRAY);
	filter2D(img, grad_v, CV_32FC1, kernel_v);
	filter2D(img, grad_h, CV_32FC1, kernel_h);
	magnitude(grad_v, grad_h, img); // img = sqrt(grad_v2 + grad_h2)
	img.convertTo(resultImg, CV_8UC1); // 32비트 실수를 8비트 uchar로 변환

}

void CImageProHwangSeungHyeokDoc::RegionCanny()
{
	Mat img;
	int lowThreshold = 50;
	const int ratio = 3;
	const int kernel_size = 3;
	img = inputImg.clone();
	if (img.channels() > 1) cvtColor(img, img, COLOR_BGR2GRAY);
	blur(img, img, Size(3, 3));
	Canny(img, resultImg, lowThreshold, lowThreshold * ratio, kernel_size);

}

void CImageProHwangSeungHyeokDoc::RegionEmbossing()
{
	float data[9] = { -1, 0, 0, 0, 0, 0, 0, 0, 1 };
	Mat kernel(3, 3, CV_32FC1, data);

	if (inputImg.channels() > 1) {
		vector<Mat> channels;
		Mat img;
		cvtColor(inputImg, img, COLOR_BGR2HSV);
		split(img, channels);
		filter2D(channels[2], channels[2], -1, kernel, Point(-1, -1), 128);
		merge(channels, img);
		cvtColor(img, resultImg, COLOR_HSV2BGR);
	}
	else filter2D(inputImg, resultImg, -1, kernel, Point(-1, -1), 128);


}

void CImageProHwangSeungHyeokDoc::RegionWaterColor()
{
	Mat img1, img2;

	img1 = inputImg.clone();
	for (int i = 0; i < 20; i++)
		if (i % 2 == 0) bilateralFilter(img1, img2, 7, 30, 3);
		else bilateralFilter(img2, img1, 7, 30, 3);
	resultImg = img1.clone();

}

void CImageProHwangSeungHyeokDoc::GaussianBlurring()
{
	GaussianBlur(inputImg, resultImg, Size(5, 5), 0);
}

void CImageProHwangSeungHyeokDoc::MedianBlurring()
{
	medianBlur(inputImg, resultImg, 5);
}

void CImageProHwangSeungHyeokDoc::BilateralBlurring()
{
	bilateralFilter(inputImg, resultImg, -1, 50, 50);
}

void CImageProHwangSeungHyeokDoc::RegionPrewitt()
{
	Mat img;
	img = inputImg.clone(); 
	if (img.channels() > 1) cvtColor(img, img, COLOR_BGR2GRAY); 
	blur(img, img, Size(3, 3)); 

	float prewitt_x[] = { -1, 0, 1, -1, 0, 1, -1, 0, 1 };
	float prewitt_y[] = { -1, -1, -1, 0, 0, 0, 1, 1, 1 };

	Mat kernel_x = Mat(3, 3, CV_32F, prewitt_x);
	Mat kernel_y = Mat(3, 3, CV_32F, prewitt_y);

	Mat grad_x, grad_y;
	filter2D(img, grad_x, CV_16S, kernel_x);
	filter2D(img, grad_y, CV_16S, kernel_y);

	convertScaleAbs(grad_x, grad_x);
	convertScaleAbs(grad_y, grad_y);

	addWeighted(grad_x, 0.5, grad_y, 0.5, 0, resultImg);
}

void CImageProHwangSeungHyeokDoc::RegionBoberts()
{
	Mat img;
	img = inputImg.clone(); 
	if (img.channels() > 1) cvtColor(img, img, COLOR_BGR2GRAY); 
	blur(img, img, Size(3, 3));  
	float roberts_x[] = { 1, 0, 0, -1 };
	float roberts_y[] = { 0, 1, -1, 0 };
	Mat kernel_x = Mat(2, 2, CV_32F, roberts_x);
	Mat kernel_y = Mat(2, 2, CV_32F, roberts_y);

	Mat grad_x, grad_y;
	filter2D(img, grad_x, CV_16S, kernel_x);
	filter2D(img, grad_y, CV_16S, kernel_y);

	convertScaleAbs(grad_x, grad_x);
	convertScaleAbs(grad_y, grad_y);

	addWeighted(grad_x, 0.5, grad_y, 0.5, 0, resultImg);
}

void CImageProHwangSeungHyeokDoc::RegionLaprasian()
{
	Mat img;
	const int kernel_size = 3;  
	img = inputImg.clone(); 
	if (img.channels() > 1) cvtColor(img, img, COLOR_BGR2GRAY); 
	blur(img, img, Size(3, 3));  

	Mat img_laplacian;
	 
	Laplacian(img, img_laplacian, CV_16S, kernel_size);
 
	convertScaleAbs(img_laplacian, resultImg);
}

void CImageProHwangSeungHyeokDoc::PixelTwoImagesSub()
{
	LoadTwoImages();
	subtract(inputImg, inputImg2, resultImg);

}

void CImageProHwangSeungHyeokDoc::PixelTwoImagesAnd()
{
	LoadTwoImages();
	bitwise_and(inputImg, inputImg2, resultImg);
}

void CImageProHwangSeungHyeokDoc::PixelTwoImagesOR()
{
	LoadTwoImages();
	bitwise_or(inputImg, inputImg2, resultImg);
}

void CImageProHwangSeungHyeokDoc::PixelTwoImagesXOR()
{
	LoadTwoImages();
	bitwise_xor(inputImg, inputImg2, resultImg);
}
