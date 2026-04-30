# Настройка Code::Blocks для работы с graphics.h / WinBGIm

В C++ программа может работать в текстовом или графическом режиме.

Обычное консольное приложение запускается в текстовом режиме по умолчанию. В таком режиме программа выводит текст в консоль и получает данные через клавиатуру.  
Для создания графических программ необходимо подключить специальную графическую библиотеку.

В этом проекте используется библиотека `graphics.h` / WinBGIm. Она позволяет рисовать линии, фигуры, текст, обрабатывать клавиатуру и мышь, а также создавать простые графические приложения.

## Требования

Для запуска проекта требуется:

- Code::Blocks;
- 32-битный компилятор TDM-GCC;
- библиотека WinBGIm;
- файлы `graphics.h`, `winbgim.h` и `libbgi.a`.

Для работы с BGI/WinBGIm рекомендуется использовать именно 32-битный компилятор, даже если операционная система 64-битная.

## Установка компилятора

1. Скачайте TDM-GCC с сайта:

```text
https://jmeubank.github.io/tdm-gcc/
```

2. Выберите 32-битную версию компилятора.

Важно: в названии установщика не должно быть `64`.

3. Установите компилятор в папку:

```text
C:\TDM-GCC-32
```

## Настройка компилятора в Code::Blocks

Откройте Code::Blocks и перейдите в меню:

```text
Settings → Compiler...
```

Далее выберите:

```text
Global compiler settings → GNU GCC Compiler → Toolchain executables
```

В поле **Compiler's installation directory** укажите путь:

```text
C:\TDM-GCC-32
```

После этого проверьте, что указаны следующие исполняемые файлы:

```text
C compiler: gcc.exe
C++ compiler: g++.exe
Linker for dynamic libs: g++.exe
Linker for static libs: ar.exe
Resource compiler: windres.exe
Make program: mingw32-make.exe
```

Если Code::Blocks не находит компилятор автоматически, можно нажать кнопку **Auto-detect**.

## Подключение WinBGIm

Изначально в компиляторе нет библиотеки `graphics.h`, поэтому её нужно добавить вручную.

После распаковки архива WinBGIm должны быть файлы:

```text
graphics.h
winbgim.h
libbgi.a
```

Скопируйте файлы в папки компилятора:

```text
graphics.h  → C:\TDM-GCC-32\include
winbgim.h   → C:\TDM-GCC-32\include
libbgi.a    → C:\TDM-GCC-32\lib
```

## Настройка Linker settings

После копирования файлов снова откройте Code::Blocks и перейдите в меню:

```text
Settings → Compiler...
```

Затем откройте вкладку:

```text
Linker settings
```

В левой части окна нажмите **Add** и укажите путь к файлу:

```text
C:\TDM-GCC-32\lib\libbgi.a
```

В правую часть окна, в поле **Other linker options**, добавьте:

```text
-lgdi32
-lcomdlg32
-luuid
-loleaut32
-lole32
```

Для конкретного проекта также можно использовать полный набор параметров:

```text
-lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32 -mwindows
```

Параметр `-mwindows` нужен для запуска графической программы без дополнительного консольного окна.

## Проверка работы graphics.h

Для проверки можно создать простой файл `main.cpp`:

```cpp
#include <graphics.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    line(100, 100, 300, 100);
    circle(200, 200, 50);
    outtextxy(150, 300, "WinBGIm works!");

    getch();
    closegraph();

    return 0;
}
```

Если открылось графическое окно с линией, окружностью и текстом, значит библиотека подключена правильно.

## Возможные ошибки

### Code::Blocks не видит компилятор

Если появляется ошибка:

```text
The compiler's setup is invalid
```

значит Code::Blocks ищет компилятор не в той папке.

Нужно проверить путь:

```text
Settings → Compiler → Toolchain executables
```

Правильный путь:

```text
C:\TDM-GCC-32
```

### Ошибка graphics.h: No such file or directory

Если появляется ошибка:

```text
graphics.h: No such file or directory
```

значит файл `graphics.h` не скопирован в папку:

```text
C:\TDM-GCC-32\include
```

Также нужно проверить наличие файла:

```text
C:\TDM-GCC-32\include\winbgim.h
```

### Ошибка cannot find -lbgi

Если появляется ошибка:

```text
cannot find -lbgi
```

значит файл `libbgi.a` не находится в папке:

```text
C:\TDM-GCC-32\lib
```

### Появляется дополнительное консольное окно

Чтобы при запуске графической программы не открывалось дополнительное консольное окно, нужно добавить параметр:

```text
-mwindows
```

Полная строка для проекта:

```text
-lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32 -mwindows
```

## Итог

После настройки Code::Blocks, TDM-GCC и WinBGIm можно запускать графические программы на C++ с использованием библиотеки `graphics.h`.

В данном проекте эта настройка используется для запуска детективной 2D-игры **«Запах антифриза»**, написанной с использованием графических функций WinBGIm.
