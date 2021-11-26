#include <Windows.h>
#include <stdio.h>
#define size_buffer 128






int WINAPI WinMain(HINSTANCE hlnstance, // ����������, ������������� ����������� ����������

    HINSTANCE hPrevInstance, // ��� ������������� � winl6. � Win32 �� ������������

    LPSTR lpCmdLine, // ��������� �� ��������� ������, ���� ���������� ��� ��������

    int nCmdShow) // ��������, ������� ����� ���� �������� � ������� Show Window ()

{
    ClipboardOutputText();
    return 0;
}






int ClipboardInputText(LPWSTR buffer)//�������� ������ � ��������� �����

{

    DWORD len;//����� ���������

    HANDLE hMem;//���������� ���������� ������� ������

    len = wcslen(buffer) + 1; // ����������� ����� ������ � ������� �������  

    hMem = GlobalAlloc(GMEM_MOVEABLE, len * sizeof(LPWSTR)); //��������� ������ � ���������� ������� ���������    

    memcpy(GlobalLock(hMem), buffer, len * sizeof(LPWSTR));// ����������� ������� ������ �� buffer � hMem

    GlobalUnlock(hMem); //�������������� ���������� ���� ������ (������� ��������� ��� ������ ��������)

    OpenClipboard(0);//������� ����� ������

    EmptyClipboard();//�������� ����� ������

    SetClipboardData(CF_UNICODETEXT, hMem);//�������� � ����� ������ ������ ���������������� ����

    CloseClipboard();//������� ����� ������, ������� ��� ��������� ��� ������ ����������    

    return 0;

}

int ClipboardOutputText()//������� ���������� �� ���������� ������

{
   
    while (TRUE)
    {
        OpenClipboard(NULL);//������� ����� ������  

        LPWSTR Mess = (LPWSTR)GetClipboardData(CF_UNICODETEXT);//������� �� ����������� ������� ������, �������� ��� ��� � �������
        char ad[2];
        ad[0] = Mess[0];
        ad[1] = '\0';
        int a = atoi(ad);
        LPWSTR answer;
        switch (a)
        {
        case 1:
            answer = L"����";
            ClipboardInputText(answer);
            break;
        case 2:
            answer = L"���";
            ClipboardInputText(answer);
            break;
        case 3:
            answer = L"���";
            ClipboardInputText(answer);
            break;
        case 4:
            answer = L"������";
            ClipboardInputText(answer);
            break;
        case 5:
            answer = L"����";
            ClipboardInputText(answer);
            break;
        case 6:
            answer = L"�����";
            ClipboardInputText(answer);
            break;
        case 7:
            answer = L"����";
            ClipboardInputText(answer);
            break;
        case 8:
            answer = L"������";
            ClipboardInputText(answer);
            break;
        case 9:
            answer = L"������";
            ClipboardInputText(answer);
            break;

        }
        CloseClipboard();//������� ����� ������, ������� ��� ��������� ��� ������ ����������
        Sleep(100);
    }
    return 0;

}

