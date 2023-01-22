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
    if (isNumber(haystack_ch) == OK) {
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
  QChar temp = text[text.size() - 1];
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
  QDesktopServices::openUrl(QUrl("Help/index.html", QUrl::TolerantMode));
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
  QByteArray ba = temp.toLocal8Bit();
  char *str = ba.data();
  char last = str[strlen(str)];
  if ((last != 'x')) {
    if ((temp == "0") || (temp == "x")) {
      ui->OutputLabel->setText("x");
    } else {
      ui->OutputLabel->setText(ui->OutputLabel->text() + "x");
    }
  }
}

void MainWindow::on_Button_OpenBr_clicked() {
  QString temp_text = ui->OutputLabel->text();
  QChar last = temp_text[temp_text.size() - 1];
  if ((ui->OutputLabel->text()) == "0") {
    ui->OutputLabel->setText("(");
  } else if (last != ')') {
    ui->OutputLabel->setText(ui->OutputLabel->text() + "(");
  }
}

void MainWindow::on_Button_CloseBr_clicked() {
  QString temp_text = ui->OutputLabel->text();
  QChar last = temp_text[temp_text.size() - 1];
  if ((ui->OutputLabel->text()) == "0") {
    ui->OutputLabel->setText(")");
  } else if (last != '(') {
    ui->OutputLabel->setText(ui->OutputLabel->text() + ")");
  }
}

void MainWindow::on_Button_dot_clicked() {
  QString temp_text = ui->OutputLabel->text();
  QChar last = temp_text[temp_text.size() - 1];
  if ((checkOperation(temp_text) != 1) && (last != '(') && (last != ')')) {
    ui->OutputLabel->setText(ui->OutputLabel->text() + ".");
  }
}

void MainWindow::on_Button_plus_clicked() {
  QString temp_text = ui->OutputLabel->text();
  QChar last = temp_text[temp_text.size() - 1];
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
  QChar last = temp_text[temp_text.size() - 1];
  if ((checkOperation((ui->OutputLabel->text())) != 1) && (last != '(')) {
    ui->OutputLabel->setText(ui->OutputLabel->text() + "*");
  }
}

void MainWindow::on_Button_div_clicked() {
  QString temp_text = ui->OutputLabel->text();
  QChar last = temp_text[temp_text.size() - 1];
  if ((checkOperation((ui->OutputLabel->text())) != 1) && (last != '(')) {
    ui->OutputLabel->setText(ui->OutputLabel->text() + "/");
  }
}

