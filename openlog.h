/**
* @file openlog.h
* @author Kandai Watanabe
* @date Created: 20170506
*/
#ifndef _OPENLOG_H_
#define _OPENLOG_H_
#include <stdio.h>
#include <string.h>
#include "Arduino.h"
#include <HardwareSerial.h>

class OpenLog {
public:
  OpenLog(int pinOpenLogReset);
  ~OpenLog();
  void init(HardwareSerial* serial);
  void openErrorFile();
  void saveErrorOnSD(String error);
  void saveDataOnSD(String alldata);

  void reset();
  void waitUntilReady2Log();
  void waitUntilReady2ReceiveCommand();
  void gotoCommandMode();
  void createFile(char *fileName);
  void appendFile(char *fileName);
  bool isExist(char *fileName);

  HardwareSerial* _serial;
  int _pinOpenLogReset;

  char _logFile[12];
  char _errorFile[12];
};

#endif
