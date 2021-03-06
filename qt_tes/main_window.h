#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
//#include <QAction>
//#include <QMenu>
//#include <QMenu>

#if 1
//QT_BEGIN_NAMESPACE
class QAction;
class QActionGroup;
class QMenu;
class QTextEdit;
class QTabWidget;
class QComboBox;
class QLineEdit;

#include <QGroupBox>
#include <QFile>
#include <QDomDocument>
#include <QTextEdit>


#include <QTabWidget>

//QT_END_NAMESPACE
#endif

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

const u8 MAX_CARD_NUM=8;
const int MAX_PERSION=4;

class MainWindow : public QMainWindow
{
  Q_OBJECT

  public:
    MainWindow();
    void create_form_groupbox();
    void backup_file();
    QTextEdit *text_edit_;


  private:
    QFile qf_;
    //QComboBox *players_[MAX_PERSION], *persion_[MAX_PERSION];
    QComboBox *players_, *persion_;
    QComboBox *card_[MAX_CARD_NUM];
    QComboBox *save_file_offset_;
    QLineEdit *cash_, *saving_, *point_, *position_, *direction_;
    QGroupBox *formGroupBox;
    QMenu *file_menu_, *edit_menu_, *help_menu_;
    QAction *open_file_, *save_file_, *save_as_;
    QAction *about_;
    QMenu *setting_menu_;
    QAction *change_font_, *backup_file_;
 
    QByteArray qba_;
    FILE *fs_;
    QString dirname_, basename_, file_name_, backup_fn_;
    QDomDocument dom_doc_;
    u32 persion_data_[4];

    void fill_data(int offset=0x4e10);
    int write_to_save_file(const QString &w_fn);
    void open_rich8_cfg();
    void parse_tes();

  protected:
    void closeEvent ( QCloseEvent * event );

  public slots:
    void open_file_slot();
    void save_file_slot();
    void save_as_slot();
    void change_player ( int index ) ;
    void change_save_file_offset ( int index );


  private slots:
    bool close();
    void change_font_slot();
    void backup_file_slot();
    void about_slot();
#if 0
    QAction *copy_, *paste_;
    QAction *change_bg_color_;
    QAction *set_encode_;
    QAction *big5_enc_, *utf8_enc_;
    QMenu *encoding_menu_;
    QActionGroup *input_enc_g_;
    QActionGroup *enc_g_;

    void switch_tab_slot(int tab_index);
    void close_tab_slot();
    void big5_enc();
    void utf8_enc();
    void copy_slot();
    void paste_slot();
    bool close();
    void change_bg_color_slot();
    void set_encode_slot();
    //virtual ~MainWindow();

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    //void change_font_slot();
    void newFile();
    void open();
    bool save();
    bool saveAs();
    void about();
    //void change_font_slot();
    void documentWasModified();

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

    QTextEdit *textEdit;
    QString curFile;

    QMenu *fileMenu;
    QMenu *editMenu;
    //QMenu *setting_menu_;
    QMenu *helpMenu;
    QToolBar *fileToolBar;
    QToolBar *editToolBar;
    QAction *newAct;
    QAction *openAct;
    QAction *saveAct;
    QAction *saveAsAct;
    QAction *exitAct;
    QAction *cutAct;
    QAction *copyAct;
    QAction *pasteAct;
    QAction *aboutAct;
    QAction *aboutQtAct;

    //QAction *change_font_;
#endif
};

#endif
