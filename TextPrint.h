#include <windows.h>
#include <string>

//вывод текста
class TextPrint {
protected:
  int left, top;
  std::string Text;
  int start_pos;

public:
  TextPrint(){this->start_pos = 1;}
  TextPrint(std::string Text, int left, int top);

  void set_text(std::string Text);
  void set_pos(int left, int top);
  void set_start_pos(int start_pos);
  void get_pos(int *left, int *top);

  void print(HDC hdc);
  void print_str(HDC hdc);
};

TextPrint::TextPrint(std::string Text, int left, int top) {
  this->left = left;
  this->top = top;
  this->Text = Text;
  this->start_pos = 1;
}

void TextPrint::set_text(std::string Text) {
  this->Text = Text;
}

void TextPrint::set_pos(int left, int top) {
  this->left = left;
  this->top = top;
}

void TextPrint::set_start_pos(int start_pos) {
  this->start_pos = start_pos;
}

void TextPrint::get_pos(int *left, int *top) {
  *left = this->left;
  *top = this->top;
}

void TextPrint::print(HDC hdc) {
  char buff[1001];
  int pos = 0, nStr = 0, cycle = 1;
//поз. в тексте/ номер стр./ флаг цикла

  for (int str_pos = 0; str_pos + 1 < start_pos; str_pos++) {
    while (this->Text[pos] != '\n') {
      if (this->Text[pos] == '\0')
        return;
      pos++;
    }
    pos++;
  }

  while (cycle == 1) {
    for (int i = 0; i < 1000; i++) {
      if (this->Text[pos] == '\n') {
        TextOut(hdc, this->left, this->top + nStr*17, buff, i);
        pos++;
        nStr++;
        break;
      }

      if (this->Text[pos] == '\0') {
        TextOut(hdc, this->left, this->top + nStr*17, buff, i);
        cycle = 0;
        break;
      }

      if (i < 1000) {
        buff[i] = this->Text[pos];
        pos++;
      }
      else {
        TextOut(hdc, this->left, this->top + nStr*17, buff, i);
        nStr++;
        break;
      }
    }
    strcpy(buff, "");
  }
}

void TextPrint::print_str(HDC hdc) {
  char buff[1001];
  int pos = 0;
//поз. в тексте

  for (int str_pos = 0; str_pos + 1 < start_pos; str_pos++) {
    while (this->Text[pos] != '\n') {
      if (this->Text[pos] == '\0')
        return;
      pos++;
    }
    pos++;
  }

  for (int i = 0; i < 1000; i++) {
    if (this->Text[pos] == '\n') {
      TextOut(hdc, this->left, this->top, buff, i);
      break;
    }

    if (this->Text[pos] == '\0') {
      TextOut(hdc, this->left, this->top, buff, i);
      break;
    }

    if (i < 999) {
      buff[i] = this->Text[pos];
      pos++;
    }
    else {
      TextOut(hdc, this->left, this->top, buff, i);
      break;
    }
  }
}
