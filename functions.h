#include "defines.h"

class SnakeMain {        //Љласс змеи
public:
  // Координаты змеи
  int snakeX[200], snakeY[200];

  //переменные игры
  bool GameOver, start_game, IsTap;
  int _x, _y; // Передвижение змеи на определённое количество шагов на следующей итерации цикла

  // переменные-счетчики
  int len; // длина змеи
  int score; // результат
  int applec; // счет Яблок
  int OldApplec; // OldApplec = applec - 1 (длЯ генерации нового Яблока)
  int TimerSpeed;
  int TimeEffect;//только в advanced-режиме
  int TimeToOver;//только в time-режиме

  char SumbHead, SumbBody;

  SnakeMain(char SumbHead, char SumbBody) {this->SumbHead = SumbHead; this->SumbBody = SumbBody;}
} SnakeMain1('O', 'o'), SnakeMain2('Q', 'q');

SnakeMain *SMarray[2] = {&SnakeMain1, &SnakeMain2};

struct SnakeTexture {
  ImgPrint *Body;
  ImgPrint *Head;
};

class Detonate {
public:
  int BombX, BombY;
  int state;

  Detonate(){this->state = 10;}
};

struct SnakeSettings {
  char PlayerName[50];
  bool Save, walls, SCrossing, Accelerate;
  int Speed, SnakeT, Control, widthX, heightY, PlayTime;
};

struct SnakeSettingsAdd {
  char PlayerName[50];
  int SnakeT;
};

char field[60 + 2][60 + 3]; // field[y(строка)][x(столбец)]
char map_field[60 + 2][60 + 3]; // field[y(строка)][x(столбец)]
WndMatrix wm;

//главная функция игры
void Cycle(HWND hWnd, SnakeMain &ptSnakeMain, int &Time, int &appleX, int &appleY, int GoldAppleX, int GoldAppleY,
bool &IsGoldApple, int &TimeAppleRespawn, bool &GameOver, bool &OutGameOver, bool &pause, bool &field_setup, int TimerProc, int PlayerNum);

//вызывать ДО каких - либо действий;
// Рисует поле заданных размеров
void Draw(char SumbHead, char SumbBody, SnakeTexture &st, int _x, int _y, HDC hdc, HWND hwnd);
void DrawCustom(int MapWidth, int MapHeight, int offset_x, int offset_y, HDC hdc, HWND hwnd);

//выводит информацию
void Write(bool slot, int score, int len, int applec, HDC hdc, HWND hwnd);
void AdvancedWrite(bool slot, int score, int len, int applec, HDC hdc, HWND hwnd);
void TimeWrite(bool slot, int TimeToOver, int score, int len, int applec, HDC hdc, HWND hwnd);

// Начальная настройка игры
void SetupSnake(char SumbHead, char SumbBody, int *snakeX, int *snakeY, int PlayerCount);
void SetupField();
void SetupFieldAdvanced();
void SetupFieldCustom();
void SetupCustomBoard(int MapWidth, int MapHeight);

// Генерация предметов (яблоки, $, временная защита и мины)
void GenerationObjects(int applec, int &OldApplec, int &appleX, int &appleY, bool spawn);

// Генерация предметов (яблоки, $, временная защита и мины)
void GenerationObject(int what, int &appleX, int &appleY);

// удаление объектов с поля
void DestroyObjects(int what);

// Движение
void Move(char SumbHead, char SumbBody, int *snakeX, int *snakeY, int _x, int _y, int score, int len, int applec);

// Логическая функция отвечает за происходящее после врезания в стену, съедания чего-либо
void Logic(SnakeMain **SMarray, char SumbHead, int *snakeX, int *snakeY, int _x, int _y, int appleX, int appleY, bool walls,
           bool SCrossing, bool &GameOver, int &score, int &len, int &applec, int PlayerNum);
// Логическая функция
bool AdvancedLogic(int *snakeX, int *snakeY, int _x, int _y, int GoldAppleX, int GoldAppleY, int &TimeEffect);
void BombLogic(SnakeMain &ptSnakeMain, int AppleX, int AppleY, int GoldAppleX, int GoldAppleY, int BombX, int BombY, int &len, int &OldApplec, bool &GameOver);
void TimeLogic(int applec, int OldApplec, int &TimeToOver, bool &GameOver);

void LoadResults(char *num_pos, char *load_str, char *load_num, int filenum);
bool LoadSettings(SnakeSettings *LS);
bool LoadSettingsAdd(SnakeSettingsAdd *LS);
bool LoadTexture(char *TextureName);
bool LoadTextureAdd(char *TextureName);

void SaveResults(int score, char *name, int filenum);
void SaveSettings(SnakeSettings SS);
void SaveSettingsAdd(SnakeSettingsAdd SS);
void SaveTexture(char *TextureName);
void SaveTextureAdd(char *TextureName);
void swap(char *a, char *b);
//------------------------------------------------------------------------


