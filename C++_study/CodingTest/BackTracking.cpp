#include <iostream>
#include <vector>
# define MAX 8

using namespace std;

int arr[MAX]; //주어진 숫자
bool visited[MAX]; //방문, 중복 방지
vector<int> vec; //출력할 수열
int cnt, n, m;

void Print() {
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << '\n';
    return;
}

void DFS(int cnt) {
    if (cnt == m) {
        Print();
        return;
    }

    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        visited[i] = true;
        vec.push_back(arr[i]);
        DFS(cnt + 1);
        vec.pop_back();
        visited[i] = false;
    }
}

int main(void) {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
        visited[i] = false;
    }

    DFS(0);
}
