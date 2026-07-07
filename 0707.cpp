
#include<iostream>
#include<conio.h>

class GameManager
{
private:
	
	// コンストラクタをprivateにすることで、外部からのインスタンス化を防ぐ
	GameManager() {}





public:

	enum Scene
	{

		Title,
		Game,
		Clear,

	};

	Scene GameScene = Title;
	

	//コピー・代入の禁止

	
	GameManager(const GameManager&) = delete;
	
	GameManager& operator=(const GameManager&) = delete;

	//
	static GameManager& Instance() {
		
		static GameManager instance;  

		return instance;

	}


	void StartGame() 
	{

		switch (GameScene)
		{
			case Title:
				std::cout << "Game Title" << std::endl;
				std::cout << "何かキー押してください" << std::endl;
				(void)_getch();
				GameScene = Game;
				return StartGame();
				break;

			case Game:
				std::cout << "Game" << std::endl;
				std::cout << "何かキー押してください" << std::endl;
				(void)_getch();
				GameScene = Clear;
				return StartGame();

			case Clear:
				std::cout << "Game Clear" << std::endl;
				std::cout << "何かキー押してください" << std::endl;
				(void)_getch();
				GameScene = Title;
				return StartGame();
		}
	}


};


int main() {
	//使用例
	GameManager::Instance().StartGame();


}