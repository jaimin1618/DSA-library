#include<bits/stdc++.h>
using namespace std;
// Here KEY for making heap is SQRT(X^2 + Y^2) or distance from origin (0,0)
// {distance^2, {x,y}}, distance^2 to reduce calculation

class Point {
	int x, y;
public:
	Point(int a, int b): x(a), y(b) {};
	friend ostream& operator<<(ostream& out, const Point& p) {
		out << "(" << p.x << "," << p.y << ")";
		return out;
	}
	int get_x() const {
		return x;
	}
	int get_y() const {
		return y;
	}
};

// vector<Point> KClosestPoints(const vector<Point>& points, int k) {
// 	using distancePointPair = pair<int, Point>; // distance-Point, of course KEY is distance
// 	// priority_queue<pair<int, Point>> x;

// 	priority_queue<distancePointPair, vector<distancePointPair>, less<distancePointPair>> x;

// 	// for(const Point& point: points) {
// 	// 	int dis = point.get_x() * point.get_x() + point.get_y() * point.get_y();
// 	// 	pair<int, Point> p = make_pair(dis, point);
// 	// 	maxH.push(p);
// 	// 	if(maxH.size() > k) {
// 	// 		maxH.pop();
// 	// 	}
// 	// }

// 	vector<Point> sol;
// 	// while(!maxH.empty()) {
// 	// 	auto p = maxH.top();
// 	// 	Point point = p.second;
// 	// 	sol.push_back(point);
// 	// }

// 	return sol;
// }

vector<vector<int>> k_closest_points(vector<vector<int>> points, int k) {
	priority_queue<pair<int, pair<int, int>>> maxH;

	for(auto& el: points) {
		int x = el[0], y = el[1];
		int d = x * x + y * y;

		pair<int, pair<int, int>> item = {d, {x, y}};
		maxH.push(item);

		if(maxH.size() > k)
			maxH.pop();
	}

	vector<vector<int>> ans;

	while(!maxH.empty()) {
		pair<int, int> xy = maxH.top().second;
		// cout << xy.first << " " << xy.second << endl;
		ans.push_back({xy.first, xy.second});
		maxH.pop();
	}

	return ans;
}

int main() {
	vector<vector<int>> points = {
		{1, 2},
		{-2, 2},
		{5, 8},
		{0, 1}
	};
	int k = 2;
	vector<vector<int>> ans = k_closest_points(points, k);

	for(auto& el: ans) {
		cout << el[0] << ", " << el[1] << endl;
	}



	return 0;
}