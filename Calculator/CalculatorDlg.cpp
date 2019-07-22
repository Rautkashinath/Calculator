
// CalculatorDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Calculator.h"
#include "CalculatorDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCalculatorDlg dialog



CCalculatorDlg::CCalculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALCULATOR_DIALOG, pParent)
	, m_result(_T("0"))
	, m_history(_T(""))
	, str(_T(""))
	, isPreviousOperator(true)
	, reset(true)
	, isEquals(false)
	, leftExpression(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON_0, m_button0);
	DDX_Control(pDX, IDC_BUTTON_1, m_button1);
	DDX_Control(pDX, IDC_BUTTON_2, m_button2);
	DDX_Control(pDX, IDC_BUTTON_3, m_button3);
	DDX_Control(pDX, IDC_BUTTON_4, m_button4);
	DDX_Control(pDX, IDC_BUTTON_5, m_button5);
	DDX_Control(pDX, IDC_BUTTON_6, m_button6);
	DDX_Control(pDX, IDC_BUTTON_7, m_button7);
	DDX_Control(pDX, IDC_BUTTON_8, m_button8);
	DDX_Control(pDX, IDC_BUTTON_9, m_button9);
	DDX_Control(pDX, IDC_BUTTON_DIVIDE, m_buttonDivide);
	DDX_Control(pDX, IDC_BUTTON_MULTIPLY, m_buttonMultiply);
	DDX_Control(pDX, IDC_BUTTON_MINUS, m_buttonMinus);
	DDX_Control(pDX, IDC_BUTTON_PLUS, m_buttonPlus);
	DDX_Control(pDX, IDC_BUTTON_EQUALS, m_buttonEquals);
	DDX_Control(pDX, IDC_BUTTON_PERCENT, m_buttonPercentage);
	DDX_Control(pDX, IDC_BUTTON_CLEAR, m_buttonC);
	DDX_Control(pDX, IDC_BUTTON_BACK, m_buttonBack);
	DDX_Control(pDX, IDC_BUTTON_POINT, m_buttonPoint);
	DDX_Control(pDX, IDC_BUTTON_NEGATIVE_POSITIVE, m_buttonTogglePositiveNegative);
	DDX_Text(pDX, IDC_EDIT_RESULT, m_result);
	DDX_Control(pDX, IDC_EDIT_RESULT, m_resultCtl);
	DDX_Text(pDX, IDC_EDIT_HISTORY, m_history);
}

BEGIN_MESSAGE_MAP(CCalculatorDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_0, &CCalculatorDlg::OnBnClickedButton0)
	ON_BN_CLICKED(IDC_BUTTON_1, &CCalculatorDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON_2, &CCalculatorDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON_3, &CCalculatorDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON_4, &CCalculatorDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON_5, &CCalculatorDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON_6, &CCalculatorDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON_7, &CCalculatorDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON_8, &CCalculatorDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON_9, &CCalculatorDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON_DIVIDE, &CCalculatorDlg::OnBnClickedButtonDivide)
	ON_BN_CLICKED(IDC_BUTTON_MULTIPLY, &CCalculatorDlg::OnBnClickedButtonMultiply)
	ON_BN_CLICKED(IDC_BUTTON_MINUS, &CCalculatorDlg::OnBnClickedButtonMinus)
	ON_BN_CLICKED(IDC_BUTTON_PLUS, &CCalculatorDlg::OnBnClickedButtonPlus)
	ON_BN_CLICKED(IDC_BUTTON_EQUALS, &CCalculatorDlg::OnBnClickedButtonEquals)
	ON_BN_CLICKED(IDC_BUTTON_NEGATIVE_POSITIVE, &CCalculatorDlg::OnBnClickedButtonNegativePositive)
	ON_BN_CLICKED(IDC_BUTTON_POINT, &CCalculatorDlg::OnBnClickedButtonPoint)
	ON_BN_CLICKED(IDC_BUTTON_PERCENT, &CCalculatorDlg::OnBnClickedButtonPercent)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, &CCalculatorDlg::OnBnClickedButtonClear)
	ON_BN_CLICKED(IDC_BUTTON_BACK, &CCalculatorDlg::OnBnClickedButtonBack)
END_MESSAGE_MAP()


// CCalculatorDlg message handlers

