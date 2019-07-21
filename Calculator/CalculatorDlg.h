
// CalculatorDlg.h : header file
//

#pragma once


// CCalculatorDlg dialog
class CCalculatorDlg : public CDialogEx
{
// Construction
public:
	CCalculatorDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCULATOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CButton m_button_0;
	CButton m_button0;
	CButton m_button1;
	CButton m_button2;
	CButton m_button3;
	CButton m_button4;
	CButton m_button5;
	CButton m_button6;
	CButton m_button7;
	CButton m_button8;
	CButton m_button9;
	CButton m_buttonDivide;
	CButton m_buttonMultiply;
	CButton m_buttonMinus;
	CButton m_buttonPlus;
	CButton m_buttonEquals;
	CButton m_buttonPercentage;
	CButton m_buttonC;
	CButton m_buttonBack;
	CButton m_buttonPoint;
	CButton m_buttonTogglePositiveNegative;
	CEdit m_edit_result;
	afx_msg void OnBnClickedButton0();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButtonDivide();
	afx_msg void OnBnClickedButtonMultiply();
	afx_msg void OnBnClickedButtonMinus();
	afx_msg void OnBnClickedButtonPlus();
	afx_msg void OnBnClickedButtonEquals();
	afx_msg void OnBnClickedButtonNegativePositive();
	afx_msg void OnBnClickedButtonPoint();
	afx_msg void OnBnClickedButtonPercent();
	afx_msg void OnBnClickedButtonClear();
	afx_msg void OnBnClickedButtonBack();

private:
	CString m_result;
	CString m_history;
	CString str = _T("");
	bool ispreviousOperation = false;
	double leftExpression = 0;

	afx_msg void appendDigit(char digit);
public:
	CEdit m_resultCtl;
};