void Cycle(HWND hWnd, SnakeMain &ptSnakeMain, int &Time, int &appleX, int &appleY, int GoldAppleX, int GoldAppleY, 
bool &IsGoldApple, int &TimeAppleRespawn, bool &GameOver, bool &OutGameOver, bool &pause, bool &field_setup, int TimerProc, int PlayerNum) {
        switch (PlayingRoutine){
          case 0://классика
            if (ptSnakeMain.start_game == 0) {
              ptSnakeMain._x = 0;
              ptSnakeMain._y = 1;
              ptSnakeMain.len = 2;
              ptSnakeMain.score = 0;
              ptSnakeMain.applec = 0;
              ptSnakeMain.OldApplec = 0;
              if (PlayTime == 0)
                Time = 1;
              else
                Time = PlayTime * 60;

              switch (Speed) {
                case 0:
                  ptSnakeMain.TimerSpeed = 130;
                  break;

                case 1:
                  ptSnakeMain.TimerSpeed = 100;
                  break;

                case 2:
                  ptSnakeMain.TimerSpeed = 70;
                  break;
              }
              SetTimer(hWnd, TimerProc, ptSnakeMain.TimerSpeed, NULL);
              SetTimer(hWnd, ID_TIMERSECOND, 1000, NULL);

              if (! field_setup) {
                SetupField();

                int AX, AY;
                GenerationObject(0, AX, AY);
                appleX = AX;
                appleY = AY;

                field_setup = 1;
              }
              SetupSnake(ptSnakeMain.SumbHead, ptSnakeMain.SumbBody, ptSnakeMain.snakeX, ptSnakeMain.snakeY, PlayerCount);
              pause = ptSnakeMain.start_game = 1;
              InvalidateRect(hWnd, NULL, TRUE);
            }
            if (pause == 0 && GameOver == 0) {
              Logic(SMarray, ptSnakeMain.SumbHead, ptSnakeMain.snakeX, ptSnakeMain.snakeY, ptSnakeMain._x, ptSnakeMain._y, appleX, appleY, walls, SCrossing,
                     GameOver, ptSnakeMain.score, ptSnakeMain.len, ptSnakeMain.applec, PlayerNum);
              if (! GameOver)
                Move(ptSnakeMain.SumbHead, ptSnakeMain.SumbBody, ptSnakeMain.snakeX, ptSnakeMain.snakeY, ptSnakeMain._x,
                     ptSnakeMain._y, ptSnakeMain.score, ptSnakeMain.len, ptSnakeMain.applec);
              if (Accelerate && ptSnakeMain.OldApplec != ptSnakeMain.applec && ptSnakeMain.TimerSpeed > 40) {
                ptSnakeMain.TimerSpeed -= 1;
                SetTimer(hWnd, TimerProc, ptSnakeMain.TimerSpeed, NULL);
              }
              GenerationObjects(ptSnakeMain.applec, ptSnakeMain.OldApplec, appleX, appleY, FALSE);
              ptSnakeMain.IsTap = 0;
              if (GameOver == 1 || OutGameOver == 1) {
                GameOver = 1;
                pause = 1;
                if (!OutGameOver)
                  ptSnakeMain.GameOver = 1;
                OutGameOver = 0;
                KillTimer(hWnd, ID_TIMERSECOND);
                if (Save == 1 && PlayerCount == 1) {
                  SaveResults(ptSnakeMain.score, PlayerName, PlayingRoutine);
                  LoadResults(numbers, names, results, filenum);
                }
              }
              InvalidateRect(hWnd, NULL, TRUE);
            }
            break;

          case 1://advanced
          case 3://custom
            if (ptSnakeMain.start_game == 0) {
              ptSnakeMain._x = 0;
              ptSnakeMain._y = 1;
              ptSnakeMain.len = 2;
              ptSnakeMain.score = 0;
              ptSnakeMain.applec = 0;
              ptSnakeMain.OldApplec = 0;
              if (PlayTime == 0)
                Time = 1;
              else
                Time = PlayTime * 60;

              switch (Speed) {
                case 0:
                  ptSnakeMain.TimerSpeed = 130;
                  break;

                case 1:
                  ptSnakeMain.TimerSpeed = 100;
                  break;

                case 2:
                  ptSnakeMain.TimerSpeed = 70;
                  break;
              }
              SetTimer(hWnd, TimerProc, ptSnakeMain.TimerSpeed, NULL);
              SetTimer(hWnd, ID_TIMERSECOND, 1000, NULL);
              SetTimer(hWnd, ID_TIMEREXPLOSION, 150, NULL);

              if (! field_setup) {
                if (PlayingRoutine == 1)
                  SetupFieldAdvanced();
                else
                  SetupFieldCustom();

                int AX, AY;
                GenerationObject(0, AX, AY);
                appleX = AX;
                appleY = AY;

                field_setup = 1;
              }
              SetupSnake(ptSnakeMain.SumbHead, ptSnakeMain.SumbBody, ptSnakeMain.snakeX, ptSnakeMain.snakeY, PlayerCount);
              pause = ptSnakeMain.start_game = 1;
              InvalidateRect(hWnd, NULL, TRUE);
            }
            if (pause == 0 && GameOver == 0) {
              Logic(SMarray, ptSnakeMain.SumbHead, ptSnakeMain.snakeX, ptSnakeMain.snakeY, ptSnakeMain._x, ptSnakeMain._y, appleX, appleY, walls, SCrossing,
                    GameOver, ptSnakeMain.score, ptSnakeMain.len, ptSnakeMain.applec, PlayerNum);
              if (! AdvancedLogic(ptSnakeMain.snakeX, ptSnakeMain.snakeY, ptSnakeMain._x, ptSnakeMain._y, GoldAppleX, GoldAppleY, ptSnakeMain.TimeEffect))
                IsGoldApple = 0;
              if (ptSnakeMain.OldApplec != ptSnakeMain.applec && ptSnakeMain.TimeEffect > 0)
                ptSnakeMain.score += 20;
              if (! GameOver)
                Move(ptSnakeMain.SumbHead, ptSnakeMain.SumbBody, ptSnakeMain.snakeX, ptSnakeMain.snakeY, ptSnakeMain._x,
                     ptSnakeMain._y, ptSnakeMain.score, ptSnakeMain.len, ptSnakeMain.applec);
              if (Accelerate && ptSnakeMain.OldApplec != ptSnakeMain.applec && ptSnakeMain.TimerSpeed > 40) {
                ptSnakeMain.TimerSpeed -= 1;
                SetTimer(hWnd, TimerProc, ptSnakeMain.TimerSpeed, NULL);
              }
              GenerationObjects(ptSnakeMain.applec, ptSnakeMain.OldApplec, appleX, appleY, FALSE);
              ptSnakeMain.IsTap = 0;
              if (GameOver == 1 || OutGameOver == 1) {
                GameOver = 1;
                pause = 1;
                if (!OutGameOver)
                  ptSnakeMain.GameOver = 1;
                OutGameOver = 0;
                KillTimer(hWnd, ID_TIMERSECOND);
                KillTimer(hWnd, ID_TIMEREXPLOSION);
                if (Save == 1 && PlayerCount == 1) {
                  SaveResults(ptSnakeMain.score, PlayerName, PlayingRoutine);
                  LoadResults(numbers, names, results, filenum);
                }
              }
              InvalidateRect(hWnd, NULL, TRUE);
            }
            break;

          case 2://time-режим
            if (ptSnakeMain.start_game == 0) {
              ptSnakeMain._x = 0;
              ptSnakeMain._y = 1;
              ptSnakeMain.len = 2;
              ptSnakeMain.score = 0;
              ptSnakeMain.applec = 0;
              ptSnakeMain.OldApplec = 0;
              ptSnakeMain.TimeToOver = 15;//time
              if (PlayTime == 0)
                Time = 1;
              else
                Time = PlayTime * 60;

              switch (Speed) {
                case 0:
                  ptSnakeMain.TimerSpeed = 130;
                  break;

                case 1:
                  ptSnakeMain.TimerSpeed = 100;
                  break;

                case 2:
                  ptSnakeMain.TimerSpeed = 70;
                  break;
              }
              SetTimer(hWnd, TimerProc, ptSnakeMain.TimerSpeed, NULL);
              SetTimer(hWnd, ID_TIMERSECOND, 1000, NULL);

              if (! field_setup) {
                SetupField();

                int AX, AY;
                GenerationObject(0, AX, AY);
                appleX = AX;
                appleY = AY;

                TimeAppleRespawn = 5;

                field_setup = 1;
              }
              SetupSnake(ptSnakeMain.SumbHead, ptSnakeMain.SumbBody, ptSnakeMain.snakeX, ptSnakeMain.snakeY, PlayerCount);
              pause = ptSnakeMain.start_game = 1;
              InvalidateRect(hWnd, NULL, TRUE);
            }
            if (pause == 0 && GameOver == 0) {
              if (ptSnakeMain.applec != ptSnakeMain.OldApplec)
                TimeAppleRespawn = 5;
              Logic(SMarray, ptSnakeMain.SumbHead, ptSnakeMain.snakeX, ptSnakeMain.snakeY, ptSnakeMain._x, ptSnakeMain._y, appleX, appleY, walls, SCrossing,
                     GameOver, ptSnakeMain.score, ptSnakeMain.len, ptSnakeMain.applec, PlayerNum);
              if (! GameOver)
                Move(ptSnakeMain.SumbHead, ptSnakeMain.SumbBody, ptSnakeMain.snakeX, ptSnakeMain.snakeY, ptSnakeMain._x,
                     ptSnakeMain._y, ptSnakeMain.score, ptSnakeMain.len, ptSnakeMain.applec);
              TimeLogic(ptSnakeMain.applec, ptSnakeMain.OldApplec, ptSnakeMain.TimeToOver, GameOver);
              if (Accelerate && ptSnakeMain.OldApplec != ptSnakeMain.applec && ptSnakeMain.TimerSpeed > 40) {
                ptSnakeMain.TimerSpeed -= 1;
                SetTimer(hWnd, TimerProc, ptSnakeMain.TimerSpeed, NULL);
              }
              GenerationObjects(ptSnakeMain.applec, ptSnakeMain.OldApplec, appleX, appleY, FALSE);
              ptSnakeMain.IsTap = 0;
              if (GameOver == 1 || OutGameOver == 1) {
                GameOver = 1;
                pause = 1;
                if (!OutGameOver)
                  ptSnakeMain.GameOver = 1;
                OutGameOver = 0;
                KillTimer(hWnd, ID_TIMERSECOND);
                if (Save == 1 && PlayerCount == 1) {
                  SaveResults(ptSnakeMain.score, PlayerName, PlayingRoutine);
                  LoadResults(numbers, names, results, filenum);
                }
              }
              InvalidateRect(hWnd, NULL, TRUE);
            }
            break;
        }
}

