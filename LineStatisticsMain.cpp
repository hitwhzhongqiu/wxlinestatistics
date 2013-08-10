/***************************************************************
 * Name:      CalculatorMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Lupin Long (longxia102@gmail.com)
 * Created:   2013-04-12
 * Copyright: Lupin Long (http://www.cnzui.com)
 * License:
 **************************************************************/

#include "LineStatisticsMain.h"
//(*InternalHeaders(CalculatorDialog)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat
{
    short_f, long_f
};

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(LineStatisticsDialog)
const long LineStatisticsDialog::ID_STATICTEXT1 = wxNewId();
const long LineStatisticsDialog::ID_STATICTEXT3 = wxNewId();
const long LineStatisticsDialog::ID_LBALL = wxNewId();
const long LineStatisticsDialog::ID_STATICTEXT4 = wxNewId();
const long LineStatisticsDialog::ID_LBNOTE = wxNewId();
const long LineStatisticsDialog::ID_STATICTEXT2 = wxNewId();
const long LineStatisticsDialog::ID_LBSPACE = wxNewId();
const long LineStatisticsDialog::ID_STATICTEXT5 = wxNewId();
const long LineStatisticsDialog::ID_TEXTFILE = wxNewId();
const long LineStatisticsDialog::ID_BTNSELFILE = wxNewId();
const long LineStatisticsDialog::ID_TXTSTATU = wxNewId();
const long LineStatisticsDialog::ID_PROGJOB = wxNewId();
const long LineStatisticsDialog::ID_BTNCOUNT = wxNewId();
const long LineStatisticsDialog::ID_MESSAGEDIALOG1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(LineStatisticsDialog,wxDialog)
    //(*EventTable(LineStatisticsDialog)
    //*)
END_EVENT_TABLE()

