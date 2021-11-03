
// CStaticTextDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "CStaticText.h"
#include "CStaticTextDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CCStaticTextDlg 对话框



CCStaticTextDlg::CCStaticTextDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CSTATICTEXT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCStaticTextDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TEXT, n_text);
	DDX_Control(pDX, IDC_IMG, n_img);
	DDX_Control(pDX, IDC_BUTTON3, n_btn);
}

BEGIN_MESSAGE_MAP(CCStaticTextDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CCStaticTextDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CCStaticTextDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CCStaticTextDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CCStaticTextDlg 消息处理程序

BOOL CCStaticTextDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	// 用 Static Text 显示图片

	// 设置静态控件窗口风格为位图居中显示
	n_img.ModifyStyle(0xf, SS_BITMAP | SS_CENTERIMAGE);

	// 通过路径获取 bitmap 句柄
#define HBMP(filepath,width,height)(HBITMAP)LoadImage(AfxGetInstanceHandle(),filepath,IMAGE_BITMAP,width,height,LR_LOADFROMFILE | LR_CREATEDIBSECTION)

	// 宽高设置 按照控件的大小去设置
	CRect rect;
	n_img.GetWindowRect(rect);

	// 静态控件设置 bmp
	n_img.SetBitmap(HBMP(TEXT("./1.bmp"), rect.Width(), rect.Height()));

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CCStaticTextDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CCStaticTextDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CCStaticTextDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


// 点击按钮改变文字内容
void CCStaticTextDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	// 设置文本内容
	n_text.SetWindowTextW(TEXT("PIECE"));
}

// 点击按钮获取文本内容
void CCStaticTextDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码

	CString str;
	n_text.GetWindowTextW(str);
	MessageBox(str);
}



void CCStaticTextDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	n_btn.EnableWindow(FALSE);
}
