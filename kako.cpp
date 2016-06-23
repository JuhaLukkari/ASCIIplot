
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;


struct termi
{
  double kerroin;
  int potenssi;

};

vector<termi> termit;



struct yhtalo
{
	string piirtomerkkijono;
	vector<termi>termit;
	int maara;
};
vector<yhtalo> yhtaloita;


bool Derivoi(string &tiedosto,int &x,int &y,char &tyhja)
{

	string nimi=tiedosto+".derivaatat";        //uusi nimi tiedostolle
	string vali=" ";                           //laiskuus :E
	ofstream yhtalotD(nimi.c_str(), ios::out); //kirjoittamista varten

    if(!yhtalotD.is_open())                    //pystyttiinkö kirjoittamaan?
	{
	    cout<<"Virhe: Tiedostoon "<<nimi<<" ei voida kirjoittaa."<<endl;
		return EXIT_FAILURE;
	}

    yhtalotD<<tyhja<<vali<<x<<vali<<y<<endl;      //kirjoitetaan alkutiedot tiedostoon
    yhtalotD<<yhtaloita[1].piirtomerkkijono<<endl;
	
yhtalotD<<yhtaloita[0].termit[0].kerroin<<endl<<yhtaloita[0].termit[0].potenssi<<vali;
  return true;
}




void tulostaAlusta(int &leveys,int &korkeus,char &tyhja)
{

   
   
   int a=0;
   int f=0;
   int lev=leveys+1;
   int kork=korkeus+1;
   string apu(lev,tyhja);
   vector<string> piirtoalusta(kork,apu);
   int ascii;
   int miny=-(kork/2);
   int maxy=kork/2;
   int minx=-(lev/2);
   int maxx=(lev/2);

   //TODO:indeksoi "oikein" eli miinus on miinus vektorissa

	for(int i=0;i>=miny;i--)
	{
		ascii=48+f;//numero 0 ascii-koodina
	
	    piirtoalusta[i].at(0)=ascii;    //pistetään merkki
		piirtoalusta[i].at(leveys/2+1)='|';//y-akseli
		a++;
		f++;

			if(ascii==57)//numero 9 ascii-koodina
			{
				ascii=48;
				f=0;
			}
	}
  
	for(int l = minx;l < maxx;l++)//x-koordinaatti
	{
      
		  piirtoalusta[0].at(l)='-';
	
	}
	
	f=0;

	for(i=0;i<maxy;i++)
	{
		ascii=48+f;
        piirtoalusta[i].at(minx)=ascii;//pistetään merkki
        piirtoalusta[i].at(0)='|';//y-akseli
		f++;

            if(ascii==57)
			{
				ascii=48;
				f=0;
			}
	}

    piirtoalusta[0].at(0)='+';//merkki origoon vielä
	ascii=0; //seuraavaa vaihetta varten
    f=0;

	for(i=0;i<maxx;i++)
	{
      ascii=48+f;
      piirtoalusta[maxy].at(i)=ascii;
      f++;
		if(ascii==57)
		{
			ascii=48;
			f=0;
		}
    }
	f=0;

    for(i=0;i>minx;i--)
	{
      ascii=48+f;
      piirtoalusta[maxy].at(i)=ascii;
      f++;

	    if(ascii==57)
		{
			ascii=48;
			f=0;
		}
    }
         
    piirtoalusta[maxy].at(minx)=' ';
	
   


    int kayra;
	int y=0;
	int k=0;
	int v=0;
	ascii=0;
 /*  for(int x=0;x>minx;x--)///nyt piirtää käyriä ,Ahaa ,miinus merkkinen tilettää pitää muuttaa jotenkin ?
   {
       
     
  // y=pow((yhtaloita[0].termit[0].kerroin)*x,yhtaloita[0].termit[0].potenssi);
  
  ascii= static_cast<int> (yhtaloita[0].piirtomerkkijono[k]);//merkki
   piirtoalusta[x].at(y)=ascii;
   k++;
   if(k==yhtaloita[0].piirtomerkkijono.length())
	   k=0;
	  
   }
/*	for(int j=miny;j<maxy;j++)
	{	
		cout<<piirtoalusta[j]<<endl;  
	}*/
 
}



bool lueTiedosto(string &tiedosto,int &x,int &y,char &tyhja)
{
	
    
  ifstream yhtalot(tiedosto.c_str());
   
  if (!yhtalot.is_open())//jos tiedostoa ei löydy
  {
	  cout<<"Virhe: Tiedostoa "<<tiedosto<<" ei voida lukea."<<endl;
	  return EXIT_FAILURE;
	 		
  }
       
   	  
	  yhtalot.get(tyhja);//haetaan tyhja merkki
	  yhtalot>>x>>y;//alustan leveys ja korkeus
        
	  int i=0;
	  int l=0;
      int maara=0;
	  int f=0;
	  yhtalo yhtaloi;
	   


 while(!yhtalot.eof())
 {
   yhtalot>>yhtaloi.piirtomerkkijono>>yhtaloi.maara;
   
   termi termi;
      
      for(int j=0;j<yhtaloi.maara;j++)
	  {
		  
		  
		  yhtalot>>termi.kerroin>>termi.potenssi;
		 
		   termit.push_back(termi);
		   yhtaloi.termit=termit;
		    
		  
	  }
	   yhtaloita.push_back(yhtaloi);    //NYT TOIMII ÄLÄ KOSKE!!
	 termit.clear();
	    
 }

	return true;
}


int main()
{
    char derivointi;
    string tiedosto="";
    int leveys=0;	
    int korkeus=0;
	char tyhja;
    


  cout<<"### OHJ-1101 Ohjelmointi 1e"<<endl;
  cout<<"### Juha-Matti Lukkari"<<endl;
  cout<<"### 201745, Aut"<<endl;
  cout<<"Anna asetustiedoston nimi (oletuksena yhtalot.txt):";

  cin>>tiedosto;                                   //mikä tiedosto?
  lueTiedosto(tiedosto,leveys,korkeus,tyhja);      //luetaan tiedoston sisältö
  cout<<"Derivoidaanko? (k/e) ";                   //derivointi?
  cin>>derivointi;                                      
  
  
   Derivoi(tiedosto,leveys,korkeus,tyhja);         //Derivoidaan yhtälöt ja kirjoitetaan ne tiedostoon
   cout<<endl;
  tulostaAlusta(leveys,korkeus,tyhja);
 
	return EXIT_SUCCESS;

}


