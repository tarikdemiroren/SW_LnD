//
//  Tarık Demirören
//  June 10, 2021
//
#include <string>
#include <iostream>
#include <random>
#include "windows.h"

using namespace std;

int sleeptime = 1000;
string summonername = "Summoner";

string threestarlight[33] = { "Elven Ranger", "Frankenstein", "Mummy", "Martial Artist",
"Charger Shark", "Mammoth", "Penguin Knight", "Beast Hunter", "Lizardman", "Minotauros", "Drunken Master",
"Living Armor", "Grim Reaper", "Mystic Witch", "Imp Champion", "Bounty Hunter", "Vagabond", "Martial Cat",
"Amazon", "Werewolf", "Bearman", "Harpu", "High Elemental", "Inferno", "Griffon", "Golem", "Serpent", "Garuda",
"Warbear", "Inugami", "Elemental", "Fairy", "Harpy" };

string threestardark[37] = { "Frankenstein", "Mummy", "Martial Artist", "Taoist", "Epikion Priest", "Viking",
"Charger Shark", "Mammoth", "Penguin Knight", "Beast Hunter", "Lizardman", "Minotauros", "Drunken Master",
"Living Armor", "Grim Reaper", "Mystic Witch", "Imp Champion", "Bounty Hunter", "Vagabond", "Martial Cat",
"Amazon", "Werewolf", "Bearman", "Harpu", "High Elemental", "Inferno", "Griffon", "Golem", "Serpent", "Hellhound",
"Yeti", "Warbear", "Harg", "Inugami", "Elemental", "Fairy", "Harpy" };

string fourstarlight[35] = { "Pirate Captain", "Giant Warrior", "Barbaric King", "Kobold Bomber", "Brownie Magician", "Kung Fu Girl",
"Samurai", "Lich", "Death Knight", "Rakshasa", "Magical Archer", "Phantom Thief", "Pierret", "Joker", "Ninja", "Cannon Girl",
"Succubus", "Sylphid", "Sylph", "Undine", "Nine-Tailed Fox", "Dryad", "Boomerang Warrior", "Chakram Dancer", "Taoist", "Epikion Priest",
"Dice Magician", "Sniper Mk.1", "Jack-o'-lantern", "Neostone Fighter", "Assasin", "Magic Knight", "Mermaid", "Anubis", "Neostone Agent" };

string fourstardark[30] = { "Pirate Captain", "Giant Warrior", "Barbaric King", "Kobold Bomber", "Brownie Magician", "Kung Fu Girl",
"Samurai", "Lich", "Death Knight", "Rakshasa", "Magical Archer", "Phantom Thief", "Pierret", "Joker",
"Succubus", "Sylphid", "Sylph", "Undine", "Nine-Tailed Fox", "Dryad", "Boomerang Warrior", "Chakram Dancer",
"Dice Magician", "Sniper Mk.1", "Jack-o'-lantern", "Horus", "Neostone Fighter", "Assasin", "Magic Knight", "Mermaid" };

string fivestarlight[25] = { "Druid", "Unicorn", "Harp Magician", "Panda Warrior", "Fairy King", "Desert Queen", "Horus", "Pioneer", "Sea Emperor",
"Polar Queen", "Sky Dancer", "Hell Lady", "Beast Monk", "Archangel", "Monkey King", "Dragon Knight", "Occult Girl", "Oracle",
"Vampire", "Chimera", "Phoenix", "Dragon", "Valkyrja", "Lightning Emperor" };

string fivestardark[27] = { "Druid", "Unicorn", "Harp Magician", "Panda Warrior", "Fairy King", "Desert Queen", "Cannon Girl", "Pioneer", "Sea Emperor",
"Polar Queen", "Sky Dancer", "Hell Lady", "Beast Monk", "Archangel", "Monkey King", "Dragon Knight", "Occult Girl", "Oracle", "Anubis", "Neostone Agent",
"Vampire", "Chimera", "Phoenix", "Dragon", "Valkyrja", "Lightning Emperor", "Ninja" };

int getRandomNumberForSummonRates();
int getRandomNumberForLnD();
void summon(int& nat5count, int& nat4count, int& nat3count);

