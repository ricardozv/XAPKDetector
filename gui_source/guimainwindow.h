/* Copyright (c) 2020-2022 hors<horsicq@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#ifndef GUIMAINWINDOW_H
#define GUIMAINWINDOW_H

#include <QDragEnterEvent>
#include <QFileDialog>
#include <QMainWindow>
#include <QMimeData>
#include "../global.h"
#include "archive_widget.h"
#include "dialogabout.h"
#include "dialogoptions.h"
#include "dialogshortcuts.h"
#include "xoptions.h"

namespace Ui
{
class GuiMainWindow;
}

class GuiMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GuiMainWindow(QWidget *pParent=nullptr);
    ~GuiMainWindow() override;

private slots:
    void handleFile(QString sFileName);
    void on_pushButtonScan_clicked();
    void on_pushButtonExit_clicked();
    void on_pushButtonOpenFile_clicked();
    void on_pushButtonAbout_clicked();
    void on_pushButtonShortcuts_clicked();
    void on_pushButtonOptions_clicked();
    void adjustWindow();
    void on_pushButtonHex_clicked();
    void on_pushButtonStrings_clicked();
    void on_pushButtonHash_clicked();
    void on_pushButtonEntropy_clicked();
    void scanFile(QString sFileName);
    void on_pushButtonSignature_clicked();
    void on_pushButtonDEX_clicked();
    void on_pushButtonELF_clicked();
    void on_pushButtonManifestMF_clicked();
    void on_pushButtonAndroidManifest_clicked();
    void openFile(QString sRecordName,XBinary::FT fileType,bool bIsVirtual);
    void openFile();

private:
    void _handleList(QList<CreateViewModelProcess::RECORD> *pList);

protected:
    void dragEnterEvent(QDragEnterEvent *pEvent) override;
    void dragMoveEvent(QDragMoveEvent *pEvent) override;
    void dropEvent(QDropEvent *pEvent) override;

private:
    Ui::GuiMainWindow *ui;
    XOptions g_xOptions;
    XShortcuts g_xShortcuts;
    FW_DEF::OPTIONS g_fwOptions;
    QList<CreateViewModelProcess::RECORD> g_listDEX;
    QList<CreateViewModelProcess::RECORD> g_listELF;
//    QList<CreateViewModelProcess::RECORD> g_listAndroidXML;
    QList<QAction *> g_listActions;
};

#endif // GUIMAINWINDOW_H
