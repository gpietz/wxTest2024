#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

class MyApp final: public wxApp {
public:
    bool OnInit() override;
};

class MyFrame final: public wxFrame {
public:
    MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
    void OnCustomActivate(wxActivateEvent& event);
};

// ----------------------------------------------------------------------------
// * MyApp *
// ----------------------------------------------------------------------------

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit() {
    if (!wxApp::OnInit()) {
        return false; // Base class initialization failed
    }

    auto *frame = new MyFrame("Hello World!", wxPoint(100, 100), wxSize(450,320));
    frame->Show(true);
    return true;
}

// ----------------------------------------------------------------------------
// * MyFrame *
// ----------------------------------------------------------------------------

MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
    : wxFrame(nullptr, wxID_ANY, title, pos, size) {
    // Bind the activate event
    Bind(wxEVT_ACTIVATE, &MyFrame::OnCustomActivate,this);
}

void MyFrame::OnCustomActivate(wxActivateEvent &event) {
    this->SetBackgroundColour(*wxBLACK);
    this->SetForegroundColour(*wxWHITE);
    this->Center();
    event.Skip();
}
