#include "vex.h"

#include <cstdio>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace vex;

int data;
std::ifstream ifs;
std::ofstream ofs;

int threshold1 = 50;
int threshold2 = 50;
int threshold3 = 50;
int threshold4 = 50;

int currentButton = 0;

typedef struct _colorText
{
  color Color;
  std::string Text;
} s_colorText;

typedef struct _IFText
{
  int Index;
  std::string Text;
} s_IFText;

typedef struct _button
{
  int xPos, yPos, width, height, state, size;
  s_colorText colorText0, colorText1, colorText2, colorText3, colorText4, colorText5, colorText6, colorText7, colorText8, colorText9, colorText10, colorText11;
} s_button;

typedef struct _button2
{
  int xPos, yPos, width, height, state, size;
  s_IFText IFText;
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

  s_IFText IFTexts[12] =
  {
    {0, "rMotors+"},
    {1, "rMotors-"},
    {2, "FUNCTION 3"},
    {3, "FUNCTION 4"},
    {4, "FUNCTION 5"},
    {5, "FUNCTION 6"},
    {6, "FUNCTION 7"},
    {7, "FUNCTION 8"},
    {8, "FUNCTION 9"},
    {9, "FUNCTION 10"},
    {10, "FUNCTION 11"},
    {11, "AUTONOMOUS"}
  };

  s_button mainButtons[8] = 
  {
    {10, 20, 100, 75, 0, 2, s_colorText{Color.red, "RED"}, s_colorText{Color.blue, "BLUE"}},
    {130, 20, 100, 75, 0, 2, s_colorText{Color.green, "LEFT"}, s_colorText{Color.purple, "RIGHT"}},
    {250, 20, 100, 75, 0, 2, s_colorText{Color.green, "MATCH"}, s_colorText{Color.purple, "SKILLS"}},
    {370, 20, 100, 75, 0, 1, s_colorText{Color.white, ""}},

    {10, 140, 100, 75, 0, 2, s_colorText{Color.yellow, "KEYBINDS"}, s_colorText{Color.yellow, "KEYBINDS"}},
    {130, 140, 100, 75, 0, 2, s_colorText{Color.yellow, "JOYSTICKS"}, s_colorText{Color.yellow, "JOYSTICKS"}},
    {250, 140, 100, 75, 0, 2, s_colorText{Color.yellow, "MOTORS"}, s_colorText{Color.yellow, "MOTORS"}},
    {370, 140, 100, 75, 0, 2, s_colorText{Color.rgb(255, 20, 147), "APPLY[X]"}, s_colorText{Color.rgb(255, 20, 147), "APPLY[X]"}}
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
    {0, 0, 480, 120, 0, 12, s_colorText{Color.rgb(255, 128, 0), IFTexts[0].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[1].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[2].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[3].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[4].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[5].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[6].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[7].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[8].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[9].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[10].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[11].Text}},
    {0, 0, 480, 120, 0, 12, s_colorText{Color.rgb(255, 128, 0), IFTexts[0].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[1].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[2].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[3].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[4].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[5].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[6].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[7].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[8].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[9].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[10].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[11].Text}},
    {0, 0, 480, 120, 0, 12, s_colorText{Color.rgb(255, 128, 0), IFTexts[0].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[1].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[2].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[3].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[4].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[5].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[6].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[7].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[8].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[9].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[10].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[11].Text}},
    {0, 0, 480, 120, 0, 12, s_colorText{Color.rgb(255, 128, 0), IFTexts[0].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[1].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[2].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[3].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[4].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[5].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[6].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[7].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[8].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[9].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[10].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[11].Text}},
    {0, 0, 480, 120, 0, 12, s_colorText{Color.rgb(255, 128, 0), IFTexts[0].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[1].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[2].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[3].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[4].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[5].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[6].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[7].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[8].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[9].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[10].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[11].Text}},
    {0, 0, 480, 120, 0, 12, s_colorText{Color.rgb(255, 128, 0), IFTexts[0].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[1].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[2].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[3].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[4].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[5].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[6].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[7].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[8].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[9].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[10].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[11].Text}},
    {0, 0, 480, 120, 0, 12, s_colorText{Color.rgb(255, 128, 0), IFTexts[0].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[1].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[2].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[3].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[4].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[5].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[6].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[7].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[8].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[9].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[10].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[11].Text}},
    {0, 0, 480, 120, 0, 12, s_colorText{Color.rgb(255, 128, 0), IFTexts[0].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[1].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[2].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[3].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[4].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[5].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[6].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[7].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[8].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[9].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[10].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[11].Text}},
    {0, 0, 480, 120, 0, 12, s_colorText{Color.rgb(255, 128, 0), IFTexts[0].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[1].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[2].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[3].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[4].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[5].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[6].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[7].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[8].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[9].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[10].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[11].Text}},
    {0, 0, 480, 120, 0, 12, s_colorText{Color.rgb(255, 128, 0), IFTexts[0].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[1].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[2].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[3].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[4].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[5].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[6].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[7].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[8].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[9].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[10].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[11].Text}},
    {0, 0, 480, 120, 0, 12, s_colorText{Color.rgb(255, 128, 0), IFTexts[0].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[1].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[2].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[3].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[4].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[5].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[6].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[7].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[8].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[9].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[10].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[11].Text}},
    {0, 0, 480, 120, 0, 12, s_colorText{Color.rgb(255, 128, 0), IFTexts[0].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[1].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[2].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[3].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[4].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[5].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[6].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[7].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[8].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[9].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[10].Text}, s_colorText{Color.rgb(255, 128, 0), IFTexts[11].Text}}
  };

  s_button joystickButtons[5] =
  {
    {0, 0, 96, 120, 0, 3, s_colorText{Color.rgb(255, 128, 0), "Tank"}, s_colorText{Color.rgb(255, 128, 0), "1 Arcade"}, s_colorText{Color.rgb(255, 128, 0), "2, Arcade"}},
    {96, 0, 96, 120, 0, 2, s_colorText{Color.rgb(255, 128, 0), "Thresholds"}, s_colorText{Color.rgb(255, 128, 0), "Thresholds"}},
    {192, 0, 96, 120, 0, 2, s_colorText{Color.rgb(255, 128, 0), "Proportion"}, s_colorText{Color.rgb(255, 128, 0), "Proportion"}},
    {288, 0, 96, 120, 0, 2, s_colorText{Color.rgb(255, 128, 0), "Turn Type"}, s_colorText{Color.rgb(255, 128, 0), "Turn Type"}},
    {384, 0, 96, 120, 0, 2, s_colorText{Color.rgb(255, 128, 0), "Keybinds"}, s_colorText{Color.rgb(255, 128, 0), "Keybinds"}}
  };

  s_button backButtons2x2[2] =
  {
    {0, 120, 240, 120, 0, 2, s_colorText{Color.rgb(255, 20, 147), "BACK[B]"}, s_colorText{Color.rgb(255, 20, 147), "BACK[B]"}},
    {240, 120, 240, 120, 0, 2, s_colorText{Color.rgb(255, 20, 147), "APPLY[X]"}, s_colorText{Color.rgb(255, 20, 147), "APPLY[X]"}}
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

  bool applied = false;
  int currentMenu = 0;
  int currentKey = 0;
  int btnNextRow = 0;
  int maxBtn = 0;
  int t_prevBtn = 0;
  bool t_2b = false;
  
  if(Brain.SDcard.isInserted())
  {
    while(!applied)
    {
      if(Controller.ButtonA.pressing() || Controller.ButtonB.pressing() || Controller.ButtonX.pressing() || Controller.ButtonY.pressing() ||
      Controller.ButtonUp.pressing() || Controller.ButtonDown.pressing() || Controller.ButtonLeft.pressing() || Controller.ButtonRight.pressing() || 
      Controller.ButtonL1.pressing()  || Controller.ButtonL2.pressing()  || Controller.ButtonR1.pressing()  || Controller.ButtonR2.pressing() || 
      Controller.Axis3.value() < -threshold3 || Controller.Axis4.value() < -threshold4 || Controller.Axis3.value() > threshold3 || Controller.Axis4.value() > threshold4 ||
      Controller.Axis1.value() < -threshold1 || Controller.Axis2.value() < -threshold2 || Controller.Axis1.value() > threshold1|| Controller.Axis2.value() > threshold2 ||
      LCD.pressing())
      Task.sleep(250);
      else Task.sleep(15);

      if(Controller.ButtonL1.pressing() || Controller.ButtonL2.pressing() || Controller.ButtonLeft.pressing() || Controller.Axis1.value() < -threshold1 || Controller.Axis4.value() < -threshold4) currentButton--;
      if(Controller.ButtonR1.pressing() || Controller.ButtonR2.pressing() || Controller.ButtonRight.pressing() || Controller.Axis1.value() > threshold1 || Controller.Axis4.value() > threshold4) currentButton++;
      if(Controller.ButtonUp.pressing() || Controller.Axis3.value() > threshold3 || Controller.Axis2.value() > threshold2) currentButton -= btnNextRow;
      if(Controller.ButtonDown.pressing() || Controller.Axis3.value() < -threshold3 || Controller.Axis2.value() < -threshold2) currentButton += btnNextRow;

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

        if(mainButtons[4].state > 0)
        {
          mainButtons[4].state = 0;
          currentMenu = 1;
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

        if(Controller.ButtonA.pressing())
        {
          if(Controller.ButtonA.pressing() || Controller.ButtonY.pressing())
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
              if(backButtons2x2[currentButton - 1].state < 0) backButtons2x2[currentButton - 1].state = backButtons2x2[currentButton].size - 1;
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
      else if(currentMenu == 4) //controls menu
      {
        btnNextRow = 5;
        maxBtn = 6;

        s_button t_btn[7];
        for(int i = 0; i < 5; i++) t_btn[i] = joystickButtons[i];
        t_btn[5] = backButtons2x2[0];
        t_btn[6] = backButtons2x2[1];
        drawButtons(t_btn, 7);
      }
    }

    LCD.clearScreen();
    LCD.render();

    if(!Brain.SDcard.isInserted())
    {
      LCD.print("NO SD CARD");
      LCD.render();
      Controller.rumble("--------");
    }
    else
    {
      ofs.open("matchsettings.txt", ofs.out);
      ofs << mainButtons[0].state << "\n";
      ofs << mainButtons[1].state << "\n";
      ofs << mainButtons[2].state;
      ofs.close();

      ofs.open("keybinds.txt", ofs.out);
      ofs << IFTexts[fButtons[0].state].Index << "\n";
      ofs << IFTexts[fButtons[1].state].Index << "\n";
      ofs << IFTexts[fButtons[2].state].Index << "\n";
      ofs << IFTexts[fButtons[3].state].Index << "\n";
      ofs << IFTexts[fButtons[4].state].Index << "\n";
      ofs << IFTexts[fButtons[5].state].Index << "\n";
      ofs << IFTexts[fButtons[6].state].Index << "\n";
      ofs << IFTexts[fButtons[7].state].Index << "\n";
      ofs << IFTexts[fButtons[8].state].Index << "\n";
      ofs << IFTexts[fButtons[9].state].Index << "\n";
      ofs << IFTexts[fButtons[10].state].Index << "\n";
      ofs << IFTexts[fButtons[11].state].Index;
      ofs.close();

      LCD.print("Config files saved");
      LCD.render();
    }
  }
  if(!Brain.SDcard.isInserted())
  {
    LCD.print("NO SD CARD");
    LCD.render();
    Controller.rumble("--------"); 
  }
}