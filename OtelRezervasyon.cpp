#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <exception>
#include <conio.h>
#include <cctype>
#include <limits>

 
using namespace std;

class Tarih{
public:
	int gun;
	int ay;
	int yil;
};

class Misafir{
	private:
    	long long int telNo;
    	long long int tcNo;
    	int odemeTercihi;
    	
	public:
		string ad;
		string soyad;
        class Tarih targiris;	
		class Tarih tarcikis;	
		void telSetter(long long int a){
			telNo = a;
		}
		void tcSetter(long long int b){
			tcNo = b;
		}
		void odemeSetter(int c){
			odemeTercihi = c;
		}
		long long int telGetter(){
			return telNo;
		}
		long long int tcGetter(){
			return tcNo;
		}
		int odemeGetter(){
			return odemeTercihi;
		}
};

class Oda{
	protected:
		int fiyat;
		int kapiSifresi;
		int kartSayisi;
		
	public:
		class Misafir mis;
		int odaTip;
		int odaNumara;
		int odaDurum;
		Oda odaEkle(int);
		void odaAra(int);
		void odaGoster(int);
		void fiyatSetter(int a){
			fiyat = a;
		}	
		void kapiSetter(int b){
			kapiSifresi = b;
		}	
		void kartSetter(int c){
			kartSayisi = c;
		}	
		int fiyatGetter(){
			return fiyat;
		}
		int kapiGetter(){
			return kapiSifresi;
		}
		int kartGetter(){
			return kartSayisi;
		}
		virtual void Guncelle(int);//oda güncelle fonksiyonu
	
};
vector<Oda> odalarim(20);
int count = 0;

class OtelYonetim : protected Oda{
	public:	    
		void check_in();
	    void bosOdaBul();
	    void misafirAra(string);
	    void check_out(int);
	    void gunlukKazanc();
	    void rezerveKontrol();
	    	
	    void Guncelle(int);//misafir güncelle fonksiyonu
		void odaBilgileriniDosyayaYaz();
		void odaBilgileriniDosyadanOku();
};
int istisna(int k){
	try{
		if(isdigit(k)==0 && k>6 && k<=0)
			throw k;
		else
			return k;
	}
	catch(...){
		cout<<"1 ile 6 arasinda bir sayi giriniz.";
		return 0;
	}
}
    void Oda::Guncelle(int i){
	int a,b,c,Catch;
	int secim;
	char cevap;
	do{
	do{
	int secim;
	cout<<"\n(1)Odanin numarasi ";
	cout<<"\n(2)Odanin tipi ";
	cout<<"\n(3)Oda durumu ";
	cout<<"\n(4)Kart sayisi ";
	cout<<"\n(5)Fiyati ";
	cout<<"\n(6)Kapi Sifresi ";
	cout<<"\nDegistirmek istediginiz ozelligi tuslayiniz : ";
	do{
		Catch = 0;
		try{
			cin >> secim;
			if(cin.fail() || secim <= 0 || secim > 6){
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			throw secim;
			}
		}
		catch(...){
			cout<<"Lutfen istenen degeri giriniz : ";
			Catch = 1;
		}
	}while(Catch == 1);
	if(istisna(secim)!=0){
		if(secim == 1){
			do{
			Catch = 0;
			cout<<"\nYeni oda numarasini giriniz (Maksimum 2 basamakli) : ";
			try{
				cin >> odalarim[i].odaNumara;
				if(cin.fail() || odalarim[i].odaNumara <= 0 || odalarim[i].odaNumara > 99){
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				throw odalarim[i].odaNumara;
				}
			}
			catch(...){
				cout<<"Lutfen istenen degeri giriniz !";
				Catch = 1;
			}
			}while(Catch == 1);
		}
		if(secim == 2){
			do{
			Catch = 0;
			cout<<"\nYeni oda tipini giriniz : ";
			try{
				cin >> odalarim[i].odaTip;
				if(cin.fail() || odalarim[i].odaTip != 2 && odalarim[i].odaTip != 3){
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				throw odalarim[i].odaTip;
				}
			}
			catch(...){
				cout<<"Lutfen istenen degeri giriniz !";
				Catch = 1;
			}
			}while(Catch == 1);
			
		}
		if(secim == 3){
			do{
			Catch = 0;
			cout<<"\nYeni oda durumunu giriniz : ";
			try{
				cin >> odalarim[i].odaDurum;
				if(cin.fail() || odalarim[i].odaDurum != 1 && odalarim[i].odaDurum != 0){
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				throw odalarim[i].odaDurum;
				}
			}
			catch(...){
				cout<<"Lutfen istenen degeri giriniz !";
				Catch = 1;
			}
			}while(Catch == 1);
		}
		if(secim == 4){
			do{
			Catch = 0;
			cout<<"\nYeni kart sayisini giriniz (Maksimum 5 tane) : ";
			try{
				cin >> a;
				if(cin.fail() || a > 5 || a < 1){
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				throw a;
				}
			}
			catch(...){
				cout<<"Lutfen istenen degeri giriniz !";
				Catch = 1;
			}
			}while(Catch == 1);
			odalarim[i].kartSetter(a);
		}
		if(secim == 5){
			do{
			Catch = 0;
			cout<<"\nYeni oda fiyatini giriniz (Maksimum 4 basamakli) : ";
			try{
				cin >> b;
				if(cin.fail() || b > 9999 || b < 1000 ){
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				throw b;
				}
			}
			catch(...){
				cout<<"Lutfen istenen degeri giriniz !";
				Catch = 1;
			}
			}while(Catch == 1);
			odalarim[i].fiyatSetter(b);
		}
		if(secim == 6){
			do{
			Catch = 0;
			cout<<"\nYeni kapi sifresini giriniz (Maksimum 4 basamakli) : ";
			try{
				cin >> c;
				if(cin.fail() || c > 9999 || c < 1000){
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				throw c;
				}
			}
			catch(...){
				cout<<"Lutfen istenen degeri giriniz !";
				Catch = 1;
			}
			}while(Catch == 1);
			odalarim[i].kapiSetter(c);
		}
		cout<<"\nGuncellemeye devam etmek istiyor musunuz (e/h) : ";
		do{
			Catch = 0;
			try{
				cin >> cevap;
				if(cin.fail()){
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				throw cevap;
				}
			}
			catch(...){
				cout<<"Lutfen istenen degeri giriniz !";
				Catch = 1;
			}
		}while(Catch == 1);
	}
	}while(istisna(secim)==0);
	}while(cevap == 'e' || cevap == 'E');
	
	remove("oda.txt");
 	ofstream odaFile("oda.txt",ios::app);
	
	if(!odaFile) {
        cout << "oda txt dosyasi acilamadi" << endl;  
    }
	for(i = 0; i<count; i++){
		odaFile<<"Oda numarasi : "<<odalarim[i].odaNumara<<endl;
		odaFile<<"Oda tipi : "<<odalarim[i].odaTip<<endl;
		odaFile<<"Oda durumu : "<<odalarim[i].odaDurum<<endl;
		odaFile<<"Kart sayisi : "<<odalarim[i].kartGetter()<<endl;
		odaFile<<"Oda fiyati : "<<odalarim[i].fiyatGetter()<<endl;
		odaFile<<"Kapi sifresi : "<<odalarim[i].kapiGetter()<<endl;
		odaFile<<endl;
	}
	odaFile.close();
}

