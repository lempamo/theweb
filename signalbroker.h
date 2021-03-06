#ifndef SIGNALBROKER_H
#define SIGNALBROKER_H

#include <QObject>
#include "cefheaders.h"
#include "cefhandler.h"

class SignalBroker : public QObject
{
    Q_OBJECT
public:
    explicit SignalBroker(QObject *parent = 0);

signals:
    void RenderProcessTerminated(Browser browser, CefRequestHandler::TerminationStatus status);
    void TitleChanged(Browser browser, const CefString& title);
    void AddressChange(Browser browser, CefRefPtr<CefFrame> frame, const CefString& url);
    void FullscreenModeChange(Browser browser, bool fullscreen);
    void JSDialog(CefRefPtr<CefBrowser> browser, const CefString &origin_url, CefHandler::JSDialogType dialog_type, const CefString &message_text, const CefString &default_prompt_text, CefRefPtr<CefJSDialogCallback> callback, bool &suppress_message);
    void LoadingStateChange(Browser browser, bool isLoading, bool canGoBack, bool canGoForward);
    void LoadError(Browser browser, CefRefPtr<CefFrame> frame, CefHandler::ErrorCode errorCode, const CefString& errorText, const CefString& failedUrl);
    void BeforeClose(Browser browser);
    void AuthCredentials(Browser browser, CefRefPtr<CefFrame> frame, bool isProxy, const CefString &host, int port, const CefString &realm, const CefString &scheme, CefRefPtr<CefAuthCallback> callback);
    void BeforeUnloadDialog(Browser browser, const CefString &message_text, bool is_reload, CefRefPtr<CefJSDialogCallback> callback);
    void BeforePopup(Browser browser, CefRefPtr<CefFrame> frame, const CefString &target_url, const CefString &target_frame_name, CefLifeSpanHandler::WindowOpenDisposition target_disposition, bool user_gesture, const CefPopupFeatures &popupFeatures, CefWindowInfo *windowInfo, CefBrowserSettings settings, bool *no_javascript_access);
    void CertificateError(Browser browser, cef_errorcode_t cert_error, const CefString &request_url, CefRefPtr<CefSSLInfo> ssl_info, CefRefPtr<CefRequestCallback> callback);
    void FaviconURLChange(Browser browser, std::vector<CefString> urls);
    void KeyEvent(CefRefPtr<CefBrowser> browser, const CefKeyEvent &event, XEvent *os_event);
    void ContextMenu(Browser browser, CefRefPtr<CefFrame> frame, CefRefPtr<CefContextMenuParams> params, CefRefPtr<CefMenuModel> model, CefRefPtr<CefRunContextMenuCallback> callback);
    void ContextMenuCommand(Browser browser, int command_id, CefRefPtr<CefContextMenuParams> params);
    void ProtocolExecution(Browser browser, const CefString& url, bool& allow_os_execution);
    void Tooltip(Browser browser, CefString& text);
    void ShowBrowser(Browser browser);
    void AskForNotification(Browser browser, CefString host);
    void MprisStateChanged(Browser browser, bool isOn);
    void MprisPlayingStateChanged(Browser browser, bool isPlaying);
    void BeforeDownload(Browser browser, CefRefPtr<CefDownloadItem> download_item, const CefString& suggested_name, CefRefPtr<CefBeforeDownloadCallback> callback);
    void NewDownload(Browser browser, CefRefPtr<CefDownloadItem> download_item);
    void DownloadUpdated(Browser browser, CefRefPtr<CefDownloadItem> download_item, CefRefPtr<CefDownloadItemCallback> callback);
    void OpenURLFromTab(Browser browser, CefRefPtr<CefFrame> frame, const CefString &target_url, CefLifeSpanHandler::WindowOpenDisposition target_disposition, bool user_gesture);
    void FileDialog(Browser browser, CefDialogHandler::FileDialogMode mode, const CefString &title, const CefString &default_file_path, const std::vector<CefString> &accept_filters, int selected_accept_filter, CefRefPtr<CefFileDialogCallback> callback);
    void PrintDialog(Browser browser, QPrinter* printer, bool has_selection, CefRefPtr<CefPrintDialogCallback> callback);
    void StatusMessage(Browser browser, const CefString& value);
    void ReloadSettings();

public slots:
};

#endif // SIGNALBROKER_H
