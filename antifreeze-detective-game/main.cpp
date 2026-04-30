#include <iostream>
#include <graphics.h>
#include <ctime>
#include <cstdlib>
#ifdef _WIN32
#include <windows.h>
#endif

// Управление без консольного окна.
// Старые коды клавиш оставлены такими же, как в исходном проекте:
// 72 — вверх, 80 — вниз, 75 — влево, 77 — вправо, 13 — Enter, 27 — Esc.
int gameGetch();
int gameKbhit();
#define getch gameGetch
#define kbhit gameKbhit
void meny();void kvadra(); int menuAction(); int waitEnterOrEsc(); void poyasnenie();void scena1();void scena2();void scena3();
void pol();void pol1();void komnata1();void Ste1(int x1,int y, int x, int y1);void Ste2(int x1,int y, int x, int y1);void Ste3(int x1,int y, int x, int y1);void Ste4(int x1,int y, int x, int y1);void da();int chess();//1 комната с управлением
void telephone();void mashina();
void polic(int x1,int y, int x, int y1);void polic1(int x1,int y, int x, int y1,int z);void polic2(int x1,int y, int x, int y1);//2 комната с управлением
void dver();void scena4();
void detect(int x1,int y,int x,int y1);void detect1(int x1,int y,int x,int y1,int z);void detect2(int x1,int y,int x,int y1);void ks();void pol2();//3 комната с управлением
void komnata2();void antif();void stakan();void al();//4 комната с управлением
void labir();void kryg(int x,int x1,int y,int y1,int color);void nadpis();void scena5();
void komnata3();void pol3();//5 комната с управлением
 void killer();
 int main()
{
#ifdef _WIN32
    // Убирает лишнее чёрное консольное окно, оставляя только графическое окно игры.
    FreeConsole();
#endif

    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode, "");
    std::atexit(closegraph);

    int y0=0,x0=0;
    meny();//рисовка меню
    //реакция на действия игрока
    int x=0,y=0;//следят за координатами при перемещении
    int n=0; //следит за координатами при нажатии
    while(1){
    delay(50);
    if(ismouseclick(WM_MOUSEMOVE)){
            delay(50);
        getmouseclick(WM_MOUSEMOVE,x,y);
        if (x>=279 && x<=529 && y>=233 &&y <=288){ setfillstyle(9,3); bar(279,233,529,288); settextstyle(0,0,2); outtextxy(312,251,"Начать игру");}
        else {setfillstyle(9,15); bar(279,233,529,288);settextstyle(0,0,2); outtextxy(312,251,"Начать игру");}
        if(x>=279 && x<=529 && y>=344 && y<=400) {setfillstyle(9,3);bar(279,344,529,400);outtextxy(362,361,"Выход");}
        else {setfillstyle(9,15);bar(279,344,529,400);outtextxy(362,361,"Выход");}
    }
    n=menuAction();//отслеживает хочет ли выйти игрок или нет
    if (n==3) return 0;
    if(n==1)  break;
    }

    //пояснение для игрока
    poyasnenie();
    if (waitEnterOrEsc()==3) return 0;
    //вступление
    cleardevice();kvadra();
    outtextxy(155,186,"Дэвид Кастор будет страдать в течение нескольких дней");outtextxy(155,206,"совершенно один. Неужели он сам обрек себя на страдание?");
    outtextxy(155,226,"Но его долгая и мучительная смерть откроет правду на"); outtextxy(155,246,"страшное предательство по отношению к нескольким людям.");
    outtextxy(155,266,"Коктейль, несущий смерть срабатывал много раз...");
    if (waitEnterOrEsc()==3) return 0;//данная команда реагирует на нажатие пользователем кнопок

    //рисовка первой сцены
    scena1();
    if (waitEnterOrEsc()==3) return 0;

    //рисовка второй сцены
    scena2();
    if (waitEnterOrEsc()==3) return 0;

    //рисовка третьей сцены
    scena3();
    if (waitEnterOrEsc()==3) return 0;

    //объяснение управления
    cleardevice();settextstyle(0,0,3); kvadra();
    outtextxy(308,72,"Пояснение");settextstyle(0,0,1); setcolor(15);
    outtextxy(100,186,"Чтобы передвигаться, используйте клавиши со стрелками. Чтобы выполнить\n");outtextxy(120,208,"действие подойдите к нему и нажмите Enter, если высветится окно,\n");
    outtextxy(140,230," чтобы продолжить выберите ответ стрелками направленными\n");outtextxy(140,252,"вправо и влево. Диалоги перелистывать с кнопки Enter.\n");
    if (waitEnterOrEsc()==3) return 0;


    //1 комната с управлением
    x=0; int x1=0; y=0; int y1=0,k2=0,k3=0,k4,k6=0,f=0;
    komnata1();Ste1(x1,y,x,y1);
    setfillstyle(1,7); setcolor(15);settextstyle(0,0,1);
    bar(154,480,628,538);outtextxy(160,495,"Поздно вечером мы с мужем поругались. Он закрылся");outtextxy(155,515,"в нашей спальне, я спала в зале. На него не похоже.");outtextxy(154,460,"???");
    if (waitEnterOrEsc()==3) return 0;pol1();
    while(1){
        k3=0;
        k4=0;//отслеживает нажатие клавиш
        int k=getch();
        switch(k)
        {case 80:{ //если вниз то мы складываем координату
            if(355+x-y1<535){pol();x+=5;Ste1(x1,y,x,y1);}break;}
        case 77:{ //если вправо то мы складываем координату
            if(425+x1-y<625){pol();x1+=5;Ste2(x1,y,x,y1);}break;}
        case 75:{//если вверх то мы вычитаем координату
             if(383+x1-y>158){pol();y+=5;Ste3(x1,y,x,y1);}break;}
        case(72):{//если влево то мы вычитаем координату
            if(285+x-y1>268){pol();y1+=5;Ste4(x1,y,x,y1);}break;}
        case(27):return 0;;
        case (13):{
            //если игрок выбрал шашки
            if (285+x-y1>=265 && 285+x-y1<=300 && 416+x1-y<=232){
               da();setfillstyle(1,3); bar(195,505,255,535);outtextxy(210,510,"Да");
               while(1){k2=getch();
               switch(k2)
                {case(75):{if (k3==0){da();setfillstyle(1,3); bar(300,505,365,535); outtextxy(310,510,"Нет"); k3=1;}//отслеживание да и нет в поле выбора
                        else if (k3==1){da();setfillstyle(1,3); bar(195,505,255,535);outtextxy(210,510,"Да"); k3=0;}break;}
                case(77):{if (k3==0){da();setfillstyle(1,3); bar(300,505,365,535); outtextxy(310,510,"Нет"); k3=1;}
                        else if (k3==1){da();setfillstyle(1,3); bar(195,505,255,535);outtextxy(210,510,"Да"); k3=0;}break;}
                case(13):{if (k3==0) {while(1){if (chess()==3) break;} k4=4; cleardevice();komnata1();Ste1(x1,y,x,y1);}
                    if (k3==1) {k4=4;pol1();}break;}
                case(27): return 0;
                    }if (k4==4) break;}}
            //если игрок выбрал комнату детей
            if(425+x1-y<=628 && 425+x1-y>=580 && 332+x-y1>=347 && 332+x-y1<=444  ) { setfillstyle(1,7); bar(154,480,628,538);setcolor(15);
            settextstyle(0,0,1);outtextxy(170,495,"Это комната наших детей, не хочу их беспокоить");outtextxy(154,460,"???");if (waitEnterOrEsc()==3) return 0;pol1();}
            //если игрок выбрал телефон без выбора главной двери
            if (285+x-y1>=265 && 285+x-y1<=300 && 416+x1-y<=628 && 416+x1-y>=550 && f==0) { setfillstyle(1,7); bar(154,480,628,538);setcolor(15);
            settextstyle(0,0,1);outtextxy(180,495,"Я не хочу сейчас кому-то звонить");outtextxy(154,460,"???");if (waitEnterOrEsc()==3) return 0;pol1();}
            //если игрок выбрал главную дверь
            if (285+x-y1>=265 && 285+x-y1<=300 && 416+x1-y<=375 && 416+x1-y>=315) {f=1; setfillstyle(1,7); bar(154,480,628,538);setcolor(15);
            settextstyle(0,0,1);outtextxy(180,495,"Эй, открой! Я начинаю волноваться...");outtextxy(180,515,"Все хорошо? (Надо позвонить в полицию.)");outtextxy(154,460,"???");if (waitEnterOrEsc()==3) return 0;pol1();}
            //если игрок выбрал телефон с выбором главной двери
            if (285+x-y1>=265 && 285+x-y1<=300 && 416+x1-y<=628 && 416+x1-y>=550 && f==1) { k6=4;setfillstyle(1,7); bar(154,480,628,538);setcolor(15);
            settextstyle(0,0,1);outtextxy(180,495,"Волнуюсь, на клавиши не попадаю");outtextxy(154,460,"???");if (waitEnterOrEsc()==3) return 0;pol1();}
            break;}} if (k6==4)break;}cleardevice();

    //мини-игра с телефоном
    //рисунок телефона
    telephone();
    //реализация игры
    x1=0;y1=0;int z1;int k=0, k1=0;
    srand(static_cast<unsigned int>(time(NULL)));
    do{k=getch();} while(k!=27 &&k!=13);if (k==27) return 0;
  switch(k){
      case(13):{
            while (k!=27 && k==13){
            settextstyle(0,0,2);
        switch(x1=rand()%3){
            case 0: outtextxy(216,233,"1"); x1=1; break;//решает какая выпадет первая цифра
            case 1: outtextxy(216,233,"2"); x1=2; break;
            case 2: outtextxy(216,233,"0"); x1=0;break;
      }
      switch(y1=rand()%3){
        case 0: outtextxy(256,233,"1");y1=1; break;//решает какая выпадет вторая цифра
        case 1: outtextxy(256,233,"0");y1=0; break;
        case 2: outtextxy(256,233,"2");y1=2; break;}
      switch(z1=rand()%3){
        case 0: outtextxy(296,233,"0"); z1=0; break;//решает какая выпадет третья цифра
        case 1: outtextxy(296,233,"1"); z1=1;break;
        case 2: outtextxy(296,233,"2"); z1=2;break;}
    settextstyle(0,0,1);
    if (x1==1 && y1==0 && z1==2){settextstyle(0,0,3);
        outtextxy(430,220,"        ");outtextxy(430,230,"Победа");
        k1=1;k=getch();break;}
    else{outtextxy(430,220,"Попробуй снова");}
    k=getch();}
  while (k!=13 && k!=27) k=getch();//определяет по нажатой кнопке, что выполнить
  if (k==27) return 0;
  if (k==13) break;}
  case(27): {return 0;}}

  //анимация машины
  mashina();
  if (waitEnterOrEsc()==3) return 0;


  //комната 2 с управлением
    x=0; x1=0;y=0;y1=0;k4=0;k6=0; f=0; int f1=0;
    cleardevice();komnata1();Ste1(x1,135,x,90);pol();polic(x1,y,x,y1);
    setfillstyle(1,7); bar(154,480,628,538);setcolor(15);settextstyle(0,0,1);outtextxy(160,495,"Мне надо поговорить с потерпевшей");outtextxy(154,460,"Полицейский");
    if (waitEnterOrEsc()==3) return 0;pol1();
    while(1){
        k4=0;//отслеживает нажатие клавиш
        int k=getch();
        switch(k)
        {
        case 80:{//если вниз то мы складываем координату
            if(425+x-y1<535){pol();x+=5;polic(x1,y,x,y1);}break;}
         case 77:{//если вправо то мы складываем координату
            if(370+x1-y<625){pol();x1+=5;polic1(x1,y,x,y1,0);}break;}
        case 75:{//если влево то мы вычитаем координату
            if(336+x1-y>158){pol();y+=5; polic1(x1,y,x,y1,-25);}break;}
        case(72):{//если вверх то мы вычитаем координату
            if(355+x-y1>268){pol();y1+=5;polic2(x1,y,x,y1);}break;}
        case(27):{return 0;}
        case(13):{
        //если игрок выбрал шашки
        if (355+x-y1>=265 && 355+x-y1<=300 && 369+x1-y<=232){
            setfillstyle(1,7); bar(154,480,628,538);setcolor(15);
            settextstyle(0,0,1);outtextxy(170,495,"Нет времени играть в шашки");outtextxy(154,460,"Полицейский");if (waitEnterOrEsc()==3) return 0;pol1();}
        //если игрок выбрал телефон
        if (355+x-y1>=265 && 355+x-y1<=300 && 369+x1-y<=628 && 336+x1-y>=550) { setfillstyle(1,7); bar(154,480,628,538);setcolor(15);
            settextstyle(0,0,1);outtextxy(180,495,"Мне некому сейчас звонить");outtextxy(154,460,"Полицейский");if (waitEnterOrEsc()==3) return 0;pol1();}
        //если игрок выбрал комнату детей
        if(369+x1-y<=628 && 336+x1-y>=580 && 355+x-y1>=347 && 355+x-y1<=444  ) { setfillstyle(1,7); bar(154,480,628,538);setcolor(15);
            settextstyle(0,0,1);outtextxy(170,495,"Потерпевшая находится в этой комнате");outtextxy(154,460,"Полицейский");if (waitEnterOrEsc()==3) return 0;pol1();}
        //если игрок выбрал главную дверь после того как поговорил со Стэйси
        if (355+x-y1>=265 && 355+x-y1<=300 && 369+x1-y<=375 && 336+x1-y>=315 && f==1) {k6=4;setfillstyle(1,7); bar(154,480,628,538);setcolor(15);
            settextstyle(0,0,1);outtextxy(165,495,"Если вы сейчас не откроете, я вынужден выбить дверь");outtextxy(154,460,"Полицейский");if (waitEnterOrEsc()==3) return 0;pol1();}
        //если игрок выбрал поговорить со Стэйси
        if (355+x-y1>=265 && 355+x-y1<=300 && 336+x1-y>=232 && 369+x1-y<=315&& f1==0) {f1=1;setfillstyle(1,7); bar(154,480,628,538);setcolor(15);
            settextstyle(0,0,1);outtextxy(157,495,"Добрый день, представьтесь и скажите, что случилось.");outtextxy(154,460,"Полицейский");if (waitEnterOrEsc()==3) return 0;pol1();}
        if (355+x-y1>=265 && 355+x-y1<=300 && 336+x1-y>=232 && 369+x1-y<=315&& f1==1) {f1=2;setfillstyle(1,7); bar(154,470,628,538);setcolor(15);
            settextstyle(0,0,1);outtextxy(180,473,"Здравствуйте, меня зовут Стэйси Кастор.");outtextxy(160,493,"Вчера я повздорила с мужем и он закрылся в нашей");outtextxy(180,513,"комнате. Сейчас он молчит и не открывает");
            outtextxy(154,450,"Стэйси Кастор");if (waitEnterOrEsc()==3) return 0;pol1();outtextxy(154,450,"                     ");}}
        if (355+x-y1>=265 && 355+x-y1<=300 && 336+x1-y>=232 && 369+x1-y<=315&& f1==2) {f=1;setfillstyle(1,7); bar(154,480,628,540);setcolor(15);
            settextstyle(0,0,1);outtextxy(180,483,"Хорошо, сейчас разберусь"); outtextxy(154,460,"Полицейский");if (waitEnterOrEsc()==3) return 0;pol1();}break;}
        if (k6==4)break;}


    //мини-игра с дверью
    x=0,y=0,x1=0,y1=0,k1=0; k2=1,k3=0,k4=1;    cleardevice();
    dver();//рисовка двери
    if (kbhit()) {k3=getch(); if (k3==27) return 0;};
    x1=rand()%160+120;
    y1=rand()%360+120;
    bar(x1,y1,x1+20,y1+20);
    while (k1!=10 && k4){
        if (kbhit()) {k3=getch(); if (k3==27)return 0;};
            delay(50);
        if (ismouseclick(WM_LBUTTONDOWN)) getmouseclick(WM_LBUTTONDOWN,x,y);
          if (x<=x1+20 && x>=x1 && y<=y1+20 && y>=y1){
                setfillstyle(1, 0);bar(101,101,299,499);
                x1=rand()%160+120;y1=rand()%360+120;k1+=1;
                if (k1==1) outtextxy(500,220,"9    раз   ");
                if (k1==2) outtextxy(500,220,"8    раз   ");
                if (k1==3) outtextxy(500,220,"7    раз   ");
                if (k1==4) outtextxy(500,220,"6    раз   ");
                if (k1==5) outtextxy(500,220,"5    раз   ");
                if (k1==6) outtextxy(500,220,"4    раз   ");
                if (k1==7) outtextxy(500,220,"3    раз   ");
                if (k1==8) outtextxy(500,220,"2    раз   ");
                if (k1==9) outtextxy(500,220,"1    раз   ");
                if (k1==10) outtextxy(500,220,"0    раз   ");
                setfillstyle(1, 4);bar(x1,y1,x1+20,y1+20);}
    }setfillstyle(1, 7);bar(101,101,299,499);
    if (waitEnterOrEsc()==3) return 0;

    //рисовка четвертой сцены
    scena4();
    if (waitEnterOrEsc()==3) return 0;

    //диалог
    cleardevice();kvadra();
    outtextxy(227,77,"Стэйси Кастор (С)   Полицейский(П)");
    if (waitEnterOrEsc()==3) return 0;
    outtextxy(83,147,"С - АААААА, ЧТО С НИМ? ПОЧЕМУ ОН НЕ ДВИГАЕТСЯ");
    if (waitEnterOrEsc()==3) return 0;
    outtextxy(83,177,"П - у него нет пульса, сожалею...");
    if (waitEnterOrEsc()==3) return 0;
    outtextxy(83,207,"С - КАК ТАК, ТОЛЬКО ВЧЕРА ОН БЫЛ ЖИВОЙ, ТАКОЕ НЕ МОГЛО ПРОИЗОЙТИ!");
    if (waitEnterOrEsc()==3) return 0;
    outtextxy(83,237,"П - девушка, прошу вас, успокойтесь");
    if (waitEnterOrEsc()==3) return 0;
    outtextxy(83,267,"С - КАК Я МОГУ УСПОКОИТЬСЯ??? У НАС ДЕТИ!");
    if (waitEnterOrEsc()==3) return 0;
    outtextxy(83,297,"П - ...");
    if (waitEnterOrEsc()==3) return 0;

     x=0; x1=0; y=0;y1=0;k2=0;k3=0;k4=0;k6=0;f=0;f1=0; int FLAG=0;//3 комната с управлением
    komnata1();Ste1(0,135,0,90);pol();detect(x1,y,x,y1);
    setfillstyle(1,7); bar(154,480,628,538);setcolor(15);settextstyle(0,0,1);outtextxy(160,495,"Мне надо поговорить со Стэйси Кастор и");outtextxy(160,515,"осмотреть место смерти Дэвида Кастора");outtextxy(154,460,"Детектив");
   if (waitEnterOrEsc()==3) return 0;pol1();
    while(1){
        k3=0;
        k4=0;//отслеживает нажатие клавиш
        int k=getch();
        switch(k)
        {
        case 80:{//если вниз то мы складываем координату
            if(430+x-y1<535){pol();x+=5;detect(x1,y,x,y1);}break;}
         case 77:{
            if(370+x1-y<625){//если вправо то мы складываем координату
            pol();x1+=5;detect1(x1,y,x,y1,0);}break;}
        case 75:{//если влево то мы вычитаем координату
            if(336+x1-y>158){pol();y+=5;detect1(x1,y,x,y1,10);}break;}
        case(72):{//если вверх то мы вычитаем координату
            if(355+x-y1>268){pol();y1+=5;detect2(x1,y,x,y1);}break;}
        case(27):{return 0;}
        case(13):{
            //если игрок выбрал шашки
            if (355+x-y1>=265 && 344+x-y1<=300 && 369+x1-y<=232){
               da();setfillstyle(1,3); bar(195,505,255,535);outtextxy(210,510,"Да");
               while(1){k2=getch();
               switch(k2)
                {case(75):{if (k3==0){da();setfillstyle(1,3); bar(300,505,365,535); outtextxy(310,510,"Нет"); k3=1;}//отслеживание да и нет в поле выбора
                        else if (k3==1){da();setfillstyle(1,3); bar(195,505,255,535);outtextxy(210,510,"Да"); k3=0;}break;}
                case(77):{if (k3==0){da();setfillstyle(1,3); bar(300,505,365,535); outtextxy(310,510,"Нет"); k3=1;}
                        else if (k3==1){da();setfillstyle(1,3); bar(195,505,255,535);outtextxy(210,510,"Да"); k3=0;}break;}
                case(13):{if (k3==0) {while(1){if (chess()==3) break;} k4=4; cleardevice();komnata1();detect(x1,y,x,y1);Ste1(0,135,0,90);}
                    if (k3==1) {k4=4;pol1();}break;}
                case(27): return 0;
                    }if (k4==4) break;}}
        //рисунок кухонной спринцовки и если игрок выбрал телефон
        if (355+x-y1>=265 && 355+x-y1<=300 && 369+x1-y<=628 && 336+x1-y>=550)  {FLAG=1;cleardevice();kvadra();ks();settextstyle(0,0,2);outtextxy(266,62,"Вы нашли:");
            settextstyle(0,0,1);outtextxy(256,495,"Что тут делает кухонная спринцовка?");if (waitEnterOrEsc()==3) return 0;pol1();komnata1();Ste1(0,135,0,90);pol();detect(x1,y,x,y1);}
        //если игрок выбрал комнату детей
        if(369+x1-y<=628 && 336+x1-y>=580 && 355+x-y1>=347 && 355+x-y1<=444  ) { setfillstyle(1,7); bar(154,480,628,538);setcolor(15);
            settextstyle(0,0,1);outtextxy(170,495,"Я уже осмотрел эту комнату");outtextxy(154,460,"Детектив");if (waitEnterOrEsc()==3) return 0;pol1();}
        //если игрок выбрал поговорить со Стэйси,диалог Детектива
        if (355+x-y1>=265 && 355+x-y1<=300 && 336+x1-y>=232 && 369+x1-y<=315&& f1==0) {f1=1;setfillstyle(1,7); bar(154,480,628,538);setcolor(15);
            settextstyle(0,0,1);outtextxy(157,495,"Добрый день, я расследую дело вашего мужа");outtextxy(160,513,"Мне нужно осмотреть комнату");outtextxy(154,460,"Детектив");if (waitEnterOrEsc()==3) return 0;pol1();}
        //если игрок выбрал поговорить со Стэйси, диалог Стэйси
        if (355+x-y1>=265 && 355+x-y1<=300 && 336+x1-y>=232 && 369+x1-y<=315&& f1==1) {setfillstyle(1,7); bar(154,470,628,538);setcolor(15);
            settextstyle(0,0,1);outtextxy(180,473,"Да, конечно проходите"); outtextxy(154,450,"Стэйси Кастор");if (waitEnterOrEsc()==3) return 0;pol1();outtextxy(154,450,"                     ");}
        //если игрок выбрал главную дверь после того как поговорил со Стэйси
        if (355+x-y1>=265 && 355+x-y1<=300 && 369+x1-y<=375 && 336+x1-y>=315 && f1==1) {k6=4;setfillstyle(1,7); bar(154,480,628,538);setcolor(15);
            settextstyle(0,0,1);outtextxy(180,495,"Так так так");outtextxy(154,460,"Детектив");if (waitEnterOrEsc()==3) return 0;}break;}}
        if (k6==4)break;}


    x=0; x1=0; y=0; y1=0;k4=0; k6=0,f1=0;
    int f2=0,f3=0,f4=0,f5=0; //4 комната с управлением
    komnata2();pol2();kvadra();detect(x1,y,x,y1);
    while(1){
        k4=0;//отслеживает нажатие клавиш
        int k=getch();
        switch(k)
        {
        case 80:{//если вниз то мы складываем координату
            if(435+x-y1<528){pol2();x+=5;detect(x1,y,x,y1);}break;}
         case 77:{//если вправо то мы складываем координату
            if((374+x1-y<740&& 355+x-y1>235 && 355+x-y1<=335)||(374+x1-y<740&& 355+x-y1>=335&& 355+x-y1<=382)||(374+x1-y<740&&355+x-y1<531 && 355+x-y1>=382)){
            pol2(); x1+=5; detect1(x1,y,x,y1,0);} break;}
        case 75:{//если влево то мы вычитаем координату
            if((335+x1-y>380 && 355+x-y1>235 && 355+x-y1<=335 )||(335+x1-y>176 && 355+x-y1>=335&& 355+x-y1<=382)||(336+x1-y>105 && 355+x-y1<531 && 355+x-y1>=382) ){
            pol2(); y+=5; detect1(x1,y,x,y1,10);} break;}
        case(72):{//если вверх то мы вычитаем координату
            if ((335+x1-y>376 && 355+x-y1>240 && 355+x-y1<=336 )||(335+x1-y>172 && 355+x-y1>336 && 355+x-y1<=386)||(336+x1-y>98 && 355+x-y1<531 && 355+x-y1>=386) ){
            pol2();y1+=5;detect2(x1,y,x,y1);}break;}
        case(27):{return 0;}
        case(13):{
        //если игрок выбрал дверь
        if (374+x1-y<746 && 335+x1-y>=646 && 355+x-y1>233 && 355+x-y1<257){
           setfillstyle(1,7); bar(154,478,628,532);setcolor(15);
            settextstyle(0,0,1);outtextxy(170,495,"Я только оттуда вошел");outtextxy(154,460,"Детектив");if (waitEnterOrEsc()==3) return 0;setfillstyle(1,0);bar(154,460,628,532);}
        //если игрок выбрал шкаф
        if (374+x1-y<646 && 335+x1-y>446 && 355+x-y1>233 && 355+x-y1<257) { setfillstyle(1,7); bar(154,480,628,532);setcolor(15);
            if (f2==0)k6+=1; f2+=1;settextstyle(0,0,1);outtextxy(180,495,"В этом шкафу нет улик");outtextxy(154,460,"Детектив");if (waitEnterOrEsc()==3) return 0;setfillstyle(1,0);bar(154,460,628,532);}
        //если игрок выбрал кровать и рисовка антифриза
        if( 374+x1-y<421 && 335+x1-y>371 && 355+x-y1>233 && 355+x-y1<332) { if (f3==0)k6+=1; f3+=1;cleardevice();kvadra();antif();settextstyle(0,0,2);outtextxy(266,62,"Вы нашли:");
            settextstyle(0,0,1);outtextxy(256,495,"Странно, что он здесь делает?");if (waitEnterOrEsc()==3) return 0; komnata2();pol2();kvadra();detect(x1,y,x,y1);}
        //если игрок выбрал стакан и рисовка стакана
        if (374+x1-y<346 && 335+x1-y>246 && 355+x-y1>332 && 355+x-y1<382) {if (f4==0)k6+=1; f4+=1;cleardevice();kvadra();setcolor(15);settextstyle(0,0,2);outtextxy(266,62,"Вы нашли:");
        settextstyle(0,0,1);outtextxy(221,495,"Стакан? Но на шкафу тоже есть стакан...");stakan();if (waitEnterOrEsc()==3) return 0; komnata2();pol2();kvadra();detect(x1,y,x,y1);}
        //если игрок выбрал столешницу и рисовка стакана с алкоголем
        if (374+x1-y<221 && 335+x1-y>121 && 355+x-y1>233 && 355+x-y1<432) {cleardevice();kvadra();if (f5==0)k6+=1; f5+=1;settextstyle(0,0,2);outtextxy(266,62,"Вы нашли:");
        settextstyle(0,0,1);outtextxy(246,495,"Пострадавший был в нетрезвом состоянии"); al();if (waitEnterOrEsc()==3) return 0;komnata2();pol2();kvadra();detect(x1,y,x,y1);}break;}}
        if (k6==4)break;}

    komnata2();pol2();kvadra();detect(x1,y,x,y1);
    setfillstyle(1,7); bar(154,478,628,532);setcolor(15);
    settextstyle(0,0,1);outtextxy(170,495,"Я осмотрел место преступления и");outtextxy(170,515,"отправлю некоторые вещи на экспертизу");outtextxy(154,460,"Детектив");if (waitEnterOrEsc()==3) return 0;
    cleardevice();

    //мини-игра лабиринт
    labir();//рисовка лабиринта
    //сама игра
    y=0;y1=0;x=0;x1=0;
    setcolor(0);
    while(1){
        k=getch();
        switch(k){
            case 80:{if (getpixel(400+x-x1,360+y-y1+20+7)!=8){kryg(x,x1,y,y1,0);y+=20;kryg(x,x1,y,y1,7);}break;}
            case 72:{if (getpixel(400+x-x1,360-y1+y-20-7)!=8){kryg(x,x1,y,y1,0);y1+=20;kryg(x,x1,y,y1,7);}break;}
            case 77:{if (getpixel(400+x-x1+20+7,360-y1+y)!=8){kryg(x,x1,y,y1,0);x+=20;kryg(x,x1,y,y1,7);}break;}
            case 75:{if (getpixel(400+x-x1-20-7,360-y1+y)!=8){kryg(x,x1,y,y1,0);x1+=20;kryg(x,x1,y,y1,7);}break;}
            case 27: return 0;
            case 13: {if (400+x-x1==300 && 360-y1+y==40) k1=0;break;}}
         if (k1==0)break;}


    //мини-игра с антифризом
    //co стаканом
    cleardevice(); kvadra();
    x=0;x1=0;k1=0;k2=0;k3=0;k4=0;int k5=0;k6=0;y1=0;y=0;
    if (kbhit()) {k3=getch(); if (k3==27) return 0;};
    nadpis();//правила
    stakan();//рисовка стакана
   setfillstyle(9,3); bar(146,157,156,167); bar(346,257,366,277); bar(221,282,231,292); bar(596,207,606,217); bar(396,357,416,377); bar(346,126,356,136);
     while(1){
            if (kbhit()) {k3=getch(); if (k3==27) return 0;};
    delay(50);
    if(ismouseclick(WM_MOUSEMOVE)){
            delay(50);
        getmouseclick(WM_MOUSEMOVE,x,y);
        if (ismouseclick(WM_LBUTTONDOWN)) getmouseclick(WM_LBUTTONDOWN,x1,y1);
        if(x>=229 && x<=489 && y>=434 && y<=490) {setfillstyle(9,3);bar(229,434,489,490);outtextxy(332,455,"Готово");}
        else {setfillstyle(9,15);bar(229,434,489,490);outtextxy(332,455,"Готово");}
        if(x1>146 && x1<156 && y1>157 &&y1<167) {setfillstyle(9,15);bar(146,157,156,167);k1=1;}
        if(x1>346 && x1<366 && y1>257 &&y1<277) {setfillstyle(9,15);bar(346,257,366,277);k2=1;}
        if(x1>221 && x1<231 && y1>282 &&y1<292) {setfillstyle(9,15);bar(221,282,231,292);k3=1;}
        if(x1>596 && x1<606 && y1>207 &&y1<227) {setfillstyle(9,15);bar(596,207,606,217);k4=1;}
        if(x1>396 && x1<416 && y1>357 &&y1<377) {setfillstyle(9,15);bar(396,357,416,377);k5=1;}
        if(x1>346 && x1<356 && y1>126 &&y1<136) {setfillstyle(9,15);bar(346,126,356,136);k6=1;}
        if(x1>=229 && x1<=489 && y1>=434 && y1<=490 && (k1&&k2&&k3&&k4&&k5&&k6)) break;}}
    //с алкоголем и co стаканом
    cleardevice(); x1=0;kvadra();
    nadpis();//правила
    al();//рисовка алкоголя со стаканом
    while(1){
    delay(50);
    if(ismouseclick(WM_MOUSEMOVE)){
            if (kbhit()) {k3=getch(); if (k3==27) return 0;};
            delay(50);
        getmouseclick(WM_MOUSEMOVE,x,y);
        if (ismouseclick(WM_LBUTTONDOWN)) getmouseclick(WM_LBUTTONDOWN,x1,y1);
        if(x>=229 && x<=489 && y>=434 && y<=490) {setfillstyle(9,3);bar(229,434,489,490);outtextxy(332,455,"Готово");}
        else {setfillstyle(9,15);bar(229,434,489,490);outtextxy(332,455,"Готово");}
        if(x1>=229 && x1<=489 && y1>=434 && y1<=490) break;}}
    // если игрок нашел кухонную спринцовку, то с ней
    if (FLAG==1){
            cleardevice(); kvadra();
         x=0;x1=0;k1=0;k2=0;k3=0;k4=0;k5=0;k6=0;y1=0;y=0;
          nadpis();//правила
          ks();//Кухонная спринцовка
         setfillstyle(9,3);bar(246,357,256,367); bar(146,257,166,277); bar(221,382,231,392); bar(596,207,606,217); bar(291,182,311,202); bar(346,126,356,136);
         if (kbhit()) {k3=getch(); if (k3==27) return 0;};
     while(1){
    delay(50);
    if(ismouseclick(WM_MOUSEMOVE)){
            delay(50);
            if (kbhit()) {k3=getch(); if (k3==27) return 0;};
        getmouseclick(WM_MOUSEMOVE,x,y);
        if (ismouseclick(WM_LBUTTONDOWN)) getmouseclick(WM_LBUTTONDOWN,x1,y1);
        if(x>=229 && x<=489 && y>=434 && y<=490) {setfillstyle(9,3);bar(229,434,489,490);outtextxy(332,455,"Готово");}
        else {setfillstyle(9,15);bar(229,434,489,490);outtextxy(332,455,"Готово");}
        if (x1>246 && x1<256 && y1>357 && y1<367){setfillstyle(9,15);bar(246,357,256,367);k1=1;}
        if (x1>146 && x1<166 && y1>257 && y1<277){setfillstyle(9,15);bar(146,257,166,277);k2=1;}
        if (x1>221 && x1<231 && y1>382 && y1<392){setfillstyle(9,15);bar(221,382,231,392);k3=1;}
        if (x1>596 && x1<606 && y1>207 && y1<217){setfillstyle(9,15);bar(596,207,606,217);k4=1;}
        if (x1>291 && x1<311 && y1>182 && y1<202){setfillstyle(9,15); bar(291,182,311,202);k5=1;}
        if (x1>346 && x1<356 && y1>126 && y1<136){setfillstyle(9,15);bar(346,126,356,136);k6=1;}
        if(x1>=229 && x1<=489 && y1>=434 && y1<=490 && (k1&&k2&&k3&&k4&&k5&&k6)) break;}}}

    //пятая сцена
    scena5();
     if (waitEnterOrEsc()==3) return 0;

     //диалог
    cleardevice();kvadra(); x=0;
    outtextxy(227,77,"Абонент (А)   Детектив(П)");
    if (waitEnterOrEsc()==3) return 0;
    outtextxy(83,147,"Д - Какое запутанное дело...");
    if (waitEnterOrEsc()==3) return 0;
    outtextxy(83,177,"Д - Почему один стакан с антифризом, другой нет");
    if (waitEnterOrEsc()==3) return 0;
    outtextxy(83,207,"Д - И почему у стакана, который стоял рядом с алкоголем,");
    outtextxy(83,237,"не было никаких отпечатков пострадавшего");
    if (waitEnterOrEsc()==3) return 0;
    if (FLAG==1) {x=60;
    outtextxy(83,267,"Д - Скорее всего это кто-то из членов семьи,");
     outtextxy(83,297,"опираясь на найденную кухонную спринцовку.");
    if (waitEnterOrEsc()==3) return 0;}
    outtextxy(83,267+x,"*Звонок*");
    if (waitEnterOrEsc()==3) return 0;
    outtextxy(83,297+x,"А - Здравствуйте, тороплюсь сообщить, одна из подозреваемых попала в больницу");
    if (waitEnterOrEsc()==3) return 0;
    outtextxy(83,327+x,"А - Это Эшли Уоллес, дочь Стэйси Кастор");
     if (waitEnterOrEsc()==3) return 0;
    outtextxy(83,357+x,"А - Следует еще раз обыскать ее комнату");
     if (waitEnterOrEsc()==3) return 0;
     outtextxy(83,387+x,"Д -Я выдвигаюсь");
      if (waitEnterOrEsc()==3) return 0;

    cleardevice();
    x=0; x1=0; y=0; y1=0; k2=0; k3=0; k4=0; k6=0,f1=0;f2=0;//5 комната с управлением
    komnata3();pol3();kvadra();detect(x1,y,x,y1);
    while(1){
        k4=0;//отслеживает нажатие клавиш
        int k=getch();
        switch(k)
        {
        case 80:{//если вниз то мы складываем координату
            if(435+x-y1<531){pol3();x+=5;detect(x1,y,x,y1);}break;}
         case 77:{//если вправо то мы складываем координату
            if(374+x1-y<615){pol3();x1+=5;detect1(x1,y,x,y1,0);}break;}
        case 75:{//если влево то мы вычитаем координату
            if(335+x1-y>125){pol3();y+=5;detect1(x1,y,x,y1,10);}break;}
        case(72):{//если вверх то мы вычитаем координату
            if (355+x-y1>300){pol3();y1+=5;detect2(x1,y,x,y1);}break;}
        case(27):{return 0;}
        case(13):{
        //если игрок выбрал компьютер
        if (374+x1-y<446 && 335+x1-y>271 && 355+x-y1>282 && 355+x-y1<332){
           setfillstyle(1,7); bar(154,478,628,532);setcolor(15);
            settextstyle(0,0,1);outtextxy(170,495,"В компьютере ничего интересного");outtextxy(154,460,"Детектив");if (waitEnterOrEsc()==3) return 0;setfillstyle(1,0);bar(154,460,628,532);}
        //если игрок выбрал столешницу с таблетками и рисовка таблеток
        if (374+x1-y<271 && 335+x1-y>171 && 355+x-y1>282 && 355+x-y1<332) { if (f1==0)k6+=1; f1+=1;cleardevice();kvadra(); setcolor(15);y0=0;x0=0;line(146,182,496,182); line(496,182,596,307); line(596,307,221,307);
        line(221,307,146,182);for ( int i=0;i<2;i++){for (int j=0;j<5;j++){circle(221+y0,207+x0,20);y0+=60;}y0=50;x0+=75;}settextstyle(0,0,2);outtextxy(266,62,"Вы нашли:");
            settextstyle(0,0,1);outtextxy(310,400,"Таблетки?");if (waitEnterOrEsc()==3) return 0;cleardevice();komnata3();pol3();kvadra();detect(x1,y,x,y1);}
        //если игрок выбрал кровать и рисовка записки
        if( 374+x1-y<621 && 335+x1-y>546 && 355+x-y1>121 && 355+x-y1<382) { if (f2==0)k6+=1; f2+=1;cleardevice();kvadra();x0=0;setcolor(15); line(171,132,571,132);line(571,132,571,307);line(571,307,171,307);
        line(171,307,171,132); settextstyle(0,0,1);outtextxy(276,142,"Предсмертная записка");for(int i=0;i<7;i++){line(196,162+x0,546,162+x0);x0+=20;}settextstyle(0,0,2);outtextxy(266,62,"Вы нашли:");
            settextstyle(0,0,1);outtextxy(171,435,"Согласно записи, Эшли признается в убийстве");outtextxy(171,455,"Дэвида. Она его с самого начала не любила.");
            outtextxy(171,475,"И из-за чувства совести совершает самоубийство");if (waitEnterOrEsc()==3) return 0; cleardevice();komnata3();pol3();kvadra();detect(x1,y,x,y1);}break;}}
        if (k6==2)break;}
    setfillstyle(1,7); bar(154,478,628,532);setcolor(15);settextstyle(0,0,1);outtextxy(170,495,"*Звонок*");outtextxy(154,460,"Телефон");
    if (waitEnterOrEsc()==3) return 0;

    //выбор, кто убийца
   killer();//рисовка данных
    if (FLAG==1) {outtextxy(20,320,"3.Найденная кухонная");outtextxy(20,340,"спринцовка скорее");outtextxy(20,360,"всего принадлежит ей.");};x1=0;y1=0; int FLAGG=0;//если игрок нашел кухонную спринцовку
    while(1){
    delay(50);
    if (kbhit()) {k3=getch(); if (k3==27) return 0;};
    if (ismouseclick(WM_LBUTTONDOWN)) getmouseclick(WM_LBUTTONDOWN,x1,y1);
        if(x1>=2 && x1<=265 && y1>=2 && y1<=500)FLAGG=1;
        if(x1>268 && x1<=530 && y1>=2 && y1<=500) FLAGG=2;
        if(x1>530 && x1<=707 && y1>=2 && y1<=500) FLAGG=2;
        if(FLAGG==1 || FLAGG==2) break;
    }
    cleardevice();kvadra();
    outtextxy(247,77,"ИТОГ");
    outtextxy(75,147,"Детективу позвонили и сказали, что Эшли пришла в себя.");
    outtextxy(75,167,"Детектив направился в больницу и опросил Эшли.");
    outtextxy(75,187,"Эшли сказала, что никакого письма не писала и никого не убивала.");
    outtextxy(75,207,"Из-за чего, полицейские проверили почерк подозреваемых.");
    outtextxy(75,227,"Оказалось, что почерк записки был идентичен почерку Стэйси.");
    outtextxy(75,247,"Когда ей сообщили об этом она призналась.");
    outtextxy(75,267,"Она сказала, что отравила дочь, чтобы огородить себя.");
    outtextxy(75,287,"УБИЙЦА-СТЭЙСИ КАСТОР.");
    if (waitEnterOrEsc()==3) return 0; cleardevice();kvadra();
    settextstyle(0,0,3); setcolor(15);
    outtextxy(224,98,"РЕЗУЛЬТАТЫ ИГРЫ");setfillstyle(9,15);
    if(FLAG==1 && FLAGG==1){settextstyle(0,0,1);outtextxy(152,249,"Вы нашли скрытую улику и правильно определили убийцу");}
    if(FLAG==0 && FLAGG==1){settextstyle(0,0,1);outtextxy(152,249,"Вы не нашли скрытую улику, но правильно определили убийцу");}
    if(FLAG==1 && FLAGG==2){settextstyle(0,0,1);outtextxy(152,249,"Вы нашли скрытую улику и неправильно определили убийцу");}
    if(FLAG==0 && FLAGG==2){settextstyle(0,0,1);outtextxy(152,249,"Вы не нашли скрытую улику и неправильно определили убийцу");}
     if (waitEnterOrEsc()==3) return 0;
    return 0;
}
// -----------------------------------------------------------------------------
// Обработка клавиатуры без использования консоли.
// Это позволяет запускать игру без дополнительного чёрного окна.
// -----------------------------------------------------------------------------
static int pendingKey = 0;