int main()
{
    cout << "Enter '0' to use LnD scroll or Enter '1' to access settings menu: ";
    int usedScrollCount = 0;
    int nat5count = 0;
    int nat4count = 0;
    int nat3count = 0;
    int continuepls;
    double finalscore;
    double number;
    cin >> continuepls;
    while (continuepls == 0 || continuepls == 1) {
        if (continuepls == 0) {
            summon(nat5count, nat4count, nat3count);
            usedScrollCount++;
            cout << endl;
        }
        if (continuepls == 1) {
            cout << "Choose summoner's name (current name: " << summonername << "): ";
            cin >> summonername;
            cout << endl;
            cout << "Choose lightning waiting time (current speed: " << sleeptime << "): ";
            cin >> sleeptime;
            cout << endl;
        }
        cout << "Enter '0' to summon or Enter '1' to access settings menu or another number to see the results: ";
        cin >> continuepls;
    }
    cout << "**************" << endl;
    cout << "Total amount of used scrolls: " << usedScrollCount << endl;
    cout << "Total amount of 5* monsters pulled: " << nat5count << endl;
    cout << "Total amount of 4* monsters pulled: " << nat4count << endl;
    cout << "Total amount of 3* monsters pulled: " << nat3count << endl;
    if (nat5count == 0 || nat4count == 0)
        number = 1.5;
    else
        number = 2;
    finalscore = (double)((double)(200 * (double)nat5count / (double)usedScrollCount) + (double)(50 / 3 * (double)nat4count / (double)usedScrollCount)) / number;
    cout << "**************" << endl;
    cout << "Your final score is: " << finalscore << endl;
    cout << endl;
    cout << "(Final score '1' represents average. '0' represents that all of the monsters you pulled were only 3 star monsters." << endl;
    cout << "The higher your final score than '1', the more lucky your summons turned out)" << endl;
    cout << "**************" << endl;
    cout << "Enter any number to quit the program" << endl;
    cin >> continuepls;
}

int getRandomNumberForSummonRates() {
    int adana = 0;
    random_device generator;
    uniform_int_distribution<int> distribution(1, 1000);
    adana = distribution(generator);
    if (adana <= 5)
        adana = 1; //Nat 5
    else if (adana > 5 && adana <= 60)
        adana = 2; //Nat 4
    else
        adana = 3; //Nat 3
    return adana;
}

int getRandomNumberForLnD() {
    int adana = 0;
    random_device generator;
    uniform_int_distribution<int> distribution(0, 1); //0 for light, 1 for dark
    adana = distribution(generator);
    return adana;
}

int getRandomNumber(int ara) {
    int adana = 0;
    random_device generator;
    uniform_int_distribution<int> distribution(0, ara);
    adana = distribution(generator);
    return adana;
}

void summon(int& nat5count, int& nat4count, int& nat3count) {
    int LorD = 0;
    int natStar = 0;
    int random;
    LorD = getRandomNumberForLnD();
    natStar = getRandomNumberForSummonRates();

    if (LorD == 0) {
        if (natStar == 1) {
            nat5count++;
            random = getRandomNumber(24);
            cout << "!!!Lightning!!!" << endl;
            Sleep(sleeptime);
            cout << "!!!Lightning!!!" << endl;
            Sleep(sleeptime);
            cout << summonername << " just got light " << fivestarlight[random] << endl;
            cout << "!!!GZZZ!!!" << endl;
        }
        if (natStar == 2) {
            nat4count++;
            random = getRandomNumber(34);
            cout << "!!!Lightning!!!" << endl;
            Sleep(sleeptime);
            cout << "!!!Lightning!!!" << endl;
            Sleep(sleeptime);
            cout << summonername << " just got light " << fourstarlight[random] << endl;
        }
        if (natStar == 3) {
            nat3count++;
            random = getRandomNumber(32);
            cout << summonername << " just got light " << threestarlight[random] << endl;
        }
    }
    if (LorD == 1) {
        if (natStar == 1) {
            nat5count++;
            random = getRandomNumber(26);
            cout << "!!!Lightning!!!" << endl;
            Sleep(sleeptime);
            cout << "!!!Lightning!!!" << endl;
            Sleep(sleeptime);
            cout << summonername << " just got dark " << fivestardark[random] << endl;
            cout << "!!!GZZZ!!!" << endl;
        }
        if (natStar == 2) {
            nat4count++;
            random = getRandomNumber(29);
            cout << "!!!Lightning!!!" << endl;
            Sleep(sleeptime);
            cout << "!!!Lightning!!!" << endl;
            Sleep(sleeptime);
            cout << summonername << " just got dark " << fourstardark[random] << endl;
        }
        if (natStar == 3) {
            nat3count++;
            random = getRandomNumber(36);
            cout << summonername << " just got dark " << threestardark[random] << endl;
        }
    }

    
}

// Programı çalıştır: Ctrl + F5 veya Hata Ayıkla > Hata Ayıklamadan Başlat menüsü
// Programda hata ayıkla: F5 veya Hata Ayıkla > Hata Ayıklamayı Başlat menüsü

// Kullanmaya Başlama İpuçları: 
//   1. Dosyaları eklemek/yönetmek için Çözüm Gezgini penceresini kullanın
//   2. Kaynak denetimine bağlanmak için Takım Gezgini penceresini kullanın
//   3. Derleme çıktısını ve diğer iletileri görmek için Çıktı penceresini kullanın
//   4. Hataları görüntülemek için Hata Listesi penceresini kullanın
//   5. Yeni kod dosyaları oluşturmak için Projeye Git > Yeni Öğe ekle veya varolan kod dosyalarını projeye eklemek için Proje > Var Olan Öğeyi Ekle adımlarını izleyin
//   6. Bu projeyi daha sonra yeniden açmak için Dosya > Aç > Proje'ye gidip .sln uzantılı dosyayı seçin
