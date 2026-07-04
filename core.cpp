#include <iostream>
#include <string>
#include <vector>

using namespace std;

class SifrelemeMotoru{
    public:
    virtual string sifrele(string hamMetin)=0;
    virtual string sifreCoz(string sifreliMetin)=0;
    virtual ~SifrelemeMotoru() {}
};
class SezarMotoru :public SifrelemeMotoru{
    private:
    int anahtar;
    public:
    SezarMotoru(int k):anahtar(k){}
    string sifrele(string hamMetin){
        string sonuc="";
        int i;
        for(i=0;i<hamMetin.length();i++){
            sonuc+=char(hamMetin[i]+anahtar);
            }
            return sonuc;
    }
    string sifreCoz(string sifreliMetin){
        string sonuc="";
        int i;
        for(i=0;i<sifreliMetin.length();i++){
            sonuc+=char(sifreliMetin[i]-anahtar);
        }
        return sonuc;
    }
};
class XorMotoru :public SifrelemeMotoru{
    private:
    char anahtarKarakter;
    public:
    XorMotoru(char karakter):anahtarKarakter(karakter){}
    string sifrele(string hamMetin) override{
        string sonuc="";
        int i;
        for(i=0;i<hamMetin.length();i++){
            sonuc+=char(hamMetin[i]^anahtarKarakter);
        }
        return sonuc;
    }
    string sifreCoz(string sifreliMetin) override{
        string sonuc="";
        int i;
        for(i=0;i<sifreliMetin.length();i++){
            sonuc+=char(sifreliMetin[i]^anahtarKarakter);
        }
        return sonuc;
    }
};
class GuvenliMesajMerkezi{
    private:
    SifrelemeMotoru* aktifMotor;
    public:
    GuvenliMesajMerkezi(SifrelemeMotoru* motor): aktifMotor(motor){}
    void motoruDegistir(SifrelemeMotoru* motor){
        aktifMotor=motor;
        cout << "🔄 [SİSTEM] Şifreleme motoru dinamik olarak değiştirildi!" << endl;
    }
    void mesajGonder(string mesaj) {
        cout << "\n📤 [MERKEZ] Gönderilecek Mesaj: " << mesaj << endl;
        string sifreli = aktifMotor->sifrele(mesaj);
        cout << "🔒 [AĞ] Şifreli Veri Paketlendi: " << sifreli << endl;
        cout << "✨ [AĞ] Veri güvenli bir şekilde karşı tarafa ulaştırıldı." << endl;
    }
};

int main() {
    cout << "=== CryptX-Core: Güvenli Mesajlaşma Altyapısı ===" << endl;
    cout << "=================================================" << endl;
    SifrelemeMotoru* sezar = new SezarMotoru(6);
    SifrelemeMotoru* xorMotoru = new XorMotoru('Y');


    GuvenliMesajMerkezi merkez(sezar);
    merkez.mesajGonder("YTUE CENG Core Engineering");

    cout << "\n-------------------------------------------------" << endl;

    merkez.motoruDegistir(xorMotoru);
    merkez.mesajGonder("YTUE CENG Core Engineering");

    delete sezar;
    delete xorMotoru;

    return 0;
}