int pollGameKey()
{
#ifdef _WIN32
    if (GetAsyncKeyState(VK_ESCAPE) & 0x0001) return 27;
    if (GetAsyncKeyState(VK_RETURN) & 0x0001) return 13;
    if (GetAsyncKeyState(VK_LEFT)   & 0x0001) return 75;
    if (GetAsyncKeyState(VK_RIGHT)  & 0x0001) return 77;
    if (GetAsyncKeyState(VK_UP)     & 0x0001) return 72;
    if (GetAsyncKeyState(VK_DOWN)   & 0x0001) return 80;
#endif
    return 0;
}

int gameKbhit()
{
    if (pendingKey != 0) return 1;
    pendingKey = pollGameKey();
    return pendingKey != 0;
}

int gameGetch()
{
    if (pendingKey != 0) {
        int key = pendingKey;
        pendingKey = 0;
        return key;
    }

    int key = 0;
    while (key == 0) {
        key = pollGameKey();
#ifdef _WIN32
        Sleep(10);
#endif
    }
    return key;
}

void kvadra()
{
   setcolor(15);line(800,1,800,600); line(800,600,1,600);
}
void meny()
{
    kvadra();setcolor(4); setfillstyle(1,4);
    fillellipse(491,477,25,22); fillellipse(500,466,25,22); fillellipse(500,388,125,55); fillellipse(491,433,25,22); fillellipse(575,487,25,22);//рисунок лужи
    fillellipse(375,433,12,12); fillellipse(333,444,8,8); fillellipse(291,433,4,4); setfillstyle(9,15); bar(1,83,800,146); setcolor(0); setfillstyle(1,0);
    bar(41,88,209,138); bar(613,88,760,138); settextstyle(0,0,3); setcolor(15);//рисовка кнопок
    outtextxy(224,98,"Запах антифриза");setfillstyle(9,15);
    bar(279,233,529,288); bar(279,344,529,400); bar(362,511,445,533);
    settextstyle(0,0,2);outtextxy(312,249,"Начать игру"); outtextxy(362,361,"Выход");
    settextstyle(0,0,1); outtextxy(383,513,"2022");
}
void poyasnenie()
{
     cleardevice();kvadra();
    settextstyle(0,0,3); setcolor(15);
    outtextxy(302,72,"Пояснение");
    settextstyle(0,0,1); setcolor(15);
    outtextxy(155,186,"Данная игра представляет из себя детектив. Но учтите,\n");
    outtextxy(117,208,"что анализировать вы должны сами, игра дает только найденные\n");
    outtextxy(155,230,"вами факты. Чтобы переключать сцены нажмите Enter.\n");
    outtextxy(95,252,"Если захотите выйти, вы в любой момент нажать Esc. Приятной вам игры!\n");

}
int menuAction()//Отвечает за выбор пункта меню
{
    int x = 0;
    int y = 0;
    int result = 2;

    delay(50);
    if (ismouseclick(WM_LBUTTONDOWN)) {
        getmouseclick(WM_LBUTTONDOWN, x, y);
    }

    if (x >= 279 && x <= 529 && y >= 233 && y <= 288) result = 1;
    if (x >= 279 && x <= 529 && y >= 344 && y <= 400) result = 3;

    return result;
}
int waitEnterOrEsc()//Ожидает Enter или Esc
{
    int key;
    do {
        key = getch();
    } while (key != 13 && key != 27);

    if (key == 13) return 1;
    if (key == 27) return 3;

    return 0;
}
void komnatadop()//Основная комната
{
    int shape [12]={708,483,708,434,395,348,83,434,83,483,708,483};
    int shape1[10]={108,179,108,427,167,411,167,191,108,179};
    int shape2[10]={121,196,121,425,155,413,155,202,121,196};
    int shape3[10]={312,333,362,344,437,327,362,316,312,333};
    cleardevice();setcolor(15); kvadra();
    setcolor(8); setfillstyle(1,8);
    line(83,77,395,145); line(395,145,708,77); line(83,77,708,77); line(395,145,395,348);
    line(83,77,83,484); line(708,77,708,484);drawpoly(6,shape);setfillstyle(2,8);floodfill(292,482,8 );setcolor(8);  //комната

    drawpoly(5,shape1);setcolor(8); drawpoly(5,shape2);setfillstyle(1,8);floodfill(119,197,8); setfillstyle(3,8); floodfill(122,197,8);setcolor(0); setfillstyle(1,0); fillellipse(158,305,4,4); //дверь

    setcolor(7); setfillstyle(1,8);drawpoly(5,shape3); floodfill(362,317,7);floodfill(396,327,7); bar(310,332,312,388); bar(360,343,362,399); bar(435,327,437,382);bar(360,316,362,371);//стол

    setcolor(7); setfillstyle(1,7); fillellipse(400,311,8,16); line(400,311,391,277); line(400,311,400,277);line(400,311,408,277); setfillstyle(1,8);fillellipse(400,277,4,4); //цветок

    setcolor(8); setfillstyle(1,8);line (235,179,286,186); line(235,179,235,287);line(286,186,286,281); line (235,287,286,281); //зеркало

    line(437,179,520,168); line(437,277,520,288);bar(437,173,463,311); bar(494,166,521,311); setcolor(0); line(445,173,445,311);line(454,173,454,311); line(502,166,502,311);
    line(510,166,510,311);//окно
}
void scena1()
{
    komnatadop();//рисование комнаты
    setfillstyle(1,7); fillellipse(298,247,19,19);setfillstyle(1,8); fillellipse(300,249,16,16);bar(288,267,317,322);setfillstyle(1,7); bar(288,322,300,394); bar(300,322,317,394);
    setfillstyle(1,8); fillellipse(294,402,8,8); fillellipse(307,402,8,8);line(300,322,300,394); bar(250,267,288,283); bar(317,272,355,288);setcolor(0);setfillstyle(1,0);line(317,327,317,288);
    line(317,272,317,288);fillellipse(302,275,5,5); bar(300,275,304,297) ;//мужчина
     setfillstyle(1,7); bar(543,230,583,278);setfillstyle(1,8);fillellipse(564,241,16,16);setfillstyle(1,7);bar(543,222,583,236);bar(564,225,581,275); setfillstyle(1,8);
    bar(547,258,575,308);setfillstyle(1,7); bar(555,308,583,363);setfillstyle(1,8); bar(565,363,578,405); setfillstyle(1,0);bar(564,258,572,338); line(302,222,302,194);
    line(727,400,727,350); line(765,400,797,370); line(770,435,805,435);//женщина
    line(316,222,329,211); setcolor(15); line(298,216,298,194);line(297,216,297,194); line(307,216,312,194); line(306,216,311,194); line(315,222,329,211);line(315,222,328,211); //ругань
}
void scena2()
{
    komnatadop();
    fillellipse(666,428,277,277); setfillstyle(1,7); bar(625,111,750,484); bar(387,111,750,277);bar(583,277,708,333); setfillstyle(1,0); bar(709,77,1920,1180);//Комната
    bar(83,484,1920,1080); fillellipse(480,388,19,19);setfillstyle(1,7);setcolor(15);line(800,1,800,600); line(800,600,1,600); setcolor(0);line(429,361,491,333);
    line(480,388,520,388);setfillstyle(1,0);fillellipse(398,478,19,13);setcolor(8); setfillstyle(1,8);line (83,484,708,484); setfillstyle(1,8); bar(367,388,400,444);//женщина
    line(140,166,140,138); line(152,166,165,150); line(154,175,168,175); //звук закрытие двери
    setcolor(0); line(625,111,625,484); line(641,111,641,484); line(658,111,658,484);line(675,111,675,484); //продолжение рисования женщины
    line(691,111,691,484);
}
void scena3()
{
    cleardevice();
    setcolor(8);
    int shape[10]={291,388,416,388,425,333,300,333,291,388};
    line(83,77,708,77); line (83,483,708,483); line(83,77,83,483); line(708,77,708,483); line(83,281,708,281); line(208,281,208,133);line(208,133,585,133); line (585,133,585,281);//квадрат
    fillellipse(458,166,16,16);setfillstyle(1,0);setcolor(0);fillellipse(445,166,16,16);//луна
   setfillstyle(6,8);bar(83,250,707,280); setfillstyle(1,0);bar(287,244,458,305);setcolor(8);line(83,250,708,250); //стена
    setcolor(15); line(800,1,800,600); line(800,600,1,600);setcolor(8); line(291,253,291,197);line(291,197,458,197);line(458,197,458,253);line(291,253,272,281); line(458,253,439,281); line(272,281,272,308); line(439,281,439,308); line(291,281,439,281); //диван с женщиной
    line(272,308,439,308);line(439,308,458,281);line(458,280,458,253); setfillstyle(1,8);fillellipse(437,258,13,13); bar(416,258,437,264);setfillstyle(1,7);bar(273,253,420,281); bar(437,244,458,277);
    setfillstyle(1,8); fillellipse(500,308,27,11); bar(499,308,504,238);setfillstyle(4,7); bar(479,216,525,238);//лампа

}
void Ste1(int x1,int y, int x, int y1)
{
    int shapeoo4[8]={383+x1-y,332+x-y1,425+x1-y,332+x-y1,404+x1-y,309+x-y1,383+x1-y,332+x-y1};
    setfillstyle(1,15); bar(387+x1-y,293+x-y1,420+x1-y,330+x-y1);setcolor(1);drawpoly(4,shapeoo4);setfillstyle(1,7);floodfill(395+x1-y,321+x-y1,1); setfillstyle(1,8);fillellipse(404+x1-y,299+x-y1,13,13);setfillstyle(1,15);
    setcolor(15); bar(395+x1-y,332+x-y1,397+x1-y,355+x-y1);bar(406+x1-y,332+x-y1,408+x1-y,355+x-y1); bar(391+x1-y,299+x-y1,416+x1-y,285+x-y1);setcolor(0);setfillstyle(1,0);fillellipse(400+x1-y,305+x-y1,2,2);fillellipse(408+x1-y,305+x-y1,2,2); line(403+x1-y,307+x-y1,405+x1-y,307+x-y1);
}
void Ste2(int x1,int y, int x, int y1)
{
    int shapeoo4[8]={383+x1-y,332+x-y1,425+x1-y,332+x-y1,404+x1-y,309+x-y1,383+x1-y,332+x-y1};
    setcolor(1);drawpoly(4,shapeoo4);setfillstyle(1,7);floodfill(395+x1-y,321+x-y1,1);setfillstyle(1,8);fillellipse(404+x1-y,299+x-y1,13,13); setfillstyle(1,15); bar(387+x1-y,288+x-y1,400+x1-y,330+x-y1);
    bar(391+x1-y,299+x-y1,423+x1-y,285+x-y1);setfillstyle(1,15); setcolor(15);bar(406+x1-y,332+x-y1,408+x1-y,355+x-y1); bar(402+x1-y,316+x-y1,404+x1-y,338+x-y1);
}
void Ste3(int x1,int y, int x, int y1)
{
    int shapeoo4[8]={383+x1-y,332+x-y1,425+x1-y,332+x-y1,404+x1-y,309+x-y1,383+x1-y,332+x-y1};
    setcolor(1);drawpoly(4,shapeoo4);setfillstyle(1,7);floodfill(393+x1-y,331+x-y1,1);setfillstyle(1,8);fillellipse(404+x1-y,299+x-y1,13,13); setfillstyle(1,15); bar(408+x1-y,288+x-y1,420+x1-y,330+x-y1);
    bar(391+x1-y,299+x-y1,416+x1-y,285+x-y1);setfillstyle(1,15); setcolor(15);bar(406+x1-y,332+x-y1,408+x1-y,355+x-y1); bar(408+x1-y,316+x-y1,410+x1-y,338+x-y1);
}
void Ste4(int x1,int y, int x, int y1)
{
    int shapeoo4[8]={383+x1-y,332+x-y1,425+x1-y,332+x-y1,404+x1-y,309+x-y1,383+x1-y,332+x-y1};
    setcolor(1);drawpoly(4,shapeoo4);setfillstyle(1,7);floodfill(393+x1-y,331+x-y1,1); setfillstyle(1,8);fillellipse(404+x1-y,299+x-y1,13,13);setfillstyle(1,15);
    setcolor(15); bar(395+x1-y,332+x-y1,397+x1-y,355+x-y1);bar(406+x1-y,332+x-y1,408+x1-y,355+x-y1);  bar(391+x1-y,299+x-y1,416+x1-y,285+x-y1);setcolor(0);setfillstyle(1,0);fillellipse(400+x1-y,305+x-y1,2,2);fillellipse(408+x1-y,305+x-y1,2,2);line(403+x1-y,307+x-y1,405+x1-y,307+x-y1);
    setfillstyle(1,15); bar(387+x1-y,293+x-y1,420+x1-y,330+x-y1);
}
void pol()
{
    setfillstyle(1,0); bar(154,265,628,538); setfillstyle(1,15);
}
void pol1()
{
      setfillstyle(1,0);bar(154,460,628,538);
}
void komnata1()
{
    cleardevice(); kvadra();
    int shape[10]={41,27,750,27,750,538,41,538,41,27};
    int shape2[12]={42,442,159,258,628,258,749,538,42,538,42,442};
    int shape3[12]={62,442,164,281,620,281,716,516,62,516,62,442};
    setcolor(7);drawpoly(5,shape); line(164,281,164,27);line(620,281,620,27);setcolor(7); drawpoly(6,shape2);setcolor(7);
    line(80,176,80,383);line(80,176,120,126); line(120,126,120,322); line(120,322,80,322); setfillstyle(1,7); floodfill(115,316,7 ); //боковая дверь
    line(315,258,315,111); line(315,111,375,111); line(375,111,375,258 );fillellipse(370,194,5,5);//важная дверь
    setfillstyle(10,7);floodfill(167,100,7 );floodfill(162,100,7 );
    line(666,158,666,347);line(666,158,708,257);line(708,257,708,444);line(708,444,666,347); floodfill(621,100,7 );setfillstyle(1,8);fillellipse(700,322,5,5);//дверь детей
    setcolor(15); drawpoly(6,shape2);drawpoly(6,shape3);//украшение
    setfillstyle(1,8);bar(628,225,629,264);setfillstyle(1,7);
    line(550,225,629,225);line(629,225,637,247);line(637,247,559,247);line(559,247,550,225);setfillstyle(1,8);floodfill(565,238,15); bar(550,225,551,264); bar(636,247,637,277);bar(558,247,559,277);
    setfillstyle(1,7); bar(604,240,612,222);bar(604,222,605,216); setfillstyle(1,0); bar(606,225,610,227);//стол с телефоном
    setfillstyle(1,8); setcolor(8);line(159,216,141,238);line(141,238,170,238);line(170,238,187,216);line(187,216,159,216);floodfill(166,222,8); bar(163,222,165,266); fillellipse(164,266,11,5);
    setfillstyle(1,7); bar(162,222,164,225); bar(162,227,157,230); bar(154,227,160,222); bar(170,227,174,220);//шашки
    pol();
}
void da()
{
    setfillstyle(1,7); bar(154,480,628,538);setcolor(15);settextstyle(0,0,2); outtextxy(180,485,"Желаете сыграть в шашки?");
    setfillstyle(1,8); bar(195,505,255,535);outtextxy(210,510,"Да");bar(300,505,365,535); outtextxy(310,510,"Нет");
}
void pole()//рисовка шахматной доски
{
    int n=1,x2,y2;
    cleardevice(); setfillstyle(1,8); kvadra();
    bar(50,30,450,430);setcolor(DARKGRAY);y2=30;setfillstyle(1,15);
    for (int i=1;i<=8;i++){x2=50; n++;
        if (n%2!=0){x2+=50;
            for(int j=1;j<=4;j++){
                bar(x2,y2,x2+50,y2+50); x2+=100;}}
        else{
            for(int j=1;j<=4;j++){
                bar(x2,y2,x2+50,y2+50);x2+=100;}}
        y2+=50;}
    setcolor(WHITE);
    settextstyle(0,0,1);
    outtextxy(25,45,"8");outtextxy(25,95,"7");outtextxy(25,145,"6");outtextxy(25,195,"5");outtextxy(25,245,"4");outtextxy(25,295,"3");outtextxy(25,345,"2");outtextxy(25,395,"1");
    outtextxy(70,445,"A");outtextxy(120,445,"B");outtextxy(170,445,"C");outtextxy(220,445,"D");outtextxy(270,445,"E");outtextxy(320,445,"F");outtextxy(370,445,"G");outtextxy(420,445,"H");
    outtextxy(570,30,"ШАШКИ");
    outtextxy(480,70,"Чтобы поменять цвет нажми пробел.");
     outtextxy(480,90,"Чтобы выйти нажми Esc.");
    outtextxy(480,110,"Чтобы убрать шашку нажми на нее ");
    outtextxy(480,130,"правой кнопкой мыши.");
    outtextxy(480,150,"Чтобы поставить шашку нажми левой");
     outtextxy(480,170,"кнопкой мыши на нужное тебе место.");
    outtextxy(480,190,"Вы можете позвать друга и");
     outtextxy(560,210,"играть с ним!");
    outtextxy(560,210,"Кто ходит:");
    setfillstyle(1, 15);
    setcolor(15);
    bar(580,260,620,300); //рамочка
}
void post(){//чтобы пользовтель мог убрать шашку
    int color3,x1,y1,x2,j,l,n=0,n2,y2;
     if (ismouseclick(WM_RBUTTONUP)){
                delay(50);
                getmouseclick(WM_RBUTTONUP, x1, y1);setfillstyle(SOLID_FILL,DARKGRAY);color3=0;
                for ( l=1;l<=2;l++){n=0;n2=1;y2=30;
                    for (int i=1;i<=8;i++){if (color3==0) {n++; x2=50;}
                        else {n2++;n=n2;x2=50;setfillstyle(SOLID_FILL,WHITE);}
                        if (n%2!=0){x2+=50;for(j=1;j<=4;j++){
                                        if(x1>=x2 && x1<=(x2+50)&& y1>=y2 && y1<=(y2+50)) bar(x2,y2,x2+50,y2+50);
                                         x2+=100;}}
                        else{
                            for(j=1;j<=4;j++){
                                if(x1>=x2 && x1<=(x2+50)&& y1>=y2 && y1<=(y2+50)) bar(x2,y2,x2+50,y2+50);
                                x2+=100;}}y2+=50;}color3+=1;}}
}
int chess()
{

    int x1,y1,color,color1,k,k1,k2,n,x2,y2,i,n2,color3,l,j;
    k2=0;pole();color=0;k=color;color1=9;// не белый, чтобы шашки не сливались с доской
    setfillstyle(1, color);setcolor(color);
    while(1){
             post();//чтобы пользовтель мог убрать шашку
            if (kbhit()){ //отслеживает нажатие пробела или Esc
                k1=getch();
                if (k1==32){color=color1;color1=k;k=color;setfillstyle(1, color);setcolor(color);}
                if (k1==27){k2=3;}
            if (k2==3) break;
            }
            if (ismouseclick(WM_LBUTTONDOWN)){ //чтобы пользовтель мог поставить шашку
                delay(50);
                setfillstyle(1, color);
                setcolor(color);
                getmouseclick(WM_LBUTTONDOWN, x1, y1);
                color3=0;
                for (l=1;l<=2;l++){n=0;n2=1;y2=30;
                    for (i=1;i<=8;i++){
                        if (color3==0) {n++; x2=50;}
                        else {n2++;n=n2;x2=50;}
                        if (n%2!=0){x2+=50;for(j=1;j<=4;j++){
                                        if(x1>=x2 && x1<=(x2+50)&& y1>=y2 && y1<=(y2+50)) fillellipse((x2+x2+50)/2,(y2+50+y2)/2,20,20);
                                         x2+=100;}}
                        else{
                            for(j=1;j<=4;j++){if(x1>=x2 && x1<=(x2+50)&& y1>=y2 && y1<=(y2+50)) fillellipse((x2+50+x2)/2,(y2+50+y2)/2,20,20);x2+=100;}}
                        y2+=50;}color3+=1;}}
            setfillstyle(1, color); //показывает какой цвет сейчас ходит
            setcolor(color);
            bar(590,270,610,290);}
    if (k2==3) return k2;
}
void telephone()
{
    setfillstyle(SOLID_FILL,LIGHTGRAY); kvadra();
    bar(140,180,390,300); bar(140,180,390,500); bar(140,80,190,180);//сам телефон
    settextstyle(0,0,1);//объяснение игры
    outtextxy(430,120, "Набери номер полиции"); outtextxy(430,140, "Прототип игры «Однорукий бандит»");
    outtextxy(430,160, "Нажимай Enter, пока на экране телефона");
    outtextxy(430,180, "не будет номера полиции");
    setfillstyle(SOLID_FILL,0);
    bar (170,205,370,270);
    bar(170,295,235,334);bar(238,295,301,334);bar(305,295,370,334);//кнопки
    bar(170,354,235,393);bar(238,354,301,393);bar(305,354,370,393);
    bar(170,413,235,452);bar(238,413,301,452);bar(305,413,370,452);settextstyle(0,0,2);
    outtextxy(192,306, "1");outtextxy(258,308, "2");outtextxy(327,306, "3");
    outtextxy(192,366, "4");outtextxy(258,368, "5");outtextxy(327,366, "6");
    outtextxy(192,426, "7");outtextxy(258,428, "2");outtextxy(327,426, "8");
}
void mashina()
{
     int m=300,i;
    cleardevice();
    setcolor(15);
    line(800,1,800,600); line(799,1,799,600);line(800,600,1,600); line(83,77,708,77);line(83,77,83,484); line(708,77,708,484); line(83,484,708,484);
    line(83, m+37, 708, m+37);setfillstyle(3,8); floodfill(600,338,15);circle(630, 140,20);
    for (i=87; i < 568; i=i+10) {
        setfillstyle(1,0);setcolor(15);
        bar(84,160,707,m+36);
        line(i, m + 23, i, m);
        line(i, m, 40 + i, m - 20);
        line(40 + i, m - 20, 80 + i, m - 20);//
        line(50+i,m-25,70+i,m-25);
        line(50+i,m-25,50+i,m-20);line(70+i,m-25,70+i,m-20);line(60+i,m-25,60+i,m-20);
        line(80 + i, m - 20, 100 + i, m);
        line(100 + i, m, 120 + i, m);
        line(120 + i, m, 120 + i, m + 23);
        line(0 + i, m + 23, 18 + i, m + 23);
        line(42 + i, m+ 23, 78 + i, m + 23);
        line(102 + i, m + 23, 120 + i, m + 23);
        line(28 + i, m, 43 + i, m - 15);
        line(43 + i, m - 15, 57 + i, m - 15);
        line(57 + i, m - 15, 57 + i, m);
        line(57 + i, m, 28 + i, m);
        line(62 + i, m - 15, 77 + i, m - 15);
        line(77 + i, m - 15, 92 + i, m);
        line(92 + i, m, 62 + i, m);
        line(62 + i, m, 62 + i, m - 15);
        setcolor(8);
        setfillstyle(1, 8);
        circle(30 + i, m + 25, 9);
        circle(90 + i, m+ 25, 9);
        floodfill(30 + i, m + 25, 8);
        floodfill(90 + i, m + 25, 8);
        delay(40);
    }

}
void polic(int x1,int y, int x, int y1)
{
    setfillstyle(1,8); bar(340+x1-y,382+x-y1,365+x1-y,405+x-y1);setcolor(1);setfillstyle(1,7); setfillstyle(1,8);fillellipse(354+x1-y,369+x-y1,13,13);setfillstyle(1,15);
    setcolor(15); bar(345+x1-y,405+x-y1,350+x1-y,430+x-y1);bar(355+x1-y,405+x-y1,360+x1-y,430+x-y1); bar(341+x1-y,369+x-y1,366+x1-y,355+x-y1);bar(368+x1-y,382+x-y1,363+x1-y,410+x-y1);bar(343+x1-y,382+x-y1,338+x1-y,410+x-y1);
    setcolor(0);setfillstyle(1,0);fillellipse(350+x1-y,375+x-y1,2,2);fillellipse(358+x1-y,375+x-y1,2,2); line(353+x1-y,377+x-y1,355+x1-y,377+x-y1);setfillstyle(1,0);
    fillellipse(349+x1-y,388+x-y1,2,2);setfillstyle(1,7); bar(341+x1-y,369+x-y1,366+x1-y,360+x-y1);
}
void polic1(int x1,int y, int x, int y1,int z)
{
   setfillstyle(1,8); bar(345+x1-y,382+x-y1,360+x1-y,405+x-y1);setcolor(1);setfillstyle(1,7); setfillstyle(1,8);fillellipse(354+x1-y,369+x-y1,13,13);setfillstyle(1,15);
    setcolor(15); bar(349+x1-y,405+x-y1,354+x1-y,430+x-y1);bar(349+x1-y,384+x-y1,353+x1-y,404+x-y1); bar(341+x1-y,369+x-y1,366+x1-y,355+x-y1);setfillstyle(1,7); bar(361+x1-y+z,364+x-y1,370+x1-y+z,369+x-y1);
}
void polic2(int x1,int y, int x, int y1)
{
    setfillstyle(1,8); bar(340+x1-y,382+x-y1,365+x1-y,405+x-y1);setcolor(1);setfillstyle(1,15);bar(368+x1-y,382+x-y1,363+x1-y,410+x-y1);bar(343+x1-y,382+x-y1,338+x1-y,410+x-y1); setfillstyle(1,8);fillellipse(354+x1-y,369+x-y1,13,13);setfillstyle(1,15);
        bar(345+x1-y,405+x-y1,350+x1-y,430+x-y1);bar(355+x1-y,405+x-y1,360+x1-y,430+x-y1); bar(341+x1-y,369+x-y1,366+x1-y,355+x-y1);
}
void dver()
{
    setfillstyle(1, 7);
    int shape1[10]={100,100,100,500,300,500,300,100,100,100};
    int shape2[10]={70,70,70,530,330,530,330,70,70,70};
    setcolor(15);line(800,1,800,600); line(800,600,1,600);
    drawpoly(5,shape1);drawpoly(5,shape2); fillellipse(310,300,10,10);
    setfillstyle(1, 4);
    settextstyle(0,0,3);
    outtextxy(420,100,"Сломай дверь");
    settextstyle(0,0,1);
    outtextxy(400,150,"Нажмите 10 раз на красный квадрат, чтобы");
    outtextxy(430,170,"сломать дверь и войти внутрь");
    outtextxy(450,200,"Вам осталось нажать:");
    outtextxy(500,220,"10   раз   ");
}
void scena4()
{
    cleardevice();
    setcolor(15);line(800,1,800,600); line(800,600,1,600);
    int shape3[10]={227,272,552,272,602,191,327,191,227,272};
    int shape4[14]={227,272,227,326,552,326,602,245,602,191,552,272,227,272};
    int shape5[10]={102,299,102,407,177,407,177,299,102,299};
    int shape6[10]={102,299,127,272,202,272,202,380,177,407};
    int shape7[10]={307,245,427,245,452,204,342,204,307,245};
    int shape8[8]={424,245,502,353,537,353,439,221};
    int shape9[8]={439,223,590,227,590,200,452,204};
    int shape10[10]={392,110,567,110,567,164,392,164,392,110};
    int shape11[10]={302,407,317,390,302,375,288,390,302,407};
    line(83,77,708,77); line(708,77,708,484);//квадрат и пол
    line(83,77,83,484); line(83,484,708,484);
    line(602,218,708,218); drawpoly(5,shape3);drawpoly(5,shape4); line(327,191,327,110); line(327,110,227,191);line(227,191,227,272);//кровать
    setfillstyle(3,15); bar(102,299,177,407); drawpoly(5,shape5);drawpoly(5,shape6); line(177,299,202,272);line(83,424,102,407);line(202,326,227,301);drawpoly(5,shape10);setfillstyle(10,7); floodfill(700,80,15);floodfill(85,80,15);//столешница с зеркалом
    setfillstyle(1,8); bar(127,243,152,285); bar(144,223,134,243);setfillstyle(1,7);bar(144,223,134,220); bar(162,285,172,275); //алкоголь с кружкой
    setfillstyle(1,8);fillellipse(297,218,25,25); drawpoly(5,shape7);floodfill(377,218,15);setfillstyle(1,7);fillellipse(302,218,24,24); line(307,245,307,255);//мужчина
    line(307,255,427,255);line(427,255,427,245);setfillstyle(1,8); bar(307,246,336,326); line(307,246,307,326);line(307,326,336,326);line(336,326,336,246);
    drawpoly(4,shape8);setcolor(0);line(484,326,517,326);line(445,272,477,272);setcolor(15);drawpoly(4,shape9);setfillstyle(1,7);fillellipse(330,339,10,10);fillellipse(528,356,20,10);
    fillellipse(589,211,10,20);line(342,204,377,191);line(367,204,402,191);setfillstyle(1,8);floodfill(380,195,15);
    line(327,77,327,120); drawpoly(5,shape11);setfillstyle(2,8); floodfill(707,480,15);//Доп элементы
}
void komnata2()
{
    cleardevice();kvadra();
     setcolor(15); setfillstyle(0,7);
    int shape12[10]={46,32,746,32,746,532,46,532,46,32};//квадрат
    int shape13[10]={171,207,371,207,346,282,146,282,171,207};
    int shape14[8]={371,207,371,232,346,307,157,307};
    int shape15[10]={221,82,371,82,371,151,221,151,221,82};
    int shape16[10]={446,57,596,57,596,232,446,232,446,57};
    int shape17[10]={82,382,132,382,132,307,82,307,82,382};
    drawpoly(5,shape12); line(746,207,171,207); line(721,207,721,96);line(721,96,646,96); line(646,96,646,207); fillellipse(708,144,5,5); line(146,32,146,282);//Дверь и комната
    setcolor(0);line(446,207,621,207);setcolor(15);
    drawpoly(5,shape13);drawpoly(4,shape14); line(346,307,346,282); line(171,207,171,132); line(171,132,146,207);//кровать
    drawpoly(5,shape15);drawpoly(5,shape16);line(596,232,621,207);line(621,207,621,82);line(621,82,596,57); line(521,232,521,57);fillellipse(533,144,5,5);fillellipse(508,144,5,5);//шкаф и зеркало
    drawpoly(5,shape17); line(132,382,157,367);line(157,367,157,282);line(157,282,132,307); line(157,282,111,282);line(111,282,82,307); line(82,382,46,532);//столешница
    setfillstyle(10,7);floodfill(47,33,15);floodfill(171,33,15);setfillstyle(3,7);floodfill(85,380,15);setfillstyle(1,8);bar(121,252,146,294); bar(129,252,139,232);setfillstyle(1,7);
    bar(129,232,139,229);bar(111,296,125,276); bar(296,332,310,318);detect(0,0,0,0);
}
void detect(int x1,int y,int x,int y1)
{
    int shapeo[10]={335+x1-y,382+x-y1,370+x1-y,382+x-y1,360+x1-y,405+x-y1,345+x1-y,405+x-y1,335+x1-y,382+x-y1};
            setcolor(15);setfillstyle(1,8); drawpoly(5,shapeo);setcolor(1); setfillstyle(1,8);fillellipse(354+x1-y,369+x-y1,13,13);setfillstyle(1,15);
            setcolor(15); bar(345+x1-y,405+x-y1,350+x1-y,430+x-y1);bar(355+x1-y,405+x-y1,360+x1-y,430+x-y1); bar(341+x1-y,369+x-y1,366+x1-y,355+x-y1);bar(372+x1-y,382+x-y1,367+x1-y,410+x-y1);bar(340+x1-y,382+x-y1,335+x1-y,410+x-y1);
            setcolor(0);setfillstyle(1,0);fillellipse(350+x1-y,375+x-y1,2,2);fillellipse(358+x1-y,375+x-y1,2,2); line(353+x1-y,377+x-y1,355+x1-y,377+x-y1);setfillstyle(1,7);
            fillellipse(353+x1-y,385+x-y1,3,3);bar(351+x1-y,388+x-y1,355+x1-y,398+x-y1);setcolor(15);line(336+x1-y,369+x-y1,336+x1-y,365+x-y1);line(336+x1-y,365+x-y1,370+x1-y,365+x-y1);line(370+x1-y,365+x-y1,370+x1-y,369+x-y1);line(370+x1-y,369+x-y1,336+x1-y,369+x-y1);
            setfillstyle(1,8);bar(372+x1-y,405+x-y1,367+x1-y,410+x-y1);bar(340+x1-y,405+x-y1,335+x1-y,410+x-y1);
}
void detect1(int x1,int y,int x,int y1,int z)
{
  int shapeo6[10]={340+x1-y,382+x-y1,365+x1-y,382+x-y1,360+x1-y,405+x-y1,345+x1-y,405+x-y1,340+x1-y,382+x-y1};setcolor(15);
    setfillstyle(1,8); drawpoly(5,shapeo6);setcolor(1); setfillstyle(1,8);fillellipse(354+x1-y,369+x-y1,13,13);setfillstyle(1,15);
    setcolor(15);bar(353+x1-y,405+x-y1,357+x1-y,430+x-y1); bar(341+x1-y,369+x-y1,366+x1-y,355+x-y1);bar(352+x1-y+z,382+x-y1,347+x1-y+z,410+x-y1);
    setfillstyle(1,0);setcolor(15);bar(336+x1-y,369+x-y1,370+x1-y,365+x-y1);line(336+x1-y,369+x-y1,336+x1-y,365+x-y1);line(336+x1-y,365+x-y1,370+x1-y,365+x-y1);line(370+x1-y,365+x-y1,370+x1-y,369+x-y1);line(370+x1-y,369+x-y1,336+x1-y,369+x-y1);
    setfillstyle(1,8);bar(352+x1-y+z,405+x-y1,347+x1-y+z,410+x-y1);
}
void detect2(int x1,int y,int x,int y1)
{
    int shapeo2[10]={335+x1-y,382+x-y1,370+x1-y,382+x-y1,360+x1-y,405+x-y1,345+x1-y,405+x-y1,335+x1-y,382+x-y1};
    setfillstyle(1,8); drawpoly(5,shapeo2);setcolor(1); setfillstyle(1,8);fillellipse(354+x1-y,369+x-y1,13,13);setfillstyle(1,15);
    setcolor(15); bar(345+x1-y,405+x-y1,350+x1-y,430+x-y1);bar(355+x1-y,405+x-y1,360+x1-y,430+x-y1); bar(341+x1-y,369+x-y1,366+x1-y,355+x-y1);bar(372+x1-y,382+x-y1,367+x1-y,410+x-y1);bar(340+x1-y,382+x-y1,335+x1-y,410+x-y1);
    setfillstyle(1,0);setcolor(15);bar(336+x1-y,369+x-y1,370+x1-y,365+x-y1);line(336+x1-y,369+x-y1,336+x1-y,365+x-y1);line(336+x1-y,365+x-y1,370+x1-y,365+x-y1);line(370+x1-y,365+x-y1,370+x1-y,369+x-y1);line(370+x1-y,369+x-y1,336+x1-y,369+x-y1);
    setfillstyle(1,8);bar(372+x1-y,405+x-y1,367+x1-y,410+x-y1);bar(340+x1-y,405+x-y1,335+x1-y,410+x-y1);
}