int istisna2(int k){
	try{
		if(k>11 || k<1)
		throw k;
	else
	return k;
	}
	catch(...){
		cout<<"1 ile 11 arasinda bir sayi giriniz.";
		return 0;
	}
}

void OtelYonetim::Guncelle(int i){

    int Catch;
    long long int a;
    long long int b;
    int c;
    int secim;
    char cevap;

    do {
        do {
            cout << "\n(1) Misafir Adi ";
            cout << "\n(2) Misafir Soyadi ";
            cout << "\n(3) Rezerve baslangic yili ";
            cout << "\n(4) Rezerve baslangic ayi ";
            cout << "\n(5) Rezerve baslangic gunu ";
            cout << "\n(6) Rezerve bitis yili ";
            cout << "\n(7) Rezerve bitis ayi ";
            cout << "\n(8) Rezerve bitis gunu ";
            cout << "\n(9) Misafir Telefon No ";
            cout << "\n(10) Misafir Tc No ";
            cout << "\n(11) Misafir Odeme Tercihi ";
            cout << "\nDegistirmek istediginiz ozelligi tuslayiniz: ";
            do{
				try{
					cin >> secim;
					if(cin.fail() || secim <= 0 || secim > 11){
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					throw secim;
				}
					else;
					Catch = 0;
				}
				catch(...){
					cout<<"Lutfen istenen degeri giriniz : ";
					Catch = 1;
			    }
			}while(Catch == 1);

            if (istisna2(secim) != 0) { // Fonksiyon 0'dan baþka bir deðer döndürüyorsa hata yoktur.
                switch (secim) {
                    case 1:
                     cout << "\n Misafir Yeni adini giriniz: ";
                       do {
                          try {
                          cin >> odalarim[i].mis.ad;
                          if (cin.fail() || odalarim[i].mis.ad.empty() || !isalpha(odalarim[i].mis.ad[0])) {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                          throw odalarim[i].mis.ad;
                     } else {
                    Catch = 0;
                   }
            } catch (...) {
            cout << "Lutfen istenen degeri giriniz: ";
            Catch = 1;
          }
         } while (Catch == 1);
          break;

                    case 2:
                     cout << "\n Misafir Yeni soyadini giriniz: ";
                       do {
                           try {
                           cin >> odalarim[i].mis.soyad;
                           if (cin.fail() || odalarim[i].mis.soyad.empty() || !isalpha(odalarim[i].mis.soyad[0])) {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                          throw odalarim[i].mis.soyad;
                     } else {
                    Catch = 0;
                  }
            } catch (...) {
            cout << "Lutfen istenen degeri giriniz: ";
            Catch = 1;
           }
          } while (Catch == 1);
           break;

                    case 3:
                        do {
                            cout << "\n Yeni Rezerve baslangic yili: ";
                            cin >> odalarim[i].mis.targiris.yil;
                            try {
                                if (odalarim[i].mis.targiris.yil < 2024) {
                                    throw odalarim[i].mis.targiris.yil;
                                } else {
                                    Catch = 0;
                                }
                            } catch (...) {
                                cout << "\n Lutfen yili dogru girin.";
                                Catch = 1;
                            }
                        } while (Catch == 1);
                        break;
                    case 4:
                        do {
                            cout << "\n Yeni Rezerve baslangic ayi: ";
                            cin >> odalarim[i].mis.targiris.ay;
                            try {
                                if (odalarim[i].mis.targiris.ay == 0 || odalarim[i].mis.targiris.ay > 12) {
                                    throw odalarim[i].mis.targiris.ay;
                                } else {
                                    Catch = 0;
                                }
                            } catch (...) {
                                cout << "\n Lutfen ayi dogru girin.";
                                Catch = 1;
                            }
                        } while (Catch == 1);
                        break;
                    case 5:
                        do {
                            cout << "\n Yeni Rezerve baslangic gunu: ";
                            cin >> odalarim[i].mis.targiris.gun;
                            try {
                                if (odalarim[i].mis.targiris.gun == 0 || odalarim[i].mis.targiris.gun > 31) {
                                    throw odalarim[i].mis.targiris.gun;
                                } else {
                                    Catch = 0;
                                }
                            } catch (...) {
                                cout << "\n Lutfen gunu dogru girin.";
                                Catch = 1;
                            }
                        } while (Catch == 1);
                        break;
                    case 6:
                        do{
	                     cout<<"\nYeni Rezerve Bitis Yili : ";
	                     cin>>odalarim[i].mis.tarcikis.yil;
	                     try{
		                  if(cin.fail() || odalarim[i].mis.tarcikis.yil<odalarim[i].mis.targiris.yil || odalarim[i].mis.tarcikis.yil>2025){
		                   cin.clear();
		                   cin.ignore(numeric_limits<streamsize>::max(), '\n');
		                   throw odalarim[i].mis.tarcikis.yil;	
		                  }
		                  else
		                   Catch=0;	
	                      }
	                     catch(...){
		                  cout << "\n Gecerli yil girin: ";
		                  Catch=1;
	                     }
                        }while(Catch==1);
                        break;
                    case 7:
                        do{
	                     cout<<"\nYeni Rezerve Bitis Ayi :  ";
	                     cin>>odalarim[i].mis.tarcikis.ay;	
		                 try{
		                  if(odalarim[i].mis.targiris.yil == odalarim[i].mis.tarcikis.yil){
			               if(cin.fail() || odalarim[i].mis.tarcikis.ay>12 || odalarim[i].mis.tarcikis.ay<odalarim[i].mis.targiris.ay ){
			                cin.clear();
			                cin.ignore(numeric_limits<streamsize>::max(), '\n');
			                throw odalarim[i].mis.tarcikis.ay;	
			               }
		                  }	
		                  if(odalarim[i].mis.targiris.yil != odalarim[i].mis.tarcikis.yil){
		                   if(cin.fail() || odalarim[i].mis.tarcikis.ay>12 || odalarim[i].mis.tarcikis.ay<=0 ){
			                cin.clear();
			                cin.ignore(numeric_limits<streamsize>::max(), '\n');
			                throw odalarim[i].mis.tarcikis.ay;	
			               }
		                  }
		                  else{
		                   Catch=0;
		                  }	
	                     }
	                     catch(...){
		                  cout << "\n Lutfen gecerli bir ay girin:";
		                  Catch=1;
	                     }
	                    }while(Catch==1);
	                    break;
                    case 8:
                        do{
    	                 cout << "\nYeni Rezerve bitis gunu: ";
                         cin >> odalarim[i].mis.tarcikis.gun;
                         try {
                          if(odalarim[i].mis.targiris.ay == odalarim[i].mis.tarcikis.ay ){
        	               if (cin.fail() || odalarim[i].mis.tarcikis.gun < odalarim[i].mis.targiris.gun || odalarim[i].mis.tarcikis.gun > 31){
        	                cin.clear();
			                cin.ignore(numeric_limits<streamsize>::max(), '\n');
			                throw odalarim[i].mis.tarcikis.gun;	
			               }
		                  }
                          if(odalarim[i].mis.targiris.ay != odalarim[i].mis.tarcikis.ay){
        	               if (cin.fail() || odalarim[i].mis.tarcikis.gun <= 0 || odalarim[i].mis.tarcikis.gun > 31){
        	                cin.clear();
			                cin.ignore(numeric_limits<streamsize>::max(), '\n');
			                throw odalarim[i].mis.tarcikis.gun;	
			               }
		                  }
                          else{
        	               Catch=0;
		                  }
                         } 
		                 catch (...) {
                          cout << "\n Lutfen gunu dogru girin.";
                          Catch = 1;
                         }
	                    }while(Catch==1);
                        break;
                    case 9:
                        cout << "\n Misafir Yeni Tel No : ";
                        do{
						try{
							cin >> a;
							if(cin.fail() || a > 5999999999 || a < 5000000000){
								cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							throw a;
							}
							else 
							Catch = 0;
						}
						catch(...){
							cout<<"Lutfen istenen degeri giriniz : ";
							Catch = 1;
							}
						}while(Catch == 1);
						odalarim[i].mis.telSetter(a);
                        break;
                    case 10:
                        cout << "\n Misafir Yeni Tc No: ";
                        do{
						try{
							cin >> b; 
							if(cin.fail() || b > 99999999999 || b < 10000000000){
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							throw b;
						}
							else
							Catch = 0;
						}
						catch(...){
							cout<<"Lutfen istenen degeri giriniz : ";
							Catch = 1;
						}
						}while(Catch == 1);
                        odalarim[i].mis.tcSetter(b);
                        
                        break;
                    case 11:
                        do {
                            cout << "\n Misafir Yeni Odeme Tercihi (Kredi Karti = 1 / Nakit = 2): ";
                            cin >> c;
                            try {
                                if (c != 1 && c != 2) {
                                    throw c;
                                } else {
                                    odalarim[i].mis.odemeSetter(c);
                                    Catch = 0;
                                }
                            } catch (...) {
                                cout << "Lutfen 1 veya 2 girin: ";
                                Catch = 1;
                            }
                        } while (Catch == 1);
                        break;
                    default:
                        cout << "Gecersiz secim. Lutfen tekrar deneyin.";
                        break;
                }
            } else {
                cout << "Gecersiz secim. Lutfen tekrar deneyin.";
            }

            cout << "\nGuncellemeye devam etmek istiyor musunuz? (e/h): ";
            do{
			Catch = 0;
				try{
					cin >> cevap;
					if(cin.fail()){
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				throw cevap;
				}
			}
			catch(...){
				cout<<"Lutfen istenen degeri giriniz : ";
				Catch = 1;
			}
		}while(Catch == 1);
    } while (cevap == 'E' || cevap == 'e');
 } while (istisna2(secim) == 0);
 
 remove("misafir.txt");

	ofstream misFile("misafir.txt",ios::app);
	if(!misFile) {
        cout << "misafir txt dosyasi acilamadi" << endl;  
    }
	for(i = 0; i<count; i++){
		misFile<<"oda no: "<<odalarim[i].odaNumara<<endl;
		misFile<<"misafir adi: "<<odalarim[i].mis.ad<<endl;
		misFile<<"misafir soyadi: "<<odalarim[i].mis.soyad<<endl;
		misFile<<"rezerve baslangic gun: "<<odalarim[i].mis.targiris.gun<<endl;
		misFile<<"rezerve baslangic ay: "<<odalarim[i].mis.targiris.ay<<endl;
		misFile<<"rezerve baslangic yil: "<<odalarim[i].mis.targiris.yil<<endl;
		misFile<<"rezerve bitis gun: "<<odalarim[i].mis.tarcikis.gun<<endl;
		misFile<<"rezerve bitis ay: "<<odalarim[i].mis.tarcikis.ay<<endl;
		misFile<<"rezerve bitis yil: "<<odalarim[i].mis.tarcikis.yil<<endl;
		misFile<<"telefon no: "<<odalarim[i].mis.telGetter()<<endl;
		misFile<<"T.C. kimlik no: "<<odalarim[i].mis.tcGetter()<<endl;
		misFile<<"odeme tercihi: "<<odalarim[i].mis.odemeGetter()<<endl;
		misFile<<endl;
	}
	misFile.close();
}

