#include <time.h>
#include <stdio.h>
#include <string.h>

struct kullanici
{
    char tahminin[50];
    int paran;
};

struct kullanici giris()
{
    struct kullanici oyuncu;
    char tah[50];
    int par;
    int oynap;

    printf("Lütfen para miktarınızı giriniz:");
    scanf("%d",&oynap);
    
    oyuncu.paran=oynap;
     while(oyuncu.paran>0)
     {
        printf("Ne kadar oynamak istediğinizi girin: ");
        scanf("%d",&par);
        printf("Bakiye:%d\nKullanılan:%d\n",oyuncu.paran,par);

        if(oyuncu.paran>=par)
        {
            printf("Lütfen tahmininizi giriniz: ");
            scanf("%s",&tah);
            strcpy(oyuncu.tahminin,tah);
            //oyuncunun parası pardan < gitmeyecek yetersiz
            oyuncu.paran = oyun(oyuncu.paran,oyuncu.tahminin,par);
            printf("toplam paran:%d\n",oyuncu.paran);
        }
        else
        {
            printf("Yetersiz para");
        }
    }
    return oyuncu;
}

int oyun(int para,char tahmin[50],int miktar)
{
        int rastgele=rand()%100;
        char cevap[50];
        if(rastgele>50)
        {
            cevap[50]="yazi";  
        }
        else
        {
            cevap[50]="tura";
        } 
        
        if (strcmp(cevap,tahmin)==0)
        {
           para+=miktar;
           printf("Teprikler kazandınız%d\n",para);
        }
  
        else
        {
            para-=miktar;
            printf("Kaybettiniz:%d\n",para);

        }
    return para;
}    

int main ()
{
    giris();
    return 0;
}