void pol2()
{
    setfillstyle(1,0); bar(96,383,158,531);bar(158,531,373,332);bar(373,531,745,233);
}
void ks()
{
    setcolor(15); int shapE[12]={221,107,271,139,383,244,358,269,246,157,221,107};
        int shapE2[10]={396,232,421,257,371,307,346,282,396,232};setcolor(15);drawpoly(6,shapE); drawpoly(5,shapE2);circle(431,317,50);
}
void antif()
{
    setcolor(15); line(296,157,396,157);line(396,157,471,257);line(471,257,423,282);
        line(423,282,346,182);line(346,182,396,157);line(346,182,246,182);line(246,182,296,157); fillellipse(283,169,15,10);line(246,182,246,407);line(246,407,421,407);
        line(421,407,421,280);line(421,407,471,357);line(471,357,471,256); line(346,296,346,232);line(346,296,396,296);line(396,296,346,232); line(346,296,376,269);
        line(246,307,421,307);line(246,357,421,357); outtextxy(296,332,"Антифриз");
}
void stakan()
{
    line(246,232,296,182);line(296,182,471,182);line(471,182,421,232);line(421,232,246,232);
        line(246,232,246,407);line(246,407,421,407);line(421,407,421,232);line(421,407,471,357); line(471,357,471,182);line(446,232,521,232);line(446,232,521,232);
        line(521,232,521,332);line(521,332,446,332);
}
void al()
{
    setfillstyle(1,8); bar(271,232,371,382);
    bar(296,132,346,232);setfillstyle(1,7);bar(296,132,346,152); bar(346,332,421,382);
}
void labir()
{
    setfillstyle(1,8);
    settextstyle(0,0,2);
    outtextxy(450,50,"Лабиринт");settextstyle(0,0,1);
    outtextxy(460,80,"Переместите кружок");
    outtextxy(460,100,"к светло-серому квадратику.");
    outtextxy(460,120,"После чего нажмите Enter.");
    int mas[22][20]= { {1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,},
		     {1,2,2,2,2,2,2,2,2,2,2,2,2,2,0,0,0,0,0,1,},
		     {1,2,1,1,0,1,1,1,1,1,1,1,1,1,1,0,1,1,0,1,},
		     {1,2,1,0,0,0,1,2,2,2,1,0,0,0,0,0,1,1,0,1,},
		     {1,2,1,1,1,1,1,2,1,2,1,1,1,0,1,0,0,0,0,1,},
		     {1,2,1,2,2,2,1,2,1,2,2,2,1,1,1,1,1,1,1,1,},
		     {1,2,1,2,1,2,1,2,1,0,1,2,2,2,2,2,2,2,2,1,},
		     {1,2,1,2,1,2,1,2,1,0,1,1,1,1,1,1,1,1,2,1,},
		     {1,2,1,2,1,2,1,2,1,0,0,0,0,0,0,0,0,0,2,1,},
		     {1,2,1,2,1,2,2,2,1,0,1,1,1,1,1,1,0,1,2,1,},
		     {1,2,1,2,1,1,1,1,1,0,0,0,1,0,1,0,0,1,2,1,},
		     {1,2,1,2,2,1,0,0,1,1,1,0,0,0,1,0,1,1,2,1,},
		     {1,2,1,1,2,1,1,0,0,0,0,0,1,0,1,0,0,1,2,1,},
		     {1,2,1,1,2,1,0,0,1,1,1,1,1,1,1,1,1,1,2,1,},
		     {1,2,1,1,2,1,1,0,1,2,2,2,2,2,2,2,2,2,2,1,},
		     {1,2,1,1,2,1,0,0,1,2,1,1,1,1,1,1,1,1,1,1,},
		     {1,2,1,1,2,1,0,1,1,2,1,1,1,1,1,1,1,1,2,1,},
		     {1,2,1,1,2,1,0,0,1,2,1,1,2,2,2,2,2,2,2,1,},
		     {1,2,1,1,2,1,0,1,1,2,1,1,2,1,1,1,1,1,1,1,},
		     {1,2,1,1,2,1,0,0,1,2,1,1,2,1,0,0,0,1,0,1,},
		     {1,2,2,2,2,1,0,1,1,2,2,2,2,0,0,1,0,0,0,1,},
		     {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,} };
    int k=0,k1=1,x, y=30; kvadra();
    for(int i=0;i<22;i++){
        x=30;
        for(int j=0;j<20;j++)
        if (mas[i][j]==1){
            bar(x,y,x+20,y+20);
            x+=20;
        }
        else x+=20;
        y+=20;
    } bar(280,0,320,30);setfillstyle(1,7); bar(290,30,310,50);
    fillellipse(400,360,7,7);
}
void kryg(int x,int x1,int y,int y1,int color)
{
    setfillstyle(1,color);fillellipse(400+x-x1,360+y-y1,7,7);}
