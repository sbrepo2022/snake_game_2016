int widthX = 40, heightY = 20; //размер поля
int MapWidth = 40, MapHeight = 20;//размер карты
int PlayTime = 0;
bool Save = TRUE, walls = TRUE, SCrossing = TRUE, Accelerate = TRUE; //настройки
int Speed = 1, SnakeT = 0, Control = 0, SnakeT2 = 0, map = 0;
bool IsLoadT = 0, IsLoadT2 = 0;
int PlayerCount = 1, PlayingRoutine = 0, filenum = 0;
char PlayerName[50] = "игрок 1", PlayerName2[50] = "игрок 2"; //имя игрока
char numbers[100], names[500], results[140]; //результаты
char TextureName[256], TextureName2[256]; //файловый путь до текстуры