void SetupSnake(char SumbHead, char SumbBody, int *snakeX, int *snakeY, int PlayerCount) {
  static int SetupNum = 1;

  for (int i = 0; i <= 200; i++) {
    snakeX[i] = 0;
    snakeY[i] = 0;
  }

  // Генерация начальных координат змеи
  int IsSetup = 0;
  if (PlayingRoutine == 1)
    switch (map) {
      case 14:
        switch (PlayerCount) {
          case 1:
            snakeX[0] = widthX / 2;
            snakeY[0] = 3;
            snakeX[1] = widthX / 2;
            snakeY[1] = 2;

            SetupNum = 1;
            break;

          case 2:
            switch(SetupNum) {
              case 1:
                snakeX[0] = widthX / 3 * 2;
                snakeY[0] = 3;
                snakeX[1] = widthX / 3 * 2;
                snakeY[1] = 2;

                SetupNum = 2;
                break;

              case 2:
                snakeX[0] = widthX / 3 + 2;
                snakeY[0] = 3;
                snakeX[1] = widthX / 3 + 2;
                snakeY[1] = 2;

                SetupNum = 1;
                break;
            }
            break;
        }
        IsSetup = 1;
        break;
    }
    
  if (!IsSetup)
    switch (PlayerCount) {
      case 1:
        snakeX[0] = widthX / 2;
        snakeY[0] = heightY / 2;
        snakeX[1] = widthX / 2;
        snakeY[1] = heightY / 2 - 1;

        SetupNum = 1;
        break;

      case 2:
        switch(SetupNum) {
          case 1:
            snakeX[0] = widthX / 3 * 2;
            snakeY[0] = heightY / 2;
            snakeX[1] = widthX / 3 * 2;
            snakeY[1] = heightY / 2 - 1;

            SetupNum = 2;
            break;

          case 2:
            snakeX[0] = widthX / 3 + 2;
            snakeY[0] = heightY / 2;
            snakeX[1] = widthX / 3 + 2;
            snakeY[1] = heightY / 2 - 1;

            SetupNum = 1;
            break;
        }
        break;
    }

  // Перенос этих координат в массив field
  field[snakeY[0]][snakeX[0]] = SumbHead;
  field[snakeY[1]][snakeX[1]] = SumbBody;
}

void SetupField() {
  // Генерация поля и стен
  for (int y = 0; y < heightY + 2; y++)
    for (int x = 0; x < widthX + 2; x++)
      if ((y == 0) || (y == heightY + 1) || (x == 0) || (x == widthX + 1))
        field[y][x] = '#';
      else
        field[y][x] = ' ';
}

