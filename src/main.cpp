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

private:
    bool m_activated = false;

    void SetupMainMenu();
    void OnExit(wxCommandEvent& event);
    void OnNotImplemented(wxCommandEvent& event);
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
    if (!m_activated) {
        m_activated = true;
        this->SetBackgroundColour(*wxBLACK);
        this->SetForegroundColour(*wxWHITE);
        this->Center();
        SetupMainMenu();
    }
    event.Skip();
}

void MyFrame::SetupMainMenu() {
    auto *fileMenu = new wxMenu();
    fileMenu->Append(wxID_NEW);
    fileMenu->Append(wxID_OPEN);
    fileMenu->Append(wxID_SEPARATOR);
    fileMenu->Append(wxID_EXIT);

    auto *menuBar = new wxMenuBar();
    menuBar->Append(fileMenu, "File");

    SetMenuBar(menuBar);
    Bind(wxEVT_MENU, &MyFrame::OnNotImplemented, this,  wxID_NEW);
    Bind(wxEVT_MENU, &MyFrame::OnNotImplemented, this, wxID_OPEN);
    Bind(wxEVT_MENU, &MyFrame::OnExit, this, wxID_EXIT);
}

void MyFrame::OnExit(wxCommandEvent& event) {
    Close(true);
}

void MyFrame::OnNotImplemented(wxCommandEvent& event) {
    wxString message = "Not implemented yet!";
    wxString caption = "Confidential Information";
    wxMessageBox(message, caption, wxOK |wxICON_INFORMATION, this);
}
