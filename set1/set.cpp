
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
template<class T>
void Delete_repetition(std::vector<T> &my_set) {
    for (int i = 0; i < my_set.size() - 1; ++i) {
        if (my_set[i] == my_set[i + 1]) {
            my_set.erase(my_set.begin() + i);
            i--;
        }
    }

}
template<class T>
class Set {
public:
    vector<T> set;
     Set<T> add(const Set& other);
    Set<T> mult(const Set& other);
    Set<T> sim_sub(const Set& other);
};

class IntegersSet : public Set<int> {
public:
    vector<int> set_of_ints;

    IntegersSet(vector<int> set_) : set_of_ints(set_) {}

    Set<int> add(IntegersSet set2) {
        Set<int> res;
        for (int i = 0; i < set_of_ints.size(); i++) {
            res.set.push_back(set_of_ints[i]);
        }
        for (int i = 0; i < set2.set_of_ints.size(); i++) {
            bool flag = 1;
            for (int j = 0; j < set_of_ints.size(); j++) {
                if (set2.set_of_ints[i] == set_of_ints[j]) flag = 0;
            }
            if (flag == 1) res.set.push_back(set2.set_of_ints[i]);
        }


                std::sort(res.set.begin(), res.set.end());
                Delete_repetition(res.set);
        return res;
    }
    Set<int> mult(IntegersSet set2)  {
        Set<int> res;
        for (int i = 0; i < set2.set_of_ints.size(); i++) {
            for (int j = 0; j < set_of_ints.size(); j++) {
                if (set2.set_of_ints[i] == set_of_ints[j]) res.set.push_back(set2.set_of_ints[i]);
            }
        }
        bool flag=0;
        for (int i = 0; i < set2.set_of_ints.size(); i++) {
            for (int j = 0; j < set_of_ints.size(); j++) {
                if (set2.set_of_ints[i] == set_of_ints[j]) flag=1;
            }
        }
        if(flag==0) res.set={0};
        std::sort(res.set.begin(), res.set.end());
        Delete_repetition(res.set);
        return res;
    }
    Set<int> sim_sub(IntegersSet set2) {
        Set<int> res;
        for (int i = 0; i < set2.set_of_ints.size(); i++) {
            bool flag = 1;
            for (int j = 0; j < set_of_ints.size(); j++) {
                if (set2.set_of_ints[i] == set_of_ints[j]) flag = 0;
            }
            if (flag == 1) {
                res.set.push_back(set2.set_of_ints[i]);
            }
        }
        for (int i = 0; i < set_of_ints.size(); i++) {
            bool flag = 1;
            for (int j = 0; j < set2.set_of_ints.size(); j++) {
                if (set_of_ints[i] == set2.set_of_ints[j]) flag = 0;
            }
            if (flag == 1) {
                res.set.push_back(set_of_ints[i]);
            }
        }
        std::sort(res.set.begin(), res.set.end());
        Delete_repetition(res.set);
        return res;
    }
};


class Stringset : public Set<std::string> {
public:
    vector<string> set_of_string;

    Stringset(vector<string> set_) : set_of_string(set_){ }
    Set<string> add(Stringset set2) {
        Set<string> res;
        for (int i = 0; i < set_of_string.size(); i++) {
            res.set.push_back(set_of_string[i]);
        }
        for (int i = 0; i < set2.set_of_string.size(); i++) {
            bool flag = 1;
            for (int j = 0; j < set_of_string.size(); j++) {
                if (set2.set_of_string[i] == set_of_string[j]) flag = 0;
            }
            if (flag == 1) res.set.push_back(set2.set_of_string[i]);
        }
        std::sort(res.set.begin(), res.set.end());
        Delete_repetition(res.set);
        return res;
    }
    Set<string> mult(Stringset set2) {
        Set<string> res;
        for (int i = 0; i < set2.set_of_string.size(); i++) {
            for (int j = 0; j < set_of_string.size(); j++) {
                if (set2.set_of_string[i] == set_of_string[j]) res.set.push_back(set2.set_of_string[i]);
            }
        }
        bool flag=0;
        for (int i = 0; i < set2.set_of_string.size(); i++) {
            for (int j = 0; j < set_of_string.size(); j++) {
                if (set2.set_of_string[i] == set_of_string[j]) flag=1;
            }
        }
        if(flag==0) res.set={""};
        std::sort(res.set.begin(), res.set.end());
        Delete_repetition(res.set);
        return res;
    }
    Set<string> sim_sub(Stringset set2) {
        Set<string> res;
        for (int i = 0; i < set2.set_of_string.size(); i++) {
            bool flag = 1;
            for (int j = 0; j < set_of_string.size(); j++) {
                if (set2.set_of_string[i] == set_of_string[j]) flag = 0;
            }
            if (flag == 1) {
                res.set.push_back(set2.set_of_string[i]);
            }
        }
        for (int i = 0; i < set_of_string.size(); i++) {
            bool flag = 1;
            for (int j = 0; j < set2.set_of_string.size(); j++) {
                if (set_of_string[i] == set2.set_of_string[j]) flag = 0;
            }
            if (flag == 1) {
                res.set.push_back(set_of_string[i]);
            }
        }
        std::sort(res.set.begin(), res.set.end());
        Delete_repetition(res.set);
        return res;
    }


};

