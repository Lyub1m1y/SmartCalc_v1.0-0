#ifndef SRC_MODEL_MAINWINDOW_H_
#define SRC_MODEL_MAINWINDOW_H_

#include <QDebug>
#include <QDesktopServices>
#include <QMainWindow>
#include <QMessageBox>
#include <QString>
#include <QUrl>
#include <QVector>
#include <string>

#include "ui_mainwindow.h"

extern "C" {
#include "../Model/smartcalc.h"
}

#define MONTH 30.4166667

QString replaceVarX(QString str1, QString str2);

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();
 private slots:

  void on_Help_clicked();

  void on_Button_res_clicked();

  void on_Button_d_0_clicked();

  void on_Button_del_clicked();

  void on_Button_d_1_clicked();

  void on_Button_d_2_clicked();

  void on_Button_d_3_clicked();

  void on_Button_d_4_clicked();

  void on_Button_d_5_clicked();

  void on_Button_d_6_clicked();

  void on_Button_d_7_clicked();

  void on_Button_d_8_clicked();

  void on_Button_d_9_clicked();

  void on_Button_X_clicked();

  void on_Button_OpenBr_clicked();

  void on_Button_CloseBr_clicked();

  void on_Button_dot_clicked();

  void on_Button_plus_clicked();

  void on_Button_minus_clicked();

  void on_Button_mult_clicked();

  void on_Button_div_clicked();

  void on_Button_sq_clicked();

  void on_Button_ln_clicked();

  void on_Button_sqrt_clicked();

  void on_Button_sin_clicked();

  void on_Button_cos_clicked();

  void on_Button_tan_clicked();

  void on_Button_atan_clicked();

  void on_Button_acos_clicked();

  void on_Button_asin_clicked();

  void on_Button_log_clicked();

  void on_Button_mod_clicked();

  void on_Button_del_last_clicked();

  void checkVoid();

  void on_Button_Grath_clicked();

  void on_count_credit_clicked();

 private:
  Ui::MainWindow *ui;
  double xBegin, xEnd, h, X = 0.0;
  int N;
  QVector<double> x, y;
};
#endif  // SRC_MODEL_MAINWINDOW_H_