void Oda::odaGoster(int i){
	cout<<"\nOda Numarasi : "<<odalarim[i].odaNumara; 
	cout<<"\nOda Tipi : "<<odalarim[i].odaTip;
	cout<<"\nOda Durumu : "<<odalarim[i].odaDurum; // Rezerve kontrol.
	cout<<"\nKart Sayisi : "<<odalarim[i].kartGetter(); // Setter, Getter
	cout<<"\nFiyati : "<<odalarim[i].fiyatGetter();	
	cout<<"\nKapi Sifresi : "<<odalarim[i].kapiGetter();
}
Oda Oda::odaEkle(int odaNo){
	class Oda oda;
	int a,b,c,Catch;
	oda.odaNumara=odaNo;
	
	cout<<"\niki kisilik mi/ uc kisilik mi(2/3)? : "; // KÝÞÝ SAYISI BELÝRLEME
	do{
		Catch = 0;
		try{
			cin>>oda.odaTip;
			if(cin.fail() || oda.odaTip != 2 && oda.odaTip != 3){
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			throw oda.odaTip;
			}
		}
		catch(...){
			cout<<"Lutfen istenen degeri giriniz : ";
			Catch = 1;
		}
	}while(Catch == 1);
	
	cout<<"\nodanin gunluk fiyati ne kadar? (4 basamak) : "; // FÝYAT ALMA
	do{
		Catch = 0;
		try{
			cin>>a;
			if(cin.fail() || a > 9999 || a < 1000 ){
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			throw a;
			}
		}
		catch(...){
			cout<<"Lutfen istenen degeri giriniz : ";
			Catch = 1;
		}
	}while(Catch == 1);
	oda.fiyatSetter(a);
	
	cout<<"\nKapi sifresini belirleyiniz ( _ _ _ _ ) : ";  // KAPI SÝFRESÝ ALMA
	do{
		Catch = 0;
		try{
			cin>>b;
			if(cin.fail() || b > 9999 || b < 1000){
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			throw b;
			}
		}
		catch(...){
			cout<<"Lutfen istenen degeri giriniz : ";
			Catch = 1;
		}
	}while(Catch == 1);
	oda.kapiSetter(b);
	
	cout<<"\nkac kart verilecek (Maksimum 5 tane) : "; // KART SAYISI ALMA
	do{
		Catch = 0;
		try{
			cin>>c;
			if(cin.fail() || c > 5 || c < 1){
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			throw c;
			}
		}
		catch(...){
			cout<<"Lutfen istenen degeri giriniz : ";
			Catch = 1;
		}
	}while(Catch == 1);
	oda.kartSetter(c);
	
	oda.odaDurum=0;

	cout<<"\nOda basariyla eklendi !";
	ofstream odaFile("oda.txt",ios::app);
	if(!odaFile) {
        cout << "oda txt dosyasi acilamadi" << endl;  
    }
	
	odaFile << "\nOda numarasi : " << oda.odaNumara;
	odaFile << "\nOda tipi : " << oda.odaTip;
	odaFile << "\nOda durumu : " << oda.odaDurum;
	odaFile << "\nKart sayisi : " << oda.kartGetter();
	odaFile << "\nOda fiyati : " << oda.fiyatGetter();
	odaFile << "\nKapi sifresi : " << oda.kapiGetter();
	odaFile << "\n---------------------------\n";
	odaFile.close();
	
	return oda;	
	
	
}

