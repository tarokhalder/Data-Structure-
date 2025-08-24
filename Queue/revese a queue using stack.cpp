#include <bits/stdc++.h>

using namespace std;

queue <int> reve(queue <int> q) {
      stack <int> s;
      while (!q.empty()) {
          s.push(q.front());
	  q.pop();
      }
      queue <int> L;
      while (!s.empty()) {
          L.push(s.top());
	  s.pop();
      }
      return L;
}
int main() {
    queue <int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    queue <int> s = reve(q);
    while (!s.empty()) {
       cout << s.front() << " ";
       s.pop();
    }
}