void MainWindow::on_Button_sq_clicked() {
  QString temp_text = ui->OutputLabel->text();
  QChar last = temp_text[temp_text.size() - 1];
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

void MainWindow::on_count_credit_clicked() {
  QString temp_text_1 = ui->edit_sum_credit->text();
  QString temp_text_2 = ui->edit_term_credit->text();
  QString temp_text_3 = ui->edit_interest_rate->text();
  QByteArray ba_1 = temp_text_1.toLocal8Bit();
  QByteArray ba_2 = temp_text_2.toLocal8Bit();
  QByteArray ba_3 = temp_text_3.toLocal8Bit();
  char *text_1 = ba_1.data();
  char *text_2 = ba_2.data();
  char *text_3 = ba_3.data();

  int status_valid = FAIL;
  if (((*text_1) != '\0') && ((*text_2) != '\0') && ((*text_3) != '\0')) {
    if ((isNumber(text_1) == OK) && (isNumber(text_2) == OK) &&
        (isNumber(text_3) == OK)) {
      status_valid = OK;
    } else {
      QMessageBox::critical(this, "Invalid expression", "Invalid input");
    }
  }

  if (status_valid == OK) {
    if ((ui->radioButton_diff->isChecked()) ||
        (ui->radioButton_ann->isChecked())) {
      double term = ui->edit_term_credit->text().toDouble();
      double payment = 0, total_pay = 0;
      double sum_credit = ui->edit_sum_credit->text().toDouble();
      double sum_interest = sum_credit;
      QString str_first_month_pay;

      for (int i = 1; i <= term; i++) {
        double interes_rate = ui->edit_interest_rate->text().toDouble();
        QString month_pay;
        if (ui->radioButton_diff->isChecked()) {
          payment = sum_credit / term +
                    sum_interest * interes_rate * MONTH / 365 / 100;
          total_pay += payment;
          sum_interest = sum_credit - i * sum_credit / term;
          month_pay = QString::number(payment, 'f', 2);
          if (i == 1) {
            str_first_month_pay = month_pay;
          }
          month_pay = str_first_month_pay + "..." + month_pay;
        } else if (ui->radioButton_ann->isChecked()) {
          i = term;
          double prStavka = interes_rate / 12 / 100;
          payment = sum_credit * (prStavka * pow(1 + prStavka, term) /
                                  (pow(1 + prStavka, term) - 1));
          total_pay = payment * term;
          month_pay = QString::number(payment, 'f', 2);
        }
        ui->output_mounthly_payment_credit->setText(month_pay);
      }
      double overpayment = total_pay - sum_credit;
      QString str_total_pay = QString::number(total_pay, 'f', 2);
      QString str_overpayment = QString::number(overpayment, 'f', 2);

      ui->output_total_payout_credit->setText(str_total_pay);
      ui->output_overpayment_credit->setText(str_overpayment);
    } else {
      QMessageBox::critical(this, "Invalid expression",
                            "Please select the type (annuity/differentiated)");
    }
  }
}

void MainWindow::on_lineEdit_dep_editingFinished() {
  ui->edit_sum_deposit->setValidator(new QIntValidator(0, 2000000000, this));
  ui->edit_term_deposit->setValidator(new QIntValidator(0, 2000000000, this));
  ui->edit_interest_rate_deposit->setValidator(
      new QDoubleValidator(0, 0, 5, this));
  ui->edit_key_rate_deposit->setValidator(new QDoubleValidator(0, 0, 5, this));
  ui->edit_tax_rate->setValidator(new QDoubleValidator(0, 0, 5, this));
  ui->lineEdit_replenish->setValidator(new QDoubleValidator(0, 0, 5, this));
}

void MainWindow::on_pushButton_2_clicked() {
  ui->edit_sum_deposit->clear();
  ui->edit_term_deposit->clear();
  ui->edit_interest_rate_deposit->clear();
  ui->edit_key_rate_deposit->clear();
  ui->edit_tax_rate->clear();
  ui->output_sum_interest->clear();
  ui->output_accrued_interest->clear();
  ui->output_sum_tax->clear();
  ui->lineEdit_replenish->clear();
}

void MainWindow::on_pushButton_clicked() {
  deposit_t newDeposit;
  newDeposit.money = ui->edit_sum_deposit->text().toInt();
  newDeposit.period = ui->edit_term_deposit->text().toInt();
  newDeposit.capitalisation = ui->box_capitalisation->currentText();
  newDeposit.payout = ui->box_payout->currentText();
  newDeposit.replenishment = ui->box_replenishment->currentText();
  if (ui->lineEdit_replenish->isVisible()) {
  }

  newDeposit.percent = 0;
  newDeposit.deposit = newDeposit.money;
  newDeposit.tax = 0;

  if (newDeposit.capitalisation == "Нет") {
    no_capitalisation(&newDeposit);
  } else {
    capitalisation(&newDeposit);
  }

  ui->output_sum_interest->setText(QString::number(newDeposit.deposit));
  ui->output_accrued_interest->setText(QString::number(newDeposit.percent));
  ui->output_sum_tax->setText(QString::number(newDeposit.tax));
}

void MainWindow::capitalisation(deposit_t *dep) {
  int capFrequency = combo_box_pars(dep->capitalisation);

  int addFrequency = 0;
  if (dep->replenishment != "Нет") {
    addFrequency = combo_box_pars(dep->replenishment);
  }
  for (int i = capFrequency; i <= dep->period; i += capFrequency) {
    if (dep->replenishment != "Нет" && i >= addFrequency) {
      dep->deposit += dep->replenish;
    }
    dep->deposit += procent_calc(dep->deposit, dep->rate, capFrequency);
  }
  dep->percent = dep->deposit - dep->money;
}

void MainWindow::no_capitalisation(deposit_t *dep) {
  dep->percent = procent_calc(dep->money, dep->rate, dep->period);
  dep->deposit = dep->money + dep->percent;
  if (dep->replenishment != "Нет") {
    replenish_calc_noCap(dep);
  }
  if (dep->rate > dep->key_rate) {
    tax_calculate(dep);
  }
}

void MainWindow::tax_calculate(deposit_t *dep) {
  double tax_dif = 0;
  tax_dif = procent_calc(dep->money, dep->key_rate, dep->period);
  dep->tax = dep->tax_kind / 100.0 * (dep->percent - tax_dif);
  dep->percent -= dep->tax;
  dep->deposit -= dep->tax;
}

void MainWindow::replenish_calc_noCap(deposit_t *dep) {
  int addFrequency = combo_box_pars(dep->replenishment);
  ;
  double added_percent = 0;
  int dop_invest = 0;
  for (int i = addFrequency; i < dep->period; i += addFrequency) {
    dop_invest += dep->replenish;
    added_percent += procent_calc(dep->replenish, dep->rate, i);
  }
  dep->percent += added_percent;
  dep->deposit += added_percent + dop_invest;
}

double MainWindow::procent_calc(int money, double rate, int period) {
  return money * rate / 100.0 * period * MONTH / 365;
}

QString ChToDot(QString str) {
  for (int i = 0; i < str.length(); i++) {
    if (str[i] == ',') {
      str[i] = '.';
    }
  }
  return str;
}

int MainWindow::combo_box_pars(QString str) {
  int value = 0;
  if (str == "Ежемесячно") {
    value = 1;
  } else if (str == "6 месяцев") {
    value = 6;
  } else if (str == "1 год") {
    value = 12;
  }
  return value;
}

void MainWindow::on_box_replenishment_currentTextChanged(const QString &arg1) {
  if (arg1 == "Нет") {
    ui->lineEdit_replenish->hide();
  } else {
    ui->lineEdit_replenish->show();
  }
}

void MainWindow::on_count_deposit_clicked() {
  QString temp_text_1 = ui->edit_sum_deposit->text();
  QString temp_text_2 = ui->edit_term_deposit->text();
  QString temp_text_3 = ui->edit_interest_rate_deposit->text();
  QString temp_text_4 = ui->edit_key_rate_deposit->text();
  QString temp_text_5 = ui->edit_tax_rate->text();
  QString temp_text_6 = ui->lineEdit_replenish->text();

  QByteArray ba_1 = temp_text_1.toLocal8Bit();
  QByteArray ba_2 = temp_text_2.toLocal8Bit();
  QByteArray ba_3 = temp_text_3.toLocal8Bit();
  QByteArray ba_4 = temp_text_4.toLocal8Bit();
  QByteArray ba_5 = temp_text_5.toLocal8Bit();
  QByteArray ba_6 = temp_text_6.toLocal8Bit();
  char *text_1 = ba_1.data();
  char *text_2 = ba_2.data();
  char *text_3 = ba_3.data();
  char *text_4 = ba_4.data();
  char *text_5 = ba_5.data();
  char *text_6 = ba_6.data();

  int status_valid = FAIL;
  if (((*text_1) != '\0') && ((*text_2) != '\0') && ((*text_3) != '\0') &&
      ((*text_4) != '\0') && ((*text_5) != '\0') && ((*text_6) != '\0')) {
    if ((isNumber(text_1) == OK) && (isNumber(text_2) == OK) &&
        (isNumber(text_3) == OK) && (isNumber(text_4) == OK) &&
        (isNumber(text_5) == OK) && (isNumber(text_6) == OK)) {
      status_valid = OK;
    } else {
      QMessageBox::critical(this, "Invalid expression", "Invalid input");
    }
  }

  if (status_valid == OK) {
    deposit_t newDeposit;
    newDeposit.money = ui->edit_sum_deposit->text().toInt();
    newDeposit.period = ui->edit_term_deposit->text().toInt();
    newDeposit.rate =
        ChToDot(ui->edit_interest_rate_deposit->text()).toDouble();
    newDeposit.key_rate = ChToDot(ui->edit_key_rate_deposit->text()).toDouble();
    newDeposit.capitalisation = ui->box_capitalisation->currentText();
    newDeposit.payout = ui->box_payout->currentText();
    newDeposit.replenishment = ui->box_replenishment->currentText();
    newDeposit.tax_kind = ChToDot(ui->edit_tax_rate->text()).toDouble();
    if (ui->lineEdit_replenish->isVisible()) {
      newDeposit.replenish = ChToDot(ui->lineEdit_replenish->text()).toDouble();
    }

    newDeposit.percent = 0;
    newDeposit.deposit = newDeposit.money;
    newDeposit.tax = 0;

    if (newDeposit.capitalisation == "Нет") {
      no_capitalisation(&newDeposit);
    } else {
      capitalisation(&newDeposit);
    }

    ui->output_accrued_interest->setText(QString::number(newDeposit.percent));
    ui->output_sum_tax->setText(QString::number(newDeposit.tax));
    ui->output_sum_interest->setText(QString::number(newDeposit.deposit));
  }
}