void Oda::odaAra(int odaNo){ 
	int i,k=0,musait = 0;
	char cevap;
	int Catch=0;
	for(i=0;i<count;i++)
	{
	if(odalarim[i].odaNumara==odaNo)
	{
	k=1;
	break;
	}
	}
	if(k==1)
	{
	cout<<"Oda detaylari\n";
	if(odalarim[i].odaDurum==1)
	{
	cout<<"\nOda musait degil";
	}
	else
	{
	cout<<"\nOda musait";
	musait = 1;
	}
	Oda::odaGoster(i);
	}
	if(musait == 1){
		cout<<"\nBilgileri guncellemek ister misiniz (e/h)?";
		do{
		    try{
	            cin >> cevap; // guncelle fonksiyonu cagirilacak
	            if(cin.fail() ||(cevap!='e'&&cevap!='E'&&cevap!='h'&&cevap!='H')){
	            	cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
	            	throw cevap;
				}
				else{
					Catch=0;
				}
			}
			catch(...){
				cout<<"lutfen belirtilen harfleri giriniz."<<endl;
				Catch=1;
			}
		}while(Catch==1);

		if(cevap == 'e'||cevap=='E'){
			class OtelYonetim ott;
			odalarim[i].Guncelle(i);
		}
	}
	else
	{
	cout<<"\nOda bulunamadi";
	}
}

void OtelYonetim::gunlukKazanc(){
	if(count==0){
	cout<<"\n Misafir Bulunamadi ";
	}	
	int toplam = 0;
	for(int i=0;i<count;i++)
	{
		try{
			if(odalarim[i].odaDurum==1) {
                cout<<"\nMisafirin Ýsmi : "<<odalarim[i].mis.ad;
                cout<<"\nMisafirin Soy Ýsmi : "<<odalarim[i].mis.soyad;
                cout<<"\nOda Numarasi : "<<odalarim[i].odaNumara;
                cout<<"\nGunluk Gelir : "<<odalarim[i].fiyatGetter(); 
                cout<<"\n---------------------------------------\n";   
                toplam = toplam + odalarim[i].fiyatGetter();
            }
		} catch (...) {
            cout << "\nHata olustu!";
  }
  
}
cout<< "Gunluk toplam gelir : " << toplam << endl;
}

