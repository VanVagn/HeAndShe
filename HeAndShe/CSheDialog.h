#pragma once
#include "afxdialogex.h"
#define WM_ENDOFDIAL WM_USER +7

// Диалоговое окно CSheDialog

class CSheDialog : public CDialog
{
	DECLARE_DYNAMIC(CSheDialog)

public:
	CSheDialog(CWnd* pParent = nullptr);// стандартный конструктор
	CSheDialog(CView* pView);
	virtual ~CSheDialog();

// Данные диалогового окна
	enum { IDD = IDD_She };


protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	BOOL m_bBeauty;
	BOOL m_bMind;
	BOOL m_bGoodness;
	BOOL m_bLove;
	BOOL m_bChild;
	CString m_strMain;
	CString m_strAnswerShe;
	afx_msg void OnOk();
	afx_msg void OnCancel();
	bool Create(void);
	CView* m_pView;
};
