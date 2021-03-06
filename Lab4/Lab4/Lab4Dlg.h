
// Lab4Dlg.h : header file
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CLab4Dlg dialog
class CLab4Dlg : public CDialog
{
// Construction
public:
	CLab4Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LAB4_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	
	DECLARE_MESSAGE_MAP()

	CComboBox Zile;
	BOOL Reducere;
	long Pret;

	double Total;

	CTreeCtrl ListaArbore;
	int NumarDVDSelectate;

public:
	
	afx_msg void OnBnClickedCalculeaza();
	afx_msg void OnCbnSelchangeCombo();
	afx_msg void OnTvnSelchangedTree(NMHDR *pNMHDR, LRESULT *pResult);
	
	int GetCheckedNumber();
	bool isChecked(CString text);
};