void OtelYonetim::check_in(){
	int i,k=0,odaNo;
	int Catch=1;
	long long int a,b;
	int c;
	class Oda oda;
	cout<<"\nOda Numaranizi Giriniz : ";
	cin>>odaNo;
	for(i=0;i<count;i++)
	{
	if(odalarim[i].odaNumara==odaNo)
	{
	k=1;
	break;
	}
	}
	if(k==1)
	{
	if(odalarim[i].odaDurum==1) // Rezervasyon sistemi kullanýlmasý lazým
	{
	cout<<"\nOda Dolu.";
	return;
    }
	cout<<"\nAdinizi giriniz : ";
	while(Catch == 1){
		try{
			cin>>odalarim[i].mis.ad;
			if(cin.fail()){
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			throw odalarim[i].mis.ad;
			}
			else;
			Catch = 0;
		}
		catch(...){
			cout<<"Lutfen istenen degeri giriniz : ";
			Catch = 1;
		}
	}

	cout<<"\nSoy adinizi giriniz : ";
	do{
		try{
			cin>>odalarim[i].mis.soyad;
			if(cin.fail()){
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			throw odalarim[i].mis.soyad;
			}
			else;
			Catch = 0;
		}
		catch(...){
			cout<<"Lutfen istenen degeri giriniz : ";
			Catch = 1;
		}
	}while(Catch == 1);
	
	do{
	cout<<"\nRezerve Baslangic Yili : ";
	cin>>odalarim[i].mis.targiris.yil;	
	try{
		if(cin.fail() || odalarim[i].mis.targiris.yil<2024 || odalarim[i].mis.targiris.yil>2025 ){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		throw odalarim[i].mis.targiris.yil;	
		}
		else
		Catch=0;
	}
	catch(...){
		cout << "\n Lutfen gecerli bir yil girin:";
		Catch=1;
	}
	}while(Catch == 1);
	do{
	cout<<"\nRezerve Baslangic Ayi :  ";
	cin>>odalarim[i].mis.targiris.ay;	
		try{
		if(cin.fail() || odalarim[i].mis.targiris.ay>12 || odalarim[i].mis.targiris.ay<=0 ){ 
	    cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		throw odalarim[i].mis.targiris.ay;
		} // burda && kullanýlmaz ay hem 0 dan küçük hem de 12 den büyük olamaz.	
		else
		Catch=0;
	}
	catch(...){
		cout << "\n Lutfen gecerli bir ay girin:";
		Catch=1;
	}
	}while(Catch==1);

	do{
    	cout << "\n Rezerve baslangic gunu: ";
        cin >> odalarim[i].mis.targiris.gun;
        try {
        if (cin.fail() || odalarim[i].mis.targiris.gun <=0 || odalarim[i].mis.targiris.gun > 31){
        cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		throw odalarim[i].mis.targiris.gun;	
		}
		else
        Catch = 0;
        } catch (...) {
        cout << "\n Lutfen gunu dogru girin.";
        Catch = 1;
        }
	}while(Catch==1);
	do{
	cout<<"\nRezerve Bitis Yili : ";
	cin>>odalarim[i].mis.tarcikis.yil;
	try{
		if(cin.fail() || odalarim[i].mis.tarcikis.yil<odalarim[i].mis.targiris.yil || odalarim[i].mis.tarcikis.yil>2025){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		throw odalarim[i].mis.tarcikis.yil;	
		}
		else
		Catch=0;	
	}
	catch(...){
		cout << "\n Gecerli yil girin: ";
		Catch=1;
	}
}while(Catch==1);
	
	do{
	cout<<"\nRezerve Bitis Ayi :  ";
	cin>>odalarim[i].mis.tarcikis.ay;	
		try{
		if(odalarim[i].mis.targiris.yil == odalarim[i].mis.tarcikis.yil){
			if(cin.fail() || odalarim[i].mis.tarcikis.ay>12 || odalarim[i].mis.tarcikis.ay<odalarim[i].mis.targiris.ay ){
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			throw odalarim[i].mis.tarcikis.ay;	
			}
		}	
		if(odalarim[i].mis.targiris.yil != odalarim[i].mis.tarcikis.yil){
			if(cin.fail() || odalarim[i].mis.tarcikis.ay>12 || odalarim[i].mis.tarcikis.ay<=0 ){
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			throw odalarim[i].mis.tarcikis.ay;	
			}
		}
		else{
		Catch=0;
		}	
	}
	catch(...){
		cout << "\n Lutfen gecerli bir ay girin:";
		Catch=1;
	}
	}while(Catch==1);

	do{
    	cout << "\n Rezerve bitis gunu: ";
        cin >> odalarim[i].mis.tarcikis.gun;
        try {
        if(odalarim[i].mis.targiris.ay == odalarim[i].mis.tarcikis.ay ){
        	if (cin.fail() || odalarim[i].mis.tarcikis.gun < odalarim[i].mis.targiris.gun || odalarim[i].mis.tarcikis.gun > 31){
        	cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			throw odalarim[i].mis.tarcikis.gun;	
			}
		}
        if(odalarim[i].mis.targiris.ay != odalarim[i].mis.tarcikis.ay){
        	if (cin.fail() || odalarim[i].mis.tarcikis.gun <= 0 || odalarim[i].mis.tarcikis.gun > 31){
        	cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			throw odalarim[i].mis.tarcikis.gun;	
			}
		}
          else{
        	Catch=0;
		  }
        } 
		catch (...) {
        cout << "\n Lutfen gunu dogru girin.";
        Catch = 1;
        }
	}while(Catch==1);
	
	cout << "\nTel No : ";
	do{
		try{
			cin >> a;
			if(cin.fail() || a > 5999999999 || a < 5000000000){
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			throw a;
			}
			else 
			Catch = 0;
		}
		catch(...){
			cout<<"Lutfen istenen degeri giriniz !";
			Catch = 1;
		}
	}while(Catch == 1);
	odalarim[i].mis.telSetter(a); 
	
	cout << "\nTc Kimlik Numarasi : ";
	do{
		try{
			cin >> b; 
			if(cin.fail() || b > 99999999999 || b < 10000000000){
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			throw b;
			}
			else
			Catch = 0;
		}
		catch(...){
			cout<<"Lutfen istenen degeri giriniz !";
			Catch = 1;
		}
	}while(Catch == 1);
	odalarim[i].mis.tcSetter(b);
	
	do {
    cout << "\n Misafir  Odeme Tercihi (Kredi Karti = 1 / Nakit = 2): ";
    cin >> c;
    try {
    	if (cin.fail() || c != 1 && c != 2){
    	cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		throw c;	
	}
    	else
		odalarim[i].mis.odemeSetter(c);
    Catch = 0;
	} 
	catch (...) {
		cout << "Lutfen 1 veya 2 girin: ";
    	Catch = 1;
    }
    }while (Catch == 1);
	
	odalarim[i].odaDurum=1;

	cout<<"\n Misafir kaydi basarili ";
	}
	
	ofstream misFile("misafir.txt",ios::app);
	if(!misFile) {
        cout << "misafir txt dosyasi acilamadi" << endl;  
    }
	
	misFile<<"oda no: "<<odaNo<<endl;
	misFile<<"misafir adi: "<<odalarim[i].mis.ad<<endl;
	misFile<<"misafir soyadi: "<<odalarim[i].mis.soyad<<endl;
	misFile<<"rezerve baslangic gun: "<<odalarim[i].mis.targiris.gun<<endl;
	misFile<<"rezerve baslangic ay: "<<odalarim[i].mis.targiris.ay<<endl;
	misFile<<"rezerve baslangic yil: "<<odalarim[i].mis.targiris.yil<<endl;
	misFile<<"rezerve bitis gun: "<<odalarim[i].mis.tarcikis.gun<<endl;
	misFile<<"rezerve bitis ay: "<<odalarim[i].mis.tarcikis.ay<<endl;
	misFile<<"rezerve bitis yil: "<<odalarim[i].mis.tarcikis.yil<<endl;
	misFile<<"telefon no: "<<odalarim[i].mis.telGetter()<<endl;
	misFile<<"T.C. kimlik no: "<<odalarim[i].mis.tcGetter()<<endl;
	misFile<<"odeme tercihi: "<<odalarim[i].mis.odemeGetter()<<endl;
	misFile<<endl;
	
	misFile.close();
	
	remove("oda.txt");
 	ofstream odaFile("oda.txt",ios::app);
	
	if(!odaFile) {
        cout << "oda txt dosyasi acilamadi" << endl;  
    }
	for(i = 0; i<count; i++){
		odaFile<<"Oda numarasi : "<<odalarim[i].odaNumara<<endl;
		odaFile<<"Oda tipi : "<<odalarim[i].odaTip<<endl;
		odaFile<<"Oda durumu : "<<odalarim[i].odaDurum<<endl;
		odaFile<<"Kart sayisi : "<<odalarim[i].kartGetter()<<endl;
		odaFile<<"Oda fiyati : "<<odalarim[i].fiyatGetter()<<endl;
		odaFile<<"Kapi sifresi : "<<odalarim[i].kapiGetter()<<endl;
		odaFile<<endl;
	}
	odaFile.close();
}

