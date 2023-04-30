#include<iostream>
#include<conio.h>
#include<dos.h>
#include<time.h>
#include<windows.h>

#define EKRAN_GENISLIGI 90
#define EKRAN_YUKSEKLIGI 26
#define WIN_GENISLIGI 70

using namespace std;


HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); 
COORD CursorPosition; // Kordinatlari tutan degiskendir


int DusmanY[3];
int DusmanX[3];
int DusmanAraba[3];
char araba[4][4] ={ ' ','#','#',' ', 
					'#','#','#','#', 
					' ','#','#',' ',
					'#','#','#','#' }; 

int arabaPozisyon = WIN_GENISLIGI/2;
int score = 0;

void gotoxy(int x , int y) // imleci x ve y koordinatlarina getirir

{

    CursorPosition.X = x;
    CursorPosition.Y = y;
    SetConsoleCursorPosition(console,CursorPosition);

}


void setcursor(bool visible, DWORD size) // imlec gorunurlugu ve boyutunu ayarlar

{

    if(size == 0)

        size = 20;

    CONSOLE_CURSOR_INFO lpCursor;

    lpCursor.bVisible = visible;
    lpCursor.dwSize = size;

    SetConsoleCursorInfo(console,&lpCursor);

}

void ekraniCiz()

{

    for(int i=0;i<EKRAN_YUKSEKLIGI;i++) //EKRANIN ÜST VE ALTİNİ CİZER

    {

        for(int j=0;j<17;j++) // EKRANNIN ÜSTÜNÜ CİZER

        {

            gotoxy(j,i);// EKRANIN ÜSTÜNÜ CİZER
            cout<<"±"; // EKRANIN ÜSTÜNÜ CİZER
            gotoxy(EKRAN_GENISLIGI-j,i); // EKRANIN ALTINI CİZER
            cout<<"±";// EKRANIN ALTINI CİZER



        }


    }

    for(int i=0;i<EKRAN_YUKSEKLIGI;i++)

    {
        gotoxy(EKRAN_GENISLIGI,i);
        cout<<"±";

    }

}

void DusmanAraci(int index)

{

    DusmanX[index] = 17 +rand()%(33);

}

void DusmanAraciCiz(int index)

{

  if(DusmanAraba[index] == true)

  {

    gotoxy(DusmanX[index],DusmanY[index]);
    cout<<"****";  

    gotoxy(DusmanX[index],DusmanY[index]+1);
     cout<<" ** "; 

    gotoxy(DusmanX[index],DusmanY[index]+2);
    cout<<"****"; 

    gotoxy(DusmanX[index],DusmanY[index]+3);
    cout<<" ** ";  

  }

}

void DusmanAraciSil(int index)

{

    if(DusmanAraba[index] == true)

    {

        gotoxy (DusmanX[index],DusmanY[index]);
        cout<<"    "; 
        gotoxy (DusmanX[index],DusmanY[index]+1);
        cout<<"    "; 
        gotoxy (DusmanX[index],DusmanY[index]+2);
        cout<<"    "; 
        gotoxy (DusmanX[index],DusmanY[index]+3);
        cout<<"    "; 

    }

}

void DusmanAraciSifirla(int index)

{

    DusmanAraciSil(index); // Dusman aracini siler
    DusmanY[index] = 1; // Yeni bir araC oluSturur
    DusmanAraci(index); // Yeni bir araC oluSturur

}

void ArabaCiz()

{

    for(int i=0;i<4;i++)

    {

        for(int j=0;j<4;j++)

        {

            gotoxy(arabaPozisyon+j,i+22); // Araba pozisyonunu belirler j yatay pozisyonu i dikey pozisyonu 22 ise arabanin yuksekligini belirler
            cout<<araba[i][j];

        }
    }

}

void ArabaSil()

{

    for(int i=0;i<4;i++)

    {

        for(int j=0;j<4;j++)

        {

            gotoxy(arabaPozisyon+j,i+22); // Araba pozisyonunu belirler j yatay pozisyonu i dikey pozisyonu 22 ise arabanin yuksekligini belirler
            cout<<" ";

        }
    }

}

int carpisma()

{

    if(DusmanY[0]+4 >=23)

    {

        if(DusmanX[0] + 4 - arabaPozisyon >= 0 && DusmanX[0] + 4 - arabaPozisyon < 9)

        {

            return 1;

        }

    }

    return 0;


}