BOOL CCalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CCalculatorDlg::CalculateResult(char op)
{
	if (isPreviousOperator)
	{
		if (m_history == "")
		{
			m_resultCtl.GetWindowTextW(str);
			m_history = str;
		}
		m_history.Trim(lastOperator);
		m_history += op;
	}
	else
	{
		if (lastOperator == '\0')
		{
			lastOperator = op;
		}
		m_resultCtl.GetWindowTextW(str);
		m_history += str;
		m_history += op;
		SetOperationResult(lastOperator,str);
		m_result.Format(_T("%f"), leftExpression);
		isPreviousOperator = true;
	}
	lastOperator = op;
	UpdateData(false);
}

void CCalculatorDlg::SetOperationResult(char op, CString str)
{
	if (reset == true)
	{
		leftExpression = _ttof(str);
		reset = false;
	}
	else
	{
		switch (op)
		{
		case '+':
			leftExpression += _ttof(str);
			break;
		case '-':
			leftExpression -= _ttof(str);
			break;
		case '*':
			leftExpression *= _ttof(str);
			break;
		case '/':
			leftExpression /= _ttof(str);
			break;
		}
	}
}
void CCalculatorDlg::AppendDigit(char digit)
{
	if (isPreviousOperator || isEquals)
	{
		m_result = digit;
		isPreviousOperator = false;
		isEquals = false;
	}
	else
	{
		if (!(m_result == "0" && digit == '0'))
		{
			if (m_result == "0")
				m_result = "";
			m_result += digit;
		}
	}
	UpdateData(false);
}

void CCalculatorDlg::OnBnClickedButton0()
{
	AppendDigit('0');
}


void CCalculatorDlg::OnBnClickedButton1()
{
	AppendDigit('1');
}


void CCalculatorDlg::OnBnClickedButton2()
{
	AppendDigit('2');
}


void CCalculatorDlg::OnBnClickedButton3()
{
	AppendDigit('3');
}


void CCalculatorDlg::OnBnClickedButton4()
{
	AppendDigit('4');
}


void CCalculatorDlg::OnBnClickedButton5()
{
	AppendDigit('5');
}


void CCalculatorDlg::OnBnClickedButton6()
{
	AppendDigit('6');
}


void CCalculatorDlg::OnBnClickedButton7()
{
	AppendDigit('7');
}


void CCalculatorDlg::OnBnClickedButton8()
{
	AppendDigit('8');
}


void CCalculatorDlg::OnBnClickedButton9()
{
	AppendDigit('9');
}


void CCalculatorDlg::OnBnClickedButtonDivide()
{
	CalculateResult('/');
}


void CCalculatorDlg::OnBnClickedButtonMultiply()
{
	CalculateResult('*');
}


void CCalculatorDlg::OnBnClickedButtonMinus()
{
	CalculateResult('-');
}


void CCalculatorDlg::OnBnClickedButtonPlus()
{
	CalculateResult('+');
	/*m_resultCtl.GetWindowTextW(str);
	m_history += str;
	m_history += "+";
	leftExpression += _ttof(str);
	m_result.Format(_T("%f"), leftExpression);
	UpdateData(false);
	ispreviousOperation = true;*/
}


void CCalculatorDlg::OnBnClickedButtonEquals()
{
	m_resultCtl.GetWindowTextW(str);
	m_history = "";
	SetOperationResult(lastOperator, str);
	m_result.Format(_T("%f"), leftExpression);
	leftExpression = 0;
	isPreviousOperator = false;
	reset = true;
	isEquals = true;
	UpdateData(false);

}


void CCalculatorDlg::OnBnClickedButtonNegativePositive()
{
	// TODO: Add your control notification handler code here
}


void CCalculatorDlg::OnBnClickedButtonPoint()
{
	if(m_result.Find('.')<0)
		AppendDigit('.');
}


void CCalculatorDlg::OnBnClickedButtonPercent()
{
	// TODO: Add your control notification handler code here
}


void CCalculatorDlg::OnBnClickedButtonClear()
{
	m_result = "0";
	m_history = "";
	leftExpression = 0;
	lastOperator = '\0';
	reset = true;
	UpdateData(false);
}


void CCalculatorDlg::OnBnClickedButtonBack()
{
	// TODO: Add your control notification handler code here
}
