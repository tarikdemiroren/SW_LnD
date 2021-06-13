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
bool secret4 = 0;
bool secret5 = 0;

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

string fivestarlight[24] = { "Druid", "Unicorn", "Harp Magician", "Panda Warrior", "Fairy King", "Desert Queen", "Horus", "Pioneer", "Sea Emperor",
"Polar Queen", "Sky Dancer", "Hell Lady", "Beast Monk", "Archangel", "Monkey King", "Dragon Knight", "Occult Girl", "Oracle",
"Vampire", "Chimera", "Phoenix", "Dragon", "Valkyrja", "Lightning Emperor" };

string fivestardark[27] = { "Druid", "Unicorn", "Harp Magician", "Panda Warrior", "Fairy King", "Desert Queen", "Cannon Girl", "Pioneer", "Sea Emperor",
"Polar Queen", "Sky Dancer", "Hell Lady", "Beast Monk", "Archangel", "Monkey King", "Dragon Knight", "Occult Girl", "Oracle", "Anubis", "Neostone Agent",
"Vampire", "Chimera", "Phoenix", "Dragon", "Valkyrja", "Lightning Emperor", "Ninja" };

int getRandomNumberForSummonRates();
int getRandomNumberForLnD();
int summon(int& nat5count, int& nat4count, int& nat3count, string& monname); // returns 1 if the monster pulled is light returns 2 if the monster pulled is dark
bool isOnListLight(string name);
bool isOnListDark(string name);

int main()
{
    string youalsoneedme;
    int youneedme;
    int wishcount;
    int attribute;
    string monstersname;
    int startover;
    bool start = 1;
    while (start) {
        cout << "Enter '0' to summon manually" << endl;
        cout << "Enter '1' to access settings" << endl;
        cout << "Enter '2' to see the current status" << endl;
        cout << "Enter '3' to wish a monster and pull it automatically" << endl;
        cout << "Enter another number to end the session or reset the progress" << endl;
        int usedScrollCount = 0;
        int nat5count = 0;
        int nat4count = 0;
        int nat3count = 0;
        int continuepls;
        double finalscore;
        double number;
        cin >> continuepls;
        cout << endl;
        while (continuepls == 0 || continuepls == 1 || continuepls == 2 || continuepls == 3) {
            if (continuepls == 0) {
                summon(nat5count, nat4count, nat3count, monstersname);
                usedScrollCount++;
            }
            if (continuepls == 1) {
                cout << "Choose summoner's name (current name: " << summonername << "): ";
                cin >> summonername;
                cout << endl;
                if (summonername == "lucky69")
                    secret5 = 1;
                else
                    secret5 = 0;
                if (summonername == "cum2us")
                    secret4 = 1;
                else
                    secret4 = 0;
                cout << "Choose lightning waiting time (current speed: " << sleeptime << "): ";
                cin >> sleeptime;
            }
            if (continuepls == 2) {
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
            }
            if (continuepls == 3) {
                sleeptime = 0;
                youneedme = 0;
                wishcount = 0;
                cout << "Choose the attribute of the monster that you wish('1' for light, '2' for dark): ";
                cin >> attribute;
                cout << "Enter the name of the monster (capitalise the first letters in each words of the monster's name): " << endl;
                getline(cin, monstersname);
                getline(cin, monstersname);
                if (attribute == 1) {
                    if (isOnListLight(monstersname)) {
                        while (youneedme != attribute || monstersname.compare(youalsoneedme) != 0) {
                            youneedme = summon(nat5count, nat4count, nat3count, youalsoneedme);
                            usedScrollCount++;
                            wishcount++;
                        }
                        cout << "The mission, the nightmares... They are finally over. ~Fives" << endl;
                        cout << "It only took " << wishcount << " amount of scrolls to pull the light " << monstersname << endl;
                    }
                    else {
                        cout << "The monster you wish is not existant" << endl;
                    }
                }
                if (attribute == 2) {
                    if (isOnListDark(monstersname)) {
                        while (youneedme != attribute || monstersname.compare(youalsoneedme) != 0) {
                            youneedme = summon(nat5count, nat4count, nat3count, youalsoneedme);
                            usedScrollCount++;
                            wishcount++;
                        }
                        cout << "The mission, the nightmares... They are finally over. ~Fives" << endl;
                        cout << "It only took " << wishcount << " amount of scrolls to pull the dark " << monstersname << endl;
                    }
                    else {
                        cout << "The monster you wish is not existant" << endl;
                    }
                }
                sleeptime = 1000;
            }            
            cout << endl;
            cout << "Enter '0' to summon manually" << endl;
            cout << "Enter '1' to access settings" << endl;
            cout << "Enter '2' to see the current status" << endl;
            cout << "Enter '3' to wish a monster and pull it automatically" << endl;
            cout << "Enter another number to end the session or reset the progress" << endl;
            cin >> continuepls;
            cout << endl;
        }

        cout << "Enter '0' to start over at the beginning: ";
        cin >> startover;
        cout << endl;
        if (startover == 0) {
            start = true;
            cout << "Your progress has been reset" << endl;
            cout << endl;
        }
        else {
            start = false;
        }
    }
    cout << "Enter any number to quit the program" << endl;
    cin >> start;
}

