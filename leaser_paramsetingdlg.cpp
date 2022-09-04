#include "leaser_paramsetingdlg.h"
#include "ui_leaser_paramsetingdlg.h"

leaser_paramsetingdlg::leaser_paramsetingdlg(my_parameters *mcs,QWidget *parent) :
  QDialog(parent),
  ui(new Ui::leaser_paramsetingdlg)
{
  m_mcs=mcs;

  ui->setupUi(this);

  ui->record->document()->setMaximumBlockCount(500);   //调试窗最大设置行数

  ui->tabWidget->setTabText(0,"相机参数");
  ui->tabWidget->setTabText(1,"插补参数");

  ui->tabWidget->setCurrentIndex(0);

  for(int i = 0; i < ui->tab1tableWidget->rowCount(); i++)//设置第一二列不可编辑
  {
      QTableWidgetItem *item0 = ui->tab1tableWidget->item(i, 0);
      QTableWidgetItem *item1 = ui->tab1tableWidget->item(i, 1);
      if(item0)
      {
          item0->setFlags(item0->flags() & (~Qt::ItemIsEditable));
      }
      if(item1)
      {
          item1->setFlags(item1->flags() & (~Qt::ItemIsEditable));
      }
  }

  connect(ui->writeTab1Btn,&QPushButton::clicked,[=](){
     if(m_mcs->resultdata.link_param_state==true)
     {
         uint16_t tab_reg[ALS103_REG_TOTALNUM-1];
         for(int i=0;i<ALS103_REG_TOTALNUM-1;i++)
         {
             tab_reg[i]=(uint16_t)(ui->tab1tableWidget->item(i,2)->text().toInt());
         }
         int rc=modbus_write_registers(m_mcs->resultdata.ctx_param,ALS103_EXPOSURE_TIME_REG_ADD+1,ALS103_REG_TOTALNUM-1,tab_reg);
         if(rc!=ALS103_REG_TOTALNUM-1)
         {
             ui->record->append("设置相机参数失败");
         }
         else
         {
             ui->record->append("设置相机参数成功");
         }
     }
     else
     {
         ui->record->append("请连接相机后再设置相机参数");
     }
  });

  connect(ui->initTab1Btn,&QPushButton::clicked,[=](){
     if(m_mcs->resultdata.link_param_state==true)
     {
         uint16_t tab_reg[1];
         tab_reg[0]=1;
         int rc=modbus_write_registers(m_mcs->resultdata.ctx_param,ALS103_INIT_REG_ADD,1,tab_reg);
         if(rc!=1)
         {
             ui->record->append("重置相机参数失败");
         }
         else
         {
             ui->record->append("重置相机参数成功");
             sleep(1);
             int real_readnum=0;
             u_int16_t rcvdata[ALS103_REG_TOTALNUM];
             real_readnum=modbus_read_registers(m_mcs->resultdata.ctx_param,ALS103_EXPOSURE_TIME_REG_ADD,ALS103_REG_TOTALNUM,rcvdata);
             if(real_readnum<0)
             {
                 ui->record->append("重新读取相机参数失败");
             }
             else
             {
                 for(int i=1;i<ALS103_REG_TOTALNUM;i++)
                 {
                     ui->tab1tableWidget->item(i-1,2)->setText(QString::number((int16_t)rcvdata[i]));
                 }
                 ui->record->append("重新读取相机参数成功");
             }
         }
     }
     else
     {
         ui->record->append("请连接相机后再重置相机参数");
     }
  });

  connect(ui->readTab1Btn,&QPushButton::clicked,[=](){
     if(m_mcs->resultdata.link_param_state==true)
     {
         int real_readnum=0;
         u_int16_t rcvdata[ALS103_REG_TOTALNUM];
         real_readnum=modbus_read_registers(m_mcs->resultdata.ctx_param,ALS103_EXPOSURE_TIME_REG_ADD,ALS103_REG_TOTALNUM,rcvdata);
         if(real_readnum<0)
         {
             ui->record->append("读取相机参数失败");
         }
         else
         {
             for(int i=1;i<ALS103_REG_TOTALNUM;i++)
             {
                 ui->tab1tableWidget->item(i-1,2)->setText(QString::number((int16_t)rcvdata[i]));
             }
             ui->record->append("读取相机参数成功");
         }
     }
     else
     {
         ui->record->append("请连接相机后再读取相机参数");
     }
  });
}

leaser_paramsetingdlg::~leaser_paramsetingdlg()
{
  delete ui;
}

void leaser_paramsetingdlg::Initparam()
{
  if(m_mcs->resultdata.link_param_state==true)
  {
      int real_readnum=1;
      u_int16_t rcvdata[ALS103_REG_TOTALNUM];
      real_readnum=modbus_read_registers(m_mcs->resultdata.ctx_param,ALS103_EXPOSURE_TIME_REG_ADD,ALS103_REG_TOTALNUM,rcvdata);
      if(real_readnum<0)
      {
          ui->record->append("读取相机参数失败");
      }
      else
      {
          for(int i=1;i<ALS103_REG_TOTALNUM;i++)
          {
              ui->tab1tableWidget->item(i-1,2)->setText(QString::number((int16_t)rcvdata[i]));
          }
          ui->record->append("读取相机参数成功");
      }
  }
}
