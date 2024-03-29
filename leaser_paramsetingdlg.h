#ifndef LEASER_PARAMSETINGDLG_H
#define LEASER_PARAMSETINGDLG_H

#include <QDialog>
#include "my_parameters.h"

namespace Ui {
class leaser_paramsetingdlg;
}

class leaser_paramsetingdlg : public QDialog
{
  Q_OBJECT

public:
  explicit leaser_paramsetingdlg(my_parameters *mcs,QWidget *parent = nullptr);
  ~leaser_paramsetingdlg();

  my_parameters *m_mcs;

  void Initparam(my_parameters *mcs);      //初始化

private slots:
  void on_tabWidget_currentChanged(int index);

private:
  Ui::leaser_paramsetingdlg *ui;
};

#endif // LEASER_PARAMSETINGDLG_H