void SetupFieldAdvanced() {
  char chWidth[11], chHeight[11];
  switch (map) {
    case 1:
      widthX = 40;
      heightY = 20;
      break;
          
    case 2:
      widthX = 30;
      heightY = 30;
      break;
            
    case 3:
      widthX = 40;
      heightY = 20;
      break;
      
    case 4:
      widthX = 30;
      heightY = 30;
      break;
            
    case 5:
      widthX = 40;
      heightY = 20;
      break;
            
    case 6:
      widthX = 40;
      heightY = 20;
      break;

    case 7:
      widthX = 40;
      heightY = 20;
      break;
      
    case 8:
      widthX = 30;
      heightY = 30;
      break;
      
    case 9:
      widthX = 30;
      heightY = 30;
      break;
      
    case 10:
      widthX = 30;
      heightY = 30;
      break;
      
    case 11:
      widthX = 40;
      heightY = 20;
      break;
      
    case 12:
      widthX = 40;
      heightY = 20;
      break;
      
    case 13:
      widthX = 30;
      heightY = 30;
      break;
      
    case 14:
      widthX = 40;
      heightY = 20;
      break;
  }
  itoa(widthX, chWidth, 10);
  itoa(heightY, chHeight, 10);
  SetWindowText(hEditWidthG, chWidth);
  SetWindowText(hEditHeightG, chHeight);
  
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

  for (int y = 0; y < heightY + 2; y++)
    for (int x = 0; x < widthX + 2; x++)
      field[y][x] = ' ';

  switch (map) {
    case 0:
      SetupField();
      break;

    case 1:
       strcpy(field[0], "##########################################");
       strcpy(field[1], "#                                        #");
       strcpy(field[2], "#                                        #");
       strcpy(field[3], "#                                        #");
       strcpy(field[4], "#                                        #");
       strcpy(field[5], "#     ++++++++++++++++++++++++++++++     #");
       strcpy(field[6], "#                                        #");
       strcpy(field[7], "#                                        #");
       strcpy(field[8], "#                                        #");
       strcpy(field[9], "#                                        #");
      strcpy(field[10], "#                                        #");
      strcpy(field[11], "#                                        #");
      strcpy(field[12], "#                                        #");
      strcpy(field[13], "#                                        #");
      strcpy(field[14], "#                                        #");
      strcpy(field[15], "#                                        #");
      strcpy(field[16], "#     ++++++++++++++++++++++++++++++     #");
      strcpy(field[17], "#                                        #");
      strcpy(field[18], "#                                        #");
      strcpy(field[19], "#                                        #");
      strcpy(field[20], "#                                        #");
      strcpy(field[21], "##########################################");
      break;
      
    case 2:
       strcpy(field[0], "################################");
       strcpy(field[1], "#                              #");
       strcpy(field[2], "#                              #");
       strcpy(field[3], "#                              #");
       strcpy(field[4], "#                              #");
       strcpy(field[5], "#     +++++++++++++++++        #");
       strcpy(field[6], "#                      ++      #");
       strcpy(field[7], "#                        +     #");
       strcpy(field[8], "#                        +     #");
       strcpy(field[9], "#                         +    #");
      strcpy(field[10], "#     +++++++++++++++     +    #");
      strcpy(field[11], "#    +               +    +    #");
      strcpy(field[12], "#    +               +    +    #");
      strcpy(field[13], "#    +               +    +    #");
      strcpy(field[14], "#    +               +    +    #");
      strcpy(field[15], "#    +               +    +    #");
      strcpy(field[16], "#    +               +    +    #");
      strcpy(field[17], "#    +               +    +    #");
      strcpy(field[18], "#    +               +    +    #");
      strcpy(field[19], "#    +               +    +    #");
      strcpy(field[20], "#    +               +    +    #");
      strcpy(field[21], "#    +               +    +    #");
      strcpy(field[22], "#    +          +++++     +    #");
      strcpy(field[23], "#    +                    +    #");
      strcpy(field[24], "#     +                  +     #");
      strcpy(field[25], "#     +                  +     #");
      strcpy(field[26], "#      ++              ++      #");
      strcpy(field[27], "#        ++++++++++++++        #");
      strcpy(field[28], "#                              #");
      strcpy(field[29], "#                              #");
      strcpy(field[30], "#                              #");
      strcpy(field[31], "################################");
      break;
      
    case 3:
       strcpy(field[0], "##########################################");
       strcpy(field[1], "#                                        #");
       strcpy(field[2], "#                                        #");
       strcpy(field[3], "#                                        #");
       strcpy(field[4], "#                                        #");
       strcpy(field[5], "#             ++++++++++++++             #");
       strcpy(field[6], "#                                        #");
       strcpy(field[7], "#          +                  +          #");
       strcpy(field[8], "#          +                  +          #");
       strcpy(field[9], "#          +                  +          #");
      strcpy(field[10], "#          +                  +          #");
      strcpy(field[11], "#          +                  +          #");
      strcpy(field[12], "#          +                  +          #");
      strcpy(field[13], "#          +                  +          #");
      strcpy(field[14], "#          +                  +          #");
      strcpy(field[15], "#          +                  +          #");
      strcpy(field[16], "#           ++++          ++++           #");
      strcpy(field[17], "#               +        +               #");
      strcpy(field[18], "#              ++        ++              #");
      strcpy(field[19], "#                                        #");
      strcpy(field[20], "#                                        #");
      strcpy(field[21], "##########################################");
      break;
      
    case 4:
       strcpy(field[0], "################################");
       strcpy(field[1], "#                              #");
       strcpy(field[2], "#                              #");
       strcpy(field[3], "#                              #");
       strcpy(field[4], "#                              #");
       strcpy(field[5], "#                              #");
       strcpy(field[6], "#                              #");
       strcpy(field[7], "#     +++              +++     #");
       strcpy(field[8], "#     +++              +++     #");
       strcpy(field[9], "#     +++              +++     #");
      strcpy(field[10], "#                              #");
      strcpy(field[11], "#                              #");
      strcpy(field[12], "#                              #");
      strcpy(field[13], "#                              #");
      strcpy(field[14], "#                              #");
      strcpy(field[15], "#                              #");
      strcpy(field[16], "#                              #");
      strcpy(field[17], "#                              #");
      strcpy(field[18], "#                              #");
      strcpy(field[19], "#                              #");
      strcpy(field[20], "#                              #");
      strcpy(field[21], "#                              #");
      strcpy(field[22], "#      ++              ++      #");
      strcpy(field[23], "#       ++            ++       #");
      strcpy(field[24], "#        ++++++++++++++        #");
      strcpy(field[25], "#          ++++++++++          #");
      strcpy(field[26], "#                              #");
      strcpy(field[27], "#                              #");
      strcpy(field[28], "#                              #");
      strcpy(field[29], "#                              #");
      strcpy(field[30], "#                              #");
      strcpy(field[31], "################################");
      break;
      
    case 5:
       strcpy(field[0], "##########################################");
       strcpy(field[1], "#                                        #");
       strcpy(field[2], "#                                        #");
       strcpy(field[3], "#     +++   +++                          #");
       strcpy(field[4], "#       +++++                            #");
       strcpy(field[5], "#                                        #");
       strcpy(field[6], "#                         ++             #");
       strcpy(field[7], "#                          ++            #");
       strcpy(field[8], "#                           ++           #");
       strcpy(field[9], "#      ++++                  ++          #");
      strcpy(field[10], "#      +                                 #");
      strcpy(field[11], "#      +                         +       #");
      strcpy(field[12], "#      +                         +       #");
      strcpy(field[13], "#                                +       #");
      strcpy(field[14], "#                                +       #");
      strcpy(field[15], "#                                +       #");
      strcpy(field[16], "#                                +       #");
      strcpy(field[17], "#                                +       #");
      strcpy(field[18], "#          +++++++++++++++++++++++       #");
      strcpy(field[19], "#                                        #");
      strcpy(field[20], "#                                        #");
      strcpy(field[21], "##########################################");
      break;
      
    case 6:
       strcpy(field[0], "##########################################");
       strcpy(field[1], "#                                        #");
       strcpy(field[2], "#                                        #");
       strcpy(field[3], "#                                        #");
       strcpy(field[4], "#                                        #");
       strcpy(field[5], "#            +++          +++            #");
       strcpy(field[6], "#        +++++++          +++++++        #");
       strcpy(field[7], "#             ++          ++             #");
       strcpy(field[8], "#             +            +             #");
       strcpy(field[9], "#             +            +             #");
      strcpy(field[10], "#             +            +             #");
      strcpy(field[11], "#             +            +             #");
      strcpy(field[12], "#             +            +             #");
      strcpy(field[13], "#             +            +             #");
      strcpy(field[14], "#             ++          ++             #");
      strcpy(field[15], "#        +++++++          ++++++++       #");
      strcpy(field[16], "#            +++          +++            #");
      strcpy(field[17], "#                                        #");
      strcpy(field[18], "#                                        #");
      strcpy(field[19], "#                                        #");
      strcpy(field[20], "#                                        #");
      strcpy(field[21], "##########################################");
      break;
      
    case 7:
       strcpy(field[0], "##########################################");
       strcpy(field[1], "#                                        #");
       strcpy(field[2], "#                                        #");
       strcpy(field[3], "#                                        #");
       strcpy(field[4], "#                      +  +              #");
       strcpy(field[5], "#             ++++++++++  ++             #");
       strcpy(field[6], "#            +              +            #");
       strcpy(field[7], "#           +                +           #");
       strcpy(field[8], "#          +                  +          #");
       strcpy(field[9], "#         +                    +         #");
      strcpy(field[10], "#        +                      +        #");
      strcpy(field[11], "#        +                      +        #");
      strcpy(field[12], "#        +                      +        #");
      strcpy(field[13], "#        +                      +        #");
      strcpy(field[14], "#                                        #");
      strcpy(field[15], "#                                        #");
      strcpy(field[16], "#        ++++++++++++++++++++++++        #");
      strcpy(field[17], "#                                        #");
      strcpy(field[18], "#                                        #");
      strcpy(field[19], "#                                        #");
      strcpy(field[20], "#                                        #");
      strcpy(field[21], "##########################################");
      break;
      
    case 8:
       strcpy(field[0], "################################");
       strcpy(field[1], "#                              #");
       strcpy(field[2], "#                              #");
       strcpy(field[3], "#                              #");
       strcpy(field[4], "#                              #");
       strcpy(field[5], "#                              #");
       strcpy(field[6], "#     ++++++++++++++++++++     #");
       strcpy(field[7], "#                              #");
       strcpy(field[8], "#                              #");
       strcpy(field[9], "#     +                  +     #");
      strcpy(field[10], "#     +                  +     #");
      strcpy(field[11], "#     +                  +     #");
      strcpy(field[12], "#     +                  +     #");
      strcpy(field[13], "#     +                  +     #");
      strcpy(field[14], "#     +                  +     #");
      strcpy(field[15], "#     +                  +     #");
      strcpy(field[16], "#     +                  +     #");
      strcpy(field[17], "#     +                  +     #");
      strcpy(field[18], "#     +                  +     #");
      strcpy(field[19], "#     +                  +     #");
      strcpy(field[20], "#     +                  +     #");
      strcpy(field[21], "#     +                  +     #");
      strcpy(field[22], "#     +                  +     #");
      strcpy(field[23], "#                              #");
      strcpy(field[24], "#                              #");
      strcpy(field[25], "#     ++++++++++++++++++++     #");
      strcpy(field[26], "#                              #");
      strcpy(field[27], "#                              #");
      strcpy(field[28], "#                              #");
      strcpy(field[29], "#                              #");
      strcpy(field[30], "#                              #");
      strcpy(field[31], "################################");
      break;
      
    case 9:
       strcpy(field[0], "################################");
       strcpy(field[1], "#                              #");
       strcpy(field[2], "#                              #");
       strcpy(field[3], "#                              #");
       strcpy(field[4], "#                              #");
       strcpy(field[5], "#                              #");
       strcpy(field[6], "#     +++++++++  +++++++++     #");
       strcpy(field[7], "#     +                  +     #");
       strcpy(field[8], "#     +                  +     #");
       strcpy(field[9], "#     +                  +     #");
      strcpy(field[10], "#     +                  +     #");
      strcpy(field[11], "#     +                  +     #");
      strcpy(field[12], "#     +                  +     #");
      strcpy(field[13], "#     +                  +     #");
      strcpy(field[14], "#     +                  +     #");
      strcpy(field[15], "#                              #");
      strcpy(field[16], "#                              #");
      strcpy(field[17], "#     +                  +     #");
      strcpy(field[18], "#     +                  +     #");
      strcpy(field[19], "#     +                  +     #");
      strcpy(field[20], "#     +                  +     #");
      strcpy(field[21], "#     +                  +     #");
      strcpy(field[22], "#     +                  +     #");
      strcpy(field[23], "#     +                  +     #");
      strcpy(field[24], "#     +                  +     #");
      strcpy(field[25], "#     +++++++++  +++++++++     #");
      strcpy(field[26], "#                              #");
      strcpy(field[27], "#                              #");
      strcpy(field[28], "#                              #");
      strcpy(field[29], "#                              #");
      strcpy(field[30], "#                              #");
      strcpy(field[31], "################################");
      break;
      
    case 10:
       strcpy(field[0], "################################");
       strcpy(field[1], "#++                          ++#");
       strcpy(field[2], "#++                          ++#");
       strcpy(field[3], "#  +                        +  #");
       strcpy(field[4], "#   +                      +   #");
       strcpy(field[5], "#    +                    +    #");
       strcpy(field[6], "#     +                  +     #");
       strcpy(field[7], "#      +                +      #");
       strcpy(field[8], "#       +              +       #");
       strcpy(field[9], "#        +            +        #");
      strcpy(field[10], "#         +          +         #");
      strcpy(field[11], "#          +        +          #");
      strcpy(field[12], "#           +      +           #");
      strcpy(field[13], "#            +    +            #");
      strcpy(field[14], "#                              #");
      strcpy(field[15], "#                              #");
      strcpy(field[16], "#                              #");
      strcpy(field[17], "#                              #");
      strcpy(field[18], "#            +    +            #");
      strcpy(field[19], "#           +      +           #");
      strcpy(field[20], "#          +        +          #");
      strcpy(field[21], "#         +          +         #");
      strcpy(field[22], "#        +            +        #");
      strcpy(field[23], "#       +              +       #");
      strcpy(field[24], "#      +                +      #");
      strcpy(field[25], "#     +                  +     #");
      strcpy(field[26], "#    +                    +    #");
      strcpy(field[27], "#   +                      +   #");
      strcpy(field[28], "#  +                        +  #");
      strcpy(field[29], "#++                          ++#");
      strcpy(field[30], "#++                          ++#");
      strcpy(field[31], "################################");
      break;
      
    case 11:
       strcpy(field[0], "##########################################");
       strcpy(field[1], "#                                        #");
       strcpy(field[2], "#   ++                                   #");
       strcpy(field[3], "#   ++        +++              ++        #");
       strcpy(field[4], "#             +++              ++        #");
       strcpy(field[5], "#             +++                        #");
       strcpy(field[6], "#                                        #");
       strcpy(field[7], "#                             ++         #");
       strcpy(field[8], "#                            ++++        #");
       strcpy(field[9], "#      +++                   ++++        #");
      strcpy(field[10], "#      +++                    ++         #");
      strcpy(field[11], "#                                        #");
      strcpy(field[12], "#                                        #");
      strcpy(field[13], "#                                +++     #");
      strcpy(field[14], "#                ++              +++     #");
      strcpy(field[15], "#                ++                      #");
      strcpy(field[16], "#     +++                                #");
      strcpy(field[17], "#     +++                                #");
      strcpy(field[18], "#     +++                  ++            #");
      strcpy(field[19], "#                          ++            #");
      strcpy(field[20], "#                                        #");
      strcpy(field[21], "##########################################");
      break;
      
    case 12:
       strcpy(field[0], "##########################################");
       strcpy(field[1], "#                                        #");
       strcpy(field[2], "#                                        #");
       strcpy(field[3], "#                                        #");
       strcpy(field[4], "#                                        #");
       strcpy(field[5], "#              ++++++++++++              #");
       strcpy(field[6], "#             ++++++++++++++             #");
       strcpy(field[7], "#            ++            ++            #");
       strcpy(field[8], "#           ++              ++           #");
       strcpy(field[9], "#          ++                ++          #");
      strcpy(field[10], "#         ++                  ++         #");
      strcpy(field[11], "#        ++                    ++        #");
      strcpy(field[12], "#       ++                      ++       #");
      strcpy(field[13], "#                                        #");
      strcpy(field[14], "#          ++++++++++++++++++++          #");
      strcpy(field[15], "#      ++++++++++++++++++++++++++++      #");
      strcpy(field[16], "#                                        #");
      strcpy(field[17], "#                                        #");
      strcpy(field[18], "#                                        #");
      strcpy(field[19], "#                                        #");
      strcpy(field[20], "#                                        #");
      strcpy(field[21], "##########################################");
      break;
      
    case 13:
       strcpy(field[0], "################################");
       strcpy(field[1], "#                              #");
       strcpy(field[2], "#                              #");
       strcpy(field[3], "#                              #");
       strcpy(field[4], "#                              #");
       strcpy(field[5], "#                              #");
       strcpy(field[6], "#                              #");
       strcpy(field[7], "#                +             #");
       strcpy(field[8], "#               +              #");
       strcpy(field[9], "#               +              #");
      strcpy(field[10], "#            ++++++            #");
      strcpy(field[11], "#           +      +           #");
      strcpy(field[12], "#          +        +          #");
      strcpy(field[13], "#         +          +         #");
      strcpy(field[14], "#        +            +        #");
      strcpy(field[15], "#        +            +        #");
      strcpy(field[16], "#                              #");
      strcpy(field[17], "#                              #");
      strcpy(field[18], "#        +            +        #");
      strcpy(field[19], "#        +            +        #");
      strcpy(field[20], "#         +          +         #");
      strcpy(field[21], "#          +        +          #");
      strcpy(field[22], "#           +      +           #");
      strcpy(field[23], "#            ++++++            #");
      strcpy(field[24], "#                              #");
      strcpy(field[25], "#                              #");
      strcpy(field[26], "#                              #");
      strcpy(field[27], "#                              #");
      strcpy(field[28], "#                              #");
      strcpy(field[29], "#                              #");
      strcpy(field[30], "#                              #");
      strcpy(field[31], "################################");
      break;
      
    case 14:
       strcpy(field[0], "##########################################");
       strcpy(field[1], "#                                        #");
       strcpy(field[2], "#                                        #");
       strcpy(field[3], "#                                        #");
       strcpy(field[4], "#                                        #");
       strcpy(field[5], "#                                        #");
       strcpy(field[6], "#  ++++   +    +   ++++   +    +  ++++++ #");
       strcpy(field[7], "# +       +    +  +    +  +   +   +      #");
       strcpy(field[8], "# +       +    +  +    +  +  +    +      #");
       strcpy(field[9], "# +       ++   +  +    +  + +     +      #");
      strcpy(field[10], "# +       + +  +  +    +  ++      +      #");
      strcpy(field[11], "#  ++++   +  + +  + ++ +  + +     +++++  #");
      strcpy(field[12], "#      +  +   ++  +    +  +  +    +      #");
      strcpy(field[13], "#      +  +    +  +    +  +   +   +      #");
      strcpy(field[14], "#      +  +    +  +    +  +    +  +      #");
      strcpy(field[15], "#      +  +    +  +    +  +    +  +      #");
      strcpy(field[16], "#  ++++   +    +  +    +  +    +  ++++++ #");
      strcpy(field[17], "#                                        #");
      strcpy(field[18], "#                                        #");
      strcpy(field[19], "#                                        #");
      strcpy(field[20], "#                                        #");
      strcpy(field[21], "##########################################");
      break;
  }
}

