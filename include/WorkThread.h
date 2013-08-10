#ifndef WORKTHREAD_H
#define WORKTHREAD_H

#include <wx/thread.h>
#include "../LineStatisticsMain.h"

class WorkThread : public wxThread
{
    public:
        WorkThread(wxThreadKind tk,void (*pfun)()=0):wxThread(tk)
        {
            p=pfun;
        }
        virtual ExitCode Entry()
        {
            if(p)
            {
                p();
            }
            return 0;
        }
    protected:
    private:
        void (*p)();
};

#endif // WORKTHREAD_H
