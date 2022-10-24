#include "functions.h"
#include "defines2.h"

bool RegWndClass(HINSTANCE, WNDPROC, LPCTSTR);

LRESULT CALLBACK WndProcMain(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK WndProcPlay(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK WndProcSettings(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK WndProcSettings2(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK WndProcHelp(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK WndProcCredits(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK WndProcPlayMenu(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK WndProcSettingAdvanced(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK WndProcSettingP2(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK WndProcCustom(HWND, UINT, WPARAM, LPARAM);
char chClassName1[] = "WindClassMain";
char chClassName2[] = "WindClassPlay";
char chClassName3[] = "WindClassSettings";
char chClassName3_2[] = "WindClassSettings2";
char chClassName4[] = "WindClassHelp";
char chClassName5[] = "WindClassCredits";
char chClassName6[] = "WindClassPlayMenu";
char chClassName7[] = "WindClassSettingAdcvanced";
char chClassName10[] = "WindClassSettingP2";
char chClassName11[] = "WindClassCustom";

HINSTANCE GlobalhInst;
char version[] = "SNAKE v 4.0.0";

SnakeTexture SnakeP;
SnakeTexture SnakeP2;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   LPSTR lpszCmdLine, int nCmdShow) {
  GlobalhInst = hInstance;
  srand(time(NULL));

PictBackMask.init(hInstance, "picture_back_mask", 0, 0);
PictBackMask.load();

PictBack.init(hInstance, "picture_back", 0, 0);
PictBack.load();
PictBack.get_himg(&hBitmapBack);

PictBack2.init(hInstance, "picture_back2", 0, 0);
PictBack2.load();
PictBackMask.get_himg(&hBitmapBackMask);
PictBack2.set_mask(hBitmapBackMask, TRUE);

//объекты змейки
SnakeTexture_a.init(hInstance, "snake_t_a", 0, 0);
SnakeTexture_a2.init(hInstance, "snake_t_a", 0, 0);
SnakeTexture_b.init(hInstance, "snake_t_b", 0, 0);
SnakeTexture_b2.init(hInstance, "snake_t_b", 0, 0);
SnakeTexture_c.init(hInstance, "snake_t_c", 0, 0);
SnakeTexture_c2.init(hInstance, "snake_t_c", 0, 0);
SnakeTexture_d.init(hInstance, "snake_t_d", 0, 0);
SnakeTexture_d2.init(hInstance, "snake_t_d", 0, 0);
SnakeTexture_e.init(hInstance, "snake_t_e", 0, 0);
SnakeTexture_e2.init(hInstance, "snake_t_e", 0, 0);
SnakeTexture_f.init(hInstance, "snake_t_f", 0, 0);
SnakeTexture_f2.init(hInstance, "snake_t_f", 0, 0);


Wall_a.init(hInstance, "wall_a", 0, 0);
Apple_a.init(hInstance, "apple_a", 0, 0);
GoldApple_a.init(hInstance, "goldapple_a", 0, 0);
Bomb_a.init(hInstance, "bomb_a", 0, 0);
Explosion.init(hInstance, "detonate", 0, 0);

SnakeTexture_a.load();
SnakeTexture_a2.load();
SnakeTexture_b.load();
SnakeTexture_b2.load();
SnakeTexture_c.load();
SnakeTexture_c2.load();
SnakeTexture_d.load();
SnakeTexture_d2.load();
SnakeTexture_e.load();
SnakeTexture_e2.load();
SnakeTexture_f.load();
SnakeTexture_f2.load();

Wall_a.load();
Apple_a.load();
GoldApple_a.load();
Bomb_a.load();
Explosion.load();

Wall_a.get_himg(&hBitmapWall_a);
Apple_a.get_himg(&hBitmapApple_a);
GoldApple_a.get_himg(&hBitmapGoldApple_a);
Bomb_a.get_himg(&hBitmapBomb_a);
Bomb_a.set_mask(LoadBitmap(hInstance, "bomb_mask"), 1);
//

//Объекты окна меню
PictPlay.init(hInstance, "picture_play", 0, 0);
PictSettings.init(hInstance, "picture_settings", 0, 0);
PictHelp.init(hInstance, "picture_help", 0, 0);
PictCredits.init(hInstance, "picture_credits", 0, 0);
PictExit.init(hInstance, "picture_exit", 0, 0);
PictSnake.init(hInstance, "picture_snake", 0, 0);
PictSnake2.init(hInstance, "picture_snake2", 0, 0);

PictPlay.load();
PictSettings.load();
PictHelp.load();
PictCredits.load();
PictExit.load();
PictSnake.load();
PictSnake2.load();

PictPlay.get_himg(&hBitmapPlay);
PictSettings.get_himg(&hBitmapSettings);
PictHelp.get_himg(&hBitmapHelp);
PictCredits.get_himg(&hBitmapCredits);
PictExit.get_himg(&hBitmapExit);
//

//объекты окна игры
PictBPause.init(hInstance, "button_pause", 0, 0);
PictBPlay.init(hInstance, "button_play", 0, 0);
PictBPauseMask.init(hInstance, "button_pause_mask", 0, 0);

PictBPause.load();
PictBPlay.load();
PictBPauseMask.load();

PictBPauseMask.get_himg(&hBitmapPauseMask);

PictBPause.set_mask(hBitmapPauseMask, TRUE);
PictBPlay.set_mask(hBitmapPauseMask, TRUE);
//

//объекты окна настроек
PictOk.init(hInstance, "picture_ok", 0, 0);
PictCancel.init(hInstance, "picture_cancel", 0, 0);
PictOne.init(hInstance, "picture_one", 0, 0);
PictTwo.init(hInstance, "picture_two", 0, 0);
PictThree.init(hInstance, "picture_three", 0, 0);
PictWASD.init(hInstance, "picture_wasd", 0, 0);
PictULDR.init(hInstance, "picture_uldr", 0, 0);
PictArrow.init(hInstance, "picture_arrow", 0, 0);
PictArrow2.init(hInstance, "picture_arrow2", 0, 0);

PictOk.load();
PictCancel.load();
PictOne.load();
PictTwo.load();
PictThree.load();
PictWASD.load();
PictULDR.load();
PictArrow.load();
PictArrow2.load();

PictOk.get_himg(&hBitmapOk);
PictCancel.get_himg(&hBitmapCancel);
PictOne.get_himg(&hBitmapOne);
PictTwo.get_himg(&hBitmapTwo);
PictThree.get_himg(&hBitmapThree);
PictWASD.get_himg(&hBitmapWASD);
PictULDR.get_himg(&hBitmapULDR);
//

//объекты помощи
//нет

//объекты создателей
PictCreditsList.init(hInstance, "credits_list", 0, 0);
PictSBstudio.init(hInstance, "SBstudio", 0, 0);

PictCreditsList.load();
PictSBstudio.load();
//

//объекты меню выбора режима
PictClassic.init(hInstance, "picture_classic", 0, 0);
PictAdvanced.init(hInstance, "picture_advanced", 0, 0);
PictTime.init(hInstance, "picture_time", 0, 0);
PictCustom.init(hInstance, "picture_custom", 0, 0);
PictSettingM.init(hInstance, "picture_settingm", 0, 0);
PictP1.init(hInstance, "p1", 0, 0);
PictP2.init(hInstance, "p2", 0, 0);

PictClassic.load();
PictAdvanced.load();
PictTime.load();
PictCustom.load();
PictSettingM.load();
PictP1.load();
PictP2.load();

PictClassic.get_himg(&hBitmapClassic);
PictAdvanced.get_himg(&hBitmapAdvanced);
PictTime.get_himg(&hBitmapTime);
PictCustom.get_himg(&hBitmapCustom);
PictSettingM.get_himg(&hBitmapSettingM);
PictP1.get_himg(&hBitmapP1);
PictP2.get_himg(&hBitmapP2);
//

  if (! RegWndClass(hInstance, WndProcMain, chClassName1))
    return 0;
  if (! RegWndClass(hInstance, WndProcPlay, chClassName2))
    return 0;
  if (! RegWndClass(hInstance, WndProcSettings, chClassName3))
    return 0;
  if (! RegWndClass(hInstance, WndProcSettings2, chClassName3_2))
    return 0;
  if (! RegWndClass(hInstance, WndProcHelp, chClassName4))
    return 0;
  if (! RegWndClass(hInstance, WndProcCredits, chClassName5))
    return 0;
  if (! RegWndClass(hInstance, WndProcPlayMenu, chClassName6))
    return 0;
  if (! RegWndClass(hInstance, WndProcSettingAdvanced, chClassName7))
    return 0;
  if (! RegWndClass(hInstance, WndProcSettingP2, chClassName10))
    return 0;
  if (! RegWndClass(hInstance, WndProcCustom, chClassName11))
    return 0;

  HWND hWnd1, hWnd2, hWnd3, hWnd3_2, hWnd4, hWnd5, hWnd6, hWnd7, hWnd10, hWnd11;
//Меню
  hWnd1 = CreateWindow(chClassName1, version,
                        WS_OVERLAPPEDWINDOW|WS_CLIPCHILDREN,
                        CW_USEDEFAULT, CW_USEDEFAULT,
                        850, 570,
                        0, 0, hInstance, NULL);
  ShowWindow(hWnd1, SW_SHOWNORMAL);
//игра
  hWnd2 = CreateWindow(chClassName2, version,
                        WS_OVERLAPPED|WS_CAPTION|WS_SYSMENU|WS_THICKFRAME|WS_MINIMIZEBOX
                        |WS_CLIPCHILDREN,
                        CW_USEDEFAULT, CW_USEDEFAULT,
                        850, 570,
                        0, 0, hInstance, NULL);
//Настройки
  hWnd3 = CreateWindow(chClassName3, version,
                        WS_OVERLAPPED|WS_CAPTION|WS_SYSMENU|WS_THICKFRAME|WS_MINIMIZEBOX
                        |WS_CLIPCHILDREN,
                        CW_USEDEFAULT, CW_USEDEFAULT,
                        850, 570,
                        0, 0, hInstance, NULL);

  hWnd3_2 = CreateWindow(chClassName3_2, version,
                        WS_OVERLAPPED|WS_CAPTION|WS_SYSMENU|WS_THICKFRAME|WS_MINIMIZEBOX
                        |WS_CLIPCHILDREN,
                        CW_USEDEFAULT, CW_USEDEFAULT,
                        850, 570,
                        0, 0, hInstance, NULL);
//помощь
  hWnd4 = CreateWindow(chClassName4, version,
                        WS_OVERLAPPED|WS_CAPTION|WS_SYSMENU|WS_THICKFRAME|WS_MINIMIZEBOX
                        |WS_CLIPCHILDREN,
                        CW_USEDEFAULT, CW_USEDEFAULT,
                        850, 570,
                        0, 0, hInstance, NULL);
//создатели
  hWnd5 = CreateWindow(chClassName5, version,
                        WS_OVERLAPPED|WS_CAPTION|WS_SYSMENU|WS_THICKFRAME|WS_MINIMIZEBOX
                        |WS_CLIPCHILDREN,
                        CW_USEDEFAULT, CW_USEDEFAULT,
                        850, 570,
                        0, 0, hInstance, NULL);
//выбор режима игры
  hWnd6 = CreateWindow(chClassName6, version,
                        WS_OVERLAPPED|WS_CAPTION|WS_SYSMENU|WS_THICKFRAME|WS_MINIMIZEBOX
                        |WS_CLIPCHILDREN,
                        CW_USEDEFAULT, CW_USEDEFAULT,
                        850, 570,
                        0, 0, hInstance, NULL);
//настройка режима advanced
  hWnd7 = CreateWindow(chClassName7, version,
                        WS_OVERLAPPED|WS_CAPTION|WS_SYSMENU|WS_THICKFRAME|WS_MINIMIZEBOX
                        |WS_CLIPCHILDREN,
                        CW_USEDEFAULT, CW_USEDEFAULT,
                        850, 570,
                        0, 0, hInstance, NULL);
//настройка второго игрока
  hWnd10 = CreateWindow(chClassName10, version,
                        WS_OVERLAPPED|WS_CAPTION|WS_SYSMENU|WS_THICKFRAME|WS_MINIMIZEBOX
                        |WS_CLIPCHILDREN,
                        CW_USEDEFAULT, CW_USEDEFAULT,
                        850, 570,
                        0, 0, GlobalhInst, NULL);
//окно создания карты
  hWnd11 = CreateWindow(chClassName11, version,
                        WS_OVERLAPPED|WS_CAPTION|WS_SYSMENU|WS_THICKFRAME|WS_MINIMIZEBOX
                        |WS_CLIPCHILDREN,
                        CW_USEDEFAULT, CW_USEDEFAULT,
                        850, 570,
                        0, LoadMenu(hInstance, "CustomMenu"), GlobalhInst, NULL);

  MSG msg;
  while(GetMessage(&msg, 0, 0, 0)) {
    DispatchMessage(&msg);
    TranslateMessage(&msg);
  }
  return msg.wParam;
}

bool RegWndClass(HINSTANCE hInst, WNDPROC WindowProc, LPCTSTR szClassName) {
  WNDCLASS wc;
  wc.lpfnWndProc = (WNDPROC)WindowProc;
  wc.style = CS_HREDRAW | CS_VREDRAW;
  wc.cbClsExtra = wc.cbWndExtra = 0;
  wc.hInstance = hInst;
  wc.hIcon = LoadIcon(hInst, "icon");
  wc.hCursor = LoadCursor(NULL, IDC_ARROW);
  wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
  wc.lpszMenuName = (LPCTSTR)NULL;
  wc.lpszClassName = szClassName;
  return RegisterClass(&wc);
}

LRESULT CALLBACK WndProcMain(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
static HWND hButtonPlay, hButtonSettings, hButtonHelp, hButtonCredits, hButtonExit, hButtonRemove;
static HWND hButtonRRes, hButtonLRes;

HWND hWndOther;//Дескриптор окна, в которое осуществляется переход

HFONT hFont;
HBRUSH hBrush, hBrush2;
RECT rc, rco;//окна, другого окна

static int timer1Iter = 0;//состояние анимированной надписи

switch(msg) {
  case WM_CREATE:
    GetClientRect(hWnd, &rc);

    hButtonPlay = CreateWindow("button", NULL,
                               WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_BITMAP,
                               rc.right/2 - 100, 50, 200, 50,
                               hWnd, (HMENU)ID_BUTTONPLAY, GlobalhInst, NULL);
    SendMessage(hButtonPlay, BM_SETIMAGE, IMAGE_BITMAP, LPARAM(hBitmapPlay));

    hButtonSettings = CreateWindow("button", NULL,
                               WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_BITMAP,
                               rc.right/2 - 100, 120, 200, 50,
                               hWnd, (HMENU)ID_BUTTONSETTINGS, GlobalhInst, NULL);
    SendMessage(hButtonSettings, BM_SETIMAGE, IMAGE_BITMAP, LPARAM(hBitmapSettings));

    hButtonHelp = CreateWindow("button", NULL,
                               WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_BITMAP,
                               rc.right/2 - 100, 190, 200, 50,
                               hWnd, (HMENU)ID_BUTTONHELP, GlobalhInst, NULL);
    SendMessage(hButtonHelp, BM_SETIMAGE, IMAGE_BITMAP, LPARAM(hBitmapHelp));

    hButtonCredits = CreateWindow("button", NULL,
                               WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_BITMAP,
                               rc.right/2 - 100, 260, 200, 50,
                               hWnd, (HMENU)ID_BUTTONCREDITS, GlobalhInst, NULL);
    SendMessage(hButtonCredits, BM_SETIMAGE, IMAGE_BITMAP, LPARAM(hBitmapCredits));

    hButtonExit = CreateWindow("button", NULL,
                               WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_BITMAP,
                               rc.right/2 - 100, 330, 200, 50,
                               hWnd, (HMENU)ID_BUTTONEXIT, GlobalhInst, NULL);
    SendMessage(hButtonExit, BM_SETIMAGE, IMAGE_BITMAP, LPARAM(hBitmapExit));

    hButtonRemove = CreateWindow("button", "Стереть результаты",
                                WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                                80, 385, 150, 30,
                                hWnd, (HMENU)ID_BUTTONREMOVE, GlobalhInst, NULL);

    hButtonRRes = CreateWindow("button", ">",
                                WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                                235, 385, 20, 30,
                                hWnd, (HMENU)ID_BUTTONRRES, GlobalhInst, NULL);

    hButtonLRes = CreateWindow("button", "<",
                                WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                                55, 385, 20, 30,
                                hWnd, (HMENU)ID_BUTTONLRES, GlobalhInst, NULL);


//Таймеры анимации
    SetTimer(hWnd, ID_TIMERAPPNAME, 1000, NULL);
    SetTimer(hWnd, ID_TIMERSNAKEBEGIN, 3000, NULL);
    Sleep(100);
    SetTimer(hWnd, ID_TIMERSNAKEEND, 3000, NULL);
//загрузка результатов
    LoadResults(numbers, names, results, filenum);

    break;

  case WM_PAINT:
    int left, top;
    PAINTSTRUCT ps;
    HDC hdcOut, hdc;
    HANDLE hBitmapBuff;
    GetClientRect(hWnd, &rc);
    hFont = CreateFont(50,0,0,0,0,1,0,0,DEFAULT_CHARSET,0,0,0,0,"Arial Bold");
    hBrush = CreateSolidBrush(RGB(204,204,204));
    hBrush2 = CreateSolidBrush(RGB(255,255,255));

    hdcOut = BeginPaint(hWnd, &ps);
    hdc = CreateCompatibleDC(hdcOut);
    hBitmapBuff = CreateCompatibleBitmap(hdcOut, rc.right, rc.bottom);
    SelectObject(hdc, hBitmapBuff);
//фон
    SelectObject(hdc, hBrush);
    Rectangle(hdc, -1, -1, rc.right + 1, rc.bottom + 1);
    DeleteObject(hBrush);
//режим для текста
    SetTextColor(hdc, RGB(0, 0, 0));
    SetBkMode(hdc, TRANSPARENT);

    SetTextAlign(hdc, TA_CENTER);
    TextOut(hdc, rc.right/2, rc.bottom - 18, "All rights reserved. SBstudio © 2016.", 37);
//фон для результатов
    SelectObject(hdc, hBrush2);
    Rectangle(hdc, 15, 50, 295, 380);
    DeleteObject(hBrush2);

    TextOut(hdc, 155, 55, "Лучшие результаты:", 18);
    switch (filenum) {
      case 0:
        TextOut(hdc, 155, 72, "(classic)", 9);
        break;

      case 1:
        TextOut(hdc, 155, 72, "(advanced)", 10);
        break;

      case 2:
        TextOut(hdc, 155, 72, "(time)", 6);
        break;

      case 3:
        TextOut(hdc, 155, 72, "(custom)", 8);
        break;
    }
//результаты
    SetTextAlign(hdc, TA_LEFT);
    Numbers.set_text(numbers);
    SetTextColor(hdc, RGB(255, 215, 0));
    Numbers.set_start_pos(1);
    Numbers.print_str(hdc);
    SetTextColor(hdc, RGB(192, 192, 192));
    Numbers.get_pos(&left, &top);
    Numbers.set_pos(left, top + 17);
    Numbers.set_start_pos(2);
    Numbers.print_str(hdc);
    SetTextColor(hdc, RGB(205, 127, 50));
    Numbers.get_pos(&left, &top);
    Numbers.set_pos(left, top + 17);
    Numbers.set_start_pos(3);
    Numbers.print_str(hdc);
    SetTextColor(hdc, RGB(0, 0, 0));
    Numbers.get_pos(&left, &top);
    Numbers.set_pos(left, top + 17);
    Numbers.set_start_pos(4);
    Numbers.print(hdc);
    Numbers.set_pos(20, 97);

    SetTextAlign(hdc, TA_CENTER);
    Names.set_text(names);
    if (strcmp(names, "Нет результатов") == 0)
      SetTextColor(hdc, RGB(0, 0, 0));
    else
      SetTextColor(hdc, RGB(255, 215, 0));
    Names.set_start_pos(1);
    Names.print_str(hdc);
    SetTextColor(hdc, RGB(192, 192, 192));
    Names.get_pos(&left, &top);
    Names.set_pos(left, top + 17);
    Names.set_start_pos(2);
    Names.print_str(hdc);
    SetTextColor(hdc, RGB(205, 127, 50));
    Names.get_pos(&left, &top);
    Names.set_pos(left, top + 17);
    Names.set_start_pos(3);
    Names.print_str(hdc);
    SetTextColor(hdc, RGB(0, 0, 0));
    Names.get_pos(&left, &top);
    Names.set_pos(left, top + 17);
    Names.set_start_pos(4);
    Names.print(hdc);
    Names.set_pos(155, 97);

    SetTextAlign(hdc, TA_RIGHT);
    Results.set_text(results);
    SetTextColor(hdc, RGB(255, 215, 0));
    Results.set_start_pos(1);
    Results.print_str(hdc);
    SetTextColor(hdc, RGB(192, 192, 192));
    Results.get_pos(&left, &top);
    Results.set_pos(left, top + 17);
    Results.set_start_pos(2);
    Results.print_str(hdc);
    SetTextColor(hdc, RGB(205, 127, 50));
    Results.get_pos(&left, &top);
    Results.set_pos(left, top + 17);
    Results.set_start_pos(3);
    Results.print_str(hdc);
    SetTextColor(hdc, RGB(0, 0, 0));
    Results.get_pos(&left, &top);
    Results.set_pos(left, top + 17);
    Results.set_start_pos(4);
    Results.print(hdc);
    Results.set_pos(290, 97);

//анимированная надпись
    SetTextAlign(hdc, TA_LEFT);
    SetTextColor(hdc, RGB(255, 0, 0));
    SelectObject(hdc, hFont);
    TextOut(hdc, rc.right - 295, 50, version, 13);
    DeleteObject(hFont);
//анимированная змея
    PictSnake.set_pos(rc.right - 219, 160);
    PictSnake.print_std(hdc);

    BitBlt(hdcOut, 0, 0, rc.right, rc.bottom, hdc, 0, 0, SRCCOPY);

    DeleteObject(hBitmapBuff);
    DeleteDC(hdc);
    EndPaint(hWnd, &ps);
    break;

  case WM_ERASEBKGND:
    break;

  case WM_COMMAND://переход в другие окна
    switch(LOWORD(wParam)) {
      case ID_BUTTONPLAY:
        hWndOther = FindWindow(chClassName6, NULL);
        GetWindowRect(hWnd, &rco);
        MoveWindow(hWndOther, rco.left, rco.top,
                   rco.right - rco.left, rco.bottom - rco.top, TRUE);
        ShowWindow(hWndOther, SW_SHOW);
        ShowWindow(hWnd, SW_HIDE);
        break;

      case ID_BUTTONSETTINGS:
        hWndOther = FindWindow(chClassName3, NULL);
        GetWindowRect(hWnd, &rco);
        MoveWindow(hWndOther, rco.left, rco.top,
                   rco.right - rco.left, rco.bottom - rco.top, TRUE);
        ShowWindow(hWndOther, SW_SHOW);
        ShowWindow(hWnd, SW_HIDE);
        break;

      case ID_BUTTONHELP:
        hWndOther = FindWindow(chClassName4, NULL);
        GetWindowRect(hWnd, &rco);
        MoveWindow(hWndOther, rco.left, rco.top,
                   rco.right - rco.left, rco.bottom - rco.top, TRUE);
        ShowWindow(hWndOther, SW_SHOW);
        ShowWindow(hWnd, SW_HIDE);
        break;

      case ID_BUTTONCREDITS:
        hWndOther = FindWindow(chClassName5, NULL);
        GetWindowRect(hWnd, &rco);
        MoveWindow(hWndOther, rco.left, rco.top,
                   rco.right - rco.left, rco.bottom - rco.top, TRUE);
        ShowWindow(hWndOther, SW_SHOW);
        ShowWindow(hWnd, SW_HIDE);

        SetTimer(hWndOther, ID_TIMERCREDITS, 20, NULL);
        break;

      case ID_BUTTONEXIT:
        PostQuitMessage(0);
        break;

      case ID_BUTTONREMOVE:
        int choose;
        choose = 0;
        char filename[100];

        switch (filenum) {
          case 0:
            strcpy(filename, "C:\\SBstudio\\Snake\\snake_results_classic.txt");
            break;

          case 1:
            strcpy(filename, "C:\\SBstudio\\Snake\\snake_results_advanced.txt");
            break;

          case 2:
            strcpy(filename, "C:\\SBstudio\\Snake\\snake_results_time.txt");
            break;

          case 3:
            strcpy(filename, "C:\\SBstudio\\Snake\\snake_results_custom.txt");
            break;
        }
        choose = MessageBox(hWnd, "Стереть результаты?", "Подтверждение", MB_OKCANCEL|MB_ICONQUESTION);
        if (choose == IDOK) {
          remove(filename);
          LoadResults(numbers, names, results, filenum);
        }
        InvalidateRect(hWnd, NULL, TRUE);
        break;

      case ID_BUTTONRRES:
        if (filenum != 3)
          filenum++;
        else
          filenum = 0;
        LoadResults(numbers, names, results, filenum);
        InvalidateRect(hWnd, NULL, TRUE);
        break;

      case ID_BUTTONLRES:
        if (filenum != 0)
          filenum--;
        else
          filenum = 3;
        LoadResults(numbers, names, results, filenum);
        InvalidateRect(hWnd, NULL, TRUE);
        break;
    }

  case WM_TIMER:
    HDC hdct;
    GetClientRect(hWnd, &rc);
    hFont = CreateFont(50,0,0,0,0,1,0,0,DEFAULT_CHARSET,0,0,0,0,"Arial Bold");

    switch(LOWORD(wParam)) {
      case ID_TIMERAPPNAME://анимация надписи
        switch(timer1Iter) {
          case 0:
            hdct = GetDC(hWnd);
            SetBkMode(hdct, TRANSPARENT);
            SetTextColor(hdct, RGB(0,255,0));
            SelectObject(hdct, hFont);
            TextOut(hdct, rc.right - 295, 50, version, 13);
            DeleteObject(hFont);
            ReleaseDC(hWnd, hdct);
            timer1Iter = 1;
            break;

          case 1:
            hdct = GetDC(hWnd);
            SetBkMode(hdct, TRANSPARENT);
            SetTextColor(hdct, RGB(0,0,255));
            SelectObject(hdct, hFont);
            TextOut(hdct, rc.right - 295, 50, version, 13);
            DeleteObject(hFont);
            ReleaseDC(hWnd, hdct);
            timer1Iter = 2;
            break;

          case 2:
            hdct = GetDC(hWnd);
            SetBkMode(hdct, TRANSPARENT);
            SetTextColor(hdct, RGB(255,0,0));
            SelectObject(hdct, hFont);
            TextOut(hdct, rc.right - 295, 50, version, 13);
            DeleteObject(hFont);
            ReleaseDC(hWnd, hdct);
            timer1Iter = 0;
            break;
        }
      break;

      case ID_TIMERSNAKEBEGIN://анимация змейки
        hdct = GetDC(hWnd);
        PictSnake2.set_pos(rc.right - 219, 160);
        PictSnake2.print_std(hdct);
        ReleaseDC(hWnd, hdct);
        break;

      case ID_TIMERSNAKEEND:
        hdct = GetDC(hWnd);
        PictSnake.set_pos(rc.right - 219, 160);
        PictSnake.print_std(hdct);
        ReleaseDC(hWnd, hdct);
        break;
    }
    break;

  case WM_SIZE://движение кнопок
    GetClientRect(hWnd, &rc);
    MoveWindow(hButtonPlay, rc.right/2 - 100, 50, 200, 50, TRUE);
    MoveWindow(hButtonSettings, rc.right/2 - 100, 120, 200, 50, TRUE);
    MoveWindow(hButtonHelp, rc.right/2 - 100, 190, 200, 50, TRUE);
    MoveWindow(hButtonCredits, rc.right/2 - 100, 260, 200, 50, TRUE);
    MoveWindow(hButtonExit, rc.right/2 - 100, 330, 200, 50, TRUE);
    break;

  case WM_GETMINMAXINFO:
    ((MINMAXINFO *)lParam)->ptMinTrackSize.x = 850;
    ((MINMAXINFO *)lParam)->ptMinTrackSize.y = 570;
  break;

  case WM_DESTROY:
    PostQuitMessage(0);
    break;

  default:
    return DefWindowProc(hWnd, msg, wParam, lParam);
}
return 0;
}

LRESULT CALLBACK WndProcPlay(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
//переменные игры
static bool GameOver = 0, OutGameOver = 0, field_setup = 0; // Окончание игры
static int appleX, appleY; // Координаты яблока
static bool IsGoldApple = 0;//наличие золотого яблока
static bool IsBomb = 0;//наличие бомбы
static int GoldAppleX, GoldAppleY;
static int BombX, BombY;
static int BombPos = 0;
static int Time;

static int TimeGoldAppleRespawn = 5;//только в advanced-режиме
static int TimeAppleRespawn = 5;//только в time-режиме

// Settings переменные
static bool pause = 0;
static int BackCount = 4;

char chTime[11];

//управление
SnakeMain *ptWASD, *ptULDR;

//вывод текста в конце игры
char OverText[81];
TextPrint OverPrint;

//Отрисовка взрывов;
static vector<Detonate> vecd;

static SnakeTexture Snake1, Snake2, Snake3, Snake4, Snake5, Snake6;

HWND hWndMain;

RECT rc, rco;
static HBRUSH hBrush, hBrush2;
static HFONT hFont;

switch(msg) {
  case WM_CREATE:
    Snake1.Body = &SnakeTexture_a;
    Snake1.Head = &SnakeTexture_a2;

    Snake2.Body = &SnakeTexture_b;
    Snake2.Head = &SnakeTexture_b2;

    Snake3.Body = &SnakeTexture_c;
    Snake3.Head = &SnakeTexture_c2;

    Snake4.Body = &SnakeTexture_d;
    Snake4.Head = &SnakeTexture_d2;

    Snake5.Body = &SnakeTexture_e;
    Snake5.Head = &SnakeTexture_e2;

    Snake6.Body = &SnakeTexture_f;
    Snake6.Head = &SnakeTexture_f2;
    break;

  case WM_PAINT:
    PAINTSTRUCT ps;
    HDC hdcOut, hdc;
    HANDLE hBitmapBuff;
    GetClientRect(hWnd, &rc);
    hBrush = CreateSolidBrush(RGB(0, 0, 128));
    hBrush2 = CreateSolidBrush(RGB(255, 255, 255));
    hFont = CreateFont(60,0,0,0,1,0,0,0,DEFAULT_CHARSET,0,0,0,0,"Arial Bold");

    hdcOut = BeginPaint(hWnd, &ps);
    hdc = CreateCompatibleDC(hdcOut);
    hBitmapBuff = CreateCompatibleBitmap(hdcOut, rc.right, rc.bottom);
    SelectObject(hdc, hBitmapBuff);
//фон
    SelectObject(hdc, hBrush);
    Rectangle(hdc, -1, -1, rc.right + 1, rc.bottom + 1);
    DeleteObject(hBrush);
    SelectObject(hdc, hBrush2);
    Rectangle(hdc, rc.right/2 - (widthX/2 + 1)*20, 40, rc.right/2 + (widthX/2 + 1)*20, 30 + (heightY + 2)*20);
    Rectangle(hdc, rc.right/2 - (widthX/2 + 1)*20 - 1, 40 + (heightY + 2)*20 - 1, rc.right/2 + (widthX/2 + 1)*20, 91 + (heightY + 2)*20);
    DeleteObject(hBrush2);

    for (int i = vecd.size() - 1; i >= 0; i--) {
      if (vecd[i].state == 10) {
        Explosion.set_cut(0, 0, 118, 118);
        Explosion.set_pos(rc.right/2 - (widthX/2 + 1)*20 + vecd[i].BombX*20 - 49, 40 + vecd[i].BombY*20 - 49);
        Explosion.print_std(hdc);
      }

      if (vecd[i].state == 9) {
        Explosion.set_cut(118, 0, 118, 118);
        Explosion.set_pos(rc.right/2 - (widthX/2 + 1)*20 + vecd[i].BombX*20 - 49, 40 + vecd[i].BombY*20 - 49);
        Explosion.print_std(hdc);
      }

      if (vecd[i].state == 8) {
        Explosion.set_cut(236, 0, 118, 118);
        Explosion.set_pos(rc.right/2 - (widthX/2 + 1)*20 + vecd[i].BombX*20 - 49, 40 + vecd[i].BombY*20 - 49);
        Explosion.print_std(hdc);
      }
      
      if (vecd[i].state == 7) {
        Explosion.set_cut(354, 0, 118, 118);
        Explosion.set_pos(rc.right/2 - (widthX/2 + 1)*20 + vecd[i].BombX*20 - 49, 40 + vecd[i].BombY*20 - 49);
        Explosion.print_std(hdc);
      }
      
      if (vecd[i].state == 6) {
        Explosion.set_cut(472, 0, 118, 118);
        Explosion.set_pos(rc.right/2 - (widthX/2 + 1)*20 + vecd[i].BombX*20 - 49, 40 + vecd[i].BombY*20 - 49);
        Explosion.print_std(hdc);
      }
    }

/*
    if (vecd[vecd.size() - 2].state <= 0){
      vecd.pop_back();
    }
*/
    switch (SnakeT) {
      case -1:
        Draw(SnakeMain1.SumbHead, SnakeMain1.SumbBody, SnakeP, SnakeMain1._x, SnakeMain1._y, hdc, hWnd);
        break;

      case 0:
        Draw(SnakeMain1.SumbHead, SnakeMain1.SumbBody, Snake1, SnakeMain1._x, SnakeMain1._y, hdc, hWnd);
        break;

      case 1:
        Draw(SnakeMain1.SumbHead, SnakeMain1.SumbBody, Snake2, SnakeMain1._x, SnakeMain1._y, hdc, hWnd);
        break;

      case 2:
        Draw(SnakeMain1.SumbHead, SnakeMain1.SumbBody, Snake3, SnakeMain1._x, SnakeMain1._y, hdc, hWnd);
        break;

      case 3:
        Draw(SnakeMain1.SumbHead, SnakeMain1.SumbBody, Snake4, SnakeMain1._x, SnakeMain1._y, hdc, hWnd);
        break;

      case 4:
        Draw(SnakeMain1.SumbHead, SnakeMain1.SumbBody, Snake5, SnakeMain1._x, SnakeMain1._y, hdc, hWnd);
        break;

      case 5:
        Draw(SnakeMain1.SumbHead, SnakeMain1.SumbBody, Snake6, SnakeMain1._x, SnakeMain1._y, hdc, hWnd);
        break;
    }

    if (PlayerCount > 1)
    switch (SnakeT2) {
      case -1:
        Draw(SnakeMain2.SumbHead, SnakeMain2.SumbBody, SnakeP2, SnakeMain2._x, SnakeMain2._y, hdc, hWnd);
        break;

      case 0:
        Draw(SnakeMain2.SumbHead, SnakeMain2.SumbBody, Snake1, SnakeMain2._x, SnakeMain2._y, hdc, hWnd);
        break;

      case 1:
        Draw(SnakeMain2.SumbHead, SnakeMain2.SumbBody, Snake2, SnakeMain2._x, SnakeMain2._y, hdc, hWnd);
        break;

      case 2:
        Draw(SnakeMain2.SumbHead, SnakeMain2.SumbBody, Snake3, SnakeMain2._x, SnakeMain2._y, hdc, hWnd);
        break;

      case 3:
        Draw(SnakeMain2.SumbHead, SnakeMain2.SumbBody, Snake4, SnakeMain2._x, SnakeMain2._y, hdc, hWnd);
        break;

      case 4:
        Draw(SnakeMain2.SumbHead, SnakeMain2.SumbBody, Snake5, SnakeMain2._x, SnakeMain2._y, hdc, hWnd);
        break;

      case 5:
        Draw(SnakeMain2.SumbHead, SnakeMain2.SumbBody, Snake6, SnakeMain2._x, SnakeMain2._y, hdc, hWnd);
        break;
    }

    switch (PlayingRoutine) {
      case 0:
        Write(0, SnakeMain1.score, SnakeMain1.len, SnakeMain1.applec, hdc, hWnd);
        break;
        
      case 1:
      case 3:
        AdvancedWrite(0, SnakeMain1.score, SnakeMain1.len, SnakeMain1.applec, hdc, hWnd);
        break;

      case 2:
        TimeWrite(0, SnakeMain1.TimeToOver, SnakeMain1.score, SnakeMain1.len, SnakeMain1.applec, hdc, hWnd);
        break;
    }

    SetTextAlign(hdc, TA_RIGHT);
    if (PlayerCount > 1)
    switch (PlayingRoutine) {
      case 0:
        Write(1, SnakeMain2.score, SnakeMain2.len, SnakeMain2.applec, hdc, hWnd);
        break;
        
      case 1:
        AdvancedWrite(1, SnakeMain2.score, SnakeMain2.len, SnakeMain2.applec, hdc, hWnd);
        break;

      case 2:
        TimeWrite(1, SnakeMain2.TimeToOver, SnakeMain2.score, SnakeMain2.len, SnakeMain2.applec, hdc, hWnd);
        break;
    }
    
    SetTextAlign(hdc, TA_CENTER);
    if (PlayTime != 0) {
      char chTime[11];
      itoa(Time, chTime, 10);
      itoa(Time, chTime, 10);
      TextPrint Time(chTime, rc.right/2, 40 + (heightY + 2)*20);
      Time.print(hdc);
    }

//картинки (в последнюю очередь)
    if (pause == 0) {
      PictBPause.set_pos(rc.right - 47, 15);
      PictBPause.print_std(hdc); 
    } else {
      PictBack2.set_pos(30, 30);
      PictBack2.print_std(hdc);

      PictBPlay.set_pos(rc.right - 47, 15);
      PictBPlay.print_std(hdc);
    }
    SetTextAlign(hdc, TA_CENTER);
    SetBkMode(hdc, TRANSPARENT);

    SelectObject(hdc, hFont);
    switch (BackCount) {
      case 3:
        TextOut(hdc, rc.right/2, (heightY + 1) * 10, "3", 1);
        break;

      case 2:
        TextOut(hdc, rc.right/2, (heightY + 1) * 10, "2", 1);
        break;

      case 1:
        TextOut(hdc, rc.right/2, (heightY + 1) * 10, "1", 1);
        break;

      case 0:
        TextOut(hdc, rc.right/2, (heightY + 1) * 10, "GO", 2);
        break;
    }
    
    if (IsBomb){
      Bomb_a.set_pos(rc.right/2 - (widthX/2 + 1)*20 + BombX*20, BombPos - 40);
      Bomb_a.print_std(hdc);
    }

    if (GameOver == 1) {
      if (PlayerCount > 1) {
        if (SnakeMain2.GameOver) {
          SetTextColor(hdc, RGB(0, 0, 255));
          strcpy(OverText, "Победил ");
          strcat(OverText, PlayerName);
          strcat(OverText, "!");
          OverPrint.set_text(OverText);
          OverPrint.set_pos(rc.right/2, (heightY + 1) * 10);
          OverPrint.print(hdc);
        }
        if (SnakeMain1.GameOver) {
          SetTextColor(hdc, RGB(255, 0, 0));
          strcpy(OverText, "Победил ");
          strcat(OverText, PlayerName2);
          strcat(OverText, "!");
          OverPrint.set_text(OverText);
          OverPrint.set_pos(rc.right/2, (heightY + 1) * 10);
          OverPrint.print(hdc);
        }
      }
      else {
        strcpy(OverText, "GameOver");
        OverPrint.set_text(OverText);
        OverPrint.set_pos(rc.right/2, (heightY + 1) * 10);
        OverPrint.print(hdc);
      }
    }
    SetTextColor(hdc, RGB(0, 0, 0));
    DeleteObject(hFont);

    BitBlt(hdcOut, 0, 0, rc.right, rc.bottom, hdc, 0, 0, SRCCOPY);

    DeleteObject(hBitmapBuff);
    DeleteDC(hdc);
    EndPaint(hWnd, &ps);
    break;

  case WM_ERASEBKGND:
    break;

  case WM_LBUTTONDOWN:
    int xPos, yPos;
    xPos = LOWORD(lParam);
    yPos = HIWORD(lParam);
    GetClientRect(hWnd, &rc);

    if (pause == 0) {
      if (xPos > rc.right-47 && xPos < rc.right-15 && yPos > 15 && yPos < 47) {
        pause = 1;
        InvalidateRect(hWnd, NULL, TRUE);
      }
    } else {
      if (xPos > 30 && xPos < 78 && yPos > 30 && yPos < 78) {
        if (PlayingRoutine != 3)
          hWndMain = FindWindow(chClassName6, NULL);
        else
          hWndMain = FindWindow(chClassName11, NULL);
        GetWindowRect(hWnd, &rco);
        MoveWindow(hWndMain, rco.left, rco.top,
                   rco.right - rco.left, rco.bottom - rco.top, TRUE);
        ShowWindow(hWndMain, SW_SHOW);
        ShowWindow(hWnd, SW_HIDE);

        SnakeMain1.start_game = 0;
        SnakeMain1.GameOver = 0;
        if (PlayerCount > 1) {
          SnakeMain2.start_game = 0;
          SnakeMain2.GameOver = 0;
        }
        GameOver = 0;
        field_setup = 0;
        IsBomb = 0;
        vecd.clear();

        BackCount = 4;
        KillTimer(hWnd, ID_TIMERPLAY);
        if (PlayerCount > 1)
          KillTimer(hWnd, ID_TIMERPLAY2);
        KillTimer(hWnd, ID_TIMERBACKCOUNT);
      }

      if (xPos > rc.right-47 && xPos < rc.right-15 && yPos > 15 && yPos < 47) {
        if (GameOver) {
          SnakeMain1.start_game = 0;
          SnakeMain1.GameOver = 0;
          if (PlayerCount > 1) {
            SnakeMain2.start_game = 0;
            SnakeMain2.GameOver = 0;
          }
          GameOver = 0;
          field_setup = 0;
          IsBomb = 0;
          vecd.clear();
        }

        if (BackCount == 4)
          BackCount = 3;

        SetTimer(hWnd, ID_TIMERBACKCOUNT, 1000, NULL);
        InvalidateRect(hWnd, NULL, TRUE);
      }
    }
    break;

  case WM_TIMER:
    switch(LOWORD(wParam)) {
      case ID_TIMERPLAY:
        Cycle(hWnd, SnakeMain1, Time, appleX, appleY, GoldAppleX, GoldAppleY, IsGoldApple, TimeAppleRespawn, GameOver, OutGameOver, pause, field_setup, ID_TIMERPLAY, 0);
        break;

      case ID_TIMERPLAY2:
        Cycle(hWnd, SnakeMain2, Time, appleX, appleY, GoldAppleX, GoldAppleY, IsGoldApple, TimeAppleRespawn, GameOver, OutGameOver, pause, field_setup, ID_TIMERPLAY2, 1);
        break;

      case ID_TIMERSECOND:
        if (pause != 1) {
          if (Time <= 0) {
            OutGameOver = 1;
            if (PlayerCount > 1)
              if (SnakeMain1.score > SnakeMain2.score)
                SnakeMain2.GameOver = 1;
              else
                SnakeMain1.GameOver = 1;
          }
          if (PlayTime != 0 && Time > 0) {
            Time--;
          }
          
          switch (PlayingRoutine) {
            case 1:
            case 3:
              if (rand() % 10 == 1 && !IsGoldApple) {
                while (1) {
                  GoldAppleX = rand() % widthX + 1;
                  GoldAppleY = rand() % heightY + 1;

                  // ѕроверка на пустую ¤чейку
                  if (field[GoldAppleY][GoldAppleX] == ' ') {
                    field[GoldAppleY][GoldAppleX] = '$';
                    break;
                  }
                }
                IsGoldApple = 1;
                TimeGoldAppleRespawn = 5;
              }

              if (IsGoldApple)
                TimeGoldAppleRespawn--;
              
              if (TimeGoldAppleRespawn <= 0) {
                DestroyObjects(1);
                IsGoldApple = 0;
              }
              
              if (SnakeMain1.TimeEffect > 0)
                SnakeMain1.TimeEffect--;
              if (PlayerCount > 1)
                if (SnakeMain2.TimeEffect > 0)
                  SnakeMain2.TimeEffect--;

              if (rand() % 2 == 1 && ! IsBomb) {
                BombPos = 0;
                BombX = rand() % (widthX - 5) + 3;
                BombY = rand() % (heightY - 5) + 3;
                IsBomb = 1;
                SetTimer(hWnd, ID_TIMERBOMB, 10, NULL);
              }

              InvalidateRect(hWnd, NULL, TRUE);
              break;

            case 2:
              TimeAppleRespawn--;
              
              SnakeMain1.TimeToOver--;
              if (PlayerCount > 1)
                SnakeMain2.TimeToOver--;

              if (TimeAppleRespawn <= 0) {
                TimeAppleRespawn = 5;
              
                SnakeMain1.score -= 10;
                if (PlayerCount > 1)
                  SnakeMain2.score -= 10;

                DestroyObjects(0);
                GenerationObject(0, appleX, appleY);
              }
              InvalidateRect(hWnd, NULL, TRUE);
              break;
          }
        }
        break;

      case ID_TIMERBACKCOUNT:
        switch (BackCount) {
          case 3:
            BackCount = 2;
            InvalidateRect(hWnd, NULL, TRUE);
            break;

          case 2:
            BackCount = 1;
            InvalidateRect(hWnd, NULL, TRUE);
            break;

          case 1:
            BackCount = 0;
            InvalidateRect(hWnd, NULL, TRUE);
            break;

          case 0:
            BackCount = 4;
            pause = 0;
            KillTimer(hWnd, ID_TIMERBACKCOUNT);
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        }
        break;

      case ID_TIMERBOMB:
        if (IsBomb && ! pause) {
          if (BombPos >= BombY*20 + 40) {
            IsBomb = 0;
            Detonate dt;
            dt.BombX = BombX;
            dt.BombY = BombY;
            vecd.insert(vecd.begin(), dt);

            BombLogic(SnakeMain1, appleX, appleY, GoldAppleX, GoldAppleY, BombX, BombY, SnakeMain1.len, SnakeMain1.OldApplec, GameOver);
            if (PlayerCount > 1)
              BombLogic(SnakeMain2, appleX, appleY, GoldAppleX, GoldAppleY, BombX, BombY, SnakeMain2.len, SnakeMain2.OldApplec, GameOver);

            if (GameOver) {
              pause = 1;
              KillTimer(hWnd, ID_TIMERSECOND);
              KillTimer(hWnd, ID_TIMEREXPLOSION);
              if (Save == 1 && PlayerCount == 1) {
                SaveResults(SnakeMain1.score, PlayerName, PlayingRoutine);
                LoadResults(numbers, names, results, filenum);
              }
              InvalidateRect(hWnd, NULL, TRUE);
            }

            KillTimer(hWnd, ID_TIMERBOMB);
            break;
          }
          BombPos += 3;
        }

        RECT brc;
        brc.left = rc.right/2 - (widthX/2 + 1)*20 + BombX*20;
        brc.top = BombPos - 43;
        brc.right = brc.left + 23;
        brc.bottom = BombPos;
        InvalidateRect(hWnd, &brc, TRUE);
        break;
        
    case ID_TIMEREXPLOSION:
      for (int i = 0; i < vecd.size(); i++) {
        vecd[i].state--;
      }
      break;

    }
    break;
    
  case WM_KEYDOWN:
    switch (Control) {
      case 0:
        ptWASD = &SnakeMain1;
        ptULDR = &SnakeMain2;
        break;

      case 1:
        ptWASD = &SnakeMain2;
        ptULDR = &SnakeMain1;
        break;
    }
    if (! GameOver && ! pause)
    switch(LOWORD(wParam)) {
      case 65:
        if (! ptWASD->IsTap && ptWASD->_x != 1) {
          ptWASD->_x = -1;
          ptWASD->_y = 0;
        }
        ptWASD->IsTap = 1;
        break;

      case 87:
        if (! ptWASD->IsTap && ptWASD->_y != 1) {
          ptWASD->_x = 0;
          ptWASD->_y = -1;
        }
        ptWASD->IsTap = 1;
        break;

      case 68:
        if (! ptWASD->IsTap && ptWASD->_x != -1) {
          ptWASD->_x = 1;
          ptWASD->_y = 0;
        }
        ptWASD->IsTap = 1;
        break;

      case 83:
        if (! ptWASD->IsTap && ptWASD->_y != -1) {
          ptWASD->_x = 0;
          ptWASD->_y = 1;
        }
        ptWASD->IsTap = 1;
        break;
        
      case VK_LEFT:
        if (! ptULDR->IsTap && ptULDR->_x != 1) {
          ptULDR->_x = -1;
          ptULDR->_y = 0;
        }
        ptULDR->IsTap = 1;
        break;

      case VK_UP:
        if (! ptULDR->IsTap && ptULDR->_y != 1) {
          ptULDR->_x = 0;
          ptULDR->_y = -1;
        }
        ptULDR->IsTap = 1;
        break;

      case VK_RIGHT:
        if (! ptULDR->IsTap && ptULDR->_x != -1) {
          ptULDR->_x = 1;
          ptULDR->_y = 0;
        }
        ptULDR->IsTap = 1;
        break;

      case VK_DOWN:
        if (! ptULDR->IsTap && ptULDR->_y != -1) {
          ptULDR->_x = 0;
          ptULDR->_y = 1;
        }
        ptULDR->IsTap = 1;
        break;

      case VK_PAUSE:
        if (! pause) {
          pause = 1;
          InvalidateRect(hWnd, NULL, TRUE);
        }
        break;
    }
    break;

  case WM_SIZE:
    break;

  case WM_GETMINMAXINFO:
    ((MINMAXINFO *)lParam)->ptMinTrackSize.x = 850;
    ((MINMAXINFO *)lParam)->ptMinTrackSize.y = 570;
  break;

  case WM_DESTROY:
    PostQuitMessage(0);
    break;

  default:
    return DefWindowProc(hWnd, msg, wParam, lParam);
}
return 0;
}

LRESULT CALLBACK WndProcSettings(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
static HWND hEditUser, hButtonSave, hButtonWall, hButtonScross, hButtonAccelerate, hButtonSpeed, 
hButtonSnakeTL, hButtonSnakeTR, hButtonBack, hButtonBackMenu;

HWND hWndMain;//для перехода в главное окно

HFONT hFont, hFont2, hFont3;
HBRUSH hBrush, hBrush2;
RECT rc, rco;//окна, другого окна

switch(msg) {
  case WM_CREATE:
    SnakeSettings LS;

    if (LoadSettings(&LS)) {
      Save = LS.Save;
      walls = LS.walls;
      SCrossing = LS.SCrossing;
      Accelerate = LS.Accelerate;
      Speed = LS.Speed;
      SnakeT = LS.SnakeT;
      strcpy(PlayerName, LS.PlayerName);
    }

    GetClientRect(hWnd, &rc);
//для ввода имени игрока
    hEditUser = CreateWindow("edit", PlayerName,
                                WS_CHILD | WS_VISIBLE | WS_BORDER | ES_CENTER,
                                rc.right/2 - 150, 130, 300, 25,
                                hWnd, (HMENU)ID_EDITUSER, GlobalhInst, NULL);
    SendMessage(hEditUser, EM_LIMITTEXT, 15, 0);
//кнопки настроек (3)
    hButtonSave = CreateWindow("button", NULL,
                                WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_BITMAP,
                                30, 200, 64, 64,
                                hWnd, (HMENU)ID_BUTTONSAVE, GlobalhInst, NULL);
    if (Save)
      SendMessage(hButtonSave, BM_SETIMAGE, IMAGE_BITMAP, LPARAM(hBitmapOk));
    else
      SendMessage(hButtonSave, BM_SETIMAGE, IMAGE_BITMAP, LPARAM(hBitmapCancel));

    hButtonWall = CreateWindow("button", NULL,
                                WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_BITMAP,
                                30, 300, 64, 64,
                                hWnd, (HMENU)ID_BUTTONWALL, GlobalhInst, NULL);
    if (walls)
      SendMessage(hButtonWall, BM_SETIMAGE, IMAGE_BITMAP, LPARAM(hBitmapOk));
    else
      SendMessage(hButtonWall, BM_SETIMAGE, IMAGE_BITMAP, LPARAM(hBitmapCancel));

    hButtonScross = CreateWindow("button", NULL,
                                WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_BITMAP,
                                30, 400, 64, 64,
                                hWnd, (HMENU)ID_BUTTONSCROSS, GlobalhInst, NULL);
    if (SCrossing)
      SendMessage(hButtonScross, BM_SETIMAGE, IMAGE_BITMAP, LPARAM(hBitmapOk));
    else
      SendMessage(hButtonScross, BM_SETIMAGE, IMAGE_BITMAP, LPARAM(hBitmapCancel));

    hButtonAccelerate = CreateWindow("button", NULL,
                                WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_BITMAP,
                                rc.right - 94, 200, 64, 64,
                                hWnd, (HMENU)ID_BUTTONACCELERATE, GlobalhInst, NULL);
    if (Accelerate)
      SendMessage(hButtonAccelerate, BM_SETIMAGE, IMAGE_BITMAP, LPARAM(hBitmapOk));
    else
      SendMessage(hButtonAccelerate, BM_SETIMAGE, IMAGE_BITMAP, LPARAM(hBitmapCancel));

    hButtonSpeed = CreateWindow("button", NULL,
                                WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_BITMAP,
                                rc.right - 94, 300, 64, 64,
                                hWnd, (HMENU)ID_BUTTONSPEED, GlobalhInst, NULL);
    switch (Speed) {
      case 0:
        SendMessage(hButtonSpeed, BM_SETIMAGE, IMAGE_BITMAP, LPARAM(hBitmapOne));
        break;

      case 1:
        SendMessage(hButtonSpeed, BM_SETIMAGE, IMAGE_BITMAP, LPARAM(hBitmapTwo));
        break;

      case 2:
        SendMessage(hButtonSpeed, BM_SETIMAGE, IMAGE_BITMAP, LPARAM(hBitmapThree));
        break;
    }

    hButtonSnakeTL = CreateWindow("button", "<",
                                WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                                rc.right - 240, 400, 20, 80,
                                hWnd, (HMENU)ID_BUTTONSNAKETL, GlobalhInst, NULL);

    hButtonSnakeTR = CreateWindow("button", ">",
                                WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                                rc.right - 50, 400, 20, 80,
                                hWnd, (HMENU)ID_BUTTONSNAKETR, GlobalhInst, NULL);

//возврат в главное меню
    hButtonBack = CreateWindow("button", NULL,
                                WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_BITMAP,
                                30, 30, 48, 48,
                                hWnd, (HMENU)ID_BUTTONBACK, GlobalhInst, NULL);
    SendMessage(hButtonBack, BM_SETIMAGE, IMAGE_BITMAP, LPARAM(hBitmapBack));
    break;

  case WM_PAINT:
    PAINTSTRUCT ps;
    HDC hdcOut, hdc;
    HANDLE hBitmapBuff;
    GetClientRect(hWnd, &rc);
    hFont = CreateFont(60,0,0,0,1,0,0,0,DEFAULT_CHARSET,0,0,0,0,"Arial Bold");
    hFont2 = CreateFont(20,0,0,0,0,1,0,0,DEFAULT_CHARSET,0,0,0,0,"Arial Bold");
    hFont3 = CreateFont(20,0,0,0,0,1,1,0,DEFAULT_CHARSET,0,0,0,0,"Arial Bold");
    hBrush = CreateSolidBrush(RGB(204,204,204));
    hBrush2 = CreateSolidBrush(RGB(255,255,255));

    hdcOut = BeginPaint(hWnd, &ps);
    hdc = CreateCompatibleDC(hdcOut);
    hBitmapBuff = CreateCompatibleBitmap(hdcOut, rc.right, rc.bottom);
    SelectObject(hdc, hBitmapBuff);
//фон
    SelectObject(hdc, hBrush);
    Rectangle(hdc, -1, -1, rc.right + 1, rc.bottom + 1);
    DeleteObject(hBrush);

    SelectObject(hdc, hBrush2);
    Rectangle(hdc, rc.right - 216, 399, rc.right - 54, 481);
    DeleteObject(hBrush2);
//картинки
    PictArrow.set_pos(rc.right/2 + 160, 20);
    PictArrow.print_std(hdc);
//режим текста
    SetTextColor(hdc, RGB(0, 0, 0));
    SetBkMode(hdc, TRANSPARENT);

    SetTextAlign(hdc, TA_CENTER);
    TextOut(hdc, rc.right/2, rc.bottom - 18, "All rights reserved. SBstudio © 2016.", 37);

    SelectObject(hdc, hFont);
    TextOut(hdc, rc.right/2 , 20, "Настройки", 9);
    DeleteObject(hFont);
//надписи у кнопок настроек
    SetTextAlign(hdc, TA_LEFT);
    SelectObject(hdc, hFont3);
    TextOut(hdc, 114, 217, "Сохранять результаты", 20);
    DeleteObject(hFont3);
    SelectObject(hdc, hFont2);
    TextOut(hdc, 114, 317, "Стены", 5);
    TextOut(hdc, 114, 417, "Поражение при столкновении с хвостом", 36);
    SetTextAlign(hdc, TA_RIGHT);
    TextOut(hdc, rc.right - 114, 217, "Ускорение", 9);
    TextOut(hdc, rc.right - 114, 317, "Скорость змеи", 13);
    TextOut(hdc, rc.right - 260, 417, "Цвет змеи", 9);
    DeleteObject(hFont2);

    switch (SnakeT) {
      case -1:
        SnakeTexture_p.set_angle(0);
        SnakeTexture_p.set_cut(0,0,0,0);
        SnakeTexture_p.set_pos(rc.right - 215, 400);
        SnakeTexture_p.print_ex(hdc, 160, 80);
        break;

      case 0:
        SnakeTexture_a.set_angle(0);
        SnakeTexture_a.set_cut(0,0,0,0);
        SnakeTexture_a.set_pos(rc.right - 215, 400);
        SnakeTexture_a.print_ex(hdc, 160, 80);
        break;

      case 1:
        SnakeTexture_b.set_angle(0);
        SnakeTexture_b.set_cut(0,0,0,0);
        SnakeTexture_b.set_pos(rc.right - 215, 400);
        SnakeTexture_b.print_ex(hdc, 160, 80);
        break;

      case 2:
        SnakeTexture_c.set_angle(0);
        SnakeTexture_c.set_cut(0,0,0,0);
        SnakeTexture_c.set_pos(rc.right - 215, 400);
        SnakeTexture_c.print_ex(hdc, 160, 80);
        break;

      case 3:
        SnakeTexture_d.set_angle(0);
        SnakeTexture_d.set_cut(0,0,0,0);
        SnakeTexture_d.set_pos(rc.right - 215, 400);
        SnakeTexture_d.print_ex(hdc, 160, 80);
        break;

      case 4:
        SnakeTexture_e.set_angle(0);
        SnakeTexture_e.set_cut(0,0,0,0);
        SnakeTexture_e.set_pos(rc.right - 215, 400);
        SnakeTexture_e.print_ex(hdc, 160, 80);
        break;

      case 5:
        SnakeTexture_f.set_angle(0);
        SnakeTexture_f.set_cut(0,0,0,0);
        SnakeTexture_f.set_pos(rc.right - 215, 400);
        SnakeTexture_f.print_ex(hdc, 160, 80);
        break;
    }

    BitBlt(hdcOut, 0, 0, rc.right, rc.bottom, hdc, 0, 0, SRCCOPY);

    DeleteObject(hBitmapBuff);
    DeleteDC(hdc);
    EndPaint(hWnd, &ps);
    break;

  case WM_ERASEBKGND:
    break;

  case WM_LBUTTONDOWN:
    int xPos, yPos;
    xPos = LOWORD(lParam);
    yPos = HIWORD(lParam);
    GetClientRect(hWnd, &rc);

    if (xPos > rc.right/2 + 150 && xPos < rc.right/2 + 214 && yPos > 20 && yPos < 84) {
      hWndMain = FindWindow(chClassName3_2, NULL);
      GetWindowRect(hWnd, &rco);
      MoveWindow(hWndMain, rco.left, rco.top,
                   rco.right - rco.left, rco.bottom - rco.top, TRUE);
      ShowWindow(hWndMain, SW_SHOW);
      ShowWindow(hWnd, SW_HIDE);

      strcpy(PlayerName, "");
      GetWindowText(hEditUser, PlayerName, 99);
    }
    break;

  case WM_COMMAND:
    switch(LOWORD(wParam)) {
      case ID_BUTTONBACK://возврат в меню
        hWndMain = FindWindow(chClassName1, NULL);
        GetWindowRect(hWnd, &rco);
        MoveWindow(hWndMain, rco.left, rco.top,
                   rco.right - rco.left, rco.bottom - rco.top, TRUE);
        ShowWindow(hWndMain, SW_SHOW);
        ShowWindow(hWnd, SW_HIDE);

        strcpy(PlayerName, "");
        GetWindowText(hEditUser, PlayerName, 99);

        SnakeSettings SS;
        SS.Save = Save;
        SS.walls = walls;
        SS.SCrossing = SCrossing;
        SS.Accelerate = Accelerate;
        SS.Speed = Speed;
        SS.SnakeT = SnakeT;
        SS.Control = Control;
        SS.widthX = widthX;
        SS.heightY = heightY;
        SS.PlayTime = PlayTime;
        strcpy(SS.PlayerName, PlayerName);
        SaveSettings(SS);
        break;

//изменение состояний кнопок настроек
      case ID_BUTTONSAVE:
        if (Save) {
          SendMessage(hButtonSave, BM_SETIMAGE, IMAGE_BITMAP, LPARAM(hBitmapCancel));
          Save = FALSE;
        } else {
          SendMessage(hButtonSave, BM_SETIMAGE, IMAGE_BITMAP, LPARAM(hBitmapOk));
          Save = TRUE;
        }
        SendMessage(hButtonWall, BM_SETIMAGE, IMAGE_BITMAP, LPARAM(hBitmapOk));
        walls = TRUE;

        SendMessage(hButtonScross, BM_SETIMAGE, IMAGE_BITMAP, LPARAM(hBitmapOk));
        SCrossing = TRUE;

        SendMessage(hButtonAccelerate, BM_SETIMAGE, IMAGE_BITMAP, LPARAM(hBitmapOk));
        Accelerate = TRUE;

        if (Speed == 0) {
          SendMessage(hButtonSpeed, BM_SETIMAGE, IMAGE_BITMAP, LPARAM(hBitmapTwo));
          Speed = 1;
        }
        break;

      case ID_BUTTONWALL:
        if (walls) {
          SendMessage(hButtonWall, BM_SETIMAGE, IMAGE_BITMAP, LPARAM(hBitmapCancel));
          walls = FALSE;

          SendMessage(hButtonSave, BM_SETIMAGE, IMAGE_BITMAP, LPARAM(hBitmapCancel));
          Save = FALSE;
        } else {
          SendMessage(hButtonWall, BM_SETIMAGE, IMAGE_BITMAP, LPARAM(hBitmapOk));
          walls = TRUE;
        }
        break;

      case ID_BUTTONSCROSS:
        if (SCrossing) {
          SendMessage(hButtonScross, BM_SETIMAGE, IMAGE_BITMAP, LPARAM(hBitmapCancel));
          SCrossing = FALSE;

          SendMessage(hButtonSave, BM_SETIMAGE, IMAGE_BITMAP, LPARAM(hBitmapCancel));
          Save = FALSE;
        } else {
          SendMessage(hButtonScross, BM_SETIMAGE, IMAGE_BITMAP, LPARAM(hBitmapOk));
          SCrossing = TRUE;
        }
        break;

      case ID_BUTTONACCELERATE:
        if (Accelerate) {
          SendMessage(hButtonAccelerate, BM_SETIMAGE, IMAGE_BITMAP, LPARAM(hBitmapCancel));
          Accelerate = FALSE;

          SendMessage(hButtonSave, BM_SETIMAGE, IMAGE_BITMAP, LPARAM(hBitmapCancel));
          Save = FALSE;
        } else {
          SendMessage(hButtonAccelerate, BM_SETIMAGE, IMAGE_BITMAP, LPARAM(hBitmapOk));
          Accelerate = TRUE;
        }
        break;

      case ID_BUTTONSPEED:
        switch (Speed) {
          case 0:
            SendMessage(hButtonSpeed, BM_SETIMAGE, IMAGE_BITMAP, LPARAM(hBitmapTwo));
            Speed = 1;
            break;

          case 1:
            SendMessage(hButtonSpeed, BM_SETIMAGE, IMAGE_BITMAP, LPARAM(hBitmapThree));
            Speed = 2;
            break;

          case 2:
            SendMessage(hButtonSpeed, BM_SETIMAGE, IMAGE_BITMAP, LPARAM(hBitmapOne));
            Speed = 0;

            SendMessage(hButtonSave, BM_SETIMAGE, IMAGE_BITMAP, LPARAM(hBitmapCancel));
            Save = FALSE;
            break;
        }
        break;

      case ID_BUTTONSNAKETR:
        switch (SnakeT) {
          case -1:
            SnakeT = 0;
            break;

          case 0:
            SnakeT = 1;
            break;

          case 1:
            SnakeT = 2;
            break;

          case 2:
            SnakeT = 3;
            break;

          case 3:
            SnakeT = 4;
            break;

          case 4:
            SnakeT = 5;
            break;

          case 5:
            if (IsLoadT) {
              SnakeT = -1;
            }
            else {
              SnakeT = 0;
            }
            break;
        }
        InvalidateRect(hWnd, NULL, TRUE);
        break;

      case ID_BUTTONSNAKETL:
        switch (SnakeT) {
          case -1:
            SnakeT = 5;
            break;

          case 0:
            if (IsLoadT) {
              SnakeT = -1;
            }
            else {
              SnakeT = 5;
            }
            break;

          case 1:
            SnakeT = 0;
            break;

          case 2:
            SnakeT = 1;
            break;

          case 3:
            SnakeT = 2;
            break;

          case 4:
            SnakeT = 3;
            break;

          case 5:
            SnakeT = 4;
            break;
        }
        InvalidateRect(hWnd, NULL, TRUE);
        break;
    }
    break;

  case WM_SIZE:
    GetClientRect(hWnd, &rc);
    MoveWindow(hEditUser, rc.right/2 - 150, 130, 300, 25, TRUE);
    MoveWindow(hButtonAccelerate, rc.right - 94, 200, 64, 64, TRUE);
    MoveWindow(hButtonSpeed, rc.right - 94, 300, 64, 64, TRUE);
    MoveWindow(hButtonSnakeTL, rc.right - 240, 400, 20, 80, TRUE);
    MoveWindow(hButtonSnakeTR, rc.right - 50, 400, 20, 80, TRUE);
    break;

  case WM_GETMINMAXINFO:
    ((MINMAXINFO *)lParam)->ptMinTrackSize.x = 850;
    ((MINMAXINFO *)lParam)->ptMinTrackSize.y = 570;
  break;

  case WM_DESTROY:
    PostQuitMessage(0);
    break;

  default:
    return DefWindowProc(hWnd, msg, wParam, lParam);
}
return 0;
}

LRESULT CALLBACK WndProcSettings2(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
static HWND hEditWidth, hEditHeight, hEditTexture, hButtonLoadT, hButtonControl, hScrollTime, hButtonBack;

HWND hWndMain;//для перехода в главное окно

HFONT hFont, hFont2, hFont3;
HBRUSH hBrush, hBrush2;
RECT rc, rco;//окна, другого окна
char chWidth[11], chHeight[11], chTime[11];
TextPrint time;

switch(msg) {
  case WM_CREATE:  
    SnakeSettings LS;

    if (LoadSettings(&LS)) {
      Control = LS.Control;
      widthX = LS.widthX;
      heightY = LS.heightY;
      PlayTime = LS.PlayTime;
    }

    itoa(widthX, chWidth, 10);
    itoa(heightY, chHeight, 10);
    
    GetClientRect(hWnd, &rc);

    hEditWidthG = hEditWidth = CreateWindow("edit", chWidth,
                                WS_CHILD | WS_VISIBLE | WS_BORDER | ES_CENTER | ES_NUMBER,
                                30, 130, 50, 20,
                                hWnd, (HMENU)ID_EDITWIDTH, GlobalhInst, NULL);
    SendMessage(hEditWidth, EM_LIMITTEXT, 3, 0);

    hEditHeightG = hEditHeight = CreateWindow("edit", chHeight,
                                WS_CHILD | WS_VISIBLE | WS_BORDER | ES_CENTER | ES_NUMBER,
                                100, 130, 50, 20,
                                hWnd, (HMENU)ID_EDITHEIGHT, GlobalhInst, NULL);
    SendMessage(hEditHeight, EM_LIMITTEXT, 3, 0);

    hEditTexture = CreateWindow("edit", "C:\\",
                                WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT | ES_AUTOHSCROLL,
                                30, 225, 400, 25,
                                hWnd, (HMENU)ID_EDITTEXTURE, GlobalhInst, NULL);
    SendMessage(hEditTexture, EM_LIMITTEXT, 255, 0);

    hButtonLoadT = CreateWindow("button", "Загрузить текстуру",
                                WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                                30, 260, 150, 25,
                                hWnd, (HMENU)ID_BUTTONLOADT, GlobalhInst, NULL);
    
    hButtonControl = CreateWindow("button", NULL,
                                WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_BITMAP,
                                rc.right - 94, 130, 64, 64,
                                hWnd, (HMENU)ID_BUTTONCONTROL, GlobalhInst, NULL);
    if (Control)
      SendMessage(hButtonControl, BM_SETIMAGE, IMAGE_BITMAP, LPARAM(hBitmapULDR));
    else
      SendMessage(hButtonControl, BM_SETIMAGE, IMAGE_BITMAP, LPARAM(hBitmapWASD));
    
    hScrollTime = CreateWindow("scrollbar", NULL,
                                WS_CHILD | WS_VISIBLE | SBS_VERT,
                                rc.right - 51, 295, 20, 20,
                                hWnd, (HMENU)ID_SCROLLTIME, GlobalhInst, NULL);
    
    hButtonBack = CreateWindow("button", NULL,
                                WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_BITMAP,
                                30, 30, 48, 48,
                                hWnd, (HMENU)ID_BUTTONBACK, GlobalhInst, NULL);
    SendMessage(hButtonBack, BM_SETIMAGE, IMAGE_BITMAP, LPARAM(hBitmapBack));

    if (LoadTexture(TextureName)) {
      SnakeTexture_p.set_img(TextureName);
      SnakeTexture_p2.set_img(TextureName);
      SnakeTexture_p.load();
      SnakeTexture_p2.load();
      SnakeP.Body = &SnakeTexture_p;
      SnakeP.Head = &SnakeTexture_p2;
      if (SnakeTexture_p.get_state()) {
        IsLoadT = 1;
        SetWindowText(hButtonLoadT, "Удалить текстуру");
        SetWindowText(hEditTexture, TextureName);
      }
      else {
        MessageBox(hWnd, "Текстура не загружена. Проверьте наличие текстуры и правильность ввода.", "Ошибка", MB_OK | MB_ICONERROR);
        SetWindowText(hEditTexture, TextureName);
        remove("C:\\SBstudio\\snake\\snake_texture.txt");
        if (SnakeT == -1) {
          SnakeT = 0;
        }
      }
    }
    else {
      if (SnakeT == -1) {
        SnakeT = 0;
      }
    }
    break;

  case WM_PAINT:
    PAINTSTRUCT ps;
    HDC hdcOut, hdc;
    HRGN hRgn;
    HANDLE hBitmapBuff;
    GetClientRect(hWnd, &rc);
    hFont = CreateFont(60,0,0,0,1,0,0,0,DEFAULT_CHARSET,0,0,0,0,"Arial Bold");
    hFont2 = CreateFont(20,0,0,0,0,1,0,0,DEFAULT_CHARSET,0,0,0,0,"Arial Bold");
    hFont3 = CreateFont(20,0,0,0,0,1,1,0,DEFAULT_CHARSET,0,0,0,0,"Arial Bold");
    hBrush = CreateSolidBrush(RGB(204,204,204));
    hBrush2 = CreateSolidBrush(RGB(255, 255, 255));

    hdcOut = BeginPaint(hWnd, &ps);
    hdc = CreateCompatibleDC(hdcOut);
    hBitmapBuff = CreateCompatibleBitmap(hdcOut, rc.right, rc.bottom);
    SelectObject(hdc, hBitmapBuff);
//фон
    SelectObject(hdc, hBrush);
    Rectangle(hdc, -1, -1, rc.right + 1, rc.bottom + 1);
    DeleteObject(hBrush);

    SelectObject(hdc, hBrush2);
    Rectangle(hdc, 29, 294, 191, 376);
    Rectangle(hdc, rc.right - 138, 294, rc.right - 30, 316);
    DeleteObject(hBrush2);
    
    itoa(PlayTime, chTime, 10);
    if (PlayTime == 0)
      strcpy(chTime, "Unlimited");
    time.set_pos(rc.right - 94, 297);
    time.set_text(chTime);
    SetTextAlign(hdc, TA_CENTER);
    time.print(hdc);
//картинки
    PictArrow2.set_pos(rc.right/2 - 214, 20);
    PictArrow2.print_std(hdc);

//режим текста
    SetTextColor(hdc, RGB(0, 0, 0));
    SetBkMode(hdc, TRANSPARENT);

    SetTextAlign(hdc, TA_CENTER);
    TextOut(hdc, rc.right/2, rc.bottom - 18, "All rights reserved. SBstudio © 2016.", 37);
    TextOut(hdc, 90, 130, "x", 1);
    TextOut(hdc, 55, 155, "min:10", 6);
    TextOut(hdc, 55, 172, "max:60", 6);
    TextOut(hdc, 125, 155, "min:10", 6);
    TextOut(hdc, 125, 172, "max:60", 6);

    SelectObject(hdc, hFont);
    TextOut(hdc, rc.right/2 , 20, "Настройки", 9);
    DeleteObject(hFont);
    SetTextAlign(hdc, TA_LEFT);

    SelectObject(hdc, hFont2);
    TextOut(hdc, 170, 130, "Размер поля", 11);
    TextOut(hdc, 450, 225, "Пользовательская текстура", 25);
    SetTextAlign(hdc, TA_RIGHT);
    TextOut(hdc, rc.right - 114, 147, "Управление", 10);
    TextOut(hdc, rc.right - 158, 294, "Время игры", 10);
    DeleteObject(hFont2);

    if (IsLoadT) {
      SnakeTexture_p.set_pos(30, 295);
      SnakeTexture_p.set_angle(0);
      SnakeTexture_p.set_cut(0, 0, 0, 0);
      SnakeTexture_p.print_ex(hdc, 160, 80);
    }

    BitBlt(hdcOut, 0, 0, rc.right, rc.bottom, hdc, 0, 0, SRCCOPY);

    DeleteObject(hBitmapBuff);
    DeleteDC(hdc);
    EndPaint(hWnd, &ps);
    break;

  case WM_ERASEBKGND:
    break;

  case WM_LBUTTONDOWN:
    int xPos, yPos;
    xPos = LOWORD(lParam);
    yPos = HIWORD(lParam);
    GetClientRect(hWnd, &rc);

    if (xPos > rc.right/2 - 214 && xPos < rc.right/2 - 150 && yPos > 20 && yPos < 84) {
      hWndMain = FindWindow(chClassName3, NULL);
      GetWindowRect(hWnd, &rco);
      MoveWindow(hWndMain, rco.left, rco.top,
                   rco.right - rco.left, rco.bottom - rco.top, TRUE);
      ShowWindow(hWndMain, SW_SHOW);
      ShowWindow(hWnd, SW_HIDE);

      GetWindowText(hEditWidth, chWidth, 4);
      GetWindowText(hEditHeight, chHeight, 4);
      widthX = atoi(chWidth);
      heightY = atoi(chHeight);
      if (widthX < 10) {
        widthX = 10;
        SetWindowText(hEditWidth, "10");
      }
      if (heightY < 10) {
        heightY = 10;
        SetWindowText(hEditHeight, "10");
      }
      if (widthX > 60) {
        widthX = 60;
        SetWindowText(hEditWidth, "60");
      }
      if (heightY > 60) {
        heightY = 60;
        SetWindowText(hEditHeight, "60");
      }
    }
    break;

  case WM_COMMAND:
    switch(LOWORD(wParam)) {
      case ID_BUTTONBACK://возврат в меню
        hWndMain = FindWindow(chClassName1, NULL);
        GetWindowRect(hWnd, &rco);
        MoveWindow(hWndMain, rco.left, rco.top,
                   rco.right - rco.left, rco.bottom - rco.top, TRUE);
        ShowWindow(hWndMain, SW_SHOW);
        ShowWindow(hWnd, SW_HIDE);

        GetWindowText(hEditWidth, chWidth, 4);
        GetWindowText(hEditHeight, chHeight, 4);
        widthX = atoi(chWidth);
        heightY = atoi(chHeight);
        if (widthX < 10) {
          widthX = 10;
          SetWindowText(hEditWidth, "10");
        }
        if (heightY < 10) {
          heightY = 10;
          SetWindowText(hEditHeight, "10");
        }
        if (widthX > 60) {
          widthX = 60;
          SetWindowText(hEditWidth, "60");
        }
        if (heightY > 60) {
          heightY = 60;
          SetWindowText(hEditHeight, "60");
        }

        SnakeSettings SS;
        SS.Save = Save;
        SS.walls = walls;
        SS.SCrossing = SCrossing;
        SS.Accelerate = Accelerate;
        SS.Speed = Speed;
        SS.SnakeT = SnakeT;
        SS.Control = Control;
        SS.widthX = widthX;
        SS.heightY = heightY;
        SS.PlayTime = PlayTime;
        strcpy(SS.PlayerName, PlayerName);
        SaveSettings(SS);
        break;

      case ID_BUTTONLOADT:
        if (! IsLoadT) {
          GetWindowText(hEditTexture, TextureName, 256);
          SnakeTexture_p.set_img(TextureName);
          SnakeTexture_p2.set_img(TextureName);
          SnakeTexture_p.load();
          SnakeTexture_p2.load();
          SnakeP.Body = &SnakeTexture_p;
          SnakeP.Head = &SnakeTexture_p2;
          if (SnakeTexture_p.get_state()) {
            SaveTexture(TextureName);
            IsLoadT = 1;
            SetWindowText(hButtonLoadT, "Удалить текстуру");
            InvalidateRect(hWnd, NULL, TRUE);
            SnakeT = -1;
            MessageBox(hWnd, "Текстура успешно загружена.", "Операция завершена", MB_OK | MB_ICONASTERISK);
          }
          else {
            MessageBox(hWnd, "Текстура не загружена. Проверьте наличие текстуры и правильность ввода.", "Ошибка", MB_OK | MB_ICONERROR);
          }
        }
        else {
          IsLoadT = 0;
          remove("C:\\SBstudio\\snake\\snake_texture.txt");
          SetWindowText(hButtonLoadT, "Загрузить текстуру");
          InvalidateRect(hWnd, NULL, TRUE);
          if (SnakeT == -1) {
            SnakeT = 0;
          }
        }
        break;
        
      case ID_BUTTONCONTROL:
        switch (Control) {
          case 0:
            SendMessage(hButtonControl, BM_SETIMAGE, IMAGE_BITMAP, LPARAM(hBitmapULDR));
            Control = 1;
            break;

          case 1:
            SendMessage(hButtonControl, BM_SETIMAGE, IMAGE_BITMAP, LPARAM(hBitmapWASD));
            Control = 0;
            break;
        }
        break;
          
    }
    break;
    
  case WM_VSCROLL:
    GetClientRect(hWnd, &rc);
    switch(LOWORD(wParam)) {
      case SB_LINERIGHT:
        if (PlayTime > 0)
          PlayTime--;
        else
          PlayTime = 5;
        break;

      case SB_LINELEFT:
        if (PlayTime < 5)
          PlayTime++;
        else
          PlayTime = 0;
        break;
    }
    InvalidateRect(hWnd, NULL, TRUE);
    break;
    
  case WM_SIZE:
    GetClientRect(hWnd, &rc);
    MoveWindow(hButtonControl, rc.right - 94, 130, 64, 64, TRUE);
    MoveWindow(hScrollTime, rc.right - 51, 295, 20, 20, TRUE);
    break;

  case WM_GETMINMAXINFO:
    ((MINMAXINFO *)lParam)->ptMinTrackSize.x = 850;
    ((MINMAXINFO *)lParam)->ptMinTrackSize.y = 570;
  break;

  case WM_DESTROY:
    PostQuitMessage(0);
    break;

  default:
    return DefWindowProc(hWnd, msg, wParam, lParam);
}
return 0;
}

LRESULT CALLBACK WndProcHelp(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
static HWND hScrollHelp, hButtonBack;

HWND hWndMain;//для перехода в меню

HFONT hFont, hFont2;
HBRUSH hBrush, hBrush2;
RECT rc, rco; //окна, другого окна

//данные ползунка
static const int ScrollSize = 55; //кол - во отображаемых строк (минимальное);
static int Spos, Srange; //позиция, диапазон
static SCROLLINFO si;

switch(msg) {
  case WM_CREATE:
  GetClientRect(hWnd, &rc);
//движение текста подсказок
//при установке диапазона ползунка из кол - ва строк вычитается кол - во видимых строк
    hScrollHelp = CreateWindow("scrollbar", NULL,
                                WS_CHILD | SBS_VERT,
                                rc.right/2 + 342, 100, rc.right/2 + 362, rc.bottom - 38,
                                hWnd, (HMENU)ID_SCROLLHELP, GlobalhInst, NULL);
    Srange = ScrollSize - (rc.bottom - 138)/17;
    si.cbSize = sizeof(si);
    si.fMask = SIF_ALL;
    si.nMin = 0;
    si.nMax = ScrollSize;
    si.nPage = ScrollSize - Srange + 1;
    si.nPos = 0;
    SetScrollInfo(hScrollHelp, SB_CTL, &si, TRUE);
    if (Srange <= 0)
      ShowWindow(hScrollHelp, SW_HIDE);
    else
      ShowWindow(hScrollHelp, SW_SHOW);
    if (Srange < Spos)
      Spos = Srange;
    if (Srange <= 0)
      Spos = 0;
//возврат в меню
    hButtonBack = CreateWindow("button", NULL,
                                WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_BITMAP,
                                30, 30, 48, 48,
                                hWnd, (HMENU)ID_BUTTONBACK, GlobalhInst, NULL);
    SendMessage(hButtonBack, BM_SETIMAGE, IMAGE_BITMAP, LPARAM(hBitmapBack));
    break;

  case WM_PAINT:
    PAINTSTRUCT ps;
    HDC hdcOut, hdc;
    HANDLE hBitmapBuff;
    HRGN hrgn;
    GetClientRect(hWnd, &rc);
    hFont = CreateFont(60,0,0,0,1,0,0,0,DEFAULT_CHARSET,0,0,0,0,"Arial Bold");
    hFont2 = CreateFont(34,0,0,0,0,0,1,0,DEFAULT_CHARSET,0,0,0,0,"Arial Bold");
    hBrush = CreateSolidBrush(RGB(204,204,204));
    hBrush2 = CreateSolidBrush(RGB(255,255,255));

    hdcOut = BeginPaint(hWnd, &ps);
    hdc = CreateCompatibleDC(hdcOut);
    hBitmapBuff = CreateCompatibleBitmap(hdcOut, rc.right, rc.bottom);
    SelectObject(hdc, hBitmapBuff);
//фон
    SelectObject(hdc, hBrush);
    Rectangle(hdc, -1, -1, rc.right + 1, rc.bottom + 1);
    DeleteObject(hBrush);
//фон для подсказок
    SelectObject(hdc, hBrush2);
    Rectangle(hdc, rc.right/2 - 340, 100, rc.right/2 + 340, rc.bottom - 38);
    DeleteObject(hBrush2);
//режим текста
    SetTextColor(hdc, RGB(0, 0, 0));
    SetBkMode(hdc, TRANSPARENT);

    SetTextAlign(hdc, TA_CENTER);
    TextOut(hdc, rc.right/2, rc.bottom - 18, "All rights reserved. SBstudio © 2016.", 37);

//текст помощи
    hrgn = CreateRectRgn(rc.right/2 - 340, 100, rc.right/2 + 340, rc.bottom - 38);
    SelectClipRgn(hdc, hrgn);
    SetTextAlign(hdc, TA_LEFT);
//текст разделов
    TextHelp.set_pos(rc.right/2 - 338, 102 - Spos*17);
    TextHelp.print(hdc);
//заголовки разделов
    SelectObject(hdc, hFont2);
    TextOut(hdc, rc.right/2 - 338, 102 - Spos*17, "Игра:", 5);
    TextOut(hdc, rc.right/2 - 338, 102 - Spos*17 + 119, "Режимы игры:", 12);
    TextOut(hdc, rc.right/2 - 338, 102 - Spos*17 + 255, "Настройки:", 10);
    TextOut(hdc, rc.right/2 - 338, 102 - Spos*17 + 510, "Сохранение результатов:", 23);
    TextOut(hdc, rc.right/2 - 338, 102 - Spos*17 + 612, "Загрузка текстуры:", 18);
    TextOut(hdc, rc.right/2 - 338, 102 - Spos*17 + 833, "О программе:", 12);
    DeleteObject(hFont2);

    hrgn = CreateRectRgn(0, 0, rc.right, rc.bottom);
    SelectClipRgn(hdc, hrgn);
//-------------

    SetTextAlign(hdc, TA_CENTER);
    SelectObject(hdc, hFont);
    TextOut(hdc, rc.right/2 , 20, "Помощь", 6);
    DeleteObject(hFont);

    BitBlt(hdcOut, 0, 0, rc.right, rc.bottom, hdc, 0, 0, SRCCOPY);

    DeleteObject(hBitmapBuff);
    DeleteDC(hdc);
    EndPaint(hWnd, &ps);
    break;

  case WM_ERASEBKGND:
    break;

  case WM_COMMAND:
    switch(LOWORD(wParam)) {
      case ID_BUTTONBACK://возврат в меню
        hWndMain = FindWindow(chClassName1, NULL);
        GetWindowRect(hWnd, &rco);
        MoveWindow(hWndMain, rco.left, rco.top,
                   rco.right - rco.left, rco.bottom - rco.top, TRUE);
        ShowWindow(hWndMain, SW_SHOW);
        ShowWindow(hWnd, SW_HIDE);
        break;
    }
    break;

  case WM_VSCROLL:
    GetClientRect(hWnd, &rc);
    switch(LOWORD(wParam)) {
      case SB_LINERIGHT:
        if (Spos < Srange)
          Spos += 1;
        break;

      case SB_LINELEFT:
        if (Spos > 0)
          Spos -= 1;
        break;

      case SB_PAGERIGHT:
        if (Spos + (rc.bottom - 138)/17 <= Srange)
          Spos += (rc.bottom - 138)/17;
        else
          Spos = Srange;
        break;

      case SB_PAGELEFT:
        if (Spos - (rc.bottom - 138)/17 >= 0)
          Spos -= (rc.bottom - 138)/17;
        else
          Spos = 0;
        break;

      case SB_THUMBPOSITION:
      case SB_THUMBTRACK:
        Spos = HIWORD(wParam);
        break;

      default:
        break;
    }
    SetScrollPos(hScrollHelp, SB_CTL, Spos, TRUE);
    InvalidateRect(hWnd, NULL, TRUE);
    break;

  case WM_SIZE:
    GetClientRect(hWnd, &rc);
    MoveWindow(hScrollHelp, rc.right/2 + 342, 100, 20, rc.bottom - 138, TRUE);

    Srange = ScrollSize - (rc.bottom - 138)/17;
    si.cbSize = sizeof(si);
    si.fMask = SIF_ALL;
    si.nMin = 0;
    si.nMax = ScrollSize;
    si.nPage = ScrollSize - Srange + 1;
    si.nPos = Spos;
    SetScrollInfo(hScrollHelp, SB_CTL, &si, TRUE);
    if (Srange <= 0)
      ShowWindow(hScrollHelp, SW_HIDE);
    else
      ShowWindow(hScrollHelp, SW_SHOW);

    if (Srange < Spos)
      Spos = Srange;
    if (Srange <= 0)
      Spos = 0;
    break;

  case WM_GETMINMAXINFO:
    ((MINMAXINFO *)lParam)->ptMinTrackSize.x = 850;
    ((MINMAXINFO *)lParam)->ptMinTrackSize.y = 570;
  break;

  case WM_DESTROY:
    PostQuitMessage(0);
    break;
  default:
    return DefWindowProc(hWnd, msg, wParam, lParam);
}
return 0;
}

LRESULT CALLBACK WndProcCredits(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
static HWND hButtonBack;

HWND hWndMain;//для перехода в меню

HFONT hFont;
HBRUSH hBrush, hBrush2;
RECT rc, rco; //окна, другого окна

static int y_offset = 0;//сдвиг листа создателей
static bool IsCenter = 0;//SVstudio в центре

switch(msg) {
  case WM_CREATE:
    GetClientRect(hWnd, &rc);
//возврат в меню
    hButtonBack = CreateWindow("button", NULL,
                                WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_BITMAP,
                                30, 30, 48, 48,
                                hWnd, (HMENU)ID_BUTTONBACK, GlobalhInst, NULL);
    SendMessage(hButtonBack, BM_SETIMAGE, IMAGE_BITMAP, LPARAM(hBitmapBack));
    break;

  case WM_PAINT:
    PAINTSTRUCT ps;
    HDC hdcOut, hdc;
    HANDLE hBitmapBuff;
    GetClientRect(hWnd, &rc);
    hFont = CreateFont(40,0,0,0,0,1,0,0,DEFAULT_CHARSET,0,0,0,0,"Arial Bold");
    hBrush = CreateSolidBrush(RGB(204,204,204));
    hBrush2 = CreateSolidBrush(RGB(255,255,255));

    hdcOut = BeginPaint(hWnd, &ps);
    hdc = CreateCompatibleDC(hdcOut);
    hBitmapBuff = CreateCompatibleBitmap(hdcOut, rc.right, rc.bottom);
    SelectObject(hdc, hBitmapBuff);
//фон
    SelectObject(hdc, hBrush);
    Rectangle(hdc, -1, -1, rc.right + 1, rc.bottom + 1);
    DeleteObject(hBrush);
//фон для списка создателей
    SelectObject(hdc, hBrush2);
    Rectangle(hdc, rc.right/2 - 201, -1, rc.right/2 + 201, rc.bottom + 1);
    DeleteObject(hBrush2);
//список создателей
    if (rc.bottom/2 - 50 >= rc.bottom - y_offset + 540)
      IsCenter = 1;

    if (IsCenter == 1)
      PictSBstudio.set_pos(rc.right/2 - 200, rc.bottom/2 - 50);
    else
      PictSBstudio.set_pos(rc.right/2 - 200, rc.bottom - y_offset + 540);
                                                                   //<>доп. смещение
    PictCreditsList.set_pos(rc.right/2 - 200, rc.bottom - y_offset + 40);
    PictCreditsList.print_std(hdc);
    PictSBstudio.print_std(hdc);

    SetTextAlign(hdc, TA_CENTER);
    SelectObject(hdc, hFont);
    TextOut(hdc, rc.right/2, rc.bottom - y_offset + 40, version, 13);
    DeleteObject(hFont);

    BitBlt(hdcOut, 0, 0, rc.right, rc.bottom, hdc, 0, 0, SRCCOPY);

    DeleteObject(hBitmapBuff);
    DeleteDC(hdc);
    EndPaint(hWnd, &ps);
    break;

  case WM_ERASEBKGND:
    break;

  case WM_COMMAND:
    switch(LOWORD(wParam)) {
      case ID_BUTTONBACK://возврат в меню
        hWndMain = FindWindow(chClassName1, NULL);
        GetWindowRect(hWnd, &rco);
        MoveWindow(hWndMain, rco.left, rco.top,
                   rco.right - rco.left, rco.bottom - rco.top, TRUE);
        ShowWindow(hWndMain, SW_SHOW);
        ShowWindow(hWnd, SW_HIDE);

        y_offset = 0;
        IsCenter = 0;
        break;
    }
    break;

  case WM_TIMER:
    HDC hdct;
    GetClientRect(hWnd, &rc);

    switch(LOWORD(wParam)) {
      case ID_TIMERCREDITS:
        y_offset += 1;
        InvalidateRect(hWnd, NULL, TRUE);
        break;
    }
    break;

  case WM_GETMINMAXINFO:
    ((MINMAXINFO *)lParam)->ptMinTrackSize.x = 850;
    ((MINMAXINFO *)lParam)->ptMinTrackSize.y = 570;
    break;

  case WM_DESTROY:
    PostQuitMessage(0);
    break;

  default:
    return DefWindowProc(hWnd, msg, wParam, lParam);
}
return 0;
}

LRESULT CALLBACK WndProcPlayMenu(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
static HWND hButtonClassic, hButtonAdvanced, hButtonTime, hButtonCustom, hButtonPlayerCount, hButtonBack,
hButtonSettingM2, hButtonSettingM3, hButtonSettingM4, hButtonSettingM5;

HWND hWndOther;//Дескриптор окна, в которое осуществляется переход

HFONT hFont;
HBRUSH hBrush;
RECT rc, rco;//окна, другого окна

switch(msg) {
  case WM_CREATE:
    GetClientRect(hWnd, &rc);

    hButtonBack = CreateWindow("button", NULL,
                                WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_BITMAP,
                                30, 30, 48, 48,
                                hWnd, (HMENU)ID_BUTTONBACK, GlobalhInst, NULL);
    SendMessage(hButtonBack, BM_SETIMAGE, IMAGE_BITMAP, LPARAM(hBitmapBack));

    hButtonClassic = CreateWindow("button", NULL,
                               WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_BITMAP,
                               rc.right/2 - 100, 120, 200, 50,
                               hWnd, (HMENU)ID_BUTTONCLASSIC, GlobalhInst, NULL);
    SendMessage(hButtonClassic, BM_SETIMAGE, IMAGE_BITMAP, LPARAM(hBitmapClassic));

    hButtonAdvanced = CreateWindow("button", NULL,
                               WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_BITMAP,
                               rc.right/2 - 100, 190, 200, 50,
                               hWnd, (HMENU)ID_BUTTONADVANCED, GlobalhInst, NULL);
    SendMessage(hButtonAdvanced, BM_SETIMAGE, IMAGE_BITMAP, LPARAM(hBitmapAdvanced));

    hButtonTime = CreateWindow("button", NULL,
                               WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_BITMAP,
                               rc.right/2 - 100, 260, 200, 50,
                               hWnd, (HMENU)ID_BUTTONTIME, GlobalhInst, NULL);
    SendMessage(hButtonTime, BM_SETIMAGE, IMAGE_BITMAP, LPARAM(hBitmapTime));

    hButtonCustom = CreateWindow("button", NULL,
                               WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_BITMAP,
                               rc.right/2 - 100, 330, 200, 50,
                               hWnd, (HMENU)ID_BUTTONCUSTOM, GlobalhInst, NULL);
    SendMessage(hButtonCustom, BM_SETIMAGE, IMAGE_BITMAP, LPARAM(hBitmapCustom));

    hButtonPlayerCount = CreateWindow("button", NULL,
                               WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_BITMAP,
                               rc.right/2 - 100, 400, 200, 50,
                               hWnd, (HMENU)ID_BUTTONPLAYERCOUNT, GlobalhInst, NULL);
    SendMessage(hButtonPlayerCount, BM_SETIMAGE, IMAGE_BITMAP, LPARAM(hBitmapP1));
    
    hButtonSettingM2 = CreateWindow("button", NULL,
                               WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_BITMAP,
                               rc.right/2 + 120, 190, 50, 50,
                               hWnd, (HMENU)ID_BUTTONSETTINGM2, GlobalhInst, NULL);
    SendMessage(hButtonSettingM2, BM_SETIMAGE, IMAGE_BITMAP, LPARAM(hBitmapSettingM));
    
    hButtonSettingM3 = CreateWindow("button", NULL,
                               WS_CHILD | BS_PUSHBUTTON | BS_BITMAP,
                               rc.right/2 + 120, 260, 50, 50,
                               hWnd, (HMENU)ID_BUTTONSETTINGM3, GlobalhInst, NULL);
    SendMessage(hButtonSettingM3, BM_SETIMAGE, IMAGE_BITMAP, LPARAM(hBitmapSettingM));
    
    hButtonSettingM4 = CreateWindow("button", NULL,
                               WS_CHILD | BS_PUSHBUTTON | BS_BITMAP,
                               rc.right/2 + 120, 330, 50, 50,
                               hWnd, (HMENU)ID_BUTTONSETTINGM4, GlobalhInst, NULL);
    SendMessage(hButtonSettingM4, BM_SETIMAGE, IMAGE_BITMAP, LPARAM(hBitmapSettingM));

    hButtonSettingM5 = CreateWindow("button", NULL,
                               WS_CHILD | BS_PUSHBUTTON | BS_BITMAP,
                               rc.right/2 + 120, 400, 50, 50,
                               hWnd, (HMENU)ID_BUTTONSETTINGM5, GlobalhInst, NULL);
    SendMessage(hButtonSettingM5, BM_SETIMAGE, IMAGE_BITMAP, LPARAM(hBitmapSettingM));
    break;

  case WM_PAINT:
    PAINTSTRUCT ps;
    HDC hdcOut, hdc;
    HANDLE hBitmapBuff;
    GetClientRect(hWnd, &rc);
    hFont = CreateFont(60,0,0,0,1,0,0,0,DEFAULT_CHARSET,0,0,0,0,"Arial Bold");
    hBrush = CreateSolidBrush(RGB(204,204,204));

    hdcOut = BeginPaint(hWnd, &ps);
    hdc = CreateCompatibleDC(hdcOut);
    hBitmapBuff = CreateCompatibleBitmap(hdcOut, rc.right, rc.bottom);
    SelectObject(hdc, hBitmapBuff);
//фон
    SelectObject(hdc, hBrush);
    Rectangle(hdc, -1, -1, rc.right + 1, rc.bottom + 1);
    DeleteObject(hBrush);

    SetBkMode(hdc, TRANSPARENT);
    SetTextAlign(hdc, TA_CENTER);
    TextOut(hdc, rc.right/2, rc.bottom - 18, "All rights reserved. SBstudio © 2016.", 37);

    SelectObject(hdc, hFont);
    TextOut(hdc, rc.right/2, 20, "Выбор режима", 12);
    DeleteObject(hFont);

    BitBlt(hdcOut, 0, 0, rc.right, rc.bottom, hdc, 0, 0, SRCCOPY);

    DeleteObject(hBitmapBuff);
    DeleteDC(hdc);
    EndPaint(hWnd, &ps);

  case WM_ERASEBKGND:
    break;

  case WM_COMMAND:
    HDC hdcL;

    switch(LOWORD(wParam)) {
      case ID_BUTTONBACK:
        hWndOther = FindWindow(chClassName1, NULL);
        GetWindowRect(hWnd, &rco);
        MoveWindow(hWndOther, rco.left, rco.top,
                   rco.right - rco.left, rco.bottom - rco.top, TRUE);
        ShowWindow(hWndOther, SW_SHOW);
        ShowWindow(hWnd, SW_HIDE);
        break;

      case ID_BUTTONCLASSIC:
        hWndOther = FindWindow(chClassName2, NULL);
        GetWindowRect(hWnd, &rco);
        MoveWindow(hWndOther, rco.left, rco.top,
                   rco.right - rco.left, rco.bottom - rco.top, TRUE);

        PlayingRoutine = 0;
        SetTimer(hWndOther, ID_TIMERPLAY, 100, NULL);
        if (PlayerCount > 1)
          SetTimer(hWndOther, ID_TIMERPLAY2, 100, NULL);

        GetClientRect(hWnd, &rc);
        hdcL = GetDC(hWnd);
        SetTextAlign(hdcL, TA_CENTER);
        SetBkMode(hdcL, TRANSPARENT);
        SelectObject(hdcL, hFont);
        TextOut(hdcL, rc.right/2, 100, "Загрузка", 8);
        DeleteObject(hFont);
        ReleaseDC(hWnd, hdcL);
        Sleep(500);

        ShowWindow(hWndOther, SW_SHOW);
        ShowWindow(hWnd, SW_HIDE);
        break;
        
      case ID_BUTTONADVANCED:
        hWndOther = FindWindow(chClassName2, NULL);
        GetWindowRect(hWnd, &rco);
        MoveWindow(hWndOther, rco.left, rco.top,
                   rco.right - rco.left, rco.bottom - rco.top, TRUE);

        PlayingRoutine = 1;
        SetTimer(hWndOther, ID_TIMERPLAY, 100, NULL);
        if (PlayerCount > 1)
          SetTimer(hWndOther, ID_TIMERPLAY2, 100, NULL);

        GetClientRect(hWnd, &rc);
        hdcL = GetDC(hWnd);
        SetTextAlign(hdcL, TA_CENTER);
        SetBkMode(hdcL, TRANSPARENT);
        SelectObject(hdcL, hFont);
        TextOut(hdcL, rc.right/2, 100, "Загрузка", 8);
        DeleteObject(hFont);
        ReleaseDC(hWnd, hdcL);
        Sleep(500);

        ShowWindow(hWndOther, SW_SHOW);
        ShowWindow(hWnd, SW_HIDE);
        break;

      case ID_BUTTONTIME:
        hWndOther = FindWindow(chClassName2, NULL);
        GetWindowRect(hWnd, &rco);
        MoveWindow(hWndOther, rco.left, rco.top,
                   rco.right - rco.left, rco.bottom - rco.top, TRUE);

        PlayingRoutine = 2;
        SetTimer(hWndOther, ID_TIMERPLAY, 100, NULL);
        if (PlayerCount > 1)
          SetTimer(hWndOther, ID_TIMERPLAY2, 100, NULL);

        GetClientRect(hWnd, &rc);
        hdcL = GetDC(hWnd);
        SetTextAlign(hdcL, TA_CENTER);
        SetBkMode(hdcL, TRANSPARENT);
        SelectObject(hdcL, hFont);
        TextOut(hdcL, rc.right/2, 100, "Загрузка", 8);
        DeleteObject(hFont);
        ReleaseDC(hWnd, hdcL);
        Sleep(500);

        ShowWindow(hWndOther, SW_SHOW);
        ShowWindow(hWnd, SW_HIDE);
        break;
        
      case ID_BUTTONCUSTOM:
        hWndOther = FindWindow(chClassName11, NULL);
        GetWindowRect(hWnd, &rco);
        MoveWindow(hWndOther, rco.left, rco.top,
                   rco.right - rco.left, rco.bottom - rco.top, TRUE);
        ShowWindow(hWndOther, SW_SHOW);
        ShowWindow(hWnd, SW_HIDE);
        
        MapWidth = widthX;
        MapHeight = heightY;
        SetupCustomBoard(MapWidth, MapHeight);
        break;

      case ID_BUTTONPLAYERCOUNT:
        switch (PlayerCount) {
          case 1:
            SendMessage(hButtonPlayerCount, BM_SETIMAGE, IMAGE_BITMAP, LPARAM(hBitmapP2));
            ShowWindow(hButtonSettingM5, SW_SHOW);
            PlayerCount = 2;
            break;

          case 2:
            SendMessage(hButtonPlayerCount, BM_SETIMAGE, IMAGE_BITMAP, LPARAM(hBitmapP1));
            ShowWindow(hButtonSettingM5, SW_HIDE);
            PlayerCount = 1;
            break;
        }
        break;
        
      case ID_BUTTONSETTINGM2:
        hWndOther = FindWindow(chClassName7, NULL);
        GetWindowRect(hWnd, &rco);
        MoveWindow(hWndOther, rco.left, rco.top,
                   rco.right - rco.left, rco.bottom - rco.top, TRUE);
        ShowWindow(hWndOther, SW_SHOW);
        ShowWindow(hWnd, SW_HIDE);
        break;

      case ID_BUTTONSETTINGM5:
        hWndOther = FindWindow(chClassName10, NULL);
        GetWindowRect(hWnd, &rco);
        MoveWindow(hWndOther, rco.left, rco.top,
                   rco.right - rco.left, rco.bottom - rco.top, TRUE);
        ShowWindow(hWndOther, SW_SHOW);
        ShowWindow(hWnd, SW_HIDE);
        break;
    }
    break;

  case WM_SIZE://движение кнопок
    GetClientRect(hWnd, &rc);
    MoveWindow(hButtonClassic, rc.right/2 - 100, 120, 200, 50, TRUE);
    MoveWindow(hButtonAdvanced, rc.right/2 - 100, 190, 200, 50, TRUE);
    MoveWindow(hButtonTime, rc.right/2 - 100, 260, 200, 50, TRUE);
    MoveWindow(hButtonCustom, rc.right/2 - 100, 330, 200, 50, TRUE);
    MoveWindow(hButtonPlayerCount, rc.right/2 - 100, 400, 200, 50, TRUE);
    MoveWindow(hButtonSettingM2, rc.right/2 + 120, 190, 50, 50, TRUE);
    MoveWindow(hButtonSettingM5, rc.right/2 + 120, 400, 50, 50, TRUE);
    break;

  case WM_GETMINMAXINFO:
    ((MINMAXINFO *)lParam)->ptMinTrackSize.x = 850;
    ((MINMAXINFO *)lParam)->ptMinTrackSize.y = 570;
    break;


  case WM_DESTROY:
    PostQuitMessage(0);
    break;

  default:
    return DefWindowProc(hWnd, msg, wParam, lParam);
}
return 0;
}

LRESULT CALLBACK WndProcSettingAdvanced(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
static HWND hListMaps, hButtonBack;

HWND hWndOther;//Дескриптор окна, в которое осуществляется переход

HFONT hFont, hFont2;
HBRUSH hBrush, hBrush2;
RECT rc, rco;//окна, другого окна

switch(msg) {
  case WM_CREATE:
    GetClientRect(hWnd, &rc);

    hButtonBack = CreateWindow("button", NULL,
                                WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_BITMAP,
                                30, 30, 48, 48,
                                hWnd, (HMENU)ID_BUTTONBACK, GlobalhInst, NULL);
    SendMessage(hButtonBack, BM_SETIMAGE, IMAGE_BITMAP, LPARAM(hBitmapBack));
    
    hListMaps = CreateWindow("listbox", NULL,
                                WS_CHILD | WS_VISIBLE | WS_BORDER,
                                rc.right/2 - 150, 150, 300, 255,
                                hWnd, (HMENU)ID_LISTMAPS, GlobalhInst, NULL);
    SendMessage(hListMaps, LB_ADDSTRING, 0, (LPARAM)"Стандартная (изменяемый размер)");
    SendMessage(hListMaps, LB_SETCURSEL, (WPARAM)0, 0L);
    SendMessage(hListMaps, LB_ADDSTRING, 0, (LPARAM)"Тоннель (40x20)");
    SendMessage(hListMaps, LB_ADDSTRING, 0, (LPARAM)"Спираль (30x30)");
    SendMessage(hListMaps, LB_ADDSTRING, 0, (LPARAM)"Горшок (40x20)");
    SendMessage(hListMaps, LB_ADDSTRING, 0, (LPARAM)"Смайлик (30x30)");
    SendMessage(hListMaps, LB_ADDSTRING, 0, (LPARAM)"Змейки (40x20)");
    SendMessage(hListMaps, LB_ADDSTRING, 0, (LPARAM)"Крепости (40x20)");
    SendMessage(hListMaps, LB_ADDSTRING, 0, (LPARAM)"Домик (40x20)");
    SendMessage(hListMaps, LB_ADDSTRING, 0, (LPARAM)"Стены (30х30)");
    SendMessage(hListMaps, LB_ADDSTRING, 0, (LPARAM)"Кормушка (30х30)");
    SendMessage(hListMaps, LB_ADDSTRING, 0, (LPARAM)"Песочные часы (30х30)");
    SendMessage(hListMaps, LB_ADDSTRING, 0, (LPARAM)"Камни (40х20)");
    SendMessage(hListMaps, LB_ADDSTRING, 0, (LPARAM)"Гора (40х20)");
    SendMessage(hListMaps, LB_ADDSTRING, 0, (LPARAM)"Яблоко (30х30)");
    SendMessage(hListMaps, LB_ADDSTRING, 0, (LPARAM)"SNAKE (40х20)");
    break;

  case WM_PAINT:
    PAINTSTRUCT ps;
    HDC hdcOut, hdc;
    HANDLE hBitmapBuff;
    GetClientRect(hWnd, &rc);
    hFont = CreateFont(60,0,0,0,1,0,0,0,DEFAULT_CHARSET,0,0,0,0,"Arial Bold");
    hFont2 = CreateFont(20,0,0,0,0,1,0,0,DEFAULT_CHARSET,0,0,0,0,"Arial Bold");
    hBrush = CreateSolidBrush(RGB(204,204,204));
    hBrush2 = CreateSolidBrush(RGB(255, 255, 255));

    hdcOut = BeginPaint(hWnd, &ps);
    hdc = CreateCompatibleDC(hdcOut);
    hBitmapBuff = CreateCompatibleBitmap(hdcOut, rc.right, rc.bottom);
    SelectObject(hdc, hBitmapBuff);
//фон
    SelectObject(hdc, hBrush);
    Rectangle(hdc, -1, -1, rc.right + 1, rc.bottom + 1);
    DeleteObject(hBrush);

    SetBkMode(hdc, TRANSPARENT);
    SetTextAlign(hdc, TA_CENTER);
    TextOut(hdc, rc.right/2, rc.bottom - 18, "All rights reserved. SBstudio © 2016.", 37);

    SelectObject(hdc, hFont);
    TextOut(hdc, rc.right/2, 20, "Настройки Advanced", 18);
    DeleteObject(hFont);

//надписи у кнопок настроек

    SetTextAlign(hdc, TA_CENTER);
    SelectObject(hdc, hFont2);
    TextOut(hdc, rc.right/2, 125, "Выбор карты", 11);
    DeleteObject(hFont2);


    BitBlt(hdcOut, 0, 0, rc.right, rc.bottom, hdc, 0, 0, SRCCOPY);

    DeleteObject(hBitmapBuff);
    DeleteDC(hdc);
    EndPaint(hWnd, &ps);
    break;

  case WM_ERASEBKGND:
    break;

  case WM_COMMAND:
    switch(LOWORD(wParam)) {
      case ID_BUTTONBACK://возврат в меню
        hWndOther = FindWindow(chClassName6, NULL);
        GetWindowRect(hWnd, &rco);
        MoveWindow(hWndOther, rco.left, rco.top,
                   rco.right - rco.left, rco.bottom - rco.top, TRUE);
        ShowWindow(hWndOther, SW_SHOW);
        ShowWindow(hWnd, SW_HIDE);
        
        map = SendMessage(hListMaps, LB_GETCURSEL, 0, 0L);
        break;
    }
    break;

  case WM_SIZE://движение кнопок
    GetClientRect(hWnd, &rc);
    MoveWindow(hListMaps, rc.right/2 - 150, 150, 300, 255, FALSE);
    break;


  case WM_GETMINMAXINFO:
    ((MINMAXINFO *)lParam)->ptMinTrackSize.x = 850;
    ((MINMAXINFO *)lParam)->ptMinTrackSize.y = 570;
    break;

  case WM_DESTROY:
    PostQuitMessage(0);
    break;

  default:
    return DefWindowProc(hWnd, msg, wParam, lParam);
}
return 0;
}

LRESULT CALLBACK WndProcSettingP2(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
static HWND hEditUser2, hEditTexture2, hButtonLoadT2, hButtonSnakeTL, hButtonSnakeTR, hButtonBack;

HWND hWndOther;//Дескриптор окна, в которое осуществляется переход

HFONT hFont, hFont2;
HBRUSH hBrush, hBrush2;
RECT rc, rco;//окна, другого окна

switch(msg) {
  case WM_CREATE:
    SnakeSettingsAdd LS;

    if (LoadSettingsAdd(&LS)) {
      SnakeT2 = LS.SnakeT;
      strcpy(PlayerName2, LS.PlayerName);
    }
  
    GetClientRect(hWnd, &rc);

    hButtonBack = CreateWindow("button", NULL,
                                WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_BITMAP,
                                30, 30, 48, 48,
                                hWnd, (HMENU)ID_BUTTONBACK, GlobalhInst, NULL);
    SendMessage(hButtonBack, BM_SETIMAGE, IMAGE_BITMAP, LPARAM(hBitmapBack));

//для ввода имени игрока
    hEditUser2 = CreateWindow("edit", PlayerName2,
                                WS_CHILD | WS_VISIBLE | WS_BORDER | ES_CENTER,
                                rc.right/2 - 150, 130, 300, 25,
                                hWnd, (HMENU)ID_EDITUSER2, GlobalhInst, NULL);
    SendMessage(hEditUser2, EM_LIMITTEXT, 15, 0);
    
    hEditTexture2 = CreateWindow("edit", "C:\\",
                                WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT | ES_AUTOHSCROLL,
                                30, 315, 400, 25,
                                hWnd, (HMENU)ID_EDITTEXTURE2, GlobalhInst, NULL);
    SendMessage(hEditTexture2, EM_LIMITTEXT, 255, 0);
    
    hButtonLoadT2 = CreateWindow("button", "Загрузить текстуру",
                                WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                                30, 350, 150, 25,
                                hWnd, (HMENU)ID_BUTTONLOADT2, GlobalhInst, NULL);

    hButtonSnakeTL = CreateWindow("button", "<",
                                WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                                30, 200, 20, 80,
                                hWnd, (HMENU)ID_BUTTONSNAKETL2, GlobalhInst, NULL);

    hButtonSnakeTR = CreateWindow("button", ">",
                                WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                                220, 200, 20, 80,
                                hWnd, (HMENU)ID_BUTTONSNAKETR2, GlobalhInst, NULL);
                                
    if (LoadTextureAdd(TextureName2)) {
      SnakeTexture_p_2.set_img(TextureName2);
      SnakeTexture_p2_2.set_img(TextureName2);
      SnakeTexture_p_2.load();
      SnakeTexture_p2_2.load();
      SnakeP2.Body = &SnakeTexture_p_2;
      SnakeP2.Head = &SnakeTexture_p2_2;
      if (SnakeTexture_p_2.get_state()) {
        IsLoadT2 = 1;
        SetWindowText(hButtonLoadT2, "Удалить текстуру");
        SetWindowText(hEditTexture2, TextureName2);
      }
      else {
        MessageBox(hWnd, "Текстура не загружена. Проверьте наличие текстуры и правильность ввода.", "Ошибка", MB_OK | MB_ICONERROR);
        SetWindowText(hEditTexture2, TextureName2);
        remove("C:\\SBstudio\\snake\\snake_texture.txt");
        if (SnakeT2 == -1) {
          SnakeT2 = 0;
        }
      }
    }
    else {
      if (SnakeT2 == -1) {
        SnakeT2 = 0;
      }
    }
    break;

  case WM_PAINT:
    PAINTSTRUCT ps;
    HDC hdcOut, hdc;
    HANDLE hBitmapBuff;
    GetClientRect(hWnd, &rc);
    hFont = CreateFont(60,0,0,0,1,0,0,0,DEFAULT_CHARSET,0,0,0,0,"Arial Bold");
    hFont2 = CreateFont(20,0,0,0,0,1,0,0,DEFAULT_CHARSET,0,0,0,0,"Arial Bold");
    hBrush = CreateSolidBrush(RGB(204,204,204));
    hBrush2 = CreateSolidBrush(RGB(255, 255, 255));

    hdcOut = BeginPaint(hWnd, &ps);
    hdc = CreateCompatibleDC(hdcOut);
    hBitmapBuff = CreateCompatibleBitmap(hdcOut, rc.right, rc.bottom);
    SelectObject(hdc, hBitmapBuff);
//фон
    SelectObject(hdc, hBrush);
    Rectangle(hdc, -1, -1, rc.right + 1, rc.bottom + 1);
    DeleteObject(hBrush);

    SelectObject(hdc, hBrush2);
    Rectangle(hdc, 54, 199, 216, 281);
    DeleteObject(hBrush2);
    
    SelectObject(hdc, hBrush2);
    Rectangle(hdc, 29, 384, 191, 466);
    DeleteObject(hBrush2);

    SetBkMode(hdc, TRANSPARENT);
    SetTextAlign(hdc, TA_CENTER);
    TextOut(hdc, rc.right/2, rc.bottom - 18, "All rights reserved. SBstudio © 2016.", 37);

    SelectObject(hdc, hFont);
    TextOut(hdc, rc.right/2, 20, "Настройки (2 игрок)", 19);
    DeleteObject(hFont);

//надписи у кнопок настроек
    SetTextAlign(hdc, TA_LEFT);
    SelectObject(hdc, hFont2);
    TextOut(hdc, 260, 217, "Цвет змеи", 9);
    TextOut(hdc, 450, 315, "Пользовательская текстура", 25);
    DeleteObject(hFont2);

    switch (SnakeT2) {
      case -1:
        SnakeTexture_p_2.set_angle(0);
        SnakeTexture_p_2.set_cut(0,0,0,0);
        SnakeTexture_p_2.set_pos(55, 200);
        SnakeTexture_p_2.print_ex(hdc, 160, 80);
        break;

      case 0:
        SnakeTexture_a.set_angle(0);
        SnakeTexture_a.set_cut(0,0,0,0);
        SnakeTexture_a.set_pos(55, 200);
        SnakeTexture_a.print_ex(hdc, 160, 80);
        break;

      case 1:
        SnakeTexture_b.set_angle(0);
        SnakeTexture_b.set_cut(0,0,0,0);
        SnakeTexture_b.set_pos(55, 200);
        SnakeTexture_b.print_ex(hdc, 160, 80);
        break;

      case 2:
        SnakeTexture_c.set_angle(0);
        SnakeTexture_c.set_cut(0,0,0,0);
        SnakeTexture_c.set_pos(55, 200);
        SnakeTexture_c.print_ex(hdc, 160, 80);
        break;

      case 3:
        SnakeTexture_d.set_angle(0);
        SnakeTexture_d.set_cut(0,0,0,0);
        SnakeTexture_d.set_pos(55, 200);
        SnakeTexture_d.print_ex(hdc, 160, 80);
        break;

      case 4:
        SnakeTexture_e.set_angle(0);
        SnakeTexture_e.set_cut(0,0,0,0);
        SnakeTexture_e.set_pos(55, 200);
        SnakeTexture_e.print_ex(hdc, 160, 80);
        break;

      case 5:
        SnakeTexture_f.set_angle(0);
        SnakeTexture_f.set_cut(0,0,0,0);
        SnakeTexture_f.set_pos(55, 200);
        SnakeTexture_f.print_ex(hdc, 160, 80);
        break;
    }
    
    if (IsLoadT2) {
      SnakeTexture_p_2.set_pos(30, 385);
      SnakeTexture_p_2.set_angle(0);
      SnakeTexture_p_2.set_cut(0, 0, 0, 0);
      SnakeTexture_p_2.print_ex(hdc, 160, 80);
    }

    BitBlt(hdcOut, 0, 0, rc.right, rc.bottom, hdc, 0, 0, SRCCOPY);

    DeleteObject(hBitmapBuff);
    DeleteDC(hdc);
    EndPaint(hWnd, &ps);
    break;

  case WM_ERASEBKGND:
    break;

  case WM_COMMAND:
    switch(LOWORD(wParam)) {
      case ID_BUTTONBACK://возврат в меню
        hWndOther = FindWindow(chClassName6, NULL);
        GetWindowRect(hWnd, &rco);
        MoveWindow(hWndOther, rco.left, rco.top,
                   rco.right - rco.left, rco.bottom - rco.top, TRUE);
        ShowWindow(hWndOther, SW_SHOW);
        ShowWindow(hWnd, SW_HIDE);

        strcpy(PlayerName2, "");
        GetWindowText(hEditUser2, PlayerName2, 99);
        
        SnakeSettingsAdd SS;
        SS.SnakeT = SnakeT2;
        strcpy(SS.PlayerName, PlayerName2);
        SaveSettingsAdd(SS);
        break;
        
      case ID_BUTTONLOADT2:
        if (! IsLoadT2) {
          GetWindowText(hEditTexture2, TextureName2, 256);
          SnakeTexture_p_2.set_img(TextureName2);
          SnakeTexture_p2_2.set_img(TextureName2);
          SnakeTexture_p_2.load();
          SnakeTexture_p2_2.load();
          SnakeP2.Body = &SnakeTexture_p_2;
          SnakeP2.Head = &SnakeTexture_p2_2;
          if (SnakeTexture_p_2.get_state()) {
            SaveTextureAdd(TextureName2);
            IsLoadT2 = 1;
            SetWindowText(hButtonLoadT2, "Удалить текстуру");
            InvalidateRect(hWnd, NULL, TRUE);
            SnakeT2 = -1;
            MessageBox(hWnd, "Текстура успешно загружена.", "Операция завершена", MB_OK | MB_ICONASTERISK);
          }
          else {
            MessageBox(hWnd, "Текстура не загружена. Проверьте наличие текстуры и правильность ввода.", "Ошибка", MB_OK | MB_ICONERROR);
          }
        }
        else {
          IsLoadT2 = 0;
          remove("C:\\SBstudio\\snake\\snake_texture2.txt");
          SetWindowText(hButtonLoadT2, "Загрузить текстуру");
          InvalidateRect(hWnd, NULL, TRUE);
          if (SnakeT2 == -1) {
            SnakeT2 = 0;
          }
        }
        break;

      case ID_BUTTONSNAKETR2:
        switch (SnakeT2) {
          case -1:
            SnakeT2 = 0;
            break;

          case 0:
            SnakeT2 = 1;
            break;

          case 1:
            SnakeT2 = 2;
            break;

          case 2:
            SnakeT2 = 3;
            break;

          case 3:
            SnakeT2 = 4;
            break;

          case 4:
            SnakeT2 = 5;
            break;

          case 5:
            if (IsLoadT2) {
              SnakeT2 = -1;
            }
            else {
              SnakeT2 = 0;
            }
            break;
        }
        InvalidateRect(hWnd, NULL, TRUE);
        break;

      case ID_BUTTONSNAKETL2:
        switch (SnakeT2) {
          case -1:
            SnakeT2 = 5;
            break;

          case 0:
            if (IsLoadT2) {
              SnakeT2 = -1;
            }
            else {
              SnakeT2 = 5;
            }
            break;

          case 1:
            SnakeT2 = 0;
            break;

          case 2:
            SnakeT2 = 1;
            break;

          case 3:
            SnakeT2 = 2;
            break;

          case 4:
            SnakeT2 = 3;
            break;

          case 5:
            SnakeT2 = 4;
            break;
        }
        InvalidateRect(hWnd, NULL, TRUE);
        break;
    }
    break;

  case WM_SIZE://движение кнопок
    GetClientRect(hWnd, &rc);
    MoveWindow(hEditUser2, rc.right/2 - 150, 130, 300, 25, TRUE);
    break;


  case WM_GETMINMAXINFO:
    ((MINMAXINFO *)lParam)->ptMinTrackSize.x = 850;
    ((MINMAXINFO *)lParam)->ptMinTrackSize.y = 570;
    break;

  case WM_DESTROY:
    PostQuitMessage(0);
    break;

  default:
    return DefWindowProc(hWnd, msg, wParam, lParam);
}
return 0;
}

LRESULT CALLBACK WndProcCustom(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
static HWND hButtonBack;

HWND hWndOther;//Дескриптор окна, в которое осуществляется переход

static int offset_x = 0, offset_y = -20;
static int pen = 0;

HFONT hFont, hFont2;
HBRUSH hBrush, hBrush2;
RECT rc, rco;//окна, другого окна

HDC hdcL;

switch(msg) {
  case WM_CREATE:
    GetClientRect(hWnd, &rc);
    break;

  case WM_PAINT:
    PAINTSTRUCT ps;
    HDC hdcOut, hdc;
    HANDLE hBitmapBuff;
    GetClientRect(hWnd, &rc);
    hFont = CreateFont(60,0,0,0,1,0,0,0,DEFAULT_CHARSET,0,0,0,0,"Arial Bold");
    hFont2 = CreateFont(20,0,0,0,0,1,0,0,DEFAULT_CHARSET,0,0,0,0,"Arial Bold");
    hBrush = CreateSolidBrush(RGB(192, 192, 0));
    hBrush2 = CreateSolidBrush(RGB(255, 255, 255));

    hdcOut = BeginPaint(hWnd, &ps);
    hdc = CreateCompatibleDC(hdcOut);
    hBitmapBuff = CreateCompatibleBitmap(hdcOut, rc.right, rc.bottom);
    SelectObject(hdc, hBitmapBuff);
//фон
    SelectObject(hdc, hBrush);
    Rectangle(hdc, -1, -1, rc.right + 1, rc.bottom + 1);
    DeleteObject(hBrush);
    
    SelectObject(hdc, hBrush2);
    Rectangle(hdc, rc.right/2 - (MapWidth/2 + 1)*20 + offset_x, 40 + offset_y, rc.right/2 + (MapWidth/2 + 1)*20 + offset_x, 30 + (MapHeight + 2)*20 + offset_y);
    DeleteObject(hBrush2);

    SetBkMode(hdc, TRANSPARENT);
    SetTextAlign(hdc, TA_CENTER);
    SelectObject(hdc, hFont2);
    //TextOut(hdc, rc.right/2, 125, "Выбор карты", 11);
    DeleteObject(hFont2);
    
//отрисовка карты
    DrawCustom(MapWidth, MapHeight, offset_x, offset_y, hdc, hWnd);
    
//картинки в последнюю очередь
    PictBack2.set_pos(30, 10);
    PictBack2.print_std(hdc);

    BitBlt(hdcOut, 0, 0, rc.right, rc.bottom, hdc, 0, 0, SRCCOPY);

    DeleteObject(hBitmapBuff);
    DeleteDC(hdc);
    EndPaint(hWnd, &ps);
    break;

  case WM_ERASEBKGND:
    break;

  case WM_COMMAND:
    switch (LOWORD(wParam)) {
      case CMD_CLEAR:
        SetupCustomBoard(MapWidth, MapHeight);
        InvalidateRect(hWnd, NULL, TRUE);
        break;
        
      case CMD_PIXEL:
        pen = 0;
        break;
        
      case CMD_PEN:
        pen = 1;
        break;
        
      case CMD_RUBBER:
        pen = 2;
        break;
        
      case CMD_PLAY:
        hWndOther = FindWindow(chClassName2, NULL);
        GetWindowRect(hWnd, &rco);
        MoveWindow(hWndOther, rco.left, rco.top,
                   rco.right - rco.left, rco.bottom - rco.top, TRUE);

        PlayingRoutine = 3;
        SetTimer(hWndOther, ID_TIMERPLAY, 100, NULL);
        if (PlayerCount > 1)
          SetTimer(hWndOther, ID_TIMERPLAY2, 100, NULL);

        GetClientRect(hWnd, &rc);
        hdcL = GetDC(hWnd);
        SetTextAlign(hdcL, TA_CENTER);
        SetBkMode(hdcL, TRANSPARENT);
        SelectObject(hdcL, hFont);
        TextOut(hdcL, rc.right/2, 100, "Загрузка", 8);
        DeleteObject(hFont);
        ReleaseDC(hWnd, hdcL);
        Sleep(500);

        ShowWindow(hWndOther, SW_SHOW);
        ShowWindow(hWnd, SW_HIDE);
        break;
    }
    break;
    
  case WM_LBUTTONDOWN:
    bool ToField;
    ToField = 1;
    int xPos, yPos, xIndex, yIndex;
    xPos = LOWORD(lParam);
    yPos = HIWORD(lParam);
    GetClientRect(hWnd, &rc);
    
    if (xPos > 30 && xPos < 78 && yPos > 10 && yPos < 58) {
      hWndOther = FindWindow(chClassName6, NULL);
      GetWindowRect(hWnd, &rco);
      MoveWindow(hWndOther, rco.left, rco.top,
                 rco.right - rco.left, rco.bottom - rco.top, TRUE);
      ShowWindow(hWndOther, SW_SHOW);
      ShowWindow(hWnd, SW_HIDE);
      ToField = 0;
    }
    if (ToField) {
      switch (pen) {
        case 0:
          xIndex = (xPos - (rc.right/2 - (MapWidth/2 + 1)*20 + offset_x))/20;
          yIndex = (yPos - (30 + offset_y))/20;
          if (xIndex > 0 && xIndex <= MapWidth && yIndex > 0 && yIndex <= MapHeight) {
            if (map_field[yIndex][xIndex] != '+') {
              map_field[yIndex][xIndex] = '+';
            }
            else {
              map_field[yIndex][xIndex] = ' ';
            }
          }
          break;
      }
    }
    ToField = 1;
    InvalidateRect(hWnd, NULL, TRUE);
    break;
    
  case WM_MOUSEMOVE:
    xPos = LOWORD(lParam);
    yPos = HIWORD(lParam);
    GetClientRect(hWnd, &rc);
    
    if ((GetKeyState(VK_LBUTTON) & 0x8000) != 0) {
      switch (pen) {
        case 1:
        case 2:
          xIndex = (xPos - (rc.right/2 - (MapWidth/2 + 1)*20 + offset_x))/20;
          yIndex = (yPos - (30 + offset_y))/20;
          if (xIndex > 0 && xIndex <= MapWidth && yIndex > 0 && yIndex <= MapHeight) {
            if (pen == 1) {
              map_field[yIndex][xIndex] = '+';
            }
            else {
              map_field[yIndex][xIndex] = ' ';
            }
          }
          break;
      }
    }

    InvalidateRect(hWnd, NULL, TRUE);
    break;

  case WM_SIZE://движение кнопок
    GetClientRect(hWnd, &rc);
    break;


  case WM_GETMINMAXINFO:
    ((MINMAXINFO *)lParam)->ptMinTrackSize.x = 850;
    ((MINMAXINFO *)lParam)->ptMinTrackSize.y = 570;
    break;

  case WM_DESTROY:
    PostQuitMessage(0);
    break;

  default:
    return DefWindowProc(hWnd, msg, wParam, lParam);
}
return 0;
}