/***************************************************************
 * Name:      LineStatisticsMain.h
 * Purpose:   Defines Application Frame
 * Author:    Lupin Long (longxia102@gmail.com)
 * Created:   2013-04-22
 * Copyright: Lupin Long (http://www.cnzui.com)
 * License:
 **************************************************************/

#ifndef LINESTATISTICSMAIN_H
#define LINESTATISTICSMAIN_H

//(*Headers(LineStatisticsDialog)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/msgdlg.h>
#include <wx/button.h>
#include <wx/dirdlg.h>
#include <wx/dialog.h>
#include <wx/gauge.h>
//*)
#include <wx/msgdlg.h>
#include <wx/thread.h>
#include <wx/dir.h>
#include <wx/textfile.h>
#include <wx/filename.h>

class WorkThread;
class LineStatisticsDialog: public wxDialog
{
    public:
        wxString m_strFileExt;
        wxString m_strPath;
        int m_nFileNums;
        int m_nCodeLines;
        int m_nSpaceLines;
        int m_nRemLines;

        WorkThread *work;

    public:
        int CountProc();
        void CountFiles(const wxString &folder);   //统计总文件数
        void CountLines(const wxString &folder);   //统计代码行数
        void CountRems(const wxString &lines);    //统计注释行数
        void UpdateUI()
        {
            this->lbAll->SetLabel(wxString::Format("%d",m_nCodeLines));
            this->lbSpace->SetLabel(wxString::Format("%d",m_nSpaceLines));
            this->lbRem->SetLabel(wxString::Format("%d",m_nRemLines));
        }
        void ShowStatus(const wxString& statu)
        {
            if(statu.Length()>40)
            {
                this->lbStatu->SetLabel(statu.Mid(0,15)+"......"+statu.Mid(statu.Length()-15-1,15));
            }
            else
            {
                this->lbStatu->SetLabel(statu);
            }
        }


    public:
        LineStatisticsDialog(wxWindow* parent,wxWindowID id = -1);
        virtual ~LineStatisticsDialog();

    private:

        //(*Handlers(LineStatisticsDialog)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnbtnCountClick(wxCommandEvent& event);
        void OnbtnSelFileClick(wxCommandEvent& event);
        void OnInit(wxInitDialogEvent& event);
        //*)

        //(*Identifiers(LineStatisticsDialog)
        static const long ID_STATICTEXT1;
        static const long ID_STATICTEXT3;
        static const long ID_LBALL;
        static const long ID_STATICTEXT4;
        static const long ID_LBNOTE;
        static const long ID_STATICTEXT2;
        static const long ID_LBSPACE;
        static const long ID_STATICTEXT5;
        static const long ID_TEXTFILE;
        static const long ID_BTNSELFILE;
        static const long ID_TXTSTATU;
        static const long ID_PROGJOB;
        static const long ID_BTNCOUNT;
        static const long ID_MESSAGEDIALOG1;
        //*)

        //(*Declarations(LineStatisticsDialog)
        wxStaticText* lbSpace;
        wxStaticText* StaticText2;
        wxStaticText* StaticText6;
        wxButton* btnCount;
        wxButton* btnSelFile;
        wxTextCtrl* txtFile;
        wxGauge* progJob;
        wxStaticText* lbStatu;
        wxStaticText* StaticText1;
        wxStaticText* StaticText3;
        wxStaticText* StaticText5;
        wxDirDialog* DirDialog1;
        wxBoxSizer* BoxSizer1;
        wxStaticText* lbAll;
        wxMessageDialog* MessageDialog1;
        wxStaticText* StaticText4;
        wxStaticText* lbRem;
        //*)

        DECLARE_EVENT_TABLE()
};

typedef int (LineStatisticsDialog::*CallBackFun)();

class WorkThread : public wxThread
{
    public:
        wxWindow *parent;

    public:
        WorkThread(wxThreadKind tk,wxWindow *obj,CallBackFun pfun=0):wxThread(tk)
        {
            parent=obj;
            p=pfun;
        }
        virtual ExitCode Entry()
        {
            if(p)
            {
                ((LineStatisticsDialog*)parent->*p)();
            }
            return 0;
        }
    protected:
    private:
        CallBackFun p;
};
#endif // LINESTATISTICSMAIN_H
