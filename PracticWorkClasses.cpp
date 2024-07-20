#include <iostream>  
#include <algorithm> 
#include <cstdlib>
using namespace std;

class player
{
	string name;
	int points;
public:
	friend bool point_sorter(const player&, const player&);
	string get_name()const { return name; }
	int get_points()const { return points; }
	void set_name(string n) { name = n; }
	void set_points(int n) { points = n; }
};
bool point_sorter(const player& l, const player& r)
{
	return l.points > r.points;
}
int main() {
	size_t n;
	cout << "Playes number:";
	cin >> n;
	player* players = new player[n];
	for (size_t i = 0; i < n; i++)
	{
		string name;
		int point;
		cout << "Players info " << i << " (name points):";
		cin >> name >> point;
		players[i].set_name(name);
		players[i].set_points(point);
	}
	sort(players, players + n, point_sorter);
	for (size_t i = 0; i < n; i++)
	{
		cout << players[i].get_name() << " " << players[i].get_points() << '\n';
	}
	delete[] players;
}
