#ifndef GLOBAL_H
#define GLOBAL_H

#define LEASER_VIEW_CONER_COL       26.9f      //水平视场26.9度
#define LEASER_VIEW_CONER_ROW       0.0f      //垂直视场0度

#define CAMIMAGE_HEIGHT             1024     //初始化相机图像长宽
#define CAMIMAGE_WIDTH              1536

#define CAMTOTALNUM                 1       //当前同型号下支持几路相机

#define CLOULD_POINT_NOTDATE        0   //深度值不存在时点云的值

/*************************/
//采集模式
#define AUTO_MOD                    0         //自适应采集模式
#define CALLBACK_MOD                1         //相机节拍采集模式
#define ACQUISITION_MOD             AUTO_MOD  //点云和深度图采集模式
/***************************/

#define ROWS_PROPORTION              1.0     //相机图像高度比例   实际距离(mm)/相机像素距离
#define COLS_PROPORTION              1.0     //相机图像宽度比例   实际距离(mm)/相机像素距离

#define DEEPIMG_CALLBACKNUM_DNUM     5     //采集深度图时多采集的帧数


//任务号103
#define ALS103_EXPOSURE_TIME_REG_ADD           0x0060
#define ALS103_PINGJUN_REG_ADD                 0x0061
#define ALS103_GUJIAERZHI_REG_ADD              0x0062
#define ALS103_WIDTHLIANTONGDIS_REG_ADD        0x0063
#define ALS103_HIGHLIANTONGDIS_REG_ADD         0x0064
#define ALS103_JIGUANGLONG_REG_ADD             0x0065
#define ALS103_JIGUANGKUANDU_REG_ADD           0x0066
#define ALS103_JIGUANGDUIBIDU_REG_ADD          0x0067

//任务号103寄存器总数
#define ALS103_REG_TOTALNUM                    0x0008
//重置任务103参数寄存器
#define ALS103_INIT_REG_ADD                    0x006f

//显示图像处理步骤
#define ALS_SHOW_STEP_REG_ADD                  0x018f


#endif // GLOBAL_H
