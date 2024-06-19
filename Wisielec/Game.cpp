#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void Game::OnInit()
{
	m_guessedLetters.clear();
	srand(time(NULL));
	int randomIndex = rand() % m_wordsPool.size();
	m_word = m_wordsPool[randomIndex];
}

void Game::OnInput()
{

}

bool Game::OnUpdate(float deltaTime)
{




	return false;
}

void Game::OnRender()
{

}

void Game::OnShutdown()
{
	m_guessedLetters.clear();

}

void Game::LoadWordsFromFile(const string& filename)
{
	ifstream file(filename);
	string word;
	while (file >> word)
	{
		m_wordsPool.push_back(word);
	}
}