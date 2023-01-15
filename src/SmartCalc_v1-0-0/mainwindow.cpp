#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

// push text(task) in backend
void MainWindow::on_Button_res_clicked() {
  QString temp_text = ui->OutputLabel->text();
  QString needle = ui->line_x->text();
  QByteArray ba_x = needle.toLocal8Bit();
  char *haystack_ch = ba_x.data();
  if ((*haystack_ch) != '\0') {
    int mod = 0;
    if (isNumber(haystack_ch, &mod) == OK) {
      temp_text = replaceVarX(temp_text, needle);
    } else {
      QMessageBox::critical(this, "Invalid expression",
                            "Invalid input for variable X");
    }
  }
  QByteArray ba = temp_text.toLocal8Bit();
  char *text = ba.data();
  double double_result = 0.0;
  int status = entryPoint(text, &double_result, X);
  if (status == OK) {
    ui->OutputLabel->setText(QString::number(double_result, 'g', 15));
  } else {
    QMessageBox::critical(this, "Invalid expression", "Invalid input");
  }
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

void MainWindow::on_Button_del_clicked() { ui->OutputLabel->setText("0"); }

void MainWindow::on_Button_del_last_clicked() {
  QString temp_text = ui->OutputLabel->text();
  QByteArray ba = temp_text.toLocal8Bit();
  char *text = ba.data();
  int length = strlen(text);
  length--;
  if (isdigit(text[length]) != 0) {
    text[length] = '\0';
  } else if (text[length] == 'x') {
    text[length] = '\0';
  } else if (text[length] == '.') {
    text[length] = '\0';
  } else if (text[length] == '(') {
    if (text[length - 1] == 'n') {
      if (text[length - 4] == 'a') {
        chToTZ(text, length, 4);
      } else if ((text[length - 3] == 't') || (text[length - 3] == 's')) {
        chToTZ(text, length, 3);
      } else if (text[length - 2] == 'l') {
        chToTZ(text, length, 2);
      }
    } else if (text[length - 1] == 'g') {
      chToTZ(text, length, 3);
    } else if (text[length - 1] == 't') {
      chToTZ(text, length, 4);
    } else if (text[length - 1] == 's') {
      if (text[length - 4] == 'a') {
        chToTZ(text, length, 4);
      } else {
        chToTZ(text, length, 3);
      }
    } else {
      text[length] = '\0';
    }
  } else if (text[length] == 'd') {
    chToTZ(text, length, 2);
  } else if (text[length] == ')') {
    text[length] = '\0';
  } else if (text[length] == '+') {
    text[length] = '\0';
  } else if (text[length] == '-') {
    text[length] = '\0';
  } else if (text[length] == '*') {
    text[length] = '\0';
  } else if (text[length] == '/') {
    text[length] = '\0';
  } else if (text[length] == '^') {
    text[length] = '\0';
  }
  ui->OutputLabel->setText(QString(text));
  MainWindow::checkVoid();
}

void MainWindow::checkVoid() {
  if (ui->OutputLabel->text() == "") {
    ui->OutputLabel->setText("0");
  }
}

void MainWindow::on_Button_d_0_clicked() {
  if ((ui->OutputLabel->text()) != "0") {
    ui->OutputLabel->setText(ui->OutputLabel->text() + "0");
  } else {
    ui->OutputLabel->setText("0");
  }
}

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
  QString temp_text = ui->OutputLabel->text();
  QCharRef last = temp_text[temp_text.size() - 1];
  if ((ui->OutputLabel->text()) == "0") {
    ui->OutputLabel->setText("(");
  } else if (last != ')') {
    ui->OutputLabel->setText(ui->OutputLabel->text() + "(");
  }
}

void MainWindow::on_Button_CloseBr_clicked() {
  QString temp_text = ui->OutputLabel->text();
  QCharRef last = temp_text[temp_text.size() - 1];
  if ((ui->OutputLabel->text()) == "0") {
    ui->OutputLabel->setText(")");
  } else if (last != '(') {
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
  QString temp_text = ui->OutputLabel->text();
  QCharRef last = temp_text[temp_text.size() - 1];
  if ((checkOperation((ui->OutputLabel->text())) != 1) && (last != '(')) {
    ui->OutputLabel->setText(ui->OutputLabel->text() + "+");
  }
}

void MainWindow::on_Button_minus_clicked() {
  if (checkOperation((ui->OutputLabel->text())) != 1) {
    ui->OutputLabel->setText(ui->OutputLabel->text() + "-");
  }
}

void MainWindow::on_Button_mult_clicked() {
  QString temp_text = ui->OutputLabel->text();
  QCharRef last = temp_text[temp_text.size() - 1];
  if ((checkOperation((ui->OutputLabel->text())) != 1) && (last != '(')) {
    ui->OutputLabel->setText(ui->OutputLabel->text() + "*");
  }
}

void MainWindow::on_Button_div_clicked() {
  QString temp_text = ui->OutputLabel->text();
  QCharRef last = temp_text[temp_text.size() - 1];
  if ((checkOperation((ui->OutputLabel->text())) != 1) && (last != '(')) {
    ui->OutputLabel->setText(ui->OutputLabel->text() + "/");
  }
}

void MainWindow::on_Button_sq_clicked() {
  QString temp_text = ui->OutputLabel->text();
  QCharRef last = temp_text[temp_text.size() - 1];
  if ((checkOperation((ui->OutputLabel->text())) != 1) && (last != '(')) {
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

QString replaceVarX(QString str1, QString str2) {
  std::string haystack = str1.toStdString();
  std::string needle = str2.toStdString();
  std::string search = "x";
  for (size_t pos = 0;; pos += needle.length()) {
    pos = haystack.find(search, pos);
    if (pos == std::string::npos) break;
    haystack.erase(pos, search.length());
    haystack.insert(pos, needle);
  }
  str1 = QString::fromStdString(haystack);
  return str1;
}

void MainWindow::on_Button_Grath_clicked() {
  ui->widget->clearGraphs();
  QString temp_str = ui->OutputLabel->text();
  QByteArray ba = temp_str.toLocal8Bit();
  char *str = ba.data();

  double x_begin = ui->spinBoxXBegin->text().toDouble();
  double x_end = ui->spinBoxXEnd->text().toDouble();
  double y_begin = ui->spinBoxYBegin->text().toDouble();
  double y_end = ui->spinBoxYEnd->text().toDouble();

  ui->widget->xAxis->setRange(x_begin, x_end);
  ui->widget->yAxis->setRange(y_begin, y_end);

  h = 0.1;
  xBegin = x_begin;
  xEnd = x_end;

  N = (xBegin - xEnd) / h + 2;

  int status = OK;

  for (X = xBegin; X < xEnd && status == 0; X += h) {
    x.push_back(X);
    double res = 0.0;
    status = entryPoint(str, &res, X);
    y.push_back(res);
  }

  if (status == FAIL) {
    QMessageBox::critical(this, "Invalid expression", "Invalid input");
  } else {
    ui->widget->addGraph();
    ui->widget->graph(0)->addData(x, y);

    ui->widget->replot();
  }

  x.clear();
  y.clear();
}
