
// Lab4Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "Lab4.h"
#include "Lab4Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CLab4Dlg dialog



CLab4Dlg::CLab4Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_LAB4_DIALOG, pParent)
	, Reducere(FALSE)
	, Pret(0)
	, Total(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLab4Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO, Zile);
	DDX_Check(pDX, IDC_REDUCERE, Reducere);
	DDX_Text(pDX, IDC_PRET, Pret);
	DDX_Text(pDX, IDC_EDIT2, Total);
	DDX_Control(pDX, IDC_TREE, ListaArbore);
}

BEGIN_MESSAGE_MAP(CLab4Dlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CALCULEAZA, &CLab4Dlg::OnBnClickedCalculeaza)
	ON_CBN_SELCHANGE(IDC_COMBO, &CLab4Dlg::OnCbnSelchangeCombo)
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE, &CLab4Dlg::OnTvnSelchangedTree)
END_MESSAGE_MAP()


// CLab4Dlg message handlers

BOOL CLab4Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	Zile.SetWindowTextW(_T("Număr zile"));

	HTREEITEM hProduse;

	hProduse = ListaArbore.InsertItem(L"Filme", TVI_ROOT);
	ListaArbore.InsertItem(L"Logan", hProduse);
	ListaArbore.InsertItem(L"Wonder Woman", hProduse);
	ListaArbore.InsertItem(L"Justice League", hProduse);
	ListaArbore.InsertItem(L"Guardians of the Galaxy Vol. 2", hProduse);
	ListaArbore.InsertItem(L"Star Wars: The Last Jedi", hProduse);
	ListaArbore.InsertItem(L"War for the Planet of the Apes", hProduse);
	ListaArbore.InsertItem(L"Beauty and the Beast", hProduse);

	ListaArbore.Expand(hProduse, TVM_EXPAND);

	hProduse = ListaArbore.InsertItem(L"Albume", TVI_ROOT);
	ListaArbore.InsertItem(L"The Dark Side of the Moon", hProduse);
	ListaArbore.InsertItem(L"Abbey Road", hProduse);
	ListaArbore.InsertItem(L"Nevermind", hProduse);
	ListaArbore.InsertItem(L"Led Zeppelin IV", hProduse);

	ListaArbore.Expand(hProduse, TVM_EXPAND);

	hProduse = ListaArbore.InsertItem(L"Seriale", TVI_ROOT);
	ListaArbore.InsertItem(L"Game of Thrones", hProduse);
	ListaArbore.InsertItem(L"Better Call Saul", hProduse);
	ListaArbore.InsertItem(L"Mr. Robot", hProduse);
	ListaArbore.InsertItem(L"Doctor Who", hProduse);
	ListaArbore.InsertItem(L"Narcos", hProduse);
	ListaArbore.InsertItem(L"Supernatural", hProduse);
	ListaArbore.InsertItem(L"Lucifer", hProduse);
	ListaArbore.InsertItem(L"The Flash", hProduse);
	ListaArbore.InsertItem(L"Silicon Valley", hProduse);

	ListaArbore.Expand(hProduse, TVM_EXPAND);

	NumarDVDSelectate = 0;

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CLab4Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CLab4Dlg::OnPaint()
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
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CLab4Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CLab4Dlg::OnBnClickedCalculeaza()
{
	// TODO: Add your control notification handler code here
	UpdateData();

	// Reducerea aferenta perioadei de inchiriere
	int Perioada = Zile.GetCurSel() + 1;
	double ReducerePerioada = 0;

	if (Perioada >= 5)
		if (Perioada == 14)
			ReducerePerioada = Perioada * 0.8;
		else
			ReducerePerioada = Perioada * 0.9;
	else
		ReducerePerioada = Perioada * 1;

	// Reducerea aferenta tipului de DVD
	double PretProduse = 0;

	UINT uCount = ListaArbore.GetVisibleCount();
	HTREEITEM hItem = ListaArbore.GetFirstVisibleItem();

	for (UINT i = 0; i < uCount; i++)
	{
		ASSERT(hItem != NULL);
		if (ListaArbore.GetCheck(hItem))
		{
			HTREEITEM Parent = ListaArbore.GetParentItem(hItem);

			if (Parent)
			{
				CString temp = ListaArbore.GetItemText(Parent);
				if (temp == "Filme")
					PretProduse += Pret * 0.95;
				if (temp == "Albume")
					PretProduse += Pret * 1;
				if (temp == "Seriale")
					PretProduse += Pret * 0.90;
			}

		}
		hItem = ListaArbore.GetNextVisibleItem(hItem);
	}

	Total = ReducerePerioada * PretProduse * (Reducere ? 0.75 : 1);

	UpdateData(FALSE);
}

void CLab4Dlg::OnCbnSelchangeCombo()
{
	// TODO: Add your control notification handler code here
}


void CLab4Dlg::OnTvnSelchangedTree(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
	
	UpdateData();

	HTREEITEM currSelect = pNMTreeView->itemNew.hItem;
	
	if (!isChecked(ListaArbore.GetItemText(currSelect)))
		ListaArbore.SetCheck(currSelect);
	else
		ListaArbore.SetCheck(currSelect, false);

	NumarDVDSelectate = GetCheckedNumber();

	CString selectate;
	
	selectate.Format(_T("%d"), NumarDVDSelectate);
	MessageBox(_T("Checkbox-uri selectate: " + selectate),
				_T("Elementele selectate."));
	
	UpdateData(FALSE);
}

int CLab4Dlg::GetCheckedNumber()
{
	UINT uCount = ListaArbore.GetVisibleCount();
	HTREEITEM hItem = ListaArbore.GetFirstVisibleItem();
	int CheckedNo = 0;

	for (UINT i = 0; i < uCount; i++)
	{
		ASSERT(hItem != NULL);
		if (ListaArbore.GetCheck(hItem))
		{
			CheckedNo++;
		}
		hItem = ListaArbore.GetNextVisibleItem(hItem);
	}

	return CheckedNo;
}

bool CLab4Dlg::isChecked(CString text)
{
	UINT uCount = ListaArbore.GetVisibleCount();
	HTREEITEM hItem = ListaArbore.GetFirstVisibleItem();

	for (UINT i = 0; i < uCount; i++)
	{
		ASSERT(hItem != NULL);
		if (ListaArbore.GetCheck(hItem) && ListaArbore.GetItemText(hItem) == text)
		{
			return true;
		}
		hItem = ListaArbore.GetNextVisibleItem(hItem);
	}

	return false;
}
