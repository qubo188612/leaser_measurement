#include "E2proomData.h"

E2proomData::E2proomData()
{
    measurementDlg_leaser_data_mod_min=E2POOM_MEASUREMENTDLG_LEASER_DATA_MOD_MIN;
    measurementDlg_leaser_data_mod_max=E2POOM_MEASUREMENTDLG_LEASER_DATA_MOD_MAX;
    measurementDlg_leaser_data_mod_use=E2POOM_MEASUREMENTDLG_LEASER_DATA_MOD_USE;


    read_para();
}

E2proomData::~E2proomData()
{

}

void E2proomData::check_para()
{
    if(measurementDlg_leaser_data_mod<measurementDlg_leaser_data_mod_min||measurementDlg_leaser_data_mod>measurementDlg_leaser_data_mod_max)
        measurementDlg_leaser_data_mod=measurementDlg_leaser_data_mod_use;
}

void E2proomData::read_para()
{
    Uint8 *buff=NULL;
    CFileOut fo;

    buff=new Uint8[E2POOM_MEASUREMENTDLG_SAVEBUFF];
    if(buff==NULL)
        return;
    if(0 > fo.ReadFile(E2POOM_MEASUREMENTDLG_SYSPATH_MOTO,buff,E2POOM_MEASUREMENTDLG_SAVEBUFF))
    {
        init_measurementDlg_para();
        if(buff!=NULL)
        {
          delete []buff;
          buff=NULL;
        }
    }
    else
    {
      Int8 *i8_p;
      i8_p = (Int8*)buff;
      measurementDlg_leaser_data_mod=*i8_p;
      i8_p++;
    }
    if(buff!=NULL)
    {
      delete []buff;
      buff=NULL;
    }


}

void E2proomData::write_measurementDlg_para()
{
    Uint8 *buff=NULL;
    CFileOut fo;

    check_para();
    buff=new Uint8[E2POOM_MEASUREMENTDLG_SAVEBUFF];
    if(buff==NULL)
      return;

    Int8 *i8_p;

    i8_p = (Int8*)buff;
    *i8_p=measurementDlg_leaser_data_mod;
    i8_p++;

    fo.WriteFile(E2POOM_MEASUREMENTDLG_SYSPATH_MOTO,buff,E2POOM_MEASUREMENTDLG_SAVEBUFF);

    if(buff!=NULL)
    {
      delete []buff;
      buff=NULL;
    }
}

void E2proomData::init_measurementDlg_para()
{
    measurementDlg_leaser_data_mod=measurementDlg_leaser_data_mod_use;
}
