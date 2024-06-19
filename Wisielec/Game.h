#pragma once
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Game
{
	enum class GameState
	{
		START,
		UPDATE,
		FINISH
	};

public:
	void OnInit();
	void OnInput();
	bool OnUpdate(float deltaTime);
	void OnRender();
	void OnShutdown();
	void LoadWordsFromFile(const string& filename);

private:
	string m_word;
	vector<string> m_wordsPool;
	vector<bool> m_guessedLetters;
	GameState m_gameState = GameState::START;
};