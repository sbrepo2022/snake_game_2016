#include <windows.h>
#include <fstream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <vector>
#include "game_var.h"
#include "WndMatrix.h"
#include "ImgPrint.h"
#include "TextPrint.h"
using namespace std;

TextPrint TextHelp("\n\n����: �������� ������� ���������� ��� ����� ������ �����.\n���������� �������������� �������� WASD ��� ��������� �� ����������.\n������ ������ �� ������������� ����, ��� ���� ����� ������ ������������� �� 1 � ������\n��������� �������. ���� ����������� ���� �����.\n\n\n\nClassic - ������������ ����� ������ ������ ������.\nAdvanced - ������� ������, �����, ����� �����. ������� ������ ���� ��������� ����� (�3).\n����� ��� ��������� �������� �����.\nTime - ��� Classic, ������ �� ��������. ������ ��������� ������ +3 ������� �� �������.\n����� ������ 5 ������ ������ �������� � ���������� � ����� �����.\n\n\n\n������ ��������� ��������.\n��������� ���������� - ��� ������ ����� ������ ������������ ����������� ��� ����������\n���������.\n����� - �������� / ��������� �����.\n��������� ��� ������������ � ������� - ��������� / ����������� ������.\n��������� - �������� / ��������� ��������� ��� �������� �����.\n�������� ���� - ��������� ��������. ��� ���� ������� (3 ������), ��� ������� ����.\n���� ���� - ����� ����� ����.\n������ ���� - ��������� ����� � ������ ����. ����������� �������� ����� � ������: 10, \n������������: 60.\n���������� - ����� ���������� ������� (WASD ��� ���������).\n���������������� �������� - �������� ����������� ��������.\n\n\n\n���������� ����������� ������������ ��� ���������� ���������� \"�����\", \"��������� ���\n������������ � �������\", \"���������\" � \"��������\" �� ����� 2 ������. ��� ���� ������ ����\n�������� \"���������� �����������\". �����: �������� ����� ��������� ������!\n\n\n\n��� �������� �������� ����������:\n1. ������� ��������. �������� ����� ����������� �������� � �������� ����������� �\n����������� 40x20. ����� �������� ����������� (20x20) ������ ��������� �������� ������,\n���������� ������. ������ �������� ����������� (��� �� 20x20) ������ ��������� ��������\n����. ��������� � ���� �� ������������ ������� ���� ������������ �������� ������, �������\n���� ����������� (� ������ �������).\n2. ��������� �����������. ��������� �������� � ������� .bmp ��� �������� ���������� �\n�������� ������������.\n3. ��������� ��������. � ������ ��� ����� ������ ������� ������ ��� ������������� ����� ��\n����� � ���������. ������� ������ \"��������� ��������\".\n\n\n\n������ ����������� ������� ������� �� ����� ���������������� C++. �����������\n��������� ���������� ��� ������ Gdi WinApi � Gdi+ WinApi. ��������� �������������\n������������� ��� ������� �����������. �� ��� �������!\n\n\n\n", 0, 0);
#define ID_BUTTONBACK 1000

#define ID_BUTTONPLAY 1001
#define ID_BUTTONSETTINGS 1002
#define ID_BUTTONHELP 1003
#define ID_BUTTONCREDITS 1004
#define ID_BUTTONEXIT 1005
#define ID_BUTTONREMOVE 1006
#define ID_BUTTONRRES 1007
#define ID_BUTTONLRES 1008

#define ID_EDITUSER 3001
#define ID_BUTTONSAVE 3002
#define ID_BUTTONWALL 3003
#define ID_BUTTONSCROSS 3004
#define ID_BUTTONACCELERATE 3005
#define ID_BUTTONSPEED 3006
#define ID_BUTTONSNAKETL 3007
#define ID_BUTTONSNAKETR 3008
#define ID_EDITWIDTH 30010
#define ID_EDITHEIGHT 3011
#define ID_EDITTEXTURE 3012
#define ID_BUTTONLOADT 3013
#define ID_BUTTONCONTROL 3014
#define ID_SCROLLTIME 3015

#define ID_SCROLLHELP 4001

