#include "vex.h"

#include <cstdio>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace vex;

int currentButton = 0;

typedef struct _colorText
{
  color Color;
  std::string Text;
} s_colorText;

typedef struct _iText
{
  int Index;
  std::string Text;
} s_iText;

typedef struct _button
{
  int xPos, yPos, width, height, state, size;
  s_colorText colorText0, colorText1, colorText2, colorText3, colorText4, colorText5, colorText6, colorText7, colorText8, colorText9, colorText10, colorText11;
} s_button;

typedef struct _button2
{
  int xPos, yPos, width, height, state, size;
  s_iText iText;
  s_colorText colorText0, colorText1, colorText2, colorText3, colorText4, colorText5, colorText6, colorText7, colorText8, colorText9, colorText10, colorText11;
} s_button2;

void buttonTouch(s_button p_buttons[], int arrsize)
{
  for(int i = 0; i < arrsize; i++)
  {
    int xOrigin = p_buttons[i].xPos;
    int yOrigin = p_buttons[i].yPos;
    int width = p_buttons[i].width;
    int height = p_buttons[i].height;
    int xEnd = xOrigin + width;
    int yEnd = yOrigin + height;

    int x = LCD.xPosition();
    int y = LCD.yPosition();
    if((x >= xOrigin && x <= xEnd) && (y >= yOrigin && y <= yEnd)) 
    {
      p_buttons[i].state++;
      if(p_buttons[i].state > p_buttons[i].size - 1) p_buttons[i].state = 0;
      currentButton = i;
    }
  }
}

void buttonTouch(s_button2 p_buttons[], int arrsize)
{
  for(int i = 0; i < arrsize; i++)
  {
    int xOrigin = p_buttons[i].xPos;
    int yOrigin = p_buttons[i].yPos;
    int width = p_buttons[i].width;
    int height = p_buttons[i].height;
    int xEnd = xOrigin + width;
    int yEnd = yOrigin + height;

    int x = LCD.xPosition();
    int y = LCD.yPosition();
    if((x >= xOrigin && x <= xEnd) && (y >= yOrigin && y <= yEnd)) 
    {
      p_buttons[i].state++;
      if(p_buttons[i].state > p_buttons[i].size - 1) p_buttons[i].state = 0;
      currentButton = i;
    }
  }
}

s_button buttonTouch(s_button p_button)
{
  int xOrigin = p_button.xPos;
  int yOrigin = p_button.yPos;
  int width = p_button.width;
  int height = p_button.height;
  int xEnd = xOrigin + width;
  int yEnd = yOrigin + height;

  int x = LCD.xPosition();
  int y = LCD.yPosition();
  if((x >= xOrigin && x <= xEnd) && (y >= yOrigin && y <= yEnd)) 
  {
    p_button.state++;
    if(p_button.state > p_button.size - 1) p_button.state = 0;
    currentButton = 0;
  }
  return(p_button);
}

void drawButtons(s_button p_buttons[], int arrsize)
{
  LCD.clearScreen();

  for(int i = 0; i < arrsize; i++)
  {
    int t_state = p_buttons[i].state;

    if(t_state == 0)
    {
      LCD.setPenColor(p_buttons[i].colorText0.Color);
      LCD.setFillColor(p_buttons[i].colorText0.Color);
      LCD.drawRectangle(p_buttons[i].xPos, p_buttons[i].yPos, p_buttons[i].width, p_buttons[i].height);
      LCD.setPenColor(Color.white);
      LCD.printAt(p_buttons[i].xPos + 1, p_buttons[i].yPos + 50, p_buttons[i].colorText0.Text.c_str());
    }
    if(t_state == 1)
    {
      LCD.setPenColor(p_buttons[i].colorText1.Color);
      LCD.setFillColor(p_buttons[i].colorText1.Color);
      LCD.drawRectangle(p_buttons[i].xPos, p_buttons[i].yPos, p_buttons[i].width, p_buttons[i].height);
      LCD.setPenColor(Color.white);
      LCD.printAt(p_buttons[i].xPos + 1, p_buttons[i].yPos + 50, p_buttons[i].colorText1.Text.c_str());
    }
    if(t_state == 2)
    {
      LCD.setPenColor(p_buttons[i].colorText2.Color);
      LCD.setFillColor(p_buttons[i].colorText2.Color);
      LCD.drawRectangle(p_buttons[i].xPos, p_buttons[i].yPos, p_buttons[i].width, p_buttons[i].height);
      LCD.setPenColor(Color.white);
      LCD.printAt(p_buttons[i].xPos + 1, p_buttons[i].yPos + 50, p_buttons[i].colorText2.Text.c_str());
    }
    if(t_state == 3)
    {
      LCD.setPenColor(p_buttons[i].colorText3.Color);
      LCD.setFillColor(p_buttons[i].colorText3.Color);
      LCD.drawRectangle(p_buttons[i].xPos, p_buttons[i].yPos, p_buttons[i].width, p_buttons[i].height);
      LCD.setPenColor(Color.white);
      LCD.printAt(p_buttons[i].xPos + 1, p_buttons[i].yPos + 50, p_buttons[i].colorText3.Text.c_str());
    }
    if(t_state == 4)
    {
      LCD.setPenColor(p_buttons[i].colorText4.Color);
      LCD.setFillColor(p_buttons[i].colorText4.Color);
      LCD.drawRectangle(p_buttons[i].xPos, p_buttons[i].yPos, p_buttons[i].width, p_buttons[i].height);
      LCD.setPenColor(Color.white);
      LCD.printAt(p_buttons[i].xPos + 1, p_buttons[i].yPos + 50, p_buttons[i].colorText4.Text.c_str());
    }
    if(t_state == 5)
    {
      LCD.setPenColor(p_buttons[i].colorText5.Color);
      LCD.setFillColor(p_buttons[i].colorText5.Color);
      LCD.drawRectangle(p_buttons[i].xPos, p_buttons[i].yPos, p_buttons[i].width, p_buttons[i].height);
      LCD.setPenColor(Color.white);
      LCD.printAt(p_buttons[i].xPos + 1, p_buttons[i].yPos + 50, p_buttons[i].colorText5.Text.c_str());
    }
    if(t_state == 6)
    {
      LCD.setPenColor(p_buttons[i].colorText6.Color);
      LCD.setFillColor(p_buttons[i].colorText6.Color);
      LCD.drawRectangle(p_buttons[i].xPos, p_buttons[i].yPos, p_buttons[i].width, p_buttons[i].height);
      LCD.setPenColor(Color.white);
      LCD.printAt(p_buttons[i].xPos + 1, p_buttons[i].yPos + 50, p_buttons[i].colorText6.Text.c_str());
    }
    if(t_state == 7)
    {
      LCD.setPenColor(p_buttons[i].colorText7.Color);
      LCD.setFillColor(p_buttons[i].colorText7.Color);
      LCD.drawRectangle(p_buttons[i].xPos, p_buttons[i].yPos, p_buttons[i].width, p_buttons[i].height);
      LCD.setPenColor(Color.white);
      LCD.printAt(p_buttons[i].xPos + 1, p_buttons[i].yPos + 50, p_buttons[i].colorText7.Text.c_str());
    }
    if(t_state == 8)
    {
      LCD.setPenColor(p_buttons[i].colorText8.Color);
      LCD.setFillColor(p_buttons[i].colorText8.Color);
      LCD.drawRectangle(p_buttons[i].xPos, p_buttons[i].yPos, p_buttons[i].width, p_buttons[i].height);
      LCD.setPenColor(Color.white);
      LCD.printAt(p_buttons[i].xPos + 1, p_buttons[i].yPos + 50, p_buttons[i].colorText8.Text.c_str());
    }
    if(t_state == 9)
    {
      LCD.setPenColor(p_buttons[i].colorText9.Color);
      LCD.setFillColor(p_buttons[i].colorText9.Color);
      LCD.drawRectangle(p_buttons[i].xPos, p_buttons[i].yPos, p_buttons[i].width, p_buttons[i].height);
      LCD.setPenColor(Color.white);
      LCD.printAt(p_buttons[i].xPos + 1, p_buttons[i].yPos + 50, p_buttons[i].colorText9.Text.c_str());
    }
    if(t_state == 10)
    {
      LCD.setPenColor(p_buttons[i].colorText10.Color);
      LCD.setFillColor(p_buttons[i].colorText10.Color);
      LCD.drawRectangle(p_buttons[i].xPos, p_buttons[i].yPos, p_buttons[i].width, p_buttons[i].height);
      LCD.setPenColor(Color.white);
      LCD.printAt(p_buttons[i].xPos + 1, p_buttons[i].yPos + 50, p_buttons[i].colorText10.Text.c_str());
    }
    if(t_state == 11)
    {
      LCD.setPenColor(p_buttons[i].colorText11.Color);
      LCD.setFillColor(p_buttons[i].colorText11.Color);
      LCD.drawRectangle(p_buttons[i].xPos, p_buttons[i].yPos, p_buttons[i].width, p_buttons[i].height);
      LCD.setPenColor(Color.white);
      LCD.printAt(p_buttons[i].xPos + 1, p_buttons[i].yPos + 50, p_buttons[i].colorText11.Text.c_str());
    }
  }

  LCD.setFillColor(Color.transparent);
  LCD.drawRectangle(p_buttons[currentButton].xPos - 2, p_buttons[currentButton].yPos - 2, p_buttons[currentButton].width + 2, p_buttons[currentButton].height + 2);

  LCD.render();
}

