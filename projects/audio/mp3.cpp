//
// Created by Ahsan Ghani on 2022-09-15.
//
#include "resource.h"

#include <cstdlib>
#include <errno.h>
#include <fstream>
#include <iostream>
#include <math.h>
#include <mmsystem.h>

using namespace std;

int number, length, byte_samp, byte_sec, bit_samp;
bool mono = TRUE;
bool PLAY = FALSE;
// errno_t wavfile;
char *filename;
int s_rate = 11025;
double limit = 5000.0;
FILE *stream;
/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);
/* Declare procedures */
int readSample(int number, bool leftchannel);
void Wav(char *c);
/*  Make the class name into a global variable  */
char szAppName[] = "Recorder";
