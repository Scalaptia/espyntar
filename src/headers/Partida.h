#include "./Games.h"
#include "./Screen.h"

class Partida
{
private:
    int currentRound = 0;
    int maxRounds;
    int players;
    bool started = false;
    Games &game;

public:
    Partida(Games &game, shared_ptr<Client> &client);
    void Ronda(shared_ptr<Client> &client, Screen *scene, Texture2D &clock);
    void DrawRounds(Screen *scene);
    bool GetStarted() { return started; }
    Games &GetGame() { return game; }
    void SetMaxRounds(int maxRounds) { this->maxRounds = maxRounds; }
};
