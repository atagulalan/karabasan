#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <stddef.h>

char isim[256] = "";
int skor = 0;
int oncekifikra = 7;
int hata = 0;

int random(int max) {
    int r = rand()%max;
    return r;
}

int say(char str[256]){
    int i;
    int len = strlen(str);
    int count = 0;

    for (i = 0; i < len; i++) {
        char c = str[i];
        if(c != ' ')
            count++;
    }
    return count;
}

void fikra(){
    char fikra[6][250] = {
    "adamın biri soğuk çay istemiş...\nçaycı çayı getirmiş...\nadam da 'ISIT DA İÇELİM KARDEŞİM!' demiş!",
    "2 laz kuş avlamadaymış...\nbiri 'niye avlanamıyoz' diye dert yanmış...\nöbürü: 'BENCE KÖPEĞİ DAHA YUKARI ATMALIYIZ!",
    "bir grup laz yürüyen merdivenle çıkarken\nelektrikler kesilmiş...\n2 saat süreyle mahsur kalmışlar!!!",
    "30 yaşındaki bir Alman koskoca bir uçağı...\ntek eliyle kaldırmış..\nadam PİLOTMUŞ lan PİLOT!",
    "Temelle Dursun soygundadırlar...\nkaçarlarken polis arkalarından bağırır:\n'DUR KAÇMA OROSPU ÇOCUĞU!!'\nTemel Dursun'a dönerek:\n'Sen kaç! beni tanıdı!'"
    };
    int rr;
    tekrardene:
    rr = random(6);
    if(rr==oncekifikra){
        goto tekrardene;
    }else{
        oncekifikra=rr;
    }
    printf("%s\n", fikra[rr]);
}

void gul(){
    char gulme[5][100] = {
    "eki!eki!eki! köh!köh!köh! ayy nekadar neşeliyim!!",
    "neee? hahhahahahhahhhhayyyy!! kafadan kopardım gene!!   hehe!",
    "kah!keh!koh!küh! hahahahaha!!! hihihihi!! ve de hohoho!",
    "he he he he...",
    "hahahaha!! ay ben ölmiiim emi!"
    };

    int rr = random(5);
    printf("%s", gulme[rr]);
}

void gerizekali(){
    int r1 = random(2);
    if(r1==1){
        printf("\ngeri zekalı taklidi yap bakiim...\nTamam tamam bukadar yeter!!!\n");
        gul();
    }
}

void sov(){
    char sovme[5][100] = {
    "EEE! mına korum böyle oyunun!! yıkıl köpek!",
    "bana bak! seni adam yerine koyduk karşımıza aldık,.. tööbe tööbee",
    "OHA! OHA! kırsaydın klavyeyi!!",
    "doğru oyna orospu!",
    "GÖT!"
    };
    int r1 = random(2);
    int r2 = random(2);
    int r3 = random(2);
    int r4 = random(2);
    int r5 = random(2);
    if(r1==1){
        printf("%s\n", sovme[0]);
    }
    if(r2==1){
        printf("%s\n", sovme[1]);
    }
    if(r3==1){
        printf("%s\n", sovme[2]);
    }
    if(r4==1){
        printf("%s\n", sovme[3]);
    }
    if(r5==1){
        printf("%s\n", sovme[4]);
    }
}

int sesliharf(char harf){
    if(harf=='a' || harf=='u' || harf=='e' || harf=='ı' || harf=='ü' || harf=='ö' || harf=='i' || harf=='o'){
        return 1;
    }else{
        return 0;
    }
}

void asama10(){
    printf("\nşimdik sana bi fıkra daha:\n");
    fikra();
    printf("Çıkmak için bir tuşa basın.");
    getch();
    exit(0);
}

