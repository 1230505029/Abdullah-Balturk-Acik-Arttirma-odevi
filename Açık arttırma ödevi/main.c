#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char urun_adi[50];
    double urun_fiyati;
    int teklif_veren_no;
    double en_yuksek_teklif;
} Urun;

void acik_artirma(Urun urun) {
    printf("\nAçık Artırma Sonuçları:\n");
    printf("Ürün Adı: %s\n", urun.urun_adi);
    printf("Satın Alan Teklif Veren No: %d\n", urun.teklif_veren_no);
    printf("Ödenecek Fiyat: %.2f TL\n", urun.en_yuksek_teklif);
}

int main(void) {
    Urun urun;

    while (1) {
        // Başlığımızı yaptım.
        printf("******* AÇIK ARTTIRMAYA HOŞGELDİNİZ *******\n");

        // Ürün adını al
        printf("Ürün Adını Girin : ");
        scanf(" %[^\n]", urun.urun_adi);

        // Programı sonlandırma kontrolünü gösterdim.
        if (strcmp(urun.urun_adi, "_") == 0) {
            printf("Program sonlandırılıyor...\n");
            break;
        }

        // İlk fiyatı nasıl alınacağını gösterdim.
        do {
            printf("Ürünün Başlangıç Fiyatını Girin: ");
            scanf("%lf", &urun.urun_fiyati);

            if (urun.urun_fiyati <= 0) {
                printf("Hatalı giriş! Başlangıç fiyatı 0'dan büyük olmalı.\n");
            }
        } while (urun.urun_fiyati <= 0);

        urun.en_yuksek_teklif = urun.urun_fiyati;

        // Teklifleri bu döngüyle alınacağını söyledim.
        int ilk_teklif_girildi = 0;

        while (1) {
            int teklif_veren_no;
            double teklif;

            printf("Teklif veren no girin: ");
            if (scanf("%d", &teklif_veren_no) != 1) {
                break;
            }

            if (teklif_veren_no == -1) {
                break;
            }

            printf("Teklifi girin: ");
            scanf("%lf", &teklif);

            if (teklif < 0 || teklif <= urun.urun_fiyati) {
                printf("Hatalı giriş! Teklif, 0'dan küçük olamaz ve başlangıç fiyatından küçük olamaz.\n");
                continue;
            }

            if (ilk_teklif_girildi && teklif <= urun.en_yuksek_teklif) {
                printf("Hatalı giriş! Teklif, en yüksek teklifin üzerinde olmalı.\n");
                continue;
            }

            urun.en_yuksek_teklif = teklif;
            urun.teklif_veren_no = teklif_veren_no;
            ilk_teklif_girildi = 1;
        }

        // Açık artırmayı sonlandırmayı gösterdim
        acik_artirma(urun);
        
        // Programı sonlandırma mesajını gösterdim ve döngüden çıktım.
        printf("Program sonlandırılıyor...\n");
        break;
    }

    return 0;
}

