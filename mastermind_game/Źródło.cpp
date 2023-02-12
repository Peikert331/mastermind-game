using namespace System;
int main(array<System::String^>^ args)
{
    Console::WriteLine(L"Gra MasterMind");
    Console::WriteLine(L"Odgadnij 4-elementowy kod sk³adaj¹cy siê z liter A,B,C,D,E,F");
    Console::WriteLine(L"x oznacza, ¿e pewien element znajduje siê na w³aœciwym miejscu");
    Console::WriteLine(L"o oznacza, ¿e pewien element wystêpuje w kodzie");
    String^ skoder = nullptr;
    String^ slamacz = nullptr;
    String^ sklucz = nullptr;
    String^ sk = nullptr;
    int i, j, runda;
    Random^ r = gcnew Random();
    for (i = 0; i < 4; i++)
    {
        skoder += wchar_t(65 + r->Next(6));
    }
    for (runda = 1; runda <= 6; runda++)
    {
        Console::WriteLine(L"Runda {0}: ", runda);
        Console::WriteLine(L"Podaj kod sk³adaj¹cy siê z czterech du¿ych liter A,B,C,D,E,F");
        slamacz = Console::ReadLine();
        while (slamacz->Length < 4)
            slamacz += slamacz + '$';
        array<wchar_t>^ lamacz = gcnew array<wchar_t>(4);
        slamacz->CopyTo(0, lamacz, 0, 4);
        sk = skoder;
        array<wchar_t>^ k = gcnew array<wchar_t>(4);
        sk->CopyTo(0, k, 0, 4);
        String^ sklucz = "";
        for (i = 0; i < 4; i++)
            if (k[i] == lamacz[i])
            {
                sklucz = sklucz + L"x";
                k[i] = '#';
                lamacz[i] = '$';
            }
        for (i = 0; i < 4; i++)
            if (k[i] != '#')
                for (j = 0; j < 4; j++)
                    if (k[i] == lamacz[j])
                    {
                        sklucz = sklucz + L"o";
                        lamacz[j] = '$';
                        break;
                    }
        Console::WriteLine(sklucz);
        if (sklucz == "xxxx")
        {
            Console::WriteLine(L"Brawo, odgad³eœ kod!");
            Console::WriteLine(L"Poprawny kod:{0}", skoder);
            Environment::Exit(0);
        }
    }
    Console::WriteLine(L"Przegra³eœ!");
    Console::WriteLine(L"Poprawny kod:{0}", skoder);
    Console::ReadKey();
    return 0;
}