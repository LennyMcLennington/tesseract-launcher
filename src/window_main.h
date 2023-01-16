#ifndef WINDOWMAIN_H
#define WINDOWMAIN_H

#include <QMainWindow>
#include <QNetworkAccessManager>

#include "manifests/version_definition.h"

QT_BEGIN_NAMESPACE
namespace Ui { class WindowMain; }
QT_END_NAMESPACE

class WindowMain : public QMainWindow
{
    Q_OBJECT

public:
    WindowMain(QWidget *parent = nullptr);
    ~WindowMain();

private:
    Ui::WindowMain *ui;

    Tesseract::Launcher::VersionDefinition selectedVersion;
    QNetworkAccessManager qnam;
};
#endif // WINDOWMAIN_H
