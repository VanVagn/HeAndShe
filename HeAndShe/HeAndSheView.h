
// HeAndSheView.h: интерфейс класса CHeAndSheView
//

#pragma once
#include "CSheDialog.h"
class CSheDialog;


class CHeAndSheView : public CFormView
{
protected: // создать только из сериализации
	CHeAndSheView() noexcept;
	DECLARE_DYNCREATE(CHeAndSheView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_HEANDSHE_FORM };
#endif

// Атрибуты
public:
	CHeAndSheDoc* GetDocument() const;

	void OnShe();

	LRESULT OnEndOfDialog(WPARAM wParam, LPARAM lParam);


	

// Операции
public:

// Переопределение
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV
	virtual void OnInitialUpdate(); // вызывается в первый раз после конструктора
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);

// Реализация
public:
	virtual ~CHeAndSheView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()
public:
	CSheDialog* m_pSheDialog;
	afx_msg void OnUpdateShe(CCmdUI* pCmdUI);
	bool m_bEnableShe;
};

#ifndef _DEBUG  // версия отладки в HeAndSheView.cpp
inline CHeAndSheDoc* CHeAndSheView::GetDocument() const
   { return reinterpret_cast<CHeAndSheDoc*>(m_pDocument); }
#endif

