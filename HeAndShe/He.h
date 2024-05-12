#pragma once
#include "afxdialogex.h"


// Диалоговое окно He

class He : public CDialog
{
	DECLARE_DYNAMIC(He)

public:
	He(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~He();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_He };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_ctrlAnswer;
	int m_nColor;
	int m_nHeight;
	int m_nWeight;
	CEdit m_ctrlInf;
	CString m_strProf;
	CString m_strQuality;
	int m_nQI;
	CSliderCtrl m_ctrlQI;
	CSpinButtonCtrl m_ctrlSpin;
	afx_msg void OnWhoishe();
	virtual BOOL OnInitDialog();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnNMCustomdrawQi(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBnClickedColor3();
	afx_msg void OnEnChangeAnswer();
};
