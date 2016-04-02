#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPlainTextEdit>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent * event) Q_DECL_OVERRIDE;

private slots:
    void newFile();
    void open();
    bool save();
    bool saveAs();
    void about();
    void exitAll();
    void documentWasModified();
    void selectAll();
    void copyAll();
    void copyText();
    void pasteText();

private:
    void createActions();
    void createMenus();
    void createToolBars();
    void createStatusBar();
    void readSettings();
    void writeSettings();
    bool maybeSave();
    void loadFile(const QString &fileName);
    bool saveFile(const QString &fileName);
    void setCurrentFile(const QString &fileName);
    QString strippedName(const QString &fullFileName);

    QPlainTextEdit *textEdit;
    QString curFile;

    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *helpMenu;
    QToolBar *fileToolBar;
    QToolBar *editToolBar;

    // Items FileMenu
    QAction *newAct;
    QAction *openAct;
    QAction *saveAct;
    QAction *saveAsAct;
    QAction *exitAct;

    //Items EditMenu
    QAction *selectAllAct;
    QAction *copyAllAct;
    QAction *copyTextAct;
    QAction *pasteTextAct;

    //Items AboutMenu
    QAction *aboutAct;



};

#endif // MAINWINDOW_H
