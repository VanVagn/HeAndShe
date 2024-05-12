// He.cpp: файл реализации
//

#include "pch.h"
#include "HeAndShe.h"
#include "afxdialogex.h"
#include "He.h"


// Диалоговое окно He

IMPLEMENT_DYNAMIC(He, CDialog)

He::He(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_He, pParent)
	, m_nColor(0)
	, m_nHeight(0)
	, m_nWeight(0)
	, m_strProf(_T(""))
	, m_strQuality(_T(""))
	, m_nQI(0)
	
{

}

He::~He()
{
}

void He::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_Answer, m_ctrlAnswer);
	DDX_Radio(pDX, IDC_Color1, m_nColor);
	DDX_Text(pDX, IDC_Height, m_nHeight);
	DDX_Text(pDX, IDC_Weight, m_nWeight);
	DDX_Control(pDX, IDC_Inf, m_ctrlInf);
	DDX_CBString(pDX, IDC_Prof, m_strProf);
	DDX_CBString(pDX, IDC_Quality, m_strQuality);
	DDX_Text(pDX, IDC_QI, m_nQI);
	DDX_Slider(pDX, IDC_QI, m_nQI);
	DDX_Control(pDX, IDC_QI, m_ctrlQI);
	DDX_Control(pDX, IDC_SPIN1, m_ctrlSpin);
}


BEGIN_MESSAGE_MAP(He, CDialog)
	ON_BN_CLICKED(IDC_WhoIsHe, &He::OnWhoishe)
	ON_WM_HSCROLL()
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_QI, &He::OnNMCustomdrawQi)
	ON_BN_CLICKED(IDC_Color3, &He::OnBnClickedColor3)
	ON_EN_CHANGE(IDC_Answer, &He::OnEnChangeAnswer)
END_MESSAGE_MAP()


// Обработчики сообщений He


void He::OnWhoishe()
{
	const int n = 5;
	CString Ans[n];
	CString Answer;
	Ans[0] = "Марс - покровитель героя \r\nВаш герой подобен своему \r\nпокровителю.";
	Ans[1] = "Гермес - покровитель героя \r\nВаш герой подобен своему \r\nпокровителю.";
	Ans[2] = "Аполлон - покровитель героя \r\nВаш герой подобен своему \r\nпокровителю.";
	Ans[3] = "Мы не знаем, кто ваш герой, \r\nно наш герой - это Вы";
	Ans[4] = "Дать ответ не можем. \r\nРекомендуем обратиться к \r\nпрофессиональным психологам.";
	UpdateData(TRUE);
	if (m_strProf == "Воин") Answer = Ans[0];
	else if (m_strProf == "Предприниматель") Answer = Ans[1];
	else if (m_strProf == "Художник") Answer = Ans[2];
	else if (m_strProf == "Программист") Answer = Ans[3];
	else Answer= Ans[4];
	m_ctrlAnswer.SetWindowText(Answer);

}


BOOL He::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_ctrlInf.SetWindowText(_T("Хотите знать, кто ваш герой? Задайте его \r\nхарактеристики и нажмите кнопку: Кто он?"));
	m_ctrlSpin.SetRange(50, 150);
	CString strQI;
	m_ctrlQI.SetRange(0, 100);
	m_ctrlQI.SetPos(50);
	strQI.Format(_T("%d"), m_ctrlQI.GetPos());
	SetDlgItemText(IDC_STATIC_QI, strQI);

	return TRUE;  
}


void He::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{

	CString strQI;
	strQI.Format(_T("%d"), m_ctrlQI.GetPos());
	SetDlgItemText(IDC_STATIC_QI, strQI);

	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}


void He::OnNMCustomdrawQi(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: добавьте свой код обработчика уведомлений
	*pResult = 0;
}


void He::OnBnClickedColor3()
{
	// TODO: добавьте свой код обработчика уведомлений
}


void He::OnEnChangeAnswer()
{
	// TODO:  Если это элемент управления RICHEDIT, то элемент управления не будет
	// send this notification unless you override the CDialog::OnInitDialog()
	// функция и вызов CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Добавьте код элемента управления
}
