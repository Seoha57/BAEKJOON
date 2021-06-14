/**************************************
단지번호붙이기
시간 제한   메모리 제한	
   1 초       128 MB

문제
<그림 1>과 같이 정사각형 모양의 지도가 있다. 1은 집이 있는 곳을, 0은 집이 없는 곳을 나타낸다. 
철수는 이 지도를 가지고 연결된 집의 모임인 단지를 정의하고, 단지에 번호를 붙이려 한다. 
여기서 연결되었다는 것은 어떤 집이 좌우, 혹은 아래위로 다른 집이 있는 경우를 말한다. 
대각선상에 집이 있는 경우는 연결된 것이 아니다. <그림 2>는 <그림 1>을 단지별로 번호를 붙인 것이다. 
지도를 입력하여 단지수를 출력하고, 각 단지에 속하는 집의 수를 오름차순으로 정렬하여 출력하는 프로그램을 작성하시오.

입력
첫 번째 줄에는 지도의 크기 N(정사각형이므로 가로와 세로의 크기는 같으며 5≤N≤25)이 입력되고,
그 다음 N줄에는 각각 N개의 자료(0혹은 1)가 입력된다.

출력
첫 번째 줄에는 총 단지수를 출력하시오. 그리고 각 단지내 집의 수를 오름차순으로 정렬하여 한 줄에 하나씩 출력하시오.
**************************************/
#include <bits/stdc++.h>

using namespace std;

bool dfs(const vector<string>& map, vector<vector<bool>>& visited, int x, int y, int& sum) {
	if (x < 0 or y < 0 or x >= map.size() or y >= map.size())
		return false;

	if (!visited[x][y] and map[x][y] == '1') {
		visited[x][y] = true;
		sum += 1;

		dfs(map, visited, x + 1, y, sum);
		dfs(map, visited, x - 1, y, sum);
		dfs(map, visited, x, y + 1, sum);
		dfs(map, visited, x, y - 1, sum);

		return true;
	}

	return false;
}

void solution(int n, const vector<string>& str) {
	vector<vector<bool>> visited(n, vector<bool>(n, false));
	vector<int> estates;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (str[i][j] == '1' and !visited[i][j]) {
				int sum = 0;
				if (dfs(str, visited, i, j, sum)) {
					estates.push_back(sum);
				}
			}
		}
	}

	sort(estates.begin(), estates.end());

	cout << estates.size() << '\n';
	for (auto house : estates) {
		cout << house << '\n';
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<string> str(N);
	for (int i = 0; i < N; ++i) {
		cin >> str[i];
	}

	solution(N, str);

	return 0;
}
