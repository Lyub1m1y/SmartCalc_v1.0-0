#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

QString replaceVarX(QString str1, QString str2) {
    size_t index = 0;
    std::string haystack = str1.toStdString();
    std::string needle = str2.toStdString();
    int needleLength = needle[needle.size() - 1];
    while (true) {
         index = haystack.find("x", index);
         if (index == std::string::npos) {
             break;
         }
         haystack.replace(index, needleLength, needle);
         index += needleLength;
    }
    str1 = QString::fromStdString(haystack);
    return str1;
}

// push text(task) in backend
void MainWindow::on_Button_res_clicked() {
  QString temp_text = ui->OutputLabel->text();
  QString needle = ui->line_x->text();
  QByteArray ba_x = needle.toLocal8Bit();
  char *haystack_ch = ba_x.data();
  if (haystack_ch != NULL) {
      if (isNumber(haystack_ch) == OK) {
          temp_text = replaceVarX(temp_text, needle);
      } else {
          QMessageBox::critical(this, "Invalid expression", "Invalid input for variable X");
      }
  }
  QByteArray ba = temp_text.toLocal8Bit();
  char *text = ba.data();
  double double_result = 0.0;
  if (entryPoint(text, &double_result) == 0) {
    ui->OutputLabel->setText(QString::number(double_result));
  } else {
      QMessageBox::critical(this, "Invalid expression", "Invalid input");
  }
//  ui->OutputLabel->setText(QString::number(double_result));
}

MainWindow::~MainWindow() { delete ui; }

int checkOperation(QString text) {
  int status = 0;
  QCharRef temp = text[text.size() - 1];
  if (temp == '+') {
    status = 1;
  }
  if (temp == '-') {
    status = 1;
  }
  if (temp == '*') {
    status = 1;
  }
  if (temp == '/') {
    status = 1;
  }
  if (temp == '^') {
    status = 1;
  }
  if (temp == '.') {
    status = 1;
  }
  if (text[text.size() - 1] == 'd') {
    if (text[text.size() - 2] == 'o') {
      if (text[text.size() - 3] == 'm') {
        status = 1;
      }
    }
  }
  return status;
}

void MainWindow::on_Help_clicked() {
  QDesktopServices::openUrl(QUrl("../dvi.html", QUrl::TolerantMode));
}

void MainWindow::on_Button_d_0_clicked() {
  if ((ui->OutputLabel->text()) != "0") {
    ui->OutputLabel->setText(ui->OutputLabel->text() + "0");
  } else {
    ui->OutputLabel->setText("0");
  }
}

void MainWindow::on_Button_del_clicked() { ui->OutputLabel->setText("0"); }

void MainWindow::on_Button_d_1_clicked() {
  if ((ui->OutputLabel->text()) == "0") {
    ui->OutputLabel->setText("1");
  } else {
    ui->OutputLabel->setText(ui->OutputLabel->text() + "1");
  }
}

void MainWindow::on_Button_d_2_clicked() {
  if ((ui->OutputLabel->text()) == "0") {
    ui->OutputLabel->setText("2");
  } else {
    ui->OutputLabel->setText(ui->OutputLabel->text() + "2");
  }
}

void MainWindow::on_Button_d_3_clicked() {
  if ((ui->OutputLabel->text()) == "0") {
    ui->OutputLabel->setText("3");
  } else {
    ui->OutputLabel->setText(ui->OutputLabel->text() + "3");
  }
}

void MainWindow::on_Button_d_4_clicked() {
  if ((ui->OutputLabel->text()) == "0") {
    ui->OutputLabel->setText("4");
  } else {
    ui->OutputLabel->setText(ui->OutputLabel->text() + "4");
  }
}

void MainWindow::on_Button_d_5_clicked() {
  if ((ui->OutputLabel->text()) == "0") {
    ui->OutputLabel->setText("5");
  } else {
    ui->OutputLabel->setText(ui->OutputLabel->text() + "5");
  }
}

void MainWindow::on_Button_d_6_clicked() {
  if ((ui->OutputLabel->text()) == "0") {
    ui->OutputLabel->setText("6");
  } else {
    ui->OutputLabel->setText(ui->OutputLabel->text() + "6");
  }
}

void MainWindow::on_Button_d_7_clicked() {
  if ((ui->OutputLabel->text()) == "0") {
    ui->OutputLabel->setText("7");
  } else {
    ui->OutputLabel->setText(ui->OutputLabel->text() + "7");
  }
}

void MainWindow::on_Button_d_8_clicked() {
  if ((ui->OutputLabel->text()) == "0") {
    ui->OutputLabel->setText("8");
  } else {
    ui->OutputLabel->setText(ui->OutputLabel->text() + "8");
  }
}

