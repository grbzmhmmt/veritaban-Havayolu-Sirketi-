#include <iostream>
#include <stdio.h>
#include <string>
#include <windows.h>
#include <mysql.h>

using std::getline;
using std::cin;

using namespace std;

int main()
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* res;

    int gstate;  ///if gtate zero not succesful if gstate unzere it is succesfully
    conn =mysql_init(0);       //conn un mysql bağlantısı olduğu tanımlanıyor
    if(conn){   //bağlantının oluştulduğu kontrol ediliyor
        cout <<"connection object ok"<<endl;
    }
    else{       //bağlantı oluşmamışsa uyarı veriliyor
        cout <<"conn object problem!"<<mysql_error(conn)<<endl;
    }

    //mysql ile bağlantı oluşturuluyor
    conn=mysql_real_connect(conn,"localhost","root","",NULL,3306,NULL,0);

    //database oluşturuluyor
    mysql_query(conn,"create database prolab");

    //prolab datbe ile bağlantı kuruluyor
    conn=mysql_real_connect(conn,"localhost","root","","prolab",3306,NULL,0);

    //ucaklar tablosu olusturuluyo
    mysql_query(conn,"create table ucaklar(ukn int(11) not null , umodel varchar(45) default null,ukapasite varchar(45) default null,primary key(ukn))");

    //yolcu tablomuz oluşturuluyor
    mysql_query(conn,"create table yolcu(tckn int(11) not null  , isim varchar(45) default null,adres varchar(45) default null,eposta varchar(45) default null,sehir varchar(45) default null,primary key(tckn))");

    //yolcular tablomuz oluşturuluyor
    mysql_query(conn,"create table yolcular(tckn int(11) not null ,tarih varchar(45) default null,ukn int(11),bn varchar(45) default null,bin varchar(45) default null,primary key(tckn,ukn,tarih,bn,bin),foreign key(ukn) references ucaklar(ukn) on delete cascade,foreign key(tckn) references yolcu(tckn) on delete cascade)");

    //seferler tablomuz oluşturuluyor
    mysql_query(conn,"create table seferler(ukn int(11) not null , bn varchar(45) default null,bin varchar(45) default null,tarih varchar(45) default null,saat varchar(45) default null,primary key(tarih,ukn),foreign key(ukn) references ucaklar(ukn) on delete cascade)");


    //aşşagıda ucaklar tablomuza 8 adet veri girişi yapılıyor
    mysql_query(conn,"insert into ucaklar(ukn,umodel,ukapasite) values('111','boing','200')");
    mysql_query(conn,"insert into ucaklar(ukn,umodel,ukapasite) values('112','jet','20')");
    mysql_query(conn,"insert into ucaklar(ukn,umodel,ukapasite) values('113','boing','150')");
    mysql_query(conn,"insert into ucaklar(ukn,umodel,ukapasite) values('114','boing','100')");
    mysql_query(conn,"insert into ucaklar(ukn,umodel,ukapasite) values('115','boing','250')");
    mysql_query(conn,"insert into ucaklar(ukn,umodel,ukapasite) values('116','jet','25')");
    mysql_query(conn,"insert into ucaklar(ukn,umodel,ukapasite) values('117','boing','225')");
    mysql_query(conn,"insert into ucaklar(ukn,umodel,ukapasite) values('118','boing','175')");


    //aşşagıda yolcu tablomuza 8 adet veri girişi yapılıyor
    mysql_query(conn,"insert into yolcu(tckn,isim,adres,eposta,sehir) values('50','baris','izmit','aaaa','kocaeli')");
    mysql_query(conn,"insert into yolcu(tckn,isim,adres,eposta,sehir) values('60','fatih','yalova','bbbb','bolu')");
    mysql_query(conn,"insert into yolcu(tckn,isim,adres,eposta,sehir) values('80','baki','korfez','cccc','istanbul')");
    mysql_query(conn,"insert into yolcu(tckn,isim,adres,eposta,sehir) values('110','gurbuz','golcuk','dddd','izmir')");
    mysql_query(conn,"insert into yolcu(tckn,isim,adres,eposta,sehir) values('200','baris','basiskele','eeee','ankara')");
    mysql_query(conn,"insert into yolcu(tckn,isim,adres,eposta,sehir) values('240','berk','hereke','ffff','ankara')");
    mysql_query(conn,"insert into yolcu(tckn,isim,adres,eposta,sehir) values('199','taha','derince','gggg','rize')");
    mysql_query(conn,"insert into yolcu(tckn,isim,adres,eposta,sehir) values('44','gurbuz','gebze','hhhh','malatya')");


    //aşşagıda seferler tablomuza 8 adet veri girişi yapılıyor
    mysql_query(conn,"insert into seferler(bn,bin,tarih,saat,ukn) values('istanbul','ankara','210517','800','111')");
    mysql_query(conn,"insert into seferler(bn,bin,tarih,saat,ukn) values('ankara','istanbul','210517','900','112')");
    mysql_query(conn,"insert into seferler(bn,bin,tarih,saat,ukn) values('izmir','malatya','210517','1000','113')");
    mysql_query(conn,"insert into seferler(bn,bin,tarih,saat,ukn) values('istanbul','antalya','210517','1100','114')");
    mysql_query(conn,"insert into seferler(bn,bin,tarih,saat,ukn) values('antalya','edirne','210517','1130','115')");
    mysql_query(conn,"insert into seferler(bn,bin,tarih,saat,ukn) values('mugla','sivas','210517','1400','116')");
    mysql_query(conn,"insert into seferler(bn,bin,tarih,saat,ukn) values('sinop','istanbul','210517','1430','117')");
    mysql_query(conn,"insert into seferler(bn,bin,tarih,saat,ukn) values('rize','konya','210517','1400','118')");


    //aşşagıda yolcular tablomuza 8 adet veri girişi yapılıyor
    mysql_query(conn,"insert into yolcular(tckn,tarih,ukn,bn,bin) values('50','210517','111','istanbul','ankara')");
    mysql_query(conn,"insert into yolcular(tckn,tarih,ukn,bn,bin) values('60','210517','112','ankara','istanbul')");
    mysql_query(conn,"insert into yolcular(tckn,tarih,ukn,bn,bin) values('80','210517','113','izmir','malatya')");
    mysql_query(conn,"insert into yolcular(tckn,tarih,ukn,bn,bin) values('110','210517','114','istanbul','antalya')");
    mysql_query(conn,"insert into yolcular(tckn,tarih,ukn,bn,bin) values('200','210517','114','istanbul','antalya')");
    mysql_query(conn,"insert into yolcular(tckn,tarih,ukn,bn,bin) values('240','210517','114','istanbul','antalya')");
    mysql_query(conn,"insert into yolcular(tckn,tarih,ukn,bn,bin) values('199','210517','115','kars','nigde')");
    mysql_query(conn,"insert into yolcular(tckn,tarih,ukn,bn,bin) values('44','210517','113','izmir','malatya')");

    //row degerleri döngü den gelen sonucların saklandıgı dizi indeks değerleri
    int secim;
    if(conn){
        while(1){   //kullanıcının sonsuz işlem yapabilmesi için sonsuz döngüye giriliyor
            cout <<" yapmak istediginiz islem numarasini giriniz :"<<endl;
            cout <<" cikmak icin 8 tuslayiniz :"<<endl; cin>>secim;     //kullanıcı yapmak istediği işlem icin secim alınıyor
            if(secim==8)        //kulllanıcı cıkmak isterse çıkış yapılıyır
                break;
            switch(secim){      //secim değeri nin ne olduğuna göre işlem yapılacak
            case 1:{            //eğer secim 1 ise;  yeni sefer tanımlama

                string ukn,tarih,bn,bin,saat;       //kullanıcıdan yandaki degerleri almak için değişkenler ytanımlanıyor
                cout<<" Kuyruk no griniz(ukn) : "<<endl; cin>>ukn;      //ukn değeri isteniyor
                cout<<" Tarih giriniz : "<<endl; cin>>tarih;            //tarih değeri isteniyor
                cout<<" Baslangic noktasini giriniz : "<<endl; cin>>bn;     //biniş yeri değeri isteniyor
                cout<<" Inis sehrini giriniz: "<<endl; cin>>bin;        // iniş yeri no değeri isteniyor
                cout<<" saati  giriniz: "<<endl; cin>>saat;         //saati değeri isteniyor

                string query="insert into seferler(ukn,tarih,bn,bin,saat) values('"+ukn+"','"+tarih+"','"+bn+"','"+bin+"','"+saat+"')";
                //bir string değerine yazmak istediğimiz  sorgu atanıyor

                const char* q = query.c_str();      //sorgumuz bir pointer değişkenine atanıyor
                cout<<"query is  :  "<<q<<endl;     //yazdığımız sorgumuz ekrana basılıyor
                mysql_query(conn,q);                //sorgumuz sorgu fonksiyonu ile mysql e gönderiliyor

                break;
            }
            case 2:{            //secim =2 ise ;    bilet satma işlemi
                int i=0;
                gstate = mysql_query(conn,"select * from yolcu");       //sorgumuz yapılıyor yolcu tablosunun tüm değerleri çekiliyor
                res=mysql_store_result(conn);                           //sorgumuz un döndüğü sonu atanıyor

                while(row=mysql_fetch_row(res)){i++;}           //sorgumuzun sonucu row değişkenine atanıyor ve sorgunun son satırına gelene kadar döngümüz devam ediyor
                string tcknno[i];               //tcknno isimli string tanımlanıyor
                i=0;
                gstate = mysql_query(conn,"select * from yolcu");         //sorgumuz yapılıyor yolcu tablosunun tüm değerleri çekiliyor
                res=mysql_store_result(conn);                              //sorgumuz un döndüğü sonu atanıyor

                while(row=mysql_fetch_row(res)){ //sorgumuzun sonucu row değişkenine atanıyor ve sorgunun son satırına gelene kadar döngümüz devam ediyor
                tcknno[i]=row[0];           //sorgumuzdaki satırların ilk koonu olan tckn numarası tcknno dizimize atanıyor
                cout<<tcknno[i]<<endl;
                i++;
                }

                string tarih,bn,bin,tckn,isim,eposta,sehir,ukn,adres;
                //kullanıcıdan alacak olduğumuz degerler için bu deikenlerin tanımlamaları yapılıyor
                int biletsayisi;
                //aşşagıda degişkenlerin ismi yazılarak kullanıcıdan  degerleri isteniyor
                cout<<" Tarih giriniz : "<<endl; cin>>tarih;
                cout<<" Baslangic noktasini giriniz : "<<endl; cin>>bn;
                cout<<" Inis sehrini giriniz: "<<endl; cin>>bin;
                cout<<" bilet sayisini giriniz: "<<endl; cin>>biletsayisi;

                mysql_query(conn,"select * from seferler");     //tüm sferler in istendiği sorgu
                res=mysql_store_result(conn);       //sonuc atanıyor
                int sonuc=0;
                while(row=mysql_fetch_row(res)){
                    if(tarih==row[2] && bn==row[0] && bin==row[1]){
                        ukn=row[4];                 //seferlerdeki ucak kuyruk numarakaru ukn dizimize atanıyor
                        sonuc=1;
                    }
                }
                if (sonuc==0){          //girilen değerler yanlış ise sefer bulunamıyor
                    cout<<"uygun sefer bulunamamistir"<<endl;
                    break;
                }
                int k=i;
                for(int i=0;i<biletsayisi;i++){     //kullanıcının bilet sayısına göre bir döngü olusturuluyor ve tckn no ları isteniyor
                    cout<<i+1<<". TCKN giriniz: "<<endl; cin>>tckn;
                    sonuc=0;
                    for(int j=0;j<k;j++){           //girilen tckn bumarası yolcu tablomuzda varmı diye kontrol ediliyor
                        if(tcknno[j]==tckn){
                            sonuc=1;
                            break;
                        }
                    }
                    if(sonuc==0){       //eğer girilen tckn numarası kayıtlı değilse yni yolcu için bilgiler istenmiyr
                        cout<<"adres giriniz";
                        cin.ignore();
                        std::getline(cin,adres);
                        cout<<"yolcu bulunamamistir lutfen yolcu bilgilerini giriniz.."<<endl;
                        cout<<"isim giriniz"<<endl; cin>>isim;
                        cout<<"eposta giriniz"<<endl; cin>>eposta;
                        cout<<"sehir giriniz"<<endl; cin>>sehir;


                        string query="insert into yolcu(tckn,isim,adres,eposta,sehir) values('"+tckn+"','"+isim+"','"+adres+"','"+eposta+"','"+sehir+"')";
                        //yolcu tablosuna insert into komutu ile yolcu ekleme sorgusu oluşturuluyor
                        const char *q=query.c_str();
                        mysql_query(conn,q);        //sorgumuz mysql_query komutu ile gönderiliyor

                    }else{}

                    string query="insert into yolcular(tckn,tarih,ukn,bn,bin) values('"+tckn+"','"+tarih+"','"+ukn+"','"+bn+"','"+bin+"')";
                    //yolcular tablosuna yolcu kleme sorgusu oluşturuluyor
                    const char *q=query.c_str();
                    mysql_query(conn,q);    //yolcu ekleme sorgumuz gönderiliyor

                }
                break;
            }
            case 3:{        //girilen tckn numarasına göre yolcuları listeleme bloğu
                gstate = mysql_query(conn,"select * from yolcular");    //tüm yolcuları çeken sorgu muz
                string tckn;
                cout<<" TCKN no nu giriniz : "<<endl; cin>>tckn;    //tckn no iisteniyor kullanıcıdan

                res=mysql_store_result(conn);
                //now ewad and display rekord one @time

                while (row=mysql_fetch_row(res)){   //çekilen sorgu bir döngü eçerisinde ekrana yazdırmak için döngümğz oluştıurulyor
                //döngü sayýsý kadar satýr basar (satýr dongüde bir artar)
                    if(tckn == row[0]){     //yolcunun tckn si ve sorgudaki tckn ler eşit ise bu blok içerisinde ekrana yazdırma işlemi yapılıyor
                        string tckn,isim,adres,eposta,sehir,tarih,ukn,bn,bin;
                        cout<<" tckn : "<<row[0]<<"  "
                            <<" tarih : "<<row[1]<<"  "
                            <<" ukn : "<<row[2]<<"  "
                            <<" bn : "<<row[3]<<"  "
                            <<" bin : "<<row[4]<<endl;
                        cout<<"\n"<<endl;
                    }
                    else {}
                }


                break;
            }
            case 4:{        //uçuş iptali icin 4 secenegi kullanılmmış ise
                string ukn,tarih;       //kullanıcıdan ucus bilgilerini almak için değişenler alınıyor
                //kullanıcıdan hangi ucusu silmek istediğinin bilgileri alınıyor
                cout<<" Kuyruk no griniz(ukn) : "<<endl; cin>>ukn;
                cout<<" Tarih giriniz : "<<endl; cin>>tarih;


                string query = "delete from yolcular where  ukn = '"+ukn+"' and tarih = '"+tarih+"'";
                //delete komutlu sorgumuzu bir string e atıyoruz
                const char * q = query.c_str();
                mysql_query(conn,q);    //alınan bilgilere göre silme komutumuza yolcunun bilgileri yolcular tablomuza gönderiliyır

                string query1 = "delete from seferler where  ukn = '"+ukn+"' and tarih = '"+tarih+"'";
                //delete komutlu sorgumuzu bir string e atıyoruz
                const char * qw = query1.c_str();
                mysql_query(conn,qw);


                break;
            }
            case 5:{    //bilet iptali
                string ukn,tarih,tckn;      //yolcunun bilgilerini almak için değişkenler oluşturuluyor
                //kullanıcıdan bilgiler alınıyor
                cout<<" Kuyruk no(ukn) nu giriniz : "<<endl; cin>>ukn;
                cout<<" Tarih'i  giriniz : "<<endl; cin>>tarih;
                cout<<" TCKN no nu  giriniz : "<<endl; cin>>tckn;

                string query="delete from yolcular where tckn="+tckn+" and ukn="+ukn+" and tarih="+tarih+"";
                //gerekli silme komutu bir string değişkenimize atılıyor
                const char* q = query.c_str();      //
                cout<<"query is  :  "<<q<<endl;
                mysql_query(conn,q);        //sorgumuz gönderiliyor

                break;
            }
            case 6:{        //sefer sorgulama
                gstate = mysql_query(conn,"select * from yolcular");
                //yolcular tablosundan tkn no larını almak için tüm yolcular çekiliyor
                string ukn,tarih;
                cout<<" kuyruk no(ukn) nu giriniz : "<<endl; cin>>ukn;
                cout<<" tarih'i  giriniz : "<<endl; cin>>tarih;
                res=mysql_store_result(conn);
                string tcknno[50];
                int i=0;
                //now ewad and display rekord one @time
                while (row=mysql_fetch_row(res)){   //tckn numarasını aktarmak için bir döng oluşturuluyor
                //döngü sayýsý kadar satýr basar (satýr dongüde bir artar)
                    if(tarih == row[1] && ukn==row[2]){
                        tcknno[i]=row[0];       //tckn ler eşitleniyor
                        i++;
                    }
                    else {}
                }

                gstate = mysql_query(conn,"select * from yolcu");
                //yolcu tablosundan tüm bilgeiler çekiliyor
                res=mysql_store_result(conn);
                i=0;
                while (row=mysql_fetch_row(res)){
                //döngü sayýsý kadar satýr basar (satýr dongüde bir artar)
                    for(int j=0;j<i;j++){
                        if(tcknno[j] == row[0]){//cekillen bilgiler ile eşlesen tckn numaraları ekran yazdırılıyor
                            cout<<row[0]<<"  "
                                <<row[1]<<"  "
                                <<row[2]<<"  "
                                <<row[3]<<"  "
                                <<row[4]<<endl;
                            cout<<"\n"<<endl;
                        }
                        else {}
                    }
                    i++;
                }
                break;
            }
            case 7:{
                string uknno[50][3];
                int i=0;
                gstate=mysql_query(conn,"select * from ucaklar");
                res=mysql_store_result(conn);
                while(row=mysql_fetch_row(res)){
                    uknno[i][0]=row[0];
                    i++;
                }
                gstate=mysql_query(conn,"select yolcular.ukn,count(*),ucaklar.ukapasite from yolcular,ucaklar where yolcular.ukn=ucaklar.ukn group by yolcular.ukn");
                res=mysql_store_result(conn);
                i=0;
                while(row=mysql_fetch_row(res)){
                    if(uknno[i][0]==row[0]){
                        uknno[i][1]=row[1];
                        uknno[i][2]=row[2];
                       // cout<<uknno[i][0]<<"  "<<uknno[i][1]<<"  "<<uknno[i][2]<<endl;
                        i++;
                    }
                }
                float ortalama[i];
                for(int j=0;j<i;j++){
                    string ilk=uknno[j][1];
                    string son=uknno[j][2];
                    int ilk1=atof(ilk.c_str());
                    int son1=atof(son.c_str());
                   // cout<<ilk1<<"  "<<son1<<endl;
                    ortalama[j]=(float)ilk1/(float)son1;
                    cout<<ortalama[j]<<endl;
                }
                float enb=0;
                for(int j=0;j<i;j++){
                    if(ortalama[j]>=enb)
                        enb=ortalama[j];
                }
                cout<<"en buyuk ortalamalar : "<<endl;
                for(int j=0;j<i;j++){
                    if(ortalama[j]>=enb)
                        cout<<ortalama[j]<<endl;
                }

                break;
            }
            }
       }

    }

    else{
        cout <<"conn object problem!"<<mysql_error(conn)<<endl;
    }

    return 0;
}
