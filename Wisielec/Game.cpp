#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void Game::OnInit()
{
    m_guessedLetters.clear();
    m_lives = 6;  
    srand(std::time(NULL));
    int randomIndex = rand() % m_wordsPool.size();
    m_word = m_wordsPool[randomIndex];
    m_guessedLetters.resize(m_word.size(), false);
    m_gameState = GameState::START;
    m_currentGuess.clear();
}

void Game::OnInput()
{
	cout << "Enter a letter: ";
	char guess;
	cin >> guess;
	m_currentGuess = guess;
}

bool Game::OnUpdate(float deltaTime)
{
    if (m_gameState == GameState::START)
    {
        m_gameState = GameState::UPDATE;
    }

    bool correctGuess = false;
    for (size_t i = 0; i < m_word.size(); ++i)
    {
        if (m_word[i] == m_currentGuess[0])
        {
            m_guessedLetters[i] = true;
            correctGuess = true;
        }
    }

    if (!correctGuess)
    {
        --m_lives;
        if (m_lives <= 0)
        {
            m_gameState = GameState::FINISH;
            cout << "Przegrana! Slowo do odgadnieca to: " << m_word << endl;
            return true;
        }
    }

    bool wordGuessed = true;
    for (bool letterGuessed : m_guessedLetters)
    {
        if (!letterGuessed)
        {
            wordGuessed = false;
            break;
        }
    }

    if (wordGuessed)
    {
        m_gameState = GameState::FINISH;
        cout << "Wygrana! Slowo do odgadniecia to: " << m_word << endl;
        return true;
    }



	return false;
}

void Game::OnRender()
{
    for (size_t i = 0; i < m_word.size(); ++i)
    {
        if (m_guessedLetters[i])
        {
            cout << m_word[i] << ' ';
        }
        else
        {
            cout << "_ ";
        }
    }
    cout << "\nLives remaining: " << m_lives << endl;
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