void nadpis()
{
    outtextxy(80,50,"Найди все синие кристалы от антифриза, их может вообще не быть");
    outtextxy(190,70,"Когда все найдешь, нажми ГОТОВО");setfillstyle(9,15);bar(229,434,489,490);outtextxy(332,455,"Готово");
}
void scena5()
{
    cleardevice(); kvadra();
    int shapp[10]={453,177,453,200,313,200,313,177,453,177};
    int shapp1[10]={438,247,413,297,388,276,363,297,383,249};
    setcolor(15);line(83,77,708,77); line (83,483,708,483); line(83,77,83,483); line(708,77,708,483);//квадрат
    line(158,77,158,202); line(158,202,658,377); line(658,377,658,77); line(83,252,708,483);setfillstyle(1,0);bar(513,83,338,340);//стол и окно
    setfillstyle(1,8);fillellipse(383,197,55,55);setcolor(0);setfillstyle(1,0);bar(453,90,313,200);  fillellipse(373,213,6,6); line(375,200,365,206);//детектив
    setfillstyle(1,7);setcolor(15); bar(333,108,433,177);drawpoly(5,shapp); bar(338,211,345,230);line(433,218,438,247); line(383,249,388,276);
    line(388,276,438,247);drawpoly(5,shapp1); setfillstyle(1,8);floodfill(390,273,15); line(438,247,513,272);line(513,272,513,397);
    line(513,397,463,447);line(463,447,413,422);line(413,422,463,372); line(463,372,463,297); fillellipse(440,433,33,20);
    line(383,249,308,274);line(308,274,308,337); line(333,299,340,347); line(333,299,308,274);line(463,297,513,272); setfillstyle(1,7);
    fillellipse(393,282,10,10); bar(383,292,403,363);
    setfillstyle(1,0);bar(450,388,502,408);
}
void komnata3()
{
    int sha[10]={171,182,246,182,246,257,171,257,171,182};
    int sha1[10]={171,182,196,157,271,157,271,232,246,257};
    int sha2[10]={271,207,321,157,471,157,421,207,271,207};
    int sha3[8]={471,157,471,232,421,282,421,207};
    int sha4[10]={321,82,446,82,446,132,321,132,321,82};
    int sha5[10]={496,57,621,57,621,257,496,257,496,57};
    int sha6[10]={671,282,721,282,696,332,646,332,671,282};
    setcolor(15);
    line(46,32,746,32); line(746,32,746,532);line(746,532,46,532); line(46,532,46,32);//комната
    line(46,532,121,232); line(121,232,121,32);line(121,232,746,232);line(71,437,71,207);line(71,207,96,107);
    line(96,107,96,332);
    setcolor(0);line(171,232,321,232); line(371,232,471,232);line(496,232,746,232);setcolor(15);
    drawpoly(5,sha); drawpoly(5,sha1); line(271,157,246,182); line(171,219,246,219); //столешница
    setfillstyle(1,8); fillellipse(208,208,5,5);fillellipse(208,230,5,5);
    drawpoly(5,sha2); line(271,207,271,282);line(271,282,321,232);line(321,232,321,207); drawpoly(4,sha3);//стол
    line(421,282,371,282);line(371,282,371,207);line(421,244,371,244);line(421,244,471,194);fillellipse(396,230,5,5);
    fillellipse(396,260,5,5);
     drawpoly(5,sha4); line(371,132,371,157);line(396,132,396,157); line(371,157,346,172);line(346,172,421,172);//компьютер
     line(421,172,396,157);
      drawpoly(5,sha5); line(558,57,558,257); line(621,57,646,82);line(646,82,646,232);line(646,232,621,257);//шкаф
      fillellipse(550,157,5,5);fillellipse(566,157,5,5);
    line(646,157,746,157);line(646,207,746,207); line(646,207,621,332);line(621,332,746,332);line(621,332,621,357);//кровать
    line(621,357,746,357);  drawpoly(5,sha6);
     setfillstyle(10,7);floodfill(200,33,15);floodfill(47,33,15);setfillstyle(1,8);  bar(196,144,210,170);  setfillstyle(1,7); bar(210,170,223,178);//доп элементы
      setfillstyle(1,0); bar(644,220,744,250);bar(646,210,744,220);bar(643,227,744,250);bar(641,235,744,250);setfillstyle(6,7);floodfill(744,232,15);
}
void pol3()
{
    setfillstyle(1,0); bar(121,296,621,531);
}
void killer()
{
    cleardevice();
    settextstyle(0,0,1);
    int sh[6]={80,150,133,80,180,150};int sh1[6]={80+267,150,133+267,80,180+267,150};int sh2[8]={80+531,150,80+531,100,180+531,100,180+531,150};
    setcolor(15);line(800,1,800,600); line(800,600,1,600); setfillstyle(1,7); bar(2,2,265,500);bar(268,500,530,2);bar(534,2,799,500);//фон
    setfillstyle(1,0); bar(20,20,246,150);bar(286,20,513,150);bar(553,20,780,150);
    setfillstyle(1,15); bar(80,60,180,150);bar(95+267,35,170+267,100); fillellipse(400,70,35,35);fillellipse(664,70,35,35);setcolor(0);drawpoly(3,sh);setcolor(15);drawpoly(4,sh2);drawpoly(3,sh1);//фото подозреваемых
    setfillstyle(1,8); fillellipse(133,70,35,35);fillellipse(400,75,30,30);fillellipse(664,75,30,30);
    setfillstyle(1,15); bar(96,30,170,70);setfillstyle(1,0);setcolor(0);fillellipse(123,80,5,5);fillellipse(143,80,5,5);fillellipse(123+267,80,5,5);fillellipse(143+267,80,5,5);
    fillellipse(123+531,80,5,5);fillellipse(143+531,80,5,5); line(128,90,138,90);line(128+267,90,138+267,90);line(128+531,90,138+531,90);
    setcolor(15);outtextxy(20,160,"Имя: Cтэйси");outtextxy(20+267,160,"Имя: Эшли");outtextxy(20+531,160,"Имя: Салли");//информация
    outtextxy(20,180,"Фамилия: Кастор");outtextxy(20+267,180,"Фамилия: Уоллес");outtextxy(20+531,180,"Фамилия: Полер");
    outtextxy(20,200,"Возраст: 45 лет");outtextxy(20+267,200,"Возраст: 17 лет");outtextxy(20+531,200,"Возраст: 55 лет");
    outtextxy(20,220,"Жена потерпевшего");outtextxy(20+267,220,"Падчерица");outtextxy(20+531,220,"Деловой партнер");
    outtextxy(20,240,"Причины подозрения:");outtextxy(20+267,240,"Причины подозрения:");outtextxy(20+531,240,"Причины подозрения:");
    outtextxy(20,260,"1.Первая сообщила о Девиде.");outtextxy(20+267,260,"1.Предсмертная записка,");outtextxy(20+531,260,"1.Слухи о том, что Салли");
    outtextxy(20,280,"2.Находилась в доме");outtextxy(20+267,280,"найденная в комнате.");outtextxy(20+531,280,"ненавидел Дэвида.");
    outtextxy(20,300,"когда Дэвид умирал.");outtextxy(20+267,300,"2.Не любила Дэвида");outtextxy(20+531,300,"2.Находился рядом, в");
    outtextxy(20+267,320,"с самого начала");outtextxy(20+531,320,"предпологаемое время смерти");outtextxy(20+531,340,"Дэвида.");
    settextstyle(0,0,2); outtextxy(200,520,"Как вы считаете, кто убийца?");settextstyle(0,0,1);outtextxy(150,545,"Щелкни левой кнопкой мыши на любой вариант");
}