void SetupFieldCustom() {
  char chWidth[11], chHeight[11];
  for (int y = 0; y < MapHeight + 2; y++)
    for (int x = 0; x < MapWidth + 2; x++)
      field[y][x] = map_field[y][x];
    
  widthX = MapWidth;
  heightY = MapHeight;
  
  itoa(widthX, chWidth, 10);
  itoa(heightY, chHeight, 10);
  SetWindowText(hEditWidthG, chWidth);
  SetWindowText(hEditHeightG, chHeight);
  
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
}

void SetupCustomBoard(int MapWidth, int MapHeight) {
  // Генерация поля и стен
  for (int y = 0; y < MapHeight + 2; y++)
    for (int x = 0; x < MapWidth + 2; x++)
      if ((y == 0) || (y == MapHeight + 1) || (x == 0) || (x == MapWidth + 1))
        map_field[y][x] = '#';
      else
        map_field[y][x] = ' ';
}

void Draw(char SumbHead, char SumbBody, SnakeTexture &st, int _x, int _y, HDC hdc, HWND hwnd) {
  wm.clear_all();
  int x, y;
  RECT rc;

  GetClientRect(hwnd, &rc);
  wm.set_pos(rc.right/2 - widthX/2*20 - 20, 30, 20, 20);
  st.Body->set_cut(20, 0, 20, 20);
  st.Head->set_cut(0, 0, 20, 20);

  for (int cy = 0; cy < heightY + 2; cy++) {
    for (int cx = 0; cx < widthX + 2; cx++) {
      if (field[cy][cx] == SumbBody) {
        x = wm.get_x(cx);
        y = wm.get_y(cy);
        st.Body->set_pos(x, y);
        st.Body->print_std(hdc);
      }
      if (field[cy][cx] == '@')
        wm.set_bitmap(hBitmapApple_a, cx, cy);
      if (field[cy][cx] == '$')
        wm.set_bitmap(hBitmapGoldApple_a, cx, cy);
      if (field[cy][cx] == '#')
        wm.set_bitmap(hBitmapWall_a, cx, cy);
      if (field[cy][cx] == '+')
        wm.set_bitmap(hBitmapWall_a, cx, cy);
      if (field[cy][cx] == SumbHead) {
        x = wm.get_x(cx);
        y = wm.get_y(cy);
        st.Head->set_pos(x, y);

        if (_x == 0 && _y == -1) {
          st.Head->set_angle(90);
          st.Head->print_std(hdc);
        }
        if (_x == 1 && _y == 0) {
          st.Head->set_angle(180);
          st.Head->print_std(hdc);
        }
        if (_x == 0 && _y == 1) {
          st.Head->set_angle(270);
          st.Head->print_std(hdc);
        }
        if (_x == -1 && _y == 0) {
          st.Head->set_angle(0);
          st.Head->print_std(hdc);
        }
      }
    }
  }
  wm.print(hdc); 
}

