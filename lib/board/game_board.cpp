//
// Created by hosein on 12/15/23.
//

#include "game_board.h"
#include "iomanip"
#include <climits>
#include <unistd.h>

GameBoard::GameBoard(int n, int m, int refresh_rate, int scale, int number_of_ghost) : n(n), m(m), scale(scale),
                                                                                       refresh_rate(refresh_rate),
                                                                                       nonPlayer(n, m), pacman(n, m) {
    ghosts = std::vector<Ghost>();
    for (int i = 0; i < number_of_ghost; ++i) {
        ghosts.emplace_back(n, m, new int[]{0,1});
    }

    while(!playable()) fix_board();
    nonPlayer.board[pacman.position[0]][pacman.position[1]].blockType = BlockType::EMPTY;
    nonPlayer.number_of_foods--;

}

GameBoard::GameBoard(const GameBoard &gameBoard) : nonPlayer(gameBoard.nonPlayer), pacman(gameBoard.pacman) {
    n = gameBoard.n;
    m = gameBoard.m;
    scale = gameBoard.scale;
    refresh_rate = gameBoard.refresh_rate;
    ghosts = std::vector<Ghost>();
    for (const auto &g: gameBoard.ghosts) {
        ghosts.push_back(g);
    }
}

bool GameBoard::playable() {
    for (const auto &g: ghosts) {
        if (g == pacman) return false;
        if (nonPlayer.board[g.position[0]][g.position[1]].blockType == BlockType::WALL) return false;
    }
    if (nonPlayer.board[pacman.position[0]][pacman.position[1]].blockType == BlockType::WALL) return false;
    return true;
}

void GameBoard::fix_board() {
    pacman = Pacman(n, m);
    int number_of_ghosts = (int) ghosts.size();
    ghosts = std::vector<Ghost>();
    for (int i = 0; i < number_of_ghosts; ++i) {
        ghosts.emplace_back(n,m);
    }
}

void GameBoard::pacman_auto_play() {
    auto move = determine_pacman_move();
    pacman_play(move);
}

void GameBoard::pacman_play(int *move) {
    auto next = pacman.next_pos(move);
    switch (nonPlayer.board[next[0]][next[1]].blockType) {
        case FOOD:
            nonPlayer.board[next[0]][next[1]].blockType = BlockType::EMPTY;
            nonPlayer.number_of_foods--;
            pacman.score+=3;
            break;
        case WALL:
            pacman.score--;
            return;

        case EMPTY:
            pacman.score--;
            break;
    }
    pacman.updater(move);
    for (const auto &g: ghosts) {
        if (g == pacman) {
            pacman.is_alive = false;
            pacman.score = INT_MIN;
            break;
        }
    }
}

int *GameBoard::determine_pacman_move() {
    return nullptr;
}

void GameBoard::ghost_auto_play(int i_th) {
    auto move = determine_ghost_move(i_th);
    ghost_play(i_th, move);
}

void GameBoard::ghost_play(int i_th, int *move) {
    auto next = ghosts[i_th].next_pos(move);
    if (nonPlayer.board[next[0]][next[1]].blockType == BlockType::WALL)
        return;
    ghosts[i_th].updater(move);
    if (pacman == ghosts[i_th]){
        pacman.is_alive = false;
        pacman.score = INT_MIN;
    }
}

int *GameBoard::determine_ghost_move(int i_th) {
    return nullptr;
}

bool GameBoard::is_end() const {
    return (!pacman.is_alive) || (nonPlayer.number_of_foods == 0);
}

void GameBoard::start(std::ostream &os) {
    os << *this;
    while(!is_end()){
        pacman_auto_play();
        for (int i = 0; i < ghosts.size(); ++i) {
            ghost_auto_play(i);
        }
        os << *this;
        usleep(refresh_rate * 1000);
    }
    if (nonPlayer.number_of_foods !=0){
        os << "Game Over\n";
    } else {
        os << "Wiiiiiiiiiiiiiiiiiiin!!!!";
    }
}

std::ostream &operator<<(std::ostream &os, const GameBoard &gameBoard) {
    std::string res;
    res += "Score: " + std::to_string(gameBoard.pacman.score) + " Number of foods: " +
           std::to_string(gameBoard.nonPlayer.number_of_foods) + "\n";
    os << res;
    bool flag = false;
    for (int i = 0; i < gameBoard.n; ++i) {
        for (int j = 0; j < gameBoard.m; ++j) {
            int loc[] = {i, j};
            flag = false;
            for(const auto &g: gameBoard.ghosts){
                if(g == loc and !flag) {
                    os << std::setw(gameBoard.scale) << g;
                    flag = true;
                }
            }
            if(!flag && gameBoard.pacman == loc){
                os << std::setw(gameBoard.scale) << gameBoard.pacman;
            } else if(!flag){
                os << std::setw(gameBoard.scale) << gameBoard.nonPlayer.board[i][j];
            }
        }
        os << "\n";
    }

    return os;
}

GameBoard &GameBoard::operator=(const GameBoard &other) noexcept {
    pacman = other.pacman;
    if (ghosts.size() != other.ghosts.size()){
        ghosts.resize(other.ghosts.size());
    }
    for (int i = 0; i < ghosts.size(); ++i) {
        ghosts[i] = other.ghosts[i];
    }
    nonPlayer = other.nonPlayer;
    n = other.n;
    m = other.m;
    scale = other.scale;
    refresh_rate = other.refresh_rate;
    return *this;
}

GameBoard::~GameBoard() = default;