void OtelYonetim::bosOdaBul(){
	int i,k=0;
	for(i=0;i<count;i++)
	{
	if(odalarim[i].odaDurum==0)
	{
	odaGoster(i);
	cout<<"\n\nBir sonraki oda icin entera tiklayiniz";
	k=1;
	}
	}
	if(k==0)
	{
	cout<<"\nButun odalar rezerve.";
	}
}

void OtelYonetim::misafirAra(string ad)
{
	class OtelYonetim ott;
	int i,k=0;
	char cevap;
	int Catch=0;
	for(i=0;i<count;i++)
	{
	if(odalarim[i].odaDurum==1 && odalarim[i].mis.ad == ad)
		{
	cout<<"\nMisafir ismi: "<<odalarim[i].mis.ad;
	cout<<"\nOda numarasi: "<<odalarim[i].odaNumara;
	cout << "\nGuncellemek istiyor musunuz ? (e/h) : ";
	do{
		try{
	        cin >> cevap; // guncelle fonksiyonu cagirilacak
	        if(cin.fail() ||(cevap!='e'&&cevap!='E'&&cevap!='h'&&cevap!='H')){
	        	cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
	            throw cevap;
			}
			else{
				Catch=0;
			}
		}
		catch(...){
			cout<<"lutfen belirtilen harfleri giriniz."<<endl;
			Catch=1;
		}
	}while(Catch==1);
	
	if(cevap == 'e' || cevap == 'E'){
		ott.Guncelle(i);	
	}

	cout<<"\n\nBir sonraki kayit\n";
	k++;
	}
	}
	if(k==0)
	{
	cout<<"\n Aradiginiz kisi bulunamadi. \n";
	}
	if(k != 0){
		cout<<"\nSu kadar kisi bulundu : " << k;	
	}
}

void OtelYonetim::check_out(int odaNumara) {
    try {
        int i, k = -1, s, odaNo;
        float totalFiyat = 0;
        for (i = 0; i < count; i++) {
            if (odalarim[i].odaDurum == 1 && odalarim[i].odaNumara == odaNumara) {
                k = i; // Oda indisini kaydetme
                break;
            }
        }
        if (k == -1) {
            throw "Oda bulunamadi veya rezerve edilmemis.";
        }

        cout << "\nKac gunluk kullanim gerceklesti:\t";
        cin >> s;
        if (cin.fail() || s <= 0) {
            throw "Gecerli bir gun sayisi giriniz.";
        }
        totalFiyat = s * odalarim[k].fiyatGetter();

        cout << "\n\t Cikis Kaydi \n";
        cout << "\nMusteri ismi : " << odalarim[k].mis.ad;
        cout << "\nOda numarasi : " << odalarim[k].odaNumara;
        cout << "\nTelefon numarasi : " << odalarim[k].mis.telGetter();
        cout << "\n*** Odenecek Tutar " << totalFiyat;

        odalarim[k].odaDurum = 0;

        // dosyaya çikýþ bilgisini yazma 
        ofstream dosyaYaz("misafir.txt", ios::app);
        if (!dosyaYaz.is_open()) {
            throw "Dosya acilirken bir hata olustu!";
        }

        dosyaYaz << odalarim[k].mis.ad << " " << odalarim[k].mis.soyad << " " << odalarim[k].odaNumara << " " << totalFiyat << "\n";
        dosyaYaz.close();
        cout << "\nCikis bilgisi basariyla kaydedildi.";
        
        remove("oda.txt");
 	ofstream odaFile("oda.txt",ios::app);
	
	if(!odaFile) {
        throw "Dosya acilirken bir hata olustu!";  
    }
	for(i = 0; i<count; i++){
		odaFile<<"Oda numarasi : "<<odalarim[i].odaNumara<<endl;
		odaFile<<"Oda tipi : "<<odalarim[i].odaTip<<endl;
		odaFile<<"Oda durumu : "<<odalarim[i].odaDurum<<endl;
		odaFile<<"Kart sayisi : "<<odalarim[i].kartGetter()<<endl;
		odaFile<<"Oda fiyati : "<<odalarim[i].fiyatGetter()<<endl;
		odaFile<<"Kapi sifresi : "<<odalarim[i].kapiGetter()<<endl;
		odaFile<<endl;
	}
	odaFile.close();
        
    } catch (const char* e) {
        cout << "\nHata: " << e;
    } catch (...) {
        cout << "\nBeklenmeyen bir hata olustu.";
    }
}

