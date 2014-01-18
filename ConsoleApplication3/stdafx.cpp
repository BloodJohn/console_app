#include "stdafx.h"

/*
Q: Для чего это сделано.
A: Все это сделано для ускорения компиляции проектов и не более того. Из-за того, что объем части общих .h-файлов превосходит все разумные пределы (например windows.h, цепляющий ещё десяток win*.h), и компилировать все эти заголовочники для каждого source-файлы просто накладно. Поэтому один раз генерится PCH-файл, а потом он (PCH) используется. Ускорение, кстати, в десятки раз, особенно заметное при работе с ATL/MFC проектами.

Q: Почему возникает ошибка "error looking precompiled header directive".
A: В каждом source-файле, для которого стоит опция "use this precompiled header" #include "stdafx.h" должно идти первым include

Q: Как избавится от генерации PCH-файлов
A: В свойствах проекта для файлов выставить "Not Using Precompiled Headers" или "Automatically Generate"

Q: Где находятся эти опции
A: VS6: Project settings -> C/C++ -> Precompiled Headers
VS.NET: Configuration Properties -> C/C++ -> Precompiled Headers

Q: Я настроил компиляцию DEBUG-версии на отказ использования PCH, но при компиляции RELEASE ошибка опять возникла.
A: Project setting для DEBUG/RELEASE представляю разные сущности. См. пред. пункт Q/A и настрой все для RELEASE-конфигурации.
*/