void DrawCustom(int MapWidth, int MapHeight, int offset_x, int offset_y, HDC hdc, HWND hwnd) {
  wm.clear_all();
  int x, y;
  RECT rc;

  GetClientRect(hwnd, &rc);
  wm.set_pos(rc.right/2 - (MapWidth/2 + 1)*20 + offset_x, 30 + offset_y, 20, 20);

  for (int cy = 0; cy < MapHeight + 2; cy++) {
    for (int cx = 0; cx < MapWidth + 2; cx++) {
      if (map_field[cy][cx] == '#')
        wm.set_bitmap(hBitmapWall_a, cx, cy);
      if (map_field[cy][cx] == '+')
        wm.set_bitmap(hBitmapWall_a, cx, cy);
    }
  }
  wm.print(hdc); 
}

void Write(bool slot, int score, int len, int applec, HDC hdc, HWND hwnd) {
  int x, y;
  char str[100] = "Очки: ", str1[10], str2[10], str3[10];
  itoa(score, str1, 10);
  itoa(len, str2, 10);
  itoa(applec, str3, 10);

  strcat(str, str1);
  strcat(str, "\nДлина змейки: ");
  strcat(str, str2);
  strcat(str, "\nЯблок съедено: ");
  strcat(str, str3);

  RECT rc;
  GetClientRect(hwnd, &rc);
  if (! slot) {
    x = rc.right/2 - (widthX/2 + 1)*20 + 2;
    y = 40 + (heightY + 2)*20;
  }
  else {
    x = rc.right/2 + (widthX/2 + 1)*20 - 2;
    y = 40 + (heightY + 2)*20;
  }
  TextPrint txt(str, x, y);
  txt.print(hdc);
}

void AdvancedWrite(bool slot, int score, int len, int applec, HDC hdc, HWND hwnd) {
  int x, y;
  char str[100] = "Очки: ", str1[10], str2[10], str3[10];
  itoa(score, str1, 10);
  itoa(len, str2, 10);
  itoa(applec, str3, 10);

  strcat(str, str1);
  strcat(str, "\nДлина змейки: ");
  strcat(str, str2);
  strcat(str, "\nЯблок съедено: ");
  strcat(str, str3);

  RECT rc;
  GetClientRect(hwnd, &rc);
  if (! slot) {
    x = rc.right/2 - (widthX/2 + 1)*20 + 2;
    y = 40 + (heightY + 2)*20;
  }
  else {
    x = rc.right/2 + (widthX/2 + 1)*20 - 2;
    y = 40 + (heightY + 2)*20;
  }
  TextPrint txt(str, x, y);
  txt.print(hdc);
}

void TimeWrite(bool slot, int TimeToOver, int score, int len, int applec, HDC hdc, HWND hwnd) {
  int x, y;
  char str[100], str1[10], str2[10], str3[10], str4[10];
  itoa(score, str1, 10);
  itoa(len, str2, 10);
  itoa(applec, str3, 10);
  itoa(TimeToOver, str4, 10);

  strcpy(str, "Очки: ");
  strcat(str, str1);
  strcat(str, "\nДлина змейки: ");
  strcat(str, str2);
  strcat(str, "\nЯблок съедено: ");
  strcat(str, str3);

  RECT rc;
  GetClientRect(hwnd, &rc);
  if (! slot) {
    x = rc.right/2 - (widthX/2 + 1)*20 + 2;
    y = 40 + (heightY + 2)*20;
  }
  else {
    x = rc.right/2 + (widthX/2 + 1)*20 - 2;
    y = 40 + (heightY + 2)*20;
  }
  TextPrint txt(str, x, y);
  txt.print(hdc);

  strcpy(str, "Время: ");
  strcat(str, str4);
  if (! slot) {
    x = rc.right/2 - (widthX/2 + 1)*20 + 132;
    y = 40 + (heightY + 2)*20;
  }
  else {
    x = rc.right/2 + (widthX/2 + 1)*20 - 132;
    y = 40 + (heightY + 2)*20;
  }
  TextPrint txt2(str, x, y);
  txt2.print(hdc);
}

void GenerationObjects(int applec, int &OldApplec, int &appleX, int &appleY, bool spawn) {
  // Генерация яблок
  if (OldApplec != applec || spawn)  {
    while (1) {
      appleX = rand() % widthX + 1;
      appleY = rand() % heightY + 1;
                        
      // Проверка на пустую ячейку
      if (field[appleY][appleX] == ' ') {
        field[appleY][appleX] = '@';
        break;
      }
    }
  OldApplec = applec;
  }
}

void GenerationObject(int what, int &appleX, int &appleY) {
  // Генерация яблок
  switch(what) {
    case 0:
      while (1) {
        appleX = rand() % widthX + 1;
        appleY = rand() % heightY + 1;
                        
        // Проверка на пустую ячейку
        if (field[appleY][appleX] == ' ') {
          field[appleY][appleX] = '@';
          break;
        }
      }
      break;
  }
}

void DestroyObjects(int what) {
  switch (what){
    case 0:
      for (int cy = 0; cy < heightY + 2; cy++) {
        for (int cx = 0; cx < widthX + 2; cx++) {
          if (field[cy][cx] == '@')
            field[cy][cx] = ' ';
        }
      }
      break;

    case 1:
      for (int cy = 0; cy < heightY + 2; cy++) {
        for (int cx = 0; cx < widthX + 2; cx++) {
          if (field[cy][cx] == '$')
            field[cy][cx] = ' ';
        }
      }
      break;
  }
}

void Move(char SumbHead, char SumbBody, int *snakeX, int *snakeY, int _x, int _y, int score, int len, int applec) {
  int x, y;

  // Коодринаты хвоста змеи
  x = snakeX[len - 1];
  y = snakeY[len - 1];
        
  // Перемешение частей змеи (кроме хвоста и головы)
  // с хвоста на последующие координаты следующих частей змеи   
  for (int i = len - 1; i > 0; i--) {
    snakeX[i] = snakeX[i - 1];
    snakeY[i] = snakeY[i - 1];
  }

  // Перемещение головы змеи
  if (snakeX[0] + _x == 0) {
    snakeX[0] = widthX;
  }
  else
    if (snakeX[0] + _x == widthX + 1) {
     snakeX[0] = 1;
    }
    else 
      if (snakeY[0] + _y == 0) {
        snakeY[0] = heightY;
      }
      else 
        if (snakeY[0] + _y == heightY + 1) {
          snakeY[0] = 1;
        }
        else {
          snakeX[0] = snakeX[0] + _x;
          snakeY[0] = snakeY[0] + _y;
        }
        
  // Визуальное перемещение змеи (в массиве field)
  field[y][x] = ' ';
  for (int i = 1; i < len; i++)
    field[snakeY[i]][snakeX[i]] = SumbBody;
  field[snakeY[0]][snakeX[0]] = SumbHead;

  field[0][0] = '#';
}