void asama9(){
    char ch;
    int tahmin = random(100)+1;
    int ustlimit = 100;
    int altlimit = 1;
    hata = 0;
    int kacinci = 0;
    char inp;
    printf("şimdik sen bi sayı tut, ben bulmaya çalışiim. Ama dürüst ol.\ntahminimde yükselmen gerekirse 'y', düşmem gerekirse 'd' ile yanıt ver.\nsayıyı bulursam 'b' ile yanıt vermen yeterli.\n");
    asama9gg:
    kacinci++;
    printf(" %d  ??\n? ", tahmin);

    scanf(" %c", &inp);





    if(inp=='y'){
        if(ustlimit-1==tahmin && altlimit+1==tahmin){
            sov();
            if(hata>5){
                goto bitis;
            }else{
                hata++;
                goto asama9gg;
            }
        }
        if(ustlimit-1==tahmin){
            tahmin--;
            sov();
            if(hata>5){
                goto bitis;
            }else{
                hata++;
                goto asama9gg;
            }
        }else{
            altlimit = tahmin;
            tahmin = random(ustlimit - altlimit -1)+altlimit+1;
            goto asama9gg;
        }

    }else if(inp=='d'){
        if(ustlimit-1==tahmin && altlimit+1==tahmin){
            sov();
            if(hata>5){
                goto bitis;
            }else{
                hata++;
                goto asama9gg;
            }
        }
        if(altlimit+1==tahmin){
            tahmin++;
            sov();
            if(hata>5){
                goto bitis;
            }else{
                hata++;
                goto asama9gg;
            }
        }else{
            ustlimit = tahmin;
            tahmin = random(ustlimit - altlimit -1)+altlimit+1;
            goto asama9gg;
        }
    }else if(inp=='b'){
    bitis:
        printf(" %d  tahminde bildim...\n", kacinci);
        if(kacinci<skor){
            printf("kodum! kodum! kodum! hehehehe!");
        }else if(kacinci>skor){
            printf("lanet olsun! beni geçtin! %100 hile yapmışsındır!");
        }else{
            printf("hmm... eşitiz galiba...");
        }
        asama10();
    }else{
        goto asama9gg;
    }
}

void asama8(){
    int tuttum = random(100) + 1;
    int cikimmi = 1;
    int simdikitahmin;
    int tahmin = 0;
    int kackere = 0;
    printf("%s,\n gel senlen oyun oynayak...\nben şimdik 1 ilen 100 arası bi sayı tutiim...\ntuttum.\n", isim);
    asama8gg:
    kackere++;
    if(tuttum == simdikitahmin){
        if(kackere <= 3){
            printf(" %d  tahminde nası bildin lan? walla brawo!!", kackere);
        }else if(kackere <= 5){
            printf(" %d . denemede buldun!! tebrik etmek lazım şindi seni...", kackere);
        }else if(kackere <= 10){
            printf(" %d tahminde buldun.. eh..", kackere);
        }else if(kackere <= 20){
            printf("NİHAYET!!!  bişey  %d  kere sorulmaz ki ama, dimi?!", kackere);
        }else if(kackere <= 30){
            printf("bir an ümidimi kesmiştim! neytse ki  %d  kerede buldun! aferin!", kackere);
        }else if(kackere>30){
            printf(" %d \ntahminde bulundun...  sen,\n1- Türkçe bilmiyorsun...\n2- Klavye kullanmasını bilmiyorsun...\n3- ya da cinsel yönden bazısorunların var!!!\nE M B E S İ L !", kackere);
        }
        skor = kackere;
        asama9();
    }else{
        printf("tahmin et bakalım..? ");
        scanf("%d", &simdikitahmin);
        if(simdikitahmin==tahmin){
            printf("aynı sayıyı ne giriyon idiot!\n");
            goto asama8gg;
        }else if(simdikitahmin>100 || simdikitahmin < 1){
            printf("Abartma! abartma!  1-100 arası dedik!\n");
            goto asama8gg;
        }else{
            if(cikimmi == 1 && tahmin > simdikitahmin){
                tahmin = simdikitahmin;
                printf("kendine gel yavrucum!\n");
                if(tahmin<tuttum){
                    printf("yaklaştın, acık daa çık!\n");
                    goto asama8gg;
                }
            }
            if(cikimmi == 0 && tahmin < simdikitahmin){
                tahmin = simdikitahmin;
                printf("naaptın sen çuçuum!!\n");
                if(tahmin<tuttum){
                    printf("biraz daa düş!\n");
                    goto asama8gg;
                }
            }
            tahmin = simdikitahmin;
            if(tahmin<tuttum){
                cikimmi=1;
                if(tahmin<=21){
                    printf("yok pire! çık azcık yaw!..\n");
                    goto asama8gg;
                }else{
                    if(tuttum-tahmin<20){
                        printf("yaklaştın, acık daa çık!\n");
                    }else{
                        printf("çık çık\n");
                    }
                    goto asama8gg;
                }

                goto asama8gg;
            }else if(tahmin>tuttum){
                cikimmi=0;
                if(tahmin>=80){
                    printf("çüşş!!  düşş!\n");
                    goto asama8gg;
                }else{
                    if(tahmin-tuttum<20){
                        printf("biraz daa düş!\n");
                    }else{
                        printf("aşşalara gel aşşalara\n");
                    }
                }

                goto asama8gg;
            }else{
                goto asama8gg;
            }
        }
    }


}