void drawButtons(s_button2 p_buttons[], int arrsize)
{
  for(int i = 0; i < arrsize; i++)
  {
    int t_state = p_buttons[i].state;

    if(t_state == 0)
    {
      LCD.setPenColor(p_buttons[i].colorText0.Color);
      LCD.setFillColor(p_buttons[i].colorText0.Color);
      LCD.drawRectangle(p_buttons[i].xPos, p_buttons[i].yPos, p_buttons[i].width, p_buttons[i].height);
      LCD.setPenColor(Color.white);
      LCD.printAt(p_buttons[i].xPos + 1, p_buttons[i].yPos + 50, p_buttons[i].colorText0.Text.c_str());
    }
    if(t_state == 1)
    {
      LCD.setPenColor(p_buttons[i].colorText1.Color);
      LCD.setFillColor(p_buttons[i].colorText1.Color);
      LCD.drawRectangle(p_buttons[i].xPos, p_buttons[i].yPos, p_buttons[i].width, p_buttons[i].height);
      LCD.setPenColor(Color.white);
      LCD.printAt(p_buttons[i].xPos + 1, p_buttons[i].yPos + 50, p_buttons[i].colorText1.Text.c_str());
    }
    if(t_state == 2)
    {
      LCD.setPenColor(p_buttons[i].colorText2.Color);
      LCD.setFillColor(p_buttons[i].colorText2.Color);
      LCD.drawRectangle(p_buttons[i].xPos, p_buttons[i].yPos, p_buttons[i].width, p_buttons[i].height);
      LCD.setPenColor(Color.white);
      LCD.printAt(p_buttons[i].xPos + 1, p_buttons[i].yPos + 50, p_buttons[i].colorText2.Text.c_str());
    }
    if(t_state == 3)
    {
      LCD.setPenColor(p_buttons[i].colorText3.Color);
      LCD.setFillColor(p_buttons[i].colorText3.Color);
      LCD.drawRectangle(p_buttons[i].xPos, p_buttons[i].yPos, p_buttons[i].width, p_buttons[i].height);
      LCD.setPenColor(Color.white);
      LCD.printAt(p_buttons[i].xPos + 1, p_buttons[i].yPos + 50, p_buttons[i].colorText3.Text.c_str());
    }
    if(t_state == 4)
    {
      LCD.setPenColor(p_buttons[i].colorText4.Color);
      LCD.setFillColor(p_buttons[i].colorText4.Color);
      LCD.drawRectangle(p_buttons[i].xPos, p_buttons[i].yPos, p_buttons[i].width, p_buttons[i].height);
      LCD.setPenColor(Color.white);
      LCD.printAt(p_buttons[i].xPos + 1, p_buttons[i].yPos + 50, p_buttons[i].colorText4.Text.c_str());
    }
    if(t_state == 5)
    {
      LCD.setPenColor(p_buttons[i].colorText5.Color);
      LCD.setFillColor(p_buttons[i].colorText5.Color);
      LCD.drawRectangle(p_buttons[i].xPos, p_buttons[i].yPos, p_buttons[i].width, p_buttons[i].height);
      LCD.setPenColor(Color.white);
      LCD.printAt(p_buttons[i].xPos + 1, p_buttons[i].yPos + 50, p_buttons[i].colorText5.Text.c_str());
    }
    if(t_state == 6)
    {
      LCD.setPenColor(p_buttons[i].colorText6.Color);
      LCD.setFillColor(p_buttons[i].colorText6.Color);
      LCD.drawRectangle(p_buttons[i].xPos, p_buttons[i].yPos, p_buttons[i].width, p_buttons[i].height);
      LCD.setPenColor(Color.white);
      LCD.printAt(p_buttons[i].xPos + 1, p_buttons[i].yPos + 50, p_buttons[i].colorText6.Text.c_str());
    }
    if(t_state == 7)
    {
      LCD.setPenColor(p_buttons[i].colorText7.Color);
      LCD.setFillColor(p_buttons[i].colorText7.Color);
      LCD.drawRectangle(p_buttons[i].xPos, p_buttons[i].yPos, p_buttons[i].width, p_buttons[i].height);
      LCD.setPenColor(Color.white);
      LCD.printAt(p_buttons[i].xPos + 1, p_buttons[i].yPos + 50, p_buttons[i].colorText7.Text.c_str());
    }
    if(t_state == 8)
    {
      LCD.setPenColor(p_buttons[i].colorText8.Color);
      LCD.setFillColor(p_buttons[i].colorText8.Color);
      LCD.drawRectangle(p_buttons[i].xPos, p_buttons[i].yPos, p_buttons[i].width, p_buttons[i].height);
      LCD.setPenColor(Color.white);
      LCD.printAt(p_buttons[i].xPos + 1, p_buttons[i].yPos + 50, p_buttons[i].colorText8.Text.c_str());
    }
    if(t_state == 9)
    {
      LCD.setPenColor(p_buttons[i].colorText9.Color);
      LCD.setFillColor(p_buttons[i].colorText9.Color);
      LCD.drawRectangle(p_buttons[i].xPos, p_buttons[i].yPos, p_buttons[i].width, p_buttons[i].height);
      LCD.setPenColor(Color.white);
      LCD.printAt(p_buttons[i].xPos + 1, p_buttons[i].yPos + 50, p_buttons[i].colorText9.Text.c_str());
    }
    if(t_state == 10)
    {
      LCD.setPenColor(p_buttons[i].colorText10.Color);
      LCD.setFillColor(p_buttons[i].colorText10.Color);
      LCD.drawRectangle(p_buttons[i].xPos, p_buttons[i].yPos, p_buttons[i].width, p_buttons[i].height);
      LCD.setPenColor(Color.white);
      LCD.printAt(p_buttons[i].xPos + 1, p_buttons[i].yPos + 50, p_buttons[i].colorText10.Text.c_str());
    }
    if(t_state == 11)
    {
      LCD.setPenColor(p_buttons[i].colorText11.Color);
      LCD.setFillColor(p_buttons[i].colorText11.Color);
      LCD.drawRectangle(p_buttons[i].xPos, p_buttons[i].yPos, p_buttons[i].width, p_buttons[i].height);
      LCD.setPenColor(Color.white);
      LCD.printAt(p_buttons[i].xPos + 1, p_buttons[i].yPos + 50, p_buttons[i].colorText11.Text.c_str());
    }
  }

  LCD.setFillColor(Color.transparent);
  LCD.drawRectangle(p_buttons[currentButton].xPos - 2, p_buttons[currentButton].yPos - 2, p_buttons[currentButton].width + 2, p_buttons[currentButton].height + 2);

  LCD.render();
}

