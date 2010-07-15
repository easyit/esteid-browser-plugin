#ifndef ESTEID_WHITELISTDIALOG_H
#define ESTEID_WHITELISTDIALOG_H

#include <windows.h>
#include <commctrl.h>
#include <string>
#include <vector>

#include "Win/basedialog.h"

class PluginSettings;

class WhitelistDialog : public BaseDialog
{
public:
    WhitelistDialog(HINSTANCE hInst, PluginSettings &conf);
    virtual ~WhitelistDialog();

    // Functions for setting up data for displaying
    void addSites(const std::vector<std::string> & sv);
    void addDefaultSites(const std::vector<std::string> & sv);

    // Call this to retrieve modified whitelist
    std::vector<std::string> getWhitelist();

    void setEntryText(const std::string & site);

    bool doDialog();

protected:
    void insertItem(const std::wstring & name, bool editable);
    void insertItem(const std::string & name, bool editable);

    void storeItems();

    LRESULT on_initdialog(WPARAM wParam);
    LRESULT on_command(WPARAM wParam, LPARAM lParam);
    LRESULT on_notify(WPARAM wParam, LPARAM lParam);
    LRESULT on_message(UINT message, WPARAM wParam, LPARAM lParam);

private:
    HWND m_hList;
    HWND m_hEdit;
    std::vector<std::string> m_sites;
    std::vector<std::string> m_defaultSites;

    PluginSettings *m_conf;
};

#endif //ESTEID_WHITELISTDIALOG_H
