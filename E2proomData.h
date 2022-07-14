#ifndef E2PROOMDATA_H
#define E2PROOMDATA_H

#include "tistdtypes.h"
#include "FileOut.h"

//主页面参数
#define E2POOM_MEASUREMENTDLG_SAVEBUFF          20
#define E2POOM_MEASUREMENTDLG_SYSPATH_MOTO			"./SAVE/E2P_MEASUREMENT_DLG.bsd"

#define E2POOM_MEASUREMENTDLG_LEASER_DATA_MOD_MIN				0   //显示模式最小值
#define E2POOM_MEASUREMENTDLG_LEASER_DATA_MOD_USE				0   //显示模式默认值   0原图，1轮廓,2轮廓点云,3深度图,4点云
#define E2POOM_MEASUREMENTDLG_LEASER_DATA_MOD_MAX				4   //显示模式最大值

class E2proomData
{
public:
    E2proomData();
    ~E2proomData();

/****************************/
    //主页面参数
    Int8 measurementDlg_leaser_data_mod;  //显示模式，0原图，1轮廓,2轮廓点云,3深度图,4点云


    void write_measurementDlg_para();				//保存主页面参数
    void init_measurementDlg_para();				//初始化主页面参数
    //默认参赛
    Int8 measurementDlg_leaser_data_mod_min;    //显示模式最小值
    Int8 measurementDlg_leaser_data_mod_max;    //显示模式最大值
    Int8 measurementDlg_leaser_data_mod_use;    //显示模式默认值

/****************************/
private:
    void read_para();				//读取
    void check_para();			//检查参数
};

#endif // E2PROOMDATA_H
