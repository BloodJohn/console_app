#include "stdafx.h"

/*
Q: ��� ���� ��� �������.
A: ��� ��� ������� ��� ��������� ���������� �������� � �� ����� ����. ��-�� ����, ��� ����� ����� ����� .h-������ ����������� ��� �������� ������� (�������� windows.h, ��������� ��� ������� win*.h), � ������������� ��� ��� ������������� ��� ������� source-����� ������ ��������. ������� ���� ��� ��������� PCH-����, � ����� �� (PCH) ������������. ���������, ������, � ������� ���, �������� �������� ��� ������ � ATL/MFC ���������.

Q: ������ ��������� ������ "error looking precompiled header directive".
A: � ������ source-�����, ��� �������� ����� ����� "use this precompiled header" #include "stdafx.h" ������ ���� ������ include

Q: ��� ��������� �� ��������� PCH-������
A: � ��������� ������� ��� ������ ��������� "Not Using Precompiled Headers" ��� "Automatically Generate"

Q: ��� ��������� ��� �����
A: VS6: Project settings -> C/C++ -> Precompiled Headers
VS.NET: Configuration Properties -> C/C++ -> Precompiled Headers

Q: � �������� ���������� DEBUG-������ �� ����� ������������� PCH, �� ��� ���������� RELEASE ������ ����� ��������.
A: Project setting ��� DEBUG/RELEASE ����������� ������ ��������. ��. ����. ����� Q/A � ������� ��� ��� RELEASE-������������.
*/