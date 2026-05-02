#include "Engine.h"


enum EBrick_Type
{
    EBT_None,
    EBT_Blue,
    EBT_Violet,
    EBT_Pink,
    EBT_Red,
    EBT_Orange,
    EBT_Yellow,
    EBT_Green
};
HPEN  Highlight_Pen, Pen_Brick, Platform_Circle_Pen, Platform_Inner_Pen;
HBRUSH Highlight_Brush, Brush_Brick, Platform_Circle_Brush, Platform_Inner_Brush;
const int Brick_Width = 45;
const int Brick_Height = 21;
const int Level_X_Offset = 24;
const int Level_Y_Offset = 18;
const int Circle_Size = 21;
const int Inner_Width = 63;

int Level_01[14][12] =
{
    0,0,0,0,0,0,0,0,0,0,0,0,
    1,1,1,1,1,1,1,1,1,1,1,1,
    2,2,2,2,2,2,2,2,2,2,2,2,
    3,3,3,3,3,3,3,3,3,3,3,3,
    4,4,4,4,4,4,4,4,4,4,4,4,
    5,5,5,5,5,5,5,5,5,5,5,5,
    6,6,6,6,6,6,6,6,6,6,6,6,
    7,7,7,7,7,7,7,7,7,7,7,7,
    1,1,1,1,1,1,1,1,1,1,1,1,
    0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,
};
//-------------------------------------------------------------------------------------
//ðèñóåò êèðïè÷è
void Create_Pen_Brush(unsigned char r, unsigned char g, unsigned char b,HPEN &pen,HBRUSH &brush )
{
    pen = CreatePen(PS_SOLID, 0, RGB(r, g, b));
    brush = CreateSolidBrush(RGB(r, g, b));
}
//-------------------------------------------------------------------------------------
//ÍÀÑÒÐÎÉÊÀ ÈÃÐÛ ÏÐÈ ÑÒÀÐÒÅ
void Init()
{
    Create_Pen_Brush(255, 255, 255, Highlight_Pen, Highlight_Brush);

    Create_Pen_Brush(180, 111, 240, Platform_Circle_Pen, Platform_Circle_Brush);
    Create_Pen_Brush(39, 146, 240, Platform_Inner_Pen, Platform_Inner_Brush);
}

//-------------------------------------------------------------------------------------
//ðèñóåò êèðïè÷è
void Draw_Brick(HDC hdc, EBrick_Type color, int x, int y)
{
    COLORREF circuit;
    COLORREF filling;
    switch (color)
    {
    case EBT_None: return;
    case EBT_Blue:
    {
        circuit = RGB(20, 106, 255);
        filling = RGB(64, 163, 255);
        break;

    }
    case EBT_Violet:
    {
        circuit = RGB(163, 23, 255);
        filling = RGB(200, 59, 251);
        break;
    }
    case EBT_Pink:
    {
        circuit = RGB(240, 28, 174);
        filling = RGB(255, 89, 188);
        break;
    }
    case EBT_Red:
    {
        circuit = RGB(235, 19, 24);
        filling = RGB(255, 42, 52);
        break;
    }
    case EBT_Orange:
    {
        circuit = RGB(255, 125, 1);
        filling = RGB(250, 145, 26);
        break;
    }
    case EBT_Yellow:
    {
        circuit = RGB(255, 198, 23);
        filling = RGB(255, 215, 60);
        break;
    }
    case EBT_Green:
    {
        circuit = RGB(0, 200, 0);
        filling = RGB(120, 255, 120);
        break;
    }
    default:
        return;
    }
    Pen_Brick = CreatePen(PS_SOLID, 0, circuit);
    Brush_Brick = CreateSolidBrush(filling);
    SelectObject(hdc, Pen_Brick);
    SelectObject(hdc, Brush_Brick);
    RoundRect(hdc, x + 2, y + 2, x + Brick_Width, y + Brick_Height, 6, 6);
}
//-------------------------------------------------------------------------------------
//ÎÒÐÈÑÎÂÊÀ ÓÐÎÂÍß
void Draw_Level(HDC hdc)
{
    for (int i = 0; i < 14; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            int x = Level_X_Offset + j * Brick_Width;
            int y = Level_Y_Offset + i * Brick_Height;

            Draw_Brick(hdc, (EBrick_Type)Level_01[i][j], x, y);
        }
    }




}
//-------------------------------------------------------------------------------------
//ÎÒÐÈÑÎÂÊÀ ÏËÀÒÔÎÐÌÛ
void Draw_Platform(HDC hdc)
{
    int x = 150, y = 300;
    //1. Ðèñóåì áîêîâûå øàðèêè
    SelectObject(hdc, Platform_Circle_Pen);
    SelectObject(hdc, Platform_Circle_Brush);

    Ellipse(hdc, x, y, x + Circle_Size, y + Circle_Size);
    Ellipse(hdc, x + Inner_Width, y, x + Circle_Size + Inner_Width, y + Circle_Size);

    //2. Ðèñóåì áëèê
    SelectObject(hdc, Highlight_Pen);
    Arc(hdc, x + 3, y + 3, x + Circle_Size - 3, y + Circle_Size - 3,
        x + 6, y + 3, x + 3, y + 6);
    RoundRect(hdc, x + 16, y + 3, x + 12 + Inner_Width - 3, y + 3 + 15, 9, 9);

    //3. Ðèñóåì ñðåäíþþ ÷àñòü
    SelectObject(hdc, Platform_Inner_Pen);
    SelectObject(hdc, Platform_Inner_Brush);

    RoundRect(hdc, x + 12, y + 3, x + 12 + Inner_Width - 3, y + 3 + 15, 9, 9);

    //4. Ðèñóåì áëèê
    SelectObject(hdc, Highlight_Brush);
    RoundRect(hdc, x + 16, y + 6, x + 12 + Inner_Width - 35, y + 6 + 3, 9, 9);
    RoundRect(hdc, x + 12 + Inner_Width - 32, y + 6, x + 12 + Inner_Width - 25, y + 6 + 3, 9, 9);
    RoundRect(hdc, x + 12 + Inner_Width - 22, y + 6, x + 12 + Inner_Width - 18, y + 6 + 3, 9, 9);
}
//-------------------------------------------------------------------------------------
//ÎÒÐÈÑÎÂÊÀ ÝÊÐÀÍÀ ÈÃÐÛ
void Draw_Frame(HDC hdc)
{
    Draw_Level(hdc);
    Draw_Platform(hdc);

   
}

//-------------------------------------------------------------------------------------