//#include <iostream>
//#include <cstring>
//#include <queue>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//const int N = 9;
//
////������״̬�ṹ�壬�������������δ�����ֵĸ���
//struct State {
//    int board[N][N];
//    int cnt;
//    State() { cnt = 0; }
//    bool operator < (const State& other) const {
//        return cnt > other.cnt;  //����δ�����ֵĸ�����С��������
//    }
//};
//
////�ж�n�Ƿ���Է���(x, y)��λ��
//bool IsValid(int board[N][N], int x, int y, int n) {
//    for (int i = 0; i < N; i++) {
//        if (board[i][y] == n) return false;  //���ͬһ��
//        if (board[x][i] == n) return false;  //���ͬһ��
//    }
//    int sx = x / 3 * 3, sy = y / 3 * 3;
//    for (int i = sx; i < sx + 3; i++) {
//        for (int j = sy; j < sy + 3; j++) {
//            if (board[i][j] == n) return false;  //���ͬһ��3x3����
//        }
//    }
//    return true;
//}
//
////��ȡ��һ�����ܵ�״̬
//vector<State> GetNextStates(State s) {
//    vector<State> next;
//    int x = -1, y = -1;
//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < N; j++) {
//            if (!s.board[i][j]) {
//                x = i, y = j;
//                break;
//            }
//        }
//        if (x != -1) break;
//    }
//    for (int i = 1; i <= N; i++) {
//        if (IsValid(s.board, x, y, i)) {
//            State t = s;
//            t.board[x][y] = i;
//            t.cnt--;
//            next.push_back(t);
//        }
//    }
//    sort(next.begin(), next.end());  //����δ�����ֵĸ�������
//    return next;
//}
//
////A*�����㷨
//bool AStarSearch(State& start) {
//    priority_queue<State> q;   //���ȶ���
//    q.push(start);
//    while (!q.empty()) {
//        State curr = q.top();   //ȡ��δ���������ٵ�״̬
//        q.pop();
//        if (curr.cnt == 0) {    //�ҵ�Ŀ��״̬
//            start = curr;
//            return true;
//        }
//        vector<State> next = GetNextStates(curr);  //��ȡ��һ��״̬
//        for (int i = 0; i < next.size(); i++) {
//            q.push(next[i]);   //���뵽���ȶ�����
//        }
//    }
//    return false;   //����ʧ��
//}
//
//int main() {
//    State start;
//    cout << "Please input " << N * N << " numbers(0 represents space):" << endl;
//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < N; j++) {
//            cin >> start.board[i][j];
//
//
//            if (!start.board[i][j]) start.cnt++;  //��¼δ�����ֵĸ���
//        }
//    }
//    if (AStarSearch(start)) {   //�����ɹ�
//        cout << "The solution is:" << endl;
//        for (int i = 0; i < N; i++) {
//            for (int j = 0; j < N; j++) {
//                cout << start.board[i][j] << " ";
//            }
//            cout << endl;
//        }
//    }
//    else {   //����ʧ��
//        cout << "No solution." << endl;
//    }
//    return 0;
//}

#include <array>     
#include <iostream>  

namespace backtracking {
   
    namespace sudoku_solver {
      
        template <size_t V>
        bool isPossible(const std::array<std::array<int, V>, V>& mat, int i, int j,
            int no, int n) {
        
            for (int x = 0; x < n; x++) {
                if (mat[x][j] == no || mat[i][x] == no) {
                    return false;
                }
            }

            int sx = (i / 3) * 3;
            int sy = (j / 3) * 3;

            for (int x = sx; x < sx + 3; x++) {
                for (int y = sy; y < sy + 3; y++) {
                    if (mat[x][y] == no) {
                        return false;
                    }
                }
            }

            return true;
        }
      
        template <size_t V>
        void printMat(const std::array<std::array<int, V>, V>& mat,
            const std::array<std::array<int, V>, V>& starting_mat, int n) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (starting_mat[i][j] != mat[i][j]) {
                        std::cout << "\033[93m" << mat[i][j] << "\033[0m"
                            << " ";
                    }
                    else {
                        std::cout << mat[i][j] << " ";
                    }
                    if ((j + 1) % 3 == 0) {
                        std::cout << '\t';
                    }
                }
                if ((i + 1) % 3 == 0) {
                    std::cout << std::endl;
                }
                std::cout << std::endl;
            }
        }

        template <size_t V>
        bool solveSudoku(std::array<std::array<int, V>, V>& mat,
            const std::array<std::array<int, V>, V>& starting_mat, int i,
            int j) {
          
            if (i == 9) {
              
                printMat<V>(mat, starting_mat, 9);
                return true;
            }

           
            if (j == 9) {
                return solveSudoku<V>(mat, starting_mat, i + 1, 0);
            }

            
            if (mat[i][j] != 0) {
                return solveSudoku<V>(mat, starting_mat, i, j + 1);
            }
         
            for (int no = 1; no <= 9; no++) {
                if (isPossible<V>(mat, i, j, no, 9)) {
                 
                    mat[i][j] = no;
                    bool solution_found = solveSudoku<V>(mat, starting_mat, i, j + 1);
                    if (solution_found) {
                        return true;
                    }
                   
                }
            }
            mat[i][j] = 0;
            return false;
        }
    }
} 


int main() {
    const int V = 9;
    std::array<std::array<int, V>, V> mat = {
        std::array<int, V>{5, 3, 0, 0, 7, 0, 0, 0, 0},
        std::array<int, V>{6, 0, 0, 1, 9, 5, 0, 0, 0},
        std::array<int, V>{0, 9, 8, 0, 0, 0, 0, 6, 0},
        std::array<int, V>{8, 0, 0, 0, 6, 0, 0, 0, 3},
        std::array<int, V>{4, 0, 0, 8, 0, 3, 0, 0, 1},
        std::array<int, V>{7, 0, 0, 0, 2, 0, 0, 0, 6},
        std::array<int, V>{0, 6, 0, 0, 0, 0, 2, 8, 0},
        std::array<int, V>{0, 0, 0, 4, 1, 9, 0, 0, 5},
        std::array<int, V>{0, 0, 0, 0, 8, 0, 0, 7, 9} };

    backtracking::sudoku_solver::printMat<V>(mat, mat, 9);
    std::cout << "Solution " << std::endl;
    std::array<std::array<int, V>, V> starting_mat = mat;
    backtracking::sudoku_solver::solveSudoku<V>(mat, starting_mat, 0, 0);

    return 0;
}