void MainWindow::on_Button_d_9_clicked() {
  if ((ui->OutputLabel->text()) == "0") {
    ui->OutputLabel->setText("9");
  } else {
    ui->OutputLabel->setText(ui->OutputLabel->text() + "9");
  }
}
void MainWindow::on_Button_X_clicked() {
  QString temp = ui->OutputLabel->text();
  if ((temp[temp.size() - 1] != "x")) {
    if ((temp == "0") || (temp == "x")) {
      ui->OutputLabel->setText("x");
    } else {
      ui->OutputLabel->setText(ui->OutputLabel->text() + "x");
    }
  }
}

void MainWindow::on_Button_OpenBr_clicked() {
  if ((ui->OutputLabel->text()) == "0") {
    ui->OutputLabel->setText("(");
  } else {
    ui->OutputLabel->setText(ui->OutputLabel->text() + "(");
  }
}

void MainWindow::on_Button_CloseBr_clicked() {
  if ((ui->OutputLabel->text()) == "0") {
    ui->OutputLabel->setText(")");
  } else {
    ui->OutputLabel->setText(ui->OutputLabel->text() + ")");
  }
}

void MainWindow::on_Button_dot_clicked() {
    QString temp_text = ui->OutputLabel->text();
    QCharRef last = temp_text[temp_text.size() - 1];
    if ((checkOperation(temp_text) != 1) && (last != '(') && (last != ')')) {
      ui->OutputLabel->setText(ui->OutputLabel->text() + ".");
    }
}

void MainWindow::on_Button_plus_clicked() {
  if (checkOperation((ui->OutputLabel->text())) != 1) {
    ui->OutputLabel->setText(ui->OutputLabel->text() + "+");
  }
}

void MainWindow::on_Button_minus_clicked() {
  if (checkOperation((ui->OutputLabel->text())) != 1) {
    ui->OutputLabel->setText(ui->OutputLabel->text() + "-");
  }
}

void MainWindow::on_Button_mult_clicked() {
  if (checkOperation((ui->OutputLabel->text())) != 1) {
    ui->OutputLabel->setText(ui->OutputLabel->text() + "*");
  }
}

void MainWindow::on_Button_div_clicked() {
  if (checkOperation((ui->OutputLabel->text())) != 1) {
    ui->OutputLabel->setText(ui->OutputLabel->text() + "/");
  }
}

void MainWindow::on_Button_sq_clicked() {
  if (checkOperation((ui->OutputLabel->text())) != 1) {
    ui->OutputLabel->setText(ui->OutputLabel->text() + "^");
  }
}

void MainWindow::on_Button_ln_clicked() {
  if ((ui->OutputLabel->text()) == "0") {
    ui->OutputLabel->setText("ln(");
  } else {
    ui->OutputLabel->setText(ui->OutputLabel->text() + "ln(");
  }
}

void MainWindow::on_Button_sqrt_clicked() {
  if ((ui->OutputLabel->text()) == "0") {
    ui->OutputLabel->setText("sqrt(");
  } else {
    ui->OutputLabel->setText(ui->OutputLabel->text() + "sqrt(");
  }
}

void MainWindow::on_Button_sin_clicked() {
  if ((ui->OutputLabel->text()) == "0") {
    ui->OutputLabel->setText("sin(");
  } else {
    ui->OutputLabel->setText(ui->OutputLabel->text() + "sin(");
  }
}

void MainWindow::on_Button_cos_clicked() {
  if ((ui->OutputLabel->text()) == "0") {
    ui->OutputLabel->setText("cos(");
  } else {
    ui->OutputLabel->setText(ui->OutputLabel->text() + "cos(");
  }
}

void MainWindow::on_Button_tan_clicked() {
  if ((ui->OutputLabel->text()) == "0") {
    ui->OutputLabel->setText("tan(");
  } else {
    ui->OutputLabel->setText(ui->OutputLabel->text() + "tan(");
  }
}

void MainWindow::on_Button_atan_clicked() {
  if ((ui->OutputLabel->text()) == "0") {
    ui->OutputLabel->setText("atan(");
  } else {
    ui->OutputLabel->setText(ui->OutputLabel->text() + "atan(");
  }
}

void MainWindow::on_Button_acos_clicked() {
  if ((ui->OutputLabel->text()) == "0") {
    ui->OutputLabel->setText("acos(");
  } else {
    ui->OutputLabel->setText(ui->OutputLabel->text() + "acos(");
  }
}

void MainWindow::on_Button_asin_clicked() {
  if ((ui->OutputLabel->text()) == "0") {
    ui->OutputLabel->setText("asin(");
  } else {
    ui->OutputLabel->setText(ui->OutputLabel->text() + "asin(");
  }
}

void MainWindow::on_Button_log_clicked() {
  if ((ui->OutputLabel->text()) == "0") {
    ui->OutputLabel->setText("log(");
  } else {
    ui->OutputLabel->setText(ui->OutputLabel->text() + "log(");
  }
}

void MainWindow::on_Button_mod_clicked() {
  if (checkOperation((ui->OutputLabel->text())) != 1) {
    ui->OutputLabel->setText(ui->OutputLabel->text() + "mod");
  }
}