void drawButton(s_button p_button)
{
  int t_state = p_button.state;

  if(t_state == 0)
  {
    LCD.setPenColor(p_button.colorText0.Color);
    LCD.setFillColor(p_button.colorText0.Color);
    LCD.drawRectangle(p_button.xPos, p_button.yPos, p_button.width, p_button.height);
    LCD.setPenColor(Color.white);
    LCD.printAt(p_button.xPos + 1, p_button.yPos + 50, p_button.colorText0.Text.c_str());
  }
  if(t_state == 1)
  {
    LCD.setPenColor(p_button.colorText1.Color);
    LCD.setFillColor(p_button.colorText1.Color);
    LCD.drawRectangle(p_button.xPos, p_button.yPos, p_button.width, p_button.height);
    LCD.setPenColor(Color.white);
    LCD.printAt(p_button.xPos + 1, p_button.yPos + 50, p_button.colorText1.Text.c_str());
  }
  if(t_state == 2)
  {
    LCD.setPenColor(p_button.colorText2.Color);
    LCD.setFillColor(p_button.colorText2.Color);
    LCD.drawRectangle(p_button.xPos, p_button.yPos, p_button.width, p_button.height);
    LCD.setPenColor(Color.white);
    LCD.printAt(p_button.xPos + 1, p_button.yPos + 50, p_button.colorText2.Text.c_str());
  }
  if(t_state == 3)
  {
    LCD.setPenColor(p_button.colorText3.Color);
    LCD.setFillColor(p_button.colorText3.Color);
    LCD.drawRectangle(p_button.xPos, p_button.yPos, p_button.width, p_button.height);
    LCD.setPenColor(Color.white);
    LCD.printAt(p_button.xPos + 1, p_button.yPos + 50, p_button.colorText3.Text.c_str());
  }
  if(t_state == 4)
  {
    LCD.setPenColor(p_button.colorText4.Color);
    LCD.setFillColor(p_button.colorText4.Color);
    LCD.drawRectangle(p_button.xPos, p_button.yPos, p_button.width, p_button.height);
    LCD.setPenColor(Color.white);
    LCD.printAt(p_button.xPos + 1, p_button.yPos + 50, p_button.colorText4.Text.c_str());
  }
  if(t_state == 5)
  {
    LCD.setPenColor(p_button.colorText5.Color);
    LCD.setFillColor(p_button.colorText5.Color);
    LCD.drawRectangle(p_button.xPos, p_button.yPos, p_button.width, p_button.height);
    LCD.setPenColor(Color.white);
    LCD.printAt(p_button.xPos + 1, p_button.yPos + 50, p_button.colorText5.Text.c_str());
  }
  if(t_state == 6)
  {
    LCD.setPenColor(p_button.colorText6.Color);
    LCD.setFillColor(p_button.colorText6.Color);
    LCD.drawRectangle(p_button.xPos, p_button.yPos, p_button.width, p_button.height);
    LCD.setPenColor(Color.white);
    LCD.printAt(p_button.xPos + 1, p_button.yPos + 50, p_button.colorText6.Text.c_str());
  }
  if(t_state == 7)
  {
    LCD.setPenColor(p_button.colorText7.Color);
    LCD.setFillColor(p_button.colorText7.Color);
    LCD.drawRectangle(p_button.xPos, p_button.yPos, p_button.width, p_button.height);
    LCD.setPenColor(Color.white);
    LCD.printAt(p_button.xPos + 1, p_button.yPos + 50, p_button.colorText7.Text.c_str());
  }
  if(t_state == 8)
  {
    LCD.setPenColor(p_button.colorText8.Color);
    LCD.setFillColor(p_button.colorText8.Color);
    LCD.drawRectangle(p_button.xPos, p_button.yPos, p_button.width, p_button.height);
    LCD.setPenColor(Color.white);
    LCD.printAt(p_button.xPos + 1, p_button.yPos + 50, p_button.colorText8.Text.c_str());
  }
  if(t_state == 9)
  {
    LCD.setPenColor(p_button.colorText9.Color);
    LCD.setFillColor(p_button.colorText9.Color);
    LCD.drawRectangle(p_button.xPos, p_button.yPos, p_button.width, p_button.height);
    LCD.setPenColor(Color.white);
    LCD.printAt(p_button.xPos + 1, p_button.yPos + 50, p_button.colorText9.Text.c_str());
  }
  if(t_state == 10)
  {
    LCD.setPenColor(p_button.colorText10.Color);
    LCD.setFillColor(p_button.colorText10.Color);
    LCD.drawRectangle(p_button.xPos, p_button.yPos, p_button.width, p_button.height);
    LCD.setPenColor(Color.white);
    LCD.printAt(p_button.xPos + 1, p_button.yPos + 50, p_button.colorText10.Text.c_str());
  }
  if(t_state == 11)
  {
    LCD.setPenColor(p_button.colorText11.Color);
    LCD.setFillColor(p_button.colorText11.Color);
    LCD.drawRectangle(p_button.xPos, p_button.yPos, p_button.width, p_button.height);
    LCD.setPenColor(Color.white);
    LCD.printAt(p_button.xPos + 1, p_button.yPos + 50, p_button.colorText11.Text.c_str());
  }

  LCD.setFillColor(Color.transparent);
  LCD.drawRectangle(p_button.xPos - 2, p_button.yPos - 2, p_button.width + 2, p_button.height + 2);
}