LineStatisticsDialog::LineStatisticsDialog(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(LineStatisticsDialog)
    wxBoxSizer* BoxSizer4;
    wxBoxSizer* BoxSizer6;
    wxBoxSizer* BoxSizer5;
    wxBoxSizer* BoxSizer7;
    wxBoxSizer* BoxSizer8;
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer3;

    Create(parent, wxID_ANY, wxT("代码统计工具"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
    BoxSizer1 = new wxBoxSizer(wxVERTICAL);
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, wxT("代码类文档行数统计："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    BoxSizer2->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer2, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
    StaticText3 = new wxStaticText(this, ID_STATICTEXT3, wxT("总量："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    StaticText3->SetForegroundColour(wxColour(0,0,255));
    BoxSizer4->Add(StaticText3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    lbAll = new wxStaticText(this, ID_LBALL, wxT("0"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBALL"));
    lbAll->SetForegroundColour(wxColour(0,0,255));
    BoxSizer4->Add(lbAll, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer4, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
    StaticText4 = new wxStaticText(this, ID_STATICTEXT4, wxT("注释："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    StaticText4->SetForegroundColour(wxColour(0,128,0));
    BoxSizer5->Add(StaticText4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    lbRem = new wxStaticText(this, ID_LBNOTE, wxT("0"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBNOTE"));
    lbRem->SetForegroundColour(wxColour(0,128,0));
    BoxSizer5->Add(lbRem, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer5, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, wxT("空行："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    StaticText2->SetForegroundColour(wxColour(128,128,128));
    BoxSizer3->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    lbSpace = new wxStaticText(this, ID_LBSPACE, wxT("0"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBSPACE"));
    lbSpace->SetForegroundColour(wxColour(128,128,128));
    BoxSizer3->Add(lbSpace, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer3, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
    StaticText5 = new wxStaticText(this, ID_STATICTEXT5, wxT("项目目录："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    BoxSizer6->Add(StaticText5, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    txtFile = new wxTextCtrl(this, ID_TEXTFILE, wxEmptyString, wxDefaultPosition, wxSize(140,22), wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTFILE"));
    BoxSizer6->Add(txtFile, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    btnSelFile = new wxButton(this, ID_BTNSELFILE, wxT("..."), wxDefaultPosition, wxSize(30,24), 0, wxDefaultValidator, _T("ID_BTNSELFILE"));
    BoxSizer6->Add(btnSelFile, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer8 = new wxBoxSizer(wxVERTICAL);
    lbStatu = new wxStaticText(this, ID_TXTSTATU, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_TXTSTATU"));
    lbStatu->SetForegroundColour(wxColour(128,128,128));
    BoxSizer8->Add(lbStatu, 0, wxLEFT|wxRIGHT|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 10);
    progJob = new wxGauge(this, ID_PROGJOB, 100, wxDefaultPosition, wxSize(100,15), 0, wxDefaultValidator, _T("ID_PROGJOB"));
    BoxSizer8->Add(progJob, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer8, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer7 = new wxBoxSizer(wxHORIZONTAL);
    btnCount = new wxButton(this, ID_BTNCOUNT, wxT("执行统计"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BTNCOUNT"));
    BoxSizer7->Add(btnCount, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer7, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(BoxSizer1);
    MessageDialog1 = new wxMessageDialog(this, wxEmptyString, wxT("Message"), wxOK|wxCANCEL, wxDefaultPosition);
    DirDialog1 = new wxDirDialog(this, wxT("Select directory"), wxEmptyString, wxDD_DEFAULT_STYLE, wxDefaultPosition, wxDefaultSize, _T("wxDirDialog"));
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);
    Center();

    Connect(ID_BTNSELFILE,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&LineStatisticsDialog::OnbtnSelFileClick);
    Connect(ID_BTNCOUNT,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&LineStatisticsDialog::OnbtnCountClick);
    Connect(wxID_ANY,wxEVT_INIT_DIALOG,(wxObjectEventFunction)&LineStatisticsDialog::OnInit);
    //*)
}

LineStatisticsDialog::~LineStatisticsDialog()
{
    //(*Destroy(LineStatisticsDialog)
    //*)
}

void LineStatisticsDialog::OnInit(wxInitDialogEvent& event)
{
    m_strFileExt=wxT("*.h|*.c|*.cpp|*.rc");
    this->m_nFileNums=0;
    this->m_nCodeLines=0;
    this->m_nRemLines=0;
    this->m_nSpaceLines=0;
    this->work=NULL;
}

void LineStatisticsDialog::OnQuit(wxCommandEvent& event)
{
    if(work!=NULL)
    {
        work->Delete();
        delete work;
        work=NULL;
    }
}

void LineStatisticsDialog::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}


int LineStatisticsDialog::CountProc()
{
    CountFiles(m_strPath);

    this->progJob->SetRange(m_nFileNums);

    CountLines(m_strPath);
    return 0;
}

void LineStatisticsDialog::OnbtnCountClick(wxCommandEvent& event)
{
    if(this->m_strPath!=wxEmptyString)
    {
        this->m_nFileNums=0;
        this->m_nCodeLines=0;
        this->m_nRemLines=0;
        this->m_nSpaceLines=0;
        this->progJob->SetValue(0);
        UpdateUI();


        if(work!=NULL)
        {
            work->Delete();
        }
        work=new WorkThread(wxTHREAD_JOINABLE,this,&LineStatisticsDialog::CountProc);
        if ( work->Create() != wxTHREAD_NO_ERROR )
        {
            wxMessageBox(wxT("创建进程时发生系统错误!"));
        }
        else
        {
            if ( work->Run() != wxTHREAD_NO_ERROR)
                wxMessageBox(wxT("启动进程时发生系统错误!"));
        }
    }
    else
    {
        wxMessageBox(wxT("请先指定项目目录！"), wxT("警告"));
    }
}

void LineStatisticsDialog::OnbtnSelFileClick(wxCommandEvent& event)
{
    if(DirDialog1->ShowModal()==wxID_OK)
    {
        this->m_strPath=DirDialog1->GetPath();
        this->txtFile->SetValue(this->m_strPath);
    }
}

void LineStatisticsDialog::CountFiles(const wxString &folder)
{
    if(!::wxDirExists(folder))
    {
        return;
    }
    else
    {
        wxDir dir(folder);
        if(!dir.IsOpened())
            return;

        //文件遍历
        wxArrayString files;
        dir.GetAllFiles(folder,&files,wxEmptyString,wxDIR_FILES|wxDIR_HIDDEN);
        m_nFileNums+=files.Count();
        files.Clear(); //free memory

        //子目录遍历
        if(dir.HasSubDirs())
        {
            wxString subdir;
            bool result= dir.GetFirst(&subdir,wxEmptyString,wxDIR_DIRS|wxDIR_HIDDEN);
            while(result)
            {
                CountFiles(folder + "\\" + subdir);
                result=dir.GetNext(&subdir);
            }
        }
    }
}

void LineStatisticsDialog::CountLines(const wxString &folder)
{
    if(!::wxDirExists(folder))
    {
        return;
    }
    else
    {
        bool result=false;

        wxDir dir(folder);
        if(!dir.IsOpened())
            return;

        //文件遍历
        wxString filename;
        result = dir.GetFirst(&filename,wxEmptyString,wxDIR_FILES|wxDIR_HIDDEN);
        while(result)
        {
            bool findError=false;

            wxString filefullpath=folder + "\\" + filename;
            ShowStatus(filefullpath);

            wxTextFile fl(filefullpath);
            //过滤不须统计的扩展名
            wxFileName flname(filefullpath);
            if(m_strFileExt.Find("*."+flname.GetExt())==wxNOT_FOUND)
            {
                findError=true;
            }
            else
            {
                if(!fl.Open())
                {
                    findError=true;
                }
            }

            //过滤不合法的文件
            if(findError)
            {
                result=dir.GetNext(&filename);
                this->progJob->SetValue(this->progJob->GetValue()+1);
                continue;
            }

            wxString linecontent=fl.GetFirstLine();
            while(!fl.Eof())
            {
                m_nCodeLines++;
                if(linecontent==wxEmptyString || linecontent.Trim()==wxT(""))
                {
                    m_nSpaceLines++;
                }
                else if(linecontent.Trim().Mid(0,2)==wxT("//"))
                {
                    m_nRemLines++;
                }
                linecontent=fl.GetNextLine();

                UpdateUI();
            }

            fl.Close();

            result=dir.GetNext(&filename);
            this->progJob->SetValue(this->progJob->GetValue()+1);
        }

        //子目录遍历
        if(dir.HasSubDirs())
        {
            wxString subdir;
            result= dir.GetFirst(&subdir,wxEmptyString,wxDIR_DIRS|wxDIR_HIDDEN);
            while(result)
            {
                wxString dirfullpath=folder + "\\" + subdir;
                ShowStatus(dirfullpath);

                CountLines(dirfullpath);
                result=dir.GetNext(&subdir);
            }
        }
    }
}

void LineStatisticsDialog::CountRems(const wxString &lines)
{

}