int getRandomNumberForSummonRates() {
    int adana = 0;
    random_device generator;
    uniform_int_distribution<int> distribution(1, 1000);
    adana = distribution(generator);
    if (adana <= 5 || secret5)
        adana = 1; //Nat 5
    else if ((adana > 5 && adana <= 60) || secret4)
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

int summon(int& nat5count, int& nat4count, int& nat3count, string& monname) {
    int LorD = 0;
    int natStar = 0;
    int random;
    LorD = getRandomNumberForLnD();
    natStar = getRandomNumberForSummonRates();

    //Light
    if (LorD == 0) {
        if (natStar == 1) {
            nat5count++;
            random = getRandomNumber(23);
            cout << "!!!Lightning!!!" << endl;
            Sleep(sleeptime);
            cout << "!!!Lightning!!!" << endl;
            Sleep(sleeptime);
            cout << summonername << " just got light " << fivestarlight[random] << endl;
            monname = fivestarlight[random];
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
            monname = fourstarlight[random];
        }
        if (natStar == 3) {
            nat3count++;
            random = getRandomNumber(32);
            cout << summonername << " just got light " << threestarlight[random] << endl;
            monname = threestarlight[random];
        }
        return 1;
    }
    //Dark
    if (LorD == 1) {
        if (natStar == 1) {
            nat5count++;
            random = getRandomNumber(26);
            cout << "!!!Lightning!!!" << endl;
            Sleep(sleeptime);
            cout << "!!!Lightning!!!" << endl;
            Sleep(sleeptime);
            cout << summonername << " just got dark " << fivestardark[random] << endl;
            monname = fivestardark[random];
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
            monname = fourstardark[random];
        }
        if (natStar == 3) {
            nat3count++;
            random = getRandomNumber(36);
            cout << summonername << " just got dark " << threestardark[random] << endl;
            monname = threestardark[random];
        }
        return 2;
    }
    return 0;
}

bool isOnListDark(string name) {
    bool adana = false;
    for (int i = 0; i < 37; i++) {
        if (name == threestardark[i]) {
            adana = true;
            break;
        }
    }
    if (adana == true)
        return adana;
    for (int i = 0; i < 30; i++) {
        if (name == fourstardark[i]) {
            adana = true;
            break;
        }
    }
    if (adana == true)
        return adana;
    for (int i = 0; i < 27; i++) {
        if (name == fivestardark[i]) {
            adana = true;
            break;
        }
    }
    return adana;
}

bool isOnListLight(string name) {
    bool adana = false;
    for (int i = 0; i < 33; i++) {
        if (name == threestarlight[i]) {
            adana = true;
            break;
        }
    }
    if (adana == true)
        return adana;
    for (int i = 0; i < 35; i++) {
        if (name == fourstarlight[i]) {
            adana = true;
            break;
        }
    }  
    if (adana == true)
        return adana;
    for (int i = 0; i < 24; i++) {
        if (name == fivestarlight[i]) {
            adana = true;
            break;
        }
    }
    return adana;
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
