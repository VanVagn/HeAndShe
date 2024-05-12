
// HeAndSheDoc.cpp: реализация класса CHeAndSheDoc 
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "HeAndShe.h"
#endif

#include "HeAndSheDoc.h"

#include <propkey.h>
#include "He.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CHeAndSheDoc

IMPLEMENT_DYNCREATE(CHeAndSheDoc, CDocument)

BEGIN_MESSAGE_MAP(CHeAndSheDoc, CDocument)
	ON_COMMAND(ID_HE, &CHeAndSheDoc::OnHe)
END_MESSAGE_MAP()


// Создание или уничтожение CHeAndSheDoc

CHeAndSheDoc::CHeAndSheDoc() noexcept
{
	// TODO: добавьте код для одноразового вызова конструктора

}

CHeAndSheDoc::~CHeAndSheDoc()
{
}

BOOL CHeAndSheDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: добавьте код повторной инициализации
	// (Документы SDI будут повторно использовать этот документ)

	return TRUE;
}




// Сериализация CHeAndSheDoc

void CHeAndSheDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: добавьте код сохранения
	}
	else
	{
		// TODO: добавьте код загрузки
	}
}

#ifdef SHARED_HANDLERS

// Поддержка для эскизов
void CHeAndSheDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Измените этот код для отображения данных документа
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

// Поддержка обработчиков поиска
void CHeAndSheDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Задание содержимого поиска из данных документа.
	// Части содержимого должны разделяться точкой с запятой ";"

	// Например:  strSearchContent = _T("точка;прямоугольник;круг;объект ole;");
	SetSearchContent(strSearchContent);
}

void CHeAndSheDoc::SetSearchContent(const CString& value)
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

// Диагностика CHeAndSheDoc

#ifdef _DEBUG
void CHeAndSheDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CHeAndSheDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// Команды CHeAndSheDoc


void CHeAndSheDoc::OnHe()
{
	He dlgHe;
		dlgHe.m_nWeight = 80;
		dlgHe.m_nHeight = 180;
		dlgHe.m_nQI = 50;
		if (dlgHe.DoModal() == IDOK) {
			TRACE("Диалог окончен нажатием ОК");
		}
		else {
			TRACE("Диалог окончкен нажатием Cancel");
		}
		TRACE("Характеристики героя:\n Рост - %u \nВес - %u \n КИ =%u \n", dlgHe.m_nHeight, dlgHe.m_nHeight, dlgHe.m_nQI);
		TRACE("Професссия - %s\n Главное качество - %s\n", dlgHe.m_strProf, dlgHe.m_strQuality);
}
