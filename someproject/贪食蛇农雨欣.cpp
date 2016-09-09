#include "global.hpp"
#include "snake.hpp"
#include <iostream>
#include <list>
#include <algorithm>
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
class map {
    public:
    map(point _size, point _head, std::list<point> _foods) {
        size = _size;
        head = _head;
        foods = _foods;
        _flag = 0;
    }
    void print() {
        for (int i = 0; i < size.x; i++) {
        for (int j = 0; j < size.y; j++) {
            int flag = 0;
            std::list<point>::iterator iter;
            if (i == head.x && j == head.y) {
            cout << HEAD;
            continue;
            }
            for (iter = foods.begin(); iter != foods.end(); iter++)
            if (i == iter -> x && j == iter -> y) {
            cout << FOOD;
            flag = 1;
            break;
            }
            if (flag == 0)
            for (iter = body.begin(); iter != body.end(); iter++)
            if (i == iter -> x && j == iter -> y) {
            cout << BODY;
            flag = 1;
            break;
            }
            if (flag == 0)
            cout << EMPTY;
        }
        cout << endl;
        }
        cout << endl;
    }
    void move(direction a) {
        point old = head;
        std::list<point> oldbody = body;
        head.move(a);
        std::list<point>::iterator iter;
        for (iter = foods.begin(); iter != foods.end(); iter++)
        if (head == *iter) {
        body.push_back(old);
        iter = foods.erase(iter);
        return;
        }
        if (!body.empty()) {
            int i = 0;
            for (iter = body.begin(); i < body.size() - 1;i++) {
            std::list<point>::iterator now = iter;
            iter++;
            *now = *iter;
            }
            *iter = old;
        }
        if (isGameOver()) {
        head = old;
        body = oldbody;
        _flag = 1;
        return;
        }
    }
    bool isGameOver() {
        if (_flag == 1)
        return true;
        std::list<point>::iterator iter;
        for (iter = body.begin(); iter != body.end(); iter++)
        if (head == *iter)
        return true;
        if (head.x >= size.x || head.y >= size.y || head.x < 0 || head.y < 0)
        return true;
        return false;
    }
    private:
    point size;
    point head;
    std::list<point> foods;
    std::list<point> body;
    int _flag;
};

