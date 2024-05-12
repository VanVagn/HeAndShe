// CSheDialog.cpp: файл реализации
//

#include "pch.h"
#include "HeAndShe.h"
#include "afxdialogex.h"
#include "CSheDialog.h"


// Диалоговое окно CSheDialog

IMPLEMENT_DYNAMIC(CSheDialog, CDialog)

CSheDialog::CSheDialog(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_She, pParent)
	, m_bBeauty(FALSE)
	, m_bMind(FALSE)
	, m_bGoodness(FALSE)
	, m_bLove(FALSE)
	, m_bChild(FALSE)
	, m_strMain(_T(""))
	, m_strAnswerShe(_T(""))
{

}

CSheDialog::CSheDialog(CView* pView)
{
	m_pView = pView;
}

CSheDialog::~CSheDialog()
{
}

void CSheDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_CHECK1, m_bBeauty);
	DDX_Check(pDX, IDC_CHECK4, m_bMind);
	DDX_Check(pDX, IDC_CHECK3, m_bGoodness);
	DDX_Check(pDX, IDC_CHECK2, m_bLove);
	DDX_Check(pDX, IDC_CHECK5, m_bChild);
	DDX_CBString(pDX, IDC_MainQual, m_strMain);
	DDX_Text(pDX, IDC_AnswerShe, m_strAnswerShe);
}


BEGIN_MESSAGE_MAP(CSheDialog, CDialog)
	ON_BN_CLICKED(IDOK, &CSheDialog::OnOk)
	ON_BN_CLICKED(IDCANCEL, &CSheDialog::OnCancel)
END_MESSAGE_MAP()


// Обработчики сообщений CSheDialog


void CSheDialog::OnOk()
{
	const int n = 5;
	CString Ans[n];
	CString Answer;
	int Count = 0;
	Ans[0]="В жизни такие героини редко\r\nвстречаются. Советуем умерить\r\nзапросы";
	Ans[1]="Ваша героиня подобна Елене\r\nпрекрасной. Такой выбор однажды\r\nпривел к гибели Трон";
	Ans[2]="Гера - покровительница героини.\r\nВаша героиня подобна\r\nсвоей покровительнице.";
	Ans[3]="Ваша героиня подобна Пенелопе.\r\nВы, вероятно, подобны Одиссею";
	Ans[4]="Дать ответ не можем. Рекомендуем\r\nобратиться к профессиональным\r\nпсихологам.";
	UpdateData(TRUE);
	if (m_bBeauty) Count++;
	if (m_bGoodness) Count++;
	if (m_bMind) Count++;
	if (m_bLove) Count++;
	if (m_bChild) Count++;

	if (Count > 3) {
		Answer = Ans[0];
	}
	else if (m_strMain == "Красота") {
		Answer = Ans[1];
	}
	else if (m_strMain == "Любит детей") {
		Answer = Ans[2];
	}
	else if (m_strMain == "Умеет любить") {
		Answer = Ans[3];
	}
	else Answer = Ans[4];

	m_strAnswerShe = Answer;
	UpdateData(FALSE);
}


void CSheDialog::OnCancel()
{
	// TODO: добавьте свой код обработчика уведомлений
	CDialog::OnCancel();
}
bool CSheDialog::Create(void) {
	return CDialog::Create(CSheDialog::IDD);
}