void Logic(SnakeMain **SMarray, char SumbHead, int *snakeX, int *snakeY, int _x, int _y, int appleX, int appleY, bool walls,
           bool SCrossing, bool &GameOver, int &score, int &len, int &applec, int PlayerNum) {
  // Действия при съедании яблока
  if ((snakeX[0] + _x == appleX) && (snakeY[0] + _y == appleY)) {
    len++;
    applec++;
    score += 10;
    return;
  }

  // Действие при самопересечении
  if (len > 4)
    for (int i = 4; i < len; i++)
      if ((snakeX[0] == snakeX[i]) && (snakeY[0] == snakeY[i]))
        if (SCrossing) {
          GameOver = TRUE;
          return;
        }
        else {
          for (int j = i; j < len; j++) {
            snakeX[j] = 0;
            snakeY[j] = 0;
          }
          len = i;
          return;
        }

  switch (PlayerNum) {
    case 0:
      PlayerNum = 1;
      break;

    case 1:
      PlayerNum = 0;
      break;
  }

  if (PlayerCount > 1 && SCrossing) {
    for (int i = 0; i < SMarray[PlayerNum]->len; i++) {
      if (snakeX[0] + _x == SMarray[PlayerNum]->snakeX[i] && snakeY[0] + _y == SMarray[PlayerNum]->snakeY[i])
        GameOver = TRUE;
    }
  }

  // Действия при столкновении со стеной
  if (walls) {
    if ((snakeX[0] + _x == 0) || (snakeX[0] + _x == widthX + 1) || (snakeY[0] + _y == 0) || (snakeY[0] + _y == heightY + 1))
      GameOver = TRUE;
  }
  if (field[snakeY[0] + _y][snakeX[0] + _x] == '+')
    GameOver = TRUE;
}

bool AdvancedLogic(int *snakeX, int *snakeY, int _x, int _y, int GoldAppleX, int GoldAppleY, int &TimeEffect){
  if (snakeX[0] + _x == GoldAppleX && snakeY[0] + _y == GoldAppleY) {
    TimeEffect = 5;
    return 0;
  }
  return 1;
}

void BombLogic(SnakeMain &ptSnakeMain, int AppleX, int AppleY, int GoldAppleX, int GoldAppleY, int BombX, int BombY, int &len, int &OldApplec, bool &GameOver) {
  int from_x, from_y, to_x, to_y;
  from_x = BombX - 2;
  if (from_x < 0)
    from_x = 0;
  from_y = BombY - 2;
  if (from_y < 0)
    from_y = 0;
  to_x = BombX + 2;
  if (to_x > widthX)
    to_x = widthX;
  to_y = BombY + 2;
  if (to_y > heightY)
    to_y = heightY;
  
  for(int i = from_x; i <= to_x; i++) {
    for (int j = from_y; j <= to_y; j++){
      if (ptSnakeMain.snakeX[0] == i && ptSnakeMain.snakeY[0] == j) {
        GameOver = 1;
        ptSnakeMain.GameOver = 1;
        return;
      }
      for(int l = 1; l < len; l++) {
        if (ptSnakeMain.snakeX[l] == i && ptSnakeMain.snakeY[l] == j) {
          for (int f = l; f < len; f++) {
            ptSnakeMain.snakeX[f] = 0;
            ptSnakeMain.snakeY[f] = 0;
          }
          len = l;
        }
      }
      if (AppleX == i && AppleY == j) {
        DestroyObjects(0);
        OldApplec -= 1;
      }
      if (GoldAppleX == i && GoldAppleY == j) {
        DestroyObjects(1);
      }
    }
  }
}

void TimeLogic(int applec, int OldApplec, int &TimeToOver, bool &GameOver) {
  if (OldApplec != applec)
    TimeToOver += 3;
  if (TimeToOver == 0)
    GameOver = 1;
}

void LoadResults(char *num_pos, char *load_str, char *load_num, int filenum) {
  const int numstr = 15;
  char buff[81], name[71], score_str[11];
  char p[81];
  int pos = 0, j = 0;
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

  strcpy(num_pos, "");
  strcpy(load_str, "");
  strcpy(load_num, "");

  std::ifstream Lfile(filename);
  if (! Lfile) {
    strcpy(load_str, "Нет результатов");
    return;
  }

  for (int i = 0; i < numstr; i++) {
    strcpy(buff, "");
    Lfile.getline(buff, 80);

    if (Lfile.eof())
      break;
//------
    for (j = 0; j < 71 && buff[pos] != '|'; j++) {
      name[j] = buff[pos];
      pos++;
    }
    name[pos] = '\0';

    pos++;
    for (j = 0; j < 11 && buff[pos] != '\0'; j++) {
      score_str[j] = buff[pos];
      pos++;
    }
    score_str[j] = '\0';
    j = pos = 0;
//-------
    itoa(i + 1, p, 10);
    strcat(p, ".\n");
    strcat(num_pos, p);

    strcat(load_str, name);
    strcat(load_str, "\n");

    strcat(load_num, score_str);
    strcat(load_num, "\n");
  }
}

void SaveResults(int score, char *name, int filenum) {
  const int numstr = 16;
  char buff[81], new_result[81], score_str[11];
  char *p[numstr], *n[numstr];
  char *pPtr, *nPtr;
  int pos = 0, j = 0;
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

  std::ifstream Lfile(filename);
  if (! Lfile) {
    CreateDirectory("C:\\SBstudio", NULL);
    CreateDirectory("C:\\SBstudio\\Snake", NULL);
    std::ofstream Sfile(filename);
    itoa(score, score_str, 10);
    strcpy(new_result, name);
    strcat(new_result, "|");
    strcat(new_result, score_str);
    strcat(new_result, "\n");
    Sfile << new_result;
    return;
  }  

  for (int i = 1; i < numstr; i++) {
    p[i] = new char[81];
    n[i] = new char[11];
    strcpy(p[i], "");
    strcpy(n[i], "");
  }

  itoa(score, score_str, 10);
  strcpy(new_result, name);
  strcat(new_result, "|");
  strcat(new_result, score_str);
  strcat(new_result, "\n");
  p[0] = new_result;
  n[0] = score_str;

  for (int i = 1; i < numstr; i++) {
    strcpy(buff, "");
    Lfile.getline(buff, 80);

    if (Lfile.eof())
      break;

    strcpy(p[i], buff);
//------
    pPtr = p[i];
    nPtr = n[i];
    while (*(pPtr + pos) != '|')
      pos++;
    pos++;
    for (j = 0; j < 11 && *(pPtr + pos) != '\0'; j++) {
      *(nPtr + j) = *(pPtr + pos);
      pos++;
    }
    *(nPtr + j) = '\0';
    j = pos = 0;
//------
    strcat(p[i], "\n");
  }
  Lfile.close(); 

  for (int i = 0; i < numstr; i++) {
    for (int l = i + 1; l < numstr; l++) {
      if (atoi(n[i]) < atoi(n[l])) {
        swap(n[i], n[l]);
        swap(p[i], p[l]);
      }
    }
  }

  std::ofstream Sfile(filename);
  char save_str[1000] = "";
  for (int i = 0; i < numstr - 1; i++) {
    strcat(save_str, p[i]);
  }
  Sfile << save_str;

  for (int i = 1; i < numstr; i++) {
    delete [] p[i];
    delete [] n[i];
  }
}