void asama7(){
    printf("memleket nere %s?\n? ", isim);
    char memleket[256];
    int memleketuzunluk;
    scanf(" %255[0-9a-zA-Z ]", &memleket);
    memleketuzunluk = strlen(memleket);
    char son1karakter = memleket[memleketuzunluk-1];
    char son2karakter = memleket[memleketuzunluk-2];
    char son3karakter = memleket[memleketuzunluk-3];
    char karakter;
    int bulundu = 0;
    if(sesliharf(son1karakter)==0){
    //son karakter sessiz
        if(sesliharf(son2karakter)==0){
        //sondan 2. karakter sessiz
            karakter = son3karakter;
            bulundu = 3;
        }else{
        //sondan 2. karakter sesli
            karakter = son2karakter;
            bulundu = 2;
        }
    }else{
    //son karakter sesli
        karakter = son1karakter;
        bulundu = 1;
    }

    if(karakter=='u' || karakter=='o'){
        printf("madem %slusun,\n buralara ne b*k yemeye geldin?! Ayrıca\n%sdan\n   adam falan çıkmaz!", memleket, memleket);
    }else if(karakter=='ü' || karakter=='ö'){
        printf("heheheh!%sden\n top çıkarmış diyolar!?!", memleket);
    }else if(karakter=='a' || karakter=='ı'){
        printf("naaaber pis\n%slı!", memleket);
    }else if(karakter=='e' || karakter=='i'){
        printf("nea!? %sden\n      adam çıkmaz ki beah!!!  hihöhöhö!!", memleket);
    }
    printf("\n");
    gul();
    printf("\nneyse %s,\n kusura bakma...", isim);
    asama8();
}

void asama6(){
    printf("bak sana şindi konuyla ilgili bir fıkra...\n");

    fikra();
    gul();

    char atasozu[3][100] = {
    "yani sakla samanı gelir zamanı.",
    "yani arkadaşlarımızı dikkatli seçmemiz lazım.",
    "buradan alınacak ders: Göte giren şemsiye açılmaz.."
    };
    int rr2 = random(3);
    printf("\n%s\n", atasozu[rr2]);
    gul();
    printf("\n");
    asama7();
}

