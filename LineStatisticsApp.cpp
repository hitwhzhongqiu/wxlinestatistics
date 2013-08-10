/***************************************************************
 * Name:      LineStatisticsApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Lupin Long (longxia102@gmail.com)
 * Created:   2013-04-22
 * Copyright: Lupin Long (http://www.cnzui.com)
 * License:
 **************************************************************/

#include "LineStatisticsApp.h"

//(*AppHeaders
#include "LineStatisticsMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(LineStatisticsApp);

bool LineStatisticsApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	LineStatisticsDialog Dlg(0);
    	SetTopWindow(&Dlg);
    	Dlg.ShowModal();
    	wxsOK = false;
    }
    //*)
    return wxsOK;

}
