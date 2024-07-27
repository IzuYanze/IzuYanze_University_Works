#include <iostream>
#include <string>
#include <map>

#include "CustomerList.h"

using namespace std;

class Gift {
private:
	OrdinaryCustomer* pOrdinaryCustomer = nullptr;
	PremiumCustomer* pPreiumCustomer = nullptr;
	Customer* member;
public:
	Gift(Customer &A, PremiumCustomer &B) :member(&A), pPreiumCustomer(&B) {};
	Gift(Customer &A, OrdinaryCustomer &B) :member(&A), pOrdinaryCustomer(&B) {};
	Gift() :member(nullptr) {};
	~Gift() {};

	const void Print()const { member->Customer::christmasPresent(); };
	const void PrintDetail() const { member->christmasPresent(); };
	void Remove() { member->~Customer(); };
	void GetGift() { Remove(); };
};

int main() {
	map<string, Gift> HoloLive_Gift_List;

	//PremiumCustomer* tempP = new PremiumCustomer("NULL", "NULL", "NULL", "NULL");
	//OrdinaryCustomer* tempO = new OrdinaryCustomer("NULL", "NULL", "NULL", "NULL");

	OrdinaryCustomer* tempO = new OrdinaryCustomer("Usada", "Peko", "Tokyo", "Hitachino Nest Espresso Stoutn");
	HoloLive_Gift_List["Peko"] = Gift(*tempO, *tempO);
	
	PremiumCustomer* tempP = new PremiumCustomer("Sakura", "Miko", "Okinawa", "Chardonnay");
	HoloLive_Gift_List["Miko"] = Gift(*tempP, *tempP);

	tempO = new OrdinaryCustomer("Himemori", "Luna", "Osaka", "Hitachino Nest White Ale");
	HoloLive_Gift_List["Luna"] = Gift(*tempO, *tempO);

	tempO = new OrdinaryCustomer("Tokino", "Sora", "Hokkaido", "Asahi Super Dry");
	HoloLive_Gift_List["Sora"] = Gift(*tempO, *tempO);

	tempP = new PremiumCustomer("Tokoyami", "Towa", "Iwate", "Sauvignon Blanc");
	HoloLive_Gift_List["Towa"] = Gift(*tempP, *tempP);

	tempO = new OrdinaryCustomer("Oozora", "Subaru", "Aichi", "Kirin Ichiban");
	HoloLive_Gift_List["Subaru"] = Gift(*tempO, *tempO);

	tempO = new OrdinaryCustomer("Akai", "Haato", "Mie", "Hitachino Nest Saison Du Japon");
	HoloLive_Gift_List["Haato"] = Gift(*tempO, *tempO);

	tempP = new PremiumCustomer("Yukihana", "Lamy", "Saga", "Syrah");
	HoloLive_Gift_List["Lamy"] = Gift(*tempP, *tempP);

	tempO = new OrdinaryCustomer("Ninomae", "Inanis", "Los Angeles", "Tokyo Black");
	HoloLive_Gift_List["Inanis"] = Gift(*tempO, *tempO);

	tempP = new PremiumCustomer("Watson", "Amelia", "San Francisco", "Riesling");
	HoloLive_Gift_List["Amelia"] = Gift(*tempP, *tempP);

	tempP = new PremiumCustomer("Gawr", "Gura", "San Diego", "Cabernet Sauvignon");
	HoloLive_Gift_List["Gura"] = Gift(*tempP, *tempP);

	tempO = new OrdinaryCustomer("Momosuzu", "Nene", "Gifu", "Hitachino Nest Red Rice Ale");
	HoloLive_Gift_List["Nene"] = Gift(*tempO, *tempO);

	tempP = new PremiumCustomer("Hoshimachi", "Suisei", "Hyogo", "Riesling");
	HoloLive_Gift_List["Suisei"] = Gift(*tempP, *tempP);

	tempO = new OrdinaryCustomer("Houshou", "Marine", "Shiga", "Sapporo Premium Black Beer");
	HoloLive_Gift_List["Marine"] = Gift(*tempO, *tempO);

	tempP = new PremiumCustomer("Inugami", "Korone", "Tottori", "Merlot");
	HoloLive_Gift_List["Korone"] = Gift(*tempP, *tempP);

	tempP = new PremiumCustomer("Nakiri", "Ayame", "Shimane", "Riesling");
	HoloLive_Gift_List["Ayame"] = Gift(*tempP, *tempP);

	tempP = new PremiumCustomer("Nekomata", "Okayu", "Ehime", "Pinor Noir");
	HoloLive_Gift_List["Okayu"] = Gift(*tempP, *tempP);

	tempO = new OrdinaryCustomer("Amane", "Kanata", "Nagano", "Hitachino Nest Real Ginger Ale");
	HoloLive_Gift_List["Kanata"] = Gift(*tempO, *tempO);

	tempO = new OrdinaryCustomer("Shiranui", "Flare", "Gunma", "Asahi Black (Kuronama)");
	HoloLive_Gift_List["Flare"] = Gift(*tempO, *tempO);

	tempO = new OrdinaryCustomer("Shirogane", "Noel", "Niigata", "Sapporo Reserve");
	HoloLive_Gift_List["Noel"] = Gift(*tempO, *tempO);

	tempO = new OrdinaryCustomer("Murasaki", "Shion", "Nara", "Sapporo Premium Beer");
	HoloLive_Gift_List["Shion"] = Gift(*tempO, *tempO);

	tempP = new PremiumCustomer("Tanigou", "Yagoo", "Takatsuki shi", "Bordeaux");
	HoloLive_Gift_List["Yagoo"] = Gift(*tempP, *tempP);


	auto PrintALL = [&HoloLive_Gift_List](void) {
		for (auto& i : HoloLive_Gift_List) {
			cout << "About-->  " << i.first << "  <--" << endl;
			i.second.Print();
			cout << endl;
		}
	};

	auto PrintALLDetail = [&HoloLive_Gift_List](void) {
		for (auto& i : HoloLive_Gift_List) {
			cout << "About-->  " << i.first << "  <--" << endl;
			i.second.PrintDetail();
			cout << endl;
		}
	};

	
	cout << "\n\n\n" << endl;
	PrintALL();

	//Do something
	cout << "\n\n\n" << "------------- DO SOMETHING --------------" << endl;
	
	//Haachama chama
	tempO = new OrdinaryCustomer("Haachama", "Haachama", "Mie", "Hitachino Nest Saison Du Japon");cout << endl;
	HoloLive_Gift_List["Haachama"] = Gift(*tempO, *tempO);

	//Noel drink same with Flare
	tempO = new OrdinaryCustomer("Shirogane", "Noel", "Niigata", "Asahi Black (Kuronama)");cout << endl;
	HoloLive_Gift_List["Noel"] = Gift(*tempO, *tempO);

	//Miko LOSS
	HoloLive_Gift_List["Miko"].Remove();
	HoloLive_Gift_List.erase("Miko");
	cout << endl;

	cout << "------------- DO SOMETHING --------------" << "\n\n\n" << endl;


	PrintALL();

	//Do something
	cout << "\n\n\n" << "------------- DO SOMETHING --------------" << endl;

	//Miko get item in 5min
	tempP = new PremiumCustomer("Sakura", "Miko", "Okinawa", "Chardonnay");cout << endl;
	HoloLive_Gift_List["Miko"] = Gift(*tempP, *tempP);

	//check Haato is Haato
	HoloLive_Gift_List["Haato"].Remove();
	HoloLive_Gift_List.erase("Haato");
	cout << endl << endl;
	tempO = new OrdinaryCustomer("Akai", "Haato", "Mie", "Hitachino Nest Saison Du Japon");cout << endl;
	tempO = new OrdinaryCustomer(*tempO);cout << endl;
	HoloLive_Gift_List["Haato"] = Gift(*tempO, *tempO);

	//Yagoo no gift
	HoloLive_Gift_List["Yagoo"].Remove();
	HoloLive_Gift_List.erase("Yagoo");
	cout << endl;

	cout << "------------- DO SOMETHING --------------" << "\n\n\n" << endl;

	PrintALL();

	cout << "\n\n\n" << "------------- Print Detail --------------" << "\n\n\n" << endl;

	PrintALLDetail();

	//CLEAR ALL
	
	cout << "\n\n\n" << "-------------- SEND Gifts ---------------" << endl;
	for (auto& i : HoloLive_Gift_List) {
		cout << i.first << " Get Gift ^ ^" << endl;
		i.second.GetGift();
		cout << endl ;
	}
	HoloLive_Gift_List.clear();
	cout << "-------------- SEND Gifts ---------------" << "\n\n\n" << endl;


	cout << "\n\n\n" << "------------- EveryOne Get Gift ~HAPPY HAPPY~ --------------" << "\n\n\n" << endl;

	PrintALL();
	//because line89 and line151 not erase
	//so should alive 2 Ordinary Customer

	cout << "----I--M---- ----E--N--D---- ----L--I--N--E----" << endl;
}

/*====================================
data source--
hololive member name -> https://hololivepro.com/en/
Japan map -> https://commons.wikimedia.org/wiki/Category:Maps_of_prefectures_of_Japan
Beer list -> https://www.beeradvocate.com/beer/top-rated/jp/
Wine list -> https://www.winentaste.com/magazine/tutorial_six_grape_varieties
--data source
======================================*/