bool LoadSettings(SnakeSettings *LS) {
  char setting[50], buff[81]; //setting - отдельная настройка (лексема в файле)
  int pos = 0, j = 0;

  std::ifstream Lfile("C:\\SBstudio\\Snake\\snake_settings.txt");
  if (! Lfile)
    return 0;

  strcpy(buff, "");
  Lfile.getline(buff, 80);

  strcpy(setting, "");
  for (j = 0; j < 49 && buff[pos] != '|'; j++) {
    setting[j] = buff[pos];
    pos++;
  }
  pos++;
  setting[j] = '\0';
  strcpy(LS->PlayerName, setting);

  strcpy(setting, "");
  setting[0] = buff[pos];
  pos += 2;
  setting[1] = '\0';
  LS->Save = (bool)atoi(setting);

  strcpy(setting, "");
  setting[0] = buff[pos];
  pos += 2;
  setting[1] = '\0';
  LS->walls = (bool)atoi(setting);

  strcpy(setting, "");
  setting[0] = buff[pos];
  pos += 2;
  setting[1] = '\0';
  LS->SCrossing = (bool)atoi(setting);

  strcpy(setting, "");
  setting[0] = buff[pos];
  pos += 2;
  setting[1] = '\0';
  LS->Accelerate = (bool)atoi(setting);

  strcpy(setting, "");
  setting[0] = buff[pos];
  pos += 2;
  setting[1] = '\0';
  LS->Speed = atoi(setting);

  strcpy(setting, "");
  for (int i = 0; buff[pos] != '|'; i++) { 
    setting[i] = buff[pos];
    if (buff[pos + 1] == '|')
      setting[i + 1] = '\0';
    pos++;
  }
  pos++;
  LS->SnakeT = atoi(setting);
  
  strcpy(setting, "");
  setting[0] = buff[pos];
  pos += 2;
  setting[1] = '\0';
  LS->Control = atoi(setting);

  strcpy(setting, "");
  for (int i = 0; buff[pos] != '|'; i++) { 
    setting[i] = buff[pos];
    if (buff[pos + 1] == '|')
      setting[i + 1] = '\0';
    pos++;
  }
  pos++;
  LS->widthX = atoi(setting);

  strcpy(setting, "");
  for (int i = 0; buff[pos] != '|'; i++) { 
    setting[i] = buff[pos];
    if (buff[pos + 1] == '|')
      setting[i + 1] = '\0';
    pos++;
  }
  pos++;
  LS->heightY = atoi(setting);
  
  strcpy(setting, "");
  for (int i = 0; buff[pos] != '|'; i++) { 
    setting[i] = buff[pos];
    if (buff[pos + 1] == '|')
      setting[i + 1] = '\0';
    pos++;
  }
  pos++;
  LS->PlayTime = atoi(setting);

  return 1;
}

bool LoadSettingsAdd(SnakeSettingsAdd *LS) {
  char setting[50], buff[81]; //setting - отдельная настройка (лексема в файле)
  int pos = 0, j = 0;

  std::ifstream Lfile("C:\\SBstudio\\Snake\\snake_settings2.txt");
  if (! Lfile)
    return 0;

  strcpy(buff, "");
  Lfile.getline(buff, 80);

  strcpy(setting, "");
  for (j = 0; j < 49 && buff[pos] != '|'; j++) {
    setting[j] = buff[pos];
    pos++;
  }
  pos++;
  setting[j] = '\0';
  strcpy(LS->PlayerName, setting);

  strcpy(setting, "");
  for (int i = 0; buff[pos] != '|'; i++) { 
    setting[i] = buff[pos];
    if (buff[pos + 1] == '|')
      setting[i + 1] = '\0';
    pos++;
  }
  pos++;
  LS->SnakeT = atoi(setting);

  return 1;
}

void SaveSettings(SnakeSettings SS) {
  char save_str[81], setting[50]; //setting - отдельная настройка (лексема в файле)

  std::ifstream Lfile("C:\\SBstudio\\Snake\\snake_settings.txt");
  if (! Lfile) {
    CreateDirectory("C:\\SBstudio", NULL);
    CreateDirectory("C:\\SBstudio\\Snake", NULL);
  }
  Lfile.close();

  std::ofstream Sfile("C:\\SBstudio\\Snake\\snake_settings.txt");
  strcpy(save_str, SS.PlayerName);
  strcat(save_str, "|");

  itoa((int)SS.Save, setting, 10);
  strcat(save_str, setting);
  strcat(save_str, "|");

  itoa((int)SS.walls, setting, 10);
  strcat(save_str, setting);
  strcat(save_str, "|");

  itoa((int)SS.SCrossing, setting, 10);
  strcat(save_str, setting);
  strcat(save_str, "|");

  itoa((int)SS.Accelerate, setting, 10);
  strcat(save_str, setting);
  strcat(save_str, "|");

  itoa(SS.Speed, setting, 10);
  strcat(save_str, setting);
  strcat(save_str, "|");

  itoa(SS.SnakeT, setting, 10);
  strcat(save_str, setting);
  strcat(save_str, "|");
  
  itoa(SS.Control, setting, 10);
  strcat(save_str, setting);
  strcat(save_str, "|");

  itoa(SS.widthX, setting, 10);
  strcat(save_str, setting);
  strcat(save_str, "|");

  itoa(SS.heightY, setting, 10);
  strcat(save_str, setting);
  strcat(save_str, "|");

  itoa(SS.PlayTime, setting, 10);
  strcat(save_str, setting);
  strcat(save_str, "|");

  strcat(save_str, "\n");
  Sfile << save_str;
}

void SaveSettingsAdd(SnakeSettingsAdd SS) {
  char save_str[81], setting[50]; //setting - отдельная настройка (лексема в файле)

  std::ifstream Lfile("C:\\SBstudio\\Snake\\snake_settings2.txt");
  if (! Lfile) {
    CreateDirectory("C:\\SBstudio", NULL);
    CreateDirectory("C:\\SBstudio\\Snake", NULL);
  }
  Lfile.close();

  std::ofstream Sfile("C:\\SBstudio\\Snake\\snake_settings2.txt");
  strcpy(save_str, SS.PlayerName);
  strcat(save_str, "|");

  itoa(SS.SnakeT, setting, 10);
  strcat(save_str, setting);
  strcat(save_str, "|");

  strcat(save_str, "\n");
  Sfile << save_str;
}

bool LoadTexture(char *TextureName) {
  std::ifstream Lfile("C:\\SBstudio\\Snake\\snake_texture.txt");
  if (! Lfile)
    return 0;

  Lfile.getline(TextureName, 255);
  return 1;
}

bool LoadTextureAdd(char *TextureName) {
  std::ifstream Lfile("C:\\SBstudio\\Snake\\snake_texture2.txt");
  if (! Lfile)
    return 0;

  Lfile.getline(TextureName, 255);
  return 1;
}

void SaveTexture(char *TextureName) {
  std::ifstream Lfile("C:\\SBstudio\\Snake\\snake_texture.txt");
  if (! Lfile) {
    CreateDirectory("C:\\SBstudio", NULL);
    CreateDirectory("C:\\SBstudio\\Snake", NULL);
  }
  Lfile.close();

  std::ofstream Sfile("C:\\SBstudio\\Snake\\snake_texture.txt");
  Sfile << TextureName;
}

void SaveTextureAdd(char *TextureName) {
  std::ifstream Lfile("C:\\SBstudio\\Snake\\snake_texture2.txt");
  if (! Lfile) {
    CreateDirectory("C:\\SBstudio", NULL);
    CreateDirectory("C:\\SBstudio\\Snake", NULL);
  }
  Lfile.close();

  std::ofstream Sfile("C:\\SBstudio\\Snake\\snake_texture2.txt");
  Sfile << TextureName;
}

void swap(char *a, char *b) {
  char c[81];
  strcpy(c, a);
  strcpy(a, b);
  strcpy(b, c);
}