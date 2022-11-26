#include <bits/stdc++.h>

using namespace std;

struct Board
{
    int _board = 0;

    bool operator< (const Board& b) const
    {
        return this->_board < b._board;
    }
};

bool isGoal(const Board& b)
{
    const int answer = 123456780;

    return answer == b._board;
}

const int dy[] = {1, -1, 0, 0};
const int dx[] = {0, 0, 1, -1};

bool move(Board& b, int direction)
{
    string board = to_string(b._board);
    if (board.length() == 8)
        board = '0' + board;
    for (int y=0; y < 3; y++) {
        for (int x=0; x < 3; x++) {
            if (board[y * 3 + x] == '0') {
                int ny = y + dy[direction];
                int nx = x + dx[direction];

                if (ny < 0 || ny >= 3 || nx < 0 || nx >= 3)
                    return false;

                swap(board[y * 3 + x], board[ny * 3 + nx]);
                b._board = stoi(board);
                return true;
            }
        }
    }
    return false;
}

int main()
{
    Board b;

    for (int i=0; i < 3; i++) {
        for (int j=0; j < 3; j++) {
            int n;
            scanf("%d", &n);
            
            b._board *= 10;
            b._board += n;
        }
    }
    
    set<Board> visited;
    queue<Board> q;
    q.push(b);
    visited.insert(b);

    int curDepth = 0;
    while (!q.empty()) {
        int size = q.size();

        while (size--) {
            Board curBoard = q.front();
            
            q.pop();

            if (isGoal(curBoard)) {
                printf("%d\n", curDepth);
                return 0;
            }

            for (int d=0; d < 4; d++) {
                Board newBoard = curBoard;
                if (move(newBoard, d) && visited.find(newBoard) == visited.end()) {
                    visited.insert(newBoard);
                    q.push(newBoard);
                }
            }
        }

        curDepth++;
    }

    printf("-1\n");
    return 0;
}