void asama5(){

    int r1 = random(2);
    int r2 = random(2);
    int r3 = random(2);
    int r4 = random(2);
    int r5 = random(2);
    int r6 = random(2);
    int r7 = random(2);

    if(r1==1){
    //R1
    printf("%s!\n", isim);
    printf("sana gözlerinin çok güzel olduğunu söyleyen olmuşmuydu hiç\n(e/h)? ");
    char secim;
    scanf(" %c", &secim);
    if(secim=='e'){
        printf("yalan söylemiş!\n");
        gul();
    }else{
        printf("doğrudur. çünkü gözlerin güzel diil!\n");
        gul();
    }
    }

    if(r2==1){
    //R2
    printf("\nyavrum\n%s\n", isim);
    printf("ayda 50 milyon kazanmak istermisin?\n(e/h)? ");
    char secim2;
    scanf(" %c", &secim2);
    if(secim2=='e'){
        printf("o zaman Ay'a gitmen lazım...\n");
        gul();
    }else{
        printf("iyi... zaten Ay'da sağlıklı çalışabileceğini sanmıyordum.\n");
        gul();
    }
    }

    if(r3==1){
    //R3
    printf("\n%s\n", isim);
    printf("adı nerden geliyo?\n? ");
    char secim3[256];
    scanf("%s", &secim3);
    printf("üüüü! baya uzaktan geliyomuş!\n");
    gul();
    }

    if(r4==1){
    //R4
    printf("\n%s\n", isim);
    printf("bi sayı tut.\ntuttunmu (e/h)\n? ");
    char secim4;
    scanf(" %c", &secim4);
    if(secim4=='e'){
        printf("şimdi de bırak!\n");
        gul();
    }else{
        printf("bi sayıyı tutamadın allah belanı versin\n");
        gul();
    }
    }

    if(r5==1){
    //R5
    if(isim[1]=='a' || isim[1]=='e' || isim[1]=='o' || isim[1]=='ö' || isim[1]=='ı' || isim[1]=='i' || isim[1]=='u' || isim[1]=='ü'){
        printf("\n%s, sana kısaca %c%c%coş diyebilirmiyim??\n", isim,isim[0],isim[1],isim[2]);
    }else{
        printf("\n%s, sana kısaca %c%coş diyebilirmiyim??\n", isim,isim[0],isim[1]);
    }
    printf("(e/h)? ");
    char secim5;
    scanf(" %c", &secim5);
    if(secim5=='e'){
        printf("iyi... ama ben demek istemiyorum!\n");
        gul();
    }else{
        if(isim[1]=='a' || isim[1]=='e' || isim[1]=='o' || isim[1]=='ö' || isim[1]=='ı' || isim[1]=='i' || isim[1]=='u' || isim[1]=='ü'){
            printf("%c%c%coş! %c%c%coş! %c%c%coş!\n",isim[0],isim[1],isim[2],isim[0],isim[1],isim[2],isim[0],isim[1],isim[2]);
        }else{
            printf("%c%coş! %c%coş! %c%coş!\n",isim[0],isim[1],isim[0],isim[1],isim[0],isim[1]);
        }

        gul();
    }
    }

    if(r6==1){
    //R6
    printf("\nnasılsınız lan\n%s?\n", isim);
    printf("iyimisin ki (e/h)\n? ");
    char secim6;
    scanf(" %c", &secim6);
    if(secim6=='e'){
        int rand6 = random(3);
        if(rand6==0){
            printf("niye iyisin? oturduğun yere bir bak bakiim...\njoysitick falan unutmuş olmasınlar?\n");
        }else if(rand6==1){
            printf("iyi iyi... sen iyi olmaya devam et\n%s!\nuyu da büyü!\n", isim);
        }else if(rand6==2){
            printf("böyle bir hayatta nasıl iyi oluyorsunuz ki lan\n%s?\nbize de söyle yolunu biz de iyi olalım..\n", isim);
        }
    }else{
        int rand62 = random(3);
        if(rand62==0){
            printf("bana ne lan! geber!\n");
        }else if(rand62==1){
            printf("iyi iyi allah kötülük versin! he he he !!\n");
        }else if(rand62==2){
            printf("derdini anlat bana! açıl bana yavrucuum! utanma ben doktorum...\nKötü olmana sebep olan şey nedir\n", isim);
            char secim62[512];
            scanf(" %511[0-9a-zA-Z ]", &secim62);
            printf("%s??\nhahahahahahahaha!!! git allasen yaw! dert  ettiğin şeye bak!\n",secim62);
        }
        gul();
    }
    }

    if(r7==1){
    //R7
    printf("\nneyse... %s\n", isim);
    printf("       öğrencimisin?\n? ");
    char secim7;
    scanf(" %c", &secim7);
    if(secim7=='e'){
        int rand7 = random(2);
        if(rand7==0){
            printf("wah! wah! wah! çok üzüldüm.. ailenin haberi varmı? ha!haha!!hohoho!!!\n");
        }else if(rand7==1){
            printf("nerde öğrencisin? okulda mı?? hihohohohhohohooo!!!\nespri konuşlandırdım!!\n");
        }

        gul();
    }else{
        int rand72 = random(2);
        if(rand72==0){
            printf("ulan insan en azından askerden yırtmak için öğrenci olur! Ama sen, tıss!\n");
        }else if(rand72==1){
            char secim72[512];
            printf("hangi işle meşgulsun o vakit?\n? ");
            scanf(" %s",secim72);
            printf("siktir lan göt! cümle alem senin ne mal olduğunu biliyor!.\n");
        }
        gul();
    }
    }

    asama6();
}