void gameover()

 {

    system("cls"); 
    cout<<"\t\t--------------------------"<<endl;
    cout<<"\t\t|        Game Over       |"<<endl;
    cout<<"\t\t--------------------------"<<endl;
    cout<<"\t\t Lutfen Menuye Donmek Icin Bir Tusa Basiniz";
    getch();

 }

 void ScoruGuncelle()

 {

    gotoxy(WIN_GENISLIGI+7,5);
    cout<<"Score: "<<score;


 }

 void Bilgiler()

 {

    system("cls");
    cout<<"Bilgiler";
    cout<<"\n--------------------------";
    cout<<"\nOyunun amaci dusman araclariyla carpmamaktir.";
    cout<<"\n\n A'ya Basarsaniz Sol Tarafa Gider";
    cout<<"\n D'ye Basarsaniz Sag Tarafa Gider";
    cout<<"\n Menuye Donmek Icin Herhangi Bir Tusa Basiniz";
    getch();

 }

  void Oyna()

  {

    arabaPozisyon = -1 + WIN_GENISLIGI/2;
    score = 0;
    DusmanAraba[0] = 1;  // Dusman Araclari Baslangicta ilk iki sirada
    DusmanAraba[1] = 1; // Dusman Araclari Baslangicta ilk iki sirada
    DusmanY[0] = DusmanY[1] = 1; // Dusman Araclari Baslangicta ilk iki sirada

    system("cls");
    ekraniCiz();
    ScoruGuncelle();
    DusmanAraci(0);
    DusmanAraci(1);

    gotoxy(WIN_GENISLIGI+7,2);  // 7 yatay 2 dikey
    cout<<"Car Game";
    gotoxy(WIN_GENISLIGI+6,4); // 6 yatay 4 dikey
    cout<<"----------";
    gotoxy(WIN_GENISLIGI+6,6); // 6 yatay 6 dikey
    cout<<"----------";
    gotoxy(WIN_GENISLIGI+7,12); // 7 yatay 12 dikey
    cout<<"Kontrol ";
    gotoxy(WIN_GENISLIGI+7,13); // 7 yatay 13 dikey
    cout<<"-------- ";
    gotoxy(WIN_GENISLIGI+2,14); // 2 yatay 14 dikey
    cout<<" A TUSU  - SOL";
    gotoxy(WIN_GENISLIGI+2,15); // 2 yatay 15 dikey
    cout<<" D TUSU -  SAG";

    gotoxy(18 , 5);
    cout<<"Oyunu Baslatmak Icin Bir Tusa Basiniz";
    getch();
    gotoxy(18 , 5);
    cout<<"                                  ";

    while(1) 

    {

        if(kbhit()) // Klavyeden Bir Tusa Basildiysa Eger

        {

            char ch = getch();

            if (ch=='a' || ch=='A')

            {

                if(arabaPozisyon > 18) // Araba pozisyonu 18 den buyukse


                    arabaPozisyon -= 4; // Araba pozisyonunu 4 azalt

                
            }



            if(ch=='d' || ch=='D') // D ye basildiysa

            {
                
                if(arabaPozisyon < 50) // Araba pozisyonu 50 den kucukse

                    arabaPozisyon += 4;


            }

            if(ch==27)

            {

                break;

            }
        }

    
    
    ArabaCiz();
    DusmanAraciCiz(0);
    DusmanAraciCiz(1);

    if(carpisma() == 1)

    {

        gameover();
        return ;

    }

    Sleep(50);
    ArabaSil();
    DusmanAraciSil(0);
    DusmanAraciSil(1);
   
    if(DusmanY[0] == 10)

    if (DusmanAraba[1] == 0)

        DusmanAraba[1] = 1;
        
    if(DusmanAraba[0] == 1)

        DusmanY[0]++;

        if(DusmanAraba[1] == 1)

        DusmanY[1]++;

        if(DusmanY[0] > EKRAN_YUKSEKLIGI-4)

        {

            DusmanAraciSifirla(0);
            score++;
            ScoruGuncelle();


        }

        if(DusmanY[1] > EKRAN_YUKSEKLIGI-4)

        {

            DusmanAraciSifirla(1);
            score++;
            ScoruGuncelle();

        }

  }


 }

int main()

{

    setcursor(0,0);
    srand(time(NULL));

    do 

    {
        

        system("color 4");
        system("cls");
        gotoxy(10,5); cout<<" -------------------------- "; 
		gotoxy(10,6); cout<<" |        Car Game        | "; 
		gotoxy(10,7); cout<<" --------------------------";
		gotoxy(10,9); cout<<"1. Oyunu Baslat";
		gotoxy(10,10); cout<<"2. Bilgiler";	 
		gotoxy(10,11); cout<<"3. Cikis";
		gotoxy(10,13); cout<<"Seciminiz: ";
		char secim = getche();
		
		if( secim=='1') 
        Oyna();

		else if( secim=='2') 
        Bilgiler();

		else if( secim=='3') 
        exit(0);
		
	}
    
    while(1);
	
	return 0;
}
        
    