void odalariYonet()
	{
	class Oda oda;
	int cevap,odaNo,i,secenek=0,Catch;
	char ch;
	do
	{
	cout<<"\n Menu \n";
	cout<<"\n1. Oda Ekle";
	cout<<"\n2. Oda Ara";
	cout<<"\n3. Menuye geri don";
	cout<<"\n\n Secenek giriniz: ";
	
	do{
		Catch = 0;
		try{
			cin >> cevap;
			if(cin.fail() || cevap <= 0 || cevap > 3){
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			throw cevap;
			}
		}
		catch(...){
			cout<<"Lutfen istenen degeri giriniz : ";
			Catch = 1;
		}
	}while(Catch == 1);

	//switch statement
	switch(cevap)
	{
	case 1:
	
	cout<<"\nOda numarasini giriniz (Maksimum 2 basamakli) :  ";
	do{
		Catch = 0;
		try{
			cin>>odaNo;
			if(cin.fail() || odaNo <= 0 || odaNo > 99){
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			throw odaNo;
			}
		}
		catch(...){
			cout<<"Lutfen istenen degeri giriniz : ";
			Catch = 1;
		}
	}while(Catch == 1);
	
	i=0;
	for(i=0;i<count;i++)
	{
	if(odalarim[i].odaNumara==odaNo)
	{
	secenek=1;
	}
	}
	if(secenek==1)
	{
	cout<<"\nBu oda numarasi coktan alindi.\nLutfen baska bir oda numarasi giriniz.";
	secenek=0;
	}
	else
	{
	odalarim[count]=oda.odaEkle(odaNo);
	count++;
	}
	break;
	case 2:
	cout<<"\nOda numarasi giriniz(Maksimum 2 basamak) : ";
	do{
		Catch = 0;
		try{
			cin>>odaNo;
			if(cin.fail() || cevap <= 0 || cevap > 99){
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			throw odaNo;
			}
		}
		catch(...){
			cout<<"Lutfen istenen degeri giriniz : ";
			Catch = 1;
		}
	}while(Catch == 1);
	oda.odaAra(odaNo);
	break;
	case 3:
	//nothing to do
	break;
	default:
	cout<<"\nLutfen sunuculan seceneklerden seciniz";
	break;
	}
	}while(cevap!=3);
	}
	
	void DosyaIslemleri()
	{
	int cevap,Catch,c;
	string satir;
	do
	{
	c = -1;
	cout<<"\n Menu \n";
	cout<<"\n1. Oda dosyasi oku";
	cout<<"\n2. Misafir dosyasi oku";
	cout<<"\n3. Mevcut dosyalari bosalt";
	cout<<"\n4. Menuye geri don";
	cout<<"\n\n Secenek giriniz: ";
	
	do{
		Catch = 0;
		try{
			cin >> cevap;
			if(cin.fail() || cevap <= 0 || cevap > 4){
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			throw cevap;
			}
		}
		catch(...){
			cout<<"Lutfen istenen degeri giriniz : ";
			Catch = 1;
		}
	}while(Catch == 1);
	
	switch(cevap){
		case 1:{
			fstream OdaDosya("oda.txt");
	    if(!OdaDosya) {
            cout << "Dosya acilamadi." << endl;
        }
        while (!OdaDosya.eof()) {
            getline(OdaDosya, satir);
            cout << satir << endl;
            c++;
	    }
	    if(OdaDosya.eof()){
	        cout<<"##dosya sonuna gelindi.##"<<endl;
	        if(c==0){
	        	cout << "Oda kaydi yapilmadi."<<endl;	
			}
		}
		OdaDosya.close();
		break;
		}
		
		case 2:{
			fstream MisDosya("misafir.txt");
		if(!MisDosya) {
            cout << "Dosya acilamadi." << endl;
        }
        while (!MisDosya.eof()) {
            getline(MisDosya, satir);
            cout << satir << endl;
            c++;
	    }
	    if(MisDosya.eof()){
	        cout<<"##dosya sonuna gelindi.##"<<endl;
		}
		if(c==0){
			cout << "Misafir kaydi yapilmadi." << endl;
		}
		MisDosya.close();
			break;
		}	
		case 3:{
			
			remove("misafir.txt");
			ofstream MisDosya("misafir.txt");
			MisDosya.close();
			
			remove("oda.txt");
			ofstream OdaDosya("oda.txt");
			OdaDosya.close();
			cout << "Dosyalar bosaltildi.";
			break;
			
		}
        case 4:{
        	//nothing to do
			break;
		}
	    default:
	    cout<<"\nLutfen sunuculan seceneklerden seciniz";
	    break;
	    }
    }while(cevap!=4);
}
	void OtelYonetim::rezerveKontrol(){
		
		
	int Catch=0,i,j,gelmeyenler=0;
	char cevap;
	class Tarih GuncelTarih;
	vector <Oda> temp(20);
	do{
	cout<<"\nKontrol edilmesi istenen Yil : ";
	cin>>GuncelTarih.yil;	
	try{
		if(cin.fail() || GuncelTarih.yil<2024 || GuncelTarih.yil>2025 ){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		throw GuncelTarih.yil;	
		}
		else
		Catch=0;
	}
	catch(...){
		cout << "\n Lutfen gecerli bir yil girin:";
		Catch=1;
	}
	}while(Catch == 1);
	do{
	cout<<"\nKontrol edilmesi istenen Ay :  ";
	cin>>GuncelTarih.ay;	
		try{
		if(cin.fail() || GuncelTarih.ay>12 || GuncelTarih.ay<=0 ){ 
	    cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		throw GuncelTarih.ay;
		} // burda && kullanýlmaz ay hem 0 dan küçük hem de 12 den büyük olamaz.	
		else
		Catch=0;
	}
	catch(...){
		cout << "\n Lutfen gecerli bir ay girin:";
		Catch=1;
	}
	}while(Catch==1);

	do{
    	cout << "\nKontrol edilmesi istenen gun: ";
        cin >> GuncelTarih.gun;
        try {
        if (cin.fail() || GuncelTarih.gun <=0 || GuncelTarih.gun > 31){
        cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		throw GuncelTarih.gun;	
		}
		else
        Catch = 0;
        } catch (...) {
        cout << "\n Lutfen gunu dogru girin.";
        Catch = 1;
        }
	}while(Catch==1);
	
	j=0;	
	for(i=0;i<count;i++){
		if(odalarim[i].mis.targiris.yil==GuncelTarih.yil){
			if(odalarim[i].mis.targiris.ay==GuncelTarih.ay){
				if(odalarim[i].mis.targiris.gun==GuncelTarih.gun){
					cout<<"rezervesi olan "<<odalarim[i].mis.ad<<" geldi mi?(e/h) ";
					do{
	                	try{
	                        cin >> cevap; // guncelle fonksiyonu cagirilacak
	                        if(isalpha(cevap)==0||(cevap!='e'&&cevap!='E'&&cevap!='h'&&cevap!='H')){
	        	                Catch=1;
	                            throw cevap;
			                }
			                else{
				                Catch=0;
			                }
		                }
		                catch(...){
			                 cout<<"lutfen belirtilen harfleri giriniz."<<endl;
		                }
	                }while(Catch==1);
					if(cevap=='H'||cevap=='h'){
						temp[j]=odalarim[i];
						odalarim[i].odaDurum=0;
						j++;
						gelmeyenler++;	
					}
				}	
			}
		}
	}
	
	if(gelmeyenler!=0){
		cout<<"Rezerve tarihinde gelmeyen musteriler: ";
	    for(i=0;i<=j;i++){
		    cout<<temp[i].mis.ad<<"\t"<<temp[i].mis.soyad<<endl;
	}
	cout<<"Oda rezerveleri iptal edildi.";
	}
	else{
		cout << "Rezerve tarihinde gelmeyen musteri yok." << endl;
	}
	
	remove("oda.txt");
 	ofstream odaFile("oda.txt",ios::app);
	
	if(!odaFile) {
        cout << "oda txt dosyasi acilamadi" << endl;  
    }
	for(i = 0; i<count; i++){
		odaFile<<"Oda numarasi : "<<odalarim[i].odaNumara<<endl;
		odaFile<<"Oda tipi : "<<odalarim[i].odaTip<<endl;
		odaFile<<"Oda durumu : "<<odalarim[i].odaDurum<<endl;
		odaFile<<"Kart sayisi : "<<odalarim[i].kartGetter()<<endl;
		odaFile<<"Oda fiyati : "<<odalarim[i].fiyatGetter()<<endl;
		odaFile<<"Kapi sifresi : "<<odalarim[i].kapiGetter()<<endl;
		odaFile<<endl;
	}
	odaFile.close();
	
}
	
	using namespace std;
	
	int main()
	{
	class OtelYonetim ot;
	int i,j,cevap,odaNo,Catch;
	char ch;
	char ad[100];
	
	do
	{
	cout<<"######## Otel Yonetimi #########\n";
	cout<<"\n1. Odalari Yonet";
	cout<<"\n2. Check-In Room";
	cout<<"\n3. Musait odalar";
	cout<<"\n4. Misafiri Ara";
	cout<<"\n5. Check-Out Room";
	cout<<"\n6. Misafir Total Fiyat";
	cout<<"\n7. Rezerve Kontrol";
	cout<<"\n8. Dosya islemleri";
	cout<<"\n9. Cikis";
	cout<<"\n\nBir secenek giriniz: ";
	do{
		Catch = 0;
		try{
			cin >> cevap;
			if(cin.fail() || cevap <= 0 || cevap > 9){
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			throw cevap;
			}
		}
		catch(...){
			cout<<"Lutfen istenen degeri giriniz : ";
			Catch = 1;
		}
	}while(Catch == 1);
	switch(cevap)
	{
	case 1:
	odalariYonet();
	break;
	case 2:
	if(count==0)
	{
	cout<<"\nBahsedilen oda maalesef bulunmamakta.\nLutfen once kaydi giriniz.";
	}
	else
	ot.check_in();
	break;
	case 3:
	if(count==0)
	{
	cout<<"\nBahsedilen oda maalesef bulunmamakta.\nLutfen once kaydi giriniz.";
	}
	else
	ot.bosOdaBul();
	break;
	case 4:
	if(count==0)
	{
	cout<<"\nBahsedilen oda maalesef bulunmamakta.\nLutfen once kaydi giriniz.";
	}
	else
	{
	cout<<"Musteri ismini giriniz : ";
	do{
		Catch = 0;
		try{
			cin>>ad;
			if(cin.fail()){
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			throw ad;
			}
		}
		catch(...){
			cout<<"Lutfen istenen degeri giriniz : ";
			Catch = 1;
		}
	}while(Catch == 1);
	ot.misafirAra(ad);
	}
	break;
	case 5:
	if(count==0)
	{
	cout<<"\nBahsedilen oda maalesef bulunmamakta.\nLutfen once kaydi giriniz.";
	}
	else
	{
	cout<<"Oda numarasini giriniz : ";
	do{
		Catch = 0;
		try{
			cin>>odaNo;
			if(cin.fail() || cevap <= 0 || cevap > 99){
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			throw odaNo;
			}
		}
		catch(...){
			cout<<"Lutfen istenen degeri giriniz : ";
			Catch = 1;
		}
	}while(Catch == 1);
	ot.check_out(odaNo);
	}
	break;
	case 6:
	ot.gunlukKazanc();	
	break;
	case 7:
	ot.rezerveKontrol();
	break;
	case 8:
	DosyaIslemleri();
	break;
	case 9:
	cout<<"\nGorusmek Uzere!\n";
	break;
	default:
	cout<<"\nLutfen sunulan seceneklerden birini seciniz.";
	break;
	}
	}while(cevap!=9);

}