void asama4(){
    int kilo;
    asama4gg:
    printf("oldu olcak kilonu da söyle bari... çok umurumda ya...\n? ");
    scanf("%d", &kilo);
    if(kilo<=39){
        printf("Rüzgarlı havada dışarı falan çıkma hehehe!");
        gerizekali();
    }else if(kilo>=40 && kilo<=59){
        printf("o kadar yemiş yersen ishal de olursun, kabız da!");
        gerizekali();
    }else if(kilo>=60 && kilo<=79){
        printf("sen normalsin o yüzden dalga geçmiicem... noormaal! noormaal! hehehe!!");
        gerizekali();
    }else if(kilo>=80 && kilo<=99){
        int degis = random(3);
        if(degis==0){
            printf("Lütfen, oturduğun koltuk sağlam kalsın!");
        }else if(degis==1){
            printf("Maaşşallaaah! damızlıkmısın? hangi çiftlikte yetiştin? keh!keh!keh!!.");
        }else if(degis==2){
            printf("Duba! dikkat et benim üstüme düşme!");
        }
        gerizekali();
    }else if(kilo>=100){
        printf("Anlamıştım... 2 saattir klavyenin anasını ağlattın");
        gerizekali();
    }
    printf("\n");
    asama5();
}


void asama3(){
     int boyu;
asama3gg:
    printf("boyun kaç cm senin?\n? ");
    scanf("%d", &boyu);
    if(boyu<=99){
        printf("Deden pigmelerin hangi kavminden lan?");
    }else if(boyu>=100 && boyu<=149){
        printf("Kısa boylu olman önemli diil, diyeceğimi sanıyorsan yanılıyorsun pis cüce!");
    }else if(boyu>=150 && boyu<=169){
        printf("Bacaklarına biraz gübre ektir. Faydası olur. kah!kih!koh!");
    }else if(boyu>=170 && boyu<=189){
        printf("iyi... bana ne... sorduk mu?!");
    }else if(boyu>=190 && boyu<=209){
        printf("Oha! fasülye sırığı!");
    }else if(boyu>=210){
        printf("Yok deve!! kaç santim dedik, milim demedik!\n");
        goto asama3gg;
    }
    printf("\n");
    asama4();
}


void asama2(){
asama2gg:
    printf("kaç yaşındasın?\n? ");
    int yas;
    scanf("%d", &yas);
    if(yas<=4){
        printf("çok küçükmüşsün be! sen git anan gelsin lan lavuk!");
    }else if(yas>=5 && yas <=9){
        printf("sütünü içtin mi yavrum?\n(e/h)? ");
        char secim;
        scanf(" %c", &secim);
        if(secim=='e'){
            printf("Beynine pek etkisi olmamış, git biraz da PEPSı iç!");
        }else{
            printf("bok iç o zaman!");
        }
    }else if(yas>=10 && yas <=17){
        printf("iyi iyi 18ine pek bişi kalmamış... Uyu da büyü!");
    }else if(yas>=18 && yas <=24){
        printf("Oy kullancanmı genç?\n(e/h)? ");
        char secim;
        scanf(" %c", &secim);
        if(secim=='e'){
            printf("ver de gör ebeninkini!");
        }else{
            printf("Ulan sen ne biçim Tee.Cee vatandaşısın? Hayvan!...");
        }
    }else if(yas>=25 && yas <=39){
        printf("vayy! naber morruk? Nerde eski programcılar dimi mirim?");
    }else if(yas>=40 && yas <=59){
        printf("Yuh! bayağı yaşlısın... yaşlılar muhattabım diildir.. Git estetik yaptır gel...");
    }else if(yas>=60 && yas <=98){
        printf("Ulan bunak! Klavyeyi nası görüyon? Geber de helvanı yiyelim. hehehe!");
    }else if(yas>=99){
        printf("Kafa bulma lan göt\n");
        goto asama2gg;
    }
    printf("\n");
    asama3();
}

void asama1(){
    printf("senin adın ne güzelim\n? ");
    scanf(" %255[0-9a-zA-Z ]", &isim);
    printf("\n");
    if(say(isim)<=2){
        printf("Uzak doğudan mısın yoksa başka bir gezegenden mi?\n %d\n harfli ismini biraz zor telafuz ediyorum da...\n%c...\n%ch%s!!!\neee.. olmadı galiba... hehehehehee!\n", say(isim), isim[0], isim[0],isim);
    }else if(say(isim)>=8){
        printf("maaşşallaaaah!\nnüfus memuru ananı babanı pek sevmiyormuş galiba!!!\n");
        gul();
    }
    printf("%s...\n",isim);
    asama2();
}

void asama0(){
    printf("PORTED BY XAVA\nmerhaba\nben karabasan...\n");
    asama1();
}

int main()
{
    srand(getpid());
    setlocale(LC_ALL, "Turkish");
    asama0();
    return 0;
}



