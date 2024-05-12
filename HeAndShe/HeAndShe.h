
// HeAndShe.h: основной файл заголовка для приложения HeAndShe
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CHeAndSheApp:
// Сведения о реализации этого класса: HeAndShe.cpp
//

class CHeAndSheApp : public CWinApp
{
public:
	CHeAndSheApp() noexcept;


// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Реализация
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CHeAndSheApp theApp;
