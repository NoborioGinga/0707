

#include<iostream>

class GameManager
{
private:
	
	// コンストラクタをprivateにすることで、外部からのインスタンス化を防ぐ
	GameManager() {}


public:
	//コピー・代入の禁止

	
	GameManager(const GameManager&) = delete;
	
	GameManager& operator=(const GameManager&) = delete;

	//
	static GameManager& Instance() {
		
		static GameManager instance;  

		return instance;

	}


	void StartGame() {
		std::cout << "ゲームタイトル" << std::endl;
	}


};


int main() {
	//使用例
	GameManager::Instance().StartGame();


}