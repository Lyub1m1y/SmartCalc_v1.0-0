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
  int status = entryPoint(text, &double_result);
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
  QString text = ui->OutputLabel->text();
  int last = MainWindow::last_button;
  if (last == NUMBER) {
    text.chop(1);
  } else if (last == PLUS) {
    text.chop(1);
  } else if (last == MINUS) {
    text.chop(1);
  } else if (last == MUL) {
    text.chop(1);
  } else if (last == DIV) {
    text.chop(1);
  } else if (last == POW) {
    text.chop(1);
  } else if (last == MOD) {
    text.chop(3);
  } else if (last == OPENBRACKET) {
    text.chop(1);
  } else if (last == CLOSEBRACKET) {
    text.chop(1);
  } else if (last == LN) {
    text.chop(3);
  } else if (last == SQRT) {
    text.chop(5);
  } else if (last == SIN) {
    text.chop(4);
  } else if (last == COS) {
    text.chop(4);
  } else if (last == TAN) {
    text.chop(4);
  } else if (last == LOG) {
    text.chop(4);
  } else if (last == ASIN) {
    text.chop(5);
  } else if (last == ACOS) {
    text.chop(5);
  } else if (last == ATAN) {
    text.chop(5);
  } else if (last == DOT) {
    text.chop(1);
  } else if (last == X) {
    text.chop(1);
  }
  ui->OutputLabel->setText(text);
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
  MainWindow::last_button = NUMBER;
}

void MainWindow::on_Button_d_1_clicked() {
  if ((ui->OutputLabel->text()) == "0") {
    ui->OutputLabel->setText("1");
  } else {
    ui->OutputLabel->setText(ui->OutputLabel->text() + "1");
  }
  MainWindow::last_button = NUMBER;
}

void MainWindow::on_Button_d_2_clicked() {
  if ((ui->OutputLabel->text()) == "0") {
    ui->OutputLabel->setText("2");
  } else {
    ui->OutputLabel->setText(ui->OutputLabel->text() + "2");
  }
  MainWindow::last_button = NUMBER;
}

void MainWindow::on_Button_d_3_clicked() {
  if ((ui->OutputLabel->text()) == "0") {
    ui->OutputLabel->setText("3");
  } else {
    ui->OutputLabel->setText(ui->OutputLabel->text() + "3");
  }
  MainWindow::last_button = NUMBER;
}

void MainWindow::on_Button_d_4_clicked() {
  if ((ui->OutputLabel->text()) == "0") {
    ui->OutputLabel->setText("4");
  } else {
    ui->OutputLabel->setText(ui->OutputLabel->text() + "4");
  }
  MainWindow::last_button = NUMBER;
}

void MainWindow::on_Button_d_5_clicked() {
  if ((ui->OutputLabel->text()) == "0") {
    ui->OutputLabel->setText("5");
  } else {
    ui->OutputLabel->setText(ui->OutputLabel->text() + "5");
  }
  MainWindow::last_button = NUMBER;
}

void MainWindow::on_Button_d_6_clicked() {
  if ((ui->OutputLabel->text()) == "0") {
    ui->OutputLabel->setText("6");
  } else {
    ui->OutputLabel->setText(ui->OutputLabel->text() + "6");
  }
  MainWindow::last_button = NUMBER;
}

void MainWindow::on_Button_d_7_clicked() {
  if ((ui->OutputLabel->text()) == "0") {
    ui->OutputLabel->setText("7");
  } else {
    ui->OutputLabel->setText(ui->OutputLabel->text() + "7");
  }
  MainWindow::last_button = NUMBER;
}

void MainWindow::on_Button_d_8_clicked() {
  if ((ui->OutputLabel->text()) == "0") {
    ui->OutputLabel->setText("8");
  } else {
    ui->OutputLabel->setText(ui->OutputLabel->text() + "8");
  }
  MainWindow::last_button = NUMBER;
}

void MainWindow::on_Button_d_9_clicked() {
  if ((ui->OutputLabel->text()) == "0") {
    ui->OutputLabel->setText("9");
  } else {
    ui->OutputLabel->setText(ui->OutputLabel->text() + "9");
  }
  MainWindow::last_button = NUMBER;
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
  MainWindow::last_button = X;
}

void MainWindow::on_Button_OpenBr_clicked() {
  QString temp_text = ui->OutputLabel->text();
  QCharRef last = temp_text[temp_text.size() - 1];
  if ((ui->OutputLabel->text()) == "0") {
    ui->OutputLabel->setText("(");
  } else if (last != ')') {
    ui->OutputLabel->setText(ui->OutputLabel->text() + "(");
  }
  MainWindow::last_button = OPENBRACKET;
}

void MainWindow::on_Button_CloseBr_clicked() {
  QString temp_text = ui->OutputLabel->text();
  QCharRef last = temp_text[temp_text.size() - 1];
  if ((ui->OutputLabel->text()) == "0") {
    ui->OutputLabel->setText(")");
  } else if (last != '(') {
    ui->OutputLabel->setText(ui->OutputLabel->text() + ")");
  }
  MainWindow::last_button = CLOSEBRACKET;
}

