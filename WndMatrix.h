#include <windows.h>
#include <vector>

//экранная матрица
class WndMatrix {
protected:
  struct BitmapPos {	//структура, отечающая за изображения
    int xIndex, yIndex;
    HANDLE hBitmap;
    BITMAP Bitmap;
  };

  int xPos, yPos, width, height;
  std::vector<BitmapPos> Vbitmap;

public:
  WndMatrix() {}
  WndMatrix(int xPos, int yPos, int width, int height);

  void set_bitmap(HANDLE hBitmap, int xIndex, int yIndex);
  void set_pos(int xPos, int yPos, int width, int height);
  void get_bitmap(HANDLE *hBitmap, int xIndex, int yIndex);
  void get_pos(int *xPos, int *yPos, int *width, int *height);
  int get_x(int xIndex);
  int get_y(int yIndex);

  void clear_all();
  void print(HDC hdc);
};

WndMatrix::WndMatrix(int xPos, int yPos, int width, int height) {
  this->xPos = xPos;
  this->yPos = yPos;
  this->width = width;
  this->height = height;
}

void WndMatrix::set_bitmap(HANDLE hBitmap, int xIndex, int yIndex) {
  for (int i = 0; i < Vbitmap.size(); i++) {
    if (Vbitmap[i].xIndex == xIndex && Vbitmap[i].yIndex == yIndex) {
      Vbitmap[i].hBitmap = hBitmap;
      GetObject(Vbitmap[i].hBitmap, sizeof(BITMAP), &Vbitmap[i].Bitmap);
      return;
    }
  }
  BitmapPos bp;
  bp.xIndex = xIndex;
  bp.yIndex = yIndex;
  bp.hBitmap = hBitmap;
  GetObject(hBitmap, sizeof(BITMAP), &bp.Bitmap);
  Vbitmap.push_back(bp);
}

void WndMatrix::set_pos(int xPos, int yPos, int width, int height) {
  this->xPos = xPos;
  this->yPos = yPos;
  this->width = width;
  this->height = height;
}

void WndMatrix::get_bitmap(HANDLE *hBitmap, int xIndex, int yIndex) {
  for (int i = 0; i < Vbitmap.size(); i++) {
    if (Vbitmap[i].xIndex == xIndex && Vbitmap[i].yIndex == yIndex) {
      *hBitmap = Vbitmap[i].hBitmap;
      return;
    }
  }
}

void WndMatrix::get_pos(int *xPos, int *yPos, int *width, int *height) {
  *xPos = this->xPos;
  *yPos = this->yPos;
  *width = this->width;
  *height = this->height;
}

int WndMatrix::get_x(int xIndex) {
  return this->width * xIndex + xPos;
}

int WndMatrix::get_y(int yIndex) {
  return this->height * yIndex + yPos;
}

void WndMatrix::clear_all() {
  Vbitmap.clear();
}

void WndMatrix::print(HDC hdc) {
  int size = Vbitmap.size();
  for (int i = 0; i < size; i++) {
    int left = this->width * Vbitmap[i].xIndex + this->xPos;
    int top = this->height * Vbitmap[i].yIndex + this->yPos;
    HDC hDC = CreateCompatibleDC(hdc);
    SelectObject(hDC, Vbitmap[i].hBitmap);
    StretchBlt(hdc, left, top, Vbitmap[i].Bitmap.bmWidth, Vbitmap[i].Bitmap.bmHeight, hDC, 0, 0, Vbitmap[i].Bitmap.bmWidth, Vbitmap[i].Bitmap.bmHeight, SRCCOPY);
    DeleteDC(hDC);
  }
}
