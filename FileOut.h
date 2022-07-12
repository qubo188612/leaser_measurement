#ifndef FILEOUT_H
#define FILEOUT_H

#include <fstream>

class CFileOut
{
public:
  CFileOut(void);
  ~CFileOut(void);
public:
  int WriteFile(char* fileName,uint8_t *dt,int dtLen);//写数据
  int ReadFile(char* fileName,uint8_t *dt,int rLen);//读数据
};

#endif // FILEOUT_H