void MainWindow::on_Button_dot_clicked() {
  QString temp_text = ui->OutputLabel->text();
  QCharRef last = temp_text[temp_text.size() - 1];
  if ((checkOperation(temp_text) != 1) && (last != '(') && (last != ')')) {
    ui->OutputLabel->setText(ui->OutputLabel->text() + ".");
  }
  MainWindow::last_button = DOT;
}

void MainWindow::on_Button_plus_clicked() {
  QString temp_text = ui->OutputLabel->text();
  QCharRef last = temp_text[temp_text.size() - 1];
  if ((checkOperation((ui->OutputLabel->text())) != 1) && (last != '(')) {
    ui->OutputLabel->setText(ui->OutputLabel->text() + "+");
  }
  MainWindow::last_button = PLUS;
}

void MainWindow::on_Button_minus_clicked() {
  if (checkOperation((ui->OutputLabel->text())) != 1) {
    ui->OutputLabel->setText(ui->OutputLabel->text() + "-");
  }
  MainWindow::last_button = MINUS;
}

void MainWindow::on_Button_mult_clicked() {
  QString temp_text = ui->OutputLabel->text();
  QCharRef last = temp_text[temp_text.size() - 1];
  if ((checkOperation((ui->OutputLabel->text())) != 1) && (last != '(')) {
    ui->OutputLabel->setText(ui->OutputLabel->text() + "*");
  }
  MainWindow::last_button = MUL;
}

void MainWindow::on_Button_div_clicked() {
  QString temp_text = ui->OutputLabel->text();
  QCharRef last = temp_text[temp_text.size() - 1];
  if ((checkOperation((ui->OutputLabel->text())) != 1) && (last != '(')) {
    ui->OutputLabel->setText(ui->OutputLabel->text() + "/");
  }
  MainWindow::last_button = DIV;
}

void MainWindow::on_Button_sq_clicked() {
  QString temp_text = ui->OutputLabel->text();
  QCharRef last = temp_text[temp_text.size() - 1];
  if ((checkOperation((ui->OutputLabel->text())) != 1) && (last != '(')) {
    ui->OutputLabel->setText(ui->OutputLabel->text() + "^");
  }
  MainWindow::last_button = POW;
}

void MainWindow::on_Button_ln_clicked() {
  if ((ui->OutputLabel->text()) == "0") {
    ui->OutputLabel->setText("ln(");
  } else {
    ui->OutputLabel->setText(ui->OutputLabel->text() + "ln(");
  }
  MainWindow::last_button = LN;
}

void MainWindow::on_Button_sqrt_clicked() {
  if ((ui->OutputLabel->text()) == "0") {
    ui->OutputLabel->setText("sqrt(");
  } else {
    ui->OutputLabel->setText(ui->OutputLabel->text() + "sqrt(");
  }
  MainWindow::last_button = SQRT;
}

void MainWindow::on_Button_sin_clicked() {
  if ((ui->OutputLabel->text()) == "0") {
    ui->OutputLabel->setText("sin(");
  } else {
    ui->OutputLabel->setText(ui->OutputLabel->text() + "sin(");
  }
  MainWindow::last_button = SIN;
}

void MainWindow::on_Button_cos_clicked() {
  if ((ui->OutputLabel->text()) == "0") {
    ui->OutputLabel->setText("cos(");
  } else {
    ui->OutputLabel->setText(ui->OutputLabel->text() + "cos(");
  }
  MainWindow::last_button = COS;
}

void MainWindow::on_Button_tan_clicked() {
  if ((ui->OutputLabel->text()) == "0") {
    ui->OutputLabel->setText("tan(");
  } else {
    ui->OutputLabel->setText(ui->OutputLabel->text() + "tan(");
  }
  MainWindow::last_button = TAN;
}

void MainWindow::on_Button_atan_clicked() {
  if ((ui->OutputLabel->text()) == "0") {
    ui->OutputLabel->setText("atan(");
  } else {
    ui->OutputLabel->setText(ui->OutputLabel->text() + "atan(");
  }
  MainWindow::last_button = ATAN;
}

void MainWindow::on_Button_acos_clicked() {
  if ((ui->OutputLabel->text()) == "0") {
    ui->OutputLabel->setText("acos(");
  } else {
    ui->OutputLabel->setText(ui->OutputLabel->text() + "acos(");
  }
  MainWindow::last_button = ACOS;
}

void MainWindow::on_Button_asin_clicked() {
  if ((ui->OutputLabel->text()) == "0") {
    ui->OutputLabel->setText("asin(");
  } else {
    ui->OutputLabel->setText(ui->OutputLabel->text() + "asin(");
  }
  MainWindow::last_button = ASIN;
}

void MainWindow::on_Button_log_clicked() {
  if ((ui->OutputLabel->text()) == "0") {
    ui->OutputLabel->setText("log(");
  } else {
    ui->OutputLabel->setText(ui->OutputLabel->text() + "log(");
  }
  MainWindow::last_button = LOG;
}

void MainWindow::on_Button_mod_clicked() {
  if (checkOperation((ui->OutputLabel->text())) != 1) {
    ui->OutputLabel->setText(ui->OutputLabel->text() + "mod");
  }
  MainWindow::last_button = MOD;
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
