
// HeAndSheView.cpp: реализация класса CHeAndSheView
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "HeAndShe.h"
#endif

#include "HeAndSheDoc.h"
#include "HeAndSheView.h"
#include "CSheDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CHeAndSheView

IMPLEMENT_DYNCREATE(CHeAndSheView, CFormView)

BEGIN_MESSAGE_MAP(CHeAndSheView, CFormView)
	// Стандартные команды печати
	ON_COMMAND(ID_FILE_PRINT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFormView::OnFilePrintPreview)
	ON_COMMAND(ID_SHE, &CHeAndSheView::OnShe)
	ON_MESSAGE(WM_ENDOFDIAL, OnEndOfDialog)
	ON_UPDATE_COMMAND_UI(ID_SHE, &CHeAndSheView::OnUpdateShe)
END_MESSAGE_MAP()

// Создание или уничтожение CHeAndSheView

CHeAndSheView::CHeAndSheView() noexcept
	: CFormView(IDD_HEANDSHE_FORM)
{
	m_pSheDialog = new CSheDialog(this);
	m_bEnableShe = TRUE;
}

CHeAndSheView::~CHeAndSheView()
{
	delete m_pSheDialog;
}

void CHeAndSheView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL CHeAndSheView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CHeAndSheView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// Печать CHeAndSheView

BOOL CHeAndSheView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// подготовка по умолчанию
	return DoPreparePrinting(pInfo);
}

void CHeAndSheView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте дополнительную инициализацию перед печатью
}

void CHeAndSheView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте очистку после печати
}

void CHeAndSheView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте свой код печати
}


// Диагностика CHeAndSheView

#ifdef _DEBUG
void CHeAndSheView::AssertValid() const
{
	CFormView::AssertValid();
}

void CHeAndSheView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CHeAndSheDoc* CHeAndSheView::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CHeAndSheDoc)));
	return (CHeAndSheDoc*)m_pDocument;
}
#endif //_DEBUG


// Обработчики сообщений CHeAndSheView

void CHeAndSheView::OnShe()
{
	TRACE("Обработчик OnShe\n");
	m_pSheDialog->m_bBeauty = TRUE;
	m_pSheDialog->m_bChild = FALSE;
	m_pSheDialog->m_bGoodness = FALSE;
	m_pSheDialog->m_bLove = TRUE;
	m_pSheDialog->m_bMind = FALSE;
	m_pSheDialog->m_strMain = "";
	m_pSheDialog->m_strAnswerShe = "";
	m_pSheDialog->Create();
	m_bEnableShe = FALSE;
}

LRESULT CHeAndSheView::OnEndOfDialog(WPARAM wParam, LPARAM lParam)
{
	m_pSheDialog->DestroyWindow();
	m_bEnableShe = TRUE;
	return 0L;
}

void CHeAndSheView::OnUpdateShe(CCmdUI* pCmdUI)
{
	pCmdUI->Enable(m_bEnableShe);
}