int main()
{
  vexcodeInit();

  int data;
  std::ifstream ifs;
  std::ofstream ofs;

  int threshold1 = 50;
  int threshold2 = 50;
  int threshold3 = 50;
  int threshold4 = 50;

  s_iText iTexts[12] =
  {
    {0, "LIFT IN"},
    {1, "LIFT OUT"},
    {2, "INTAKES IN"},
    {3, "INTAKES OUT"},
    {4, "LIFT SAME DIRECTION IN"},
    {5, "LIFT SAME DIRECTION OUT"},
    {6, "INTAKES AND LIFT OUT"},
    {7, "INTAKES AND LIFT IN"},
    {8, "LIFT IN SLOW"},
    {9, "LIFT OUT SLOW"},
    {10, "SHOOT BALL"},
    {11, "AUTONOMOUS"}
  };

  s_iText deadbandIText[10] =
  {
    {0, "5"},
    {1, "10"},
    {2, "15"},
    {3, "20"},
    {4, "25"},
    {5, "30"},
    {6, "35"},
    {7, "40"},
    {8, "45"},
    {9, "50"}
  };

  s_button mainButtons[8] = 
  {
    {0, 0, 120, 120, 0, 2, s_colorText{Color.red, "RED"}, s_colorText{Color.blue, "BLUE"}},
    {120, 0, 120, 120, 0, 2, s_colorText{Color.green, "LEFT"}, s_colorText{Color.green, "RIGHT"}},
    {240, 0, 120, 120, 0, 2, s_colorText{Color.green, "MATCH"}, s_colorText{Color.green, "SKILLS"}},
    {360, 0, 120, 120, 0, 2, s_colorText{Color.rgb(210, 105, 30), "SETTINGS"}, s_colorText{Color.rgb(210, 105, 30), "SETTINGS"}},

    {0, 120, 120, 120, 0, 2, s_colorText{Color.rgb(210, 105, 30), "KEYBINDS"}, s_colorText{Color.rgb(210, 105, 30), "KEYBINDS"}},
    {120, 120, 120, 120, 0, 2, s_colorText{Color.rgb(210, 105, 30), "JOYSTICKS"}, s_colorText{Color.rgb(210, 105, 30), "JOYSTICKS"}},
    {240, 120, 120, 120, 0, 2, s_colorText{Color.rgb(210, 105, 30), "MOTORS"}, s_colorText{Color.rgb(210, 105, 30), "MOTORS"}},
    {360, 120, 120, 120, 0, 2, s_colorText{Color.rgb(255, 20, 147), "APPLY[X]"}, s_colorText{Color.rgb(255, 20, 147), "APPLY[X]"}}
  };

  s_button keybindButtons[14] =
  {
    {0, 0, 69, 120, 0, 2, s_colorText{Color.purple, "L1"}, s_colorText{Color.purple, "L1"}},
    {69, 0, 69, 120, 0, 2, s_colorText{Color.purple, "L2"}, s_colorText{Color.purple, "L2"}},
    {138, 0, 69, 120, 0, 2, s_colorText{Color.purple, "R1"}, s_colorText{Color.purple, "R1"}},
    {207, 0, 69, 120, 0, 2, s_colorText{Color.purple, "R2"}, s_colorText{Color.purple, "R2"}},
    {276, 0, 69, 120, 0, 2, s_colorText{Color.purple, "X"}, s_colorText{Color.purple, "X"}},
    {345, 0, 69, 120, 0, 2, s_colorText{Color.purple, "Y"}, s_colorText{Color.purple, "Y"}},
    {414, 0, 69, 120, 0, 2, s_colorText{Color.purple, "A"}, s_colorText{Color.purple, "A"}},

    {0, 120, 69, 120, 0, 2, s_colorText{Color.purple, "B"}, s_colorText{Color.purple, "B"}},
    {69, 120, 69, 120, 0, 2, s_colorText{Color.purple, "UP"}, s_colorText{Color.purple, "UP"}},
    {138, 120, 69, 120, 0, 2, s_colorText{Color.purple, "DOWN"}, s_colorText{Color.purple, "DOWN"}},
    {207, 120, 69, 120, 0, 2, s_colorText{Color.purple, "LEFT"}, s_colorText{Color.purple, "LEFT"}},
    {276, 120, 69, 120, 0, 2, s_colorText{Color.purple, "RIGHT"}, s_colorText{Color.purple, "RIGHT"}},
    {345, 120, 69, 120, 0, 2, s_colorText{Color.rgb(255, 20, 147), "BACK[B]"}, s_colorText{Color.rgb(255, 20, 147), "BACK[B]"}},
    {414, 120, 69, 120, 0, 2, s_colorText{Color.rgb(255, 20, 147), "APPLY[X]"}, s_colorText{Color.rgb(255, 20, 147), "APPLY[X]"}}
  };

  s_button fButtons[12] =
  {
    {0, 0, 480, 120, 0, 12, s_colorText{Color.rgb(255, 128, 0), iTexts[0].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[1].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[2].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[3].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[4].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[5].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[6].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[7].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[8].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[9].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[10].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[11].Text}},
    {0, 0, 480, 120, 0, 12, s_colorText{Color.rgb(255, 128, 0), iTexts[0].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[1].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[2].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[3].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[4].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[5].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[6].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[7].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[8].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[9].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[10].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[11].Text}},
    {0, 0, 480, 120, 0, 12, s_colorText{Color.rgb(255, 128, 0), iTexts[0].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[1].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[2].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[3].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[4].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[5].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[6].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[7].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[8].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[9].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[10].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[11].Text}},
    {0, 0, 480, 120, 0, 12, s_colorText{Color.rgb(255, 128, 0), iTexts[0].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[1].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[2].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[3].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[4].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[5].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[6].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[7].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[8].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[9].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[10].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[11].Text}},
    {0, 0, 480, 120, 0, 12, s_colorText{Color.rgb(255, 128, 0), iTexts[0].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[1].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[2].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[3].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[4].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[5].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[6].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[7].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[8].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[9].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[10].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[11].Text}},
    {0, 0, 480, 120, 0, 12, s_colorText{Color.rgb(255, 128, 0), iTexts[0].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[1].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[2].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[3].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[4].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[5].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[6].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[7].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[8].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[9].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[10].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[11].Text}},
    {0, 0, 480, 120, 0, 12, s_colorText{Color.rgb(255, 128, 0), iTexts[0].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[1].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[2].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[3].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[4].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[5].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[6].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[7].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[8].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[9].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[10].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[11].Text}},
    {0, 0, 480, 120, 0, 12, s_colorText{Color.rgb(255, 128, 0), iTexts[0].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[1].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[2].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[3].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[4].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[5].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[6].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[7].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[8].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[9].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[10].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[11].Text}},
    {0, 0, 480, 120, 0, 12, s_colorText{Color.rgb(255, 128, 0), iTexts[0].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[1].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[2].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[3].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[4].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[5].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[6].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[7].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[8].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[9].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[10].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[11].Text}},
    {0, 0, 480, 120, 0, 12, s_colorText{Color.rgb(255, 128, 0), iTexts[0].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[1].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[2].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[3].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[4].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[5].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[6].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[7].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[8].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[9].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[10].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[11].Text}},
    {0, 0, 480, 120, 0, 12, s_colorText{Color.rgb(255, 128, 0), iTexts[0].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[1].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[2].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[3].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[4].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[5].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[6].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[7].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[8].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[9].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[10].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[11].Text}},
    {0, 0, 480, 120, 0, 12, s_colorText{Color.rgb(255, 128, 0), iTexts[0].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[1].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[2].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[3].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[4].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[5].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[6].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[7].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[8].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[9].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[10].Text}, s_colorText{Color.rgb(255, 128, 0), iTexts[11].Text}}
  };

  s_button dButtons[4] =
  {
    {0, 0, 480, 120, 0, 10, s_colorText{Color.rgb(255, 128, 0), deadbandIText[0].Text}, s_colorText{Color.rgb(255, 128, 0), deadbandIText[1].Text}, s_colorText{Color.rgb(255, 128, 0), deadbandIText[2].Text}, s_colorText{Color.rgb(255, 128, 0), deadbandIText[3].Text}, s_colorText{Color.rgb(255, 128, 0), deadbandIText[4].Text}, s_colorText{Color.rgb(255, 128, 0), deadbandIText[5].Text}, s_colorText{Color.rgb(255, 128, 0), deadbandIText[6].Text}, s_colorText{Color.rgb(255, 128, 0), deadbandIText[7].Text}, s_colorText{Color.rgb(255, 128, 0), deadbandIText[8].Text}, s_colorText{Color.rgb(255, 128, 0), deadbandIText[9].Text}},
    {0, 0, 480, 120, 0, 10, s_colorText{Color.rgb(255, 128, 0), deadbandIText[0].Text}, s_colorText{Color.rgb(255, 128, 0), deadbandIText[1].Text}, s_colorText{Color.rgb(255, 128, 0), deadbandIText[2].Text}, s_colorText{Color.rgb(255, 128, 0), deadbandIText[3].Text}, s_colorText{Color.rgb(255, 128, 0), deadbandIText[4].Text}, s_colorText{Color.rgb(255, 128, 0), deadbandIText[5].Text}, s_colorText{Color.rgb(255, 128, 0), deadbandIText[6].Text}, s_colorText{Color.rgb(255, 128, 0), deadbandIText[7].Text}, s_colorText{Color.rgb(255, 128, 0), deadbandIText[8].Text}, s_colorText{Color.rgb(255, 128, 0), deadbandIText[9].Text}},
    {0, 0, 480, 120, 0, 10, s_colorText{Color.rgb(255, 128, 0), deadbandIText[0].Text}, s_colorText{Color.rgb(255, 128, 0), deadbandIText[1].Text}, s_colorText{Color.rgb(255, 128, 0), deadbandIText[2].Text}, s_colorText{Color.rgb(255, 128, 0), deadbandIText[3].Text}, s_colorText{Color.rgb(255, 128, 0), deadbandIText[4].Text}, s_colorText{Color.rgb(255, 128, 0), deadbandIText[5].Text}, s_colorText{Color.rgb(255, 128, 0), deadbandIText[6].Text}, s_colorText{Color.rgb(255, 128, 0), deadbandIText[7].Text}, s_colorText{Color.rgb(255, 128, 0), deadbandIText[8].Text}, s_colorText{Color.rgb(255, 128, 0), deadbandIText[9].Text}},
    {0, 0, 480, 120, 0, 10, s_colorText{Color.rgb(255, 128, 0), deadbandIText[0].Text}, s_colorText{Color.rgb(255, 128, 0), deadbandIText[1].Text}, s_colorText{Color.rgb(255, 128, 0), deadbandIText[2].Text}, s_colorText{Color.rgb(255, 128, 0), deadbandIText[3].Text}, s_colorText{Color.rgb(255, 128, 0), deadbandIText[4].Text}, s_colorText{Color.rgb(255, 128, 0), deadbandIText[5].Text}, s_colorText{Color.rgb(255, 128, 0), deadbandIText[6].Text}, s_colorText{Color.rgb(255, 128, 0), deadbandIText[7].Text}, s_colorText{Color.rgb(255, 128, 0), deadbandIText[8].Text}, s_colorText{Color.rgb(255, 128, 0), deadbandIText[9].Text}}
  };

  s_button joystickButtons[5] =
  {
    {0, 0, 96, 120, 0, 3, s_colorText{Color.green, "TANK"}, s_colorText{Color.green, "1 ARCADE"}, s_colorText{Color.green, "2 ARCADE"}},
    {96, 0, 96, 120, 0, 2, s_colorText{Color.rgb(16, 133, 72), "TURN TYPE"}, s_colorText{Color.rgb(16, 133, 72), "TURN TYPE"}},
    {192, 0, 96, 120, 0, 2, s_colorText{Color.rgb(16, 133, 72), "KEYBINDS"}, s_colorText{Color.rgb(16, 133, 72), "KEYBINDS"}},
    {288, 0, 96, 120, 0, 2, s_colorText{Color.rgb(210, 105, 30), "DEADBANDS"}, s_colorText{Color.rgb(210, 105, 30), "DEADBANDS"}},
    {384, 0, 96, 120, 0, 2, s_colorText{Color.rgb(210, 105, 30), "PROPORTION"}, s_colorText{Color.rgb(210, 105, 30), "PROPORTION"}}
  };

  s_button deadbandsButtons[4] =
  {
    {0, 0, 120, 120, 0, 2, s_colorText{Color.purple, "AXIS 1"}, s_colorText{Color.purple, "AXIS 1"}},
    {120, 0, 120, 120, 0, 2, s_colorText{Color.purple, "AXIS 2"}, s_colorText{Color.purple, "AXIS 2"}},
    {240, 0, 120, 120, 0, 2, s_colorText{Color.purple, "AXIS 3"}, s_colorText{Color.purple, "AXIS 3"}},
    {360, 0, 120, 120, 0, 2, s_colorText{Color.purple, "AXIS 4"}, s_colorText{Color.purple, "AXIS 4"}}
  };

  s_button turnTypeButtons[2] =
  {
    {0, 0, 160, 120, 0, 2, s_colorText{Color.green, "RELATIVE"}, s_colorText{Color.green, "ABSOLUTE"}},
    {0, 0, 160, 120, 0, 2, s_colorText{Color.green, "RELATIVE"}, s_colorText{Color.green, "ABSOLUTE"}}
  };

  s_button ttr1Buttons[2] =
  {
    {160, 0, 160, 120, 0, 1, s_colorText{Color.rgb(83, 62, 138), "L: DRIVE & TURN"}},
    {320, 0, 160, 120, 0, 1, s_colorText{Color.rgb(83, 62, 138), "R: KEYBINDS"}}
  };

  s_button tta1Buttons[2] =
  {
    {160, 0, 160, 120, 0, 1, s_colorText{Color.rgb(83, 62, 138), "L: DRIVE & TURN"}},
    {320, 0, 160, 120, 0, 1, s_colorText{Color.rgb(83, 62, 138), "R: ABS-TURN"}}
  };

  s_button ttr2Buttons[2] =
  {
    {160, 0, 160, 120, 0, 1, s_colorText{Color.rgb(83, 62, 138), "L: DRIVE"}},
    {320, 0, 160, 120, 0, 1, s_colorText{Color.rgb(83, 62, 138), "R: TURN"}}
  };

  s_button tta2Buttons[2] =
  {
    {160, 0, 160, 120, 0, 1, s_colorText{Color.rgb(83, 62, 138), "L: DRIVE"}},
    {320, 0, 160, 120, 0, 1, s_colorText{Color.rgb(83, 62, 138), "R: ABS-TURN"}}
  };

  s_button settingsButtons[2] =
  {
    {0, 0, 240, 120, 0, 2, s_colorText{Color.green, "2 WHEEL TURN"}, s_colorText{Color.green, "4 WHEEL TURN"}},
    {240, 0, 240, 120, 0, 2, s_colorText{Color.green, "ERRORS OFF"}, s_colorText{Color.green, "ERRORS ON"}}
  };

  s_button backButtons2x2[2] =
  {
    {0, 120, 240, 120, 0, 2, s_colorText{Color.rgb(255, 20, 147), "BACK[B]"}, s_colorText{Color.rgb(255, 20, 147), "BACK[B]"}},
    {240, 120, 240, 120, 0, 2, s_colorText{Color.rgb(255, 20, 147), "APPLY[X]"}, s_colorText{Color.rgb(255, 20, 147), "APPLY[X]"}}
  };

  s_button messageButtons[1] =
  {
    {0, 0, 480, 120, 0, 1, s_colorText{Color.black, "REQUIRES ARCADE"}},
  };


  ifs.open("matchsettings.txt", ifs.in);
  for(int i = 0; i < 3; i++)
  {
    ifs >> data;
    mainButtons[i].state = data;
  }
  ifs.close();

  ifs.open("keybinds.txt", ifs.in);
  for(int i = 0; i < 12; i++)
  {
    ifs >> data;
    fButtons[i].state = data;
  }
  ifs.close();

  ifs.open("joysticks.txt", ifs.in);
  ifs >> data;
  joystickButtons[0].state = data;
  ifs.close();

  ifs.open("deadbands.txt", ifs.in);
  for(int i = 0; i < 4; i++)
  {
    ifs >> data;
    dButtons[i].state = data;
  }
  ifs.close();

  ifs.open("settings.txt", ifs.in);
  for(int i = 0; i < 2; i++)
  {
    ifs >> data;
    settingsButtons[i].state = data;
  }
  ifs.close();

  bool applied = false;
  int currentMenu = 0;
  int currentKey = 0;
  int currentDeadband = 0;
  int btnNextRow = 0;
  int maxBtn = 0;
  int t_prevBtn = 0;
  bool t_2b = false;
  
  if(Brain.SDcard.isInserted())
  {
    while(!applied)
    {
      if(Controller.ButtonL1.pressing() || Controller.ButtonL2.pressing() || Controller.ButtonLeft.pressing() || Controller.Axis1.position() < -threshold1 || Controller.Axis4.position() < -threshold4) currentButton--;
      if(Controller.ButtonR1.pressing() || Controller.ButtonR2.pressing() || Controller.ButtonRight.pressing() || Controller.Axis1.position() > threshold1 || Controller.Axis4.position() > threshold4) currentButton++;
      if(Controller.ButtonUp.pressing() || Controller.Axis3.position() > threshold3 || Controller.Axis2.position() > threshold2) currentButton -= btnNextRow;
      if(Controller.ButtonDown.pressing() || Controller.Axis3.position() < -threshold3 || Controller.Axis2.position() < -threshold2) currentButton += btnNextRow;

      if(currentButton > maxBtn) currentButton = maxBtn;
      else if(currentButton < 0) currentButton = 0;

      if(currentMenu == 0) //main menu
      {
        btnNextRow = 4;
        maxBtn = 7;
        drawButtons(mainButtons, 8);
        
        if(Controller.ButtonA.pressing() || Controller.ButtonY.pressing())
        {
          if(Controller.ButtonA.pressing())
          {
            mainButtons[currentButton].state++;
            if(mainButtons[currentButton].state > mainButtons[currentButton].size - 1) mainButtons[currentButton].state = 0;
          }
          else if(Controller.ButtonY.pressing())
          {
            mainButtons[currentButton].state--;
            if(mainButtons[currentButton].state < 0) mainButtons[currentButton].state = mainButtons[currentButton].size;
          }
        }
        if(LCD.pressing())
        {
          buttonTouch(mainButtons, 8);
        }

        if(mainButtons[7].state == 1 || Controller.ButtonX.pressing()) applied = true;

        if(mainButtons[3].state > 0)
        {
          mainButtons[3].state = 0;
          currentMenu = 7;
          currentButton = 0;
        }

        if(mainButtons[4].state > 0)
        {
          mainButtons[4].state = 0;
          currentMenu = 1;
          currentButton = 0;
        }

        if(mainButtons[5].state > 0)
        {
          mainButtons[5].state = 0;
          currentMenu = 3;
          currentButton = 0;
        }
      }
      else if(currentMenu == 1) //keybinds menu
      {
        if(t_2b) 
        {
          currentButton = t_prevBtn;
          t_2b = false;
        }
        btnNextRow = 7;
        maxBtn = 13;
        drawButtons(keybindButtons, 14);

        if(Controller.ButtonA.pressing() || Controller.ButtonY.pressing())
        {
          if(Controller.ButtonA.pressing())
          {
            keybindButtons[currentButton].state++;
            if(keybindButtons[currentButton].state > keybindButtons[currentButton].size - 1) keybindButtons[currentButton].state = 0;
          }
          else if(Controller.ButtonY.pressing())
          {
            keybindButtons[currentButton].state--;
            if(keybindButtons[currentButton].state < 0) keybindButtons[currentButton].state = keybindButtons[currentButton].size - 1;
          }
        }
        if(LCD.pressing())
        {
          buttonTouch(keybindButtons, 14);
        }

        for(int i = 0; i < 12; i++)
        {
          if(keybindButtons[i].state > 0)
          {
            t_prevBtn = currentButton;
            currentButton = 0;
            keybindButtons[i].state = 0;
            currentKey = i;
            currentMenu = 2;
            break;
          }
        }

        if(keybindButtons[13].state == 1 || Controller.ButtonX.pressing()) applied = true;

        if(keybindButtons[12].state == 1 || Controller.ButtonB.pressing())
        {
          keybindButtons[12].state = 0;
          currentMenu = 0;
          currentButton = 0;
        }
      }
      else if(currentMenu == 2) //configure key submenu
      {
        btnNextRow = 2;
        maxBtn = 2;

        s_button t_btn[3];
        t_btn[0] = fButtons[currentKey];
        t_btn[1] = backButtons2x2[0];
        t_btn[2] = backButtons2x2[1];
        drawButtons(t_btn, 3);

        if(Controller.ButtonA.pressing() || Controller.ButtonY.pressing())
        {
          if(currentButton == 0)
          {
            if(Controller.ButtonA.pressing())
            {
              fButtons[currentKey].state++;
              if(fButtons[currentKey].state > fButtons[currentKey].size - 1) fButtons[currentKey].state = 0;
            }
            else if(Controller.ButtonY.pressing())
            {
              fButtons[currentKey].state--;
              if(fButtons[currentKey].state < 0) fButtons[currentKey].state = fButtons[currentKey].size - 1;
            }
          }
          else
          {
            if(Controller.ButtonA.pressing())
            {
              backButtons2x2[currentButton - 1].state++;
              if(backButtons2x2[currentButton - 1].state > backButtons2x2[currentButton - 1].size - 1) backButtons2x2[currentButton - 1].state = 0;
            }
            else if(Controller.ButtonY.pressing())
            {
              backButtons2x2[currentButton - 1].state--;
              if(backButtons2x2[currentButton - 1].state < 0) backButtons2x2[currentButton - 1].state = backButtons2x2[currentButton - 1].size - 1;
            }
          }
        }
        if(LCD.pressing())
        {
          fButtons[currentKey] = buttonTouch(fButtons[currentKey]);
          buttonTouch(backButtons2x2, 2);
        }

        if(backButtons2x2[1].state == 1 || Controller.ButtonX.pressing()) applied = true;

        if(backButtons2x2[0].state == 1 || Controller.ButtonB.pressing())
        {
          backButtons2x2[0].state = 0;
          currentMenu = 1;
          t_2b = true;
        }
      }
      else if(currentMenu == 3) //joysticks menu
      {
        btnNextRow = 5;
        maxBtn = 6;

        s_button t_btn[7];
        for(int i = 0; i < 5; i++) t_btn[i] = joystickButtons[i];
        t_btn[5] = backButtons2x2[0];
        t_btn[6] = backButtons2x2[1];
        drawButtons(t_btn, 7);

        if(Controller.ButtonA.pressing() || Controller.ButtonY.pressing())
        {
          if(currentButton < 5)
          {
            if(Controller.ButtonA.pressing())
            {
              joystickButtons[currentButton].state++;
              if(joystickButtons[currentButton].state > joystickButtons[currentButton].size - 1) joystickButtons[currentButton].state = 0;
            }
            else if(Controller.ButtonY.pressing())
            {
              joystickButtons[currentButton].state--;
              if(joystickButtons[currentButton].state < 0) joystickButtons[currentButton].state = joystickButtons[currentButton].size - 1;
            }
          }
          else
          {
            if(Controller.ButtonA.pressing())
            {
              backButtons2x2[currentButton - 5].state++;
              if(backButtons2x2[currentButton - 5].state > backButtons2x2[currentButton - 5].size - 1) backButtons2x2[currentButton - 5].state = 0;
            }
            else if(Controller.ButtonY.pressing())
            {
              backButtons2x2[currentButton - 5].state--;
              if(backButtons2x2[currentButton - 5].state < 0) backButtons2x2[currentButton - 5].state = backButtons2x2[currentButton - 5].size - 1;
            }
          }
        }
        if(LCD.pressing())
        {
          buttonTouch(joystickButtons, 5);
          buttonTouch(backButtons2x2, 2);
        }

        if(joystickButtons[3].state > 0)
        {
          joystickButtons[3].state = 0;
          currentMenu = 4;
          currentButton = 0;
        }

        if(joystickButtons[1].state > 0)
        {
          joystickButtons[1].state = 0;
          currentMenu = 6;
          currentButton = 0;
        }

        if(backButtons2x2[1].state == 1 || Controller.ButtonX.pressing()) applied = true;

        if(backButtons2x2[0].state == 1 || Controller.ButtonB.pressing())
        {
          backButtons2x2[0].state = 0;
          currentMenu = 0;
          currentButton = 0;
        }
      }
      else if(currentMenu == 4) //deadbands menu
      {
        if(t_2b) 
        {
          currentButton = t_prevBtn;
          t_2b = false;
        }
        btnNextRow = 4;
        maxBtn = 5;

        s_button t_btn[6];
        for(int i = 0; i < 4; i++) t_btn[i] = deadbandsButtons[i];
        t_btn[4] = backButtons2x2[0];
        t_btn[5] = backButtons2x2[1];
        drawButtons(t_btn, 6);

        if(Controller.ButtonA.pressing() || Controller.ButtonY.pressing())
        {
          if(currentButton < 4)
          {
            if(Controller.ButtonA.pressing())
            {
              deadbandsButtons[currentButton].state++;
              if(deadbandsButtons[currentButton].state > deadbandsButtons[currentButton].size - 1) deadbandsButtons[currentButton].state = 0;
            }
            else if(Controller.ButtonY.pressing())
            {
              deadbandsButtons[currentButton].state--;
              if(deadbandsButtons[currentButton].state < 0) deadbandsButtons[currentButton].state = deadbandsButtons[currentButton].size - 1;
            }
          }
          else
          {
            if(Controller.ButtonA.pressing())
            {
              backButtons2x2[currentButton - 4].state++;
              if(backButtons2x2[currentButton - 4].state > backButtons2x2[currentButton - 4].size - 1) backButtons2x2[currentButton - 4].state = 0;
            }
            else if(Controller.ButtonY.pressing())
            {
              backButtons2x2[currentButton - 4].state--;
              if(backButtons2x2[currentButton - 4].state < 0) backButtons2x2[currentButton - 4].state = backButtons2x2[currentButton-4].size - 1;
            }
          }
        }
        if(LCD.pressing())
        {
          buttonTouch(deadbandsButtons, 4);
          buttonTouch(backButtons2x2, 2);
        }

        for(int i = 0; i < 4; i++)
        {
          if(deadbandsButtons[i].state > 0)
          {
            t_prevBtn = currentButton;
            currentButton = 0;
            deadbandsButtons[i].state = 0;
            currentDeadband = i;
            currentMenu = 5;
            break;
          }
        }

        if(backButtons2x2[1].state == 1 || Controller.ButtonX.pressing()) applied = true;

        if(backButtons2x2[0].state == 1 || Controller.ButtonB.pressing())
        {
          backButtons2x2[0].state = 0;
          currentMenu = 3;
          currentButton = 0;
        }
      }
      else if(currentMenu == 5) //deadbands axis submenu
      {
        btnNextRow = 2;
        maxBtn = 2;

        s_button t_btn[3];
        t_btn[0] = dButtons[currentDeadband];
        t_btn[1] = backButtons2x2[0];
        t_btn[2] = backButtons2x2[1];
        drawButtons(t_btn, 3);

        if(Controller.ButtonA.pressing() || Controller.ButtonY.pressing())
        {
          if(currentButton == 0)
          {
            if(Controller.ButtonA.pressing())
            {
              dButtons[currentDeadband].state++;
              if(dButtons[currentDeadband].state > dButtons[currentDeadband].size - 1) dButtons[currentDeadband].state = 0;
            }
            else if(Controller.ButtonY.pressing())
            {
              dButtons[currentDeadband].state--;
              if(dButtons[currentDeadband].state < 0) dButtons[currentDeadband].state = dButtons[currentDeadband].size - 1;
            }
          }
          else
          {
            if(Controller.ButtonA.pressing())
            {
              backButtons2x2[currentButton - 1].state++;
              if(backButtons2x2[currentButton - 1].state > backButtons2x2[currentButton - 1].size - 1) backButtons2x2[currentButton - 1].state = 0;
            }
            else if(Controller.ButtonY.pressing())
            {
              backButtons2x2[currentButton - 1].state--;
              if(backButtons2x2[currentButton - 1].state < 0) backButtons2x2[currentButton - 1].state = backButtons2x2[currentButton - 1].size - 1;
            }
          }
        }
        if(LCD.pressing())
        {
          dButtons[currentDeadband] = buttonTouch(dButtons[currentDeadband]);
          buttonTouch(backButtons2x2, 2);
        }

        if(backButtons2x2[1].state == 1 || Controller.ButtonX.pressing()) applied = true;

        if(backButtons2x2[0].state == 1 || Controller.ButtonB.pressing())
        {
          backButtons2x2[0].state = 0;
          currentMenu = 4;
          t_2b = true;
        }
      }
      else if(currentMenu == 6) //turn type
      {
        if(joystickButtons[0].state == 0) //tank
        {
          btnNextRow = 2;
          maxBtn = 2;
          s_button t_btn[3];
          t_btn[0] = messageButtons[0];
          t_btn[1] = backButtons2x2[0];
          t_btn[2] = backButtons2x2[1];
          drawButtons(t_btn, 3);

          if(Controller.ButtonA.pressing() || Controller.ButtonY.pressing())
          {
            if(currentButton != 0)
            {
              if(Controller.ButtonA.pressing())
              {
                backButtons2x2[currentButton - 1].state++;
                if(backButtons2x2[currentButton - 1].state > backButtons2x2[currentButton - 1].size - 1) backButtons2x2[currentButton - 1].state = 0;
              }
              else if(Controller.ButtonY.pressing())
              {
                backButtons2x2[currentButton - 1].state--;
                if(backButtons2x2[currentButton - 1].state < 0) backButtons2x2[currentButton - 1].state = backButtons2x2[currentButton - 1].size - 1;
              }
            }
          }
          if(LCD.pressing())
          {
            messageButtons[0] = buttonTouch(messageButtons[0]);
            buttonTouch(backButtons2x2, 2);
          }

          if(backButtons2x2[1].state == 1 || Controller.ButtonX.pressing()) applied = true;

          if(backButtons2x2[0].state == 1 || Controller.ButtonB.pressing())
          {
            backButtons2x2[0].state = 0;
            currentMenu = 3;
          }
        }
        else if(joystickButtons[0].state == 1) //1 arcade
        {
          btnNextRow = 3;
          maxBtn = 4;
          s_button t_btn[5];
          t_btn[0] = turnTypeButtons[0];
          if(turnTypeButtons[0].state == 0) //relative
          {
            t_btn[1] = ttr1Buttons[0];
            t_btn[2] = ttr1Buttons[1];
          }
          else if(turnTypeButtons[0].state == 1) //absolute
          {
            t_btn[1] = tta1Buttons[0];
            t_btn[2] = tta1Buttons[1];
          }
          t_btn[3] = backButtons2x2[0];
          t_btn[4] = backButtons2x2[1];
          drawButtons(t_btn, 5);

          if(Controller.ButtonA.pressing() || Controller.ButtonY.pressing())
          {
            if(currentButton == 0)
            {
              if(Controller.ButtonA.pressing())
              {
                turnTypeButtons[0].state++;
                if(turnTypeButtons[0].state > turnTypeButtons[0].size - 1) turnTypeButtons[0].state = 0;
              }
              else if(Controller.ButtonY.pressing())
              {
                turnTypeButtons[0].state--;
                if(turnTypeButtons[0].state < 0) turnTypeButtons[0].state = turnTypeButtons[0].size - 1;
              }
            }
            else if(currentButton > 2)
            {
              if(Controller.ButtonA.pressing())
              {
                backButtons2x2[currentButton - 3].state++;
                if(backButtons2x2[currentButton - 3].state > backButtons2x2[currentButton - 3].size - 1) backButtons2x2[currentButton - 3].state = 0;
              }
              else if(Controller.ButtonY.pressing())
              {
                backButtons2x2[currentButton - 3].state--;
                if(backButtons2x2[currentButton - 3].state < 0) backButtons2x2[currentButton - 3].state = backButtons2x2[currentButton - 3].size - 1;
              }
            }
          }
          if(LCD.pressing())
          {
            turnTypeButtons[0] = buttonTouch(turnTypeButtons[0]);
            buttonTouch(backButtons2x2, 2);
          }

          if(backButtons2x2[1].state == 1 || Controller.ButtonX.pressing()) applied = true;

          if(backButtons2x2[0].state == 1 || Controller.ButtonB.pressing())
          {
            backButtons2x2[0].state = 0;
            currentMenu = 3;
          }
        }
        else if(joystickButtons[0].state == 2) //2 arcade
        {
          btnNextRow = 3;
          maxBtn = 4;
          s_button t_btn[5];
          t_btn[0] = turnTypeButtons[1];
          if(turnTypeButtons[1].state == 0) //relative
          {
            t_btn[1] = ttr2Buttons[0];
            t_btn[2] = ttr2Buttons[1];
          }
          else if(turnTypeButtons[1].state == 1) //absolute
          {
            t_btn[1] = tta2Buttons[0];
            t_btn[2] = tta2Buttons[1];
          }
          t_btn[3] = backButtons2x2[0];
          t_btn[4] = backButtons2x2[1];
          drawButtons(t_btn, 5);

          if(Controller.ButtonA.pressing() || Controller.ButtonY.pressing())
          {
            if(currentButton == 0)
            {
              if(Controller.ButtonA.pressing())
              {
                turnTypeButtons[1].state++;
                if(turnTypeButtons[1].state > turnTypeButtons[1].size - 1) turnTypeButtons[1].state = 0;
              }
              else if(Controller.ButtonY.pressing())
              {
                turnTypeButtons[1].state--;
                if(turnTypeButtons[1].state < 0) turnTypeButtons[1].state = turnTypeButtons[1].size - 1;
              }
            }
            else if(currentButton > 2)
            {
              if(Controller.ButtonA.pressing())
              {
                backButtons2x2[currentButton - 3].state++;
                if(backButtons2x2[currentButton - 3].state > backButtons2x2[currentButton - 3].size - 1) backButtons2x2[currentButton - 3].state = 0;
              }
              else if(Controller.ButtonY.pressing())
              {
                backButtons2x2[currentButton - 3].state--;
                if(backButtons2x2[currentButton - 3].state < 0) backButtons2x2[currentButton - 3].state = backButtons2x2[currentButton - 3].size - 1;
              }
            }
          }
          if(LCD.pressing())
          {
            turnTypeButtons[0] = buttonTouch(turnTypeButtons[0]);
            buttonTouch(backButtons2x2, 2);
          }

          if(backButtons2x2[1].state == 1 || Controller.ButtonX.pressing()) applied = true;

          if(backButtons2x2[0].state == 1 || Controller.ButtonB.pressing())
          {
            backButtons2x2[0].state = 0;
            currentMenu = 3;
          }
        }
      }
      else if(currentMenu == 7) //settings menu
      {
        btnNextRow = 2;
        maxBtn = 3;

        s_button t_btn[4];
        t_btn[0] = settingsButtons[0];
        t_btn[1] = settingsButtons[1];
        t_btn[2] = backButtons2x2[0];
        t_btn[3] = backButtons2x2[1];
        drawButtons(t_btn, 4);

        if(Controller.ButtonA.pressing() || Controller.ButtonY.pressing())
        {
          if(currentButton < 2)
          {
            if(Controller.ButtonA.pressing())
            {
              settingsButtons[currentButton].state++;
              if(settingsButtons[currentButton].state > settingsButtons[currentButton].size - 1) settingsButtons[currentButton].state = 0;
            }
            else if(Controller.ButtonY.pressing())
            {
              settingsButtons[currentButton].state--;
              if(settingsButtons[currentButton].state < currentButton) settingsButtons[currentButton].state = settingsButtons[currentButton].size - 1;
            }
          }
          else
          {
            if(Controller.ButtonA.pressing())
            {
              backButtons2x2[currentButton - 2].state++;
              if(backButtons2x2[currentButton - 2].state > backButtons2x2[currentButton - 2].size - 1) backButtons2x2[currentButton - 2].state = 0;
            }
            else if(Controller.ButtonY.pressing())
            {
              backButtons2x2[currentButton - 2].state--;
              if(backButtons2x2[currentButton - 2].state < 0) backButtons2x2[currentButton - 2].state = backButtons2x2[currentButton - 2].size - 1;
            }
          }
        }
        if(LCD.pressing())
        {
          buttonTouch(settingsButtons, 2);
          buttonTouch(backButtons2x2, 2);
        }

        if(backButtons2x2[1].state == 1 || Controller.ButtonX.pressing()) applied = true;

        if(backButtons2x2[0].state == 1 || Controller.ButtonB.pressing())
        {
          backButtons2x2[0].state = 0;
          currentMenu = 1;
        }
      }

      if(Controller.ButtonA.pressing() || Controller.ButtonB.pressing() || Controller.ButtonX.pressing() || Controller.ButtonY.pressing() ||
      Controller.ButtonUp.pressing() || Controller.ButtonDown.pressing() || Controller.ButtonLeft.pressing() || Controller.ButtonRight.pressing() || 
      Controller.ButtonL1.pressing()  || Controller.ButtonL2.pressing()  || Controller.ButtonR1.pressing()  || Controller.ButtonR2.pressing() || 
      Controller.Axis3.position() < -threshold3 || Controller.Axis4.position() < -threshold4 || Controller.Axis3.position() > threshold3 || Controller.Axis4.position() > threshold4 ||
      Controller.Axis1.position() < -threshold1 || Controller.Axis2.position() < -threshold2 || Controller.Axis1.position() > threshold1|| Controller.Axis2.position() > threshold2 ||
      LCD.pressing())
      Task.sleep(250);
      else Task.sleep(15);
    }

    LCD.clearScreen();
    LCD.render();

    if(!Brain.SDcard.isInserted())
    {
      LCD.print("NO SD CARD");
      LCD.render();
      while(true) Controller.rumble("-");
    }
    else
    {
      ofs.open("matchsettings.txt", ofs.out);
      ofs << mainButtons[0].state << "\n";
      ofs << mainButtons[1].state << "\n";
      ofs << mainButtons[2].state;
      ofs.close();

      ofs.open("keybinds.txt", ofs.out);
      ofs << iTexts[fButtons[0].state].Index << "\n";
      ofs << iTexts[fButtons[1].state].Index << "\n";
      ofs << iTexts[fButtons[2].state].Index << "\n";
      ofs << iTexts[fButtons[3].state].Index << "\n";
      ofs << iTexts[fButtons[4].state].Index << "\n";
      ofs << iTexts[fButtons[5].state].Index << "\n";
      ofs << iTexts[fButtons[6].state].Index << "\n";
      ofs << iTexts[fButtons[7].state].Index << "\n";
      ofs << iTexts[fButtons[8].state].Index << "\n";
      ofs << iTexts[fButtons[9].state].Index << "\n";
      ofs << iTexts[fButtons[10].state].Index << "\n";
      ofs << iTexts[fButtons[11].state].Index;
      ofs.close();

      ofs.open("joysticks.txt", ofs.out);
      ofs << joystickButtons[0].state << "\n";
      if(joystickButtons[0].state == 0) ofs << 0 << "\n";
      else if(joystickButtons[0].state == 1) ofs << turnTypeButtons[0].state + 1 << "\n";
      else if(joystickButtons[0].state == 2) ofs << turnTypeButtons[1].state + 1 << "\n";
      ofs.close();

      ofs.open("deadbands.txt", ofs.out);
      ofs << deadbandIText[dButtons[0].state].Index << "\n";
      ofs << deadbandIText[dButtons[1].state].Index << "\n";
      ofs << deadbandIText[dButtons[2].state].Index << "\n";
      ofs << deadbandIText[dButtons[3].state].Index;
      ofs.close();

      ofs.open("settings.txt", ofs.out);
      ofs << settingsButtons[0].state << "\n";
      ofs << settingsButtons[1].state;
      ofs.close();

      LCD.print("Config files saved");
      LCD.render();
    }
  }
  if(!Brain.SDcard.isInserted())
  {
    LCD.print("NO SD CARD");
    LCD.render();
    while(true) Controller.rumble("-"); 
  }
}