#define ID_BUTTONCLASSIC 6001
#define ID_BUTTONADVANCED 6002
#define ID_BUTTONTIME 6003
#define ID_BUTTONCUSTOM 6004
#define ID_BUTTONPLAYERCOUNT 6005
#define ID_BUTTONSETTINGM2 6006
#define ID_BUTTONSETTINGM3 6007
#define ID_BUTTONSETTINGM4 6008
#define ID_BUTTONSETTINGM5 6009

#define ID_LISTMAPS 6071

#define ID_EDITUSER2 6101
#define ID_EDITTEXTURE2 6102
#define ID_BUTTONLOADT2 6103
#define ID_BUTTONSNAKETL2 6104
#define ID_BUTTONSNAKETR2 6105

#define ID_TIMERAPPNAME 15001
#define ID_TIMERSNAKEBEGIN 15002
#define ID_TIMERSNAKEEND 15003

#define ID_TIMERPLAY 20001
#define ID_TIMERPLAY2 20002
#define ID_TIMERSECOND 20003
#define ID_TIMERBACKCOUNT 20004
#define ID_TIMERBOMB 20005
#define ID_TIMEREXPLOSION 20006

#define ID_TIMERCREDITS 50001

HWND hEditWidthG, hEditHeightG;

ImgPrintRC PictBack;
ImgPrintRC PictBack2;
ImgPrintRC PictBackMask;

//������� ������
ImgPrint SnakeTexture_p;
ImgPrint SnakeTexture_p2;
ImgPrint SnakeTexture_p_2;
ImgPrint SnakeTexture_p2_2;

ImgPrintRC SnakeTexture_a;
ImgPrintRC SnakeTexture_a2;
ImgPrintRC SnakeTexture_b;
ImgPrintRC SnakeTexture_b2;
ImgPrintRC SnakeTexture_c;
ImgPrintRC SnakeTexture_c2;
ImgPrintRC SnakeTexture_d;
ImgPrintRC SnakeTexture_d2;
ImgPrintRC SnakeTexture_e;
ImgPrintRC SnakeTexture_e2;
ImgPrintRC SnakeTexture_f;
ImgPrintRC SnakeTexture_f2;

ImgPrintRC Wall_a;
ImgPrintRC Apple_a;
ImgPrintRC GoldApple_a;
ImgPrintRC Bomb_a;
ImgPrintRC Explosion;

//������� ����
ImgPrintRC PictPlay;
ImgPrintRC PictSettings;
ImgPrintRC PictHelp;
ImgPrintRC PictCredits;
ImgPrintRC PictExit;
ImgPrintRC PictSnake;
ImgPrintRC PictSnake2;

TextPrint Numbers("", 20, 97);
TextPrint Names("", 155, 97);
TextPrint Results("", 290, 97);

//������� ����
ImgPrintRC PictBPause;
ImgPrintRC PictBPlay;
ImgPrintRC PictBPauseMask;

//������� ��������
ImgPrintRC PictOk;
ImgPrintRC PictCancel;
ImgPrintRC PictOne;
ImgPrintRC PictTwo;
ImgPrintRC PictThree;
ImgPrintRC PictWASD;
ImgPrintRC PictULDR;
ImgPrintRC PictArrow;
ImgPrintRC PictArrow2;

//������� ������
//���
//������� ����������
ImgPrintRC PictCreditsList;
ImgPrintRC PictSBstudio;

//������� ���� ������ ������
ImgPrintRC PictClassic;
ImgPrintRC PictAdvanced;
ImgPrintRC PictTime;
ImgPrintRC PictCustom;
ImgPrintRC PictSettingM;
ImgPrintRC PictP1;
ImgPrintRC PictP2;

HANDLE hBitmapWall_a, hBitmapApple_a, hBitmapGoldApple_a, hBitmapBomb_a, hBitmapDetonate1, hBitmapDetonate2, hBitmapDetonate3;
HANDLE hBitmapBack, hBitmapBackMask;
HANDLE hBitmapPlay, hBitmapSettings, hBitmapHelp, hBitmapCredits, hBitmapExit;
HANDLE hBitmapClassic, hBitmapAdvanced, hBitmapTime, hBitmapCustom, hBitmapSettingM, hBitmapP1, hBitmapP2;
HANDLE hBitmapPauseMask;
HANDLE hBitmapOk, hBitmapCancel, hBitmapOne, hBitmapTwo, hBitmapThree, hBitmapWASD, hBitmapULDR;