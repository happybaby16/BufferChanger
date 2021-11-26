#include <Windows.h>
#include <stdio.h>
#define size_buffer 128






int WINAPI WinMain(HINSTANCE hlnstance, // дескриптор, присваиваемый запущенному приложению

    HINSTANCE hPrevInstance, // для совместимости с winl6. в Win32 не используется

    LPSTR lpCmdLine, // указатель на командною строку, если приложение так запущено

    int nCmdShow) // значение, которое может быть передано в функцию Show Window ()

{
    ClipboardOutputText();
    return 0;
}






int ClipboardInputText(LPWSTR buffer)//записать строку в системный буфер

{

    DWORD len;//длина сообщения

    HANDLE hMem;//дескриптор глобальной области памяти

    len = wcslen(buffer) + 1; // определение длины строки в формате юникода  

    hMem = GlobalAlloc(GMEM_MOVEABLE, len * sizeof(LPWSTR)); //выделение памяти в глобальной области видимости    

    memcpy(GlobalLock(hMem), buffer, len * sizeof(LPWSTR));// копирование области памяти из buffer в hMem

    GlobalUnlock(hMem); //разблокировать содержимое этой памяти (сделать доступным для других программ)

    OpenClipboard(0);//открыть буфер обмена

    EmptyClipboard();//очистить буфер обмена

    SetClipboardData(CF_UNICODETEXT, hMem);//записать в буфер обмена данные соответствующего типа

    CloseClipboard();//закрыть буфер обмена, сделать его доступным для других приложений    

    return 0;

}

int ClipboardOutputText()//считать информацию из системного буфера

{
   
    while (TRUE)
    {
        OpenClipboard(NULL);//открыть буфер обмена  

        LPWSTR Mess = (LPWSTR)GetClipboardData(CF_UNICODETEXT);//Считать из глобального участка памяти, привести это все к стороке
        char ad[2];
        ad[0] = Mess[0];
        ad[1] = '\0';
        int a = atoi(ad);
        LPWSTR answer;
        switch (a)
        {
        case 1:
            answer = L"Один";
            ClipboardInputText(answer);
            break;
        case 2:
            answer = L"Два";
            ClipboardInputText(answer);
            break;
        case 3:
            answer = L"Три";
            ClipboardInputText(answer);
            break;
        case 4:
            answer = L"Четыре";
            ClipboardInputText(answer);
            break;
        case 5:
            answer = L"Пять";
            ClipboardInputText(answer);
            break;
        case 6:
            answer = L"Шесть";
            ClipboardInputText(answer);
            break;
        case 7:
            answer = L"Семь";
            ClipboardInputText(answer);
            break;
        case 8:
            answer = L"Восемь";
            ClipboardInputText(answer);
            break;
        case 9:
            answer = L"Девять";
            ClipboardInputText(answer);
            break;

        }
        CloseClipboard();//закрыть буфер обмена, сделать его доступным для других приложений
        Sleep(100);
    }
    return 0;

}

