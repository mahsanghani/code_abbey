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

int WINAPI WinMain(HINSTANCE hThisInstance, HINSTANCE hPrevInstance,
                   LPSTR lpszArgument, int nCmdShow) {

  HWND hwnd;        /* This is the handle for our window */
  MSG messages;     /* Here messages to the application are saved */
  WNDCLASSEX wincl; /* Data structure for the windowclass */

  /* The Window structure */
  wincl.hInstance = hThisInstance;
  wincl.lpszClassName = szAppName;
  wincl.lpfnWndProc = WindowProcedure; /* This function is called by windows */
  wincl.style = CS_DBLCLKS;            /* Catch double-clicks */
  wincl.cbSize = sizeof(WNDCLASSEX);

  /* Use default icon and mouse-pointer */
  wincl.hIcon = LoadIcon(NULL, IDI_APPLICATION);
  wincl.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
  wincl.hCursor = LoadCursor(NULL, IDC_ARROW);
  wincl.lpszMenuName = "APP_MENU"; /*menu */
  wincl.cbClsExtra = 0;            /* No extra bytes after the window class */
  wincl.cbWndExtra = 0;            /* structure or the window instance */
  /* Use Windows's default colour as the background of the window */
  wincl.hbrBackground = (HBRUSH)COLOR_BACKGROUND;

  /* Register the window class, and if it fails quit the program */
  if (!RegisterClassEx(&wincl))
    return 0;

  /* The class is registered, let's create the program*/
  hwnd =
      CreateWindowEx(0,         /* Extended possibilites for variation */
                     szAppName, /* Classname */
                     szAppName, /* Title Text */
                     WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU |
                         WS_MINIMIZEBOX, /* default window */
                     CW_USEDEFAULT,      /* Windows decides the position */
                     CW_USEDEFAULT, /* where the window ends up on the screen */
                     430,           /* The programs width */
                     315,           /* and height in pixels */
                     HWND_DESKTOP, /* The window is a child-window to desktop */
                     NULL,         /*use class menu */
                     hThisInstance, /* Program Instance handler */
                     NULL           /* No Window Creation data */
      );

  /* Make the window visible on the screen */
  ShowWindow(hwnd, nCmdShow);

  /* Run the message loop. It will run until GetMessage() returns 0 */
  while (GetMessage(&messages, NULL, 0, 0)) {
    /* Translate virtual-key messages into character messages */
    TranslateMessage(&messages);
    /* Send message to WindowProcedure */
    DispatchMessage(&messages);
  }

  /* The program return-value is 0 - The value that PostQuitMessage() gave */
  return messages.wParam;
}

LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT message, WPARAM wParam,
                                 LPARAM lParam) {
  static HWND RecButton;
  static HWND PlyButton;
  static HWND StpButton;
  static HMENU hMenu;
  static HPEN hPen;
  static BOOL bRecording, bPlaying, bEnding, bTerminating;
  static DWORD dwDataLength, dwRepetitions = 1;
  static HWAVEIN hWaveIn;
  static HWAVEOUT hWaveOut;
  static PBYTE pBuffer1, pBuffer2, pSaveBuffer, pNewBuffer;
  static PWAVEHDR pWaveHdr1, pWaveHdr2;
  static TCHAR szOpenError[] = TEXT("Error opening waveform audio!");
  static TCHAR szMemError[] = TEXT("Error allocating memory!");
  static WAVEFORMATEX waveform;
  static int sampleRate = 11025;
  const int NUMPTS = 11025 * 10;
  hMenu = GetMenu(hwnd);
  HDC hDC;
  POINT pt[NUM];
  switch (message) /* handle the messages */
  {
  case WM_CREATE:
    RecButton = CreateWindow(TEXT("button"), "RECORD",
                             WS_VISIBLE | WS_CHILD | ES_LEFT | 1, 7, 175, 100,
                             25, hwnd, (HMENU)IDC_RECORD,
                             ((LPCREATESTRUCT)lParam)->hInstance, NULL);
    PlyButton = CreateWindow(TEXT("button"), "PLAY",
                             WS_VISIBLE | WS_CHILD | ES_LEFT | 1, 157, 175, 100,
                             25, hwnd, (HMENU)IDC_PLAY,
                             ((LPCREATESTRUCT)lParam)->hInstance, NULL);
    StpButton = CreateWindow(TEXT("button"), "STOP",
                             WS_VISIBLE | WS_CHILD | ES_LEFT | 1, 314, 175, 100,
                             25, hwnd, (HMENU)IDC_STOP,
                             ((LPCREATESTRUCT)lParam)->hInstance, NULL);
    EnableWindow(PlyButton, FALSE);
    EnableWindow(StpButton, FALSE);

    pWaveHdr1 = reinterpret_cast<PWAVEHDR>(malloc(sizeof(WAVEHDR)));
    pWaveHdr2 = reinterpret_cast<PWAVEHDR>(malloc(sizeof(WAVEHDR)));
    // Allocate memory for save buffer

    pSaveBuffer = reinterpret_cast<PBYTE>(malloc(1));
    return 0;

  case WM_PAINT:
    PAINTSTRUCT ps;
    hDC = BeginPaint(hwnd, &ps);

    if (hDC) {
      RECT rc;
      rc.top = 15;
      rc.left = 0;
      rc.bottom = 165;
      rc.right = 425;
      FillRect(hDC, &rc, (HBRUSH)GetStockObject(BLACK_BRUSH));
      if (PLAY == TRUE) {
        FillRect(hDC, &rc, (HBRUSH)GetStockObject(BLACK_BRUSH));
        Wav("temp.wav");
        hPen = CreatePen(PS_SOLID, 1, RGB(0, 200, 0));
        SelectObject(hDC, hPen);

        SetMapMode(hDC, MM_ISOTROPIC);
        SetWindowExtEx(hDC, 430, 315, NULL);
        SetViewportExtEx(hDC, 200, 200, NULL);
        SetViewportOrgEx(hDC, 0, 0, NULL);

        int sample = 0;
        int i = 1;
        int num = 20000;
        sample = readSample(i, TRUE);
        // scale the sample

        pt[i].x = i / 20;
        pt[i].y = (int)((sample)*2);
        MoveToEx(hDC, pt[i].x, pt[i].y, NULL);
        while (i < num && sample != (int)0xefffffff) {
          // scale the sample

          pt[i].x = i / 20;
          pt[i].y = (int)((sample)*2);

          LineTo(hDC, pt[i].x, pt[i].y);
          i++;
          sample = readSample(i, TRUE);
        }
      }
      DeleteObject(hPen);
      DeleteDC(hDC);
      EndPaint(hwnd, &ps);
    }
    return 0;

  case MM_WIM_OPEN:
    // Shrink down the save buffer

    pSaveBuffer = reinterpret_cast<PBYTE>(realloc(pSaveBuffer, 1));

    // Add the buffers

    waveInAddBuffer(hWaveIn, pWaveHdr1, sizeof(WAVEHDR));
    waveInAddBuffer(hWaveIn, pWaveHdr2, sizeof(WAVEHDR));

    // Begin sampling

    bRecording = TRUE;
    bEnding = FALSE;
    dwDataLength = 0;
    waveInStart(hWaveIn);
    return TRUE;

  case MM_WIM_DATA:

    // Reallocate save buffer memory

    pNewBuffer = reinterpret_cast<PBYTE>(realloc(
        pSaveBuffer, dwDataLength + ((PWAVEHDR)lParam)->dwBytesRecorded));

    if (pNewBuffer == NULL) {
      waveInClose(hWaveIn);

      MessageBox(hwnd, szMemError, szAppName, MB_ICONEXCLAMATION | MB_OK);
      return TRUE;
    }

    pSaveBuffer = pNewBuffer;
    CopyMemory(pSaveBuffer + dwDataLength, ((PWAVEHDR)lParam)->lpData,
               ((PWAVEHDR)lParam)->dwBytesRecorded);

    dwDataLength += ((PWAVEHDR)lParam)->dwBytesRecorded;

    if (bEnding) {
      waveInClose(hWaveIn);
      return TRUE;
    }

    // Send out a new buffer

    waveInAddBuffer(hWaveIn, (PWAVEHDR)lParam, sizeof(WAVEHDR));
    return TRUE;

  case MM_WIM_CLOSE:
    // Free the buffer memory

    waveInUnprepareHeader(hWaveIn, pWaveHdr1, sizeof(WAVEHDR));
    waveInUnprepareHeader(hWaveIn, pWaveHdr2, sizeof(WAVEHDR));

    free(pBuffer1);
    free(pBuffer2);

    // Enable and disable buttons
    if (dwDataLength > 0) {
      EnableWindow(PlyButton, TRUE);
    }
    bRecording = FALSE;

    if (bTerminating)
      SendMessage(hwnd, WM_SYSCOMMAND, SC_CLOSE, 0L);

    return TRUE;

  case MM_WOM_OPEN:

    // Set up header

    pWaveHdr1->lpData = reinterpret_cast<CHAR *>(pSaveBuffer);
    pWaveHdr1->dwBufferLength = dwDataLength;
    pWaveHdr1->dwBytesRecorded = 0;
    pWaveHdr1->dwUser = 0;
    pWaveHdr1->dwFlags = WHDR_BEGINLOOP | WHDR_ENDLOOP;
    pWaveHdr1->dwLoops = dwRepetitions;
    pWaveHdr1->lpNext = NULL;
    pWaveHdr1->reserved = 0;

    // Prepare and write

    waveOutPrepareHeader(hWaveOut, pWaveHdr1, sizeof(WAVEHDR));
    waveOutWrite(hWaveOut, pWaveHdr1, sizeof(WAVEHDR));

    bEnding = FALSE;
    bPlaying = TRUE;
    return TRUE;

  case MM_WOM_DONE:

    waveOutUnprepareHeader(hWaveOut, pWaveHdr1, sizeof(WAVEHDR));
    waveOutClose(hWaveOut);
    EnableWindow(PlyButton, TRUE);
    return TRUE;

  case MM_WOM_CLOSE:

    dwRepetitions = 1;
    bPlaying = FALSE;

    return TRUE;

  case WM_COMMAND:

    switch (wParam) {

    case APP_SAVE: {

      int chunksize, pcmsize, NumSamples, subchunk1size;
      int audioFormat = 1;
      int numChannels = 1;
      int bitsPerSample = 8;

      NumSamples = ((long)(NUMPTS / sampleRate) * 1000);
      pcmsize = sizeof(PCMWAVEFORMAT);

      ;
      subchunk1size = 16;
      int byteRate = sampleRate * numChannels * bitsPerSample / 8;
      int blockAlign = numChannels * bitsPerSample / 8;
      int subchunk2size = pWaveHdr1->dwBufferLength * numChannels;

      chunksize = (36 + subchunk2size);
      fstream myFile("test.wav", ios::out | ios::binary);

      // write the wav file per the wav file format
      myFile.seekp(0, ios::beg);
      myFile.write("RIFF", 4);             // chunk id
      myFile.write((char *)&chunksize, 4); // chunk size (36 + SubChunk2Size))
      myFile.write("WAVE", 4);             // format
      myFile.write("fmt ", 4);             // subchunk1ID
      myFile.write((char *)&subchunk1size, 4); // subchunk1size (16 for PCM)
      myFile.write((char *)&audioFormat, 2);   // AudioFormat (1 for PCM)
      myFile.write((char *)&numChannels, 2);   // NumChannels
      myFile.write((char *)&sampleRate, 4);    // sample rate
      myFile.write((char *)&byteRate,
                   4); // byte rate (SampleRate * NumChannels * BitsPerSample/8)
      myFile.write((char *)&blockAlign,
                   2); // block align (NumChannels * BitsPerSample/8)
      myFile.write((char *)&bitsPerSample, 2); // bits per sample
      myFile.write("data", 4);                 // subchunk2ID
      myFile.write(
          (char *)&subchunk2size,
          4); // subchunk2size (NumSamples * NumChannels * BitsPerSample/8)

      myFile.write(pWaveHdr1->lpData, pWaveHdr1->dwBufferLength); // data

    } break;

    case IDC_RECORD: {
      EnableWindow(RecButton, FALSE);
      EnableWindow(PlyButton, FALSE);
      EnableWindow(StpButton, TRUE);
      pBuffer1 = reinterpret_cast<PBYTE>(malloc(INP_BUFFER_SIZE));
      pBuffer2 = reinterpret_cast<PBYTE>(malloc(INP_BUFFER_SIZE));

      if (!pBuffer1 || !pBuffer2) {
        if (pBuffer1)
          free(pBuffer1);
        if (pBuffer2)
          free(pBuffer2);
        MessageBox(hwnd, szMemError, szAppName, MB_ICONEXCLAMATION | MB_OK);
        return TRUE;
      }
      // Open waveform audio for input

      waveform.wFormatTag = WAVE_FORMAT_PCM;
      waveform.nChannels = 1;
      waveform.nSamplesPerSec = 11025;
      waveform.nAvgBytesPerSec = 11025;
      waveform.nBlockAlign = 1;
      waveform.wBitsPerSample = 8;
      waveform.cbSize = 0;

      if (waveInOpen(&hWaveIn, WAVE_MAPPER, &waveform, (DWORD)hwnd, 0,
                     CALLBACK_WINDOW)) {
        free(pBuffer1);
        free(pBuffer2);
      }
      // Set up headers and prepare them

      pWaveHdr1->lpData = reinterpret_cast<CHAR *>(pBuffer1);
      pWaveHdr1->dwBufferLength = INP_BUFFER_SIZE;
      pWaveHdr1->dwBytesRecorded = 0;
      pWaveHdr1->dwUser = 0;
      pWaveHdr1->dwFlags = 0;
      pWaveHdr1->dwLoops = 1;
      pWaveHdr1->lpNext = NULL;
      pWaveHdr1->reserved = 0;

      waveInPrepareHeader(hWaveIn, pWaveHdr1, sizeof(WAVEHDR));

      pWaveHdr2->lpData = reinterpret_cast<CHAR *>(pBuffer2);
      pWaveHdr2->dwBufferLength = INP_BUFFER_SIZE;
      pWaveHdr2->dwBytesRecorded = 0;
      pWaveHdr2->dwUser = 0;
      pWaveHdr2->dwFlags = 0;
      pWaveHdr2->dwLoops = 1;
      pWaveHdr2->lpNext = NULL;
      pWaveHdr2->reserved = 0;

      waveInPrepareHeader(hWaveIn, pWaveHdr2, sizeof(WAVEHDR));
    } break;

    case IDC_STOP: {
      // Reset input to return last buffer
      EnableWindow(RecButton, TRUE);
      EnableWindow(StpButton, FALSE);
      EnableWindow(PlyButton, TRUE);
      bEnding = TRUE;

      // save wav file to temp.wav
      int chunksize, pcmsize, NumSamples, subchunk1size;
      int audioFormat = 1;
      int numChannels = 1;
      int bitsPerSample = 8;

      NumSamples = ((long)(NUMPTS / sampleRate) * 1000);
      pcmsize = sizeof(PCMWAVEFORMAT);

      subchunk1size = 16;
      int byteRate = (sampleRate * numChannels) * (bitsPerSample / 8);
      int blockAlign = numChannels * bitsPerSample / 8;
      int subchunk2size = pWaveHdr1->dwBufferLength * numChannels;

      chunksize = (36 + subchunk2size);
      fstream myFile("temp.wav", ios::out | ios::binary);

      // write the wav file per the wav file format
      myFile.seekp(0, ios::beg);
      myFile.write("RIFF", 4);             // chunk id
      myFile.write((char *)&chunksize, 4); // chunk size (36 + SubChunk2Size))
      myFile.write("WAVE", 4);             // format
      myFile.write("fmt ", 4);             // subchunk1ID
      myFile.write((char *)&subchunk1size, 4); // subchunk1size (16 for PCM)
      myFile.write((char *)&audioFormat, 2);   // AudioFormat (1 for PCM)
      myFile.write((char *)&numChannels, 2);   // NumChannels
      myFile.write((char *)&sampleRate, 4);    // sample rate
      myFile.write((char *)&byteRate,
                   4); // byte rate (SampleRate * NumChannels * BitsPerSample/8)
      myFile.write((char *)&blockAlign,
                   2); // block align (NumChannels * BitsPerSample/8)
      myFile.write((char *)&bitsPerSample, 2); // bits per sample
      myFile.write("data", 4);                 // subchunk2ID
      myFile.write(
          (char *)&subchunk2size,
          4); // subchunk2size (NumSamples * NumChannels * BitsPerSample/8)

      myFile.write(pWaveHdr1->lpData, pWaveHdr1->dwBufferLength); // data
    } break;

    case IDC_PLAY: {
      // play wav file
      bPlaying = TRUE;

      EnableWindow(PlyButton, FALSE);
      waveform.wFormatTag = WAVE_FORMAT_PCM;
      waveform.nChannels = 1;
      waveform.nSamplesPerSec = 11025;
      waveform.nAvgBytesPerSec = 11025;
      waveform.nBlockAlign = 1;
      waveform.wBitsPerSample = 8;
      waveform.cbSize = 0;
      waveInReset(hWaveIn);

      if (waveOutOpen(&hWaveOut, WAVE_MAPPER, &waveform, (DWORD)hwnd, 0,
                      CALLBACK_WINDOW)) {

        MessageBox(hwnd, szOpenError, szAppName, MB_ICONEXCLAMATION | MB_OK);
      }

      Wav("temp.wav");
      // Open waveform audio for output

      RECT rc;
      GetClientRect(hwnd, &rc);
      PLAY = TRUE;
      InvalidateRect(hwnd, &rc, TRUE);
    } break;
    }
    break;

  case WM_DESTROY:
    PostQuitMessage(0); /* send a WM_QUIT to the message queue */
    break;

  default: /* for messages that we don't deal with */
    return DefWindowProc(hwnd, message, wParam, lParam);
  }

  return 0;
}
